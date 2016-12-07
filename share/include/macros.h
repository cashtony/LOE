#ifndef __MACROS_H_2014_01_09_11_11__
#define __MACROS_H_2014_01_09_11_11__

// tolua_begin
#define MAX_IP_LEN                16
#define MAX_DBNAME_LEN            256

#ifndef MAX_PATH
    #define MAX_PATH              260
#endif


#define  CELL_WIDTH               (16 * 1000)

#define  MAX_OBJ_NAME_SIZE	      32
#define  MAX_OBJ_NAME_BUF_SIZE	  (MAX_OBJ_NAME_SIZE + 1)

#define  MAX_TRIGGER_NUM          255
#define  GRIDS_PER_METER          1
#define  HEIGHT_PER_METER         1000

#define INVALID_CHAR_VALUE        0x7F
#define INVALID_SHORT_VALUE       0x7FFF
#define INVALID_INT_VALUE         0x7FFFFFF

#define INVALID_8BIT_VALUE        UINT8(-1)
#define INVALID_16BIT_VALUE       UINT16(-1)
#define INVALID_32BIT_VALUE       UINT32(-1)
#define INVALID_64BIT_VALUE       UINT64(-1)
#define INVALID_OBJ_ID            UINT32(-1)

#define DATA_FORMULA              (10000.0f)
#define DATA_FORMULA_UINT32        UINT32(10000)
#define DATA_FORMULA_DATA_UINT32   UINT32(100)
#define DATA_CALC                 (100.0f)


// tolua_end

#define	 NET_SEND_BUFFER_SIZE		1024

#ifdef WIN32
#define LOG_POS                  __FUNCTION__
#else
#define LOG_POS                  __FILE__
#endif

// 资源文件定义
#define ITEM_UPGRADE_CSV               "starexp.csv"


#define MAX_TARGETPOS_NUM       8
#define MOVE_INTERVAL           500
#define BASE_INSTANCED_SCENE    1000
#define MOVE_TIMER_INTERVAL     50
#define MOVE_UPDATE_MAX_NUM     10
#define WONDERLAND_AWARD_TIME   (5 * 60)
#define M0VE_ELASTIC_MAX		3000

// 战场跨服副本id界限
#define BASE_INSTANCED_NONECROSS_SCENE_LIMIT   3000000000
#define BASE_INSTANCED_BATTLE_SCENE            3001000000
#define BASE_INSTANCED_BATTLE_SCENE_MAX        3002000000
#define BASE_INSTANCED_CORSS_SCENE             3003000000
#define BASE_INSTANCED_CORSS_SCENE_MAX         3004000000
#define BASE_INSTANCED_ARENA_SCENE             3005000000
#define BASE_INSTANCED_ARENA_SCENE_MAX         3006000000
#define BASE_INSTANCED_GUILDBATTLE_SCENE       3007000000
#define BASE_INSTANCED_GUILDBATTLE_SCENE_MAX   3007010000
#define MELEE_SCENE_BASE_ID		57
#define MELEE_BATTLE_FIELD_ID	(UINT32)-1

#define TIME_CHECK_SLOW         1000
#define TIME_CHECK_FAST         500


/// 时间换算
#define MSEL_TO_SECOND_TIME     1000
#define MSEL_TO_MINUTE_TIME     (60 * MSEL_TO_SECOND_TIME)
#define MSEL_TO_HOUR_TIME       (60 * MSEL_TO_MINUTE_TIME)
#define MSEL_TO_DAY_TIME        (24 * MSEL_TO_HOUR_TIME)
#define MSEL_TO_WEEK_TIME       (7 * MSEL_TO_DAY_TIME)
#define SEL_TO_MONTH_TIME       (30 * 24 * 3600)
#define SEL_TO_HOUR_TIME        (60 * 60)
#define SEL_TO_DAY_TIME         (24 * SEL_TO_HOUR_TIME)

#define SPIRIT_UPDATE_MINUTE    (5 * 60)
#define SPIRIT_UPDATE_SECOND    (SPIRIT_UPDATE_MINUTE * MSEL_TO_SECOND_TIME)
#define HEAVEN_EXP_UPDATE_MINUTE  (60 * MSEL_TO_SECOND_TIME)
#define MAX_OFF_GUAJI_TIME		(8 * SEL_TO_HOUR_TIME)
#define FUDI_ADD_EXP_PER_SECOND	10
#define FUDI_ADD_EXP_PER_TIME	(FUDI_ADD_EXP_PER_SECOND * MSEL_TO_SECOND_TIME)

// 对象ID池 不同gs的objid会相同的情况
//#define ROLEID_BASE              0
//#define ROLEID_SIZE              100000000000
//#define ROLEID_MAX               ROLEID_SIZE

#define MONSTERID_BASE           0//(ROLEID_MAX + 1)
#define MONSTERID_MAX            (MONSTERID_BASE + 100000000000)
#define MONSTERID_SIZE           (MONSTERID_MAX - MONSTERID_BASE)

#define PETID_BASE               (MONSTERID_MAX + 1)
#define PETID_MAX                (PETID_BASE + 100000000000)
#define PETID_SIZE               (PETID_MAX - PETID_BASE)


// 对象模板的一些参数
#define TEMPLATE_IP_ADDRESS_LENGTH	16
#define TEMPLATE_MAX_PATH_LENGTH	128
#define	TEMPLATE_MAX_CHAR			20480
#define TEMPLATE_MAX_STATE          5
#define TEMPLATE_MAX_AIACTION       10        // 每个AI状态最多的AI动作行为数
#define TEMPLATE_MAX_TRIGEVENT      5
#define	TEMPLATE_MAX_MONSTER_ITEM	16
#define	TEMPLATE_MAX_MONSTER_SKILL	8
#define MAX_LEVEL                   256
#define MAX_HEAVEN                  30        /// 变30了注意点.
#define MAX_ROLLWAIT_TIME           (30 * 1000)

