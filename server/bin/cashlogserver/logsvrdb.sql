CREATE DATABASE if not exists `cashlog` default CHARACTER SET utf8 COLLATE utf8_general_ci;

use `cashlog`;

CREATE TABLE if not exists `log_error` (
	`id` bigint(20) NOT NULL AUTO_INCREMENT,
	`sql_text` mediumtext,
	`create_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
	PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS `payrecord` (
	`orderno` varchar(50) NOT NULL COMMENT '定单号',
	`type` tinyint(4) unsigned NOT NULL COMMENT '类型,0:安卓 1:IOS',
	`accountid` bigint(20) unsigned NOT NULL COMMENT '帐号ID',
	`gameorderno` varchar(50) NOT NULL COMMENT '游戏定单号',
	`product` varchar(50) NOT NULL COMMENT '产品ID',
	`extend` varchar(100) NOT NULL COMMENT '游戏扩展信息',
	`paytime` bigint(20) unsigned NOT NULL,
	`ip` int(11) unsigned NOT NULL,
	`md5` varchar(33) NOT NULL COMMENT 'MD5码',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '产生时间',
	`savetime` varchar(20) NOT NULL COMMENT '保存时间'
) ENGINE = InnoDB DEFAULT CHARSET = utf8 COMMENT = '支付定单日志';

CREATE TABLE IF NOT EXISTS `dealrecord` (
	`orderno` varchar(50) NOT NULL COMMENT '定单号',
	`accountid` bigint(20) unsigned NOT NULL COMMENT '帐号ID',
	`serverid` int(11) unsigned NOT NULL COMMENT '服务器ID',
	`result` tinyint(4) unsigned NOT NULL COMMENT '结果类型',
	`money` int(11) unsigned NOT NULL COMMENT '本次充值的金钱花费',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '产生时间',
	`savetime` varchar(20) NOT NULL COMMENT '保存时间'
) ENGINE = InnoDB DEFAULT CHARSET = utf8 COMMENT = '处理定单日志';

CREATE TABLE IF NOT EXISTS `errrecord` (
	`orderno` varchar(50) NOT NULL COMMENT '定单号',
	`errtype` tinyint(4) unsigned NOT NULL COMMENT '错误类型',
	`gameerr` tinyint(4) unsigned NOT NULL COMMENT '游戏定义的错误类型',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '产生时间',
	`savetime` varchar(20) NOT NULL COMMENT '保存时间'
) ENGINE = InnoDB DEFAULT CHARSET = utf8 COMMENT = '错误定单日志';

