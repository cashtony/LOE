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

// ��Դ�ļ�����
#define ITEM_UPGRADE_CSV               "starexp.csv"


#define MAX_TARGETPOS_NUM       8
#define MOVE_INTERVAL           500
#define BASE_INSTANCED_SCENE    1000
#define MOVE_TIMER_INTERVAL     50
#define MOVE_UPDATE_MAX_NUM     10
#define WONDERLAND_AWARD_TIME   (5 * 60)
#define M0VE_ELASTIC_MAX		3000

// ս���������id����
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


/// ʱ�任��
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

// ����ID�� ��ͬgs��objid����ͬ�����
//#define ROLEID_BASE              0
//#define ROLEID_SIZE              100000000000
//#define ROLEID_MAX               ROLEID_SIZE

#define MONSTERID_BASE           0//(ROLEID_MAX + 1)
#define MONSTERID_MAX            (MONSTERID_BASE + 100000000000)
#define MONSTERID_SIZE           (MONSTERID_MAX - MONSTERID_BASE)

#define PETID_BASE               (MONSTERID_MAX + 1)
#define PETID_MAX                (PETID_BASE + 100000000000)
#define PETID_SIZE               (PETID_MAX - PETID_BASE)


// ����ģ���һЩ����
#define TEMPLATE_IP_ADDRESS_LENGTH	16
#define TEMPLATE_MAX_PATH_LENGTH	128
#define	TEMPLATE_MAX_CHAR			20480
#define TEMPLATE_MAX_STATE          5
#define TEMPLATE_MAX_AIACTION       10        // ÿ��AI״̬����AI������Ϊ��
#define TEMPLATE_MAX_TRIGEVENT      5
#define	TEMPLATE_MAX_MONSTER_ITEM	16
#define	TEMPLATE_MAX_MONSTER_SKILL	8
#define MAX_LEVEL                   256
#define MAX_HEAVEN                  30        /// ��30��ע���.
#define MAX_ROLLWAIT_TIME           (30 * 1000)

// tolua_end

#define MAPPING_LOG_LOOP_NUM		512
#define MAPPING_LOG_CHECK_ID		0x12345678



// Attack Operate
#define PI                          3.1416f
#define ANGLE_INT_MAX               360
#define ANGLE_FLOAT_TO_INT          57.2958f
#define ANGLE_INT_TO_FLOAT          0.01745f
#define MIN_ATTACK_ANGLE            (-PI/2)   // ������С�Ƕ�
#define MAX_ATTACK_ANGLE            (PI/2)    // �������Ƕ�
#define MIN_SNEAK_ANGLE             (-PI/3)   // ͵Ϯ��С�Ƕ�
#define MAX_SNEAK_ANGLE             (PI/3)    // ͵Ϯ���Ƕ�
#define MIN_BLOCK_ANGLE             (-PI/2)   // ����С�Ƕ�
#define MAX_BLOCK_ANGLE             (PI/2)    // �����Ƕ� 
#define MIN_REVISE_ANGLE            (-PI/18)  // ���﹥���Ƕ�������С�Ƕ�
#define MAX_REVISE_ANGLE            (PI/18)   // ���﹥���Ƕ��������Ƕ�
#define ATK_ORI_CORRECT             10          // ׷���Ƕ�����,��ֹ׷��ʱ����һ��
#define ATK_DIS_CORRECT             500         // ׷����������,��ֹ׷��ʱ����һ��
#define AI_CHASE_SEAT_INTERVAL      18          // ׷���˼��
#define AI_CHASE_SEAT_NUM           (ANGLE_INT_MAX/AI_CHASE_SEAT_INTERVAL) ///׷���˼��
#define AI_BY_RAIDING_RANGE         5000      // ���ﱻϮ����Ӧ��Χ
#define AI_CALL_HELP_RANGE          5000      // ������ȷ�Χ
#define AI_CALL_HELP_MORE_RANGE     15000     // ����������ȷ�Χ
#define AI_JUGDE_ROLE_SPEED         4         // ������������ٶ�(����)
#define AI_GOBACK_RESUME_TIME       1000      // ���ﷵ�ػظ�ʱ����
#define AI_GOBACK_CHECK_TIME		6000      // ���ﷵ�ؼ��ʱ����
#define AI_CHECK_ENMITY_TIME        8000      // �����л���޶����
#define AI_ESCAPE_MAX_RANGE         16000     // �������ܾ��뵱ǰ��Զ����
#define AI_COMA_LAST_TIME           10000     // �������ʱ��
#define AI_COMA_PLAY_TIME           16000     // ��ʬʱ��
#define AI_ENMITY_OT_VALUE          12/10     // OTϵ��
#define IMPROVE_SKILL_MAX_TIME      10        // �����书����
#define AI_ATTACK_WAIT_TIME         300       // ׷�������ȴ���ʼ������ʱ��
#define AI_CHASE_WAIT_TIME          1800      // ׷��ʱ����
#define AI_UNCHASE_WAIT_TIME        10000     // ׷�������ĵȴ�ʱ��
#define AI_UNCHASE_OTAL_SECOND		24     // ׷���������ۼ�ʱ��
#define AI_BOSS_LAMPOON_TIME        5000      // BOSSսά�ֳ��ʱ��
#define AI_STAND_NATK_CHECK_TIME	1000

