CREATE DATABASE if not exists `cashctrl` default CHARACTER SET utf8 COLLATE utf8_general_ci;

use `cashctrl`;

CREATE TABLE if not exists `log_error` (
	`id`			bigint(20) NOT NULL AUTO_INCREMENT,
	`sql_text`		mediumtext,
	`create_time`		timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
	PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE if not exists `gamecash` (
	`orderno` varchar(50) NOT NULL COMMENT '定单号',
	`type` tinyint(4) unsigned NOT NULL COMMENT '类型,0:安卓 1:IOS',
	`accountid` bigint(20) unsigned NOT NULL COMMENT '帐号ID',
	`gameorderno` varchar(50) NOT NULL COMMENT '游戏定单号',
	`product` varchar(50) NOT NULL COMMENT '产品ID',
	`extend` varchar(100) NOT NULL COMMENT '游戏扩展信息',
	`paytime` bigint(20) unsigned NOT NULL,
	`ip` int(11) unsigned NOT NULL,
	`md5` varchar(33) NOT NULL COMMENT 'MD5码',
	`recvtime` varchar(20) NOT NULL COMMENT '接收时间',
	`isdeal` tinyint(4) unsigned NOT NULL COMMENT '是否已经处理',
	`dealsvr` int(11) unsigned NOT NULL COMMENT '处理服务器',
	`dealtime` varchar(20) NOT NULL COMMENT '处理时间',
	PRIMARY KEY		(`orderno`),
	KEY	`accountid`	(`accountid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;