// tolua_end

#define MAPPING_LOG_LOOP_NUM		512
#define MAPPING_LOG_CHECK_ID		0x12345678



// Attack Operate
#define PI                          3.1416f
#define ANGLE_INT_MAX               360
#define ANGLE_FLOAT_TO_INT          57.2958f
#define ANGLE_INT_TO_FLOAT          0.01745f
#define MIN_ATTACK_ANGLE            (-PI/2)   // 攻击最小角度
#define MAX_ATTACK_ANGLE            (PI/2)    // 攻击最大角度
#define MIN_SNEAK_ANGLE             (-PI/3)   // 偷袭最小角度
#define MAX_SNEAK_ANGLE             (PI/3)    // 偷袭最大角度
#define MIN_BLOCK_ANGLE             (-PI/2)   // 格挡最小角度
#define MAX_BLOCK_ANGLE             (PI/2)    // 格挡最大角度 
#define MIN_REVISE_ANGLE            (-PI/18)  // 怪物攻击角度修正最小角度
#define MAX_REVISE_ANGLE            (PI/18)   // 怪物攻击角度修正最大角度
#define ATK_ORI_CORRECT             10          // 追击角度修正,防止追击时聚在一点
#define ATK_DIS_CORRECT             500         // 追击距离修正,防止追击时聚在一点
#define AI_CHASE_SEAT_INTERVAL      18          // 追击人间隔
#define AI_CHASE_SEAT_NUM           (ANGLE_INT_MAX/AI_CHASE_SEAT_INTERVAL) ///追击人间隔
#define AI_BY_RAIDING_RANGE         5000      // 怪物被袭击响应范围
#define AI_CALL_HELP_RANGE          5000      // 怪物呼救范围
#define AI_CALL_HELP_MORE_RANGE     15000     // 怪物大声呼救范围
#define AI_JUGDE_ROLE_SPEED         4         // 怪物估算人物速度(毫秒)
#define AI_GOBACK_RESUME_TIME       1000      // 怪物返回回复时间间隔
#define AI_GOBACK_CHECK_TIME		6000      // 怪物返回检查时间间隔
#define AI_CHECK_ENMITY_TIME        8000      // 怪物切换仇恨度最高
#define AI_ESCAPE_MAX_RANGE         16000     // 怪物逃跑距离当前最远距离
#define AI_COMA_LAST_TIME           10000     // 怪物昏迷时间
#define AI_COMA_PLAY_TIME           16000     // 鞭尸时间
#define AI_ENMITY_OT_VALUE          12/10     // OT系数
#define IMPROVE_SKILL_MAX_TIME      10        // 修炼武功次数
#define AI_ATTACK_WAIT_TIME         300       // 追击结束等待开始物理攻击时间
#define AI_CHASE_WAIT_TIME          1800      // 追击时间间隔
#define AI_UNCHASE_WAIT_TIME        10000     // 追击不到的等待时间
#define AI_UNCHASE_OTAL_SECOND		24     // 追击不到的累计时间
#define AI_BOSS_LAMPOON_TIME        5000      // BOSS战维持仇恨时间
#define AI_STAND_NATK_CHECK_TIME	1000

#define GET_SKILL_POINT_LEVEL       1         // 每隔多少等级得到一个技能点

#define MIN_CHANGE_ATTACK_MODE_LEVEL 35       // 能改变攻击模式的等级
#define MIN_DEAD_PK_PROTECT_TIME    3         // 多少次死亡进入pk保护流程
#define PK_PROTECT_BUFF_ID          111       // 死亡保护buffid0
#define GM_CONCEAL_BUFF_ID          135       // 经验    
#define FUDI_MULTIPLE_BUFF_ID       116       // 境界福地双倍符
#define FUDI_ADD_MAX_EXP_BUFF_ID    117       // 境界福地上限符

#define PHY_ATTACK_ACTION_TIME      0         // 普通攻击动作时间 ms
#define PHY_EQUIP_WEAPON_TIME       800       // 装备武器所需的动作时间 ms
#define PHY_ATTACK_TIMER            100       // 普通攻击UPDATE时间 ms
#define EFFECT_DELAY_TIMER          50       // 效果延时UPDATE时间 ms

#define ATTACK_SKILL_ID_COMMOM      1         // 普通物理攻击(近战武器)
#define ATTACK_SKILL_ID_FIRE        2         // 射击(弓弩)
#define ATTACK_SKILL_ID_CAST        3         // 投掷(暗器)
#define ATTACK_SKILL_ID_BACK        4         // 返回

#define MAX_BATTLE_VS_FORCE_COUNT   2         // 战场最大势力数量
#define MAX_BATTLE_VS_EXP_AWARD_NUM	10			///前10场获取经验

#define MAX_ITEM_RESET_COST_COUNT   10        // 洗练消耗配置次数最大值 

#define MAX_ITEM_LOCK_HEAD_COUNT    4         // 洗练最大锁定字头数

//骑乘相关
#define MOUNT_SKILL_ID_RIDE			102       // 上马技能ID
#define MOUNT_SKILL_ID_UNRIDE		103       // 下马技能ID

//卡死回城技能
#define DEATHREVIVE         119