#define GET_SKILL_POINT_LEVEL       1         // ÿ�����ٵȼ��õ�һ�����ܵ�

#define MIN_CHANGE_ATTACK_MODE_LEVEL 35       // �ܸı乥��ģʽ�ĵȼ�
#define MIN_DEAD_PK_PROTECT_TIME    3         // ���ٴ���������pk��������
#define PK_PROTECT_BUFF_ID          111       // ��������buffid0
#define GM_CONCEAL_BUFF_ID          135       // ����    
#define FUDI_MULTIPLE_BUFF_ID       116       // ���縣��˫����
#define FUDI_ADD_MAX_EXP_BUFF_ID    117       // ���縣�����޷�

#define PHY_ATTACK_ACTION_TIME      0         // ��ͨ��������ʱ�� ms
#define PHY_EQUIP_WEAPON_TIME       800       // װ����������Ķ���ʱ�� ms
#define PHY_ATTACK_TIMER            100       // ��ͨ����UPDATEʱ�� ms
#define EFFECT_DELAY_TIMER          50       // Ч����ʱUPDATEʱ�� ms

#define ATTACK_SKILL_ID_COMMOM      1         // ��ͨ������(��ս����)
#define ATTACK_SKILL_ID_FIRE        2         // ���(����)
#define ATTACK_SKILL_ID_CAST        3         // Ͷ��(����)
#define ATTACK_SKILL_ID_BACK        4         // ����

#define MAX_BATTLE_VS_FORCE_COUNT   2         // ս�������������
#define MAX_BATTLE_VS_EXP_AWARD_NUM	10			///ǰ10����ȡ����

#define MAX_ITEM_RESET_COST_COUNT   10        // ϴ���������ô������ֵ 

#define MAX_ITEM_LOCK_HEAD_COUNT    4         // ϴ�����������ͷ��

//������
#define MOUNT_SKILL_ID_RIDE			102       // ������ID
#define MOUNT_SKILL_ID_UNRIDE		103       // ������ID

//�����سǼ���
#define DEATHREVIVE         119

//��Ʊģ��id
#define LOTTERY_TICKET_TEMPLATE_ID  0

//------------------------------------------------------------------------
// ע��: ����ˡ��ͻ��˵Ĺ��������޸�Ҫͬ��
#define SINGLE_ATTACK_DIS           3000   // ���ֹ������룬��λ����
#define TWOHAND_ATTACK_DIS          4000   // ˫�ֹ������룬��λ����
#define BOW_ATTACK_DIS              30000  // ���������룬��λ����
#define DART_ATTACK_DIS             20000  // �����������룬��λ����

#define CLIENT_SQR_SINGLE_ATTACK_DIS    9   // �ͻ�����-���ֹ������루ƽ��������λ��
#define CLIENT_SQR_TWOHAND_ATTACK_DIS   16   // �ͻ�����-˫�ֹ������루ƽ��������λ��
#define CLIENT_SQR_BOW_ATTACK_DIS       900	// �ͻ�����-���������루ƽ��������λ��
#define CLIENT_SQR_DART_ATTACK_DIS      400	// �ͻ�����-�����������루ƽ��������λ��
//------------------------------------------------------------------------
#define CYLINDER_HEIGHT_VALUE			5000
#define MALE_UNDER_WATER_HEIGHT			2000
#define FEMALE_UNDER_WATER_HEIGHT		1900

