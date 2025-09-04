#pragma once

#include <Windows.h>
#include "sinbaram/sinLinkHeader.h"
#include "smwsock.h"
#include "smPacket.h"

#define WNDPROC_SOCKETACCEPT( window, socket, address )		( SendMessageA( window, WSA_ACCEPT, (WPARAM)socket, (LPARAM)address ) )
#define WNDPROC_SOCKETPACKET( window, socketdata, packet )	( PostMessageA( window, SWM_RECVSUCCESS, (WPARAM)socketdata, (LPARAM)packet ) )
#define WNDPROC_SOCKETCLOSE( window, socketdata )			( PostMessageA( window, SWM_MDISCONNECT, (WPARAM)socketdata, (LPARAM)NULL ) )

#define RELEASE(p)			{ if(p != NULL) p->Release(); p = NULL;}
#define INIT(p)				{ if(p != NULL) p->Init();}
#define INITP(p, ptr)		{ if(p != NULL && ptr != NULL) p->Init(ptr);}
#define DELET(p)			{ if(p != NULL) delete p; p = NULL;}
#define DELETA(p)			{ if(p != NULL) delete[] p; p = NULL;}
#define SHUTDOWN(p)			{ if(p != NULL) p->Shutdown();}
#define ADDREF(p)			{ if(p != NULL) p->AddRef();}
#define CLEARPTR(p)			{ if(p != NULL) p->Clear();}
#define RESETPTR(p)			{ if(p != NULL) p.reset(); p = NULL;}


#define MAX_LAGGRACE		1000 * 60 * 10
#define NUM_ENCKEYS			256

extern const BOOL SOCKET_NODELAY;

extern const int RCVWND_SIZE;
extern const int SNDWND_SIZE;

struct Packet 
{
	int	  iLength;				
	int	  iHeader;				
}; 

struct PacketSending
{
	union
	{
		BOOL	  bInUse;
		UINT	  uCount;
	};
	UINT		  uSize;
	BYTE		  baPacket[smSOCKBUFF_SIZE];
};

struct PacketReceiving
{
	BOOL		  bInUse;
	BOOL		  bDelete;
	BYTE		  baPacket[smSOCKBUFF_SIZE];
	DWORD		  recvTime;
	DWORD		  recvTime2;
};

struct PacketPing : Packet
{
	DWORD	  dwTime;
	DWORD	  dwTick;
};

class SocketData
{
public:
	
	SocketData			* pcThis;

	
	bool				  bInUse;
	bool				  bConnecting;
	bool				  bConnected;
	bool				  bReserved;

	
	SOCKET				  s;
	rsPLAYINFO			* ud;
	smWINSOCK			* u;

	
	char				  szIP[32];
	long				  lIP;
	int					  iPort;

	
	DWORD				  dwTimeLastPacketReceived;

	
	UINT				  iDefReceivePacket;
	UINT				  iMaxReceivePacket;
	HANDLE				  hReceiveThread;
	HANDLE				  hReceiveThreadSignal;
	CMutex				* pcReceiveMutex;
	UINT				  iReceiveWheel;
	PacketReceiving		* psaPacketReceiving;

	
	UINT				  iDefSendPacket;
	UINT				  iMaxSendPacket;
	HANDLE				  hSendEvent;
	HANDLE				  hSendThread;
	HANDLE				  hSendThreadSignal;
	CMutex				* pcSendMutex;
	UINT				  iSendWheel;
	UINT				  iSendingWheel;
	PacketSending		* psaPacketSending;
	BOOL				  bBlockSend;
	DWORD				  dwBulkThreadId;
	PacketSending		  sBulkPacket;

	
	bool				  bKeySet;
	BYTE				  baKeySet[NUM_ENCKEYS];
	BYTE				  bNextKey;
	int					  iIPIndex;

	
	bool				  bPing;
	DWORD				  dwPingTime;
	int					  iPing;

	
	UINT				  iCountIN;
	UINT				  iCountOUT;
	UINT				  iCountOUTB;

	
	int					  iRecvRet;
	int					  iRecvEC;
	int					  iSendRet;
	int					  iSendEC;

	BOOL				  bKeepAlive;

public:
	
	SocketData();
	~SocketData();

	void				  Prepare(UINT iMaxSendPacket, UINT iMaxReceivePacket);

	
	void				  Init();
	void				  UnInit();

	
	bool				  Connect(const char * pszIP, int iPort);
	void				  Open(smWINSOCK* s, sockaddr_in * addr);
	void				  Close();

	
	PacketReceiving		* FreePacketReceiving();
	void				  FreePacketReceiving(PacketReceiving * pp);

	PacketReceiving		* ReceivePacket();

	
	PacketSending		* NextPacketSending();
	void				  FreePacketSending(PacketSending * pp);

private:
	
	BOOL				  Send(BYTE * pbData, UINT uSize);
	BOOL				  SendData(BYTE * pbData, UINT uSize);

	
	PacketSending		* FindAutomaticBulk(UINT uSizeNeeded);

public:
	
	BOOL				  Send(PacketSending * pp);

	
	BOOL				  SendPacket(Packet * p, BOOL bEncrypted = FALSE);
	BOOL				  SendPacketBlank(DWORD iHeader, BOOL bEncrypted = FALSE);

	
	BOOL				  StartBulkSend();
	BOOL				  FlushBulkSend();
	BOOL				  StopBulkSend();

	

	BYTE				  GetNextIPIndex();
	BYTE				  ValIPIndex(BYTE iIndex, Packet * p);

	
	void				  SetPing(int i) { iPing = i; bPing = false; }
	int					  GetPing(DWORD dwTime);

};