//彩票模板id
#define LOTTERY_TICKET_TEMPLATE_ID  0

//------------------------------------------------------------------------
// 注意: 服务端、客户端的攻击距离修改要同步
#define SINGLE_ATTACK_DIS           3000   // 单手攻击距离，单位毫米
#define TWOHAND_ATTACK_DIS          4000   // 双手攻击距离，单位毫米
#define BOW_ATTACK_DIS              30000  // 弓攻击距离，单位毫米
#define DART_ATTACK_DIS             20000  // 暗器攻击距离，单位毫米

#define CLIENT_SQR_SINGLE_ATTACK_DIS    9   // 客户端用-单手攻击距离（平方），单位米
#define CLIENT_SQR_TWOHAND_ATTACK_DIS   16   // 客户端用-双手攻击距离（平方），单位米
#define CLIENT_SQR_BOW_ATTACK_DIS       900	// 客户端用-弓攻击距离（平方），单位米
#define CLIENT_SQR_DART_ATTACK_DIS      400	// 客户端用-暗器攻击距离（平方），单位米
//------------------------------------------------------------------------
#define CYLINDER_HEIGHT_VALUE			5000
#define MALE_UNDER_WATER_HEIGHT			2000
#define FEMALE_UNDER_WATER_HEIGHT		1900

#define ATTACK_DURATION             8000   // 战斗状态刷新时间ms
#define TICK_DURATION               5000   // 回血刷新时间ms
#define TICK_LEAPVALUE_DURATION     2000   // 回轻功值时间ms
#define ALL_SKILL_COOLDOWN_TIME     1500   // 所有技能冷却时间ms，公共冷却时间
#define MAX_ALL_COOLDOWN_TIME       2000   // 最大公共cd时间
#define MIN_ALL_COOLDOWN_TIME       500    // 最小公共cd时间
#define AOE_MAX_Z_DIS				8000

#define	DEAD_COST_LEVEL_LOW         20     // 死亡消耗最低等级

#define MAX_BUFF_NUM                20    
#define INVALID_BUF_NUM             0xFFFFFFFF  
#define INVALID_BUF_TIME            0xFFFFFFFF  
#define USING_LIFE_SKILL_TIME       3000 // 生活技能使用时间
#define SKILL_FLY_SPEED             (200 * 200)
#define MAX_SKILL_LEVEL             10
#define MAX_WAIT_LEAP_GO            2000
#define CHARACTER_COEFFICIENT       1000
#define CREATE_ATTACK_ACTION        99
#define PHYATTACK_STOP_DELAY        2000   // 毫秒
#define ATTACK_FAR_BLOCK_PARAM      2      // 远程攻击被格档概率系数
#define MIN_ATTACK_TIME             1000   // 最小攻击时间间隔 ms
#define MAX_SKILL_PREPARE_TIME      10000  // 最大蓄力时间
#define MIN_SKILL_PREPARE_TIME      500    // 最小蓄力时间
#define MAX_SKILL_SET_TIME          120000 // 通道技能最大施法时间
#define MIN_SKILL_SET_TIME          500    // 通道技能最小施法时间
#define MAX_RELATED_SKILL_NUM       5      // 关联技能的最大个数
#define ONE_DAY_SECOND              86400  //一天的秒数
#define MIN_SKILL_FLYTIME           100    // 技能最小延时时间
#define MIN_FLASH_INSTANT_MOVE_TIME 200    // 闪击的移动时间做动作的时间
#define SCHOOL_SKILL_MIN_ID         1000   // 门派技能id必须大于这个, 约定
#define SCHOOL_SKILL_MAX_ID         100000 // 门派技能id必须小于这个, 约定
#define CREATE_SKILL_MAX_IMPROVE_TIMES  10 // 自创武功可修炼次数
#define CREATE_SKILL_MAX_LEVEL      12     // 自创武功可进阶次数

#define PK_VALUE_PER_PERSON           100    //最后一刀杀死每个玩家增加的pk值
#define PK_VALUE_PER_PERSON_COMMON    50     //参与杀死每个玩家增加的pk值
#define PK_VALUE_REDUCE_INTERVAL      120000 // PK值消减时间2分钟
#define PK_VALUE_PER_MONSTER_NORMAL   5      //每杀死5个普通怪物，减少一点pk值
#define PK_VALUE_PER_MONSTER_OUTSTAND 5      //每杀死5个精英怪物，减少一点pk值
#define PK_VALUE_PER_MONSTER_BOSS     5      //每杀死5个boss，减少一点pk值
#define MONSTER_DEAD_ROCK_DIS         5000   //怪物死亡被击飞距离 mm

#define DEAD_JIANGHU_CARD_ID          620401 //江湖令牌
#define GOLD_RECOVER_EQUIP_ITEM_ID          400005 //金色解封石
#define NORMAL_RECOVER_EQUIP_ITEM_ID        400004 //普通解封石

#define PK_BROWN_REMOVE_INTERVAL    15000  // 褐色名字移除时间15秒

#define WAIT_ANSWER_TIME            60000  // 发起请求等待时间 1分钟
#define ROLE_DEAD_WAIT_TIME         64000  // 角色死亡等待时间
#define ROLE_DEAD_WAIT_TIME_PVP     19000  // PVP战场死亡复活时间   
#define ROLE_BREATH_TIME            90000   /// 角色呼吸时间
#define ROLE_BREATH_REVERT_TIME     10000   /// 角色呼吸恢复时间
#define ROLE_BREATH_REVERT      (ROLE_BREATH_TIME/ROLE_BREATH_REVERT_TIME)   /// 角色呼吸恢复时间
#define ROLE_DROWN_TIME             3000   /// 角色溺水掉血间隔
#define ROLE_DEAD_WAIT_TIME_FIGHT   14000  /// 生死乱斗死亡等待时间