#define ATTACK_DURATION             8000   // ս��״̬ˢ��ʱ��ms
#define TICK_DURATION               5000   // ��Ѫˢ��ʱ��ms
#define TICK_LEAPVALUE_DURATION     2000   // ���Ṧֵʱ��ms
#define ALL_SKILL_COOLDOWN_TIME     1500   // ���м�����ȴʱ��ms��������ȴʱ��
#define MAX_ALL_COOLDOWN_TIME       2000   // ��󹫹�cdʱ��
#define MIN_ALL_COOLDOWN_TIME       500    // ��С����cdʱ��
#define AOE_MAX_Z_DIS				8000

#define	DEAD_COST_LEVEL_LOW         20     // ����������͵ȼ�

#define MAX_BUFF_NUM                20    
#define INVALID_BUF_NUM             0xFFFFFFFF  
#define INVALID_BUF_TIME            0xFFFFFFFF  
#define USING_LIFE_SKILL_TIME       3000 // �����ʹ��ʱ��
#define SKILL_FLY_SPEED             (200 * 200)
#define MAX_SKILL_LEVEL             10
#define MAX_WAIT_LEAP_GO            2000
#define CHARACTER_COEFFICIENT       1000
#define CREATE_ATTACK_ACTION        99
#define PHYATTACK_STOP_DELAY        2000   // ����
#define ATTACK_FAR_BLOCK_PARAM      2      // Զ�̹������񵵸���ϵ��
#define MIN_ATTACK_TIME             1000   // ��С����ʱ���� ms
#define MAX_SKILL_PREPARE_TIME      10000  // �������ʱ��
#define MIN_SKILL_PREPARE_TIME      500    // ��С����ʱ��
#define MAX_SKILL_SET_TIME          120000 // ͨ���������ʩ��ʱ��
#define MIN_SKILL_SET_TIME          500    // ͨ��������Сʩ��ʱ��
#define MAX_RELATED_SKILL_NUM       5      // �������ܵ�������
#define ONE_DAY_SECOND              86400  //һ�������
#define MIN_SKILL_FLYTIME           100    // ������С��ʱʱ��
#define MIN_FLASH_INSTANT_MOVE_TIME 200    // �������ƶ�ʱ����������ʱ��
#define SCHOOL_SKILL_MIN_ID         1000   // ���ɼ���id����������, Լ��
#define SCHOOL_SKILL_MAX_ID         100000 // ���ɼ���id����С�����, Լ��
#define CREATE_SKILL_MAX_IMPROVE_TIMES  10 // �Դ��书����������
#define CREATE_SKILL_MAX_LEVEL      12     // �Դ��书�ɽ��״���

#define PK_VALUE_PER_PERSON           100    //���һ��ɱ��ÿ��������ӵ�pkֵ
#define PK_VALUE_PER_PERSON_COMMON    50     //����ɱ��ÿ��������ӵ�pkֵ
#define PK_VALUE_REDUCE_INTERVAL      120000 // PKֵ����ʱ��2����
#define PK_VALUE_PER_MONSTER_NORMAL   5      //ÿɱ��5����ͨ�������һ��pkֵ
#define PK_VALUE_PER_MONSTER_OUTSTAND 5      //ÿɱ��5����Ӣ�������һ��pkֵ
#define PK_VALUE_PER_MONSTER_BOSS     5      //ÿɱ��5��boss������һ��pkֵ
#define MONSTER_DEAD_ROCK_DIS         5000   //�������������ɾ��� mm

#define DEAD_JIANGHU_CARD_ID          620401 //��������
#define GOLD_RECOVER_EQUIP_ITEM_ID          400005 //��ɫ���ʯ
#define NORMAL_RECOVER_EQUIP_ITEM_ID        400004 //��ͨ���ʯ

#define PK_BROWN_REMOVE_INTERVAL    15000  // ��ɫ�����Ƴ�ʱ��15��

