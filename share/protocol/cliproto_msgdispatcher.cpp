#include "cliproto_msgdispatcher.h"

NSCLIPROTO_BEGIN

bool CCliProtoMsgDispatcher::Init()
{
    Register(CGID_LOGIN, &CCliProtoMsgDispatcher::OnCG_LOGIN, sizeof(CG_LOGIN));
    Register(GCID_LOGIN, &CCliProtoMsgDispatcher::OnGC_LOGIN, sizeof(GC_LOGIN));
    Register(CGID_LOGOUT, &CCliProtoMsgDispatcher::OnCG_LOGOUT, sizeof(CG_LOGOUT));
    Register(GCID_LOGOUT, &CCliProtoMsgDispatcher::OnGC_LOGOUT, sizeof(GC_LOGOUT));
    Register(GCID_ROLELIST, &CCliProtoMsgDispatcher::OnGC_ROLELIST, sizeof(GC_ROLELIST));
    Register(CGID_CREATEROLE, &CCliProtoMsgDispatcher::OnCG_CREATEROLE, sizeof(CG_CREATEROLE));
    Register(GCID_CREATEROLE, &CCliProtoMsgDispatcher::OnGC_CREATEROLE, sizeof(GC_CREATEROLE));
    Register(CGID_DELROLE, &CCliProtoMsgDispatcher::OnCG_DELROLE, sizeof(CG_DELROLE));
    Register(GCID_DELROLE, &CCliProtoMsgDispatcher::OnGC_DELROLE, sizeof(GC_DELROLE));
    Register(CGID_SELECTROLE, &CCliProtoMsgDispatcher::OnCG_SELECTROLE, sizeof(CG_SELECTROLE));
    Register(GCID_SELECTROLE, &CCliProtoMsgDispatcher::OnGC_SELECTROLE, sizeof(GC_SELECTROLE));
    Register(GCID_QUEUE_INFO, &CCliProtoMsgDispatcher::OnGC_QUEUE_INFO, sizeof(GC_QUEUE_INFO));
    Register(GCID_GPK_DYN_CODE, &CCliProtoMsgDispatcher::OnGC_GPK_CLT_DYN_CODE, sizeof(GC_GPK_CLT_DYN_CODE));
    Register(CGID_GPK_NEGLECT, &CCliProtoMsgDispatcher::OnCG_GPK_CLT_NEGLECT, sizeof(CG_GPK_CLT_NEGLECT));
    Register(GCID_GPK_CAL_ORIGIN, &CCliProtoMsgDispatcher::OnGC_GPK_CAL_ORIGIN, sizeof(GC_GPK_CAL_ORIGIN));
    Register(CGID_GPK_CAL_RESULT, &CCliProtoMsgDispatcher::OnCG_GPK_CAL_RESULT, sizeof(CG_GPK_CAL_RESULT));
    Register(GCID_ERROR, &CCliProtoMsgDispatcher::OnGC_ERROR, sizeof(GC_ERROR));
    Register(GCID_ERRORSTRING, &CCliProtoMsgDispatcher::OnGC_ERRORSTRING, sizeof(GC_ERRORSTRING));
    Register(CGID_HEART_BEAT, &CCliProtoMsgDispatcher::OnCG_HEART_BEAT, sizeof(CG_HEART_BEAT));
    Register(GCID_HEART_BEAT, &CCliProtoMsgDispatcher::OnGC_HEART_BEAT, sizeof(GC_HEART_BEAT));
    Register(GCID_PUBLIC_STRING, &CCliProtoMsgDispatcher::OnGC_PUBLIC_STRING, sizeof(GC_PUBLIC_STRING));
    Register(LGID_LOGIN_REQ, &CCliProtoMsgDispatcher::OnLGPKG_LOGIN_REQ, sizeof(LGPKG_LOGIN_REQ));
    Register(LGID_LOGIN_ACK, &CCliProtoMsgDispatcher::OnLGPKG_LOGIN_ACK, sizeof(LGPKG_LOGIN_ACK));
    Register(LGID_GAMESERVER_LIST_REQ, &CCliProtoMsgDispatcher::OnLGPKG_GAMESERVER_LIST_REQ, sizeof(LGPKG_GAMESERVER_LIST_REQ));
    Register(LGID_GAMESERVER_LIST_ACK, &CCliProtoMsgDispatcher::OnLGPKG_GAMESERVER_LIST_ACK, sizeof(LGPKG_GAMESERVER_LIST_ACK));
    Register(GSID_SERVERINFO_RPT, &CCliProtoMsgDispatcher::OnGSPKG_SERVERINFO_RPT, sizeof(GSPKG_SERVERINFO_RPT));
    Register(GSID_SERVER_GROUP_DESC_RPT, &CCliProtoMsgDispatcher::OnGSPKG_SERVER_GROUP_DESC_RPT, sizeof(GSPKG_SERVER_GROUP_DESC_RPT));
    Register(GSID_ENTERGAME_REQ, &CCliProtoMsgDispatcher::OnGSPKG_ENTERGAME_REQ, sizeof(GSPKG_ENTERGAME_REQ));
    Register(GSID_ENTERGAME_ACK, &CCliProtoMsgDispatcher::OnGSPKG_ENTERGAME_ACK, sizeof(GSPKG_ENTERGAME_ACK));
    Register(GSID_LEAVEGAME_REQ, &CCliProtoMsgDispatcher::OnGSPKG_LEAVEGAME_REQ, sizeof(GSPKG_LEAVEGAME_REQ));
    Register(GSID_LEAVEGAME_ACK, &CCliProtoMsgDispatcher::OnGSPKG_LEAVEGAME_ACK, sizeof(GSPKG_LEAVEGAME_ACK));
    Register(GSID_KICKOUT_NTF, &CCliProtoMsgDispatcher::OnGSPKG_KICKOUT_NTF, sizeof(GSPKG_KICKOUT_NTF));
    Register(GSID_MSG_BROADCAST, &CCliProtoMsgDispatcher::OnGSPKG_MSG_BROADCAST, sizeof(GSPKG_MSG_BROADCAST));
    Register(GSID_LOAD_GSDATA_NTF, &CCliProtoMsgDispatcher::OnGSPKG_LOAD_GSDATA_NTF, sizeof(GSPKG_LOAD_GSDATA_NTF));
    Register(GSID_UPDATEGMLEVEL_NTF, &CCliProtoMsgDispatcher::OnGSPKG_UPDATEGMLEVEL_NTF, sizeof(GSPKG_UPDATEGMLEVEL_NTF));
    Register(GSID_SWITCHSCENE_REQ, &CCliProtoMsgDispatcher::OnGSPKG_SWITCHSCENE_REQ, sizeof(GSPKG_SWITCHSCENE_REQ));
    Register(GSID_SWITCHSCENE_ACK, &CCliProtoMsgDispatcher::OnGSPKG_SWITCHSCENE_ACK, sizeof(GSPKG_SWITCHSCENE_ACK));
    Register(SCID_SELF_LOADSCENE, &CCliProtoMsgDispatcher::OnSC_SELF_LOADSCENE, sizeof(SC_SELF_LOADSCENE));
    Register(CSID_ENTERSCENE, &CCliProtoMsgDispatcher::OnCS_ENTERSCENE, sizeof(CS_ENTERSCENE));
    Register(SCID_SELF_ENTERSCENE, &CCliProtoMsgDispatcher::OnSC_SELF_ENTERSCENE, sizeof(SC_SELF_ENTERSCENE));
    Register(SCID_SELF_DATA_END, &CCliProtoMsgDispatcher::OnSC_SELF_DATA_END, sizeof(SC_SELF_DATA_END));
    Register(SCID_SELF_APPEAR, &CCliProtoMsgDispatcher::OnSC_SELF_APPEAR, sizeof(SC_SELF_APPEAR));
    Register(SCID_SELF_BASE_PRO, &CCliProtoMsgDispatcher::OnSC_SELF_BASE_PRO, sizeof(SC_SELF_BASE_PRO));
    Register(CSID_LEVEL_REQ, &CCliProtoMsgDispatcher::OnCS_LEVEL_REQ, sizeof(CS_LEVEL_REQ));
    Register(SCID_LEVEL_ACK, &CCliProtoMsgDispatcher::OnSC_LEVEL_ACK, sizeof(SC_LEVEL_ACK));
    Register(CSID_LEVEL_RESULT_NTF, &CCliProtoMsgDispatcher::OnCS_LEVEL_RESULT_NTF, sizeof(CS_LEVEL_RESULT_NTF));
    Register(SCID_TREASURE_CHEST_NTF, &CCliProtoMsgDispatcher::OnSC_TREASURE_CHEST_NTF, sizeof(SC_TREASURE_CHEST_NTF));
    Register(CSID_OPEN_TREASURE_CHEST_REQ, &CCliProtoMsgDispatcher::OnCS_OPEN_TREASURE_CHEST_REQ, sizeof(CS_OPEN_TREASURE_CHEST_REQ));
    Register(SCID_OPEN_TREASURE_CHEST_ACK, &CCliProtoMsgDispatcher::OnSC_OPEN_TREASURE_CHEST_ACK, sizeof(SC_OPEN_TREASURE_CHEST_ACK));
    Register(SCID_LEVEL_INFO, &CCliProtoMsgDispatcher::OnSC_LEVEL_INFO, sizeof(SC_LEVEL_INFO));
    Register(CSID_GET_BATTLE_BOX_REQ, &CCliProtoMsgDispatcher::OnCS_GET_BATTLE_BOX_REQ, sizeof(CS_GET_BATTLE_BOX_REQ));
    Register(SCID_GET_BATTLE_BOX_ACK, &CCliProtoMsgDispatcher::OnSC_GET_BATTLE_BOX_ACK, sizeof(SC_GET_BATTLE_BOX_ACK));
    Register(SCID_BATTLE_GOT_STAR_NTF, &CCliProtoMsgDispatcher::OnSC_BATTLE_GOT_STAR_NTF, sizeof(SC_BATTLE_GOT_STAR_NTF));
    Register(SCID_SELF_VOLATILE_PRO, &CCliProtoMsgDispatcher::OnSC_SELF_VOLATILE_PRO, sizeof(SC_SELF_VOLATILE_PRO));
    Register(SCID_CLIENT_CONFIG_NTF, &CCliProtoMsgDispatcher::OnSC_CLIENT_CONFIG_NTF, sizeof(SC_CLIENT_CONFIG_NTF));
    Register(CSID_CLIENT_CONFIG_UPDATE, &CCliProtoMsgDispatcher::OnCS_CLIENT_CONFIG_UPDATE, sizeof(CS_CLIENT_CONFIG_UPDATE));
    Register(SCID_ERROR_NTF, &CCliProtoMsgDispatcher::OnSC_ERROR_NTF, sizeof(SC_ERROR_NTF));
    Register(SCID_SELF_ITEM_NTF, &CCliProtoMsgDispatcher::OnSC_SELF_ITEM_NTF, sizeof(SC_SELF_ITEM_NTF));
    Register(CSID_MOVE_ITEM_REQ, &CCliProtoMsgDispatcher::OnCS_MOVE_ITEM_REQ, sizeof(CS_MOVE_ITEM_REQ));
    Register(SCID_MOVE_ITEM_ACK, &CCliProtoMsgDispatcher::OnSC_MOVE_ITEM_ACK, sizeof(SC_MOVE_ITEM_ACK));
    Register(SCID_ROLE_BAG_NTF, &CCliProtoMsgDispatcher::OnSC_ROLE_BAG_NTF, sizeof(SC_ROLE_BAG_NTF));
    Register(SCID_ROLE_EQUIP_NTF, &CCliProtoMsgDispatcher::OnSC_ROLE_EQUIP_NTF, sizeof(SC_ROLE_EQUIP_NTF));
    Register(CSID_ROLE_EQUIP_REQ, &CCliProtoMsgDispatcher::OnCS_ROLE_EQUIP_REQ, sizeof(CS_ROLE_EQUIP_REQ));
    Register(CSID_ROLE_EVENT_REQ, &CCliProtoMsgDispatcher::OnCS_ROLE_EVENT_REQ, sizeof(CS_ROLE_EVENT_REQ));
    Register(SCID_ROLE_BAG_SINGLE_LEAVE_NTF, &CCliProtoMsgDispatcher::OnSC_ROLE_BAG_SINGLE_LEAVE_NTF, sizeof(SC_ROLE_BAG_SINGLE_LEAVE_NTF));
    Register(SCID_ROLE_BAG_SINGLE_ENTER_NTF, &CCliProtoMsgDispatcher::OnSC_ROLE_BAG_SINGLE_ENTER_NTF, sizeof(SC_ROLE_BAG_SINGLE_ENTER_NTF));
    Register(SCID_ROLE_EQUIP_SINGLE_LEAVE_NTF, &CCliProtoMsgDispatcher::OnSC_ROLE_EQUIP_SINGLE_LEAVE_NTF, sizeof(SC_ROLE_EQUIP_SINGLE_LEAVE_NTF));
    Register(SCID_ROLE_EQUIP_SINGLE_ENTER_NTF, &CCliProtoMsgDispatcher::OnSC_ROLE_EQUIP_SINGLE_ENTER_NTF, sizeof(SC_ROLE_EQUIP_SINGLE_ENTER_NTF));
    Register(CSID_ROLE_ITEMUP_RPT, &CCliProtoMsgDispatcher::OnCS_ROLE_ITEMUP_RPT, sizeof(CS_ROLE_ITEMUP_RPT));
    Register(SCID_ROLE_ITEMUP_NTF, &CCliProtoMsgDispatcher::OnSC_ROLE_ITEMUP_NTF, sizeof(SC_ROLE_ITEMUP_NTF));
    Register(SCID_ROLE_ITEMUP_ACK, &CCliProtoMsgDispatcher::OnSC_ROLE_ITEMUP_ACK, sizeof(SC_ROLE_ITEMUP_ACK));
    Register(SCID_ROLE_SUIT_NTF, &CCliProtoMsgDispatcher::OnSC_ROLE_SUIT_NTF, sizeof(SC_ROLE_SUIT_NTF));
    Register(CSID_ROLE_HOLE_ON_REQ, &CCliProtoMsgDispatcher::OnCS_ROLE_HOLE_ON_REQ, sizeof(CS_ROLE_HOLE_ON_REQ));
    Register(SCID_ROLE_HOLE_ON_ACK, &CCliProtoMsgDispatcher::OnSC_ROLE_HOLE_ON_ACK, sizeof(SC_ROLE_HOLE_ON_ACK));
    Register(CSID_ROLE_HOLE_OFF_REQ, &CCliProtoMsgDispatcher::OnCS_ROLE_HOLE_OFF_REQ, sizeof(CS_ROLE_HOLE_OFF_REQ));
    Register(SCID_ROLE_HOLE_OFF_ACK, &CCliProtoMsgDispatcher::OnSC_ROLE_HOLE_OFF_ACK, sizeof(SC_ROLE_HOLE_OFF_ACK));
    Register(CSID_ROLE_HOLE_REFRESH_REQ, &CCliProtoMsgDispatcher::OnCS_ROLE_HOLE_REFRESH_REQ, sizeof(CS_ROLE_HOLE_REFRESH_REQ));
    Register(SCID_ROLE_HOLE_REFRESH_ACK, &CCliProtoMsgDispatcher::OnSC_ROLE_HOLE_REFRESH_ACK, sizeof(SC_ROLE_HOLE_REFRESH_ACK));
    Register(CSID_ROLE_HOLE_MERGE_REQ, &CCliProtoMsgDispatcher::OnCS_ROLE_HOLE_MERGE_REQ, sizeof(CS_ROLE_HOLE_MERGE_REQ));
    Register(SCID_ROLE_HOLE_MERGE_ACK, &CCliProtoMsgDispatcher::OnSC_ROLE_HOLE_MERGE_ACK, sizeof(SC_ROLE_HOLE_MERGE_ACK));
    Register(CSID_ROLE_HOLE_MERGE2_REQ, &CCliProtoMsgDispatcher::OnCS_ROLE_HOLE_MERGE2_REQ, sizeof(CS_ROLE_HOLE_MERGE2_REQ));
    Register(SCID_ROLE_HOLE_MERGE2_ACK, &CCliProtoMsgDispatcher::OnSC_ROLE_HOLE_MERGE2_ACK, sizeof(SC_ROLE_HOLE_MERGE2_ACK));
    Register(CSID_LOCK_RPT, &CCliProtoMsgDispatcher::OnCS_LOCK_RPT, sizeof(CS_LOCK_RPT));
    Register(CSID_ROLE_USEITEM_REQ, &CCliProtoMsgDispatcher::OnCS_ROLE_USEITEM_REQ, sizeof(CS_ROLE_USEITEM_REQ));
    Register(CSID_PET_USEITEM_REQ, &CCliProtoMsgDispatcher::OnCS_PET_USEITEM_REQ, sizeof(CS_PET_USEITEM_REQ));
    Register(SCID_PET_USEITEM_ACK, &CCliProtoMsgDispatcher::OnSC_PET_USEITEM_ACK, sizeof(SC_PET_USEITEM_ACK));
    Register(SCID_ROLE_LIMIT_NTF, &CCliProtoMsgDispatcher::OnSC_ROLE_LIMIT_NTF, sizeof(SC_ROLE_LIMIT_NTF));
    Register(CSID_GATHER_ITEM_MERGE_REQ, &CCliProtoMsgDispatcher::OnCS_GATHER_ITEM_MERGE_REQ, sizeof(CS_GATHER_ITEM_MERGE_REQ));
    Register(SCID_GATHER_ITEM_MERGE_ACK, &CCliProtoMsgDispatcher::OnSC_GATHER_ITEM_MERGE_ACK, sizeof(SC_GATHER_ITEM_MERGE_ACK));
    Register(SCID_GATHER_INFO_NTF, &CCliProtoMsgDispatcher::OnSC_GATHER_INFO_NTF, sizeof(SC_GATHER_INFO_NTF));
    Register(SCID_GATHER_SINGLE_ENTER_NTF, &CCliProtoMsgDispatcher::OnSC_GATHER_SINGLE_ENTER_NTF, sizeof(SC_GATHER_SINGLE_ENTER_NTF));
    Register(SCID_GATHER_SINGLE_LEAVE_NTF, &CCliProtoMsgDispatcher::OnSC_GATHER_SINGLE_LEAVE_NTF, sizeof(SC_GATHER_SINGLE_LEAVE_NTF));
    Register(CSID_ROLE_PROD_REQ, &CCliProtoMsgDispatcher::OnCS_ROLE_PROD_REQ, sizeof(CS_ROLE_PROD_REQ));
    Register(SCID_ROLE_PROD_ACK, &CCliProtoMsgDispatcher::OnSC_ROLE_PROD_ACK, sizeof(SC_ROLE_PROD_ACK));
    Register(SCID_ROLE_USEITEM_START_ACK, &CCliProtoMsgDispatcher::OnSC_ROLE_USEITEM_START_ACK, sizeof(SC_ROLE_USEITEM_START_ACK));
    Register(SCID_ROLE_USEITEM_END_ACK, &CCliProtoMsgDispatcher::OnSC_ROLE_USEITEM_END_ACK, sizeof(SC_ROLE_USEITEM_END_ACK));
    Register(SCID_USER_SKILLS_NTF, &CCliProtoMsgDispatcher::OnSC_USER_SKILLS_NTF, sizeof(SC_USER_SKILLS_NTF));
    Register(CSID_LEARN_SKILL, &CCliProtoMsgDispatcher::OnCS_LEARN_SKILL, sizeof(CS_LEARN_SKILL));
    Register(SCID_SKILL_INFO_NTF, &CCliProtoMsgDispatcher::OnSC_SKILL_INFO_NTF, sizeof(SC_SKILL_INFO_NTF));
    Register(SCID_REMOVE_SKILL_NTF, &CCliProtoMsgDispatcher::OnSC_REMOVE_SKILL_NTF, sizeof(SC_REMOVE_SKILL_NTF));
    Register(SCID_SKILL_POINT_NTF, &CCliProtoMsgDispatcher::OnSC_SKILL_POINT_NTF, sizeof(SC_SKILL_POINT_NTF));
    Register(CSID_SKILL_RESET_ALL_REQ, &CCliProtoMsgDispatcher::OnCS_SKILL_RESET_ALL_REQ, sizeof(CS_SKILL_RESET_ALL_REQ));
    Register(SCID_USER_PETS_NTF, &CCliProtoMsgDispatcher::OnSC_USER_PETS_NTF, sizeof(SC_USER_PETS_NTF));
    Register(SCID_PET_INFO_NTF, &CCliProtoMsgDispatcher::OnSC_PET_INFO_NTF, sizeof(SC_PET_INFO_NTF));
    Register(CSID_SET_BATTLE_PET_REQ, &CCliProtoMsgDispatcher::OnCS_SET_BATTLE_PET_REQ, sizeof(CS_SET_BATTLE_PET_REQ));
    Register(SCID_SET_BATTLE_PET_NTF, &CCliProtoMsgDispatcher::OnSC_SET_BATTLE_PET_NTF, sizeof(SC_SET_BATTLE_PET_NTF));
    Register(CSID_PET_GET_EXP_RPT, &CCliProtoMsgDispatcher::OnCS_PET_GET_EXP_RPT, sizeof(CS_PET_GET_EXP_RPT));
    Register(SCID_PET_LEVEL_NTF, &CCliProtoMsgDispatcher::OnSC_PET_LEVEL_NTF, sizeof(SC_PET_LEVEL_NTF));
    Register(CSID_PET_UP_REQ, &CCliProtoMsgDispatcher::OnCS_PET_UP_REQ, sizeof(CS_PET_UP_REQ));
    Register(SCID_PET_UP_ACK, &CCliProtoMsgDispatcher::OnSC_PET_UP_ACK, sizeof(SC_PET_UP_ACK));
    Register(CSID_PET_MERGE_REQ, &CCliProtoMsgDispatcher::OnCS_PET_MERGE_REQ, sizeof(CS_PET_MERGE_REQ));
    Register(SCID_PET_ADD_NTF, &CCliProtoMsgDispatcher::OnSC_PET_ADD_NTF, sizeof(SC_PET_ADD_NTF));
    Register(SCID_PETS_RECORD_NTF, &CCliProtoMsgDispatcher::OnSC_PETS_RECORD_NTF, sizeof(SC_PETS_RECORD_NTF));
    Register(SCID_PET_BAG_NTF, &CCliProtoMsgDispatcher::OnSC_PET_BAG_NTF, sizeof(SC_PET_BAG_NTF));
    Register(CSID_PET_EQUIP_REQ, &CCliProtoMsgDispatcher::OnCS_PET_EQUIP_REQ, sizeof(CS_PET_EQUIP_REQ));
    Register(CSID_PET_EVENT_REQ, &CCliProtoMsgDispatcher::OnCS_PET_EVENT_REQ, sizeof(CS_PET_EVENT_REQ));
    Register(SCID_PET_BAG_SINGLE_LEAVE_NTF, &CCliProtoMsgDispatcher::OnSC_PET_BAG_SINGLE_LEAVE_NTF, sizeof(SC_PET_BAG_SINGLE_LEAVE_NTF));
    Register(SCID_PET_BAG_SINGLE_ENTER_NTF, &CCliProtoMsgDispatcher::OnSC_PET_BAG_SINGLE_ENTER_NTF, sizeof(SC_PET_BAG_SINGLE_ENTER_NTF));
    Register(CSID_PET_TEAM_RPT, &CCliProtoMsgDispatcher::OnCS_PET_TEAM_RPT, sizeof(CS_PET_TEAM_RPT));
    Register(SCID_PET_TEAM_NTF, &CCliProtoMsgDispatcher::OnSC_PET_TEAM_NTF, sizeof(SC_PET_TEAM_NTF));
    Register(SCID_PET_GET_EXP_ACK, &CCliProtoMsgDispatcher::OnSC_PET_GET_EXP_ACK, sizeof(SC_PET_GET_EXP_ACK));
    Register(SCID_PET_SINGLE_ENTER_NTF, &CCliProtoMsgDispatcher::OnSC_PET_SINGLE_ENTER_NTF, sizeof(SC_PET_SINGLE_ENTER_NTF));
    Register(SCID_PET_SINGLE_LEAVE_NTF, &CCliProtoMsgDispatcher::OnSC_PET_SINGLE_LEAVE_NTF, sizeof(SC_PET_SINGLE_LEAVE_NTF));
    Register(SCID_PET_EVENT_ACK, &CCliProtoMsgDispatcher::OnSC_PET_EVENT_ACK, sizeof(SC_PET_EVENT_ACK));
    Register(CSID_MOVE_SYNC_MODE, &CCliProtoMsgDispatcher::OnCS_MOVE_SYNC_MODE, sizeof(CS_MOVE_SYNC_MODE));
    Register(CSID_MOVE_BEGIN, &CCliProtoMsgDispatcher::OnCS_MOVE_BEGIN, sizeof(CS_MOVE_BEGIN));
    Register(CSID_MOVE_STOP, &CCliProtoMsgDispatcher::OnCS_MOVE_STOP, sizeof(CS_MOVE_STOP));
    Register(SCID_MOVE_BEGIN, &CCliProtoMsgDispatcher::OnSC_MOVE_BEGIN, sizeof(SC_MOVE_BEGIN));
    Register(SCID_MOVE_STOP, &CCliProtoMsgDispatcher::OnSC_MOVE_STOP, sizeof(SC_MOVE_STOP));
    Register(SCID_OTHER_APPEAR, &CCliProtoMsgDispatcher::OnSC_OTHER_APPEAR, sizeof(SC_OTHER_APPEAR));
    Register(SCID_OTHER_UPDATE, &CCliProtoMsgDispatcher::OnSC_OTHER_UPDATE, sizeof(SC_OTHER_UPDATE));
    Register(SCID_OTHER_DISAPPEAR, &CCliProtoMsgDispatcher::OnSC_OTHER_DISAPPEAR, sizeof(SC_OTHER_DISAPPEAR));
    Register(CSID_CHAT, &CCliProtoMsgDispatcher::OnCS_CHAT, sizeof(CS_CHAT));
    Register(SCID_CHAT, &CCliProtoMsgDispatcher::OnSC_CHAT, sizeof(SC_CHAT));
    Register(SCID_CHAT_ACK, &CCliProtoMsgDispatcher::OnSC_CHAT_ACK, sizeof(SC_CHAT_ACK));
    Register(SCID_FRIENDS_LIST_NTF, &CCliProtoMsgDispatcher::OnSC_FRIENDS_LIST_NTF, sizeof(SC_FRIENDS_LIST_NTF));
    Register(CSID_QUERY_ROLE_REQ, &CCliProtoMsgDispatcher::OnCS_QUERY_ROLE_REQ, sizeof(CS_QUERY_ROLE_REQ));
    Register(SCID_QUERY_ROLE_ACK, &CCliProtoMsgDispatcher::OnSC_QUERY_ROLE_ACK, sizeof(SC_QUERY_ROLE_ACK));
    Register(CSID_ADD_FRIEND_REQ, &CCliProtoMsgDispatcher::OnCS_ADD_FRIEND_REQ, sizeof(CS_ADD_FRIEND_REQ));
    Register(SCID_ADD_FRIEND_ACK, &CCliProtoMsgDispatcher::OnSC_ADD_FRIEND_ACK, sizeof(SC_ADD_FRIEND_ACK));
    Register(CSID_REMOVE_FRIEND_REQ, &CCliProtoMsgDispatcher::OnCS_REMOVE_FRIEND_REQ, sizeof(CS_REMOVE_FRIEND_REQ));
    Register(SCID_REMOVE_FRIEND_ACK, &CCliProtoMsgDispatcher::OnSC_REMOVE_FRIEND_ACK, sizeof(SC_REMOVE_FRIEND_ACK));
    Register(CSID_DONATE_ACTION_POINT_REQ, &CCliProtoMsgDispatcher::OnCS_DONATE_ACTION_POINT_REQ, sizeof(CS_DONATE_ACTION_POINT_REQ));
    Register(SCID_DONATE_ACTION_POINT_ACK, &CCliProtoMsgDispatcher::OnSC_DONATE_ACTION_POINT_ACK, sizeof(SC_DONATE_ACTION_POINT_ACK));
    Register(SCID_DONATE_ACTION_POINT_OTHER_NTF, &CCliProtoMsgDispatcher::OnSC_DONATE_ACTION_POINT_OTHER_NTF, sizeof(SC_DONATE_ACTION_POINT_OTHER_NTF));
    Register(CSID_RECEIVE_ACTION_POINT_REQ, &CCliProtoMsgDispatcher::OnCS_RECEIVE_ACTION_POINT_REQ, sizeof(CS_RECEIVE_ACTION_POINT_REQ));
    Register(SCID_RECEIVE_ACTION_POINT_ACK, &CCliProtoMsgDispatcher::OnSC_RECEIVE_ACTION_POINT_ACK, sizeof(SC_RECEIVE_ACTION_POINT_ACK));
    Register(CSID_RESPONSE_ADD_FRIEND_REQ, &CCliProtoMsgDispatcher::OnCS_RESPONSE_ADD_FRIEND_REQ, sizeof(CS_RESPONSE_ADD_FRIEND_REQ));
    Register(SCID_REQUEST_ADD_FRIEND_NTF, &CCliProtoMsgDispatcher::OnSC_REQUEST_ADD_FRIEND_NTF, sizeof(SC_REQUEST_ADD_FRIEND_NTF));
    Register(SCID_FRIEND_INFO_CHANGE_NTF, &CCliProtoMsgDispatcher::OnSC_FRIEND_INFO_CHANGE_NTF, sizeof(SC_FRIEND_INFO_CHANGE_NTF));
    Register(SCID_FRIEND_REMOVE_INVITE_NTF, &CCliProtoMsgDispatcher::OnSC_FRIEND_REMOVE_INVITE_NTF, sizeof(SC_FRIEND_REMOVE_INVITE_NTF));
    Register(CSID_FRIEND_ASSIST_LIST_REQ, &CCliProtoMsgDispatcher::OnCS_FRIEND_ASSIST_LIST_REQ, sizeof(CS_FRIEND_ASSIST_LIST_REQ));
    Register(SCID_FRIEND_ASSIST_LIST_ACK, &CCliProtoMsgDispatcher::OnSC_FRIEND_ASSIST_LIST_ACK, sizeof(SC_FRIEND_ASSIST_LIST_ACK));
    Register(CSID_SELECT_FRIEND_ASSIST_REQ, &CCliProtoMsgDispatcher::OnCS_SELECT_FRIEND_ASSIST_REQ, sizeof(CS_SELECT_FRIEND_ASSIST_REQ));
    Register(SCID_SELECT_FRIEND_ASSIST_ACK, &CCliProtoMsgDispatcher::OnSC_SELECT_FRIEND_ASSIST_ACK, sizeof(SC_SELECT_FRIEND_ASSIST_ACK));
    Register(SCID_FRIEND_EPINFO_NTF, &CCliProtoMsgDispatcher::OnSC_FRIEND_EPINFO_NTF, sizeof(SC_FRIEND_EPINFO_NTF));
    Register(CSID_FRIENDS_LIST_REQ, &CCliProtoMsgDispatcher::OnCS_FRIENDS_LIST_REQ, sizeof(CS_FRIENDS_LIST_REQ));
    Register(SCID_ABYSS_TRIGGER_ACK, &CCliProtoMsgDispatcher::OnSC_ABYSS_TRIGGER_ACK, sizeof(SC_ABYSS_TRIGGER_ACK));
    Register(CSID_ABYSS_OPEN_REQ, &CCliProtoMsgDispatcher::OnCS_ABYSS_OPEN_REQ, sizeof(CS_ABYSS_OPEN_REQ));
    Register(SCID_ABYSS_OPEN_ACK, &CCliProtoMsgDispatcher::OnSC_ABYSS_OPEN_ACK, sizeof(SC_ABYSS_OPEN_ACK));
    Register(SCID_ABYSS_OPEN_NTF, &CCliProtoMsgDispatcher::OnSC_ABYSS_OPEN_NTF, sizeof(SC_ABYSS_OPEN_NTF));
    Register(CSID_GET_ABYSS_TRIGGER_LIST_REQ, &CCliProtoMsgDispatcher::OnCS_GET_ABYSS_TRIGGER_LIST_REQ, sizeof(CS_GET_ABYSS_TRIGGER_LIST_REQ));
    Register(SCID_GET_ABYSS_TRIGGER_LIST_ACK, &CCliProtoMsgDispatcher::OnSC_GET_ABYSS_TRIGGER_LIST_ACK, sizeof(SC_GET_ABYSS_TRIGGER_LIST_ACK));
    Register(CSID_GET_ABYSS_OPEN_LIST_REQ, &CCliProtoMsgDispatcher::OnCS_GET_ABYSS_OPEN_LIST_REQ, sizeof(CS_GET_ABYSS_OPEN_LIST_REQ));
    Register(SCID_GET_ABYSS_OPEN_LIST_ACK, &CCliProtoMsgDispatcher::OnSC_GET_ABYSS_OPEN_LIST_ACK, sizeof(SC_GET_ABYSS_OPEN_LIST_ACK));
    Register(CSID_GET_ABYSS_OPEN_REC_REQ, &CCliProtoMsgDispatcher::OnCS_GET_ABYSS_OPEN_REC_REQ, sizeof(CS_GET_ABYSS_OPEN_REC_REQ));
    Register(SCID_GET_ABYSS_OPEN_REC_ACK, &CCliProtoMsgDispatcher::OnSC_GET_ABYSS_OPEN_REC_ACK, sizeof(SC_GET_ABYSS_OPEN_REC_ACK));
    Register(SCID_ENTER_ABYSS_ACK, &CCliProtoMsgDispatcher::OnSC_ENTER_ABYSS_ACK, sizeof(SC_ENTER_ABYSS_ACK));
    Register(SCID_ABYSS_RUN_NTF, &CCliProtoMsgDispatcher::OnSC_ABYSS_RUN_NTF, sizeof(SC_ABYSS_RUN_NTF));
    Register(SCID_MAIL_LIST_NTF, &CCliProtoMsgDispatcher::OnSC_MAIL_LIST_NTF, sizeof(SC_MAIL_LIST_NTF));
    Register(CSID_SEND_MAIL_REQ, &CCliProtoMsgDispatcher::OnCS_SEND_MAIL_REQ, sizeof(CS_SEND_MAIL_REQ));
    Register(SCID_SEND_MAIL_ACK, &CCliProtoMsgDispatcher::OnSC_SEND_MAIL_ACK, sizeof(SC_SEND_MAIL_ACK));
    Register(CSID_GET_ITEM_FROM_MAIL_REQ, &CCliProtoMsgDispatcher::OnCS_GET_ITEM_FROM_MAIL_REQ, sizeof(CS_GET_ITEM_FROM_MAIL_REQ));
    Register(CSID_GET_MONEY_FROM_MAIL_REQ, &CCliProtoMsgDispatcher::OnCS_GET_MONEY_FROM_MAIL_REQ, sizeof(CS_GET_MONEY_FROM_MAIL_REQ));
    Register(CSID_READ_MAIL_REQ, &CCliProtoMsgDispatcher::OnCS_READ_MAIL_REQ, sizeof(CS_READ_MAIL_REQ));
    Register(SCID_READ_MAIL_ACK, &CCliProtoMsgDispatcher::OnSC_READ_MAIL_ACK, sizeof(SC_READ_MAIL_ACK));
    Register(CSID_DELETE_MAIL_REQ, &CCliProtoMsgDispatcher::OnCS_DELETE_MAIL_REQ, sizeof(CS_DELETE_MAIL_REQ));
    Register(SCID_DELETE_MAIL_ACK, &CCliProtoMsgDispatcher::OnSC_DELETE_MAIL_ACK, sizeof(SC_DELETE_MAIL_ACK));
    Register(SCID_UPDATE_MAIL_NTF, &CCliProtoMsgDispatcher::OnSC_UPDATE_MAIL_NTF, sizeof(SC_UPDATE_MAIL_NTF));
    Register(SCID_SHOP_ACTION_POINT_BOUGHT_NTF, &CCliProtoMsgDispatcher::OnSC_SHOP_ACTION_POINT_BOUGHT_NTF, sizeof(SC_SHOP_ACTION_POINT_BOUGHT_NTF));
    Register(CSID_SHOP_BUY_ACTION_POINT_REQ, &CCliProtoMsgDispatcher::OnCS_SHOP_BUY_ACTION_POINT_REQ, sizeof(CS_SHOP_BUY_ACTION_POINT_REQ));
    Register(SCID_SHOP_BUY_ACTION_POINT_ACK, &CCliProtoMsgDispatcher::OnSC_SHOP_BUY_ACTION_POINT_ACK, sizeof(SC_SHOP_BUY_ACTION_POINT_ACK));
    Register(SCID_SHOP_BUY_PET_INFO_CHEAP_NTF, &CCliProtoMsgDispatcher::OnSC_SHOP_BUY_PET_INFO_CHEAP_NTF, sizeof(SC_SHOP_BUY_PET_INFO_CHEAP_NTF));
    Register(SCID_SHOP_BUY_PET_INFO_EXPENSIVE_NTF, &CCliProtoMsgDispatcher::OnSC_SHOP_BUY_PET_INFO_EXPENSIVE_NTF, sizeof(SC_SHOP_BUY_PET_INFO_EXPENSIVE_NTF));
    Register(CSID_SHOP_BUY_PET_REQ, &CCliProtoMsgDispatcher::OnCS_SHOP_BUY_PET_REQ, sizeof(CS_SHOP_BUY_PET_REQ));
    Register(SCID_SHOP_BUY_PET_ACK, &CCliProtoMsgDispatcher::OnSC_SHOP_BUY_PET_ACK, sizeof(SC_SHOP_BUY_PET_ACK));
    Register(CSID_SHOP_GET_GOODSLIST_REQ, &CCliProtoMsgDispatcher::OnCS_SHOP_GET_GOODSLIST_REQ, sizeof(CS_SHOP_GET_GOODSLIST_REQ));
    Register(SCID_SHOP_GET_GOODSLIST_ACK, &CCliProtoMsgDispatcher::OnSC_SHOP_GET_GOODSLIST_ACK, sizeof(SC_SHOP_GET_GOODSLIST_ACK));
    Register(CSID_SHOP_BUY_GOODS_REQ, &CCliProtoMsgDispatcher::OnCS_SHOP_BUY_GOODS_REQ, sizeof(CS_SHOP_BUY_GOODS_REQ));
    Register(SCID_SHOP_BUY_GOODS_ACK, &CCliProtoMsgDispatcher::OnSC_SHOP_BUY_GOODS_ACK, sizeof(SC_SHOP_BUY_GOODS_ACK));
    Register(CSID_SHOP_SECRET_GOODS_REQ, &CCliProtoMsgDispatcher::OnCS_SHOP_SECRET_GOODS_REQ, sizeof(CS_SHOP_SECRET_GOODS_REQ));
    Register(SCID_SHOP_SECRET_GOODS_ACK, &CCliProtoMsgDispatcher::OnSC_SHOP_SECRET_GOODS_ACK, sizeof(SC_SHOP_SECRET_GOODS_ACK));
    Register(CSID_SHOP_SECRET_BUY_REQ, &CCliProtoMsgDispatcher::OnCS_SHOP_SECRET_BUY_REQ, sizeof(CS_SHOP_SECRET_BUY_REQ));
    Register(SCID_SHOP_SECRET_BUY_ACK, &CCliProtoMsgDispatcher::OnSC_SHOP_SECRET_BUY_ACK, sizeof(SC_SHOP_SECRET_BUY_ACK));
    Register(CSID_SHOP_SECRET_REFRESH_REQ, &CCliProtoMsgDispatcher::OnCS_SHOP_SECRET_REFRESH_REQ, sizeof(CS_SHOP_SECRET_REFRESH_REQ));
    Register(CSID_SELF_PVP_PRO_REQ, &CCliProtoMsgDispatcher::OnCS_SELF_PVP_PRO_REQ, sizeof(CS_SELF_PVP_PRO_REQ));
    Register(SCID_SELF_PVP_PRO_ACK, &CCliProtoMsgDispatcher::OnSC_SELF_PVP_PRO_ACK, sizeof(SC_SELF_PVP_PRO_ACK));
    Register(CSID_GET_PVP_MATCH_REQ, &CCliProtoMsgDispatcher::OnCS_GET_PVP_MATCH_REQ, sizeof(CS_GET_PVP_MATCH_REQ));
    Register(SCID_GET_PVP_MATCH_ACK, &CCliProtoMsgDispatcher::OnSC_GET_PVP_MATCH_ACK, sizeof(SC_GET_PVP_MATCH_ACK));
    Register(CSID_ENTER_PVP_REQ, &CCliProtoMsgDispatcher::OnCS_ENTER_PVP_REQ, sizeof(CS_ENTER_PVP_REQ));
    Register(SCID_ENTER_PVP_ACK, &CCliProtoMsgDispatcher::OnSC_ENTER_PVP_ACK, sizeof(SC_ENTER_PVP_ACK));
    Register(CSID_PVP_RETULT_REQ, &CCliProtoMsgDispatcher::OnCS_PVP_RETULT_REQ, sizeof(CS_PVP_RETULT_REQ));
    Register(SCID_PVP_RETULT_ACK, &CCliProtoMsgDispatcher::OnSC_PVP_RETULT_ACK, sizeof(SC_PVP_RETULT_ACK));
    Register(CSID_GET_RANK_LIST_REQ, &CCliProtoMsgDispatcher::OnCS_GET_RANK_LIST_REQ, sizeof(CS_GET_RANK_LIST_REQ));
    Register(SCID_GET_RANK_LIST_ACK, &CCliProtoMsgDispatcher::OnSC_GET_RANK_LIST_ACK, sizeof(SC_GET_RANK_LIST_ACK));
    Register(CSID_GET_PVP_MILITARY_REWARD_REQ, &CCliProtoMsgDispatcher::OnCS_GET_PVP_MILITARY_REWARD_REQ, sizeof(CS_GET_PVP_MILITARY_REWARD_REQ));
    Register(SCID_GET_PVP_MILITARY_REWARD_ACK, &CCliProtoMsgDispatcher::OnSC_GET_PVP_MILITARY_REWARD_ACK, sizeof(SC_GET_PVP_MILITARY_REWARD_ACK));
    Register(CSID_GET_PVP_REPUTE_REWARD_REQ, &CCliProtoMsgDispatcher::OnCS_GET_PVP_REPUTE_REWARD_REQ, sizeof(CS_GET_PVP_REPUTE_REWARD_REQ));
    Register(SCID_GET_PVP_REPUTE_REWARD_ACK, &CCliProtoMsgDispatcher::OnSC_GET_PVP_REPUTE_REWARD_ACK, sizeof(SC_GET_PVP_REPUTE_REWARD_ACK));
    Register(CSID_PVP_BUY_CHALLENGE_TIMES_REQ, &CCliProtoMsgDispatcher::OnCS_PVP_BUY_CHALLENGE_TIMES_REQ, sizeof(CS_PVP_BUY_CHALLENGE_TIMES_REQ));
    Register(SCID_PVP_BUY_CHALLENGE_TIMES_ACK, &CCliProtoMsgDispatcher::OnSC_PVP_BUY_CHALLENGE_TIMES_ACK, sizeof(SC_PVP_BUY_CHALLENGE_TIMES_ACK));
    Register(SCID_PVP_TIME_NTF, &CCliProtoMsgDispatcher::OnSC_PVP_TIME_NTF, sizeof(SC_PVP_TIME_NTF));
    Register(CSID_GET_PVP_ROLE_INFO_REQ, &CCliProtoMsgDispatcher::OnCS_GET_PVP_ROLE_INFO_REQ, sizeof(CS_GET_PVP_ROLE_INFO_REQ));
    Register(SCID_GET_PVP_ROLE_INFO_ACK, &CCliProtoMsgDispatcher::OnSC_GET_PVP_ROLE_INFO_ACK, sizeof(SC_GET_PVP_ROLE_INFO_ACK));
    Register(SCID_VIP_INFO_NTF, &CCliProtoMsgDispatcher::OnSC_VIP_INFO_NTF, sizeof(SC_VIP_INFO_NTF));
    Register(SCID_VIP_RMBINFO_NTF, &CCliProtoMsgDispatcher::OnSC_VIP_RMBINFO_NTF, sizeof(SC_VIP_RMBINFO_NTF));
    Register(SCID_VIP_MONTHCARD_NTF, &CCliProtoMsgDispatcher::OnSC_VIP_MONTHCARD_NTF, sizeof(SC_VIP_MONTHCARD_NTF));
    Register(CSID_VIP_MONTHCARD_GETITEM_REQ, &CCliProtoMsgDispatcher::OnCS_VIP_MONTHCARD_GETITEM_REQ, sizeof(CS_VIP_MONTHCARD_GETITEM_REQ));
    Register(SCID_VIP_MONTHCARD_GETITEM_ACK, &CCliProtoMsgDispatcher::OnSC_VIP_MONTHCARD_GETITEM_ACK, sizeof(SC_VIP_MONTHCARD_GETITEM_ACK));
    Register(SCID_GIFT_SIGN_NTF, &CCliProtoMsgDispatcher::OnSC_GIFT_SIGN_NTF, sizeof(SC_GIFT_SIGN_NTF));
    Register(SCID_GIFT_SIGN_VIP_NTF, &CCliProtoMsgDispatcher::OnSC_GIFT_SIGN_VIP_NTF, sizeof(SC_GIFT_SIGN_VIP_NTF));
    Register(CSID_GIFT_SIGN, &CCliProtoMsgDispatcher::OnCS_GIFT_SIGN, sizeof(CS_GIFT_SIGN));
    Register(CSID_GIFT_SIGN_VIP, &CCliProtoMsgDispatcher::OnCS_GIFT_SIGN_VIP, sizeof(CS_GIFT_SIGN_VIP));
    Register(SCID_GIFT_LEVEL_NTF, &CCliProtoMsgDispatcher::OnSC_GIFT_LEVEL_NTF, sizeof(SC_GIFT_LEVEL_NTF));
    Register(CSID_GIFT_LEVEL, &CCliProtoMsgDispatcher::OnCS_GIFT_LEVEL, sizeof(CS_GIFT_LEVEL));
    Register(SCID_GIFT_DAY_NTF, &CCliProtoMsgDispatcher::OnSC_GIFT_DAY_NTF, sizeof(SC_GIFT_DAY_NTF));
    Register(SCID_GIFT_DAY_UPD, &CCliProtoMsgDispatcher::OnSC_GIFT_DAY_UPD, sizeof(SC_GIFT_DAY_UPD));
    Register(CSID_GIFT_DAY_SCORE_REQ, &CCliProtoMsgDispatcher::OnCS_GIFT_DAY_SCORE_REQ, sizeof(CS_GIFT_DAY_SCORE_REQ));
    Register(CSID_GIFT_DAY_BOX_REQ, &CCliProtoMsgDispatcher::OnCS_GIFT_DAY_BOX_REQ, sizeof(CS_GIFT_DAY_BOX_REQ));
    Register(SCID_GIFT_DAY_BOX_NTF, &CCliProtoMsgDispatcher::OnSC_GIFT_DAY_BOX_NTF, sizeof(SC_GIFT_DAY_BOX_NTF));
    Register(CSID_GIFT_JIHUOMA_REQ, &CCliProtoMsgDispatcher::OnCS_GIFT_JIHUOMA_REQ, sizeof(CS_GIFT_JIHUOMA_REQ));
    Register(SCID_GIFT_JIHUOMA_ACK, &CCliProtoMsgDispatcher::OnSC_GIFT_JIHUOMA_ACK, sizeof(SC_GIFT_JIHUOMA_ACK));
    Register(CSID_GIFT_EP_INFO_REQ, &CCliProtoMsgDispatcher::OnCS_GIFT_EP_INFO_REQ, sizeof(CS_GIFT_EP_INFO_REQ));
    Register(SCID_GIFT_EP_INFO_ACK, &CCliProtoMsgDispatcher::OnSC_GIFT_EP_INFO_ACK, sizeof(SC_GIFT_EP_INFO_ACK));
    Register(CSID_GIFT_RECEIVE_EP_REQ, &CCliProtoMsgDispatcher::OnCS_GIFT_RECEIVE_EP_REQ, sizeof(CS_GIFT_RECEIVE_EP_REQ));
    Register(SCID_GIFT_RECEIVE_EP_ACK, &CCliProtoMsgDispatcher::OnSC_GIFT_RECEIVE_EP_ACK, sizeof(SC_GIFT_RECEIVE_EP_ACK));
    Register(CSID_WB_INFO_REFRESH_REQ, &CCliProtoMsgDispatcher::OnCS_WB_INFO_REFRESH_REQ, sizeof(CS_WB_INFO_REFRESH_REQ));
    Register(SCID_WB_INFO_REFRESH_ACK, &CCliProtoMsgDispatcher::OnSC_WB_INFO_REFRESH_ACK, sizeof(SC_WB_INFO_REFRESH_ACK));
    Register(CSID_WB_ADD_BUF_REQ, &CCliProtoMsgDispatcher::OnCS_WB_ADD_BUF_REQ, sizeof(CS_WB_ADD_BUF_REQ));
    Register(SCID_WB_ADD_BUF_ACK, &CCliProtoMsgDispatcher::OnSC_WB_ADD_BUF_ACK, sizeof(SC_WB_ADD_BUF_ACK));
    Register(CSID_WB_RELIVE_REQ, &CCliProtoMsgDispatcher::OnCS_WB_RELIVE_REQ, sizeof(CS_WB_RELIVE_REQ));
    Register(SCID_WB_RELIVE_ACK, &CCliProtoMsgDispatcher::OnSC_WB_RELIVE_ACK, sizeof(SC_WB_RELIVE_ACK));
    Register(SCID_WB_KILLED_NTF, &CCliProtoMsgDispatcher::OnSC_WB_KILLED_NTF, sizeof(SC_WB_KILLED_NTF));
    Register(SCID_WB_RUN_NTF, &CCliProtoMsgDispatcher::OnSC_WB_RUN_NTF, sizeof(SC_WB_RUN_NTF));
    Register(CSID_WB_ENTER_REQ, &CCliProtoMsgDispatcher::OnCS_WB_ENTER_REQ, sizeof(CS_WB_ENTER_REQ));
    Register(SCID_WB_ENTER_ACK, &CCliProtoMsgDispatcher::OnSC_WB_ENTER_ACK, sizeof(SC_WB_ENTER_ACK));
    Register(CSID_WB_RESULT_REQ, &CCliProtoMsgDispatcher::OnCS_WB_RESULT_REQ, sizeof(CS_WB_RESULT_REQ));
    Register(SCID_WB_RESULT_ACK, &CCliProtoMsgDispatcher::OnSC_WB_RESULT_ACK, sizeof(SC_WB_RESULT_ACK));
    Register(CSID_ROLE_RANK_REQ, &CCliProtoMsgDispatcher::OnCS_ROLE_RANK_REQ, sizeof(CS_ROLE_RANK_REQ));
    Register(SCID_ROLE_RANK_ACK, &CCliProtoMsgDispatcher::OnSC_ROLE_RANK_ACK, sizeof(SC_ROLE_RANK_ACK));
    Register(CSID_GET_PT_BASEINFO_REQ, &CCliProtoMsgDispatcher::OnCS_GET_PT_BASEINFO_REQ, sizeof(CS_GET_PT_BASEINFO_REQ));
    Register(SCID_GET_PT_BASEINFO_ACK, &CCliProtoMsgDispatcher::OnSC_GET_PT_BASEINFO_ACK, sizeof(SC_GET_PT_BASEINFO_ACK));
    Register(CSID_BUY_PT_TIMES_REQ, &CCliProtoMsgDispatcher::OnCS_BUY_PT_TIMES_REQ, sizeof(CS_BUY_PT_TIMES_REQ));
    Register(SCID_BUY_PT_TIMES_ACK, &CCliProtoMsgDispatcher::OnSC_BUY_PT_TIMES_ACK, sizeof(SC_BUY_PT_TIMES_ACK));
    Register(CSID_GET_MD_BASEINFO_REQ, &CCliProtoMsgDispatcher::OnCS_GET_MD_BASEINFO_REQ, sizeof(CS_GET_MD_BASEINFO_REQ));
    Register(SCID_GET_MD_BASEINFO_ACK, &CCliProtoMsgDispatcher::OnSC_GET_MD_BASEINFO_ACK, sizeof(SC_GET_MD_BASEINFO_ACK));
    Register(CSID_BUY_MD_TIMES_REQ, &CCliProtoMsgDispatcher::OnCS_BUY_MD_TIMES_REQ, sizeof(CS_BUY_MD_TIMES_REQ));
    Register(SCID_BUY_MD_TIMES_ACK, &CCliProtoMsgDispatcher::OnSC_BUY_MD_TIMES_ACK, sizeof(SC_BUY_MD_TIMES_ACK));
    Register(CSID_GET_FD_BASEINFO_REQ, &CCliProtoMsgDispatcher::OnCS_GET_FD_BASEINFO_REQ, sizeof(CS_GET_FD_BASEINFO_REQ));
    Register(SCID_GET_FD_BASEINFO_ACK, &CCliProtoMsgDispatcher::OnSC_GET_FD_BASEINFO_ACK, sizeof(SC_GET_FD_BASEINFO_ACK));
    Register(CSID_BUY_FD_TIMES_REQ, &CCliProtoMsgDispatcher::OnCS_BUY_FD_TIMES_REQ, sizeof(CS_BUY_FD_TIMES_REQ));
    Register(SCID_BUY_FD_TIMES_ACK, &CCliProtoMsgDispatcher::OnSC_BUY_FD_TIMES_ACK, sizeof(SC_BUY_FD_TIMES_ACK));
    Register(CSID_GUILD_INFO_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_INFO_REQ, sizeof(CS_GUILD_INFO_REQ));
    Register(CSID_GUILD_LIST_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_LIST_REQ, sizeof(CS_GUILD_LIST_REQ));
    Register(SCID_GUILD_LIST_ACK, &CCliProtoMsgDispatcher::OnSC_GUILD_LIST_ACK, sizeof(SC_GUILD_LIST_ACK));
    Register(CSID_GUILD_ENTER_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_ENTER_REQ, sizeof(CS_GUILD_ENTER_REQ));
    Register(SCID_GUILD_ENTER_ACK, &CCliProtoMsgDispatcher::OnSC_GUILD_ENTER_ACK, sizeof(SC_GUILD_ENTER_ACK));
    Register(CSID_GUILD_CREATE_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_CREATE_REQ, sizeof(CS_GUILD_CREATE_REQ));
    Register(SCID_GUILD_CREATE_ACK, &CCliProtoMsgDispatcher::OnSC_GUILD_CREATE_ACK, sizeof(SC_GUILD_CREATE_ACK));
    Register(CSID_GUILD_LEAVE_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_LEAVE_REQ, sizeof(CS_GUILD_LEAVE_REQ));
    Register(SCID_GUILD_LEAVE_ACK, &CCliProtoMsgDispatcher::OnSC_GUILD_LEAVE_ACK, sizeof(SC_GUILD_LEAVE_ACK));
    Register(SCID_GUILD_BASEINFO_ACK, &CCliProtoMsgDispatcher::OnSC_GUILD_BASEINFO_ACK, sizeof(SC_GUILD_BASEINFO_ACK));
    Register(CSID_GUILD_LOG_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_LOG_REQ, sizeof(CS_GUILD_LOG_REQ));
    Register(SCID_GUILD_LOG_ACK, &CCliProtoMsgDispatcher::OnSC_GUILD_LOG_ACK, sizeof(SC_GUILD_LOG_ACK));
    Register(CSID_GUILD_CHANGE_NOTICE_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_CHANGE_NOTICE_REQ, sizeof(CS_GUILD_CHANGE_NOTICE_REQ));
    Register(CSID_GUILD_DETAIL_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_DETAIL_REQ, sizeof(CS_GUILD_DETAIL_REQ));
    Register(SCID_GUILD_DETAIL_ACK, &CCliProtoMsgDispatcher::OnSC_GUILD_DETAIL_ACK, sizeof(SC_GUILD_DETAIL_ACK));
    Register(CSID_GUILD_ENTERLIST_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_ENTERLIST_REQ, sizeof(CS_GUILD_ENTERLIST_REQ));
    Register(SCID_GUILD_ENTERLIST_ACK, &CCliProtoMsgDispatcher::OnSC_GUILD_ENTERLIST_ACK, sizeof(SC_GUILD_ENTERLIST_ACK));
    Register(CSID_GUILD_ENTER_ACCEPT_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_ENTER_ACCEPT_REQ, sizeof(CS_GUILD_ENTER_ACCEPT_REQ));
    Register(SCID_GUILD_ENTER_ACCEPT_ACK, &CCliProtoMsgDispatcher::OnSC_GUILD_ENTER_ACCEPT_ACK, sizeof(SC_GUILD_ENTER_ACCEPT_ACK));
    Register(CSID_GUILD_ENTER_CLEAR_REQ, &CCliProtoMsgDispatcher::OnCS_GUILD_ENTER_CLEAR_REQ, sizeof(CS_GUILD_ENTER_CLEAR_REQ));
    Register(SCID_GUILD_ENTER_CLEAR_ACK, &CCliProtoMsgDispatcher::OnSC_GUILD_ENTER_CLEAR_ACK, sizeof(SC_GUILD_ENTER_CLEAR_ACK));
    return true;
}

