CREATE DATABASE if not exists `cashctrl` default CHARACTER SET utf8 COLLATE utf8_general_ci;

use `cashctrl`;

CREATE TABLE if not exists `log_error` (
	`id`			bigint(20) NOT NULL AUTO_INCREMENT,
	`sql_text`		mediumtext,
	`create_time`		timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
	PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE if not exists `gamecash` (
	`orderno` varchar(50) NOT NULL COMMENT '������',
	`type` tinyint(4) unsigned NOT NULL COMMENT '����,0:��׿ 1:IOS',
	`accountid` bigint(20) unsigned NOT NULL COMMENT '�ʺ�ID',
	`gameorderno` varchar(50) NOT NULL COMMENT '��Ϸ������',
	`product` varchar(50) NOT NULL COMMENT '��ƷID',
	`extend` varchar(100) NOT NULL COMMENT '��Ϸ��չ��Ϣ',
	`paytime` bigint(20) unsigned NOT NULL,
	`ip` int(11) unsigned NOT NULL,
	`md5` varchar(33) NOT NULL COMMENT 'MD5��',
	`recvtime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`isdeal` tinyint(4) unsigned NOT NULL COMMENT '�Ƿ��Ѿ�����',
	`dealsvr` int(11) unsigned NOT NULL COMMENT '���������',
	`dealtime` varchar(20) NOT NULL COMMENT '����ʱ��',
	PRIMARY KEY		(`orderno`),
	KEY	`accountid`	(`accountid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;