#define WAIT_ANSWER_TIME            60000  // ��������ȴ�ʱ�� 1����
#define ROLE_DEAD_WAIT_TIME         64000  // ��ɫ�����ȴ�ʱ��
#define ROLE_DEAD_WAIT_TIME_PVP     19000  // PVPս����������ʱ��   
#define ROLE_BREATH_TIME            90000   /// ��ɫ����ʱ��
#define ROLE_BREATH_REVERT_TIME     10000   /// ��ɫ�����ָ�ʱ��
#define ROLE_BREATH_REVERT      (ROLE_BREATH_TIME/ROLE_BREATH_REVERT_TIME)   /// ��ɫ�����ָ�ʱ��
#define ROLE_DROWN_TIME             3000   /// ��ɫ��ˮ��Ѫ���
#define ROLE_DEAD_WAIT_TIME_FIGHT   14000  /// �����Ҷ������ȴ�ʱ��

#define FIGHTER_BUFF_CLASSID        1      // ƴ������buff��classid
#define FIGHTER_BUFF_MAX_LEVEL      10     // ���ȼ�
#define WEAKNESS_BUFF_ID            11     // ս��δ�����뿪ս������ң�����ų����buff ������15�������ڲ����Ŷ� ���߱���
#define BI_HAI_BATTLE_BUFF_ID       136    // �̺���Ȫ�뿪�����buff ���߱���
#define LOSER_BUFF_ID               12     // ��Դս���б����ɱ����õ�buff ���߱���
#define ABSORB_WUHUN_BUFF_ID        13     // ���Ա������buffid
#define SUMMON_WUHUN_PUBLIC_CD      3000   // ����ʱ��Ĺ���cd 3s
#define WUHUN_BEIDONG_MAX_LEVEL     6      // �������ȼ� 
#define WUHUN_NORMAL_SKILL_MAX_LEVEL   10  // ��ͨ�������ȼ� 
#define WUHUN_ADD_HUNNENG_PER_MONSTER  5   // ÿɱ��һ�������õĻ���
#define SUMMON_MONSTER_SHOW_HOST_CODE	514
#define STEP_ADD_Z_HEIGHT 2000

#define WUHUN_GOLD_BENYUAN    492000       // ���б�Դ ��ľˮ����
#define WUHUN_WOOD_BENYUAN    492001
#define WUHUN_WATER_BENYUAN   492002
#define WUHUN_FIRE_BENYUAN    492003
#define WUHUN_DUST_BENYUAN    492004

#define PK_PUTIGUO_ITEM_ID    100361       // ������ͷ����� �����

#define LIEMING_LINGWU_GET_ITEM_COUNT    200 //�������õ��������
#define LIEMING_LINGWU_CHIP_MAX_COUNT    999 //��Ƭ������
#define LIEMING_ITEM_MAX_LEVEL    8   //��Ʒ���ȼ�
#define LIEMING_ITEM_INIT_GRID_COUNT 24    //��ʼ���ٸ���
#define LIEMING_QEUIP_INIT_PAGE_COUNT 2    //��ʼ����װ��ҳǩ
#define LIEMING_ADD_EQUIP_GRID_PER_ROLE_LEVEL 5 //���ټ�����װ��һ������
#define LIEMING_ADD_EQUIP_GRID_BASE_LEVEL   45  //���ټ���ʼ��װ����

#define LEAP_JIPAO_BUFF_ID         80111     //����buffid      ������Ӱ
#define LEAP_JIPAO_WATER_BUFF_ID   80115     //ˮ�ϼ���buffid  ����̤��
#define LEAP_FLYING_BUFF_ID        80112     //Ʈ��buffid      ��������
#define LEAP_WATER_SPEED_BUFF_ID   80113     //ˮ�м���        ��Ƽ��ˮ
#define LEAP_SPEED_BUFF_ID         80114     //���м���        �������� 


#define ENTER_SCENE_BUFF_ID         99     // ���볡��ʱ��ʹ����޵е�buff

#define IMMUNITY_DEAD_BUFF_ID       41616  // ��������buffid
#define UNIMMUNITY_DEAD_BUFF_ID     41621  // ����������buffid

#define RETURN_STAND_TIME           3000   // ����վ������Ҫ��ʱ��

// duel
#define DUEL_READY_TIME             5000   // ����׼��ʱ�� 5s
#define DUEL_ALERT_TIME             5000   // ����������Χ����ʱ�� 5s
#define DUEL_DURA_TIME              300000 // ����ʱ�� 5m
#define DUEL_MIN_HP                 1      // �����������Сhp

