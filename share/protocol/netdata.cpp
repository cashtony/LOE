#include "netdata.h"


unsigned long long htonll(unsigned long long number)
{
    return ( htonl( (unsigned long)((number >> 32) & 0xFFFFFFFF)) |
        ((unsigned long long) (htonl((unsigned long)(number & 0xFFFFFFFF)))  << 32));
}

unsigned long long ntohll(unsigned long long number)
{
    return ( ntohl( (unsigned long)((number >> 32) & 0xFFFFFFFF) ) |
        ((unsigned long long) (ntohl((unsigned long)(number & 0xFFFFFFFF)))  << 32));
}

CNetData::CNetData()
{
	m_pBuf	= NULL;
	m_iSize = 0;
	m_iPos	= 0;
}

CNetData::~CNetData()
{
}

void CNetData::Prepare(char *pNetData, int iSize)
{
	m_pBuf	= pNetData;
	m_iSize	= iSize;
	m_iPos	= 0;
}

void CNetData::Reset()
{
	m_iPos = 0;
}

int CNetData::AddByte(unsigned char byByte, const char* key)
{
	if(m_iPos + (int)sizeof(byByte) > m_iSize)
		return -1;

	*(unsigned char*)(m_pBuf + m_iPos) = byByte;
	m_iPos += sizeof(byByte);

	return m_iPos; 
}

int CNetData::DelByte(unsigned char &byByte, const char* key)
{
	if(m_iPos + (int)sizeof(byByte) > m_iSize)
		return -1;

	byByte = *(unsigned char*)(m_pBuf + m_iPos);
	m_iPos += sizeof(byByte);

	return m_iPos;
}

int CNetData::AddChar(char chChar, const char* key)
{
	if(m_iPos + (int)sizeof(chChar) > m_iSize)
		return -1;

	*(char*)(m_pBuf + m_iPos) = chChar;
	m_iPos += sizeof(chChar);

	return m_iPos; 
}

int CNetData::DelChar(char &chChar, const char* key)
{
	if(m_iPos + (int)sizeof(chChar) > m_iSize)
		return -1;

	chChar = *(char*)(m_pBuf + m_iPos);
	m_iPos += sizeof(chChar);

	return m_iPos; 
}

int CNetData::AddWord(unsigned short wWord, const char* key)
{
	if(m_iPos + (int)sizeof(wWord) > m_iSize)
		return -1;

	*(unsigned short*)(m_pBuf + m_iPos) = htons(wWord);
	m_iPos += sizeof(wWord);

	return m_iPos; 
}

int CNetData::DelWord(unsigned short &wWord, const char* key)
{
	if(m_iPos + (int)sizeof(wWord) > m_iSize)
		return -1;

	wWord = ntohs(*(unsigned short*)(m_pBuf + m_iPos));
	m_iPos += sizeof(wWord);

	return m_iPos; 
}

int CNetData::AddShort(short shShort, const char* key)
{
	if(m_iPos + (int)sizeof(shShort) > m_iSize)
		return -1;

	*(short*)(m_pBuf + m_iPos) = htons(shShort);
	m_iPos += sizeof(shShort);

	return m_iPos;
}

int CNetData::DelShort(short &shShort, const char* key)
{
	if(m_iPos + (int)sizeof(shShort) > m_iSize)
		return -1;

	shShort = ntohs(*(short*)(m_pBuf + m_iPos));
	m_iPos += sizeof(shShort);

	return m_iPos;
}

int CNetData::AddDword(unsigned int dwDword, const char* key)
{
	if(m_iPos + (int)sizeof(dwDword) > m_iSize)
		return -1;

	*(unsigned int*)(m_pBuf + m_iPos) = htonl(dwDword);
	m_iPos += sizeof(dwDword);

	return m_iPos;
}

int CNetData::DelDword(unsigned int &dwDword, const char* key)
{
	if(m_iPos + (int)sizeof(dwDword) > m_iSize)
		return -1;

	dwDword = ntohl(*(unsigned int*)(m_pBuf + m_iPos));
	m_iPos += sizeof(dwDword);

	return m_iPos;
}

int CNetData::AddInt(int iInt, const char* key)
{
	if(m_iPos + (int)sizeof(iInt) > m_iSize)
		return -1;

	*(int*)(m_pBuf + m_iPos) = htonl(iInt);
	m_iPos += sizeof(iInt);

	return m_iPos;
}

int CNetData::DelInt(int &iInt, const char* key)
{
	if(m_iPos + (int)sizeof(iInt) > m_iSize)
		return -1;

	iInt = ntohl(*(int*)(m_pBuf + m_iPos));
	m_iPos += sizeof(iInt);

	return m_iPos;
}