bool CCliProtoMsgDispatcher::OnCG_LOGIN(const void* pBuf, int nLen, const void* pObject)
{
    CG_LOGIN* pData = (CG_LOGIN*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_LOGIN(const void* pBuf, int nLen, const void* pObject)
{
    GC_LOGIN* pData = (GC_LOGIN*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCG_LOGOUT(const void* pBuf, int nLen, const void* pObject)
{
    CG_LOGOUT* pData = (CG_LOGOUT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_LOGOUT(const void* pBuf, int nLen, const void* pObject)
{
    GC_LOGOUT* pData = (GC_LOGOUT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_ROLELIST(const void* pBuf, int nLen, const void* pObject)
{
    GC_ROLELIST* pData = (GC_ROLELIST*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCG_CREATEROLE(const void* pBuf, int nLen, const void* pObject)
{
    CG_CREATEROLE* pData = (CG_CREATEROLE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_CREATEROLE(const void* pBuf, int nLen, const void* pObject)
{
    GC_CREATEROLE* pData = (GC_CREATEROLE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCG_DELROLE(const void* pBuf, int nLen, const void* pObject)
{
    CG_DELROLE* pData = (CG_DELROLE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_DELROLE(const void* pBuf, int nLen, const void* pObject)
{
    GC_DELROLE* pData = (GC_DELROLE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCG_SELECTROLE(const void* pBuf, int nLen, const void* pObject)
{
    CG_SELECTROLE* pData = (CG_SELECTROLE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_SELECTROLE(const void* pBuf, int nLen, const void* pObject)
{
    GC_SELECTROLE* pData = (GC_SELECTROLE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_QUEUE_INFO(const void* pBuf, int nLen, const void* pObject)
{
    GC_QUEUE_INFO* pData = (GC_QUEUE_INFO*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_GPK_CLT_DYN_CODE(const void* pBuf, int nLen, const void* pObject)
{
    GC_GPK_CLT_DYN_CODE* pData = (GC_GPK_CLT_DYN_CODE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCG_GPK_CLT_NEGLECT(const void* pBuf, int nLen, const void* pObject)
{
    CG_GPK_CLT_NEGLECT* pData = (CG_GPK_CLT_NEGLECT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_GPK_CAL_ORIGIN(const void* pBuf, int nLen, const void* pObject)
{
    GC_GPK_CAL_ORIGIN* pData = (GC_GPK_CAL_ORIGIN*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCG_GPK_CAL_RESULT(const void* pBuf, int nLen, const void* pObject)
{
    CG_GPK_CAL_RESULT* pData = (CG_GPK_CAL_RESULT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_ERROR(const void* pBuf, int nLen, const void* pObject)
{
    GC_ERROR* pData = (GC_ERROR*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_ERRORSTRING(const void* pBuf, int nLen, const void* pObject)
{
    GC_ERRORSTRING* pData = (GC_ERRORSTRING*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCG_HEART_BEAT(const void* pBuf, int nLen, const void* pObject)
{
    CG_HEART_BEAT* pData = (CG_HEART_BEAT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_HEART_BEAT(const void* pBuf, int nLen, const void* pObject)
{
    GC_HEART_BEAT* pData = (GC_HEART_BEAT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGC_PUBLIC_STRING(const void* pBuf, int nLen, const void* pObject)
{
    GC_PUBLIC_STRING* pData = (GC_PUBLIC_STRING*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnLGPKG_LOGIN_REQ(const void* pBuf, int nLen, const void* pObject)
{
    LGPKG_LOGIN_REQ* pData = (LGPKG_LOGIN_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnLGPKG_LOGIN_ACK(const void* pBuf, int nLen, const void* pObject)
{
    LGPKG_LOGIN_ACK* pData = (LGPKG_LOGIN_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnLGPKG_GAMESERVER_LIST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    LGPKG_GAMESERVER_LIST_REQ* pData = (LGPKG_GAMESERVER_LIST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnLGPKG_GAMESERVER_LIST_ACK(const void* pBuf, int nLen, const void* pObject)
{
    LGPKG_GAMESERVER_LIST_ACK* pData = (LGPKG_GAMESERVER_LIST_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_SERVERINFO_RPT(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_SERVERINFO_RPT* pData = (GSPKG_SERVERINFO_RPT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_SERVER_GROUP_DESC_RPT(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_SERVER_GROUP_DESC_RPT* pData = (GSPKG_SERVER_GROUP_DESC_RPT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_ENTERGAME_REQ(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_ENTERGAME_REQ* pData = (GSPKG_ENTERGAME_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_ENTERGAME_ACK(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_ENTERGAME_ACK* pData = (GSPKG_ENTERGAME_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_LEAVEGAME_REQ(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_LEAVEGAME_REQ* pData = (GSPKG_LEAVEGAME_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_LEAVEGAME_ACK(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_LEAVEGAME_ACK* pData = (GSPKG_LEAVEGAME_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_KICKOUT_NTF(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_KICKOUT_NTF* pData = (GSPKG_KICKOUT_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_MSG_BROADCAST(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_MSG_BROADCAST* pData = (GSPKG_MSG_BROADCAST*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_LOAD_GSDATA_NTF(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_LOAD_GSDATA_NTF* pData = (GSPKG_LOAD_GSDATA_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_UPDATEGMLEVEL_NTF(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_UPDATEGMLEVEL_NTF* pData = (GSPKG_UPDATEGMLEVEL_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_SWITCHSCENE_REQ(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_SWITCHSCENE_REQ* pData = (GSPKG_SWITCHSCENE_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnGSPKG_SWITCHSCENE_ACK(const void* pBuf, int nLen, const void* pObject)
{
    GSPKG_SWITCHSCENE_ACK* pData = (GSPKG_SWITCHSCENE_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SELF_LOADSCENE(const void* pBuf, int nLen, const void* pObject)
{
    SC_SELF_LOADSCENE* pData = (SC_SELF_LOADSCENE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ENTERSCENE(const void* pBuf, int nLen, const void* pObject)
{
    CS_ENTERSCENE* pData = (CS_ENTERSCENE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SELF_ENTERSCENE(const void* pBuf, int nLen, const void* pObject)
{
    SC_SELF_ENTERSCENE* pData = (SC_SELF_ENTERSCENE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SELF_DATA_END(const void* pBuf, int nLen, const void* pObject)
{
    SC_SELF_DATA_END* pData = (SC_SELF_DATA_END*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SELF_APPEAR(const void* pBuf, int nLen, const void* pObject)
{
    SC_SELF_APPEAR* pData = (SC_SELF_APPEAR*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SELF_BASE_PRO(const void* pBuf, int nLen, const void* pObject)
{
    SC_SELF_BASE_PRO* pData = (SC_SELF_BASE_PRO*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_LEVEL_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_LEVEL_REQ* pData = (CS_LEVEL_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_LEVEL_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_LEVEL_ACK* pData = (SC_LEVEL_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_LEVEL_RESULT_NTF(const void* pBuf, int nLen, const void* pObject)
{
    CS_LEVEL_RESULT_NTF* pData = (CS_LEVEL_RESULT_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_TREASURE_CHEST_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_TREASURE_CHEST_NTF* pData = (SC_TREASURE_CHEST_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_OPEN_TREASURE_CHEST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_OPEN_TREASURE_CHEST_REQ* pData = (CS_OPEN_TREASURE_CHEST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_OPEN_TREASURE_CHEST_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_OPEN_TREASURE_CHEST_ACK* pData = (SC_OPEN_TREASURE_CHEST_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_LEVEL_INFO(const void* pBuf, int nLen, const void* pObject)
{
    SC_LEVEL_INFO* pData = (SC_LEVEL_INFO*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_BATTLE_BOX_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_BATTLE_BOX_REQ* pData = (CS_GET_BATTLE_BOX_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_BATTLE_BOX_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_BATTLE_BOX_ACK* pData = (SC_GET_BATTLE_BOX_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_BATTLE_GOT_STAR_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_BATTLE_GOT_STAR_NTF* pData = (SC_BATTLE_GOT_STAR_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SELF_VOLATILE_PRO(const void* pBuf, int nLen, const void* pObject)
{
    SC_SELF_VOLATILE_PRO* pData = (SC_SELF_VOLATILE_PRO*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_CLIENT_CONFIG_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_CLIENT_CONFIG_NTF* pData = (SC_CLIENT_CONFIG_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_CLIENT_CONFIG_UPDATE(const void* pBuf, int nLen, const void* pObject)
{
    CS_CLIENT_CONFIG_UPDATE* pData = (CS_CLIENT_CONFIG_UPDATE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ERROR_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ERROR_NTF* pData = (SC_ERROR_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SELF_ITEM_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_SELF_ITEM_NTF* pData = (SC_SELF_ITEM_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_MOVE_ITEM_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_MOVE_ITEM_REQ* pData = (CS_MOVE_ITEM_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_MOVE_ITEM_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_MOVE_ITEM_ACK* pData = (SC_MOVE_ITEM_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_BAG_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_BAG_NTF* pData = (SC_ROLE_BAG_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_EQUIP_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_EQUIP_NTF* pData = (SC_ROLE_EQUIP_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_EQUIP_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_EQUIP_REQ* pData = (CS_ROLE_EQUIP_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_EVENT_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_EVENT_REQ* pData = (CS_ROLE_EVENT_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_BAG_SINGLE_LEAVE_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_BAG_SINGLE_LEAVE_NTF* pData = (SC_ROLE_BAG_SINGLE_LEAVE_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_BAG_SINGLE_ENTER_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_BAG_SINGLE_ENTER_NTF* pData = (SC_ROLE_BAG_SINGLE_ENTER_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_EQUIP_SINGLE_LEAVE_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_EQUIP_SINGLE_LEAVE_NTF* pData = (SC_ROLE_EQUIP_SINGLE_LEAVE_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_EQUIP_SINGLE_ENTER_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_EQUIP_SINGLE_ENTER_NTF* pData = (SC_ROLE_EQUIP_SINGLE_ENTER_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_ITEMUP_RPT(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_ITEMUP_RPT* pData = (CS_ROLE_ITEMUP_RPT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_ITEMUP_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_ITEMUP_NTF* pData = (SC_ROLE_ITEMUP_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_ITEMUP_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_ITEMUP_ACK* pData = (SC_ROLE_ITEMUP_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_SUIT_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_SUIT_NTF* pData = (SC_ROLE_SUIT_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_HOLE_ON_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_HOLE_ON_REQ* pData = (CS_ROLE_HOLE_ON_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_HOLE_ON_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_HOLE_ON_ACK* pData = (SC_ROLE_HOLE_ON_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_HOLE_OFF_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_HOLE_OFF_REQ* pData = (CS_ROLE_HOLE_OFF_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_HOLE_OFF_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_HOLE_OFF_ACK* pData = (SC_ROLE_HOLE_OFF_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_HOLE_REFRESH_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_HOLE_REFRESH_REQ* pData = (CS_ROLE_HOLE_REFRESH_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_HOLE_REFRESH_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_HOLE_REFRESH_ACK* pData = (SC_ROLE_HOLE_REFRESH_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_HOLE_MERGE_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_HOLE_MERGE_REQ* pData = (CS_ROLE_HOLE_MERGE_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_HOLE_MERGE_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_HOLE_MERGE_ACK* pData = (SC_ROLE_HOLE_MERGE_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_HOLE_MERGE2_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_HOLE_MERGE2_REQ* pData = (CS_ROLE_HOLE_MERGE2_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_HOLE_MERGE2_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_HOLE_MERGE2_ACK* pData = (SC_ROLE_HOLE_MERGE2_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_LOCK_RPT(const void* pBuf, int nLen, const void* pObject)
{
    CS_LOCK_RPT* pData = (CS_LOCK_RPT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_USEITEM_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_USEITEM_REQ* pData = (CS_ROLE_USEITEM_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_PET_USEITEM_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_PET_USEITEM_REQ* pData = (CS_PET_USEITEM_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_USEITEM_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_USEITEM_ACK* pData = (SC_PET_USEITEM_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_LIMIT_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_LIMIT_NTF* pData = (SC_ROLE_LIMIT_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GATHER_ITEM_MERGE_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GATHER_ITEM_MERGE_REQ* pData = (CS_GATHER_ITEM_MERGE_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GATHER_ITEM_MERGE_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GATHER_ITEM_MERGE_ACK* pData = (SC_GATHER_ITEM_MERGE_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GATHER_INFO_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_GATHER_INFO_NTF* pData = (SC_GATHER_INFO_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GATHER_SINGLE_ENTER_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_GATHER_SINGLE_ENTER_NTF* pData = (SC_GATHER_SINGLE_ENTER_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GATHER_SINGLE_LEAVE_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_GATHER_SINGLE_LEAVE_NTF* pData = (SC_GATHER_SINGLE_LEAVE_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_PROD_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_PROD_REQ* pData = (CS_ROLE_PROD_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_PROD_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_PROD_ACK* pData = (SC_ROLE_PROD_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_USEITEM_START_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_USEITEM_START_ACK* pData = (SC_ROLE_USEITEM_START_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_USEITEM_END_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_USEITEM_END_ACK* pData = (SC_ROLE_USEITEM_END_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_USER_SKILLS_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_USER_SKILLS_NTF* pData = (SC_USER_SKILLS_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_LEARN_SKILL(const void* pBuf, int nLen, const void* pObject)
{
    CS_LEARN_SKILL* pData = (CS_LEARN_SKILL*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SKILL_INFO_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_SKILL_INFO_NTF* pData = (SC_SKILL_INFO_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_REMOVE_SKILL_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_REMOVE_SKILL_NTF* pData = (SC_REMOVE_SKILL_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SKILL_POINT_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_SKILL_POINT_NTF* pData = (SC_SKILL_POINT_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SKILL_RESET_ALL_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SKILL_RESET_ALL_REQ* pData = (CS_SKILL_RESET_ALL_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_USER_PETS_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_USER_PETS_NTF* pData = (SC_USER_PETS_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_INFO_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_INFO_NTF* pData = (SC_PET_INFO_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SET_BATTLE_PET_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SET_BATTLE_PET_REQ* pData = (CS_SET_BATTLE_PET_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SET_BATTLE_PET_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_SET_BATTLE_PET_NTF* pData = (SC_SET_BATTLE_PET_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_PET_GET_EXP_RPT(const void* pBuf, int nLen, const void* pObject)
{
    CS_PET_GET_EXP_RPT* pData = (CS_PET_GET_EXP_RPT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_LEVEL_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_LEVEL_NTF* pData = (SC_PET_LEVEL_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_PET_UP_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_PET_UP_REQ* pData = (CS_PET_UP_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_UP_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_UP_ACK* pData = (SC_PET_UP_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_PET_MERGE_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_PET_MERGE_REQ* pData = (CS_PET_MERGE_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_ADD_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_ADD_NTF* pData = (SC_PET_ADD_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PETS_RECORD_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PETS_RECORD_NTF* pData = (SC_PETS_RECORD_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_BAG_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_BAG_NTF* pData = (SC_PET_BAG_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_PET_EQUIP_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_PET_EQUIP_REQ* pData = (CS_PET_EQUIP_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_PET_EVENT_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_PET_EVENT_REQ* pData = (CS_PET_EVENT_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_BAG_SINGLE_LEAVE_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_BAG_SINGLE_LEAVE_NTF* pData = (SC_PET_BAG_SINGLE_LEAVE_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_BAG_SINGLE_ENTER_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_BAG_SINGLE_ENTER_NTF* pData = (SC_PET_BAG_SINGLE_ENTER_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_PET_TEAM_RPT(const void* pBuf, int nLen, const void* pObject)
{
    CS_PET_TEAM_RPT* pData = (CS_PET_TEAM_RPT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_TEAM_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_TEAM_NTF* pData = (SC_PET_TEAM_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_GET_EXP_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_GET_EXP_ACK* pData = (SC_PET_GET_EXP_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_SINGLE_ENTER_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_SINGLE_ENTER_NTF* pData = (SC_PET_SINGLE_ENTER_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_SINGLE_LEAVE_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_SINGLE_LEAVE_NTF* pData = (SC_PET_SINGLE_LEAVE_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PET_EVENT_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_PET_EVENT_ACK* pData = (SC_PET_EVENT_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_MOVE_SYNC_MODE(const void* pBuf, int nLen, const void* pObject)
{
    CS_MOVE_SYNC_MODE* pData = (CS_MOVE_SYNC_MODE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_MOVE_BEGIN(const void* pBuf, int nLen, const void* pObject)
{
    CS_MOVE_BEGIN* pData = (CS_MOVE_BEGIN*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_MOVE_STOP(const void* pBuf, int nLen, const void* pObject)
{
    CS_MOVE_STOP* pData = (CS_MOVE_STOP*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_MOVE_BEGIN(const void* pBuf, int nLen, const void* pObject)
{
    SC_MOVE_BEGIN* pData = (SC_MOVE_BEGIN*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_MOVE_STOP(const void* pBuf, int nLen, const void* pObject)
{
    SC_MOVE_STOP* pData = (SC_MOVE_STOP*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_OTHER_APPEAR(const void* pBuf, int nLen, const void* pObject)
{
    SC_OTHER_APPEAR* pData = (SC_OTHER_APPEAR*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_OTHER_UPDATE(const void* pBuf, int nLen, const void* pObject)
{
    SC_OTHER_UPDATE* pData = (SC_OTHER_UPDATE*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_OTHER_DISAPPEAR(const void* pBuf, int nLen, const void* pObject)
{
    SC_OTHER_DISAPPEAR* pData = (SC_OTHER_DISAPPEAR*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_CHAT(const void* pBuf, int nLen, const void* pObject)
{
    CS_CHAT* pData = (CS_CHAT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_CHAT(const void* pBuf, int nLen, const void* pObject)
{
    SC_CHAT* pData = (SC_CHAT*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_CHAT_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_CHAT_ACK* pData = (SC_CHAT_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_FRIENDS_LIST_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_FRIENDS_LIST_NTF* pData = (SC_FRIENDS_LIST_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_QUERY_ROLE_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_QUERY_ROLE_REQ* pData = (CS_QUERY_ROLE_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_QUERY_ROLE_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_QUERY_ROLE_ACK* pData = (SC_QUERY_ROLE_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ADD_FRIEND_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ADD_FRIEND_REQ* pData = (CS_ADD_FRIEND_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ADD_FRIEND_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ADD_FRIEND_ACK* pData = (SC_ADD_FRIEND_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_REMOVE_FRIEND_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_REMOVE_FRIEND_REQ* pData = (CS_REMOVE_FRIEND_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_REMOVE_FRIEND_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_REMOVE_FRIEND_ACK* pData = (SC_REMOVE_FRIEND_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_DONATE_ACTION_POINT_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_DONATE_ACTION_POINT_REQ* pData = (CS_DONATE_ACTION_POINT_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_DONATE_ACTION_POINT_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_DONATE_ACTION_POINT_ACK* pData = (SC_DONATE_ACTION_POINT_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_DONATE_ACTION_POINT_OTHER_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_DONATE_ACTION_POINT_OTHER_NTF* pData = (SC_DONATE_ACTION_POINT_OTHER_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_RECEIVE_ACTION_POINT_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_RECEIVE_ACTION_POINT_REQ* pData = (CS_RECEIVE_ACTION_POINT_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_RECEIVE_ACTION_POINT_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_RECEIVE_ACTION_POINT_ACK* pData = (SC_RECEIVE_ACTION_POINT_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_RESPONSE_ADD_FRIEND_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_RESPONSE_ADD_FRIEND_REQ* pData = (CS_RESPONSE_ADD_FRIEND_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_REQUEST_ADD_FRIEND_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_REQUEST_ADD_FRIEND_NTF* pData = (SC_REQUEST_ADD_FRIEND_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_FRIEND_INFO_CHANGE_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_FRIEND_INFO_CHANGE_NTF* pData = (SC_FRIEND_INFO_CHANGE_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_FRIEND_REMOVE_INVITE_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_FRIEND_REMOVE_INVITE_NTF* pData = (SC_FRIEND_REMOVE_INVITE_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_FRIEND_ASSIST_LIST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_FRIEND_ASSIST_LIST_REQ* pData = (CS_FRIEND_ASSIST_LIST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_FRIEND_ASSIST_LIST_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_FRIEND_ASSIST_LIST_ACK* pData = (SC_FRIEND_ASSIST_LIST_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SELECT_FRIEND_ASSIST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SELECT_FRIEND_ASSIST_REQ* pData = (CS_SELECT_FRIEND_ASSIST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SELECT_FRIEND_ASSIST_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_SELECT_FRIEND_ASSIST_ACK* pData = (SC_SELECT_FRIEND_ASSIST_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_FRIEND_EPINFO_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_FRIEND_EPINFO_NTF* pData = (SC_FRIEND_EPINFO_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_FRIENDS_LIST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_FRIENDS_LIST_REQ* pData = (CS_FRIENDS_LIST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ABYSS_TRIGGER_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ABYSS_TRIGGER_ACK* pData = (SC_ABYSS_TRIGGER_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ABYSS_OPEN_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ABYSS_OPEN_REQ* pData = (CS_ABYSS_OPEN_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ABYSS_OPEN_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ABYSS_OPEN_ACK* pData = (SC_ABYSS_OPEN_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ABYSS_OPEN_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ABYSS_OPEN_NTF* pData = (SC_ABYSS_OPEN_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_ABYSS_TRIGGER_LIST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_ABYSS_TRIGGER_LIST_REQ* pData = (CS_GET_ABYSS_TRIGGER_LIST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_ABYSS_TRIGGER_LIST_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_ABYSS_TRIGGER_LIST_ACK* pData = (SC_GET_ABYSS_TRIGGER_LIST_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_ABYSS_OPEN_LIST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_ABYSS_OPEN_LIST_REQ* pData = (CS_GET_ABYSS_OPEN_LIST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_ABYSS_OPEN_LIST_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_ABYSS_OPEN_LIST_ACK* pData = (SC_GET_ABYSS_OPEN_LIST_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_ABYSS_OPEN_REC_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_ABYSS_OPEN_REC_REQ* pData = (CS_GET_ABYSS_OPEN_REC_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_ABYSS_OPEN_REC_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_ABYSS_OPEN_REC_ACK* pData = (SC_GET_ABYSS_OPEN_REC_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ENTER_ABYSS_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ENTER_ABYSS_ACK* pData = (SC_ENTER_ABYSS_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ABYSS_RUN_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_ABYSS_RUN_NTF* pData = (SC_ABYSS_RUN_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_MAIL_LIST_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_MAIL_LIST_NTF* pData = (SC_MAIL_LIST_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SEND_MAIL_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SEND_MAIL_REQ* pData = (CS_SEND_MAIL_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SEND_MAIL_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_SEND_MAIL_ACK* pData = (SC_SEND_MAIL_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_ITEM_FROM_MAIL_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_ITEM_FROM_MAIL_REQ* pData = (CS_GET_ITEM_FROM_MAIL_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_MONEY_FROM_MAIL_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_MONEY_FROM_MAIL_REQ* pData = (CS_GET_MONEY_FROM_MAIL_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_READ_MAIL_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_READ_MAIL_REQ* pData = (CS_READ_MAIL_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_READ_MAIL_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_READ_MAIL_ACK* pData = (SC_READ_MAIL_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_DELETE_MAIL_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_DELETE_MAIL_REQ* pData = (CS_DELETE_MAIL_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_DELETE_MAIL_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_DELETE_MAIL_ACK* pData = (SC_DELETE_MAIL_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_UPDATE_MAIL_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_UPDATE_MAIL_NTF* pData = (SC_UPDATE_MAIL_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SHOP_ACTION_POINT_BOUGHT_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_SHOP_ACTION_POINT_BOUGHT_NTF* pData = (SC_SHOP_ACTION_POINT_BOUGHT_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SHOP_BUY_ACTION_POINT_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SHOP_BUY_ACTION_POINT_REQ* pData = (CS_SHOP_BUY_ACTION_POINT_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SHOP_BUY_ACTION_POINT_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_SHOP_BUY_ACTION_POINT_ACK* pData = (SC_SHOP_BUY_ACTION_POINT_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SHOP_BUY_PET_INFO_CHEAP_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_SHOP_BUY_PET_INFO_CHEAP_NTF* pData = (SC_SHOP_BUY_PET_INFO_CHEAP_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SHOP_BUY_PET_INFO_EXPENSIVE_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_SHOP_BUY_PET_INFO_EXPENSIVE_NTF* pData = (SC_SHOP_BUY_PET_INFO_EXPENSIVE_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SHOP_BUY_PET_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SHOP_BUY_PET_REQ* pData = (CS_SHOP_BUY_PET_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SHOP_BUY_PET_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_SHOP_BUY_PET_ACK* pData = (SC_SHOP_BUY_PET_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SHOP_GET_GOODSLIST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SHOP_GET_GOODSLIST_REQ* pData = (CS_SHOP_GET_GOODSLIST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SHOP_GET_GOODSLIST_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_SHOP_GET_GOODSLIST_ACK* pData = (SC_SHOP_GET_GOODSLIST_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SHOP_BUY_GOODS_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SHOP_BUY_GOODS_REQ* pData = (CS_SHOP_BUY_GOODS_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SHOP_BUY_GOODS_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_SHOP_BUY_GOODS_ACK* pData = (SC_SHOP_BUY_GOODS_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SHOP_SECRET_GOODS_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SHOP_SECRET_GOODS_REQ* pData = (CS_SHOP_SECRET_GOODS_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SHOP_SECRET_GOODS_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_SHOP_SECRET_GOODS_ACK* pData = (SC_SHOP_SECRET_GOODS_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SHOP_SECRET_BUY_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SHOP_SECRET_BUY_REQ* pData = (CS_SHOP_SECRET_BUY_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SHOP_SECRET_BUY_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_SHOP_SECRET_BUY_ACK* pData = (SC_SHOP_SECRET_BUY_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SHOP_SECRET_REFRESH_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SHOP_SECRET_REFRESH_REQ* pData = (CS_SHOP_SECRET_REFRESH_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_SELF_PVP_PRO_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_SELF_PVP_PRO_REQ* pData = (CS_SELF_PVP_PRO_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_SELF_PVP_PRO_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_SELF_PVP_PRO_ACK* pData = (SC_SELF_PVP_PRO_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_PVP_MATCH_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_PVP_MATCH_REQ* pData = (CS_GET_PVP_MATCH_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_PVP_MATCH_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_PVP_MATCH_ACK* pData = (SC_GET_PVP_MATCH_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ENTER_PVP_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ENTER_PVP_REQ* pData = (CS_ENTER_PVP_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ENTER_PVP_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ENTER_PVP_ACK* pData = (SC_ENTER_PVP_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_PVP_RETULT_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_PVP_RETULT_REQ* pData = (CS_PVP_RETULT_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PVP_RETULT_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_PVP_RETULT_ACK* pData = (SC_PVP_RETULT_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_RANK_LIST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_RANK_LIST_REQ* pData = (CS_GET_RANK_LIST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_RANK_LIST_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_RANK_LIST_ACK* pData = (SC_GET_RANK_LIST_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_PVP_MILITARY_REWARD_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_PVP_MILITARY_REWARD_REQ* pData = (CS_GET_PVP_MILITARY_REWARD_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_PVP_MILITARY_REWARD_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_PVP_MILITARY_REWARD_ACK* pData = (SC_GET_PVP_MILITARY_REWARD_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_PVP_REPUTE_REWARD_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_PVP_REPUTE_REWARD_REQ* pData = (CS_GET_PVP_REPUTE_REWARD_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_PVP_REPUTE_REWARD_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_PVP_REPUTE_REWARD_ACK* pData = (SC_GET_PVP_REPUTE_REWARD_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_PVP_BUY_CHALLENGE_TIMES_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_PVP_BUY_CHALLENGE_TIMES_REQ* pData = (CS_PVP_BUY_CHALLENGE_TIMES_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PVP_BUY_CHALLENGE_TIMES_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_PVP_BUY_CHALLENGE_TIMES_ACK* pData = (SC_PVP_BUY_CHALLENGE_TIMES_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_PVP_TIME_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_PVP_TIME_NTF* pData = (SC_PVP_TIME_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_PVP_ROLE_INFO_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_PVP_ROLE_INFO_REQ* pData = (CS_GET_PVP_ROLE_INFO_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_PVP_ROLE_INFO_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_PVP_ROLE_INFO_ACK* pData = (SC_GET_PVP_ROLE_INFO_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_VIP_INFO_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_VIP_INFO_NTF* pData = (SC_VIP_INFO_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_VIP_RMBINFO_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_VIP_RMBINFO_NTF* pData = (SC_VIP_RMBINFO_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_VIP_MONTHCARD_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_VIP_MONTHCARD_NTF* pData = (SC_VIP_MONTHCARD_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_VIP_MONTHCARD_GETITEM_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_VIP_MONTHCARD_GETITEM_REQ* pData = (CS_VIP_MONTHCARD_GETITEM_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_VIP_MONTHCARD_GETITEM_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_VIP_MONTHCARD_GETITEM_ACK* pData = (SC_VIP_MONTHCARD_GETITEM_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GIFT_SIGN_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_GIFT_SIGN_NTF* pData = (SC_GIFT_SIGN_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GIFT_SIGN_VIP_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_GIFT_SIGN_VIP_NTF* pData = (SC_GIFT_SIGN_VIP_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GIFT_SIGN(const void* pBuf, int nLen, const void* pObject)
{
    CS_GIFT_SIGN* pData = (CS_GIFT_SIGN*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GIFT_SIGN_VIP(const void* pBuf, int nLen, const void* pObject)
{
    CS_GIFT_SIGN_VIP* pData = (CS_GIFT_SIGN_VIP*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GIFT_LEVEL_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_GIFT_LEVEL_NTF* pData = (SC_GIFT_LEVEL_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GIFT_LEVEL(const void* pBuf, int nLen, const void* pObject)
{
    CS_GIFT_LEVEL* pData = (CS_GIFT_LEVEL*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GIFT_DAY_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_GIFT_DAY_NTF* pData = (SC_GIFT_DAY_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GIFT_DAY_UPD(const void* pBuf, int nLen, const void* pObject)
{
    SC_GIFT_DAY_UPD* pData = (SC_GIFT_DAY_UPD*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GIFT_DAY_SCORE_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GIFT_DAY_SCORE_REQ* pData = (CS_GIFT_DAY_SCORE_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GIFT_DAY_BOX_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GIFT_DAY_BOX_REQ* pData = (CS_GIFT_DAY_BOX_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GIFT_DAY_BOX_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_GIFT_DAY_BOX_NTF* pData = (SC_GIFT_DAY_BOX_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GIFT_JIHUOMA_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GIFT_JIHUOMA_REQ* pData = (CS_GIFT_JIHUOMA_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GIFT_JIHUOMA_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GIFT_JIHUOMA_ACK* pData = (SC_GIFT_JIHUOMA_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GIFT_EP_INFO_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GIFT_EP_INFO_REQ* pData = (CS_GIFT_EP_INFO_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GIFT_EP_INFO_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GIFT_EP_INFO_ACK* pData = (SC_GIFT_EP_INFO_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GIFT_RECEIVE_EP_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GIFT_RECEIVE_EP_REQ* pData = (CS_GIFT_RECEIVE_EP_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GIFT_RECEIVE_EP_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GIFT_RECEIVE_EP_ACK* pData = (SC_GIFT_RECEIVE_EP_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_WB_INFO_REFRESH_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_WB_INFO_REFRESH_REQ* pData = (CS_WB_INFO_REFRESH_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_WB_INFO_REFRESH_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_WB_INFO_REFRESH_ACK* pData = (SC_WB_INFO_REFRESH_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_WB_ADD_BUF_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_WB_ADD_BUF_REQ* pData = (CS_WB_ADD_BUF_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_WB_ADD_BUF_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_WB_ADD_BUF_ACK* pData = (SC_WB_ADD_BUF_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_WB_RELIVE_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_WB_RELIVE_REQ* pData = (CS_WB_RELIVE_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_WB_RELIVE_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_WB_RELIVE_ACK* pData = (SC_WB_RELIVE_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_WB_KILLED_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_WB_KILLED_NTF* pData = (SC_WB_KILLED_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_WB_RUN_NTF(const void* pBuf, int nLen, const void* pObject)
{
    SC_WB_RUN_NTF* pData = (SC_WB_RUN_NTF*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_WB_ENTER_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_WB_ENTER_REQ* pData = (CS_WB_ENTER_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_WB_ENTER_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_WB_ENTER_ACK* pData = (SC_WB_ENTER_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_WB_RESULT_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_WB_RESULT_REQ* pData = (CS_WB_RESULT_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_WB_RESULT_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_WB_RESULT_ACK* pData = (SC_WB_RESULT_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_ROLE_RANK_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_ROLE_RANK_REQ* pData = (CS_ROLE_RANK_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_ROLE_RANK_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_ROLE_RANK_ACK* pData = (SC_ROLE_RANK_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_PT_BASEINFO_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_PT_BASEINFO_REQ* pData = (CS_GET_PT_BASEINFO_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_PT_BASEINFO_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_PT_BASEINFO_ACK* pData = (SC_GET_PT_BASEINFO_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_BUY_PT_TIMES_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_BUY_PT_TIMES_REQ* pData = (CS_BUY_PT_TIMES_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_BUY_PT_TIMES_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_BUY_PT_TIMES_ACK* pData = (SC_BUY_PT_TIMES_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_MD_BASEINFO_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_MD_BASEINFO_REQ* pData = (CS_GET_MD_BASEINFO_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_MD_BASEINFO_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_MD_BASEINFO_ACK* pData = (SC_GET_MD_BASEINFO_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_BUY_MD_TIMES_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_BUY_MD_TIMES_REQ* pData = (CS_BUY_MD_TIMES_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_BUY_MD_TIMES_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_BUY_MD_TIMES_ACK* pData = (SC_BUY_MD_TIMES_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GET_FD_BASEINFO_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GET_FD_BASEINFO_REQ* pData = (CS_GET_FD_BASEINFO_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GET_FD_BASEINFO_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GET_FD_BASEINFO_ACK* pData = (SC_GET_FD_BASEINFO_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_BUY_FD_TIMES_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_BUY_FD_TIMES_REQ* pData = (CS_BUY_FD_TIMES_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_BUY_FD_TIMES_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_BUY_FD_TIMES_ACK* pData = (SC_BUY_FD_TIMES_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_INFO_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_INFO_REQ* pData = (CS_GUILD_INFO_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_LIST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_LIST_REQ* pData = (CS_GUILD_LIST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GUILD_LIST_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GUILD_LIST_ACK* pData = (SC_GUILD_LIST_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_ENTER_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_ENTER_REQ* pData = (CS_GUILD_ENTER_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GUILD_ENTER_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GUILD_ENTER_ACK* pData = (SC_GUILD_ENTER_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_CREATE_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_CREATE_REQ* pData = (CS_GUILD_CREATE_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GUILD_CREATE_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GUILD_CREATE_ACK* pData = (SC_GUILD_CREATE_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_LEAVE_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_LEAVE_REQ* pData = (CS_GUILD_LEAVE_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GUILD_LEAVE_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GUILD_LEAVE_ACK* pData = (SC_GUILD_LEAVE_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GUILD_BASEINFO_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GUILD_BASEINFO_ACK* pData = (SC_GUILD_BASEINFO_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_LOG_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_LOG_REQ* pData = (CS_GUILD_LOG_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GUILD_LOG_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GUILD_LOG_ACK* pData = (SC_GUILD_LOG_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_CHANGE_NOTICE_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_CHANGE_NOTICE_REQ* pData = (CS_GUILD_CHANGE_NOTICE_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_DETAIL_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_DETAIL_REQ* pData = (CS_GUILD_DETAIL_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GUILD_DETAIL_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GUILD_DETAIL_ACK* pData = (SC_GUILD_DETAIL_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_ENTERLIST_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_ENTERLIST_REQ* pData = (CS_GUILD_ENTERLIST_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GUILD_ENTERLIST_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GUILD_ENTERLIST_ACK* pData = (SC_GUILD_ENTERLIST_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_ENTER_ACCEPT_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_ENTER_ACCEPT_REQ* pData = (CS_GUILD_ENTER_ACCEPT_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GUILD_ENTER_ACCEPT_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GUILD_ENTER_ACCEPT_ACK* pData = (SC_GUILD_ENTER_ACCEPT_ACK*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnCS_GUILD_ENTER_CLEAR_REQ(const void* pBuf, int nLen, const void* pObject)
{
    CS_GUILD_ENTER_CLEAR_REQ* pData = (CS_GUILD_ENTER_CLEAR_REQ*)pBuf;

    return false;
}

bool CCliProtoMsgDispatcher::OnSC_GUILD_ENTER_CLEAR_ACK(const void* pBuf, int nLen, const void* pObject)
{
    SC_GUILD_ENTER_CLEAR_ACK* pData = (SC_GUILD_ENTER_CLEAR_ACK*)pBuf;

    return false;
}

NSCLIPROTO_END