#define DUEL_ALERT_DISTANCE         80000  //�����������
#define DUEL_ALERT_DISTANCE_SQUARE  6400000000
#define DUEL_MAX_DISTANCE           100000 //��������
#define DUEL_MAX_DISTANCE_SQUARE    10000000000 //��64λ�洢

#define NPC_DUEL_CLOSE_TIME         10000       //�д���رճ�����ʱ��
#define NPC_DUEL_BOSS_COUNT_MAX     5           //npc�д����ˢ������

//deadMark
#define DEAD_MARK_LIVE_TIME_BY_ROLE 60000     //1���� �����ɱ��ʬ����ʱ��
#define DEAD_MARK_LIVE_TIME_BY_MST  180000    //3���� ������ɱ��ʬ����ʱ��
#define DEAD_MARK_PROTECTED_TIME    120000    //2���� ������ɱ��ʬ�屣��ʱ�� ����ʱ�佫�����˶���ʰȡ
#define DEAD_MARK_AFTER_PICK        3000      //3���� ��ʰȡ�걣��ʱ��
#define DEAD_ENTER_DIFU_PER         0         //��������ظ��ĸ��� ��ʱΪ0 ��ֱ�
#define DIFU_SCENE_BASE_ID          101
#define CREATE_WORLD_SCENE_ID       43

// Resist
#define RESIST_TOTAL_TIME           30000  //ͳ��ʱ�� 30s
#define RESIST_HIT_MAX_TIMES        3      //�涨ʱ��������������
#define RESIST_IMMUNITY_TIME        10000  //����ʱ�� 10s

//AI
#define AI_ESCAPE_PERCENT_HP        0.05        // �������ܵ�HP����
#define AI_MAX_PATROLPOS_COUNT      10          // ��������Ѳ�ߵ�����
#define AI_MAX_ACTIONPARA_LEN       128         // AI����������󳤶�
#define AI_ENEMY_REFRESH_TIME       8000        // ����Ŀ��ˢ�¼��8��
#define AI_ESCAPE_SETTLE_TIME       86400000    // ���ܺ�ͣ��ʱ��
#define MAX_SKILL_PERACTION         5           // ÿ���������Ŀ�ѡ������
#define MAX_SUMMONMON_NUM           5           // ����ٻ����������
#define PET_AI_GUARD_RANGE          10000       // ���ﾯ�䷶Χ
#define PET_AI_DISPEAR_RANGE        30000       // ������ڷ�Χ
#define PET_AI_FOLLOW_WALK_RANGE    2000        // ������沽�о���
#define PET_AI_FOLLOW_RANGE         200         // ����������
#define CROWD_MONSTER_MAX           16          // ���ＯȺ��������
#define MONSTER_BIRTH_AI_TIME       6000        // �������������������ʱ�� 
#define MONSTER_CHECK_SKILL_TIME    3000        // ����ʹ�ü��ܼ��
#define MONSTER_CLICK_STICK_TIME    15000       // ����Ի����ͣ��ʱ�� 
#define EAVESDROP_CONTENT_LEN       255         // ��������Ի�����
#define MONSTER_SUMMON_DESTROY_TIME 30000       // �ٻ���������ʱ��
#define MONSTER_CONVOY_FAILED_DIS   (32 * 1000)   /// ����ʧ�ܾ���
#define MONSTER_CONVOY_FOLLOW_DIS   (2 * 1000)    // ���͸������
#define MONSTER_CONVOY_CHECK_TIME   3000        // ���ͼ��ʱ����
#define MONSTER_CONVOY_WARNING_DIS  (10 * 1000)   // ���͸������
#define MONSTER_CONVOY_PROTECTOR_DIS (50 * 1000)  // ���ͼ��ʱ����
#define PLAYER_BIRTH_POS_DIS		2500		// ��ҳ�����Χ����
#define PLAYER_ENTER_RANDOM_DIS		3000		// ��ҽ��볡�����
#define MONSTER_SUMMON_MAX_NUM		1024
#define MONSTER_ANCESTOR_MAX_NUM	3

#define BATTLE_ITEM_MEDAL_DUST   109000  // ����ѫ��
#define BATTLE_ITEM_MEDAL_POISON 109001  // �綾ѫ��
#define BATTLE_ITEM_MEDAL_SPIRIT 109006  // ����ѫ��

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

