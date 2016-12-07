#ifndef _Server_ProtoHeader_H_
#define _Server_ProtoHeader_H_

/// ��������֮�����PIPEͨ��ʱ��BusinessID����, �����ĩβ����µġ�
enum EBusinessID
{
    COMMON_BUSINESS_ID,     // ����ҵ��, ������Ϸ���ܵ��߼���������������
    TUNNEL_BUSINESS_ID,     // �������ҵ��, ר�Ź����Э��ʹ��
    STATUS_BUSINESS_ID,     // ���������ݲɼ��㱨��ҵ��
    _MANAGE_BUSINESS_ID,     // �������ҵ���Ƿ��Ҫ��ȷ��

    SERVERBUSINESS_SIZE ,  /// �ܵĴ�С
};

/// ����Pipe��Typeֵ
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
