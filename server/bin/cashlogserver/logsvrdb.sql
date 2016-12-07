CREATE DATABASE if not exists `cashlog` default CHARACTER SET utf8 COLLATE utf8_general_ci;

use `cashlog`;

CREATE TABLE if not exists `log_error` (
	`id` bigint(20) NOT NULL AUTO_INCREMENT,
	`sql_text` mediumtext,
	`create_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
	PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS `payrecord` (
	`orderno` varchar(50) NOT NULL COMMENT '������',
	`type` tinyint(4) unsigned NOT NULL COMMENT '����,0:��׿ 1:IOS',
	`accountid` bigint(20) unsigned NOT NULL COMMENT '�ʺ�ID',
	`gameorderno` varchar(50) NOT NULL COMMENT '��Ϸ������',
	`product` varchar(50) NOT NULL COMMENT '��ƷID',
	`extend` varchar(100) NOT NULL COMMENT '��Ϸ��չ��Ϣ',
	`paytime` bigint(20) unsigned NOT NULL,
	`ip` int(11) unsigned NOT NULL,
	`md5` varchar(33) NOT NULL COMMENT 'MD5��',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��'
) ENGINE = InnoDB DEFAULT CHARSET = utf8 COMMENT = '֧��������־';

CREATE TABLE IF NOT EXISTS `dealrecord` (
	`orderno` varchar(50) NOT NULL COMMENT '������',
	`accountid` bigint(20) unsigned NOT NULL COMMENT '�ʺ�ID',
	`serverid` int(11) unsigned NOT NULL COMMENT '������ID',
	`result` tinyint(4) unsigned NOT NULL COMMENT '�������',
	`money` int(11) unsigned NOT NULL COMMENT '���γ�ֵ�Ľ�Ǯ����',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��'
) ENGINE = InnoDB DEFAULT CHARSET = utf8 COMMENT = '��������־';

CREATE TABLE IF NOT EXISTS `errrecord` (
	`orderno` varchar(50) NOT NULL COMMENT '������',
	`errtype` tinyint(4) unsigned NOT NULL COMMENT '��������',
	`gameerr` tinyint(4) unsigned NOT NULL COMMENT '��Ϸ����Ĵ�������',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��'
) ENGINE = InnoDB DEFAULT CHARSET = utf8 COMMENT = '���󶨵���־';

