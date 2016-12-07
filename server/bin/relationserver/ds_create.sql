/*
MySQL Data Transfer
Source Host: localhost
Source Database: ds_relation
Target Host: localhost
Target Database: ds_relation
Date: 2014-2-20 17:28:41
*/
DROP DATABASE IF EXISTS `ds_relation`;
CREATE DATABASE IF NOT EXISTS `ds_relation`;

use `ds_relation`;

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for role
-- ----------------------------
CREATE TABLE if not exists `rs_role` (
  `roleid` bigint(20) NOT NULL DEFAULT '0',
  `name` varchar(64) NOT NULL,
  `data` mediumblob,
  PRIMARY KEY (`roleid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for role
-- ----------------------------
CREATE TABLE if not exists `rs_activity` (
  
  `actid` bigint(20) NOT NULL DEFAULT '0',
  
  `data` mediumblob,
  
  PRIMARY KEY (`actid`)

) ENGINE=InnoDB DEFAULT CHARSET=utf8;



-- ----------------------------
-- Table structure for mail
-- ----------------------------
CREATE TABLE IF NOT EXISTS `mail` (
  `mailid` bigint(20) NOT NULL,
  `type` tinyint(4) NOT NULL,
  `getmoneytime` int(10) NOT NULL DEFAULT '0',
  `getitemtime` int(10) NOT NULL DEFAULT '0',
  `receiverid` bigint(20) NOT NULL,
  `money` int(10) NOT NULL DEFAULT '0',
  `sendtime` int(10) NOT NULL DEFAULT '0',
  `readtime` int(10) NOT NULL DEFAULT '0',
  `deletetime` int(10) NOT NULL DEFAULT '0',
  `sender` varchar(40) CHARACTER SET utf8 NOT NULL,
  `receiver` varchar(40) CHARACTER SET utf8 NOT NULL,
  `title` varchar(100) CHARACTER SET utf8 NOT NULL,
  `content` varchar(3000) CHARACTER SET utf8 NOT NULL,
  `item1` varchar(1000) NOT NULL,
  `item2` varchar(1000) NOT NULL,
  `item3` varchar(1000) NOT NULL,
  `item4` varchar(1000) NOT NULL,
  `item5` varchar(1000) NOT NULL,
  PRIMARY KEY (`mailid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


-- ----------------------------
-- Table structure for PVP
-- ----------------------------
CREATE TABLE IF NOT EXISTS `PVP` (
  `roleid` bigint(20) NOT NULL DEFAULT '0',
  `data` mediumblob,
  `roleinfo` varchar(1024) DEFAULT NULL,
  PRIMARY KEY (`roleid`)  
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


-- ----------------------------
-- Table structure for PVP
-- ----------------------------
CREATE TABLE IF NOT EXISTS `pvp_role_info` (
  `roleid` bigint(20) NOT NULL DEFAULT '0',
  `name` varchar(64) NOT NULL,
  `data` mediumblob,
  PRIMARY KEY (`roleid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


-- ----------------------------
-- Table structure for Worldboss
-- ----------------------------
CREATE TABLE IF NOT EXISTS `worldboss` (
  `id` bigint(20) NOT NULL DEFAULT '0',
  `data` mediumblob,
  `dbstatus` tinyint(1) NOT NULL DEFAULT '0',
  `bosstemplateid` int(11) NOT NULL DEFAULT '0',
  `bossstatus` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