#define FIGHTER_BUFF_CLASSID        1      // 拼命三郎buff的classid
#define FIGHTER_BUFF_MAX_LEVEL      10     // 最大等级
#define WEAKNESS_BUFF_ID            11     // 战场未结束离开战场的玩家，给与懦弱者buff 并且在15分钟以内不能排队 下线保留
#define BI_HAI_BATTLE_BUFF_ID       136    // 碧海灵泉离开后给的buff 下线保留
#define LOSER_BUFF_ID               12     // 资源战场中被玩家杀死获得的buff 下线保留
#define ABSORB_WUHUN_BUFF_ID        13     // 可以被吸魂的buffid
#define SUMMON_WUHUN_PUBLIC_CD      3000   // 唤醒时候的公共cd 3s
#define WUHUN_BEIDONG_MAX_LEVEL     6      // 被动最大等级 
#define WUHUN_NORMAL_SKILL_MAX_LEVEL   10  // 普通技能最大等级 
#define WUHUN_ADD_HUNNENG_PER_MONSTER  5   // 每杀死一个怪物获得的魂能
#define SUMMON_MONSTER_SHOW_HOST_CODE	514
#define STEP_ADD_Z_HEIGHT 2000

#define WUHUN_GOLD_BENYUAN    492000       // 五行本源 金木水火土
#define WUHUN_WOOD_BENYUAN    492001
#define WUHUN_WATER_BENYUAN   492002
#define WUHUN_FIRE_BENYUAN    492003
#define WUHUN_DUST_BENYUAN    492004

#define PK_PUTIGUO_ITEM_ID    100361       // 红名免惩罚道具 菩提果

#define LIEMING_LINGWU_GET_ITEM_COUNT    200 //能领悟获得的最大数量
#define LIEMING_LINGWU_CHIP_MAX_COUNT    999 //碎片最大个数
#define LIEMING_ITEM_MAX_LEVEL    8   //物品最大等级
#define LIEMING_ITEM_INIT_GRID_COUNT 24    //初始多少格子
#define LIEMING_QEUIP_INIT_PAGE_COUNT 2    //初始多少装备页签
#define LIEMING_ADD_EQUIP_GRID_PER_ROLE_LEVEL 5 //多少级增加装备一个格子
#define LIEMING_ADD_EQUIP_GRID_BASE_LEVEL   45  //多少级开始有装备格

#define LEAP_JIPAO_BUFF_ID         80111     //疾跑buffid      神行无影
#define LEAP_JIPAO_WATER_BUFF_ID   80115     //水上疾跑buffid  神行踏浪
#define LEAP_FLYING_BUFF_ID        80112     //飘飞buffid      神行御风
#define LEAP_WATER_SPEED_BUFF_ID   80113     //水中加速        登萍渡水
#define LEAP_SPEED_BUFF_ID         80114     //空中加速        神行御空 


#define ENTER_SCENE_BUFF_ID         99     // 进入场景时，使玩家无敌的buff

#define IMMUNITY_DEAD_BUFF_ID       41616  // 免疫死亡buffid
#define UNIMMUNITY_DEAD_BUFF_ID     41621  // 抗免疫死亡buffid

#define RETURN_STAND_TIME           3000   // 倒地站起来需要的时间

// duel
#define DUEL_READY_TIME             5000   // 决斗准备时间 5s
#define DUEL_ALERT_TIME             5000   // 决斗超出范围警戒时间 5s
#define DUEL_DURA_TIME              300000 // 决斗时间 5m
#define DUEL_MIN_HP                 1      // 决斗结果的最小hp

#define DUEL_ALERT_DISTANCE         80000  //决斗警戒距离
#define DUEL_ALERT_DISTANCE_SQUARE  6400000000
#define DUEL_MAX_DISTANCE           100000 //决斗距离
#define DUEL_MAX_DISTANCE_SQUARE    10000000000 //用64位存储

#define NPC_DUEL_CLOSE_TIME         10000       //切磋玩关闭场景的时间
#define NPC_DUEL_BOSS_COUNT_MAX     5           //npc切磋最多刷怪数量

//deadMark
#define DEAD_MARK_LIVE_TIME_BY_ROLE 60000     //1分钟 被玩家杀死尸体存活时间
#define DEAD_MARK_LIVE_TIME_BY_MST  180000    //3分钟 被怪物杀死尸体存活时间
#define DEAD_MARK_PROTECTED_TIME    120000    //2分钟 被怪物杀死尸体保护时间 超过时间将所有人都能拾取
#define DEAD_MARK_AFTER_PICK        3000      //3秒钟 被拾取完保留时间
#define DEAD_ENTER_DIFU_PER         0         //死亡进入地府的概率 暂时为0 万分比
#define DIFU_SCENE_BASE_ID          101
#define CREATE_WORLD_SCENE_ID       43

// Resist
#define RESIST_TOTAL_TIME           30000  //统计时间 30s
#define RESIST_HIT_MAX_TIMES        3      //规定时间内命中最大次数
#define RESIST_IMMUNITY_TIME        10000  //免疫时间 10s

