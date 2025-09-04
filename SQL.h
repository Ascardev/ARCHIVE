














#pragma once

#include <sqltypes.h>
#include <sqlext.h>
#include "CMutex.h"
#include "date.h"

#define MAX_PARAMS		10000
#define MAX_QUERY_SIZE	2048

enum EParamType
{
	PARAMTYPE_String			= 0,
	PARAMTYPE_Integer			= 1,
	PARAMTYPE_BigInteger		= 2,
	PARAMTYPE_Time				= 3,
	PARAMTYPE_TimeNow			= 4,
	PARAMTYPE_TimeSet			= 5,
	PARAMTYPE_Binary			= 6,
	PARAMTYPE_SmallInteger		= 7,
	PARAMTYPE_TinyInteger		= 8,
	PARAMTYPE_Float				= 9
};

enum EDebugMethod
{
	DEBUGMETHOD_None			= 0,
	DEBUGMETHOD_Constructor		= 1,
	DEBUGMETHOD_Destructor		= 2,
	DEBUGMETHOD_Connect			= 11,
	DEBUGMETHOD_Reconnect		= 12,
	DEBUGMETHOD_Disconnect		= 13,
	DEBUGMETHOD_Open			= 21,
	DEBUGMETHOD_Clear			= 22,
	DEBUGMETHOD_Close			= 23,
	DEBUGMETHOD_Prepare			= 31,
	DEBUGMETHOD_Execute			= 41,
	DEBUGMETHOD_ExecuteDirect	= 42,
};

class SQLFetchedRow
{
private:

public:
						  SQLFetchedRow();
	virtual				 ~SQLFetchedRow();
};

class SQLColumn
{
protected:
	int					  index;	
	string				  name;		
	SQLSMALLINT			  sql_type;	
	size_t				  size;		

public:
						  SQLColumn( int _index, string _name, SQLSMALLINT _sql_type, size_t _size = 0 );
	virtual				 ~SQLColumn() {}

	string				  GetName() { return name; }
	SQLSMALLINT			  GetSQLType() { return sql_type; }
	size_t				  GetSize() { return size; }
};












class SQLBoundColumn : public SQLColumn
{
	friend class SQLConnection;

protected:
	int					  iRows;
	void				* pvBuffer;
	int					  iBufferSize;
	SQLLEN				* piIndicator;

public:
						  SQLBoundColumn( int _index, string _name, SQLSMALLINT _sql_type, size_t _size = 0 );
	virtual				 ~SQLBoundColumn();

	void				  Bind( int _iRows );
};







class SQLConnection
{
private:
	BOOL				  bNoOpen;		
	BOOL				  bConnected;	
	BOOL				  bReset;		
	char				  szConnectionString[256];	
	char				  szDBName[64];

	SQLHENV				  hEnv;
	SQLHDBC				  hDbc;
	SQLHSTMT			  hStmt;
	CMutex				* pcMutex;
	char				  szLastError[256];
	SQLRETURN			  retcode;

	BOOL				  bOpen;
	BOOL				  bPrepared;

	bool				  baBlock[MAX_PARAMS];
	SQLINTEGER			  iaBlock[MAX_PARAMS];
	SQLINTEGER			* BlockNext();
	void				  BlockFree();

	BOOL				  bBulkSelect;
	int					  iRowsPerFetch;
	int					  iRowsFetched;
	int					  iRowWheel;
	SQLUSMALLINT		* piaRowStatus;

	bool				  bAdditionalSecurity;
	char				  szCurrentQuery[MAX_QUERY_SIZE];

	EDebugMethod		  iDebugMethod;
public:
						  SQLConnection( char * pszConnectionString, char * pszDBName );
	virtual				 ~SQLConnection();

	BOOL				  Connect();
	BOOL				  Reconnect();
	void				  Disconnect();

	void				  Error( char * pszError );
	void				  Error( SQLSMALLINT iHandleType );
	void				  HandleError( char * pszFormat, ... );

	BOOL				  Open( bool bAdditionalSecurity = false );

	bool				  Prepare( char * pszQuery, ... );
	bool				  Check( char * pszQuery );
	void				  BulkSelect( int iRowsPerFetch );

	bool				  BindCol( int iColumn, EParamType iParamType, void * pvBuffer, int iBufferSize );
	bool				  BindParameterInput( int iParam, EParamType iParamType, void * pvBuffer = NULL, int iBufferSize = 0 );

	bool				  Fetch( int iRow = -1 );
	bool                  Fetch2();
	int					  FetchScroll();

	bool				  GetData( int iParam, EParamType iParamType, void * pvBuffer = NULL, int iBufferSize = 0 );
	int					  GetLastRow();

	bool				  Execute();
	bool				  Execute( char * pszQuery );

	void				  Clear();
	void				  Close();

	static BOOL			  IsSafeUserInput( const char * pszInput );

};
