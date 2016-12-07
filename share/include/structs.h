#ifndef __STRUCTS_H_2014_01_08_17_43__
#define __STRUCTS_H_2014_01_08_17_43__

#ifndef SDTYPE_H
#include "sdtype.h"
#endif

#ifndef __TYPES_H_2014_01_08_16_56__
#include "types.h"
#endif

#ifndef __MACROS_H_2014_01_09_11_11__
#include "macros.h"
#endif

#ifndef HEADPROTO_H_INCLUDE_VERSION_1
#include "headerproto.h"
#endif

#include <vector>
#include <list>
#include <set>
#include <string>
#include <map>
#include <cassert>


// tolua_begin
struct SPoint
{
    int nX;
    int nY;
};

struct SPos
{
    SPos() :nX(INVALID_INT_VALUE),nY(INVALID_INT_VALUE), nZ(INVALID_INT_VALUE)
    {}

    SPos(int x, int y, int z = INVALID_INT_VALUE) : nX(x), nY(y), nZ(z)
    {}

    SPos(const SPos& rhs) : nX(rhs.nX), nY(rhs.nY), nZ(rhs.nZ)
    {}

    SPos operator + (const SPos& rhs) const
    {
        SPos st;
        st.nX = this->nX + rhs.nX;
        st.nY = this->nY + rhs.nY;
        st.nZ = this->nZ + rhs.nZ;
        return st;
    }

    SPos operator - (const SPos& rhs) const
    {
        SPos st;
        st.nX = this->nX - rhs.nX;
        st.nY = this->nY - rhs.nY;
        st.nZ = this->nZ - rhs.nZ;
        return st;
    }

    SPos operator * (float fVal) const
    {
        SPos st;
        st.nX = (int)(this->nX*fVal);
        st.nY = (int)(this->nY*fVal);
        st.nZ = (int)(this->nZ*fVal);
        return st;
    }

    SPos operator / (float fVal) const
    {
        SPos st;
        st.nX = (int)(this->nX/fVal);
        st.nY = (int)(this->nY/fVal);
        st.nZ = (int)(this->nZ/fVal);
        return st;
    }


    SPos& operator = (const SPos& rhs)
    {
        if (&rhs != this)
        {
            this->nX = rhs.nX;
            this->nY = rhs.nY;
            this->nZ = rhs.nZ;
        }

        return *this;
    }

    bool operator <= (const SPos& rhs) const
    {
        return (nX <= rhs.nX &&
                    nY <= rhs.nY &&
                    nZ <= rhs.nZ);
    }

    bool operator < (const SPos& rhs) const
    {
        return (nX < rhs.nX &&
                    nY < rhs.nY &&
                    nZ < rhs.nZ);
    }

    bool operator >= (const SPos& rhs) const
    {
        return (nX >= rhs.nX &&
                    nY >= rhs.nY &&
                    nZ >= rhs.nZ);
    }

    bool operator > (const SPos& rhs) const
    {
        return (nX > rhs.nX &&
                    nY > rhs.nY &&
                    nZ > rhs.nZ);
    }

    bool operator == (const SPos& rhs) const
    {
        return ( nX == rhs.nX
                    && nY == rhs.nY
                    && nZ == rhs.nZ);
    }

    bool operator != (const SPos& rhs) const
    {
        return !operator == (rhs);
    }

    //������д��������ģ�� SPosInfo������
    SPos& operator = (const SPosInfo & rhs)
    {
        this->nX = rhs.nX;
        this->nY = rhs.nY;
        this->nZ = rhs.nZ;
        return *this;
    }

    //��������С
    void MiniMize(int nMultiple)
    {
        nX /= nMultiple;
        nY /= nMultiple;
        nZ /= nMultiple;
    }

    // ȫ�ֵ�0λ��
    static const SPos& Zero()
    {
        static SPos stZero(INVALID_INT_VALUE, INVALID_INT_VALUE, INVALID_INT_VALUE);
        return stZero;
    }

    void Release()
    {
        delete this;
    }

    int nX;
    int nY;
    int nZ;
};