//AI
#define AI_ESCAPE_PERCENT_HP        0.05        // 怪物逃跑的HP比例
#define AI_MAX_PATROLPOS_COUNT      10          // 怪物最多的巡逻点数量
#define AI_MAX_ACTIONPARA_LEN       128         // AI动作参数最大长度
#define AI_ENEMY_REFRESH_TIME       8000        // 攻击目标刷新间隔8秒
#define AI_ESCAPE_SETTLE_TIME       86400000    // 逃跑后停留时间
#define MAX_SKILL_PERACTION         5           // 每个动作最大的可选技能数
#define MAX_SUMMONMON_NUM           5           // 最大召唤怪物的种类
#define PET_AI_GUARD_RANGE          10000       // 宠物警戒范围
#define PET_AI_DISPEAR_RANGE        30000       // 宠物存在范围
#define PET_AI_FOLLOW_WALK_RANGE    2000        // 宠物跟随步行距离
#define PET_AI_FOLLOW_RANGE         200         // 宠物跟随距离
#define CROWD_MONSTER_MAX           16          // 怪物集群数量上限
#define MONSTER_BIRTH_AI_TIME       6000        // 怪物出生不主动攻击人时间 
#define MONSTER_CHECK_SKILL_TIME    3000        // 怪物使用技能检查
#define MONSTER_CLICK_STICK_TIME    15000       // 怪物对话点击停留时间 
#define EAVESDROP_CONTENT_LEN       255         // 窃听任务对话长度
#define MONSTER_SUMMON_DESTROY_TIME 30000       // 召唤怪物销毁时间
#define MONSTER_CONVOY_FAILED_DIS   (32 * 1000)   /// 护送失败距离
#define MONSTER_CONVOY_FOLLOW_DIS   (2 * 1000)    // 护送跟随距离
#define MONSTER_CONVOY_CHECK_TIME   3000        // 护送检查时间间隔
#define MONSTER_CONVOY_WARNING_DIS  (10 * 1000)   // 护送跟随距离
#define MONSTER_CONVOY_PROTECTOR_DIS (50 * 1000)  // 护送检查时间间隔
#define PLAYER_BIRTH_POS_DIS		2500		// 玩家出生范围距离
#define PLAYER_ENTER_RANDOM_DIS		3000		// 玩家进入场景随机
#define MONSTER_SUMMON_MAX_NUM		1024
#define MONSTER_ANCESTOR_MAX_NUM	3

#define BATTLE_ITEM_MEDAL_DUST   109000  // 土灵勋章
#define BATTLE_ITEM_MEDAL_POISON 109001  // 剧毒勋章
#define BATTLE_ITEM_MEDAL_SPIRIT 109006  // 精气勋章

// bag,bank
#define BAG_BAG_POS_NUM			    4
#define BANK_BAG_POS_NUM			6
#define MIN_CITY_BANK_SIZE		    60
#define MAX_CITY_BANK_SIZE		    144
#define MAX_HOUSE_CHEST_SIZE	    36
#define MIN_BAG_SIZE		        36
#define MAX_BAG_SIZE			    108
#define MAX_BAG_GRID_PER_ROW        9
#define MAX_BANK_GRID_PER_ROW       12

// 生活技能
#define  MAX_USETOOL_DISTANCE       (5000*5000)               /// 使用工具的距离
#define  CDTIME_RELEATED_VALUE      (24*3600*365*30)        /// 30年时间
#define  MAX_MATCHTOOL_NUM          5                       /// 配方工具的最大数量
#define  CREATE_THRESHOLD           10                      /// 具有创建功能的阈值
#define  LEVEL_DISTANCE             6        
#define  MAX_MATCH_DES_NUM          24                      /// 配方技能描述长度
#define  RS_FREEMATCH_NUM           3
#define  MAX_SKILLNAME_LEN          16                      // 生活技能名字长度
#define  MAX_MATCHNAME_LEN          16                      // 配方名字长度

//奇遇
#define MAX_TRIGGER_EVENT_PER_ADVENTURE   5              // 每个奇遇最多对应的触发事件

#define MAX_ITEM_NUM_PER_SET              10             // 套装最多物品数
#define MAX_AVAILABLEDINSTANCE_NUM        100            // 队伍中可享用怪物经验值的范围.
#define MAX_PERFORMANCE_TIME              (1000*60*30)   // 最多演出时间30分钟
#define MAX_PERFORMANCE_SUSPEND_TIME      (1000*60*10)   // 最多挂起时间10分钟
#define TMP_CREATE_MONSTER_APPEAR_TIME    (1000*60*3)    // 临时创造生物的维续时间
#define INVALID_ADVENTURE_ID              0xFFFFFFFF
#define INVALID_PERFORM_ID                0xFFFFFFFF
#define ADVENTURE_DROP_ITEMLIST_BASE      0

// 怒酒最大值
#define MAX_DRUNKEN_VALUE                 1000
// 怒酒值每秒衰减

#define TIMER_DRUNKEN_COUNT               (1*1000)
#define TIMER_DRUNKEN_VALUE               50

enum INPUT_DIR_MASK
{
	INPUT_DIR_TURNLEFT = (1 << 0),
	INPUT_DIR_TURNRIGHT	= (1 << 1),
	INPUT_DIR_UP = (1 << 2),
	INPUT_DIR_DOWN = (1 << 3),
	INPUT_DIR_LEFT = (1 << 4),
	INPUT_DIR_RIGHT = (1 << 5),
	INPUT_DIR_VERTICAL_UP = (1 << 6),
	INPUT_DIR_VERTICAL_DOWN = (1 << 7),
	INPUT_DIR_DOUBLE_UP = (1 << 8),
};

