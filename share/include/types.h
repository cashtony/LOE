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
	CreatureState_Alive = 0,    ///活着
	CreatureState_Dead,     ///死亡
	CreatureState_Coma,     ///昏迷
};


///  tolua_end
enum EShopItem
{
    ShopItem_Potion = 1, // 推图使用的药品
    ShopItem_Relive = 2, // 推图复活
};


#endif /// __TYPES_H_2014_01_08_16_56__