struct SVector
{
    SVector() :fX(0),fY(0), fZ(0)
    {}
    SVector(float x, float y, float z = 0) : fX(x), fY(y), fZ(z)
    {}

    SVector operator + (const SVector& rhs)
    {
        SVector st;
        st.fX = this->fX + rhs.fX;
        st.fY = this->fY + rhs.fY;
        st.fZ = this->fZ + rhs.fZ;
        return st;
    }

    SVector operator - (const SVector& rhs)
    {
        SVector st;
        st.fX = this->fX - rhs.fX;
        st.fY = this->fY - rhs.fY;
        st.fZ = this->fZ - rhs.fZ;
        return st;
    }
    SVector operator * (float fVal)
    {
        SVector st;
        st.fX = (this->fX*fVal);
        st.fY = (this->fY*fVal);
        st.fZ = (this->fZ*fVal);
        return st;
    }

    SVector operator / (float fVal)
    {
        SVector st;
        st.fX = (this->fX/fVal);
        st.fY = (this->fY/fVal);
        st.fZ = (this->fZ/fVal);
        return st;
    }


    SVector& operator = (const SVector& rhs)
    {
        if (&rhs != this)
        {
            this->fX = rhs.fX;
            this->fY = rhs.fY;
            this->fZ = rhs.fZ;
        }

        return *this;
    }

    bool operator == (const SVector& rhs)
    {
        return ( fX == rhs.fX
                    && fY == rhs.fY
                    && fZ == rhs.fZ);
    }

    bool operator != (const SVector& rhs)
    {
        return !operator == (rhs);
    }

    static const SVector& Zero()
    {
        static SVector stZeroVec(0, 0, 0);
        return stZeroVec;
    }

    float fX;
    float fY;
    float fZ;
};

inline bool CheckBit(UINT32 dwValue, int nBit)
{
    if (sizeof(UINT32) < nBit)
    {
        return false;
    }

    return (dwValue | 1 << nBit) > 0 ? true : false;
}

inline UINT32 SetBit(UINT32 dwValue, int nBit)
{
    if (sizeof(UINT32) < nBit)
    {
        return false;
    }

    return (dwValue | 1 << nBit);
}

struct SGridPos
{
    short GridX;
    short GridY;
    short GridZ;
};

struct  SCellIndex
{
    UINT16  wXIndex;
    UINT16  wYIndex;
};

struct SArgs
{
    SArgs(UINT32 dwArgs) : dwEventId(dwArgs), objId(0) {}
    SArgs(UINT32 dwArgs, UINT32 dwObjID) : dwEventId(dwArgs), objId(dwObjID) {}
    unsigned int    dwEventId;
    unsigned int    objId;
};
// tolua_end

inline
bool operator == (const SPosInfo &a, const SPosInfo &b)
{
    return a.nX == b.nX && a.nY == b.nY && a.nZ == b.nZ && a.nOrientation == b.nOrientation;
}

struct SMailItemTemplate
{
	int nTemplateID;
	int nCount;
};

struct SSendMail
{
	int               nMoney;	/// ��Ǯ            
	char              szReceiver[ROLE_NAME_LEN];	/// �ռ�������      
	char              szTitle[MAX_MAIL_TITLE_LEN];	/// ����            
	char              szContent[MAX_MAIL_CONTENT_LEN];	/// ����            
	unsigned char     byItemCount;	/// ��Ʒ����        
	SMailItemTemplate aItems[MAX_MAIL_ITEM_COUNT];
};

struct SWorldBossTimeNode
{
	UINT64	qwTimePoint;	//ʱ���
	int		nTypePoint;		//timer����  1-׼�� 2-��ʼ 3-���� 4-����
};

struct SWorldBossTime
{
	int		nIndex;			//
	std::vector<SWorldBossTimeNode> vecTime;
};

struct SBossTimeTemplate
{
	int		nStartHour;
	int		nStartMinite;
	int		nStopHour;
	int		nStopMinite;
};

#endif ///__STRUCTS_H_2014_01_08_17_43__
