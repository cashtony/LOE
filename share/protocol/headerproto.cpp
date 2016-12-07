#include "headerproto.h"

CHeaderProto::CHeaderProto()
{
	memset(m_EncodeFuncArray, 0, sizeof(m_EncodeFuncArray));
	memset(m_DecodeFuncArray, 0, sizeof(m_DecodeFuncArray));
	Init();
}

CHeaderProto::~CHeaderProto()
{
}

int CHeaderProto::Encode(int iMsgID, const void *pHost, char *pNet, int iNetSize)
{
	INetData *poData = m_poData ? m_poData : &m_oData;
	poData->Prepare(pNet, iNetSize);

	EnFuncCHeaderProto pfnEncode = FindEncodeFunc(iMsgID);
	if(NULL == pfnEncode)
		return -1;

	++m_iPkgEncodeCount[iMsgID - HEADERPROTO_MSGID_OFFSET];

	return (*pfnEncode)(pHost, poData);
}

int CHeaderProto::Decode(int iMsgID, const char *pNet, int iNetSize, void *pHost, int iHostSize)
{
	INetData *poData = m_poData ? m_poData : &m_oData;
	poData->Prepare(const_cast<char *>(pNet), iNetSize);

	DeFuncCHeaderProto pfnDecode = FindDecodeFunc(iMsgID);
	if(NULL == pfnDecode)
		return -1;

	if(iHostSize < m_iPkgSizeArray[iMsgID - HEADERPROTO_MSGID_OFFSET])
		return -1;
	++m_iPkgDecodeCount[iMsgID - HEADERPROTO_MSGID_OFFSET];

	return (*pfnDecode)(pHost, poData);
}

EnFuncCHeaderProto CHeaderProto::FindEncodeFunc(int iMsgID)
{
	int iMsgIndex = iMsgID - HEADERPROTO_MSGID_OFFSET; 
	if(iMsgIndex >= HEADERPROTO_MSGID_RANGE || iMsgIndex < 0)
		return NULL;
	return m_EncodeFuncArray[iMsgIndex];
}

DeFuncCHeaderProto CHeaderProto::FindDecodeFunc(int iMsgID)
{
	int iMsgIndex = iMsgID - HEADERPROTO_MSGID_OFFSET; 
	if(iMsgIndex >= HEADERPROTO_MSGID_RANGE || iMsgIndex < 0)
		return NULL;
	return m_DecodeFuncArray[iMsgIndex];
}

bool CHeaderProto::Init()
{
	m_poData = 0;
	memset(m_iPkgEncodeCount, 0, sizeof(m_iPkgEncodeCount));
	memset(m_iPkgDecodeCount, 0, sizeof(m_iPkgDecodeCount));
#ifdef CHeaderProto_ID2NAME_DES
	memset(m_arrPkgID2Name, 0, sizeof(m_arrPkgID2Name));
#endif

	return true;
}

int CHeaderProto::GetPkgEncodeCount(int iMsgID)
{
	if(iMsgID - HEADERPROTO_MSGID_OFFSET >= HEADERPROTO_MSGID_RANGE)
		return NULL;
	return m_iPkgEncodeCount[iMsgID - HEADERPROTO_MSGID_OFFSET];
}

int CHeaderProto::GetPkgDecodeCount(int iMsgID)
{
	if(iMsgID - HEADERPROTO_MSGID_OFFSET >= HEADERPROTO_MSGID_RANGE)
		return NULL;
	return m_iPkgDecodeCount[iMsgID - HEADERPROTO_MSGID_OFFSET];
}

#ifdef HEADERPROTO_ID2NAME_DES
const char* CHeaderProto::GetPkgName(int iMsgID)
{
   if(iMsgID - HEADERPROTO_MSGID_OFFSET >= HEADERPROTO_MSGID_RANGE)
		return NULL;
   return m_arrPkgID2Name[iMsgID - HEADERPROTO_MSGID_OFFSET];
}
#endif