#define INPUT_MOUSE_LEFT	              (0)
#define INPUT_MOUSE_RIGHT	              (0)
#define INPUT_SWIM_AUTOUP				  (0)
#define INPUT_SWIM_AUTODWON				  (0)

#define MAX_MOVE_INTERVAL                 (3 * 1000)
#define MOVEENERGY_TIME_1                 (3 * 1000)
#define MOVEENERGY_TIME_2                 (6 * 1000)
#define MOVEENERGY_TIME_KEEP              (2 * 1000)

#define SENDEMAIL_FEE                     50              // 发送邮件费用
#define THING_TIMER                       (600 * 1000)      // 场景物品自动消失时间为10分钟
#define TRIP_SCENE_ASK_WAIT_TIME		  60

#define SCENE_CLEAR_TIME                  30000           // 副本地图清人timer时间
#define SCENE_WAIT_ROLE_TIME			  (5 * 60 * 1000)    // 附属世界等人销毁时间
#define SCENE_MAX_SYNC_NUM				  2048

// 一个UINT32 分2两半, 前面从UUID里面取
// 后面在GS上生成
#define SCENE_INSTANCED_ID_R              12
#define SCENE_INSTANCED_ID_L              20

#define ROLE_HP_TIMER                     1000       // HP定时通知RS 
#define ROLE_MP_TIMER                     1000       // MP定时通知RS

// 关系宏
#define CREATE_GUILD_LEVEL                 30         // 申请帮会的等级
#define REPLY_GUILD_LEVEL                  20         // 响应帮会的等级
#define JOIN_GUILD_LEVEL                   1

#define IS_VALID_ID(UINT32_ID)     (UINT32_ID != INVALID_32BIT_ID)

//
// !!note: 下面的模块提供给客户端使用(毋修改)
//

// 获取变化的Job, 返回unsigned int
#define GET_JOB(pBuf) (*(UINT32*)pBuf)

/// 提取提升或降级帮会成员
#define GET_ROLENAME(pBuf) ((const char*)pBuf)
#define GET_OLD_ROLEGUILDLEVEL(pBuf)  (*(UINT8*)((const char*)pBuf + ROLE_NAME_LEN))
#define GET_NEW_ROLEGUILDLEVEL(pBuf)  (*(UINT8*)((const char*)pBuf + ROLE_NAME_LEN + sizeof(UINT8)))
/// 设置提升或降级帮会成员
#define SET_ROLEGUILDLEVEL_CHG(szData, szRoleName, byOldGuildLevelIndex, byNewGuildLevelIndex)\
    strncpy(szData, szRoleName, ROLE_NAME_LEN);\
    memcpy(szData+ ROLE_NAME_LEN, &byOldGuildLevelIndex, sizeof(UINT8));\
    memcpy(szData + ROLE_NAME_LEN + sizeof(UINT8), &byNewGuildLevelIndex, sizeof(UINT8));


/// 帮会繁荣度改变
#define GET_GUILDPROSPER(pBuf) (*((int*)pBuf))

/// 帮会等级变化
#define GET_GUILDLEVEL(pBuf) (*((UINT16*)pBuf))


/// 帮会转让帮主
#define GET_GUILDOLDLEADER(pBuf) (*((UINT64*)pBuf))
#define GET_GUILDNEWLEADER(pBuf) (*((UINT64*)(pBuf + sizeof(UINT64))))
/// 设置帮主变化
#define  SET_GUILDLEADER_CHG(szData, qwOldLeaderID, qwNewLeaderID)\
    memcpy(szData, &qwOldLeaderID, sizeof(UINT64));\
    memcpy(szData + sizeof(UINT64), &qwNewLeaderID, sizeof(UINT64));


// 帮会成员备注改变
#define GET_GUILD_MEMBERNAME(pBuf) ((const char*)pBuf)
#define GET_GUILD_MEMBERMEMO(pBuf) ((const char*)((const char*)pBuf + ROLE_NAME_LEN))

// 设置帮会成员备注
#define SET_GUILD_MEMBERMEMO(szData, szName, szMemo)\
    strncpy(szData, szName, ROLE_NAME_LEN);\
    strncpy(szData + ROLE_NAME_LEN , szMemo, GUILD_MEMO_LEN);\
    szData[ROLE_NAME_LEN + GUILD_MEMO_LEN] = 0;

/// 帮会宗旨变化
#define GET_GUILD_AIM(pBuf) ((const char*)pBuf)

/// 帮会信息获取相关函数
#define GET_GUILD_MEMO_FORUM(pBuf)   ((SGuildMemoInfo*)pBuf)->szForum
#define GET_GUILD_MEMO_CONTACT(pBuf) ((SGuildMemoInfo*)pBuf)->szContact
#define GET_GUILD_MEMO_MEMO(pBuf)    ((SGuildMemoInfo*)pBuf)->szMemo

// 帮会成员等级
#define GET_GUILD_MEMBER_LEVEL(pBuf)  (*(UINT32*)pBuf)

// 帮会成员当前贡献度
#define GET_GUILD_MEMBER_CURDEVOTION(pBuf)  (*(UINT32*)pBuf)

// 帮会成员当前最大贡献度
#define GET_GUILD_MEMBER_MAXDEVOTION(pBuf)  (*(UINT32*)pBuf)

// 帮会JOB
#define GET_GUILD_MEMBER_JOB(pBuf) GET_JOB(pBuf)

// 获取帮会的最大人数
#define GET_GUILD_MAX_MEMBER(pBuf) (*(UINT16*)pBuf)

