
























































#ifndef CRCPP_CRC_H_

#define CRCPP_CRC_H_
#define CRCPP_BRANCHLESS
#define CRCPP_USE_CPP11

#include <climits>  
#ifdef CRCPP_USE_CPP11
#include <cstddef>  
#include <cstdint>  
#else
#include <stddef.h> 
#include <stdint.h> 
#endif
#include <limits>   
#include <utility>  

#ifndef crcpp_uint8
#   ifdef CRCPP_USE_CPP11
        
#       define crcpp_uint8 ::std::uint8_t
#   else
        
#       define crcpp_uint8 uint8_t
#   endif
#endif

#ifndef crcpp_uint16
#   ifdef CRCPP_USE_CPP11
        
#       define crcpp_uint16 ::std::uint16_t
#   else
        
#       define crcpp_uint16 uint16_t
#   endif
#endif

#ifndef crcpp_uint32
#   ifdef CRCPP_USE_CPP11
        
#       define crcpp_uint32 ::std::uint32_t
#   else
        
#       define crcpp_uint32 uint32_t
#   endif
#endif

#ifndef crcpp_uint64
#   ifdef CRCPP_USE_CPP11
        
#       define crcpp_uint64 ::std::uint64_t
#   else
        
#       define crcpp_uint64 uint64_t
#   endif
#endif

#ifndef crcpp_size
#   ifdef CRCPP_USE_CPP11
        
#       define crcpp_size ::std::size_t
#   else
        
#       define crcpp_size size_t
#   endif
#endif

#ifdef CRCPP_USE_CPP11
    
#   define crcpp_constexpr constexpr
#else
    
#   define crcpp_constexpr const
#endif

#ifdef CRCPP_USE_NAMESPACE
namespace CRCPP
{
#endif








class CRC
{
public:
    
    template <typename CRCType, crcpp_uint16 CRCWidth>
    struct Table;

    


    template <typename CRCType, crcpp_uint16 CRCWidth>
    struct Parameters
    {
        CRCType polynomial;   
        CRCType initialValue; 
        CRCType finalXOR;     
        bool reflectInput;    
        bool reflectOutput;   

        Table<CRCType, CRCWidth> MakeTable() const;
    };

    



    template <typename CRCType, crcpp_uint16 CRCWidth>
    struct Table
    {
        
        Table(const Parameters<CRCType, CRCWidth> & parameters);

#ifdef CRCPP_USE_CPP11
        Table(Parameters<CRCType, CRCWidth> && parameters);
#endif

        const Parameters<CRCType, CRCWidth> & GetParameters() const;

        const CRCType * GetTable() const;

        CRCType operator[](unsigned char index) const;

    private:
        void InitTable();

        Parameters<CRCType, CRCWidth> parameters; 
        CRCType table[1 << CHAR_BIT];             
    };

    
    
    template <typename CRCType, crcpp_uint16 CRCWidth>
    static CRCType Calculate(const void * data, crcpp_size size, const Parameters<CRCType, CRCWidth> & parameters);

    template <typename CRCType, crcpp_uint16 CRCWidth>
    static CRCType Calculate(const void * data, crcpp_size size, const Parameters<CRCType, CRCWidth> & parameters, CRCType crc);

    template <typename CRCType, crcpp_uint16 CRCWidth>
    static CRCType Calculate(const void * data, crcpp_size size, const Table<CRCType, CRCWidth> & lookupTable);