int EncodeSError(const void *pHost, INetData* poNetData)
{
	const SError *pstIn = (const SError*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nType, "Type"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szError, sizeof(pstIn->szError), "Error"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSError(void *pHost, INetData* poNetData)
{
	SError *pstOut = (SError*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nType, "Type"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szError, sizeof(pstOut->szError), "Error"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSPosInfo(const void *pHost, INetData* poNetData)
{
	const SPosInfo *pstIn = (const SPosInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nX, "X"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nY, "Y"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nZ, "Z"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nOrientation, "Orientation"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSPosInfo(void *pHost, INetData* poNetData)
{
	SPosInfo *pstOut = (SPosInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nX, "X"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nY, "Y"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nZ, "Z"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nOrientation, "Orientation"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRoleDBInfo(const void *pHost, INetData* poNetData)
{
	const SRoleDBInfo *pstIn = (const SRoleDBInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nDBIndex, "DBIndex"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nHP, "HP"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nSP, "SP"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nEP, "EP"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nVipEP, "VipEP"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nAP, "AP"))
		return -1;

	if(-1 == poNetData->AddInt64(pstIn->llExperience, "Experience"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwNonMoney, "NonMoney"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwNonCash, "NonCash"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwCash, "Cash"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwLatestWorldChatTime, "LatestWorldChatTime"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szXData, sizeof(pstIn->szXData), "XData"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szXData2, sizeof(pstIn->szXData2), "XData2"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szXData3, sizeof(pstIn->szXData3), "XData3"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szActivityInfo, sizeof(pstIn->szActivityInfo), "ActivityInfo"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szShop, sizeof(pstIn->szShop), "Shop"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szClentCfg, sizeof(pstIn->szClentCfg), "ClentCfg"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRoleDBInfo(void *pHost, INetData* poNetData)
{
	SRoleDBInfo *pstOut = (SRoleDBInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nDBIndex, "DBIndex"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nHP, "HP"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nSP, "SP"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nEP, "EP"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nVipEP, "VipEP"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nAP, "AP"))
		return -1;

	if(-1 == poNetData->DelInt64(pstOut->llExperience, "Experience"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwNonMoney, "NonMoney"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwNonCash, "NonCash"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwCash, "Cash"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwLatestWorldChatTime, "LatestWorldChatTime"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szXData, sizeof(pstOut->szXData), "XData"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szXData2, sizeof(pstOut->szXData2), "XData2"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szXData3, sizeof(pstOut->szXData3), "XData3"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szActivityInfo, sizeof(pstOut->szActivityInfo), "ActivityInfo"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szShop, sizeof(pstOut->szShop), "Shop"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szClentCfg, sizeof(pstOut->szClentCfg), "ClentCfg"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSItemInfo(const void *pHost, INetData* poNetData)
{
	const SItemInfo *pstIn = (const SItemInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byIndex, "Index"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySlot, "Slot"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byExInfoIndex, "ExInfoIndex"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byMakerInfoIndex, "MakerInfoIndex"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byTimeInfoIndex, "TimeInfoIndex"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wCount, "Count"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwFlag, "Flag"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byPersonalFlag, "PersonalFlag"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwObjId, "ObjId"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwItemUUId, "ItemUUId"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSItemInfo(void *pHost, INetData* poNetData)
{
	SItemInfo *pstOut = (SItemInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byIndex, "Index"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySlot, "Slot"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byExInfoIndex, "ExInfoIndex"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byMakerInfoIndex, "MakerInfoIndex"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byTimeInfoIndex, "TimeInfoIndex"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wCount, "Count"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwFlag, "Flag"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byPersonalFlag, "PersonalFlag"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwObjId, "ObjId"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwItemUUId, "ItemUUId"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRollItemData(const void *pHost, INetData* poNetData)
{
	const SRollItemData *pstIn = (const SRollItemData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byType, "Type"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwID, "ID"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wNum, "Num"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nBroadcastFlag, "BroadcastFlag"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRare, "Rare"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRollItemData(void *pHost, INetData* poNetData)
{
	SRollItemData *pstOut = (SRollItemData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byType, "Type"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwID, "ID"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wNum, "Num"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nBroadcastFlag, "BroadcastFlag"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRare, "Rare"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRollData_Common(const void *pHost, INetData* poNetData)
{
	const SRollData_Common *pstIn = (const SRollData_Common*)pHost;
	poNetData->EnterStruct();

	(void*)pstIn;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRollData_Common(void *pHost, INetData* poNetData)
{
	SRollData_Common *pstOut = (SRollData_Common*)pHost;
	poNetData->EnterStruct();

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRollData_Money(const void *pHost, INetData* poNetData)
{
	const SRollData_Money *pstIn = (const SRollData_Money*)pHost;
	poNetData->EnterStruct();

	(void*)pstIn;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRollData_Money(void *pHost, INetData* poNetData)
{
	SRollData_Money *pstOut = (SRollData_Money*)pHost;
	poNetData->EnterStruct();

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRollData_Cell(const void *pHost, INetData* poNetData)
{
	const SRollData_Cell *pstIn = (const SRollData_Cell*)pHost;
	poNetData->EnterStruct();

	(void*)pstIn;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRollData_Cell(void *pHost, INetData* poNetData)
{
	SRollData_Cell *pstOut = (SRollData_Cell*)pHost;
	poNetData->EnterStruct();

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRollPoolItem(const void *pHost, INetData* poNetData)
{
	const SRollPoolItem *pstIn = (const SRollPoolItem*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTemplate, "Template"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nNum, "Num"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRollPoolItem(void *pHost, INetData* poNetData)
{
	SRollPoolItem *pstOut = (SRollPoolItem*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTemplate, "Template"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nNum, "Num"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSBaseItemInfo(const void *pHost, INetData* poNetData)
{
	const SBaseItemInfo *pstIn = (const SBaseItemInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nNum, "Num"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSBaseItemInfo(void *pHost, INetData* poNetData)
{
	SBaseItemInfo *pstOut = (SBaseItemInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nNum, "Num"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSMultiItems(const void *pHost, INetData* poNetData)
{
	const SMultiItems *pstIn = (const SMultiItems*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nTypeCount, "TypeCount"))
		return -1;

	int i;
	if ((int)pstIn->nTypeCount > MAX_ITEM_COUNT || pstIn->nTypeCount < 0)
       return -1;
	for(i = 0; i < MAX_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstIn->nTypeCount)
			break;
		if(-1 == EncodeSBaseItemInfo(&pstIn->astItems[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSMultiItems(void *pHost, INetData* poNetData)
{
	SMultiItems *pstOut = (SMultiItems*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nTypeCount, "TypeCount"))
		return -1;

	int i;
	if ((int)pstOut->nTypeCount > MAX_ITEM_COUNT || pstOut->nTypeCount < 0)
       return -1;
	for(i = 0; i < MAX_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstOut->nTypeCount)
			break;
		if(-1 == DecodeSBaseItemInfo(&pstOut->astItems[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSBlob(const void *pHost, INetData* poNetData)
{
	const SBlob *pstIn = (const SBlob*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwLen, "Len"))
		return -1;

   if (pstIn->dwLen > MAX_BLOB_LEN)
		return -1;
	if(-1 == poNetData->AddBuf(pstIn->abyData, pstIn->dwLen, "Data"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSBlob(void *pHost, INetData* poNetData)
{
	SBlob *pstOut = (SBlob*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwLen, "Len"))
		return -1;

   if (pstOut->dwLen > MAX_BLOB_LEN)
		return -1;
	if(-1 == poNetData->DelBuf(pstOut->abyData, pstOut->dwLen, "Data"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSBigBlob(const void *pHost, INetData* poNetData)
{
	const SBigBlob *pstIn = (const SBigBlob*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwLen, "Len"))
		return -1;

   if (pstIn->dwLen > MAX_BIGBLOB_LEN)
		return -1;
	if(-1 == poNetData->AddBuf(pstIn->abyData, pstIn->dwLen, "Data"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSBigBlob(void *pHost, INetData* poNetData)
{
	SBigBlob *pstOut = (SBigBlob*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwLen, "Len"))
		return -1;

   if (pstOut->dwLen > MAX_BIGBLOB_LEN)
		return -1;
	if(-1 == poNetData->DelBuf(pstOut->abyData, pstOut->dwLen, "Data"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSMediumBlob(const void *pHost, INetData* poNetData)
{
	const SMediumBlob *pstIn = (const SMediumBlob*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwLen, "Len"))
		return -1;

   if (pstIn->dwLen > MAX_MEDIUMBLOB_LEN)
		return -1;
	if(-1 == poNetData->AddBuf(pstIn->abyData, pstIn->dwLen, "Data"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSMediumBlob(void *pHost, INetData* poNetData)
{
	SMediumBlob *pstOut = (SMediumBlob*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwLen, "Len"))
		return -1;

   if (pstOut->dwLen > MAX_MEDIUMBLOB_LEN)
		return -1;
	if(-1 == poNetData->DelBuf(pstOut->abyData, pstOut->dwLen, "Data"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSBigMoreBlob(const void *pHost, INetData* poNetData)
{
	const SBigMoreBlob *pstIn = (const SBigMoreBlob*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwLen, "Len"))
		return -1;

   if (pstIn->dwLen > MAX_BIG_MORE_BLOB_LEN)
		return -1;
	if(-1 == poNetData->AddBuf(pstIn->abyData, pstIn->dwLen, "Data"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSBigMoreBlob(void *pHost, INetData* poNetData)
{
	SBigMoreBlob *pstOut = (SBigMoreBlob*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwLen, "Len"))
		return -1;

   if (pstOut->dwLen > MAX_BIG_MORE_BLOB_LEN)
		return -1;
	if(-1 == poNetData->DelBuf(pstOut->abyData, pstOut->dwLen, "Data"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSEXBigBlob(const void *pHost, INetData* poNetData)
{
	const SEXBigBlob *pstIn = (const SEXBigBlob*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwLen, "Len"))
		return -1;

   if (pstIn->dwLen > MAX_EXEBIGBLOB_LEN)
		return -1;
	if(-1 == poNetData->AddBuf(pstIn->abyData, pstIn->dwLen, "Data"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSEXBigBlob(void *pHost, INetData* poNetData)
{
	SEXBigBlob *pstOut = (SEXBigBlob*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwLen, "Len"))
		return -1;

   if (pstOut->dwLen > MAX_EXEBIGBLOB_LEN)
		return -1;
	if(-1 == poNetData->DelBuf(pstOut->abyData, pstOut->dwLen, "Data"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSEquipInfo(const void *pHost, INetData* poNetData)
{
	const SEquipInfo *pstIn = (const SEquipInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->bySlot, "Slot"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwHuanhuaTemplateId, "HuanhuaTemplateId"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byStarCount, "StarCount"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSEquipInfo(void *pHost, INetData* poNetData)
{
	SEquipInfo *pstOut = (SEquipInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->bySlot, "Slot"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwHuanhuaTemplateId, "HuanhuaTemplateId"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byStarCount, "StarCount"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRoleInfo(const void *pHost, INetData* poNetData)
{
	const SRoleInfo *pstIn = (const SRoleInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwDBRoleId, "DBRoleId"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szRoleName, sizeof(pstIn->szRoleName), "RoleName"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nLevel, "Level"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byBaseJob, "BaseJob"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byJob, "Job"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byGender, "Gender"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySkinColor, "SkinColor"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szcreatetime, sizeof(pstIn->szcreatetime), "createtime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwLastLoginTime, "LastLoginTime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwLastLogoutTime, "LastLogoutTime"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwSceneId, "SceneId"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwInstanceSceneId, "InstanceSceneId"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwLatestSceneId, "LatestSceneId"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwLatestInstanceSceneId, "LatestInstanceSceneId"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwForbidenTime, "ForbidenTime"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRoleInfo(void *pHost, INetData* poNetData)
{
	SRoleInfo *pstOut = (SRoleInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwDBRoleId, "DBRoleId"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szRoleName, sizeof(pstOut->szRoleName), "RoleName"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nLevel, "Level"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byBaseJob, "BaseJob"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byJob, "Job"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byGender, "Gender"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySkinColor, "SkinColor"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szcreatetime, sizeof(pstOut->szcreatetime), "createtime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwLastLoginTime, "LastLoginTime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwLastLogoutTime, "LastLogoutTime"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwSceneId, "SceneId"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwInstanceSceneId, "InstanceSceneId"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwLatestSceneId, "LatestSceneId"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwLatestInstanceSceneId, "LatestInstanceSceneId"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwForbidenTime, "ForbidenTime"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSXGEM(const void *pHost, INetData* poNetData)
{
	const SXGEM *pstIn = (const SXGEM*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nTID, "TID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSXGEM(void *pHost, INetData* poNetData)
{
	SXGEM *pstOut = (SXGEM*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nTID, "TID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSXITEM(const void *pHost, INetData* poNetData)
{
	const SXITEM *pstIn = (const SXITEM*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwUID, "UID"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nTID, "TID"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nUP, "UP"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nCT, "CT"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nEXP, "EXP"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nLK, "LK"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wGEMCount, "GEMCount"))
		return -1;

	int i;
	if ((int)pstIn->wGEMCount > MAX_GEM_COUNT || pstIn->wGEMCount < 0)
       return -1;
	for(i = 0; i < MAX_GEM_COUNT; ++i)
	{
		if(i >= (int)pstIn->wGEMCount)
			break;
		if(-1 == EncodeSXGEM(&pstIn->astGEM[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSXITEM(void *pHost, INetData* poNetData)
{
	SXITEM *pstOut = (SXITEM*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwUID, "UID"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nTID, "TID"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nUP, "UP"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nCT, "CT"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nEXP, "EXP"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nLK, "LK"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wGEMCount, "GEMCount"))
		return -1;

	int i;
	if ((int)pstOut->wGEMCount > MAX_GEM_COUNT || pstOut->wGEMCount < 0)
       return -1;
	for(i = 0; i < MAX_GEM_COUNT; ++i)
	{
		if(i >= (int)pstOut->wGEMCount)
			break;
		if(-1 == DecodeSXGEM(&pstOut->astGEM[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSXITEMS(const void *pHost, INetData* poNetData)
{
	const SXITEMS *pstIn = (const SXITEMS*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddWord(pstIn->wItemCount, "ItemCount"))
		return -1;

	int i;
	if ((int)pstIn->wItemCount > MAX_ITEM_COUNT || pstIn->wItemCount < 0)
       return -1;
	for(i = 0; i < MAX_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstIn->wItemCount)
			break;
		if(-1 == EncodeSXITEM(&pstIn->astItems[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSXITEMS(void *pHost, INetData* poNetData)
{
	SXITEMS *pstOut = (SXITEMS*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelWord(pstOut->wItemCount, "ItemCount"))
		return -1;

	int i;
	if ((int)pstOut->wItemCount > MAX_ITEM_COUNT || pstOut->wItemCount < 0)
       return -1;
	for(i = 0; i < MAX_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstOut->wItemCount)
			break;
		if(-1 == DecodeSXITEM(&pstOut->astItems[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRoleInfoWithEquip(const void *pHost, INetData* poNetData)
{
	const SRoleInfoWithEquip *pstIn = (const SRoleInfoWithEquip*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSRoleInfo(&pstIn->stRoleInfo, poNetData))
		return -1;

	if(-1 == EncodeSXITEMS(&pstIn->stEquip, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRoleInfoWithEquip(void *pHost, INetData* poNetData)
{
	SRoleInfoWithEquip *pstOut = (SRoleInfoWithEquip*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSRoleInfo(&pstOut->stRoleInfo, poNetData))
		return -1;

	if(-1 == DecodeSXITEMS(&pstOut->stEquip, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRoleInfoWithEquipAll(const void *pHost, INetData* poNetData)
{
	const SRoleInfoWithEquipAll *pstIn = (const SRoleInfoWithEquipAll*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSRoleInfo(&pstIn->stRoleInfo, poNetData))
		return -1;

	if(-1 == EncodeSRoleDBInfo(&pstIn->stRoleDBInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRoleInfoWithEquipAll(void *pHost, INetData* poNetData)
{
	SRoleInfoWithEquipAll *pstOut = (SRoleInfoWithEquipAll*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSRoleInfo(&pstOut->stRoleInfo, poNetData))
		return -1;

	if(-1 == DecodeSRoleDBInfo(&pstOut->stRoleDBInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSROLE_SUIT_ITEM(const void *pHost, INetData* poNetData)
{
	const SROLE_SUIT_ITEM *pstIn = (const SROLE_SUIT_ITEM*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwItemUUID, "ItemUUID"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nItemID, "ItemID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSROLE_SUIT_ITEM(void *pHost, INetData* poNetData)
{
	SROLE_SUIT_ITEM *pstOut = (SROLE_SUIT_ITEM*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwItemUUID, "ItemUUID"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nItemID, "ItemID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSROLE_SUIT(const void *pHost, INetData* poNetData)
{
	const SROLE_SUIT *pstIn = (const SROLE_SUIT*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nSuitID, "SuitID"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nSuitCount, "SuitCount"))
		return -1;

	int i;
	if ((int)pstIn->nSuitCount > MAX_SUIT_ITEM_COUNT || pstIn->nSuitCount < 0)
       return -1;
	for(i = 0; i < MAX_SUIT_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstIn->nSuitCount)
			break;
		if(-1 == EncodeSROLE_SUIT_ITEM(&pstIn->astSuitItem[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSROLE_SUIT(void *pHost, INetData* poNetData)
{
	SROLE_SUIT *pstOut = (SROLE_SUIT*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nSuitID, "SuitID"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nSuitCount, "SuitCount"))
		return -1;

	int i;
	if ((int)pstOut->nSuitCount > MAX_SUIT_ITEM_COUNT || pstOut->nSuitCount < 0)
       return -1;
	for(i = 0; i < MAX_SUIT_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstOut->nSuitCount)
			break;
		if(-1 == DecodeSROLE_SUIT_ITEM(&pstOut->astSuitItem[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSHeadRecord(const void *pHost, INetData* poNetData)
{
	const SHeadRecord *pstIn = (const SHeadRecord*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddChar(pstIn->chRandomValue, "RandomValue"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wHeadID, "HeadID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSHeadRecord(void *pHost, INetData* poNetData)
{
	SHeadRecord *pstOut = (SHeadRecord*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelChar(pstOut->chRandomValue, "RandomValue"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wHeadID, "HeadID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRandomEquipHead(const void *pHost, INetData* poNetData)
{
	const SRandomEquipHead *pstIn = (const SRandomEquipHead*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byIsIdentifyed, "IsIdentifyed"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->byCount > MAX_EQUIP_HEAD || pstIn->byCount < 0)
       return -1;
	for(i = 0; i < MAX_EQUIP_HEAD; ++i)
	{
		if(i >= (int)pstIn->byCount)
			break;
		if(-1 == EncodeSHeadRecord(&pstIn->astHeads[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRandomEquipHead(void *pHost, INetData* poNetData)
{
	SRandomEquipHead *pstOut = (SRandomEquipHead*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byIsIdentifyed, "IsIdentifyed"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->byCount > MAX_EQUIP_HEAD || pstOut->byCount < 0)
       return -1;
	for(i = 0; i < MAX_EQUIP_HEAD; ++i)
	{
		if(i >= (int)pstOut->byCount)
			break;
		if(-1 == DecodeSHeadRecord(&pstOut->astHeads[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSItemEquipExInfo(const void *pHost, INetData* poNetData)
{
	const SItemEquipExInfo *pstIn = (const SItemEquipExInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byLevel, "Level"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byMaxLevel, "MaxLevel"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byMaxHoleNum, "MaxHoleNum"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHole, "Hole"))
		return -1;

	if(-1 == EncodeSRandomEquipHead(&pstIn->stRandomHead, poNetData))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwDurability, "Durability"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwMaxDurability, "MaxDurability"))
		return -1;

	int i;
	for(i = 0; i < MAX_ITEM_HOLE_NUM; ++i)
	{
		if(-1 == poNetData->AddDword(pstIn->adwGemID[i], "GemID"))
			return -1;
	}

	if(-1 == poNetData->AddChar(pstIn->chSmithingRandom, "SmithingRandom"))
		return -1;

	if(-1 == poNetData->AddChar(pstIn->chStarRandom, "StarRandom"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byReduceEquipNeedLevel, "ReduceEquipNeedLevel"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwHunhuaTemplateID, "HunhuaTemplateID"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwHunhuaEndTime, "HunhuaEndTime"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwBuffID, "BuffID"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwStarExp, "StarExp"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSItemEquipExInfo(void *pHost, INetData* poNetData)
{
	SItemEquipExInfo *pstOut = (SItemEquipExInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byLevel, "Level"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byMaxLevel, "MaxLevel"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byMaxHoleNum, "MaxHoleNum"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHole, "Hole"))
		return -1;

	if(-1 == DecodeSRandomEquipHead(&pstOut->stRandomHead, poNetData))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwDurability, "Durability"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwMaxDurability, "MaxDurability"))
		return -1;

	int i;
	for(i = 0; i < MAX_ITEM_HOLE_NUM; ++i)
	{
		if(-1 == poNetData->DelDword(pstOut->adwGemID[i], "GemID"))
			return -1;
	}

	if(-1 == poNetData->DelChar(pstOut->chSmithingRandom, "SmithingRandom"))
		return -1;

	if(-1 == poNetData->DelChar(pstOut->chStarRandom, "StarRandom"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byReduceEquipNeedLevel, "ReduceEquipNeedLevel"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwHunhuaTemplateID, "HunhuaTemplateID"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwHunhuaEndTime, "HunhuaEndTime"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwBuffID, "BuffID"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwStarExp, "StarExp"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSItemMakerInfo(const void *pHost, INetData* poNetData)
{
	const SItemMakerInfo *pstIn = (const SItemMakerInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddBuf(pstIn->abyMaker, ROLE_NAME_LEN, "Maker"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwVirtue, "Virtue"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwEvil, "Evil"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwGoodness, "Goodness"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwBadness, "Badness"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSItemMakerInfo(void *pHost, INetData* poNetData)
{
	SItemMakerInfo *pstOut = (SItemMakerInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelBuf(pstOut->abyMaker, ROLE_NAME_LEN, "Maker"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwVirtue, "Virtue"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwEvil, "Evil"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwGoodness, "Goodness"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwBadness, "Badness"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSItemTimeInfo(const void *pHost, INetData* poNetData)
{
	const SItemTimeInfo *pstIn = (const SItemTimeInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byUseNum, "UseNum"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwDestroyTime, "DestroyTime"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSItemTimeInfo(void *pHost, INetData* poNetData)
{
	SItemTimeInfo *pstOut = (SItemTimeInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byUseNum, "UseNum"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwDestroyTime, "DestroyTime"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSNull(const void *pHost, INetData* poNetData)
{
	const SNull *pstIn = (const SNull*)pHost;
	poNetData->EnterStruct();

	(void*)pstIn;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSNull(void *pHost, INetData* poNetData)
{
	SNull *pstOut = (SNull*)pHost;
	poNetData->EnterStruct();

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeUnUItemExInfo(const void *pHost, int iSelect, INetData* poNetData)
{
	switch(iSelect){
	case ITEM_EX_TYPE_NULL:
		return EncodeSNull(pHost, poNetData);
	case ITEM_EX_TYPE_EQUIP:
		return EncodeSItemEquipExInfo(pHost, poNetData);
	default: return -1;
	}
}

int DecodeUnUItemExInfo(void *pHost, int iSelect, INetData* poNetData)
{
	switch(iSelect){
	case ITEM_EX_TYPE_NULL:
		return DecodeSNull(pHost, poNetData);
	case ITEM_EX_TYPE_EQUIP:
		return DecodeSItemEquipExInfo(pHost, poNetData);
	default: return -1;
	}
}

int EncodeSItemExInfo(const void *pHost, INetData* poNetData)
{
	const SItemExInfo *pstIn = (const SItemExInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byType, "Type"))
		return -1;

	if(-1 == EncodeUnUItemExInfo(&pstIn->stExInfo, pstIn->byType, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSItemExInfo(void *pHost, INetData* poNetData)
{
	SItemExInfo *pstOut = (SItemExInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byType, "Type"))
		return -1;

	if(-1 == DecodeUnUItemExInfo(&pstOut->stExInfo, pstOut->byType, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSExchangeItem(const void *pHost, INetData* poNetData)
{
	const SExchangeItem *pstIn = (const SExchangeItem*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byAdd, "Add"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byFromIndex, "FromIndex"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byFromSlot, "FromSlot"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byToSlot, "ToSlot"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSExchangeItem(void *pHost, INetData* poNetData)
{
	SExchangeItem *pstOut = (SExchangeItem*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byAdd, "Add"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byFromIndex, "FromIndex"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byFromSlot, "FromSlot"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byToSlot, "ToSlot"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSItemShortcut(const void *pHost, INetData* poNetData)
{
	const SItemShortcut *pstIn = (const SItemShortcut*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->bySlot, "Slot"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwItemUUId, "ItemUUId"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSItemShortcut(void *pHost, INetData* poNetData)
{
	SItemShortcut *pstOut = (SItemShortcut*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->bySlot, "Slot"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwItemUUId, "ItemUUId"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRoleName(const void *pHost, INetData* poNetData)
{
	const SRoleName *pstIn = (const SRoleName*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddString(pstIn->szRoleName, sizeof(pstIn->szRoleName), "RoleName"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwRoleID, "RoleID"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwLevel, "Level"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwJob, "Job"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRoleName(void *pHost, INetData* poNetData)
{
	SRoleName *pstOut = (SRoleName*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelString(pstOut->szRoleName, sizeof(pstOut->szRoleName), "RoleName"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwRoleID, "RoleID"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwLevel, "Level"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwJob, "Job"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSServerInfo(const void *pHost, INetData* poNetData)
{
	const SServerInfo *pstIn = (const SServerInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwServerID, "ServerID"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwListenIP, "ListenIP"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wListenPort, "ListenPort"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSServerInfo(void *pHost, INetData* poNetData)
{
	SServerInfo *pstOut = (SServerInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwServerID, "ServerID"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwListenIP, "ListenIP"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wListenPort, "ListenPort"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeMonthCardInfo(const void *pHost, INetData* poNetData)
{
	const MonthCardInfo *pstIn = (const MonthCardInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nUId, "UId"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwBTm, "BTm"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nDays, "Days"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwUTm, "UTm"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeMonthCardInfo(void *pHost, INetData* poNetData)
{
	MonthCardInfo *pstOut = (MonthCardInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nUId, "UId"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwBTm, "BTm"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nDays, "Days"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwUTm, "UTm"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSLMAccountInfo(const void *pHost, INetData* poNetData)
{
	const SLMAccountInfo *pstIn = (const SLMAccountInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwAccountId, "AccountId"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRMBCount, "RMBCount"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRMBSum, "RMBSum"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwCash, "Cash"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nVIPLevel, "VIPLevel"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byGMLevel, "GMLevel"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byMonthCardCount, "MonthCardCount"))
		return -1;

	int i;
	if ((int)pstIn->byMonthCardCount > MAX_MONTHCARD_COUNT || pstIn->byMonthCardCount < 0)
       return -1;
	for(i = 0; i < MAX_MONTHCARD_COUNT; ++i)
	{
		if(i >= (int)pstIn->byMonthCardCount)
			break;
		if(-1 == EncodeMonthCardInfo(&pstIn->astMonthCardInfos[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSLMAccountInfo(void *pHost, INetData* poNetData)
{
	SLMAccountInfo *pstOut = (SLMAccountInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwAccountId, "AccountId"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRMBCount, "RMBCount"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRMBSum, "RMBSum"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwCash, "Cash"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nVIPLevel, "VIPLevel"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byGMLevel, "GMLevel"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byMonthCardCount, "MonthCardCount"))
		return -1;

	int i;
	if ((int)pstOut->byMonthCardCount > MAX_MONTHCARD_COUNT || pstOut->byMonthCardCount < 0)
       return -1;
	for(i = 0; i < MAX_MONTHCARD_COUNT; ++i)
	{
		if(i >= (int)pstOut->byMonthCardCount)
			break;
		if(-1 == DecodeMonthCardInfo(&pstOut->astMonthCardInfos[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGameServerDescInfo(const void *pHost, INetData* poNetData)
{
	const SGameServerDescInfo *pstIn = (const SGameServerDescInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byOptLen, "OptLen"))
		return -1;

	if(-1 == poNetData->AddBuf(pstIn->abyOpt, 255, "Opt"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wDescLen, "DescLen"))
		return -1;

   if (pstIn->wDescLen > MAX_SERVER_DESC_LEN)
		return -1;
	if(-1 == poNetData->AddBuf(pstIn->abyDesc, pstIn->wDescLen, "Desc"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wStateLen, "StateLen"))
		return -1;

   if (pstIn->wStateLen > MAX_SERVER_STATE_LEN)
		return -1;
	if(-1 == poNetData->AddBuf(pstIn->abyState, pstIn->wStateLen, "State"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGameServerDescInfo(void *pHost, INetData* poNetData)
{
	SGameServerDescInfo *pstOut = (SGameServerDescInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byOptLen, "OptLen"))
		return -1;

	if(-1 == poNetData->DelBuf(pstOut->abyOpt, 255, "Opt"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wDescLen, "DescLen"))
		return -1;

   if (pstOut->wDescLen > MAX_SERVER_DESC_LEN)
		return -1;
	if(-1 == poNetData->DelBuf(pstOut->abyDesc, pstOut->wDescLen, "Desc"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wStateLen, "StateLen"))
		return -1;

   if (pstOut->wStateLen > MAX_SERVER_STATE_LEN)
		return -1;
	if(-1 == poNetData->DelBuf(pstOut->abyState, pstOut->wStateLen, "State"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGameServerInfo(const void *pHost, INetData* poNetData)
{
	const SGameServerInfo *pstIn = (const SGameServerInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSServerInfo(&pstIn->stServer, poNetData))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wPlayerCount, "PlayerCount"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byServerState, "ServerState"))
		return -1;

	if(-1 == EncodeSGameServerDescInfo(&pstIn->stDesc, poNetData))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwServerUniqueId, "ServerUniqueId"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGameServerInfo(void *pHost, INetData* poNetData)
{
	SGameServerInfo *pstOut = (SGameServerInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSServerInfo(&pstOut->stServer, poNetData))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wPlayerCount, "PlayerCount"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byServerState, "ServerState"))
		return -1;

	if(-1 == DecodeSGameServerDescInfo(&pstOut->stDesc, poNetData))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwServerUniqueId, "ServerUniqueId"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeCTDT_CONNECTION_INFO(const void *pHost, INetData* poNetData)
{
	const CTDT_CONNECTION_INFO *pstIn = (const CTDT_CONNECTION_INFO*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwIncomingBytesPerMinute, "IncomingBytesPerMinute"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwOutgoingBytesPerMinute, "OutgoingBytesPerMinute"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeCTDT_CONNECTION_INFO(void *pHost, INetData* poNetData)
{
	CTDT_CONNECTION_INFO *pstOut = (CTDT_CONNECTION_INFO*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwIncomingBytesPerMinute, "IncomingBytesPerMinute"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwOutgoingBytesPerMinute, "OutgoingBytesPerMinute"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSUUItemInfo(const void *pHost, INetData* poNetData)
{
	const SUUItemInfo *pstIn = (const SUUItemInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddWord(pstIn->wCount, "Count"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwUUID, "UUID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSUUItemInfo(void *pHost, INetData* poNetData)
{
	SUUItemInfo *pstOut = (SUUItemInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelWord(pstOut->wCount, "Count"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwTemplateId, "TemplateId"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwUUID, "UUID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSItemList(const void *pHost, INetData* poNetData)
{
	const SItemList *pstIn = (const SItemList*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddWord(pstIn->wCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->wCount > MAX_ROLE_ITEM_COUNT || pstIn->wCount < 0)
       return -1;
	for(i = 0; i < MAX_ROLE_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstIn->wCount)
			break;
		if(-1 == EncodeSUUItemInfo(&pstIn->astItemList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSItemList(void *pHost, INetData* poNetData)
{
	SItemList *pstOut = (SItemList*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelWord(pstOut->wCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->wCount > MAX_ROLE_ITEM_COUNT || pstOut->wCount < 0)
       return -1;
	for(i = 0; i < MAX_ROLE_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstOut->wCount)
			break;
		if(-1 == DecodeSUUItemInfo(&pstOut->astItemList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSLevelInfo(const void *pHost, INetData* poNetData)
{
	const SLevelInfo *pstIn = (const SLevelInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwLevelID, "LevelID"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byCrystal, "Crystal"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wUsedTimes, "UsedTimes"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSLevelInfo(void *pHost, INetData* poNetData)
{
	SLevelInfo *pstOut = (SLevelInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwLevelID, "LevelID"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byCrystal, "Crystal"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wUsedTimes, "UsedTimes"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSBattleInfo(const void *pHost, INetData* poNetData)
{
	const SBattleInfo *pstIn = (const SBattleInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwBattleID, "BattleID"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wGetStars, "GetStars"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSBattleInfo(void *pHost, INetData* poNetData)
{
	SBattleInfo *pstOut = (SBattleInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwBattleID, "BattleID"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wGetStars, "GetStars"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSCHAT(const void *pHost, INetData* poNetData)
{
	const SCHAT *pstIn = (const SCHAT*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byChatType, "ChatType"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szWho, sizeof(pstIn->szWho), "Who"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szToWho, sizeof(pstIn->szToWho), "ToWho"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szContent, sizeof(pstIn->szContent), "Content"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byGmLevel, "GmLevel"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySpeakerVIPLevel, "SpeakerVIPLevel"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSCHAT(void *pHost, INetData* poNetData)
{
	SCHAT *pstOut = (SCHAT*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byChatType, "ChatType"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szWho, sizeof(pstOut->szWho), "Who"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szToWho, sizeof(pstOut->szToWho), "ToWho"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szContent, sizeof(pstOut->szContent), "Content"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byGmLevel, "GmLevel"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySpeakerVIPLevel, "SpeakerVIPLevel"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSFriendEquipInfo(const void *pHost, INetData* poNetData)
{
	const SFriendEquipInfo *pstIn = (const SFriendEquipInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTemplateID, "TemplateID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSFriendEquipInfo(void *pHost, INetData* poNetData)
{
	SFriendEquipInfo *pstOut = (SFriendEquipInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTemplateID, "TemplateID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSFriendPetInfo(const void *pHost, INetData* poNetData)
{
	const SFriendPetInfo *pstIn = (const SFriendPetInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTemplateID, "TemplateID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSFriendPetInfo(void *pHost, INetData* poNetData)
{
	SFriendPetInfo *pstOut = (SFriendPetInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTemplateID, "TemplateID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRSNull(const void *pHost, INetData* poNetData)
{
	const SRSNull *pstIn = (const SRSNull*)pHost;
	poNetData->EnterStruct();

	(void*)pstIn;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRSNull(void *pHost, INetData* poNetData)
{
	SRSNull *pstOut = (SRSNull*)pHost;
	poNetData->EnterStruct();

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRSRoleBaseData(const void *pHost, INetData* poNetData)
{
	const SRSRoleBaseData *pstIn = (const SRSRoleBaseData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwLevel, "Level"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwAttack, "Attack"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nPVPWins, "PVPWins"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nPVPRepute, "PVPRepute"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRSRoleBaseData(void *pHost, INetData* poNetData)
{
	SRSRoleBaseData *pstOut = (SRSRoleBaseData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwLevel, "Level"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwAttack, "Attack"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nPVPWins, "PVPWins"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nPVPRepute, "PVPRepute"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRSRoleEquipData(const void *pHost, INetData* poNetData)
{
	const SRSRoleEquipData *pstIn = (const SRSRoleEquipData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->byCount > MAX_EQUIP_ITEM_NUM || pstIn->byCount < 0)
       return -1;
	for(i = 0; i < MAX_EQUIP_ITEM_NUM; ++i)
	{
		if(i >= (int)pstIn->byCount)
			break;
		if(-1 == EncodeSXITEM(&pstIn->astEquipInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRSRoleEquipData(void *pHost, INetData* poNetData)
{
	SRSRoleEquipData *pstOut = (SRSRoleEquipData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->byCount > MAX_EQUIP_ITEM_NUM || pstOut->byCount < 0)
       return -1;
	for(i = 0; i < MAX_EQUIP_ITEM_NUM; ++i)
	{
		if(i >= (int)pstOut->byCount)
			break;
		if(-1 == DecodeSXITEM(&pstOut->astEquipInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRSRolePetData(const void *pHost, INetData* poNetData)
{
	const SRSRolePetData *pstIn = (const SRSRolePetData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->byCount > MAX_FRIENDS_PET_COUNT || pstIn->byCount < 0)
       return -1;
	for(i = 0; i < MAX_FRIENDS_PET_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount)
			break;
		if(-1 == EncodeSFriendPetInfo(&pstIn->astPetInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRSRolePetData(void *pHost, INetData* poNetData)
{
	SRSRolePetData *pstOut = (SRSRolePetData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->byCount > MAX_FRIENDS_PET_COUNT || pstOut->byCount < 0)
       return -1;
	for(i = 0; i < MAX_FRIENDS_PET_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount)
			break;
		if(-1 == DecodeSFriendPetInfo(&pstOut->astPetInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRSRoleOnlineData(const void *pHost, INetData* poNetData)
{
	const SRSRoleOnlineData *pstIn = (const SRSRoleOnlineData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byIsOnline, "IsOnline"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRSRoleOnlineData(void *pHost, INetData* poNetData)
{
	SRSRoleOnlineData *pstOut = (SRSRoleOnlineData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byIsOnline, "IsOnline"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeUnURSRoleProperty(const void *pHost, int iSelect, INetData* poNetData)
{
	switch(iSelect){
	case RS_ROLE_PROPERTY_NULL:
		return EncodeSRSNull(pHost, poNetData);
	case RS_ROLE_PROPERTY_BASE:
		return EncodeSRSRoleBaseData(pHost, poNetData);
	case RS_ROLE_PROPERTY_EQUIP:
		return EncodeSRSRoleEquipData(pHost, poNetData);
	case RS_ROLE_PROPERTY_PET:
		return EncodeSRSRolePetData(pHost, poNetData);
	case RS_ROLE_PROPERTY_ONLINE:
		return EncodeSRSRoleOnlineData(pHost, poNetData);
	default: return -1;
	}
}

int DecodeUnURSRoleProperty(void *pHost, int iSelect, INetData* poNetData)
{
	switch(iSelect){
	case RS_ROLE_PROPERTY_NULL:
		return DecodeSRSNull(pHost, poNetData);
	case RS_ROLE_PROPERTY_BASE:
		return DecodeSRSRoleBaseData(pHost, poNetData);
	case RS_ROLE_PROPERTY_EQUIP:
		return DecodeSRSRoleEquipData(pHost, poNetData);
	case RS_ROLE_PROPERTY_PET:
		return DecodeSRSRolePetData(pHost, poNetData);
	case RS_ROLE_PROPERTY_ONLINE:
		return DecodeSRSRoleOnlineData(pHost, poNetData);
	default: return -1;
	}
}

int EncodeSRSRoleProperty(const void *pHost, INetData* poNetData)
{
	const SRSRoleProperty *pstIn = (const SRSRoleProperty*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byType, "Type"))
		return -1;

	if(-1 == EncodeUnURSRoleProperty(&pstIn->stProperty, pstIn->byType, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRSRoleProperty(void *pHost, INetData* poNetData)
{
	SRSRoleProperty *pstOut = (SRSRoleProperty*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byType, "Type"))
		return -1;

	if(-1 == DecodeUnURSRoleProperty(&pstOut->stProperty, pstOut->byType, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSFriendInfo(const void *pHost, INetData* poNetData)
{
	const SFriendInfo *pstIn = (const SFriendInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwHead, "Head"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szName, sizeof(pstIn->szName), "Name"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySkinColor, "SkinColor"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wLevel, "Level"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byJob, "Job"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwAttack, "Attack"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byIsOnline, "IsOnline"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwActionPoint, "ActionPoint"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byCanDonateActionPoint, "CanDonateActionPoint"))
		return -1;

	if(-1 == EncodeSRSRoleEquipData(&pstIn->stEquip, poNetData))
		return -1;

	if(-1 == EncodeSRSRolePetData(&pstIn->stPet, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSFriendInfo(void *pHost, INetData* poNetData)
{
	SFriendInfo *pstOut = (SFriendInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwHead, "Head"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szName, sizeof(pstOut->szName), "Name"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySkinColor, "SkinColor"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wLevel, "Level"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byJob, "Job"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwAttack, "Attack"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byIsOnline, "IsOnline"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwActionPoint, "ActionPoint"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byCanDonateActionPoint, "CanDonateActionPoint"))
		return -1;

	if(-1 == DecodeSRSRoleEquipData(&pstOut->stEquip, poNetData))
		return -1;

	if(-1 == DecodeSRSRolePetData(&pstOut->stPet, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSFriendInviteInfo(const void *pHost, INetData* poNetData)
{
	const SFriendInviteInfo *pstIn = (const SFriendInviteInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == EncodeSFriendInfo(&pstIn->stInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSFriendInviteInfo(void *pHost, INetData* poNetData)
{
	SFriendInviteInfo *pstOut = (SFriendInviteInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == DecodeSFriendInfo(&pstOut->stInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSFriendInviteList(const void *pHost, INetData* poNetData)
{
	const SFriendInviteList *pstIn = (const SFriendInviteList*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwInviteCount, "InviteCount"))
		return -1;

	int i;
	if ((int)pstIn->dwInviteCount > MAX_FRIENDS_INVITE_COUNT || pstIn->dwInviteCount < 0)
       return -1;
	for(i = 0; i < MAX_FRIENDS_INVITE_COUNT; ++i)
	{
		if(i >= (int)pstIn->dwInviteCount)
			break;
		if(-1 == EncodeSFriendInviteInfo(&pstIn->astInviteList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSFriendInviteList(void *pHost, INetData* poNetData)
{
	SFriendInviteList *pstOut = (SFriendInviteList*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwInviteCount, "InviteCount"))
		return -1;

	int i;
	if ((int)pstOut->dwInviteCount > MAX_FRIENDS_INVITE_COUNT || pstOut->dwInviteCount < 0)
       return -1;
	for(i = 0; i < MAX_FRIENDS_INVITE_COUNT; ++i)
	{
		if(i >= (int)pstOut->dwInviteCount)
			break;
		if(-1 == DecodeSFriendInviteInfo(&pstOut->astInviteList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRoleBaseInfo(const void *pHost, INetData* poNetData)
{
	const SRoleBaseInfo *pstIn = (const SRoleBaseInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szName, sizeof(pstIn->szName), "Name"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySkinColor, "SkinColor"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->AddWord(pstIn->wLevel, "Level"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byJob, "Job"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwAttack, "Attack"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nPVPWins, "PVPWins"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nPVPRepute, "PVPRepute"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byIsOnline, "IsOnline"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nVIPLevel, "VIPLevel"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRoleBaseInfo(void *pHost, INetData* poNetData)
{
	SRoleBaseInfo *pstOut = (SRoleBaseInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szName, sizeof(pstOut->szName), "Name"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySkinColor, "SkinColor"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->DelWord(pstOut->wLevel, "Level"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byJob, "Job"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwAttack, "Attack"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nPVPWins, "PVPWins"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nPVPRepute, "PVPRepute"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byIsOnline, "IsOnline"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nVIPLevel, "VIPLevel"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSDBPET(const void *pHost, INetData* poNetData)
{
	const SDBPET *pstIn = (const SDBPET*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwUID, "UID"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwTID, "TID"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nLV, "LV"))
		return -1;

	if(-1 == poNetData->AddInt64(pstIn->llEXP, "EXP"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nHP, "HP"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nSP, "SP"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nUP, "UP"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nLOCK, "LOCK"))
		return -1;

	if(-1 == EncodeSXITEMS(&pstIn->stEQ, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSDBPET(void *pHost, INetData* poNetData)
{
	SDBPET *pstOut = (SDBPET*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwUID, "UID"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwTID, "TID"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nLV, "LV"))
		return -1;

	if(-1 == poNetData->DelInt64(pstOut->llEXP, "EXP"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nHP, "HP"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nSP, "SP"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nUP, "UP"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nLOCK, "LOCK"))
		return -1;

	if(-1 == DecodeSXITEMS(&pstOut->stEQ, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRSBattlePets(const void *pHost, INetData* poNetData)
{
	const SRSBattlePets *pstIn = (const SRSBattlePets*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->byCount > MAX_BATTLE_PET_COUNT || pstIn->byCount < 0)
       return -1;
	for(i = 0; i < MAX_BATTLE_PET_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount)
			break;
		if(-1 == EncodeSDBPET(&pstIn->astPets[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRSBattlePets(void *pHost, INetData* poNetData)
{
	SRSBattlePets *pstOut = (SRSBattlePets*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->byCount > MAX_BATTLE_PET_COUNT || pstOut->byCount < 0)
       return -1;
	for(i = 0; i < MAX_BATTLE_PET_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount)
			break;
		if(-1 == DecodeSDBPET(&pstOut->astPets[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRoleRsServerInfo(const void *pHost, INetData* poNetData)
{
	const SRoleRsServerInfo *pstIn = (const SRoleRsServerInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSRoleBaseInfo(&pstIn->stBaseInfo, poNetData))
		return -1;

	if(-1 == EncodeSRSRoleEquipData(&pstIn->stEquip, poNetData))
		return -1;

	if(-1 == EncodeSRSRolePetData(&pstIn->stPet, poNetData))
		return -1;

	if(-1 == EncodeSRSBattlePets(&pstIn->stBattlePets, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRoleRsServerInfo(void *pHost, INetData* poNetData)
{
	SRoleRsServerInfo *pstOut = (SRoleRsServerInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSRoleBaseInfo(&pstOut->stBaseInfo, poNetData))
		return -1;

	if(-1 == DecodeSRSRoleEquipData(&pstOut->stEquip, poNetData))
		return -1;

	if(-1 == DecodeSRSRolePetData(&pstOut->stPet, poNetData))
		return -1;

	if(-1 == DecodeSRSBattlePets(&pstOut->stBattlePets, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSAssistBattlePersonInfo(const void *pHost, INetData* poNetData)
{
	const SAssistBattlePersonInfo *pstIn = (const SAssistBattlePersonInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byIsFriend, "IsFriend"))
		return -1;

	if(-1 == EncodeSFriendInfo(&pstIn->stInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSAssistBattlePersonInfo(void *pHost, INetData* poNetData)
{
	SAssistBattlePersonInfo *pstOut = (SAssistBattlePersonInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byIsFriend, "IsFriend"))
		return -1;

	if(-1 == DecodeSFriendInfo(&pstOut->stInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSSeverAssistBattleInfo(const void *pHost, INetData* poNetData)
{
	const SSeverAssistBattleInfo *pstIn = (const SSeverAssistBattleInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSAssistBattlePersonInfo(&pstIn->stAssistor, poNetData))
		return -1;

	if(-1 == EncodeSDBPET(&pstIn->stBattlePet, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSSeverAssistBattleInfo(void *pHost, INetData* poNetData)
{
	SSeverAssistBattleInfo *pstOut = (SSeverAssistBattleInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSAssistBattlePersonInfo(&pstOut->stAssistor, poNetData))
		return -1;

	if(-1 == DecodeSDBPET(&pstOut->stBattlePet, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeFRIENDS_LIST_NTF(const void *pHost, INetData* poNetData)
{
	const FRIENDS_LIST_NTF *pstIn = (const FRIENDS_LIST_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->dwCount > MAX_FRIENDS_COUNT || pstIn->dwCount < 0)
       return -1;
	for(i = 0; i < MAX_FRIENDS_COUNT; ++i)
	{
		if(i >= (int)pstIn->dwCount)
			break;
		if(-1 == EncodeSFriendInfo(&pstIn->astList[i], poNetData))
			return -1;
	}

	if(-1 == EncodeSFriendInviteList(&pstIn->stInviteList, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeFRIENDS_LIST_NTF(void *pHost, INetData* poNetData)
{
	FRIENDS_LIST_NTF *pstOut = (FRIENDS_LIST_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->dwCount > MAX_FRIENDS_COUNT || pstOut->dwCount < 0)
       return -1;
	for(i = 0; i < MAX_FRIENDS_COUNT; ++i)
	{
		if(i >= (int)pstOut->dwCount)
			break;
		if(-1 == DecodeSFriendInfo(&pstOut->astList[i], poNetData))
			return -1;
	}

	if(-1 == DecodeSFriendInviteList(&pstOut->stInviteList, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeQUERY_ROLE_REQ(const void *pHost, INetData* poNetData)
{
	const QUERY_ROLE_REQ *pstIn = (const QUERY_ROLE_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwPage, "Page"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szKeyWords, sizeof(pstIn->szKeyWords), "KeyWords"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeQUERY_ROLE_REQ(void *pHost, INetData* poNetData)
{
	QUERY_ROLE_REQ *pstOut = (QUERY_ROLE_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwPage, "Page"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szKeyWords, sizeof(pstOut->szKeyWords), "KeyWords"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeQUERY_ROLE_ACK(const void *pHost, INetData* poNetData)
{
	const QUERY_ROLE_ACK *pstIn = (const QUERY_ROLE_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwCount, "Count"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwPage, "Page"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwTotalPage, "TotalPage"))
		return -1;

	int i;
	if ((int)pstIn->dwCount > MAX_FRIENDS_COUNT_PER_PAGE || pstIn->dwCount < 0)
       return -1;
	for(i = 0; i < MAX_FRIENDS_COUNT_PER_PAGE; ++i)
	{
		if(i >= (int)pstIn->dwCount)
			break;
		if(-1 == EncodeSFriendInfo(&pstIn->astLists[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeQUERY_ROLE_ACK(void *pHost, INetData* poNetData)
{
	QUERY_ROLE_ACK *pstOut = (QUERY_ROLE_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwCount, "Count"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwPage, "Page"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwTotalPage, "TotalPage"))
		return -1;

	int i;
	if ((int)pstOut->dwCount > MAX_FRIENDS_COUNT_PER_PAGE || pstOut->dwCount < 0)
       return -1;
	for(i = 0; i < MAX_FRIENDS_COUNT_PER_PAGE; ++i)
	{
		if(i >= (int)pstOut->dwCount)
			break;
		if(-1 == DecodeSFriendInfo(&pstOut->astLists[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeADD_FRIEND_REQ(const void *pHost, INetData* poNetData)
{
	const ADD_FRIEND_REQ *pstIn = (const ADD_FRIEND_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddString(pstIn->szName, sizeof(pstIn->szName), "Name"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeADD_FRIEND_REQ(void *pHost, INetData* poNetData)
{
	ADD_FRIEND_REQ *pstOut = (ADD_FRIEND_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelString(pstOut->szName, sizeof(pstOut->szName), "Name"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeADD_FRIEND_ACK(const void *pHost, INetData* poNetData)
{
	const ADD_FRIEND_ACK *pstIn = (const ADD_FRIEND_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->byCount > 1 || pstIn->byCount < 0)
       return -1;
	for(i = 0; i < 1; ++i)
	{
		if(i >= (int)pstIn->byCount)
			break;
		if(-1 == EncodeSFriendInfo(&pstIn->astFriends[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeADD_FRIEND_ACK(void *pHost, INetData* poNetData)
{
	ADD_FRIEND_ACK *pstOut = (ADD_FRIEND_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->byCount > 1 || pstOut->byCount < 0)
       return -1;
	for(i = 0; i < 1; ++i)
	{
		if(i >= (int)pstOut->byCount)
			break;
		if(-1 == DecodeSFriendInfo(&pstOut->astFriends[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeREMOVE_FRIEND_REQ(const void *pHost, INetData* poNetData)
{
	const REMOVE_FRIEND_REQ *pstIn = (const REMOVE_FRIEND_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeREMOVE_FRIEND_REQ(void *pHost, INetData* poNetData)
{
	REMOVE_FRIEND_REQ *pstOut = (REMOVE_FRIEND_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeREMOVE_FRIEND_ACK(const void *pHost, INetData* poNetData)
{
	const REMOVE_FRIEND_ACK *pstIn = (const REMOVE_FRIEND_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeREMOVE_FRIEND_ACK(void *pHost, INetData* poNetData)
{
	REMOVE_FRIEND_ACK *pstOut = (REMOVE_FRIEND_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeDONATE_ACTION_POINT_REQ(const void *pHost, INetData* poNetData)
{
	const DONATE_ACTION_POINT_REQ *pstIn = (const DONATE_ACTION_POINT_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeDONATE_ACTION_POINT_REQ(void *pHost, INetData* poNetData)
{
	DONATE_ACTION_POINT_REQ *pstOut = (DONATE_ACTION_POINT_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeDONATE_ACTION_POINT_ACK(const void *pHost, INetData* poNetData)
{
	const DONATE_ACTION_POINT_ACK *pstIn = (const DONATE_ACTION_POINT_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeDONATE_ACTION_POINT_ACK(void *pHost, INetData* poNetData)
{
	DONATE_ACTION_POINT_ACK *pstOut = (DONATE_ACTION_POINT_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeDONATE_ACTION_POINT_OTHER_NTF(const void *pHost, INetData* poNetData)
{
	const DONATE_ACTION_POINT_OTHER_NTF *pstIn = (const DONATE_ACTION_POINT_OTHER_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeDONATE_ACTION_POINT_OTHER_NTF(void *pHost, INetData* poNetData)
{
	DONATE_ACTION_POINT_OTHER_NTF *pstOut = (DONATE_ACTION_POINT_OTHER_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeRECEIVE_ACTION_POINT_REQ(const void *pHost, INetData* poNetData)
{
	const RECEIVE_ACTION_POINT_REQ *pstIn = (const RECEIVE_ACTION_POINT_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeRECEIVE_ACTION_POINT_REQ(void *pHost, INetData* poNetData)
{
	RECEIVE_ACTION_POINT_REQ *pstOut = (RECEIVE_ACTION_POINT_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeRECEIVE_ACTION_POINT_ACK(const void *pHost, INetData* poNetData)
{
	const RECEIVE_ACTION_POINT_ACK *pstIn = (const RECEIVE_ACTION_POINT_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeRECEIVE_ACTION_POINT_ACK(void *pHost, INetData* poNetData)
{
	RECEIVE_ACTION_POINT_ACK *pstOut = (RECEIVE_ACTION_POINT_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeREQUEST_ADD_FRIEND_NTF(const void *pHost, INetData* poNetData)
{
	const REQUEST_ADD_FRIEND_NTF *pstIn = (const REQUEST_ADD_FRIEND_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSFriendInviteInfo(&pstIn->stNewInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeREQUEST_ADD_FRIEND_NTF(void *pHost, INetData* poNetData)
{
	REQUEST_ADD_FRIEND_NTF *pstOut = (REQUEST_ADD_FRIEND_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSFriendInviteInfo(&pstOut->stNewInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeRESPONSE_ADD_FRIEND_REQ(const void *pHost, INetData* poNetData)
{
	const RESPONSE_ADD_FRIEND_REQ *pstIn = (const RESPONSE_ADD_FRIEND_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byAgree, "Agree"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeRESPONSE_ADD_FRIEND_REQ(void *pHost, INetData* poNetData)
{
	RESPONSE_ADD_FRIEND_REQ *pstOut = (RESPONSE_ADD_FRIEND_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byAgree, "Agree"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeFRIEND_REMOVE_INVITE_NTF(const void *pHost, INetData* poNetData)
{
	const FRIEND_REMOVE_INVITE_NTF *pstIn = (const FRIEND_REMOVE_INVITE_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeFRIEND_REMOVE_INVITE_NTF(void *pHost, INetData* poNetData)
{
	FRIEND_REMOVE_INVITE_NTF *pstOut = (FRIEND_REMOVE_INVITE_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeFRIEND_INFO_CHANGE_NTF(const void *pHost, INetData* poNetData)
{
	const FRIEND_INFO_CHANGE_NTF *pstIn = (const FRIEND_INFO_CHANGE_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSRSRoleProperty(&pstIn->stInfo, poNetData))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeFRIEND_INFO_CHANGE_NTF(void *pHost, INetData* poNetData)
{
	FRIEND_INFO_CHANGE_NTF *pstOut = (FRIEND_INFO_CHANGE_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSRSRoleProperty(&pstOut->stInfo, poNetData))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeFRIEND_ASSIST_LIST_REQ(const void *pHost, INetData* poNetData)
{
	const FRIEND_ASSIST_LIST_REQ *pstIn = (const FRIEND_ASSIST_LIST_REQ*)pHost;
	poNetData->EnterStruct();

	(void*)pstIn;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeFRIEND_ASSIST_LIST_REQ(void *pHost, INetData* poNetData)
{
	FRIEND_ASSIST_LIST_REQ *pstOut = (FRIEND_ASSIST_LIST_REQ*)pHost;
	poNetData->EnterStruct();

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSELECT_FRIEND_ASSIST_REQ(const void *pHost, INetData* poNetData)
{
	const SELECT_FRIEND_ASSIST_REQ *pstIn = (const SELECT_FRIEND_ASSIST_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSELECT_FRIEND_ASSIST_REQ(void *pHost, INetData* poNetData)
{
	SELECT_FRIEND_ASSIST_REQ *pstOut = (SELECT_FRIEND_ASSIST_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSELECT_FRIEND_ASSIST_ACK(const void *pHost, INetData* poNetData)
{
	const SELECT_FRIEND_ASSIST_ACK *pstIn = (const SELECT_FRIEND_ASSIST_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSELECT_FRIEND_ASSIST_ACK(void *pHost, INetData* poNetData)
{
	SELECT_FRIEND_ASSIST_ACK *pstOut = (SELECT_FRIEND_ASSIST_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSAbyssRsServerInfo(const void *pHost, INetData* poNetData)
{
	const SAbyssRsServerInfo *pstIn = (const SAbyssRsServerInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwActDBID, "ActDBID"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwActTmpId, "ActTmpId"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nBlood, "Blood"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szRolename, sizeof(pstIn->szRolename), "Rolename"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nAtkcount, "Atkcount"))
		return -1;

	int i;
	for(i = 0; i < MAX_FRIEND_COUNT; ++i)
	{
		if(-1 == poNetData->AddUint64(pstIn->aqwAtklist[i], "Atklist"))
			return -1;
	}

	if(-1 == poNetData->AddInt(pstIn->nStatus, "Status"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwTritime, "Tritime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwOpentime, "Opentime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwKilltime, "Killtime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwEntranceExistTime, "EntranceExistTime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwAbyssExistTime, "AbyssExistTime"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSAbyssRsServerInfo(void *pHost, INetData* poNetData)
{
	SAbyssRsServerInfo *pstOut = (SAbyssRsServerInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwActDBID, "ActDBID"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwActTmpId, "ActTmpId"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nBlood, "Blood"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szRolename, sizeof(pstOut->szRolename), "Rolename"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nAtkcount, "Atkcount"))
		return -1;

	int i;
	for(i = 0; i < MAX_FRIEND_COUNT; ++i)
	{
		if(-1 == poNetData->DelUint64(pstOut->aqwAtklist[i], "Atklist"))
			return -1;
	}

	if(-1 == poNetData->DelInt(pstOut->nStatus, "Status"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwTritime, "Tritime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwOpentime, "Opentime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwKilltime, "Killtime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwEntranceExistTime, "EntranceExistTime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwAbyssExistTime, "AbyssExistTime"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeABYSS_TRIGGER_REQ(const void *pHost, INetData* poNetData)
{
	const ABYSS_TRIGGER_REQ *pstIn = (const ABYSS_TRIGGER_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwAbyssDBID, "AbyssDBID"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwAbyTemplateID, "AbyTemplateID"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szAbyName, sizeof(pstIn->szAbyName), "AbyName"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwMonsterID, "MonsterID"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwTotalBlood, "TotalBlood"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwTriggerTime, "TriggerTime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwEntranceExistTime, "EntranceExistTime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwAbyssExistTime, "AbyssExistTime"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szRolename, sizeof(pstIn->szRolename), "Rolename"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byJob, "Job"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeABYSS_TRIGGER_REQ(void *pHost, INetData* poNetData)
{
	ABYSS_TRIGGER_REQ *pstOut = (ABYSS_TRIGGER_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwAbyssDBID, "AbyssDBID"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwAbyTemplateID, "AbyTemplateID"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szAbyName, sizeof(pstOut->szAbyName), "AbyName"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwMonsterID, "MonsterID"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwTotalBlood, "TotalBlood"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwTriggerTime, "TriggerTime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwEntranceExistTime, "EntranceExistTime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwAbyssExistTime, "AbyssExistTime"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szRolename, sizeof(pstOut->szRolename), "Rolename"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byJob, "Job"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeABYSS_TRIGGER_ACK(const void *pHost, INetData* poNetData)
{
	const ABYSS_TRIGGER_ACK *pstIn = (const ABYSS_TRIGGER_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byIfTrigger, "IfTrigger"))
		return -1;

	if(-1 == EncodeSAbyssRsServerInfo(&pstIn->stAbyssInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeABYSS_TRIGGER_ACK(void *pHost, INetData* poNetData)
{
	ABYSS_TRIGGER_ACK *pstOut = (ABYSS_TRIGGER_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byIfTrigger, "IfTrigger"))
		return -1;

	if(-1 == DecodeSAbyssRsServerInfo(&pstOut->stAbyssInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeABYSS_OPEN_REQ(const void *pHost, INetData* poNetData)
{
	const ABYSS_OPEN_REQ *pstIn = (const ABYSS_OPEN_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwAbyssDBID, "AbyssDBID"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwOpenTime, "OpenTime"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeABYSS_OPEN_REQ(void *pHost, INetData* poNetData)
{
	ABYSS_OPEN_REQ *pstOut = (ABYSS_OPEN_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwAbyssDBID, "AbyssDBID"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwOpenTime, "OpenTime"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeABYSS_OPEN_ACK(const void *pHost, INetData* poNetData)
{
	const ABYSS_OPEN_ACK *pstIn = (const ABYSS_OPEN_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSAbyssRsServerInfo(&pstIn->stAbyssInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeABYSS_OPEN_ACK(void *pHost, INetData* poNetData)
{
	ABYSS_OPEN_ACK *pstOut = (ABYSS_OPEN_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSAbyssRsServerInfo(&pstOut->stAbyssInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeABYSS_OPEN_NTF(const void *pHost, INetData* poNetData)
{
	const ABYSS_OPEN_NTF *pstIn = (const ABYSS_OPEN_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nAbyssCount, "AbyssCount"))
		return -1;

	int i;
	if ((int)pstIn->nAbyssCount > MAX_ABYSS_OPEN_COUNT || pstIn->nAbyssCount < 0)
       return -1;
	for(i = 0; i < MAX_ABYSS_OPEN_COUNT; ++i)
	{
		if(i >= (int)pstIn->nAbyssCount)
			break;
		if(-1 == EncodeSAbyssRsServerInfo(&pstIn->astAbyssInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeABYSS_OPEN_NTF(void *pHost, INetData* poNetData)
{
	ABYSS_OPEN_NTF *pstOut = (ABYSS_OPEN_NTF*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nAbyssCount, "AbyssCount"))
		return -1;

	int i;
	if ((int)pstOut->nAbyssCount > MAX_ABYSS_OPEN_COUNT || pstOut->nAbyssCount < 0)
       return -1;
	for(i = 0; i < MAX_ABYSS_OPEN_COUNT; ++i)
	{
		if(i >= (int)pstOut->nAbyssCount)
			break;
		if(-1 == DecodeSAbyssRsServerInfo(&pstOut->astAbyssInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeGET_ABYSS_TRIGGER_LIST_REQ(const void *pHost, INetData* poNetData)
{
	const GET_ABYSS_TRIGGER_LIST_REQ *pstIn = (const GET_ABYSS_TRIGGER_LIST_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeGET_ABYSS_TRIGGER_LIST_REQ(void *pHost, INetData* poNetData)
{
	GET_ABYSS_TRIGGER_LIST_REQ *pstOut = (GET_ABYSS_TRIGGER_LIST_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeGET_ABYSS_TRIGGER_LIST_ACK(const void *pHost, INetData* poNetData)
{
	const GET_ABYSS_TRIGGER_LIST_ACK *pstIn = (const GET_ABYSS_TRIGGER_LIST_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nAbyssCount, "AbyssCount"))
		return -1;

	int i;
	if ((int)pstIn->nAbyssCount > MAX_ABYSS_OPEN_COUNT || pstIn->nAbyssCount < 0)
       return -1;
	for(i = 0; i < MAX_ABYSS_OPEN_COUNT; ++i)
	{
		if(i >= (int)pstIn->nAbyssCount)
			break;
		if(-1 == EncodeSAbyssRsServerInfo(&pstIn->astAbyssInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeGET_ABYSS_TRIGGER_LIST_ACK(void *pHost, INetData* poNetData)
{
	GET_ABYSS_TRIGGER_LIST_ACK *pstOut = (GET_ABYSS_TRIGGER_LIST_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nAbyssCount, "AbyssCount"))
		return -1;

	int i;
	if ((int)pstOut->nAbyssCount > MAX_ABYSS_OPEN_COUNT || pstOut->nAbyssCount < 0)
       return -1;
	for(i = 0; i < MAX_ABYSS_OPEN_COUNT; ++i)
	{
		if(i >= (int)pstOut->nAbyssCount)
			break;
		if(-1 == DecodeSAbyssRsServerInfo(&pstOut->astAbyssInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeGET_ABYSS_OPEN_LIST_REQ(const void *pHost, INetData* poNetData)
{
	const GET_ABYSS_OPEN_LIST_REQ *pstIn = (const GET_ABYSS_OPEN_LIST_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeGET_ABYSS_OPEN_LIST_REQ(void *pHost, INetData* poNetData)
{
	GET_ABYSS_OPEN_LIST_REQ *pstOut = (GET_ABYSS_OPEN_LIST_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeGET_ABYSS_OPEN_LIST_ACK(const void *pHost, INetData* poNetData)
{
	const GET_ABYSS_OPEN_LIST_ACK *pstIn = (const GET_ABYSS_OPEN_LIST_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nAbyssCount, "AbyssCount"))
		return -1;

	int i;
	if ((int)pstIn->nAbyssCount > MAX_ABYSS_OPEN_COUNT || pstIn->nAbyssCount < 0)
       return -1;
	for(i = 0; i < MAX_ABYSS_OPEN_COUNT; ++i)
	{
		if(i >= (int)pstIn->nAbyssCount)
			break;
		if(-1 == EncodeSAbyssRsServerInfo(&pstIn->astAbyssInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeGET_ABYSS_OPEN_LIST_ACK(void *pHost, INetData* poNetData)
{
	GET_ABYSS_OPEN_LIST_ACK *pstOut = (GET_ABYSS_OPEN_LIST_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nAbyssCount, "AbyssCount"))
		return -1;

	int i;
	if ((int)pstOut->nAbyssCount > MAX_ABYSS_OPEN_COUNT || pstOut->nAbyssCount < 0)
       return -1;
	for(i = 0; i < MAX_ABYSS_OPEN_COUNT; ++i)
	{
		if(i >= (int)pstOut->nAbyssCount)
			break;
		if(-1 == DecodeSAbyssRsServerInfo(&pstOut->astAbyssInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeABYSS_OPEN_RECORD(const void *pHost, INetData* poNetData)
{
	const ABYSS_OPEN_RECORD *pstIn = (const ABYSS_OPEN_RECORD*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwAbydbid, "Abydbid"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwAbyTmpid, "AbyTmpid"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwOpentime, "Opentime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szRolename, sizeof(pstIn->szRolename), "Rolename"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeABYSS_OPEN_RECORD(void *pHost, INetData* poNetData)
{
	ABYSS_OPEN_RECORD *pstOut = (ABYSS_OPEN_RECORD*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwAbydbid, "Abydbid"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwAbyTmpid, "AbyTmpid"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwOpentime, "Opentime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szRolename, sizeof(pstOut->szRolename), "Rolename"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeGET_ABYSS_OPEN_REC_REQ(const void *pHost, INetData* poNetData)
{
	const GET_ABYSS_OPEN_REC_REQ *pstIn = (const GET_ABYSS_OPEN_REC_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeGET_ABYSS_OPEN_REC_REQ(void *pHost, INetData* poNetData)
{
	GET_ABYSS_OPEN_REC_REQ *pstOut = (GET_ABYSS_OPEN_REC_REQ*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeGET_ABYSS_OPEN_REC_ACK(const void *pHost, INetData* poNetData)
{
	const GET_ABYSS_OPEN_REC_ACK *pstIn = (const GET_ABYSS_OPEN_REC_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->nCount > MAX_XABYSS_RECORD_COUNT || pstIn->nCount < 0)
       return -1;
	for(i = 0; i < MAX_XABYSS_RECORD_COUNT; ++i)
	{
		if(i >= (int)pstIn->nCount)
			break;
		if(-1 == EncodeABYSS_OPEN_RECORD(&pstIn->astRecords[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeGET_ABYSS_OPEN_REC_ACK(void *pHost, INetData* poNetData)
{
	GET_ABYSS_OPEN_REC_ACK *pstOut = (GET_ABYSS_OPEN_REC_ACK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->nCount > MAX_XABYSS_RECORD_COUNT || pstOut->nCount < 0)
       return -1;
	for(i = 0; i < MAX_XABYSS_RECORD_COUNT; ++i)
	{
		if(i >= (int)pstOut->nCount)
			break;
		if(-1 == DecodeABYSS_OPEN_RECORD(&pstOut->astRecords[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeATK_INFO(const void *pHost, INetData* poNetData)
{
	const ATK_INFO *pstIn = (const ATK_INFO*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byJob, "Job"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeATK_INFO(void *pHost, INetData* poNetData)
{
	ATK_INFO *pstOut = (ATK_INFO*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byJob, "Job"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeATK_INFO_LIST(const void *pHost, INetData* poNetData)
{
	const ATK_INFO_LIST *pstIn = (const ATK_INFO_LIST*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nAtkcount, "Atkcount"))
		return -1;

	int i;
	if ((int)pstIn->nAtkcount > MAX_FRIEND_COUNT || pstIn->nAtkcount < 0)
       return -1;
	for(i = 0; i < MAX_FRIEND_COUNT; ++i)
	{
		if(i >= (int)pstIn->nAtkcount)
			break;
		if(-1 == EncodeATK_INFO(&pstIn->astAtklist[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeATK_INFO_LIST(void *pHost, INetData* poNetData)
{
	ATK_INFO_LIST *pstOut = (ATK_INFO_LIST*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nAtkcount, "Atkcount"))
		return -1;

	int i;
	if ((int)pstOut->nAtkcount > MAX_FRIEND_COUNT || pstOut->nAtkcount < 0)
       return -1;
	for(i = 0; i < MAX_FRIEND_COUNT; ++i)
	{
		if(i >= (int)pstOut->nAtkcount)
			break;
		if(-1 == DecodeATK_INFO(&pstOut->astAtklist[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeABYSS_SEND_REWARD_MAIL(const void *pHost, INetData* poNetData)
{
	const ABYSS_SEND_REWARD_MAIL *pstIn = (const ABYSS_SEND_REWARD_MAIL*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTmpID, "TmpID"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szRolename, sizeof(pstIn->szRolename), "Rolename"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byJob, "Job"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nStatus, "Status"))
		return -1;

	if(-1 == EncodeATK_INFO_LIST(&pstIn->stAtkInfoList, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeABYSS_SEND_REWARD_MAIL(void *pHost, INetData* poNetData)
{
	ABYSS_SEND_REWARD_MAIL *pstOut = (ABYSS_SEND_REWARD_MAIL*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTmpID, "TmpID"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szRolename, sizeof(pstOut->szRolename), "Rolename"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byJob, "Job"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nStatus, "Status"))
		return -1;

	if(-1 == DecodeATK_INFO_LIST(&pstOut->stAtkInfoList, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSMailDetail(const void *pHost, INetData* poNetData)
{
	const SMailDetail *pstIn = (const SMailDetail*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byType, "Type"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwUniqueID, "UniqueID"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMoney, "Money"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwSendTime, "SendTime"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwReadTime, "ReadTime"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szSender, sizeof(pstIn->szSender), "Sender"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szReceiver, sizeof(pstIn->szReceiver), "Receiver"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szTitle, sizeof(pstIn->szTitle), "Title"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szContent, sizeof(pstIn->szContent), "Content"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byItemCount, "ItemCount"))
		return -1;

	int i;
	if ((int)pstIn->byItemCount > MAX_MAIL_ITEM_COUNT || pstIn->byItemCount < 0)
       return -1;
	for(i = 0; i < MAX_MAIL_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstIn->byItemCount)
			break;
		if(-1 == EncodeSXITEM(&pstIn->astItems[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSMailDetail(void *pHost, INetData* poNetData)
{
	SMailDetail *pstOut = (SMailDetail*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byType, "Type"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwUniqueID, "UniqueID"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMoney, "Money"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwSendTime, "SendTime"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwReadTime, "ReadTime"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szSender, sizeof(pstOut->szSender), "Sender"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szReceiver, sizeof(pstOut->szReceiver), "Receiver"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szTitle, sizeof(pstOut->szTitle), "Title"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szContent, sizeof(pstOut->szContent), "Content"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byItemCount, "ItemCount"))
		return -1;

	int i;
	if ((int)pstOut->byItemCount > MAX_MAIL_ITEM_COUNT || pstOut->byItemCount < 0)
       return -1;
	for(i = 0; i < MAX_MAIL_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstOut->byItemCount)
			break;
		if(-1 == DecodeSXITEM(&pstOut->astItems[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeMAIL_LIST(const void *pHost, INetData* poNetData)
{
	const MAIL_LIST *pstIn = (const MAIL_LIST*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddWord(pstIn->wCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->wCount > MAX_MAIL_COUNT || pstIn->wCount < 0)
       return -1;
	for(i = 0; i < MAX_MAIL_COUNT; ++i)
	{
		if(i >= (int)pstIn->wCount)
			break;
		if(-1 == EncodeSMailDetail(&pstIn->astMails[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeMAIL_LIST(void *pHost, INetData* poNetData)
{
	MAIL_LIST *pstOut = (MAIL_LIST*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelWord(pstOut->wCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->wCount > MAX_MAIL_COUNT || pstOut->wCount < 0)
       return -1;
	for(i = 0; i < MAX_MAIL_COUNT; ++i)
	{
		if(i >= (int)pstOut->wCount)
			break;
		if(-1 == DecodeSMailDetail(&pstOut->astMails[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSEND_MAIL(const void *pHost, INetData* poNetData)
{
	const SEND_MAIL *pstIn = (const SEND_MAIL*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nMoney, "Money"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szReceiver, sizeof(pstIn->szReceiver), "Receiver"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szTitle, sizeof(pstIn->szTitle), "Title"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szContent, sizeof(pstIn->szContent), "Content"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byItemCount, "ItemCount"))
		return -1;

	int i;
	if((int)pstIn->byItemCount > MAX_MAIL_ITEM_COUNT || pstIn->byItemCount < 0)
       return -1;
	for(i = 0; i < MAX_MAIL_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstIn->byItemCount)
			break;
		if(-1 == poNetData->AddUint64(pstIn->aqwItems[i], "Items"))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSEND_MAIL(void *pHost, INetData* poNetData)
{
	SEND_MAIL *pstOut = (SEND_MAIL*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nMoney, "Money"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szReceiver, sizeof(pstOut->szReceiver), "Receiver"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szTitle, sizeof(pstOut->szTitle), "Title"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szContent, sizeof(pstOut->szContent), "Content"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byItemCount, "ItemCount"))
		return -1;

	int i;
	if ((int)pstOut->byItemCount > MAX_MAIL_ITEM_COUNT || pstOut->byItemCount < 0)
       return -1;
	for(i = 0; i < MAX_MAIL_ITEM_COUNT; ++i)
	{
		if(i >= (int)pstOut->byItemCount)
			break;
		if(-1 == poNetData->DelUint64(pstOut->aqwItems[i], "Items"))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeMAIL_ID_LIST(const void *pHost, INetData* poNetData)
{
	const MAIL_ID_LIST *pstIn = (const MAIL_ID_LIST*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddWord(pstIn->wCount, "Count"))
		return -1;

	int i;
	if((int)pstIn->wCount > MAX_MAIL_COUNT || pstIn->wCount < 0)
       return -1;
	for(i = 0; i < MAX_MAIL_COUNT; ++i)
	{
		if(i >= (int)pstIn->wCount)
			break;
		if(-1 == poNetData->AddUint64(pstIn->aqwMailIDs[i], "MailIDs"))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeMAIL_ID_LIST(void *pHost, INetData* poNetData)
{
	MAIL_ID_LIST *pstOut = (MAIL_ID_LIST*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelWord(pstOut->wCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->wCount > MAX_MAIL_COUNT || pstOut->wCount < 0)
       return -1;
	for(i = 0; i < MAX_MAIL_COUNT; ++i)
	{
		if(i >= (int)pstOut->wCount)
			break;
		if(-1 == poNetData->DelUint64(pstOut->aqwMailIDs[i], "MailIDs"))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSPVPRoleAllData(const void *pHost, INetData* poNetData)
{
	const SPVPRoleAllData *pstIn = (const SPVPRoleAllData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwDigitid, "Digitid"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szRoleName, sizeof(pstIn->szRoleName), "RoleName"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRoleLevel, "RoleLevel"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMiLevel, "MiLevel"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRepute, "Repute"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nPoints, "Points"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRanks, "Ranks"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byBaseJob, "BaseJob"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairColor, "HairColor"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nAttack, "Attack"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSPVPRoleAllData(void *pHost, INetData* poNetData)
{
	SPVPRoleAllData *pstOut = (SPVPRoleAllData*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwDigitid, "Digitid"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szRoleName, sizeof(pstOut->szRoleName), "RoleName"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRoleLevel, "RoleLevel"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMiLevel, "MiLevel"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRepute, "Repute"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nPoints, "Points"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRanks, "Ranks"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byBaseJob, "BaseJob"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairColor, "HairColor"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nAttack, "Attack"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodePVP_MATCH(const void *pHost, INetData* poNetData)
{
	const PVP_MATCH *pstIn = (const PVP_MATCH*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szRoleName, sizeof(pstIn->szRoleName), "RoleName"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRoleLevel, "RoleLevel"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMilitaryLevel, "MilitaryLevel"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nPoints, "Points"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byBaseJob, "BaseJob"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairColor, "HairColor"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodePVP_MATCH(void *pHost, INetData* poNetData)
{
	PVP_MATCH *pstOut = (PVP_MATCH*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szRoleName, sizeof(pstOut->szRoleName), "RoleName"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRoleLevel, "RoleLevel"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMilitaryLevel, "MilitaryLevel"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nPoints, "Points"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byBaseJob, "BaseJob"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairColor, "HairColor"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodePVP_MATCH_LIST(const void *pHost, INetData* poNetData)
{
	const PVP_MATCH_LIST *pstIn = (const PVP_MATCH_LIST*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddWord(pstIn->wCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->wCount > MAX_PVP_MATCH_COUNT || pstIn->wCount < 0)
       return -1;
	for(i = 0; i < MAX_PVP_MATCH_COUNT; ++i)
	{
		if(i >= (int)pstIn->wCount)
			break;
		if(-1 == EncodePVP_MATCH(&pstIn->astPVPMatchList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodePVP_MATCH_LIST(void *pHost, INetData* poNetData)
{
	PVP_MATCH_LIST *pstOut = (PVP_MATCH_LIST*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelWord(pstOut->wCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->wCount > MAX_PVP_MATCH_COUNT || pstOut->wCount < 0)
       return -1;
	for(i = 0; i < MAX_PVP_MATCH_COUNT; ++i)
	{
		if(i >= (int)pstOut->wCount)
			break;
		if(-1 == DecodePVP_MATCH(&pstOut->astPVPMatchList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodePVP_RANK(const void *pHost, INetData* poNetData)
{
	const PVP_RANK *pstIn = (const PVP_RANK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szRoleName, sizeof(pstIn->szRoleName), "RoleName"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRoleLevel, "RoleLevel"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMilitaryLevel, "MilitaryLevel"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nPoints, "Points"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRank, "Rank"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byBaseJob, "BaseJob"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairColor, "HairColor"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodePVP_RANK(void *pHost, INetData* poNetData)
{
	PVP_RANK *pstOut = (PVP_RANK*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleid, "Roleid"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szRoleName, sizeof(pstOut->szRoleName), "RoleName"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRoleLevel, "RoleLevel"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMilitaryLevel, "MilitaryLevel"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nPoints, "Points"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRank, "Rank"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byBaseJob, "BaseJob"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairColor, "HairColor"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodePVP_RANK_LIST(const void *pHost, INetData* poNetData)
{
	const PVP_RANK_LIST *pstIn = (const PVP_RANK_LIST*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddWord(pstIn->wCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->wCount > MAX_PVP_RANK_COUNT || pstIn->wCount < 0)
       return -1;
	for(i = 0; i < MAX_PVP_RANK_COUNT; ++i)
	{
		if(i >= (int)pstIn->wCount)
			break;
		if(-1 == EncodePVP_RANK(&pstIn->astPVPRankList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodePVP_RANK_LIST(void *pHost, INetData* poNetData)
{
	PVP_RANK_LIST *pstOut = (PVP_RANK_LIST*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelWord(pstOut->wCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->wCount > MAX_PVP_RANK_COUNT || pstOut->wCount < 0)
       return -1;
	for(i = 0; i < MAX_PVP_RANK_COUNT; ++i)
	{
		if(i >= (int)pstOut->wCount)
			break;
		if(-1 == DecodePVP_RANK(&pstOut->astPVPRankList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRobotPet(const void *pHost, INetData* poNetData)
{
	const SRobotPet *pstIn = (const SRobotPet*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nTemplateId, "TemplateId"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRobotPet(void *pHost, INetData* poNetData)
{
	SRobotPet *pstOut = (SRobotPet*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nTemplateId, "TemplateId"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRobotPets(const void *pHost, INetData* poNetData)
{
	const SRobotPets *pstIn = (const SRobotPets*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddWord(pstIn->wPetCount, "PetCount"))
		return -1;

	int i;
	if ((int)pstIn->wPetCount > PET_BTPOS_TEAM || pstIn->wPetCount < 0)
       return -1;
	for(i = 0; i < PET_BTPOS_TEAM; ++i)
	{
		if(i >= (int)pstIn->wPetCount)
			break;
		if(-1 == EncodeSRobotPet(&pstIn->astPetsInfo[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->AddInt(pstIn->nPetLevel, "PetLevel"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nPetUp, "PetUp"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRobotPets(void *pHost, INetData* poNetData)
{
	SRobotPets *pstOut = (SRobotPets*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelWord(pstOut->wPetCount, "PetCount"))
		return -1;

	int i;
	if ((int)pstOut->wPetCount > PET_BTPOS_TEAM || pstOut->wPetCount < 0)
       return -1;
	for(i = 0; i < PET_BTPOS_TEAM; ++i)
	{
		if(i >= (int)pstOut->wPetCount)
			break;
		if(-1 == DecodeSRobotPet(&pstOut->astPetsInfo[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->DelInt(pstOut->nPetLevel, "PetLevel"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nPetUp, "PetUp"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRobosEquip(const void *pHost, INetData* poNetData)
{
	const SRobosEquip *pstIn = (const SRobosEquip*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nTemplateId, "TemplateId"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRobosEquip(void *pHost, INetData* poNetData)
{
	SRobosEquip *pstOut = (SRobosEquip*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nTemplateId, "TemplateId"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRobosEquips(const void *pHost, INetData* poNetData)
{
	const SRobosEquips *pstIn = (const SRobosEquips*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byEquipCount, "EquipCount"))
		return -1;

	int i;
	if ((int)pstIn->byEquipCount > MAX_EQUIP_ITEM_NUM || pstIn->byEquipCount < 0)
       return -1;
	for(i = 0; i < MAX_EQUIP_ITEM_NUM; ++i)
	{
		if(i >= (int)pstIn->byEquipCount)
			break;
		if(-1 == EncodeSRobosEquip(&pstIn->astEquipInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRobosEquips(void *pHost, INetData* poNetData)
{
	SRobosEquips *pstOut = (SRobosEquips*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byEquipCount, "EquipCount"))
		return -1;

	int i;
	if ((int)pstOut->byEquipCount > MAX_EQUIP_ITEM_NUM || pstOut->byEquipCount < 0)
       return -1;
	for(i = 0; i < MAX_EQUIP_ITEM_NUM; ++i)
	{
		if(i >= (int)pstOut->byEquipCount)
			break;
		if(-1 == DecodeSRobosEquip(&pstOut->astEquipInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRobotBuff(const void *pHost, INetData* poNetData)
{
	const SRobotBuff *pstIn = (const SRobotBuff*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nTemplateId, "TemplateId"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRobotBuff(void *pHost, INetData* poNetData)
{
	SRobotBuff *pstOut = (SRobotBuff*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nTemplateId, "TemplateId"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRobotBuffs(const void *pHost, INetData* poNetData)
{
	const SRobotBuffs *pstIn = (const SRobotBuffs*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byBuffCount, "BuffCount"))
		return -1;

	int i;
	if ((int)pstIn->byBuffCount > MAX_PVP_ROBOT_BUFF_COUNT || pstIn->byBuffCount < 0)
       return -1;
	for(i = 0; i < MAX_PVP_ROBOT_BUFF_COUNT; ++i)
	{
		if(i >= (int)pstIn->byBuffCount)
			break;
		if(-1 == EncodeSRobotBuff(&pstIn->astBuffInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRobotBuffs(void *pHost, INetData* poNetData)
{
	SRobotBuffs *pstOut = (SRobotBuffs*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byBuffCount, "BuffCount"))
		return -1;

	int i;
	if ((int)pstOut->byBuffCount > MAX_PVP_ROBOT_BUFF_COUNT || pstOut->byBuffCount < 0)
       return -1;
	for(i = 0; i < MAX_PVP_ROBOT_BUFF_COUNT; ++i)
	{
		if(i >= (int)pstOut->byBuffCount)
			break;
		if(-1 == DecodeSRobotBuff(&pstOut->astBuffInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSPVPRobot(const void *pHost, INetData* poNetData)
{
	const SPVPRobot *pstIn = (const SPVPRobot*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwUID, "UID"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwDGID, "DGID"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szName, sizeof(pstIn->szName), "Name"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nLevel, "Level"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byJob, "Job"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nQuality, "Quality"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRepute, "Repute"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMilitery, "Militery"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nPoints, "Points"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byHairColor, "HairColor"))
		return -1;

	if(-1 == EncodeSRobosEquips(&pstIn->stEquips, poNetData))
		return -1;

	if(-1 == EncodeSRobotPets(&pstIn->stPets, poNetData))
		return -1;

	if(-1 == EncodeSRobotBuffs(&pstIn->stBuffs, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSPVPRobot(void *pHost, INetData* poNetData)
{
	SPVPRobot *pstOut = (SPVPRobot*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwUID, "UID"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwDGID, "DGID"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szName, sizeof(pstOut->szName), "Name"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nLevel, "Level"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byJob, "Job"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nQuality, "Quality"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRepute, "Repute"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMilitery, "Militery"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nPoints, "Points"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->bySex, "Sex"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairStyle, "HairStyle"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byHairColor, "HairColor"))
		return -1;

	if(-1 == DecodeSRobosEquips(&pstOut->stEquips, poNetData))
		return -1;

	if(-1 == DecodeSRobotPets(&pstOut->stPets, poNetData))
		return -1;

	if(-1 == DecodeSRobotBuffs(&pstOut->stBuffs, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSSeverPVPBattleInfo(const void *pHost, INetData* poNetData)
{
	const SSeverPVPBattleInfo *pstIn = (const SSeverPVPBattleInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSPVPRoleAllData(&pstIn->stPVPProperty, poNetData))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szRoleAllInfo, sizeof(pstIn->szRoleAllInfo), "RoleAllInfo"))
		return -1;

	if(-1 == EncodeSPVPRobot(&pstIn->stPVPRobot, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSSeverPVPBattleInfo(void *pHost, INetData* poNetData)
{
	SSeverPVPBattleInfo *pstOut = (SSeverPVPBattleInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSPVPRoleAllData(&pstOut->stPVPProperty, poNetData))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szRoleAllInfo, sizeof(pstOut->szRoleAllInfo), "RoleAllInfo"))
		return -1;

	if(-1 == DecodeSPVPRobot(&pstOut->stPVPRobot, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeWBAtkInfo(const void *pHost, INetData* poNetData)
{
	const WBAtkInfo *pstIn = (const WBAtkInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwId, "Id"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szNm, sizeof(pstIn->szNm), "Nm"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nDmg, "Dmg"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nBuf, "Buf"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nBufId, "BufId"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRank, "Rank"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeWBAtkInfo(void *pHost, INetData* poNetData)
{
	WBAtkInfo *pstOut = (WBAtkInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwId, "Id"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szNm, sizeof(pstOut->szNm), "Nm"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nDmg, "Dmg"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nBuf, "Buf"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nBufId, "BufId"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRank, "Rank"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeWBBossBuff(const void *pHost, INetData* poNetData)
{
	const WBBossBuff *pstIn = (const WBBossBuff*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nPercent, "Percent"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nBuffID, "BuffID"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeWBBossBuff(void *pHost, INetData* poNetData)
{
	WBBossBuff *pstOut = (WBBossBuff*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nPercent, "Percent"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nBuffID, "BuffID"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSWorldBossInfo(const void *pHost, INetData* poNetData)
{
	const SWorldBossInfo *pstIn = (const SWorldBossInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwWBDBID, "WBDBID"))
		return -1;

	if(-1 == poNetData->AddDword(pstIn->dwWBTmpId, "WBTmpId"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nTotalNum, "TotalNum"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nBlood, "Blood"))
		return -1;

	if(-1 == EncodeWBBossBuff(&pstIn->stBossBuff, poNetData))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nAtkcount, "Atkcount"))
		return -1;

	int i;
	for(i = 0; i < MAX_WB_RANK_COUNT; ++i)
	{
		if(-1 == EncodeWBAtkInfo(&pstIn->astAtklist[i], poNetData))
			return -1;
	}

	if(-1 == EncodeWBAtkInfo(&pstIn->stAtkInfo, poNetData))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nStatus, "Status"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwStartTime, "StartTime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwEndTime, "EndTime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwKilltime, "Killtime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwReliveTime, "ReliveTime"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwNextTime, "NextTime"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nTime, "Time"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSWorldBossInfo(void *pHost, INetData* poNetData)
{
	SWorldBossInfo *pstOut = (SWorldBossInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwWBDBID, "WBDBID"))
		return -1;

	if(-1 == poNetData->DelDword(pstOut->dwWBTmpId, "WBTmpId"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nTotalNum, "TotalNum"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nBlood, "Blood"))
		return -1;

	if(-1 == DecodeWBBossBuff(&pstOut->stBossBuff, poNetData))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nAtkcount, "Atkcount"))
		return -1;

	int i;
	for(i = 0; i < MAX_WB_RANK_COUNT; ++i)
	{
		if(-1 == DecodeWBAtkInfo(&pstOut->astAtklist[i], poNetData))
			return -1;
	}

	if(-1 == DecodeWBAtkInfo(&pstOut->stAtkInfo, poNetData))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nStatus, "Status"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwStartTime, "StartTime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwEndTime, "EndTime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwKilltime, "Killtime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwReliveTime, "ReliveTime"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwNextTime, "NextTime"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nTime, "Time"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRankRoleReq(const void *pHost, INetData* poNetData)
{
	const SRankRoleReq *pstIn = (const SRankRoleReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddUint64(pstIn->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRankType, "RankType"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nPage, "Page"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRankRoleReq(void *pHost, INetData* poNetData)
{
	SRankRoleReq *pstOut = (SRankRoleReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelUint64(pstOut->qwRoleDBID, "RoleDBID"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRankType, "RankType"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nPage, "Page"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRankRole(const void *pHost, INetData* poNetData)
{
	const SRankRole *pstIn = (const SRankRole*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSRoleRsServerInfo(&pstIn->stRoleInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRankRole(void *pHost, INetData* poNetData)
{
	SRankRole *pstOut = (SRankRole*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSRoleRsServerInfo(&pstOut->stRoleInfo, poNetData))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSRankRoleAck(const void *pHost, INetData* poNetData)
{
	const SRankRoleAck *pstIn = (const SRankRoleAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == EncodeSRankRoleReq(&pstIn->stReq, poNetData))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nTotalCount, "TotalCount"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nSelfRank, "SelfRank"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nRankCount, "RankCount"))
		return -1;

	int i;
	if ((int)pstIn->nRankCount > MAX_RANK_PAGE_COUNT || pstIn->nRankCount < 0)
       return -1;
	for(i = 0; i < MAX_RANK_PAGE_COUNT; ++i)
	{
		if(i >= (int)pstIn->nRankCount)
			break;
		if(-1 == EncodeSRankRole(&pstIn->astRank[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSRankRoleAck(void *pHost, INetData* poNetData)
{
	SRankRoleAck *pstOut = (SRankRoleAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == DecodeSRankRoleReq(&pstOut->stReq, poNetData))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nTotalCount, "TotalCount"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nSelfRank, "SelfRank"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nRankCount, "RankCount"))
		return -1;

	int i;
	if ((int)pstOut->nRankCount > MAX_RANK_PAGE_COUNT || pstOut->nRankCount < 0)
       return -1;
	for(i = 0; i < MAX_RANK_PAGE_COUNT; ++i)
	{
		if(i >= (int)pstOut->nRankCount)
			break;
		if(-1 == DecodeSRankRole(&pstOut->astRank[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildListReq(const void *pHost, INetData* poNetData)
{
	const SGuildListReq *pstIn = (const SGuildListReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwPage, "Page"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildListReq(void *pHost, INetData* poNetData)
{
	SGuildListReq *pstOut = (SGuildListReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwPage, "Page"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildListInfo(const void *pHost, INetData* poNetData)
{
	const SGuildListInfo *pstIn = (const SGuildListInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nGuildId, "GuildId"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szGuildName, sizeof(pstIn->szGuildName), "GuildName"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nGuildLv, "GuildLv"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szPresidentName, sizeof(pstIn->szPresidentName), "PresidentName"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMemberCount, "MemberCount"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMemberMax, "MemberMax"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildListInfo(void *pHost, INetData* poNetData)
{
	SGuildListInfo *pstOut = (SGuildListInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nGuildId, "GuildId"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szGuildName, sizeof(pstOut->szGuildName), "GuildName"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nGuildLv, "GuildLv"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szPresidentName, sizeof(pstOut->szPresidentName), "PresidentName"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMemberCount, "MemberCount"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMemberMax, "MemberMax"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildListAck(const void *pHost, INetData* poNetData)
{
	const SGuildListAck *pstIn = (const SGuildListAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->byCount > MAX_GUILD_LIST_PER_PAGE || pstIn->byCount < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LIST_PER_PAGE; ++i)
	{
		if(i >= (int)pstIn->byCount)
			break;
		if(-1 == EncodeSGuildListInfo(&pstIn->astInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildListAck(void *pHost, INetData* poNetData)
{
	SGuildListAck *pstOut = (SGuildListAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->byCount > MAX_GUILD_LIST_PER_PAGE || pstOut->byCount < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LIST_PER_PAGE; ++i)
	{
		if(i >= (int)pstOut->byCount)
			break;
		if(-1 == DecodeSGuildListInfo(&pstOut->astInfo[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildEnterReq(const void *pHost, INetData* poNetData)
{
	const SGuildEnterReq *pstIn = (const SGuildEnterReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nGuildId, "GuildId"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildEnterReq(void *pHost, INetData* poNetData)
{
	SGuildEnterReq *pstOut = (SGuildEnterReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nGuildId, "GuildId"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildEnterAck(const void *pHost, INetData* poNetData)
{
	const SGuildEnterAck *pstIn = (const SGuildEnterAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nGuildId, "GuildId"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildEnterAck(void *pHost, INetData* poNetData)
{
	SGuildEnterAck *pstOut = (SGuildEnterAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nGuildId, "GuildId"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLeaveAck(const void *pHost, INetData* poNetData)
{
	const SGuildLeaveAck *pstIn = (const SGuildLeaveAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLeaveAck(void *pHost, INetData* poNetData)
{
	SGuildLeaveAck *pstOut = (SGuildLeaveAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildCreateReq(const void *pHost, INetData* poNetData)
{
	const SGuildCreateReq *pstIn = (const SGuildCreateReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddString(pstIn->szGuildName, sizeof(pstIn->szGuildName), "GuildName"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szGuildAim, sizeof(pstIn->szGuildAim), "GuildAim"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byCostType, "CostType"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildCreateReq(void *pHost, INetData* poNetData)
{
	SGuildCreateReq *pstOut = (SGuildCreateReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelString(pstOut->szGuildName, sizeof(pstOut->szGuildName), "GuildName"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szGuildAim, sizeof(pstOut->szGuildAim), "GuildAim"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byCostType, "CostType"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildCreateAck(const void *pHost, INetData* poNetData)
{
	const SGuildCreateAck *pstIn = (const SGuildCreateAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildCreateAck(void *pHost, INetData* poNetData)
{
	SGuildCreateAck *pstOut = (SGuildCreateAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildBaseInfo(const void *pHost, INetData* poNetData)
{
	const SGuildBaseInfo *pstIn = (const SGuildBaseInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddInt(pstIn->nGuildId, "GuildId"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szGuildName, sizeof(pstIn->szGuildName), "GuildName"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szGuildNotice, sizeof(pstIn->szGuildNotice), "GuildNotice"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMemberCount, "MemberCount"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMemberMax, "MemberMax"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMyContribution, "MyContribution"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMyContributionMax, "MyContributionMax"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildBaseInfo(void *pHost, INetData* poNetData)
{
	SGuildBaseInfo *pstOut = (SGuildBaseInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelInt(pstOut->nGuildId, "GuildId"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szGuildName, sizeof(pstOut->szGuildName), "GuildName"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szGuildNotice, sizeof(pstOut->szGuildNotice), "GuildNotice"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMemberCount, "MemberCount"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMemberMax, "MemberMax"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMyContribution, "MyContribution"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMyContributionMax, "MyContributionMax"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLog_MemberEnter(const void *pHost, INetData* poNetData)
{
	const SGuildLog_MemberEnter *pstIn = (const SGuildLog_MemberEnter*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szMemberName, sizeof(pstIn->szMemberName), "MemberName"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLog_MemberEnter(void *pHost, INetData* poNetData)
{
	SGuildLog_MemberEnter *pstOut = (SGuildLog_MemberEnter*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szMemberName, sizeof(pstOut->szMemberName), "MemberName"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLog_MemberKick(const void *pHost, INetData* poNetData)
{
	const SGuildLog_MemberKick *pstIn = (const SGuildLog_MemberKick*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szMemberName, sizeof(pstIn->szMemberName), "MemberName"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szKickName, sizeof(pstIn->szKickName), "KickName"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLog_MemberKick(void *pHost, INetData* poNetData)
{
	SGuildLog_MemberKick *pstOut = (SGuildLog_MemberKick*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szMemberName, sizeof(pstOut->szMemberName), "MemberName"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szKickName, sizeof(pstOut->szKickName), "KickName"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLog_PotitionChange(const void *pHost, INetData* poNetData)
{
	const SGuildLog_PotitionChange *pstIn = (const SGuildLog_PotitionChange*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szMemberName, sizeof(pstIn->szMemberName), "MemberName"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szPositionChangeName, sizeof(pstIn->szPositionChangeName), "PositionChangeName"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byNewPosition, "NewPosition"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLog_PotitionChange(void *pHost, INetData* poNetData)
{
	SGuildLog_PotitionChange *pstOut = (SGuildLog_PotitionChange*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szMemberName, sizeof(pstOut->szMemberName), "MemberName"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szPositionChangeName, sizeof(pstOut->szPositionChangeName), "PositionChangeName"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byNewPosition, "NewPosition"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLog_PresidentChange(const void *pHost, INetData* poNetData)
{
	const SGuildLog_PresidentChange *pstIn = (const SGuildLog_PresidentChange*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szFromName, sizeof(pstIn->szFromName), "FromName"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szToName, sizeof(pstIn->szToName), "ToName"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLog_PresidentChange(void *pHost, INetData* poNetData)
{
	SGuildLog_PresidentChange *pstOut = (SGuildLog_PresidentChange*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szFromName, sizeof(pstOut->szFromName), "FromName"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szToName, sizeof(pstOut->szToName), "ToName"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLog_PresidentImpeach(const void *pHost, INetData* poNetData)
{
	const SGuildLog_PresidentImpeach *pstIn = (const SGuildLog_PresidentImpeach*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szFromName, sizeof(pstIn->szFromName), "FromName"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szToName, sizeof(pstIn->szToName), "ToName"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLog_PresidentImpeach(void *pHost, INetData* poNetData)
{
	SGuildLog_PresidentImpeach *pstOut = (SGuildLog_PresidentImpeach*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szFromName, sizeof(pstOut->szFromName), "FromName"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szToName, sizeof(pstOut->szToName), "ToName"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLog_LevelUp(const void *pHost, INetData* poNetData)
{
	const SGuildLog_LevelUp *pstIn = (const SGuildLog_LevelUp*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nFromLevel, "FromLevel"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nToLevel, "ToLevel"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLog_LevelUp(void *pHost, INetData* poNetData)
{
	SGuildLog_LevelUp *pstOut = (SGuildLog_LevelUp*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nFromLevel, "FromLevel"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nToLevel, "ToLevel"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLog_TechnologyUp(const void *pHost, INetData* poNetData)
{
	const SGuildLog_TechnologyUp *pstIn = (const SGuildLog_TechnologyUp*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byTechnologyType, "TechnologyType"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szOpName, sizeof(pstIn->szOpName), "OpName"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nFromLevel, "FromLevel"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nToLevel, "ToLevel"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLog_TechnologyUp(void *pHost, INetData* poNetData)
{
	SGuildLog_TechnologyUp *pstOut = (SGuildLog_TechnologyUp*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byTechnologyType, "TechnologyType"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szOpName, sizeof(pstOut->szOpName), "OpName"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nFromLevel, "FromLevel"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nToLevel, "ToLevel"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLog_Pray(const void *pHost, INetData* poNetData)
{
	const SGuildLog_Pray *pstIn = (const SGuildLog_Pray*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byPrayType, "PrayType"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szOpName, sizeof(pstIn->szOpName), "OpName"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMoney, "Money"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLog_Pray(void *pHost, INetData* poNetData)
{
	SGuildLog_Pray *pstOut = (SGuildLog_Pray*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byPrayType, "PrayType"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szOpName, sizeof(pstOut->szOpName), "OpName"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMoney, "Money"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLog_NoticeChange(const void *pHost, INetData* poNetData)
{
	const SGuildLog_NoticeChange *pstIn = (const SGuildLog_NoticeChange*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szOpName, sizeof(pstIn->szOpName), "OpName"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLog_NoticeChange(void *pHost, INetData* poNetData)
{
	SGuildLog_NoticeChange *pstOut = (SGuildLog_NoticeChange*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szOpName, sizeof(pstOut->szOpName), "OpName"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLog_AimChange(const void *pHost, INetData* poNetData)
{
	const SGuildLog_AimChange *pstIn = (const SGuildLog_AimChange*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddDword(pstIn->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szOpName, sizeof(pstIn->szOpName), "OpName"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLog_AimChange(void *pHost, INetData* poNetData)
{
	SGuildLog_AimChange *pstOut = (SGuildLog_AimChange*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelDword(pstOut->dwTime, "Time"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szOpName, sizeof(pstOut->szOpName), "OpName"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildLogAck(const void *pHost, INetData* poNetData)
{
	const SGuildLogAck *pstIn = (const SGuildLogAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byCount11, "Count11"))
		return -1;

	int i;
	if ((int)pstIn->byCount11 > MAX_GUILD_LOG_COUNT || pstIn->byCount11 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount11)
			break;
		if(-1 == EncodeSGuildLog_MemberEnter(&pstIn->astMemberEnter[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->AddByte(pstIn->byCount12, "Count12"))
		return -1;

	if ((int)pstIn->byCount12 > MAX_GUILD_LOG_COUNT || pstIn->byCount12 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount12)
			break;
		if(-1 == EncodeSGuildLog_MemberKick(&pstIn->astMemberKick[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->AddByte(pstIn->byCount13, "Count13"))
		return -1;

	if ((int)pstIn->byCount13 > MAX_GUILD_LOG_COUNT || pstIn->byCount13 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount13)
			break;
		if(-1 == EncodeSGuildLog_PotitionChange(&pstIn->astPotitionChange[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->AddByte(pstIn->byCount14, "Count14"))
		return -1;

	if ((int)pstIn->byCount14 > MAX_GUILD_LOG_COUNT || pstIn->byCount14 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount14)
			break;
		if(-1 == EncodeSGuildLog_PresidentChange(&pstIn->astPresidentChange[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->AddByte(pstIn->byCount15, "Count15"))
		return -1;

	if ((int)pstIn->byCount15 > MAX_GUILD_LOG_COUNT || pstIn->byCount15 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount15)
			break;
		if(-1 == EncodeSGuildLog_PresidentImpeach(&pstIn->astPresidentImpeach[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->AddByte(pstIn->byCount20, "Count20"))
		return -1;

	if ((int)pstIn->byCount20 > MAX_GUILD_LOG_COUNT || pstIn->byCount20 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount20)
			break;
		if(-1 == EncodeSGuildLog_LevelUp(&pstIn->astLevelUp[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->AddByte(pstIn->byCount30, "Count30"))
		return -1;

	if ((int)pstIn->byCount30 > MAX_GUILD_LOG_COUNT || pstIn->byCount30 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount30)
			break;
		if(-1 == EncodeSGuildLog_TechnologyUp(&pstIn->astTechnologyUp[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->AddByte(pstIn->byCount40, "Count40"))
		return -1;

	if ((int)pstIn->byCount40 > MAX_GUILD_LOG_COUNT || pstIn->byCount40 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount40)
			break;
		if(-1 == EncodeSGuildLog_Pray(&pstIn->astPray[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->AddByte(pstIn->byCount50, "Count50"))
		return -1;

	if ((int)pstIn->byCount50 > MAX_GUILD_LOG_COUNT || pstIn->byCount50 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount50)
			break;
		if(-1 == EncodeSGuildLog_NoticeChange(&pstIn->astNoticeChange[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->AddByte(pstIn->byCount60, "Count60"))
		return -1;

	if ((int)pstIn->byCount60 > MAX_GUILD_LOG_COUNT || pstIn->byCount60 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount60)
			break;
		if(-1 == EncodeSGuildLog_AimChange(&pstIn->astAimChange[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildLogAck(void *pHost, INetData* poNetData)
{
	SGuildLogAck *pstOut = (SGuildLogAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byCount11, "Count11"))
		return -1;

	int i;
	if ((int)pstOut->byCount11 > MAX_GUILD_LOG_COUNT || pstOut->byCount11 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount11)
			break;
		if(-1 == DecodeSGuildLog_MemberEnter(&pstOut->astMemberEnter[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->DelByte(pstOut->byCount12, "Count12"))
		return -1;

	if ((int)pstOut->byCount12 > MAX_GUILD_LOG_COUNT || pstOut->byCount12 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount12)
			break;
		if(-1 == DecodeSGuildLog_MemberKick(&pstOut->astMemberKick[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->DelByte(pstOut->byCount13, "Count13"))
		return -1;

	if ((int)pstOut->byCount13 > MAX_GUILD_LOG_COUNT || pstOut->byCount13 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount13)
			break;
		if(-1 == DecodeSGuildLog_PotitionChange(&pstOut->astPotitionChange[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->DelByte(pstOut->byCount14, "Count14"))
		return -1;

	if ((int)pstOut->byCount14 > MAX_GUILD_LOG_COUNT || pstOut->byCount14 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount14)
			break;
		if(-1 == DecodeSGuildLog_PresidentChange(&pstOut->astPresidentChange[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->DelByte(pstOut->byCount15, "Count15"))
		return -1;

	if ((int)pstOut->byCount15 > MAX_GUILD_LOG_COUNT || pstOut->byCount15 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount15)
			break;
		if(-1 == DecodeSGuildLog_PresidentImpeach(&pstOut->astPresidentImpeach[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->DelByte(pstOut->byCount20, "Count20"))
		return -1;

	if ((int)pstOut->byCount20 > MAX_GUILD_LOG_COUNT || pstOut->byCount20 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount20)
			break;
		if(-1 == DecodeSGuildLog_LevelUp(&pstOut->astLevelUp[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->DelByte(pstOut->byCount30, "Count30"))
		return -1;

	if ((int)pstOut->byCount30 > MAX_GUILD_LOG_COUNT || pstOut->byCount30 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount30)
			break;
		if(-1 == DecodeSGuildLog_TechnologyUp(&pstOut->astTechnologyUp[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->DelByte(pstOut->byCount40, "Count40"))
		return -1;

	if ((int)pstOut->byCount40 > MAX_GUILD_LOG_COUNT || pstOut->byCount40 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount40)
			break;
		if(-1 == DecodeSGuildLog_Pray(&pstOut->astPray[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->DelByte(pstOut->byCount50, "Count50"))
		return -1;

	if ((int)pstOut->byCount50 > MAX_GUILD_LOG_COUNT || pstOut->byCount50 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount50)
			break;
		if(-1 == DecodeSGuildLog_NoticeChange(&pstOut->astNoticeChange[i], poNetData))
			return -1;
	}

	if(-1 == poNetData->DelByte(pstOut->byCount60, "Count60"))
		return -1;

	if ((int)pstOut->byCount60 > MAX_GUILD_LOG_COUNT || pstOut->byCount60 < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_LOG_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount60)
			break;
		if(-1 == DecodeSGuildLog_AimChange(&pstOut->astAimChange[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildChangeNoticeReq(const void *pHost, INetData* poNetData)
{
	const SGuildChangeNoticeReq *pstIn = (const SGuildChangeNoticeReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddString(pstIn->szNewNotice, sizeof(pstIn->szNewNotice), "NewNotice"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildChangeNoticeReq(void *pHost, INetData* poNetData)
{
	SGuildChangeNoticeReq *pstOut = (SGuildChangeNoticeReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelString(pstOut->szNewNotice, sizeof(pstOut->szNewNotice), "NewNotice"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildChangeNoticeAck(const void *pHost, INetData* poNetData)
{
	const SGuildChangeNoticeAck *pstIn = (const SGuildChangeNoticeAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildChangeNoticeAck(void *pHost, INetData* poNetData)
{
	SGuildChangeNoticeAck *pstOut = (SGuildChangeNoticeAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildMemberListInfo(const void *pHost, INetData* poNetData)
{
	const SGuildMemberListInfo *pstIn = (const SGuildMemberListInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddString(pstIn->szName, sizeof(pstIn->szName), "Name"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nLevel, "Level"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nAttack, "Attack"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byPosition, "Position"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nContribution, "Contribution"))
		return -1;

	if(-1 == poNetData->AddUint64(pstIn->qwOfflineTime, "OfflineTime"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildMemberListInfo(void *pHost, INetData* poNetData)
{
	SGuildMemberListInfo *pstOut = (SGuildMemberListInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelString(pstOut->szName, sizeof(pstOut->szName), "Name"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nLevel, "Level"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nAttack, "Attack"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byPosition, "Position"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nContribution, "Contribution"))
		return -1;

	if(-1 == poNetData->DelUint64(pstOut->qwOfflineTime, "OfflineTime"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildDetailAck(const void *pHost, INetData* poNetData)
{
	const SGuildDetailAck *pstIn = (const SGuildDetailAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddString(pstIn->szGuildName, sizeof(pstIn->szGuildName), "GuildName"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nGuildId, "GuildId"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nGuildLevel, "GuildLevel"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMemberCount, "MemberCount"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMemberMax, "MemberMax"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nGuildAttack, "GuildAttack"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nAttack, "Attack"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nReputation, "Reputation"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nMoney, "Money"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szGuildAim, sizeof(pstIn->szGuildAim), "GuildAim"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->byCount > MAX_GUILD_MEMBER_COUNT || pstIn->byCount < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_MEMBER_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount)
			break;
		if(-1 == EncodeSGuildMemberListInfo(&pstIn->astMemberList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildDetailAck(void *pHost, INetData* poNetData)
{
	SGuildDetailAck *pstOut = (SGuildDetailAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelString(pstOut->szGuildName, sizeof(pstOut->szGuildName), "GuildName"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nGuildId, "GuildId"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nGuildLevel, "GuildLevel"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMemberCount, "MemberCount"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMemberMax, "MemberMax"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nGuildAttack, "GuildAttack"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nAttack, "Attack"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nReputation, "Reputation"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nMoney, "Money"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szGuildAim, sizeof(pstOut->szGuildAim), "GuildAim"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->byCount > MAX_GUILD_MEMBER_COUNT || pstOut->byCount < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_MEMBER_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount)
			break;
		if(-1 == DecodeSGuildMemberListInfo(&pstOut->astMemberList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildEnterInfo(const void *pHost, INetData* poNetData)
{
	const SGuildEnterInfo *pstIn = (const SGuildEnterInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddString(pstIn->szName, sizeof(pstIn->szName), "Name"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nLevel, "Level"))
		return -1;

	if(-1 == poNetData->AddInt(pstIn->nAttack, "Attack"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byBaseJob, "BaseJob"))
		return -1;

	if(-1 == poNetData->AddByte(pstIn->byJob, "Job"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildEnterInfo(void *pHost, INetData* poNetData)
{
	SGuildEnterInfo *pstOut = (SGuildEnterInfo*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelString(pstOut->szName, sizeof(pstOut->szName), "Name"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nLevel, "Level"))
		return -1;

	if(-1 == poNetData->DelInt(pstOut->nAttack, "Attack"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byBaseJob, "BaseJob"))
		return -1;

	if(-1 == poNetData->DelByte(pstOut->byJob, "Job"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildEnterListAck(const void *pHost, INetData* poNetData)
{
	const SGuildEnterListAck *pstIn = (const SGuildEnterListAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstIn->byCount > MAX_GUILD_ENTER_COUNT || pstIn->byCount < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_ENTER_COUNT; ++i)
	{
		if(i >= (int)pstIn->byCount)
			break;
		if(-1 == EncodeSGuildEnterInfo(&pstIn->astEnterList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildEnterListAck(void *pHost, INetData* poNetData)
{
	SGuildEnterListAck *pstOut = (SGuildEnterListAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byCount, "Count"))
		return -1;

	int i;
	if ((int)pstOut->byCount > MAX_GUILD_ENTER_COUNT || pstOut->byCount < 0)
       return -1;
	for(i = 0; i < MAX_GUILD_ENTER_COUNT; ++i)
	{
		if(i >= (int)pstOut->byCount)
			break;
		if(-1 == DecodeSGuildEnterInfo(&pstOut->astEnterList[i], poNetData))
			return -1;
	}

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildEnterAcceptReq(const void *pHost, INetData* poNetData)
{
	const SGuildEnterAcceptReq *pstIn = (const SGuildEnterAcceptReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byAccept, "Accept"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szName, sizeof(pstIn->szName), "Name"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildEnterAcceptReq(void *pHost, INetData* poNetData)
{
	SGuildEnterAcceptReq *pstOut = (SGuildEnterAcceptReq*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byAccept, "Accept"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szName, sizeof(pstOut->szName), "Name"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildEnterAcceptAck(const void *pHost, INetData* poNetData)
{
	const SGuildEnterAcceptAck *pstIn = (const SGuildEnterAcceptAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	if(-1 == poNetData->AddString(pstIn->szName, sizeof(pstIn->szName), "Name"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildEnterAcceptAck(void *pHost, INetData* poNetData)
{
	SGuildEnterAcceptAck *pstOut = (SGuildEnterAcceptAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	if(-1 == poNetData->DelString(pstOut->szName, sizeof(pstOut->szName), "Name"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

int EncodeSGuildEnterClearAck(const void *pHost, INetData* poNetData)
{
	const SGuildEnterClearAck *pstIn = (const SGuildEnterClearAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->AddByte(pstIn->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return poNetData->GetDataLen();
}

int DecodeSGuildEnterClearAck(void *pHost, INetData* poNetData)
{
	SGuildEnterClearAck *pstOut = (SGuildEnterClearAck*)pHost;
	poNetData->EnterStruct();

	if(-1 == poNetData->DelByte(pstOut->byResult, "Result"))
		return -1;

	poNetData->LeaveStruct();
	return sizeof(*pstOut);
}

