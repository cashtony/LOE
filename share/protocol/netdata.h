#ifndef __NETDATA_H_INCLUDE__
#define __NETDATA_H_INCLUDE__

#if (defined(WIN32) || defined(WIN64))
  #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
  #endif
  #include <Winsock2.h>
#endif

#include "fsm.h"

unsigned long long htonll(unsigned long long number);
unsigned long long ntohll(unsigned long long number);
class INetData
{
public:
    virtual ~INetData() = 0;

    virtual void Prepare(char *pNetData, int iSize) = 0;
    virtual void Reset() = 0;

    virtual char* GetData() = 0;
    virtual int GetDataLen() const = 0;

    virtual void EnterStruct(){}
    virtual void LeaveStruct(){}

    virtual int AddByte(unsigned char byByte, const char* key) = 0;
    virtual int DelByte(unsigned char &byByte, const char* key) = 0;
    
    virtual int AddChar(char chChar, const char* key) = 0;
    virtual int DelChar(char &chChar, const char* key) = 0;

    virtual int AddWord(unsigned short wWord, const char* key) = 0;
    virtual int DelWord(unsigned short &wWord, const char* key) = 0;
    
    virtual int AddShort(short shShort, const char* key) = 0;
    virtual int DelShort(short &shShort, const char* key) = 0;

    virtual int AddDword(unsigned int dwDword, const char* key) = 0;
    virtual int DelDword(unsigned int &dwDword, const char* key) = 0;
    
    virtual int AddInt(int iInt, const char* key) = 0;
    virtual int DelInt(int &iInt, const char* key) = 0;

    virtual int AddUint64(unsigned long long qwUint64, const char* key) = 0;
    virtual int DelUint64(unsigned long long& qwUint64, const char* key) = 0;
    
    virtual int AddInt64(long long llInt64, const char* key) = 0;
    virtual int DelInt64(long long &llInt64, const char* key) = 0;
    
    virtual int AddFloat(float fFloat, const char* key) = 0;
    virtual int DelFloat(float &fFloat, const char* key) = 0;
    
    virtual int AddDouble(double dbDouble, const char* key) = 0;
    virtual int DelDouble(double &dbDouble, const char* key) = 0;
    
    virtual int AddString(const char *pszString, int iSize, const char* key) = 0;
    virtual int DelString(char *pszOut, int iSize, const char* key) = 0;
    
    virtual int Strnlen(const char *pszString, int iSize, const char* key) = 0;
     
    virtual int AddBuf(const unsigned char* pbyBuf, int iSize, const char* key) = 0;
    virtual int DelBuf(unsigned char* pbyBuf, int iSize, const char* key) = 0;

};
inline
INetData::~INetData()
{
}

class CNetData : public INetData
{
public:
	CNetData();
	virtual ~CNetData();

	virtual void Prepare(char *pNetData, int iSize);
	virtual void Reset();
    
    virtual char* GetData(){ return m_pBuf; }
    virtual int GetDataLen() const { return m_iPos; }
    
	virtual int AddByte(unsigned char byByte, const char* key = "");
	virtual int DelByte(unsigned char &byByte, const char* key = "");
    
	virtual int AddChar(char chChar, const char* key = "");
	virtual int DelChar(char &chChar, const char* key = "");
    
	virtual int AddWord(unsigned short wWord, const char* key = "");
	virtual int DelWord(unsigned short &wWord, const char* key = "");
    
	virtual int AddShort(short shShort, const char* key = "");
	virtual int DelShort(short &shShort, const char* key = "");
    
	virtual int AddDword(unsigned int dwDword, const char* key = "");
	virtual int DelDword(unsigned int &dwDword, const char* key = "");
    
	virtual int AddInt(int iInt, const char* key = "");
	virtual int DelInt(int &iInt, const char* key = "");
    
	virtual int AddUint64(unsigned long long qwUint64, const char* key = "");
	virtual int DelUint64(unsigned long long& qwUint64, const char* key = "");
    
	virtual int AddInt64(long long llInt64, const char* key = "");
	virtual int DelInt64(long long &llInt64, const char* key = "");
    
	virtual int AddFloat(float fFloat, const char* key = "");
	virtual int DelFloat(float &fFloat, const char* key = "");
    
	virtual int AddDouble(double dbDouble, const char* key = ""); 
	virtual int DelDouble(double &dbDouble, const char* key = "");
    
	virtual int AddString(const char *pszString, int iSize, const char* key = "");
	virtual int DelString(char *pszOut, int iSize, const char* key = "");
    
	virtual int Strnlen(const char *pszString, int iSize, const char* key = "");
     
	virtual int AddBuf(const unsigned char* pbyBuf, int iSize, const char* key = "");
	virtual int DelBuf(unsigned char* pbyBuf, int iSize, const char* key = "");

protected:
	char * m_pBuf;
	int m_iSize;
	int m_iPos;
};

template <typename SType>
struct STypeBit
{
    typedef SType SBitType;
    #define CHAT_BIT_COUNT 8

    STypeBit(const SType& tData)
    {
        tType = tData;
    }

    STypeBit()
    {
        tType = SType();
    }

    operator SType()const
    {
        return tType;
    }

    template<typename SOtherType>
    operator SOtherType()
    {
        return static_cast<SOtherType>(tType);
    }

    bool operator [] (int nBit) const
    {
        return Test(nBit);
    }

    void operator = (const SType& tVal)
    {
        tType = tVal;
    }

    void  Set(int nBit, bool bSet)
    {
        if ((sizeof(SType) * CHAT_BIT_COUNT) <= nBit)
        {
            if (bSet)
            {
                // 只要查出范围的值，就将每个bit设置1, gqf
                tType = (0x1 << sizeof(SType)) - 1;
            }
            return;
        }

        int nBitMask = (0x1 << nBit);
        bSet? (tType |= nBitMask) : (tType &= ~nBitMask);
    }

    bool Test(int nBit) const
    {
        if ((sizeof(SType) * CHAT_BIT_COUNT) <= nBit)
        {
            return false;
        }

        return ((tType & (0x1 << nBit))? true : false);
    }

    SType Count() const
    {
        SType tCount = SType();
        for (SType i = tType; i != 0; i &= (i - 1))
        {
            tCount++;
        }
        return tCount;
    }

    SType tType;
};

#endif // __NETDATA_H_INCLUDE__