    template <typename CRCType, crcpp_uint16 CRCWidth>
    static CRCType Calculate(const void * data, crcpp_size size, const Table<CRCType, CRCWidth> & lookupTable, CRCType crc);

    
    
#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS
    static const Parameters< crcpp_uint8,  4> & CRC_4_ITU();
    static const Parameters< crcpp_uint8,  5> & CRC_5_EPC();
    static const Parameters< crcpp_uint8,  5> & CRC_5_ITU();
    static const Parameters< crcpp_uint8,  5> & CRC_5_USB();
    static const Parameters< crcpp_uint8,  6> & CRC_6_CDMA2000A();
    static const Parameters< crcpp_uint8,  6> & CRC_6_CDMA2000B();
    static const Parameters< crcpp_uint8,  6> & CRC_6_ITU();
    static const Parameters< crcpp_uint8,  7> & CRC_7();
#endif
    static const Parameters< crcpp_uint8,  8> & CRC_8();
#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS
    static const Parameters< crcpp_uint8,  8> & CRC_8_EBU();
    static const Parameters< crcpp_uint8,  8> & CRC_8_MAXIM();
    static const Parameters< crcpp_uint8,  8> & CRC_8_WCDMA();
    static const Parameters<crcpp_uint16, 10> & CRC_10();
    static const Parameters<crcpp_uint16, 10> & CRC_10_CDMA2000();
    static const Parameters<crcpp_uint16, 11> & CRC_11();
    static const Parameters<crcpp_uint16, 12> & CRC_12_CDMA2000();
    static const Parameters<crcpp_uint16, 12> & CRC_12_DECT();
    static const Parameters<crcpp_uint16, 12> & CRC_12_UMTS();
    static const Parameters<crcpp_uint16, 13> & CRC_13_BBC();
    static const Parameters<crcpp_uint16, 15> & CRC_15();
    static const Parameters<crcpp_uint16, 15> & CRC_15_MPT1327();
#endif
    static const Parameters<crcpp_uint16, 16> & CRC_16_ARC();
    static const Parameters<crcpp_uint16, 16> & CRC_16_BUYPASS();
    static const Parameters<crcpp_uint16, 16> & CRC_16_CCITTFALSE();
#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS
    static const Parameters<crcpp_uint16, 16> & CRC_16_CDMA2000();
    static const Parameters<crcpp_uint16, 16> & CRC_16_CMS();
    static const Parameters<crcpp_uint16, 16> & CRC_16_DECTR();
    static const Parameters<crcpp_uint16, 16> & CRC_16_DECTX();
    static const Parameters<crcpp_uint16, 16> & CRC_16_DNP();
#endif
    static const Parameters<crcpp_uint16, 16> & CRC_16_GENIBUS();
    static const Parameters<crcpp_uint16, 16> & CRC_16_KERMIT();
#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS
    static const Parameters<crcpp_uint16, 16> & CRC_16_MAXIM();
    static const Parameters<crcpp_uint16, 16> & CRC_16_MODBUS();
    static const Parameters<crcpp_uint16, 16> & CRC_16_T10DIF();
    static const Parameters<crcpp_uint16, 16> & CRC_16_USB();
#endif
    static const Parameters<crcpp_uint16, 16> & CRC_16_X25();
    static const Parameters<crcpp_uint16, 16> & CRC_16_XMODEM();
#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS
    static const Parameters<crcpp_uint32, 17> & CRC_17_CAN();
    static const Parameters<crcpp_uint32, 21> & CRC_21_CAN();
    static const Parameters<crcpp_uint32, 24> & CRC_24();
    static const Parameters<crcpp_uint32, 24> & CRC_24_FLEXRAYA();
    static const Parameters<crcpp_uint32, 24> & CRC_24_FLEXRAYB();
    static const Parameters<crcpp_uint32, 30> & CRC_30();
#endif
    static const Parameters<crcpp_uint32, 32> & CRC_32();
    static const Parameters<crcpp_uint32, 32> & CRC_32_BZIP2();
#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS
    static const Parameters<crcpp_uint32, 32> & CRC_32_C();
#endif
    static const Parameters<crcpp_uint32, 32> & CRC_32_MPEG2();
    static const Parameters<crcpp_uint32, 32> & CRC_32_POSIX();
#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS
    static const Parameters<crcpp_uint32, 32> & CRC_32_Q();
    static const Parameters<crcpp_uint64, 40> & CRC_40_GSM();
    static const Parameters<crcpp_uint64, 64> & CRC_64();
#endif

#ifdef CRCPP_USE_CPP11
    CRC() = delete;
    CRC(const CRC & other) = delete;
    CRC & operator=(const CRC & other) = delete;
    CRC(CRC && other) = delete;
    CRC & operator=(CRC && other) = delete;
#endif

private:
#ifndef CRCPP_USE_CPP11
    CRC();
    CRC(const CRC & other);
    CRC & operator=(const CRC & other);
#endif