//
// 正在加入帮会列表信息变化
//
#define GET_JOIN_GUILD_MEMBER_LEVEL(pBuf) GET_GUILD_MEMBER_LEVEL(pBuf)
#define GET_JOIN_GUILD_MEMBER_JOB(pBuf) GET_JOB(pBuf)

//
// 好友信息变化
//

// 好友是否加入队伍, 用RS_RESULT_YES : RS_RESULT_NO表示
#define GET_FRIEND_WHETHERINGROUP(pBuf) (*(unsigned char*)pBuf)

// 获取好友的等级
#define GET_FRIEND_LEVEL(pBuf) (*(UINT32*)pBuf)

// 好友Job
#define GET_FRIEND_JOB(pBuf)  (*(UINT32*)pBuf)
#define GET_FRIEND_SUBJOB(pBuf)  (*(UINT32*)(pBuf + sizeof(UINT32)))

// 获取和好友之间的亲密度
#define GET_FRIEND_INTIMACY(pBuf) (*(int*)pBuf)

//
// 宠物相关属性获取
//
// 获取HP, 返回int
#define GET_PET_HP(pBuf) (*(int*)pBuf)

//获取MAXHP, 返回int
#define GET_PET_MAXHP(pBuf) (*(int*)pBuf)

// 获取MP, 返回int
#define GET_PET_MP(pBuf) (*(int*)pBuf)

//获取MAXMP, 返回int
#define GET_PET_MAXMP(pBuf) (*(int*)pBuf)

// 添加BUFF, 返回SBuffDataInfo*
#define GET_PET_ADDBUF(pBuf) ((SBuffDataInfo*)pBuf)

// 删除BUFF, 返回SBuffDataInfo*
#define GET_PET_REMOVEBUF(pBuf) ((SBuffDataInfo*)pBuf)

// 出现或消失的宠物模板ID
#define GET_PET_FOLD_TEMPLATE_VAL(pBuf) (*((unsigned int*)pBuf))

// 是否消失参数
#define GET_PET_FOLD_VAL(pBuf) *(int*)(pBuf + sizeof(UINT32))

// 获取PKCOLOR
#define GET_PKCOLOR_VAL(pBuf)  (*((unsigned char*)pBuf))

// 流派下一级领悟时间
#define GET_SCHOOL_NEXT_SKILL_LEVEL_START_TIME(pBuf) (*(unsigned int*)pBuf)

// 当前学习的技能等级
#define GET_SCHOOL_STUDIED_LEVEL(pBuf) (*((unsigned char*)pBuf))

// 获取BUFF信息
#define GET_BUFF_OBJID(pBuf) (*(unsigned int*)pBuf)
#define GET_BUFF_ID(pBuf)    (*(unsigned int*)(pBuf+sizeof(UINT32)))
#define GET_BUFF_LAYER(pBuf) (*(unsigned char*)(pBuf+sizeof(UINT32)+sizeof(UINT32)))
#define GET_BUFF_STATE(pBuf) (*(unsigned char*)(pBuf+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT8)))

// 场景变换宏
#define GET_CHG_INSTANCE_SCENE_ID(pBuf) (*(unsigned int*)pBuf)
#define GET_CHG_BASE_SCENE_ID(pBuf) (*(unsigned int*)(pBuf+sizeof(unsigned int)))

// 获取帮会个人活跃度
#define GET_GUILD_ACTIVE(pBuf) (*(unsigned int*)pBuf)


/// 脚本位置属性
#define  SCRIPT_POS_X   "x"
#define  SCRIPT_POS_Y   "y"
#define  SCRIPT_POS_Z   "z"

#define SCRIPT_EXPORT_INCREASE          60
#define SCRIPT_STEP_SIZE                1
#define SCRIPT_START_STEP_SIZE          (1024 * 1024)

/// 物品脚本函数
#define ITEM_SCRIPT_FUNC_CREATE         "OnItemCreate"
#define ITEM_SCRIPT_FUNC_GET            "OnGetItem"
#define ITEM_SCRIPT_FUNC_EQUIP_CHECK    "CanEquipItem"
#define ITEM_SCRIPT_FUNC_EQUIP          "OnEquipItem"
#define ITEM_SCRIPT_FUNC_UNEQUIP        "OnUnequipItem"
#define ITEM_SCRIPT_FUNC_USE_CHECK      "CanUseItem"
#define ITEM_SCRIPT_FUNC_EFFECT         "OnUseItemEffect"
#define ITEM_SCRIPT_FUNC_DESTROY        "OnDestroyItem"
#define ITEM_SCRIPT_FUNC_OBTAIN         "OnAbtain"
#define ITEM_SCRIPT_FUNC_SPECIAL_EVENT	"OnSpecialEvent"

/// 场景脚本函数
#define SCENE_SCRIPT_FUNC_CREATE        "OnCreateScene"
#define SCENE_SCRIPT_FUNC_DESTROY       "OnDestroyScene"
#define SCENE_SCRIPT_FUNC_ENTER         "OnRoleEnterScene"
#define SCENE_SCRIPT_FUNC_LEAVE         "OnRoleLeaveScene"
#define SCENE_SCRIPT_POS_TRIGGER        "PosTrigger"
#define SCENE_SCRIPT_TIMER_TRIGGER      "TimerTrigger"
#define SCENE_SCRIPT_TIMER              "Timer"
#define SCENE_SCRIPT_CROWD_DEAD         "CrowdDead"
#define SCENE_SCRIPT_CROWD_PATROL       "CrowdPatrolPoint"
#define SCENE_SCRIPT_ROLE_DEAD          "OnRoleDead"
#define SCENE_SCRIPT_ROLE_RELIVE		"OnRoleRelive"
#define SCENE_SCRIPT_MIRROR_IMAGE       "CreateMirrorImage"
#define SCENE_SCRIPT_PREPAREENTER       "OnPrepareEnterScene"
#define SCENE_SCRIPT_RELIVE_POS			"CreateRelivePos"
#define SCENE_SCRIPT_FUNC_ROLETIERENOVER  "OnRoleTierenOver"
#define SCENE_SCRIPT_FUNC_PLAN_FINISH   "OnScenePlanFinish"