// �����
#define  MAX_USETOOL_DISTANCE       (5000*5000)               /// ʹ�ù��ߵľ���
#define  CDTIME_RELEATED_VALUE      (24*3600*365*30)        /// 30��ʱ��
#define  MAX_MATCHTOOL_NUM          5                       /// �䷽���ߵ��������
#define  CREATE_THRESHOLD           10                      /// ���д������ܵ���ֵ
#define  LEVEL_DISTANCE             6        
#define  MAX_MATCH_DES_NUM          24                      /// �䷽������������
#define  RS_FREEMATCH_NUM           3
#define  MAX_SKILLNAME_LEN          16                      // ��������ֳ���
#define  MAX_MATCHNAME_LEN          16                      // �䷽���ֳ���

//����
#define MAX_TRIGGER_EVENT_PER_ADVENTURE   5              // ÿ����������Ӧ�Ĵ����¼�

#define MAX_ITEM_NUM_PER_SET              10             // ��װ�����Ʒ��
#define MAX_AVAILABLEDINSTANCE_NUM        100            // �����п����ù��ﾭ��ֵ�ķ�Χ.
#define MAX_PERFORMANCE_TIME              (1000*60*30)   // ����ݳ�ʱ��30����
#define MAX_PERFORMANCE_SUSPEND_TIME      (1000*60*10)   // ������ʱ��10����
#define TMP_CREATE_MONSTER_APPEAR_TIME    (1000*60*3)    // ��ʱ���������ά��ʱ��
#define INVALID_ADVENTURE_ID              0xFFFFFFFF
#define INVALID_PERFORM_ID                0xFFFFFFFF
#define ADVENTURE_DROP_ITEMLIST_BASE      0

// ŭ�����ֵ
#define MAX_DRUNKEN_VALUE                 1000
// ŭ��ֵÿ��˥��

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

#define SENDEMAIL_FEE                     50              // �����ʼ�����
#define THING_TIMER                       (600 * 1000)      // ������Ʒ�Զ���ʧʱ��Ϊ10����
#define TRIP_SCENE_ASK_WAIT_TIME		  60

#define SCENE_CLEAR_TIME                  30000           // ������ͼ����timerʱ��
#define SCENE_WAIT_ROLE_TIME			  (5 * 60 * 1000)    // ���������������ʱ��
#define SCENE_MAX_SYNC_NUM				  2048

// һ��UINT32 ��2����, ǰ���UUID����ȡ
// ������GS������
#define SCENE_INSTANCED_ID_R              12
#define SCENE_INSTANCED_ID_L              20

#define ROLE_HP_TIMER                     1000       // HP��ʱ֪ͨRS 
#define ROLE_MP_TIMER                     1000       // MP��ʱ֪ͨRS

// ��ϵ��
#define CREATE_GUILD_LEVEL                 30         // ������ĵȼ�
#define REPLY_GUILD_LEVEL                  20         // ��Ӧ���ĵȼ�
#define JOIN_GUILD_LEVEL                   1

#define IS_VALID_ID(UINT32_ID)     (UINT32_ID != INVALID_32BIT_ID)

//
// !!note: �����ģ���ṩ���ͻ���ʹ��(���޸�)
//

// ��ȡ�仯��Job, ����unsigned int
#define GET_JOB(pBuf) (*(UINT32*)pBuf)

/// ��ȡ�����򽵼�����Ա
#define GET_ROLENAME(pBuf) ((const char*)pBuf)
#define GET_OLD_ROLEGUILDLEVEL(pBuf)  (*(UINT8*)((const char*)pBuf + ROLE_NAME_LEN))
#define GET_NEW_ROLEGUILDLEVEL(pBuf)  (*(UINT8*)((const char*)pBuf + ROLE_NAME_LEN + sizeof(UINT8)))
/// ���������򽵼�����Ա
#define SET_ROLEGUILDLEVEL_CHG(szData, szRoleName, byOldGuildLevelIndex, byNewGuildLevelIndex)\
    strncpy(szData, szRoleName, ROLE_NAME_LEN);\
    memcpy(szData+ ROLE_NAME_LEN, &byOldGuildLevelIndex, sizeof(UINT8));\
    memcpy(szData + ROLE_NAME_LEN + sizeof(UINT8), &byNewGuildLevelIndex, sizeof(UINT8));


/// ��ᷱ�ٶȸı�
#define GET_GUILDPROSPER(pBuf) (*((int*)pBuf))

