




	
#define MAX_TRADE_ITEM			20
#define MAX_CRAFTITEM_INFO		300
#define MAX_AGINGITEM_INFO		100
#define MAX_MAKEITEM_INFO		100

#define T_SET_BOX				0
#define T_MONEY_POSI			1
#define T_MONEY_TEXT_POSI		2
#define T_WEIGHT_TEXT_POSI		3
#define T_CHECK_POSI			4
#define T_CLOSE_POSI			5
#define T_COIN_POSI             6
#define T_COIN_TEXT_POSI		7
#define T_TRADE_CLOSE_POSI		8


#define MAX_SHELTOM				17	
#define MAX_AGING				20	
#define MAX_RUNE				14	
#define MAX_RECIPE_KIND			11	
#define MAX_RECIPE_ITEM			60	
#define MAX_HANDMADEITEM		176 

#define MAX_SEEL_COUNT			5	



struct sTRADE{
	sITEM TradeItem[MAX_TRADE_ITEM]; 
	int Money;			
	int Coin;
	int Weight;			
	int CheckFlag;		
	int CheckMoney;
};


struct sWAREHOUSE{
	sITEM WareHouseItem[100]; 
	int Money;
	short Weight[2];
	int BuyAreaCount; 
	int FakeMoney;


};


struct sCRAFTITEM{
	sITEM CraftItem[15];	
	int   SheltomIndex[12];

};


struct sCRAFTITEM_SERVER{
	int size, code;
	int DocIndex;
	int Result;
	sITEM DesCraftItem;
	DWORD SheltomCode[12];
	DWORD Head[12];
	DWORD CheckSum[12];
	int  Index;
	int  Money;

	DWORD A_StoneItemCode;
	DWORD A_StoneHead;
	DWORD A_StoneCheckSum;
};


struct sCRAFTITEM_INFO{
	DWORD MainItemCode[8];	
	int AddItem[20];			
	int PlusElementCode[8];	
	float AddElement[8];	
	int ElementKind[8];		
	char Doc[256];			

};
























struct sREMODEL_ITEM
{
	sITEM	RemodelItem[2];
};


struct sREMODEL_ITEM_SERVER
{
	int		size, code;
	int		DocIndex;
	int		Result;
	int		Index;

	sITEM	DesRemodelItem;

	DWORD	dwRemodelStoneItemCode;
	DWORD	dwRemodelStoneHead;
	DWORD	dwRemodelStoneCheckSum;
};

struct sAGINGITEM{
	sITEM AgingItem[15];	
	int   SheltomIndex[12];	
	int   AgingOkFlag;	    

};

struct sAGINGITEM_INFO{
	DWORD MainItemCode;		
	int PlusElementCode[8];	
	float AddElement[8];	
	int ElementKind[8];		
	char Doc[128];			

};


struct sMAKEITEM_INFO{
	DWORD CODE[15];			
	DWORD Result_CODE;		

};

struct sPOSTBOX_ITEM{
	char	szName[64];
	DWORD	CODE;
};


struct sRECON_ITEM{
	DWORD  dwCODE;    
	int	   iLevel[2]; 
	int	   iCount;    
	int    iPrice;    
};























































































class cAGING{
public:

	int OpenFlag;
	int AgingItemCheckSum;
	LPDIRECT3DTEXTURE9	lpGraySheltom[MAX_SHELTOM];

public:
	
	int  AginStoneKind;         
								
								
                                
	
public:

	int  AgingItem(int MakeItemFlag =0);		
	int  CancelAgingItem(int Flag=0);	
	int  CheckItem(sITEM *pItem);		
	int  CheckAgingItemOk(); 

	int  SetAgingItemAreaCheck(sITEM *pItem );	
	
	
	int  CheckAgingData();

	
	int sinSendAgingItem();
	int sinRecvAgingItem(sCRAFTITEM_SERVER *pCraftItem_Server);
	int sinRecvAgingItemResult(sCRAFTITEM_SERVER *pCraftItem_Server);

	bool isSheltomAreaEmpty(sITEM* Item, int Area);
	bool isAgeableItem(sITEM * pItem);
	bool isItemAreaEmpty();
	bool isStoneAreaEmpty();

};






































class cREMODEL
{
public:

	int	OpenFlag;
	int	RemodelItemCheckSum;
	int	HaveMixtureResetStone;

public:

	int IsStone(DWORD Code);
	int IsItem(DWORD Code, DWORD Class);
	int	SetRemodelItemAreaCheck(sITEM *pItem);
	int PickUpRemodelItem(int x, int y, int PickUpFlag = 0, int Kind = 0);
	int LastSetRemodelItem(sITEM *pItem, int kind);
	int	CancelRemodelItem(int Flag = 0);
	int	CheckRemodelItemForm();
	int	ReformRemodelItem();



	int	RemodelItem();
	int	CheckItem();
	int	CheckRemodelItemOk();
	int	CheckRemodelItemData();



	int	sinSendRemodelItem();
	int	sinRecvRemodelItem(sREMODEL_ITEM_SERVER * pRemodelItem);
	int	sinRecvRemodelItemResult(sREMODEL_ITEM_SERVER * pRemodelItem_Server);
};



























































class cCRAFTITEM{
public:
	int OpenFlag;
	int CraftItemCheckSum;
	int ForceFlag;
	int ForceItemPrice;
	int iReconItemFlag;
public:

	int SetCraftItemAreaCheck(sITEM *pItem,int Kind=0); 
	int LastSetCraftItem(sITEM *pItem,int Kind=0);
	int PickUpCraftItem(int x , int y , int PickUpFlag=0,int Kind=0); 

	
	int MixingItem();

	
	int CraftCheckEmptyArea(sITEM *pItem);
	int CancelMixItem(); 

	int CheckHackCraftItem(); 
	int CheckCraftItemForm(); 
	int ReFormCraftItem();    

	int sinSendCraftItem();	  
	int sinRecvCraftItem(sCRAFTITEM_SERVER *pCraftItem_Server);   

	
	int sinRecvCraftItemResult(sCRAFTITEM_SERVER *pCraftItem_Server);

	
	int CheckForceOrbPrice();
	int CheckForceOrbPrice(sITEM *pItem);

	
	int haCheckReconItem(); 
	int haSendReconItem();  
	




	
	int GetCraftCheckEmptyArea();
	
	int haCraftSortItem(sCRAFTITEM *pCraftItem);

	bool isSheltomAreaEmpty(sITEM* Item, int Area);
	bool isMixableItem(sITEM* Item);

	bool isItemAreaEmpty();
	bool isStoneAreaEmpty();
};







class cWAREHOUSE{
public:
	int OpenFlag;	
	int WareHouseCheckSum;

public:

	int SetWareHouseItemAreaCheck(sITEM *pItem); 
	int CrashWareHouseItem(RECT &desRect, int PassItemIndex=0); 
	int ChangeWareHouseItem(sITEM *pItem); 
	int LastSetWareHouseItem(sITEM *pItem); 
	int PickUpWareHouseItem(int x , int y , int PickUpFlag=0); 

	
	int GetWeight();

	
	int LoadWareHouseItemIamge();	
	
	
	int BackUpInvenItem();
	bool cWAREHOUSE::GetEmptyArea(sITEM * pItem, POINT * EmptyPos);
	bool cWAREHOUSE::CanStoreItem(sITEM * pItem);
	int RestoreInvenItem(); 
	
	int CloseWareHouse();

	
	int ReFormWareHouse();
	int CheckWareHouseForm();

	
	int CopyItemNotPickUp(sITEM *pItem,int JumpIndex);
	int CheckCopyItem(); 
	int DeleteCopyItem(); 
	int SendItemToIven(int x, int y, int PickUpFlag = 0);
};




class cTRADE{

public:

	int OpenFlag;
	int MatTrade[4];
	int MatWareHouse[3]; 
	int MatTradebuttonMain;
	int MatTradebuttonCancel;
	int LpButtonYes;
	int LpButtonYes_;
	int LpButtonNo;
	int LpButtonNo_;

	LPDIRECT3DTEXTURE9 lpbuttonCancel;

	LPDIRECT3DTEXTURE9 lpbuttonCancelInfo;

	LPDIRECT3DTEXTURE9 lpbuttonOk;
	LPDIRECT3DTEXTURE9 lpCheck;

	LPDIRECT3DTEXTURE9 lpCheck_Glay;
	LPDIRECT3DTEXTURE9 lpCheckInfo;
	LPDIRECT3DTEXTURE9 lpDelayCheck;

	LPDIRECT3DTEXTURE9 lpCenterBox;

	sITEM CheckItem[100];
	sITEM CheckRecvItem[MAX_TRADE_ITEM];

	
	int   TradeRequestFlag;
	DWORD TradeCharCode;
	char  szTradeCharName[64];

	int   TradeItemCheckSum;



public:
	cTRADE();
	~cTRADE();

