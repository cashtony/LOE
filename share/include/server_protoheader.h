#ifndef _Server_ProtoHeader_H_
#define _Server_ProtoHeader_H_

/// 各服务器之间进行PIPE通信时的BusinessID定义, 务必在末尾添加新的。
enum EBusinessID
{
    COMMON_BUSINESS_ID,     // 基本业务, 各类游戏功能的逻辑交互均留在这里
    TUNNEL_BUSINESS_ID,     // 隧道控制业务, 专门供隧道协议使用
    STATUS_BUSINESS_ID,     // 服务器数据采集汇报等业务
    _MANAGE_BUSINESS_ID,     // 管理操作业务，是否必要待确认

    SERVERBUSINESS_SIZE ,  /// 总的大小
};

/// 各个Pipe的Type值
#define SD_CENTER_SERVER            1
#define SD_LOGIN_SERVER             2
#define SD_LOGINGATE_SERVER         3
#define SD_RS_SERVER                4
#define SD_LOCALMAP_SERVER          5
#define SD_NAME_SERVER              6
#define SD_DB_SERVER                7
#define SD_GAME_SERVER              8
#define SD_GATE_SERVER              10
#define SD_ACCOUNT_SERVER           11
#define SD_CASHCTRL_SERVER          12
#define SD_CASHLOG_SERVER           13

#define SD_UPDATE_WEB               20
#define SD_SVN_WEB                  22
#define SD_SN_SERVER                23
#define	SD_GM_SERVER				24
#define	SD_GM_GATE_SERVER			25
#define SD_RK_SERVER                26

#define SD_LOG_SERVER               28

#define SD_NOTICE_SERVER            29

#define	SD_APP_GATE_SERVER			40
#define	SD_APP_SERVER				41
#define	SD_APP_PROXY				42
#define	SD_APP_PROXY_GATE			43
#define	SD_APP_PROXY_GS				44
#define	SD_GPLUS_SERVER				45
#define	SD_PLUS_DB_SERVER			47
#define	SD_PLUS_CTRL_SERVER			48

#define SD_ROUTER_SERVER            97
#define SD_WEBSERVICE_SERVER        98
#define SD_AGENT                    99

#endif//_Server_ProtoHeader_H_