/// ���ȼ��仯
#define GET_GUILDLEVEL(pBuf) (*((UINT16*)pBuf))


/// ���ת�ð���
#define GET_GUILDOLDLEADER(pBuf) (*((UINT64*)pBuf))
#define GET_GUILDNEWLEADER(pBuf) (*((UINT64*)(pBuf + sizeof(UINT64))))
/// ���ð����仯
#define  SET_GUILDLEADER_CHG(szData, qwOldLeaderID, qwNewLeaderID)\
    memcpy(szData, &qwOldLeaderID, sizeof(UINT64));\
    memcpy(szData + sizeof(UINT64), &qwNewLeaderID, sizeof(UINT64));


// ����Ա��ע�ı�
#define GET_GUILD_MEMBERNAME(pBuf) ((const char*)pBuf)
#define GET_GUILD_MEMBERMEMO(pBuf) ((const char*)((const char*)pBuf + ROLE_NAME_LEN))

// ���ð���Ա��ע
#define SET_GUILD_MEMBERMEMO(szData, szName, szMemo)\
    strncpy(szData, szName, ROLE_NAME_LEN);\
    strncpy(szData + ROLE_NAME_LEN , szMemo, GUILD_MEMO_LEN);\
    szData[ROLE_NAME_LEN + GUILD_MEMO_LEN] = 0;

/// �����ּ�仯
#define GET_GUILD_AIM(pBuf) ((const char*)pBuf)

/// �����Ϣ��ȡ��غ���
#define GET_GUILD_MEMO_FORUM(pBuf)   ((SGuildMemoInfo*)pBuf)->szForum
#define GET_GUILD_MEMO_CONTACT(pBuf) ((SGuildMemoInfo*)pBuf)->szContact
#define GET_GUILD_MEMO_MEMO(pBuf)    ((SGuildMemoInfo*)pBuf)->szMemo

// ����Ա�ȼ�
#define GET_GUILD_MEMBER_LEVEL(pBuf)  (*(UINT32*)pBuf)

// ����Ա��ǰ���׶�
#define GET_GUILD_MEMBER_CURDEVOTION(pBuf)  (*(UINT32*)pBuf)

// ����Ա��ǰ����׶�
#define GET_GUILD_MEMBER_MAXDEVOTION(pBuf)  (*(UINT32*)pBuf)

// ���JOB
#define GET_GUILD_MEMBER_JOB(pBuf) GET_JOB(pBuf)

// ��ȡ�����������
#define GET_GUILD_MAX_MEMBER(pBuf) (*(UINT16*)pBuf)

//
// ���ڼ������б���Ϣ�仯
//
#define GET_JOIN_GUILD_MEMBER_LEVEL(pBuf) GET_GUILD_MEMBER_LEVEL(pBuf)
#define GET_JOIN_GUILD_MEMBER_JOB(pBuf) GET_JOB(pBuf)

//
// ������Ϣ�仯
//

// �����Ƿ�������, ��RS_RESULT_YES : RS_RESULT_NO��ʾ
#define GET_FRIEND_WHETHERINGROUP(pBuf) (*(unsigned char*)pBuf)

// ��ȡ���ѵĵȼ�
#define GET_FRIEND_LEVEL(pBuf) (*(UINT32*)pBuf)

// ����Job
#define GET_FRIEND_JOB(pBuf)  (*(UINT32*)pBuf)
#define GET_FRIEND_SUBJOB(pBuf)  (*(UINT32*)(pBuf + sizeof(UINT32)))

// ��ȡ�ͺ���֮������ܶ�
#define GET_FRIEND_INTIMACY(pBuf) (*(int*)pBuf)

//
// ����������Ի�ȡ
//
// ��ȡHP, ����int
#define GET_PET_HP(pBuf) (*(int*)pBuf)

//��ȡMAXHP, ����int
#define GET_PET_MAXHP(pBuf) (*(int*)pBuf)

// ��ȡMP, ����int
#define GET_PET_MP(pBuf) (*(int*)pBuf)

//��ȡMAXMP, ����int
#define GET_PET_MAXMP(pBuf) (*(int*)pBuf)

// ���BUFF, ����SBuffDataInfo*
#define GET_PET_ADDBUF(pBuf) ((SBuffDataInfo*)pBuf)

