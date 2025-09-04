#include <windows.h>
#include <mutex>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <fstream>

#include "AssetsReader.h"

namespace Game
{
    constexpr const char* AssetsPath = "Data";

    
    constexpr unsigned int MaxAllocationTime = 1000 * 60;

    
    constexpr unsigned int CypherSalt = 0xDEAD0000;

    std::ifstream::pos_type LegacyFileSize(const char* FileName)
    {
        std::ifstream in(FileName, std::ifstream::ate | std::ifstream::binary);
        return in.tellg();
    }

    AssetsReader& AssetsReader::GetInstance()
    {
        static AssetsReader Instance;
        return Instance;
    }

    AssetsReader::AssetsReader() : m_LookupTable(CRC::CRC_32().MakeTable())
    {
    }

    void AssetsReader::Update()
    {
        static unsigned int s_LastCheckTime = 0;

        auto CurrentTime = GetCurrentTime();

        if (s_LastCheckTime < CurrentTime)
        {
            auto ErasePredicate = [CurrentTime](AssetsBinary& Binary)
            {
                if (Binary.AllocationTime + MaxAllocationTime < CurrentTime)
                {
                    delete[] Binary.Memory;
                    return true;
                }

                return false;
            };

            
            s_LastCheckTime = CurrentTime + 10 * 1000;

            
            m_Cache.erase(std::remove_if(m_Cache.begin(), m_Cache.end(), ErasePredicate), m_Cache.end());
        }
    }

    bool AssetsReader::Get(const char* FilePath, AssetsBinary& Binary)
    {
        std::string FileLower = FilePath;
        std::transform(FileLower.begin(), FileLower.end(), FileLower.begin(), ::tolower);

        auto FileCRC = CRC::Calculate(FileLower.data(), FileLower.size(), m_LookupTable);

        
        {
            for (auto& Bin : m_Cache)
            {
                if (Bin.Crc == FileCRC)
                {
                    Bin.AllocationTime = GetCurrentTime();

                    
                    Binary = Bin;
                    return true;
                }
            }
        }

        using namespace std::string_literals;

        
        auto FileID = FileCRC + CypherSalt;

        
        auto ErrorCode = std::error_code{ };
        auto FileBin = AssetsPath + "\\"s + std::to_string(FileID) + ".bin"s;
        auto FileSize = static_cast<unsigned int>(LegacyFileSize(FileBin.c_str()));

        if (!ErrorCode)
        {
            
            FILE* File = nullptr;
            if (fopen_s(&File, FileBin.c_str(), "rb") == 0)
            {
                unsigned char* Memory = new unsigned char[FileSize];

                
                fread_s(Memory, FileSize, sizeof(unsigned char), FileSize, File);
                fclose(File);

                
                unsigned char Keys[sizeof(FileCRC)] = { 0 };

                
                auto* Bytes = reinterpret_cast<unsigned char*>(&FileCRC);
                Keys[0] = Bytes[0];
                Keys[1] = Bytes[1];
                Keys[2] = Bytes[2];
                Keys[3] = Bytes[3];

                
                Binary.Memory = Memory;

                
                for (size_t i = 0; i < FileSize; i++)
                {
                    Binary.Memory[i] = Memory[i];
                    Binary.Memory[i] ^= Keys[i % _countof(Keys)];
                }

                
                Binary.Size = FileSize;
                Binary.Crc = FileCRC;
                Binary.AllocationTime = GetCurrentTime();

                
                m_Cache.emplace_back(Binary);

                
                return true;
            }
        }

        return false;
    }
}