	void Init(); 
	void Load();
	void Release();
	void DrawImage(int Image, int x, int y, int w, int h);
	void Draw();
	void Close();
	void Main();
	void LButtonDown(int x , int y);
	void LButtonUp(int x , int y);
	void RButtonDown(int x , int y);
	void RButtonUp(int x, int y);
	void KeyDown(); 

	void DrawTradeText(); 

	
	int SetTradeItemAreaCheck(sITEM *pItem); 
	int CrashTradeItem(RECT &desRect, int PassItemIndex=0 , int Kind=0); 
	int InitTradeColorRect(); 
	int ChangeTradeItem(sITEM *pItem); 
	int LastSetTradeItem(sITEM *pItem); 
	int PickUpTradeItem(int x , int y , int PickUpFlag=0); 

	
	int CheckTradeItemSet(); 
	int TradeCheckEmptyArea(sITEM *pItem); 
	int ChecketInvenItem(sITEM *pItem); 

	
	int CheckOkTradeItem();			
	int CancelTradeItem();			
	int LoadTradeItemIamge();		

	
	int CheckTradeButtonOk();		

	
	int GetWeight();

	
	int CheckTradeItemForm();	
	int ReFormTradeItem();		

	int SendItemToIven(int x, int y, int PickUpFlag = 0);

	bool GetEmptyArea(sITEM * pItem, POINT * EmptyPos);

	bool IsItemOkay(sITEM * pItem);
};



int CopyMixItemCheckDelete(sITEM *pItem);
int sinMakeItemCheck(); 
int sinPosBoxNpc();     

extern cTRADE cTrade;
extern sTRADE sTrade;
extern sTRADE sTradeRecv;

extern int RequestTradeButtonFlag; 
	   
extern cWAREHOUSE cWareHouse; 
extern sWAREHOUSE sWareHouse; 
extern sITEM *BackUpInvenItem2; 


extern cCRAFTITEM cCraftItem;	












extern sCRAFTITEM sCraftItem;
extern sCRAFTITEM_INFO sCraftItem_Info[MAX_CRAFTITEM_INFO]; 

extern sCRAFTITEM_SERVER sCraftItem_Send; 
extern sCRAFTITEM_SERVER sCraftItem_Recv; 

extern sCRAFTITEM_SERVER sAging_Send; 
extern sCRAFTITEM_SERVER sAging_Recv; 


extern int ShowItemCraftMessageFlag; 
extern int ShowItemAgingMessageFlag; 
extern int ShowItemSmeltingMessageFlag; 
extern int ShowItemManufactureMessageFlag; 
extern int ShowItemOverSpace;	

extern int TempShowMoney;	  
extern int TempShowCoin;
extern int ItemPickUpFlag;	  
extern int WareHouseSaveFlag;


extern cAGING	cAging;		  
extern sAGINGITEM sAgingItem;
extern sAGINGITEM_INFO sAgingItem_Info[MAX_AGINGITEM_INFO];

extern int AgingLevelAttack[20];
extern int AgingLevelCritical[20];

extern char szAgingItemBuff[128];
extern POINT CraftItemMessageSize;

extern int AgingCheckSheltomFlag; 
extern int AgingSheltomCnt2;
extern int MixItemNoCopyFlag;
extern int CheckMixItemCopyFlag;
extern sMAKEITEM_INFO sMakeItem_Info[MAX_MAKEITEM_INFO];









extern cREMODEL cRemodel;
extern sREMODEL_ITEM	sRemodelItem;
extern sREMODEL_ITEM sRemodelItemBackUp;
extern int RemodelCheckFlag;
extern sREMODEL_ITEM_SERVER	sRemodel_Send;
extern sREMODEL_ITEM_SERVER	sRemodel_Recv;

extern char *PostBoxDocFilePath[];

extern sPOSTBOX_ITEM sPostbox_Item[50];
extern int PostBoxIndexCnt;
extern DWORD ExpressItemCode;
extern char  szExpressItemName[64]; 

extern sCRAFTITEM_SERVER sWingItem_Send; 
extern sCRAFTITEM_SERVER sWingItem_Recv; 

extern int DownTradePosi[9][4];
extern DWORD SheltomCode2[];
extern DWORD MagicSheltomCode[]; 
extern DWORD BillingMagicSheltomCode[]; 
extern int ForceItemPrice2;
extern sRECON_ITEM sReconItem[MAX_SEEL_COUNT]; 
extern int		MixCancelButtonDelayFlag; 
