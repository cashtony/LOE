DROP DATABASE IF EXISTS `ds_game`;
CREATE DATABASE IF NOT EXISTS `ds_game`;

use `ds_game`;

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for item
-- ----------------------------
CREATE TABLE if not exists `item` (
  `UUID` bigint(20) NOT NULL DEFAULT '0',
  `TemplateID` int(11) NOT NULL,
  `Count` int(10) unsigned NOT NULL,
  `pos` tinyint(3) NOT NULL COMMENT 'defined in headerproto.xml EItemPos',
  `roleid` bigint(20) NOT NULL,
  `ExInfo` blob COMMENT 'xml, or maybe json',
  PRIMARY KEY (`UUID`),
  KEY `idx_roleid_pos` (`pos`,`roleid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


-- ----------------------------
-- Table structure for role
-- ----------------------------
CREATE TABLE if not exists `role` (
  `DBIndex` bigint(20) NOT NULL auto_increment,
  `DBRoleId` bigint(20) NOT NULL DEFAULT '0',
  `RoleName` varchar(32) NOT NULL,
  `ptid` varchar(32) DEFAULT NULL,
  `mac` char(18) DEFAULT NULL,
  `digitid` bigint(20) DEFAULT NULL,
  `Level` int(10) NOT NULL,
  `Gender` tinyint(2) NOT NULL,
  `BaseJob` tinyint(2) NOT NULL,
  `Job` tinyint(2) NOT NULL,
  `SkinColor` tinyint(2) NOT NULL,
  `HairStyle` tinyint(2) NOT NULL,
  `SceneId` int(11) unsigned NOT NULL DEFAULT '0',
  `InstanceSceneId` int(11) unsigned NOT NULL DEFAULT '0',
  `LatestSceneId` int(11) unsigned NOT NULL DEFAULT '0',
  `LatestInstanceSceneId` int(11) unsigned NOT NULL DEFAULT '0',
  `HP` int(11) NOT NULL DEFAULT '0',
  `SP` int(11) NOT NULL DEFAULT '0',
  `EP` int(11) NOT NULL DEFAULT '0',
  `VipEP` int(11) NOT NULL DEFAULT '0',
  `AP` int(11) NOT NULL DEFAULT '0',
  `Experience` bigint(20) NOT NULL DEFAULT '0',
  `NonMoney` int(10) unsigned NOT NULL DEFAULT '0',
  `Cash` int(10) unsigned NOT NULL DEFAULT '0',
  `NonCash` int(10) unsigned NOT NULL DEFAULT '0',
  `LatestWorldChatTime` bigint(20) unsigned NOT NULL DEFAULT '0',
  `LastLoginTime` bigint(10) unsigned NOT NULL DEFAULT '0',
  `LastLogoutTime` bigint(10) unsigned NOT NULL DEFAULT '0',
  `agile` mediumtext COMMENT 'json text',
  `XData` mediumblob,
  `XData2` mediumblob,
  `XData3` mediumblob,
  `ActivityInfo` mediumblob,
  `Shop` mediumblob,
  `bindpt` tinyint(1) NOT NULL DEFAULT '0',
  `inited` tinyint(1) DEFAULT '0',
  `deleted` tinyint(1) NOT NULL DEFAULT '0',
  `createtime` varchar(64) NOT NULL,
  `deletetime` timestamp NULL DEFAULT NULL,
  `ClentCfg` varchar(512) DEFAULT NULL,
  `ForbidenTime` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`DBRoleId`),
  UNIQUE KEY `idx_rolename_unique` (`RoleName`),
  UNIQUE KEY `idx_DBIndex_unique` (`DBIndex`),
  KEY `idx_ptid` (`ptid`),
  KEY `idx_mac` (`mac`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for online
-- ----------------------------
CREATE TABLE if not exists `online` (
  `roleid` bigint(20) NOT NULL DEFAULT '0',
  `token` timestamp NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`roleid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