int CNetData::AddUint64(unsigned long long qwUint64, const char* key)
{
	if(m_iPos + (int)sizeof(qwUint64) > m_iSize)
		return -1;

	*(unsigned long long*)(m_pBuf + m_iPos) = htonll(qwUint64);
	m_iPos += sizeof(qwUint64);

	return m_iPos;
}

int CNetData::DelUint64(unsigned long long& qwUint64, const char* key)
{
	if(m_iPos + (int)sizeof(qwUint64) > m_iSize)
		return -1;

	qwUint64 = ntohll(*(unsigned long long*)(m_pBuf + m_iPos));
	m_iPos += sizeof(qwUint64);

	return m_iPos;
}

int CNetData::AddInt64(long long llInt64, const char* key)
{
	if(m_iPos + (int)sizeof(llInt64) > m_iSize)
		return -1;

	*(long long*)(m_pBuf + m_iPos) = htonll(llInt64);
	m_iPos += sizeof(llInt64);

	return m_iPos;
}

int CNetData::DelInt64(long long &llInt64, const char* key)
{
	if(m_iPos + (int)sizeof(llInt64) > m_iSize)
		return -1;

	llInt64 = ntohll(*(long long*)(m_pBuf + m_iPos));
	m_iPos += sizeof(llInt64);

	return m_iPos;
}

int CNetData::AddFloat(float fFloat, const char* key)
{
	if(m_iPos + (int)sizeof(fFloat) > m_iSize)
		return -1;

	*(float*)(m_pBuf + m_iPos) = fFloat;
	m_iPos += sizeof(fFloat);

	return m_iPos;
}

int CNetData::DelFloat(float &fFloat, const char* key)
{
	if(m_iPos + (int)sizeof(fFloat) > m_iSize)
		return -1;

	fFloat = (*(float*)(m_pBuf + m_iPos));
	m_iPos += sizeof(fFloat);

	return m_iPos;
}

int CNetData::AddDouble(double dbDouble, const char* key)
{
    if(m_iPos + (int)sizeof(dbDouble) > m_iSize)
        return -1;

    *(double*)(m_pBuf + m_iPos) = dbDouble;
    m_iPos += sizeof(dbDouble);

    return m_iPos;
}

int CNetData::DelDouble(double &dbDouble, const char* key)
{
    if(m_iPos + (int)sizeof(dbDouble) > m_iSize)
        return -1;

    dbDouble = (*(double*)(m_pBuf + m_iPos));
    m_iPos += sizeof(dbDouble);

    return m_iPos;
}

int CNetData::AddString(const char *pszString, int iSize, const char* key)
{
	int iLen = Strnlen(pszString, iSize-1);

	if(m_iPos + (int)sizeof(unsigned short) + iLen > m_iSize)
		return -1;

	if(-1 == AddWord((unsigned short)iLen))
		return -1;

	memcpy(m_pBuf + m_iPos, pszString, iLen);
	m_iPos += iLen;

	return m_iPos;
}

int CNetData::DelString(char *pszOut, int iSize, const char* key)
{
	unsigned short wLen = 0;
	if(-1 == DelWord(wLen))
		return -1;

	if(m_iPos + (int)wLen > m_iSize)
		return -1;

	if( int(wLen + 1) > iSize )
		return -1;

	memcpy(pszOut, m_pBuf+m_iPos, wLen);
	pszOut[wLen] = '\0';
	m_iPos += wLen;

	return m_iPos;
}

int CNetData::Strnlen(const char *pszString, int iSize, const char* key)
{
	int i;
	const char *ptr = pszString;

	for(i = 0; i < iSize; i++)
	{
		if('\0' == *ptr)
		{
			return i;
		}
		ptr++;
	}

	return iSize;
}

int CNetData::AddBuf( const unsigned char* pbyBuf, int iSize , const char* key)
{
	if (iSize < 0 || NULL == pbyBuf)
	{
		return -1;
	}

	if(m_iPos + iSize > m_iSize)
		return -1;

	memcpy(m_pBuf + m_iPos, pbyBuf, iSize);
	m_iPos += iSize;

	return m_iPos;
}

int CNetData::DelBuf( unsigned char* pbyBuf, int iSize , const char* key)
{
	if (iSize < 0 || NULL == pbyBuf)
	{
		return -1;
	}

	if(m_iPos + iSize > m_iSize)
		return -1;

	memcpy(pbyBuf, m_pBuf+m_iPos, iSize);

	m_iPos += iSize;

	return m_iPos;
}
