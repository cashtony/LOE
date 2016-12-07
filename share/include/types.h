#ifndef __TYPES_H_2014_01_08_16_56__
#define __TYPES_H_2014_01_08_16_56__
#include "math.h"
#include "cliproto.h"

///  tolua_begin

enum EObjType
{
	ObjType_Role = 0,
	ObjType_Monster,
	ObjType_Pet,
	ObjType_Item,
	ObjType_Buff,
	ObjType_Trigger,
	ObjType_Duelmark,
	ObjType_Deadmark,
	ObjType_Size,
	ObjType_Invalid = -1,
};


enum ECreatureState
{
	CreatureState_Alive = 0,    ///����
	CreatureState_Dead,     ///����
	CreatureState_Coma,     ///����
};


///  tolua_end
enum EShopItem
{
    ShopItem_Potion = 1, // ��ͼʹ�õ�ҩƷ
    ShopItem_Relive = 2, // ��ͼ����
};


#endif /// __TYPES_H_2014_01_08_16_56__


