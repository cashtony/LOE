/*
MySQL Data Transfer
Source Host: localhost
Source Database: ds_localmap
Target Host: localhost
Target Database: ds_localmap
Date: 2014-2-20 17:28:41
*/
DROP DATABASE IF EXISTS `ds_localmap`;
CREATE DATABASE IF NOT EXISTS `ds_localmap`;

use `ds_localmap`;

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for account
-- ----------------------------
CREATE TABLE if not exists `lm_account_info` (
  `accountid` bigint(20) NOT NULL DEFAULT '0',
  `rmbdata` mediumblob,
  `viplevel` int(10) DEFAULT '0',
  `gmlevel` int(10) DEFAULT '0',
  `cash` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`accountid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