/// AI脚本函数
#define AI_SCRIPT_FUNC_CHECK_ENEMY      "CheckEnemy"
#define AI_SCRIPT_FUNC_AI_START         "OnAiStart"
#define AI_SCRIPT_FUNC_ATK_START        "OnAtkStateStart"
#define AI_SCRIPT_FUNC_ATK_END          "OnAtkStateEnd"
#define AI_SCRIPT_FUNC_ATK_HP_CHANGE    "OnAtkHpChange"
#define AI_SCRIPT_FUNC_ATK_DEAD         "OnAtkDead"
#define AI_SCRIPT_FUNC_MOVE_ARRIVE      "OnMovePosArrive"
#define AI_SCRIPT_FUNC_DISPEAR          "OnDispear"
#define AI_SCRIPT_FUNC_ROLE_NEAR        "OnRoleNear"

#define AI_SCRIPT_TIMER                 "Timer"
#define AI_SCRIPT_ACTION                "Action"
#define AI_SCRIPT_ENEMY                 "Enemy"
#define AI_SCRIPT_DEAD_PLAY             "deadplay"
#define AI_SCRIPT_APPRAR                "appear"
#define AI_SCRIPT_APP_START             "appstart"
#define AI_SCRIPT_APP_END               "append"
#define AI_SCRIPT_ENEMY_DONE            "EnemyDone"
#define AI_SCRIPT_CATCH_PER             "catchper"
#define AI_SCRIPT_ALL_LOOT_HP_PER       "allloothpper"
 

// 任务脚本函数
#define TASK_SCRIPT_FUNC_CANACCEPT       "CanAccept"
#define TASK_SCRIPT_FUNC_ONACCEPT        "OnAccept"
#define TASK_SCRIPT_FUNC_ONFINISH        "OnFinish"
#define TASK_SCRIPT_FUNC_ONFULFILL       "OnFulfill"
#define TASK_SCRIPT_FUNC_ONSTEP1         "OnStep1"
#define TASK_SCRIPT_FUNC_ONSTEP2         "OnStep2"
#define TASK_SCRIPT_FUNC_ONSTEP3         "OnStep3"
#define TASK_SCRIPT_FUNC_ONSTEP4         "OnStep4"
#define TASK_SCRIPT_FUNC_ONSTEP5         "OnStep5"
#define TASK_SCRIPT_FUNC_ONSTEP6         "OnStep6"
#define TASK_SCRIPT_FUNC_GETMAINTASKEXP  "GetMainTaskExp"
#define TASK_SCRIPT_FUNC_GETSUBTASKEXP   "GetSubTaskExp"
#define TASK_SCRIPT_FUNC_TIMEOUT         "OnTimeOut"
#define TASK_SCRIPT_FUNC_CANCEL          "OnCancel"
#define TASK_SCRIPT_FUNC_ACCEPTCYCLE     "OnAcceptCycle"
#define TASK_SCRIPT_FUNC_FINISHCYCLE     "OnFinishCycle"
#define TASK_SCRIPT_FUNC_VISIBLE         "CanVisible"
#define TASK_SCRIPT_FUNC_GETEXP          "GetExp"

// 场景物件脚本函数
#define THING_SCRIPT_FUNC_CANLOOT         "CanLoot"
#define THING_SCRIPT_FUNC_ONLOOTED        "OnLooted"
#define THING_SCRIPT_FUNC_CANTRIGGER      "CanTrigger"
#define THING_SCRIPT_FUNC_TRIGGEREFFECT   "TriggerEffect"
#define THING_SCRIPT_FUNC_CANLOOTSTART    "CanLootStart"
#define THING_SCRIPT_FUNC_KILLED          "Onkilled"
#define THING_SCRIPT_FUNC_ENTERSCENE      "EnterScene"
#define THING_SCRIPT_FUNC_LOOTING         "OnLooting"

#define MAX_MOUNT_LEVEL_PER_QULITY    10  //坐骑每阶最大等级


#define MAX_MATERIAL_NUM				3 //装备升级材料最大为3

#define MAX_CHECKROLE_TIMESEC   10  //场景没人上报间隔

#define TREASURE_HUNT_SUMMON_LIFESPAN  (2*60*1000)

#define MAX_MORAL_COUNT 100

#define TOWN_PORTAL_ITEM_ID   921  //回城石物品模板id

#define MAX_CHECKROLE_TIMESEC   10  //场景没人上报间隔

#define SPAWN_ITEM_BEGIN_ID 10000000

#define OFFSET(x, y) do{ memcpy(x, &y, sizeof(y));(char*)(x) += sizeof(y);} while(0)

#define MAX_EXPPER_BASE          10000  // 经验值奖励基础

#define ALIGNMENT_SIZE(val,alignment) (((val) + (alignment) - 1)/(alignment))

#define MAX_ITEM_ACTIVITY_REWARD_ITEM_COUNT 10

#define MAX_STAR_COMPENSATE_COUNT  10  //装备补偿点数星级最大值  

#endif //__MACROS_H_2014_01_09_11_11__