// ɾ��BUFF, ����SBuffDataInfo*
#define GET_PET_REMOVEBUF(pBuf) ((SBuffDataInfo*)pBuf)

// ���ֻ���ʧ�ĳ���ģ��ID
#define GET_PET_FOLD_TEMPLATE_VAL(pBuf) (*((unsigned int*)pBuf))

// �Ƿ���ʧ����
#define GET_PET_FOLD_VAL(pBuf) *(int*)(pBuf + sizeof(UINT32))

// ��ȡPKCOLOR
#define GET_PKCOLOR_VAL(pBuf)  (*((unsigned char*)pBuf))

// ������һ������ʱ��
#define GET_SCHOOL_NEXT_SKILL_LEVEL_START_TIME(pBuf) (*(unsigned int*)pBuf)

// ��ǰѧϰ�ļ��ܵȼ�
#define GET_SCHOOL_STUDIED_LEVEL(pBuf) (*((unsigned char*)pBuf))

// ��ȡBUFF��Ϣ
#define GET_BUFF_OBJID(pBuf) (*(unsigned int*)pBuf)
#define GET_BUFF_ID(pBuf)    (*(unsigned int*)(pBuf+sizeof(UINT32)))
#define GET_BUFF_LAYER(pBuf) (*(unsigned char*)(pBuf+sizeof(UINT32)+sizeof(UINT32)))
#define GET_BUFF_STATE(pBuf) (*(unsigned char*)(pBuf+sizeof(UINT32)+sizeof(UINT32)+sizeof(UINT8)))

// �����任��
#define GET_CHG_INSTANCE_SCENE_ID(pBuf) (*(unsigned int*)pBuf)
#define GET_CHG_BASE_SCENE_ID(pBuf) (*(unsigned int*)(pBuf+sizeof(unsigned int)))

// ��ȡ�����˻�Ծ��
#define GET_GUILD_ACTIVE(pBuf) (*(unsigned int*)pBuf)


/// �ű�λ������
#define  SCRIPT_POS_X   "x"
#define  SCRIPT_POS_Y   "y"
#define  SCRIPT_POS_Z   "z"

#define SCRIPT_EXPORT_INCREASE          60
#define SCRIPT_STEP_SIZE                1
#define SCRIPT_START_STEP_SIZE          (1024 * 1024)

/// ��Ʒ�ű�����
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

/// �����ű�����
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

/// AI�ű�����
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
 

// ����ű�����
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

// ��������ű�����
#define THING_SCRIPT_FUNC_CANLOOT         "CanLoot"
#define THING_SCRIPT_FUNC_ONLOOTED        "OnLooted"
#define THING_SCRIPT_FUNC_CANTRIGGER      "CanTrigger"
#define THING_SCRIPT_FUNC_TRIGGEREFFECT   "TriggerEffect"
#define THING_SCRIPT_FUNC_CANLOOTSTART    "CanLootStart"
#define THING_SCRIPT_FUNC_KILLED          "Onkilled"
#define THING_SCRIPT_FUNC_ENTERSCENE      "EnterScene"
#define THING_SCRIPT_FUNC_LOOTING         "OnLooting"

#define MAX_MOUNT_LEVEL_PER_QULITY    10  //����ÿ�����ȼ�


#define MAX_MATERIAL_NUM				3 //װ�������������Ϊ3

#define MAX_CHECKROLE_TIMESEC   10  //����û���ϱ����

#define TREASURE_HUNT_SUMMON_LIFESPAN  (2*60*1000)

#define MAX_MORAL_COUNT 100

#define TOWN_PORTAL_ITEM_ID   921  //�س�ʯ��Ʒģ��id

#define MAX_CHECKROLE_TIMESEC   10  //����û���ϱ����

#define SPAWN_ITEM_BEGIN_ID 10000000

#define OFFSET(x, y) do{ memcpy(x, &y, sizeof(y));(char*)(x) += sizeof(y);} while(0)

#define MAX_EXPPER_BASE          10000  // ����ֵ��������

#define ALIGNMENT_SIZE(val,alignment) (((val) + (alignment) - 1)/(alignment))

#define MAX_ITEM_ACTIVITY_REWARD_ITEM_COUNT 10

#define MAX_STAR_COMPENSATE_COUNT  10  //װ�����������Ǽ����ֵ  

#endif //__MACROS_H_2014_01_09_11_11__