    template <typename IntegerType>
    static IntegerType Reflect(IntegerType value, crcpp_uint16 numBits);

    template <typename CRCType, crcpp_uint16 CRCWidth>
    static CRCType Finalize(CRCType remainder, CRCType finalXOR, bool reflectOutput);

    template <typename CRCType, crcpp_uint16 CRCWidth>
    static CRCType UndoFinalize(CRCType remainder, CRCType finalXOR, bool reflectOutput);

    template <typename CRCType, crcpp_uint16 CRCWidth>
    static CRCType CalculateRemainder(const void * data, crcpp_size size, const Parameters<CRCType, CRCWidth> & parameters, CRCType remainder);

    template <typename CRCType, crcpp_uint16 CRCWidth>
    static CRCType CalculateRemainder(const void * data, crcpp_size size, const Table<CRCType, CRCWidth> & lookupTable, CRCType remainder);
};









template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRC::Table<CRCType, CRCWidth> CRC::Parameters<CRCType, CRCWidth>::MakeTable() const
{
    
    return CRC::Table<CRCType, CRCWidth>(*this);
}







template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRC::Table<CRCType, CRCWidth>::Table(const Parameters<CRCType, CRCWidth> & params) :
    parameters(params)
{
    InitTable();
}

#ifdef CRCPP_USE_CPP11






template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRC::Table<CRCType, CRCWidth>::Table(Parameters<CRCType, CRCWidth> && params) :
    parameters(::std::move(params))
{
    InitTable();
}
#endif







template <typename CRCType, crcpp_uint16 CRCWidth>
inline const CRC::Parameters<CRCType, CRCWidth> & CRC::Table<CRCType, CRCWidth>::GetParameters() const
{
    return parameters;
}







template <typename CRCType, crcpp_uint16 CRCWidth>
inline const CRCType * CRC::Table<CRCType, CRCWidth>::GetTable() const
{
    return table;
}








template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRCType CRC::Table<CRCType, CRCWidth>::operator[](unsigned char index) const
{
    return table[index];
}






template <typename CRCType, crcpp_uint16 CRCWidth>
inline void CRC::Table<CRCType, CRCWidth>::InitTable()
{
    
    static crcpp_constexpr CRCType BIT_MASK((CRCType(1) << (CRCWidth - CRCType(1))) |
                                           ((CRCType(1) << (CRCWidth - CRCType(1))) - CRCType(1)));

    
    static crcpp_constexpr CRCType SHIFT((CHAR_BIT >= CRCWidth) ? static_cast<CRCType>(CHAR_BIT - CRCWidth) : 0);

    CRCType crc;
    unsigned char byte = 0;

    
    do
    {
        crc = CRC::CalculateRemainder<CRCType, CRCWidth>(&byte, sizeof(byte), parameters, CRCType(0));

        
        
        
        crc &= BIT_MASK;

        if (!parameters.reflectInput && CRCWidth < CHAR_BIT)
        {
            
            
            crc = static_cast<CRCType>(crc << SHIFT);
        }

        table[byte] = crc;
    }
    while (++byte);
}










template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRCType CRC::Calculate(const void * data, crcpp_size size, const Parameters<CRCType, CRCWidth> & parameters)
{
    CRCType remainder = CalculateRemainder(data, size, parameters, parameters.initialValue);

    

    return Finalize<CRCType, CRCWidth>(remainder, parameters.finalXOR, parameters.reflectInput != parameters.reflectOutput);
}











template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRCType CRC::Calculate(const void * data, crcpp_size size, const Parameters<CRCType, CRCWidth> & parameters, CRCType crc)
{
    CRCType remainder = UndoFinalize<CRCType, CRCWidth>(crc, parameters.finalXOR, parameters.reflectInput != parameters.reflectOutput);

    remainder = CalculateRemainder(data, size, parameters, remainder);

    

    return Finalize<CRCType, CRCWidth>(remainder, parameters.finalXOR, parameters.reflectInput != parameters.reflectOutput);
}










template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRCType CRC::Calculate(const void * data, crcpp_size size, const Table<CRCType, CRCWidth> & lookupTable)
{
    const Parameters<CRCType, CRCWidth> & parameters = lookupTable.GetParameters();

    CRCType remainder = CalculateRemainder(data, size, lookupTable, parameters.initialValue);

    

    return Finalize<CRCType, CRCWidth>(remainder, parameters.finalXOR, parameters.reflectInput != parameters.reflectOutput);
}












template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRCType CRC::Calculate(const void * data, crcpp_size size, const Table<CRCType, CRCWidth> & lookupTable, CRCType crc)
{
    const Parameters<CRCType, CRCWidth> & parameters = lookupTable.GetParameters();

    CRCType remainder = UndoFinalize<CRCType, CRCWidth>(crc, parameters.finalXOR, parameters.reflectInput != parameters.reflectOutput);

    remainder = CalculateRemainder(data, size, lookupTable, remainder);

    

    return Finalize<CRCType, CRCWidth>(remainder, parameters.finalXOR, parameters.reflectInput != parameters.reflectOutput);
}








template <typename IntegerType>
inline IntegerType CRC::Reflect(IntegerType value, crcpp_uint16 numBits)
{
    IntegerType reversedValue(0);

    for (crcpp_uint16 i = 0; i < numBits; ++i)
    {
        reversedValue = static_cast<IntegerType>((reversedValue << 1) | (value & 1));
        value = static_cast<IntegerType>(value >> 1);
    }

    return reversedValue;
}










template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRCType CRC::Finalize(CRCType remainder, CRCType finalXOR, bool reflectOutput)
{
    
    static crcpp_constexpr CRCType BIT_MASK = (CRCType(1) << (CRCWidth - CRCType(1))) |
                                             ((CRCType(1) << (CRCWidth - CRCType(1))) - CRCType(1));

    if (reflectOutput)
    {
        remainder = Reflect(remainder, CRCWidth);
    }

    return (remainder ^ finalXOR) & BIT_MASK;
}


















template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRCType CRC::UndoFinalize(CRCType crc, CRCType finalXOR, bool reflectOutput)
{
    
    static crcpp_constexpr CRCType BIT_MASK = (CRCType(1) << (CRCWidth - CRCType(1))) |
                                             ((CRCType(1) << (CRCWidth - CRCType(1))) - CRCType(1));

    crc = (crc & BIT_MASK) ^ finalXOR;

    if (reflectOutput)
    {
        crc = Reflect(crc, CRCWidth);
    }

    return crc;
}











template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRCType CRC::CalculateRemainder(const void * data, crcpp_size size, const Parameters<CRCType, CRCWidth> & parameters, CRCType remainder)
{
#ifdef CRCPP_USE_CPP11
    
    
    static_assert(::std::numeric_limits<CRCType>::digits >= CRCWidth, "CRCType is too small to contain a CRC of width CRCWidth.");
#else
    
    
    enum { static_assert_failed_CRCType_is_too_small_to_contain_a_CRC_of_width_CRCWidth = 1 / (::std::numeric_limits<CRCType>::digits >= CRCWidth ? 1 : 0) };
#endif

    const unsigned char * current = reinterpret_cast<const unsigned char *>(data);

    
    
    if (parameters.reflectInput)
    {
        CRCType polynomial = CRC::Reflect(parameters.polynomial, CRCWidth);
        while (size--)
        {
            remainder = static_cast<CRCType>(remainder ^ *current++);

            
            for (crcpp_size i = 0; i < CHAR_BIT; ++i)
            {
#ifdef CRCPP_BRANCHLESS
                
                
                
                
                
                remainder = static_cast<CRCType>((remainder >> 1) ^ ((remainder & 1) * polynomial));
#else
                remainder = static_cast<CRCType>((remainder & 1) ? ((remainder >> 1) ^ polynomial) : (remainder >> 1));
#endif
            }
        }
    }
    else if (CRCWidth >= CHAR_BIT)
    {
        static crcpp_constexpr CRCType CRC_WIDTH_MINUS_ONE(CRCWidth - CRCType(1));
#ifndef CRCPP_BRANCHLESS
        static crcpp_constexpr CRCType CRC_HIGHEST_BIT_MASK(CRCType(1) << CRC_WIDTH_MINUS_ONE);
#endif
        
        static crcpp_constexpr CRCType SHIFT((CRCWidth >= CHAR_BIT) ? static_cast<CRCType>(CRCWidth - CHAR_BIT) : 0);

        while (size--)
        {
            remainder = static_cast<CRCType>(remainder ^ (static_cast<CRCType>(*current++) << SHIFT));

            
            for (crcpp_size i = 0; i < CHAR_BIT; ++i)
            {
#ifdef CRCPP_BRANCHLESS
                
                
                
                
                
                remainder = static_cast<CRCType>((remainder << 1) ^ (((remainder >> CRC_WIDTH_MINUS_ONE) & 1) * parameters.polynomial));
#else
                remainder = static_cast<CRCType>((remainder & CRC_HIGHEST_BIT_MASK) ? ((remainder << 1) ^ parameters.polynomial) : (remainder << 1));
#endif
            }
        }
    }
    else
    {
        static crcpp_constexpr CRCType CHAR_BIT_MINUS_ONE(CHAR_BIT - 1);
#ifndef CRCPP_BRANCHLESS
        static crcpp_constexpr CRCType CHAR_BIT_HIGHEST_BIT_MASK(CRCType(1) << CHAR_BIT_MINUS_ONE);
#endif
        
        static crcpp_constexpr CRCType SHIFT((CHAR_BIT >= CRCWidth) ? static_cast<CRCType>(CHAR_BIT - CRCWidth) : 0);

        CRCType polynomial = static_cast<CRCType>(parameters.polynomial << SHIFT);
        remainder = static_cast<CRCType>(remainder << SHIFT);

        while (size--)
        {
            remainder = static_cast<CRCType>(remainder ^ *current++);

            
            for (crcpp_size i = 0; i < CHAR_BIT; ++i)
            {
#ifdef CRCPP_BRANCHLESS
                
                
                
                
                
                remainder = static_cast<CRCType>((remainder << 1) ^ (((remainder >> CHAR_BIT_MINUS_ONE) & 1) * polynomial));
#else
                remainder = static_cast<CRCType>((remainder & CHAR_BIT_HIGHEST_BIT_MASK) ? ((remainder << 1) ^ polynomial) : (remainder << 1));
#endif
            }
        }

        remainder = static_cast<CRCType>(remainder >> SHIFT);
    }

    return remainder;
}











template <typename CRCType, crcpp_uint16 CRCWidth>
inline CRCType CRC::CalculateRemainder(const void * data, crcpp_size size, const Table<CRCType, CRCWidth> & lookupTable, CRCType remainder)
{
    const unsigned char * current = reinterpret_cast<const unsigned char *>(data);

    if (lookupTable.GetParameters().reflectInput)
    {
        while (size--)
        {
#if defined(WIN32) || defined(_WIN32) || defined(WINCE)
    
    
    
#   pragma warning (push)
#   pragma warning (disable : 4333)
#endif
            remainder = static_cast<CRCType>((remainder >> CHAR_BIT) ^ lookupTable[static_cast<unsigned char>(remainder ^ *current++)]);
#if defined(WIN32) || defined(_WIN32) || defined(WINCE)
#   pragma warning (pop)
#endif
        }
    }
    else if (CRCWidth >= CHAR_BIT)
    {
        
        static crcpp_constexpr CRCType SHIFT((CRCWidth >= CHAR_BIT) ? static_cast<CRCType>(CRCWidth - CHAR_BIT) : 0);

        while (size--)
        {
            remainder = static_cast<CRCType>((remainder << CHAR_BIT) ^ lookupTable[static_cast<unsigned char>((remainder >> SHIFT) ^ *current++)]);
        }
    }
    else
    {
        
        static crcpp_constexpr CRCType SHIFT((CHAR_BIT >= CRCWidth) ? static_cast<CRCType>(CHAR_BIT - CRCWidth) : 0);

        remainder = static_cast<CRCType>(remainder << SHIFT);

        while (size--)
        {
            
            remainder = lookupTable[static_cast<unsigned char>(remainder ^ *current++)];
        }

        remainder = static_cast<CRCType>(remainder >> SHIFT);
    }

    return remainder;
}

#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS












inline const CRC::Parameters<crcpp_uint8, 4> & CRC::CRC_4_ITU()
{
    static const Parameters<crcpp_uint8, 4> parameters = { 0x3, 0x0, 0x0, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint8, 5> & CRC::CRC_5_EPC()
{
    static const Parameters<crcpp_uint8, 5> parameters = { 0x09, 0x09, 0x00, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint8, 5> & CRC::CRC_5_ITU()
{
    static const Parameters<crcpp_uint8, 5> parameters = { 0x15, 0x00, 0x00, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint8, 5> & CRC::CRC_5_USB()
{
    static const Parameters<crcpp_uint8, 5> parameters = { 0x05, 0x1F, 0x1F, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint8, 6> & CRC::CRC_6_CDMA2000A()
{
    static const Parameters<crcpp_uint8, 6> parameters = { 0x27, 0x3F, 0x00, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint8, 6> & CRC::CRC_6_CDMA2000B()
{
    static const Parameters<crcpp_uint8, 6> parameters = { 0x07, 0x3F, 0x00, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint8, 6> & CRC::CRC_6_ITU()
{
    static const Parameters<crcpp_uint8, 6> parameters = { 0x03, 0x00, 0x00, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint8, 7> & CRC::CRC_7()
{
    static const Parameters<crcpp_uint8, 7> parameters = { 0x09, 0x00, 0x00, false, false };
    return parameters;
}
#endif 













inline const CRC::Parameters<crcpp_uint8, 8> & CRC::CRC_8()
{
    static const Parameters<crcpp_uint8, 8> parameters = { 0x07, 0x00, 0x00, false, false };
    return parameters;
}

#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS












inline const CRC::Parameters<crcpp_uint8, 8> & CRC::CRC_8_EBU()
{
    static const Parameters<crcpp_uint8, 8> parameters = { 0x1D, 0xFF, 0x00, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint8, 8> & CRC::CRC_8_MAXIM()
{
    static const Parameters<crcpp_uint8, 8> parameters = { 0x31, 0x00, 0x00, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint8, 8> & CRC::CRC_8_WCDMA()
{
    static const Parameters<crcpp_uint8, 8> parameters = { 0x9B, 0x00, 0x00, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 10> & CRC::CRC_10()
{
    static const Parameters<crcpp_uint16, 10> parameters = { 0x233, 0x000, 0x000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 10> & CRC::CRC_10_CDMA2000()
{
    static const Parameters<crcpp_uint16, 10> parameters = { 0x3D9, 0x3FF, 0x000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 11> & CRC::CRC_11()
{
    static const Parameters<crcpp_uint16, 11> parameters = { 0x385, 0x01A, 0x000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 12> & CRC::CRC_12_CDMA2000()
{
    static const Parameters<crcpp_uint16, 12> parameters = { 0xF13, 0xFFF, 0x000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 12> & CRC::CRC_12_DECT()
{
    static const Parameters<crcpp_uint16, 12> parameters = { 0x80F, 0x000, 0x000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 12> & CRC::CRC_12_UMTS()
{
    static const Parameters<crcpp_uint16, 12> parameters = { 0x80F, 0x000, 0x000, false, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 13> & CRC::CRC_13_BBC()
{
    static const Parameters<crcpp_uint16, 13> parameters = { 0x1CF5, 0x0000, 0x0000, false, false };
   return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 15> & CRC::CRC_15()
{
    static const Parameters<crcpp_uint16, 15> parameters = { 0x4599, 0x0000, 0x0000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 15> & CRC::CRC_15_MPT1327()
{
    static const Parameters<crcpp_uint16, 15> parameters = { 0x6815, 0x0000, 0x0001, false, false };
    return parameters;
}
#endif 













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_ARC()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x8005, 0x0000, 0x0000, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_BUYPASS()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x8005, 0x0000, 0x0000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_CCITTFALSE()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x1021, 0xFFFF, 0x0000, false, false };
    return parameters;
}

#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS












inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_CDMA2000()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0xC867, 0xFFFF, 0x0000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_CMS()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x8005, 0xFFFF, 0x0000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_DECTR()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x0589, 0x0000, 0x0001, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_DECTX()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x0589, 0x0000, 0x0000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_DNP()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x3D65, 0x0000, 0xFFFF, true, true };
    return parameters;
}
#endif 













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_GENIBUS()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x1021, 0xFFFF, 0xFFFF, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_KERMIT()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x1021, 0x0000, 0x0000, true, true };
    return parameters;
}

#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS












inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_MAXIM()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x8005, 0x0000, 0xFFFF, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_MODBUS()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x8005, 0xFFFF, 0x0000, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_T10DIF()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x8BB7, 0x0000, 0x0000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_USB()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x8005, 0xFFFF, 0xFFFF, true, true };
    return parameters;
}

#endif 













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_X25()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x1021, 0xFFFF, 0xFFFF, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint16, 16> & CRC::CRC_16_XMODEM()
{
    static const Parameters<crcpp_uint16, 16> parameters = { 0x1021, 0x0000, 0x0000, false, false };
    return parameters;
}

#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS












inline const CRC::Parameters<crcpp_uint32, 17> & CRC::CRC_17_CAN()
{
    static const Parameters<crcpp_uint32, 17> parameters = { 0x1685B, 0x00000, 0x00000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint32, 21> & CRC::CRC_21_CAN()
{
    static const Parameters<crcpp_uint32, 21> parameters = { 0x102899, 0x000000, 0x000000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint32, 24> & CRC::CRC_24()
{
    static const Parameters<crcpp_uint32, 24> parameters = { 0x864CFB, 0xB704CE, 0x000000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint32, 24> & CRC::CRC_24_FLEXRAYA()
{
    static const Parameters<crcpp_uint32, 24> parameters = { 0x5D6DCB, 0xFEDCBA, 0x000000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint32, 24> & CRC::CRC_24_FLEXRAYB()
{
    static const Parameters<crcpp_uint32, 24> parameters = { 0x5D6DCB, 0xABCDEF, 0x000000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint32, 30> & CRC::CRC_30()
{
    static const Parameters<crcpp_uint32, 30> parameters = { 0x2030B9C7, 0x3FFFFFFF, 0x00000000, false, false };
    return parameters;
}
#endif 













inline const CRC::Parameters<crcpp_uint32, 32> & CRC::CRC_32()
{
    static const Parameters<crcpp_uint32, 32> parameters = { 0x04C11DB7, 0xFFFFFFFF, 0xFFFFFFFF, true, true };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint32, 32> & CRC::CRC_32_BZIP2()
{
    static const Parameters<crcpp_uint32, 32> parameters = { 0x04C11DB7, 0xFFFFFFFF, 0xFFFFFFFF, false, false };
    return parameters;
}

#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS












inline const CRC::Parameters<crcpp_uint32, 32> & CRC::CRC_32_C()
{
    static const Parameters<crcpp_uint32, 32> parameters = { 0x1EDC6F41, 0xFFFFFFFF, 0xFFFFFFFF, true, true };
    return parameters;
}
#endif













inline const CRC::Parameters<crcpp_uint32, 32> & CRC::CRC_32_MPEG2()
{
    static const Parameters<crcpp_uint32, 32> parameters = { 0x04C11DB7, 0xFFFFFFFF, 0x00000000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint32, 32> & CRC::CRC_32_POSIX()
{
    static const Parameters<crcpp_uint32, 32> parameters = { 0x04C11DB7, 0x00000000, 0xFFFFFFFF, false, false };
    return parameters;
}

#ifdef CRCPP_INCLUDE_ESOTERIC_CRC_DEFINITIONS












inline const CRC::Parameters<crcpp_uint32, 32> & CRC::CRC_32_Q()
{
    static const Parameters<crcpp_uint32, 32> parameters = { 0x814141AB, 0x00000000, 0x00000000, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint64, 40> & CRC::CRC_40_GSM()
{
    static const Parameters<crcpp_uint64, 40> parameters = { 0x0004820009, 0x0000000000, 0xFFFFFFFFFF, false, false };
    return parameters;
}













inline const CRC::Parameters<crcpp_uint64, 64> & CRC::CRC_64()
{
    static const Parameters<crcpp_uint64, 64> parameters = { 0x42F0E1EBA9EA3693, 0x0000000000000000, 0x0000000000000000, false, false };
    return parameters;
}
#endif 

#ifdef CRCPP_USE_NAMESPACE
}
#endif

#endif 
