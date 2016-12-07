CREATE DATABASE if not exists `%s` default CHARACTER SET utf8 COLLATE utf8_general_ci;

use `%s`;

CREATE TABLE if not exists `log_error` (
	`id` bigint(20) NOT NULL AUTO_INCREMENT,
	`sql_text` mediumtext,
	`create_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
	PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS `gs_log` (
	`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`name` varchar(20) NOT NULL COMMENT '�ʺ�',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = 'gs������־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6)
);

CREATE TABLE IF NOT EXISTS `rs_log` (
	`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`name` varchar(20) NOT NULL COMMENT '�ʺ�',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = 'rs������־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6)
);

CREATE TABLE IF NOT EXISTS `log_login_logout` (
	`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`userName` varchar(64) NOT NULL COMMENT '�ʺ�',
	`digitId` bigint(20) unsigned NOT NULL COMMENT '����id',
	`serverArea` int(11) NOT NULL COMMENT '����id',
	`serverGroup` int(11) NOT NULL COMMENT '��������id',
	`roleName` varchar(21) NOT NULL COMMENT '��ɫ��',
	`roleId` bigint(20) unsigned NOT NULL COMMENT '��ɫid',
	`roleJob` int(11) NOT NULL COMMENT '��ɫְҵ',
	`roleLevel` int(11) NOT NULL COMMENT '��ɫ�ȼ�',
	`roleMilitaryLvl` int(11) NOT NULL COMMENT '��ɫ���׵ȼ�',
	`roleVIPLvl` int(11) NOT NULL COMMENT '��ɫVIP�ȼ�',
	`ip` varchar(33) NOT NULL COMMENT 'ip',
	`type` int(11) NOT NULL COMMENT '1:���ߡ� 2:���ߡ�3�������������ߡ�4���쳣���ߡ���',
	`onlineTime` int(11) NOT NULL COMMENT '����ʱ��',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = '��½�ǳ���־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6),
	partition  p7 values in (7),
	partition  p8 values in (8),
	partition  p9 values in (9),
	partition  p10 values in (10),
	partition  p11 values in (11),
	partition  p12 values in (12),
	partition  p13 values in (13)
);

CREATE TABLE IF NOT EXISTS `log_level_challenge` (
	`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`userName` varchar(64) NOT NULL COMMENT '�ʺ�',
	`digitId` bigint(20) unsigned NOT NULL COMMENT '����id',
	`serverArea` int(11) NOT NULL COMMENT '����id',
	`serverGroup` int(11) NOT NULL COMMENT '��������id',
	`roleName` varchar(21) NOT NULL COMMENT '��ɫ��',
	`roleId` bigint(20) unsigned NOT NULL COMMENT '��ɫid',
	`roleJob` int(11) NOT NULL COMMENT '��ɫְҵ',
	`roleLevel` int(11) NOT NULL COMMENT '��ɫ�ȼ�',
	`roleMilitaryLvl` int(11) NOT NULL COMMENT '��ɫ���׵ȼ�',
	`roleVIPLvl` int(11) NOT NULL COMMENT '��ɫVIP�ȼ�',
	`levelType` int(11) NOT NULL COMMENT '�ؿ����� ��ͨģʽ-0  ��Ӣģʽ-1 ר��ģʽ-2',
	`roleAtk` int(11) NOT NULL COMMENT '����ս��',
	`startType` int(11) NOT NULL COMMENT '�������� ��ս-0��ɨ��-1',
	`startCount` int(11) NOT NULL COMMENT '�������',
	`succCount` int(11) NOT NULL COMMENT '�ɹ�����',
	`failCount` int(11) NOT NULL COMMENT 'ʧ�ܴ���',
	`reliveCount` int(11) NOT NULL COMMENT 'ԭ�ظ������',
	`passTime` int(11) NOT NULL COMMENT 'ͨ��ʱ�� ��',
	`passJudge` int(11) NOT NULL COMMENT 'ͨ������ S-0   A-1   B-2',
	`buff1` int(11) NOT NULL COMMENT ' ǿ��buff1�������',
	`buff2` int(11) NOT NULL COMMENT ' ǿ��buff2�������',
	`buff3` int(11) NOT NULL COMMENT ' ǿ��buff3�������',
	`buff4` int(11) NOT NULL COMMENT ' ǿ��buff4�������',
	`petID1` int(11) NOT NULL COMMENT ' ��սս��id',
	`petJob1` int(11) NOT NULL COMMENT ' ��սս��ְҵ',
	`petQuality1` int(11) NOT NULL COMMENT ' ��սս��Ʒ��',
	`petLevel1` int(11) NOT NULL COMMENT ' ��սս��ȼ�',
	`petUp1` int(11) NOT NULL COMMENT ' ��սս��ǿ���ȼ�',
	`petID2` int(11) NOT NULL COMMENT ' ��սս��id',
	`petJob2` int(11) NOT NULL COMMENT ' ��սս��ְҵ',
	`petQuality2` int(11) NOT NULL COMMENT ' ��սս��Ʒ��',
	`petLevel2` int(11) NOT NULL COMMENT ' ��սս��ȼ�',
	`petUp2` int(11) NOT NULL COMMENT ' ��սս��ǿ���ȼ�',
	`petID3` int(11) NOT NULL COMMENT ' ��սս��id',
	`petJob3` int(11) NOT NULL COMMENT ' ��սս��ְҵ',
	`petQuality3` int(11) NOT NULL COMMENT ' ��սս��Ʒ��',
	`petLevel3` int(11) NOT NULL COMMENT ' ��սս��ȼ�',
	`petUp3` int(11) NOT NULL COMMENT ' ��սս��ǿ���ȼ�',
	`petEffectId` int(11) NOT NULL COMMENT 'ս�����Ч��ID',
	`petChangeCount` int(11) NOT NULL COMMENT 'ս���л����� ÿ�л�һ��ս���+1�μ�����ϵͳ�Զ��л���Ҳ��',
	`AssistPetID` int(11) NOT NULL COMMENT ' ��սս��id',
	`AssistPetJob` int(11) NOT NULL COMMENT ' ��սս��ְҵ',
	`AssistPetQuality` int(11) NOT NULL COMMENT ' ��սս��Ʒ��',
	`AssistPetLevel` int(11) NOT NULL COMMENT ' ��սս��ȼ�',
	`AssistPetUp` int(11) NOT NULL COMMENT ' ��սս��ǿ���ȼ�',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = '�ؿ���ս��־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6),
	partition  p7 values in (7),
	partition  p8 values in (8),
	partition  p9 values in (9),
	partition  p10 values in (10),
	partition  p11 values in (11),
	partition  p12 values in (12),
	partition  p13 values in (13)
);

CREATE TABLE IF NOT EXISTS `log_pvp` (
	`Id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`UserName` varchar(64) NOT NULL COMMENT '�ʺ�',
	`DigitId` bigint(20) unsigned NOT NULL COMMENT '����id',
	`ServerArea` int(11) NOT NULL COMMENT '����id',
	`ServerGroup` int(11) NOT NULL COMMENT '��������id',
	`RoleName` varchar(21) NOT NULL COMMENT '��ɫ��',
	`RoleId` bigint(20) unsigned NOT NULL COMMENT '��ɫid',
	`RoleJob` int(11) NOT NULL COMMENT '��ɫְҵ',
	`RoleLevel` int(11) NOT NULL COMMENT '��ɫ�ȼ�',
	`RoleMilitaryLvl` int(11) NOT NULL COMMENT '��ɫ���׵ȼ�',
	`RoleVIPLvl` int(11) NOT NULL COMMENT '��ɫVIP�ȼ�',
	`PvpPoint` int(11) NOT NULL COMMENT 'pvp����',
	`PvpRepute` int(11) NOT NULL COMMENT 'pvp����',
	`RoleAtk` int(11) NOT NULL COMMENT 'ս����',
	`PetID1` int(11) NOT NULL COMMENT ' ��սս��id',
	`PetJob1` int(11) NOT NULL COMMENT ' ��սս��ְҵ',
	`PetQuality1` int(11) NOT NULL COMMENT ' ��սս��Ʒ��',
	`PetLevel1` int(11) NOT NULL COMMENT ' ��սս��ȼ�',
	`PetUp1` int(11) NOT NULL COMMENT ' ��սս��ǿ���ȼ�',
	`PetID2` int(11) NOT NULL COMMENT ' ��սս��id',
	`PetJob2` int(11) NOT NULL COMMENT ' ��սս��ְҵ',
	`PetQuality2` int(11) NOT NULL COMMENT ' ��սս��Ʒ��',
	`PetLevel2` int(11) NOT NULL COMMENT ' ��սս��ȼ�',
	`PetUp2` int(11) NOT NULL COMMENT ' ��սս��ǿ���ȼ�',
	`PetID3` int(11) NOT NULL COMMENT ' ��սս��id',
	`PetJob3` int(11) NOT NULL COMMENT ' ��սս��ְҵ',
	`PetQuality3` int(11) NOT NULL COMMENT ' ��սս��Ʒ��',
	`PetLevel3` int(11) NOT NULL COMMENT ' ��սս��ȼ�',
	`PetUp3` int(11) NOT NULL COMMENT ' ��սս��ǿ���ȼ�',
	`PetEffectId` int(11) NOT NULL COMMENT 'ս�����Ч��ID',
	`OtherRoleId` bigint(20) unsigned NOT NULL COMMENT '����ս�߽�ɫid',
	`OtherRoleName` varchar(21) NOT NULL COMMENT '����ս�߽�ɫ��',
	`OtherRoleJob` int(11) NOT NULL COMMENT '����ս�߽�ɫְҵ',
	`OtherRoleLevel` int(11) NOT NULL COMMENT '����ս�߽�ɫ�ȼ�',
	`OtherRoleMilitaryLvl` int(11) NOT NULL COMMENT '����ս�߽�ɫ���׵ȼ�',
	`OtherPvpPoint` int(11) NOT NULL COMMENT '����ս��pvp����',
	`OtherRoleAtk` int(11) NOT NULL COMMENT '����ս��ս����',
	`OtherPetID1` int(11) NOT NULL COMMENT '����ս�� ��սս��id',
	`OtherPetJob1` int(11) NOT NULL COMMENT '����ս�� ��սս��ְҵ',
	`OtherPetQuality1` int(11) NOT NULL COMMENT '����ս�� ��սս��Ʒ��',
	`OtherPetLevel1` int(11) NOT NULL COMMENT '����ս�� ��սս��ȼ�',
	`OtherPetUp1` int(11) NOT NULL COMMENT '����ս�� ��սս��ǿ���ȼ�',
	`OtherPetID2` int(11) NOT NULL COMMENT '����ս�� ��սս��id',
	`OtherPetJob2` int(11) NOT NULL COMMENT '����ս�� ��սս��ְҵ',
	`OtherPetQuality2` int(11) NOT NULL COMMENT '����ս�� ��սս��Ʒ��',
	`OtherPetLevel2` int(11) NOT NULL COMMENT '����ս�� ��սս��ȼ�',
	`OtherPetUp2` int(11) NOT NULL COMMENT '����ս�� ��սս��ǿ���ȼ�',
	`OtherPetID3` int(11) NOT NULL COMMENT '����ս�� ��սս��id',
	`OtherPetJob3` int(11) NOT NULL COMMENT '����ս�� ��սս��ְҵ',
	`OtherPetQuality3` int(11) NOT NULL COMMENT '����ս�� ��սս��Ʒ��',
	`OtherPetLevel3` int(11) NOT NULL COMMENT '����ս�� ��սս��ȼ�',
	`OtherPetUp3` int(11) NOT NULL COMMENT '����ս�� ��սս��ǿ���ȼ�',
	`OtherPetEffectId` int(11) NOT NULL COMMENT '����ս�� ս�����Ч��ID',
	`Result` int(11) NOT NULL COMMENT '��ս��ʤ��-1   ��ս��ʧ��-0',
	`PointAfter` int(11) NOT NULL COMMENT '��¼��ս�����-��ս�����',
	`ReputeAfter` int(11) NOT NULL COMMENT '��¼��ս������-��ս������',
	`Timeout` int(11) NOT NULL COMMENT '�Ƿ�ʱ��ľ����� ��-0  ��-1',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`Id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = 'pvp��־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6),
	partition  p7 values in (7),
	partition  p8 values in (8),
	partition  p9 values in (9),
	partition  p10 values in (10),
	partition  p11 values in (11),
	partition  p12 values in (12),
	partition  p13 values in (13)
);

CREATE TABLE IF NOT EXISTS `log_card` (
	`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`userName` varchar(64) NOT NULL COMMENT '�ʺ�',
	`digitId` bigint(20) unsigned NOT NULL COMMENT '����id',
	`serverArea` int(11) NOT NULL COMMENT '����id',
	`serverGroup` int(11) NOT NULL COMMENT '��������id',
	`roleName` varchar(21) NOT NULL COMMENT '��ɫ��',
	`roleId` bigint(20) unsigned NOT NULL COMMENT '��ɫid',
	`roleJob` int(11) NOT NULL COMMENT '��ɫְҵ',
	`roleLevel` int(11) NOT NULL COMMENT '��ɫ�ȼ�',
	`roleMilitaryLvl` int(11) NOT NULL COMMENT '��ɫ���׵ȼ�',
	`roleVIPLvl` int(11) NOT NULL COMMENT '��ɫVIP�ȼ�',
	`type` int(11) NOT NULL COMMENT '��ȡ��λ �͵�-0  �ߵ�-1',
	`free` int(11) NOT NULL COMMENT '�����Ƿ�Ϊ��ѳ�ȡ �͵���ȡ-0  ��ѳ�ȡ-1  ���ѳ�ȡ-2',
	`freeCountToday` int(11) NOT NULL COMMENT '���γ�ȡ�Ǳ���λ���յڼ�����ѳ�ȡ ����Ǹ��ѳ�ȡ�������0',
	`tenSelect` int(11) NOT NULL COMMENT '�Ƿ�Ϊʮ���� ��-0  ��-1',
	`petTemplateId` int(11) NOT NULL COMMENT '��ȡս��ģ��ID',
	`petQuality` int(11) NOT NULL COMMENT '��ȡս��Ʒ�� Ʒ��ID����ɫ-1 ��ɫ-2 ��ɫ-3 ��ɫ-4 ��ɫ-5',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = '�鿨��־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6),
	partition  p7 values in (7),
	partition  p8 values in (8),
	partition  p9 values in (9),
	partition  p10 values in (10),
	partition  p11 values in (11),
	partition  p12 values in (12),
	partition  p13 values in (13)
);

CREATE TABLE IF NOT EXISTS `log_cash` (
	`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`userName` varchar(64) NOT NULL COMMENT '�ʺ�',
	`digitId` bigint(20) unsigned NOT NULL COMMENT '����id',
	`serverArea` int(11) NOT NULL COMMENT '����id',
	`serverGroup` int(11) NOT NULL COMMENT '��������id',
	`roleName` varchar(21) NOT NULL COMMENT '��ɫ��',
	`roleId` bigint(20) unsigned NOT NULL COMMENT '��ɫid',
	`roleJob` int(11) NOT NULL COMMENT '��ɫְҵ',
	`roleLevel` int(11) NOT NULL COMMENT '��ɫ�ȼ�',
	`roleMilitaryLvl` int(11) NOT NULL COMMENT '��ɫ���׵ȼ�',
	`roleVIPLvl` int(11) NOT NULL COMMENT '��ɫVIP�ȼ�',
	`type` int(11) NOT NULL COMMENT '����-0������-1���һ�-2',
	`approach` int(11) NOT NULL COMMENT '����/���ľ���;�� ',
	`info1` int(11) NOT NULL COMMENT '����1',
	`info2` int(11) NOT NULL COMMENT '����2',
	`info3` int(11) NOT NULL COMMENT '����3',
	`count` int(11) NOT NULL COMMENT '����',
	`exchangeOrderId` int(11) NOT NULL COMMENT '�һ�����ID',
	`exchangeProductId` int(11) NOT NULL COMMENT '�һ���ƷID',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = '������־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6),
	partition  p7 values in (7),
	partition  p8 values in (8),
	partition  p9 values in (9),
	partition  p10 values in (10),
	partition  p11 values in (11),
	partition  p12 values in (12),
	partition  p13 values in (13)
);

CREATE TABLE IF NOT EXISTS `log_money` (
	`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`userName` varchar(64) NOT NULL COMMENT '�ʺ�',
	`digitId` bigint(20) unsigned NOT NULL COMMENT '����id',
	`serverArea` int(11) NOT NULL COMMENT '����id',
	`serverGroup` int(11) NOT NULL COMMENT '��������id',
	`roleName` varchar(21) NOT NULL COMMENT '��ɫ��',
	`roleId` bigint(20) unsigned NOT NULL COMMENT '��ɫid',
	`roleJob` int(11) NOT NULL COMMENT '��ɫְҵ',
	`roleLevel` int(11) NOT NULL COMMENT '��ɫ�ȼ�',
	`roleMilitaryLvl` int(11) NOT NULL COMMENT '��ɫ���׵ȼ�',
	`roleVIPLvl` int(11) NOT NULL COMMENT '��ɫVIP�ȼ�',
	`type` int(11) NOT NULL COMMENT '����-0������-1',
	`approach` int(11) NOT NULL COMMENT '����/���ľ���;�� ',
	`info1` int(11) NOT NULL COMMENT '����1',
	`info2` int(11) NOT NULL COMMENT '����2',
	`info3` int(11) NOT NULL COMMENT '����3',
	`count` int(11) NOT NULL COMMENT '����',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = '��Ǯ��־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6),
	partition  p7 values in (7),
	partition  p8 values in (8),
	partition  p9 values in (9),
	partition  p10 values in (10),
	partition  p11 values in (11),
	partition  p12 values in (12),
	partition  p13 values in (13)
);

CREATE TABLE IF NOT EXISTS `log_item` (
	`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`userName` varchar(64) NOT NULL COMMENT '�ʺ�',
	`digitId` bigint(20) unsigned NOT NULL COMMENT '����id',
	`serverArea` int(11) NOT NULL COMMENT '����id',
	`serverGroup` int(11) NOT NULL COMMENT '��������id',
	`roleName` varchar(21) NOT NULL COMMENT '��ɫ��',
	`roleId` bigint(20) unsigned NOT NULL COMMENT '��ɫid',
	`roleJob` int(11) NOT NULL COMMENT '��ɫְҵ',
	`roleLevel` int(11) NOT NULL COMMENT '��ɫ�ȼ�',
	`roleMilitaryLvl` int(11) NOT NULL COMMENT '��ɫ���׵ȼ�',
	`roleVIPLvl` int(11) NOT NULL COMMENT '��ɫVIP�ȼ�',
	`itemName` varchar(256) NOT NULL COMMENT '��Ʒ����',
	`itemType` int(11) NOT NULL COMMENT '����orս����Ʒ ����-0��ս��-1',
	`class` int(11) NOT NULL COMMENT '��Ʒ���� ����-0��ñ��-1������-2������-3����װ-4������-5����ָ-6����Ʒ-7������-8������-9�����-20����ʯ-40������-60',
	`subClass` int(11) NOT NULL COMMENT '��ƷС��',
	`quility` int(11) NOT NULL COMMENT 'Ʒ�� ��-0����-1����-2����-3����-4����-5',
	`uuid` bigint(20) unsigned NOT NULL COMMENT 'ʵ�������߶���Ҫ��ΨһID',
	`templateId` int(11) NOT NULL COMMENT '���߾����ģ��ID',
	`type` int(11) NOT NULL COMMENT ' ����/���ģ��������֣� ����-0������-1',
	`approach` int(11) NOT NULL COMMENT '����/����;��',
	`info1` int(11) NOT NULL COMMENT '����1',
	`info2` int(11) NOT NULL COMMENT '����2',
	`info3` int(11) NOT NULL COMMENT '����3',
	`count` int(11) NOT NULL COMMENT '����',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = '������־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6),
	partition  p7 values in (7),
	partition  p8 values in (8),
	partition  p9 values in (9),
	partition  p10 values in (10),
	partition  p11 values in (11),
	partition  p12 values in (12),
	partition  p13 values in (13)
);

CREATE TABLE IF NOT EXISTS `log_resource` (
	`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`userName` varchar(64) NOT NULL COMMENT '�ʺ�',
	`digitId` bigint(20) unsigned NOT NULL COMMENT '����id',
	`serverArea` int(11) NOT NULL COMMENT '����id',
	`serverGroup` int(11) NOT NULL COMMENT '��������id',
	`roleName` varchar(21) NOT NULL COMMENT '��ɫ��',
	`roleId` bigint(20) unsigned NOT NULL COMMENT '��ɫid',
	`roleJob` int(11) NOT NULL COMMENT '��ɫְҵ',
	`roleLevel` int(11) NOT NULL COMMENT '��ɫ�ȼ�',
	`roleMilitaryLvl` int(11) NOT NULL COMMENT '��ɫ���׵ȼ�',
	`roleVIPLvl` int(11) NOT NULL COMMENT '��ɫVIP�ȼ�',
	`type` int(11) NOT NULL COMMENT '��Դ���� ����-0������ˮ��-1������-2������ֵ-3������-4',
	`approach` int(11) NOT NULL COMMENT '����/���ľ���;�� ',
	`info1` int(11) NOT NULL COMMENT '����1',
	`info2` int(11) NOT NULL COMMENT '����2',
	`info3` int(11) NOT NULL COMMENT '����3',
	`count` int(11) NOT NULL COMMENT '����',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = '��Դ��־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6),
	partition  p7 values in (7),
	partition  p8 values in (8),
	partition  p9 values in (9),
	partition  p10 values in (10),
	partition  p11 values in (11),
	partition  p12 values in (12),
	partition  p13 values in (13)
);

CREATE TABLE IF NOT EXISTS `log_activity` (
	`id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '������ID',
	`userName` varchar(64) NOT NULL COMMENT '�ʺ�',
	`digitId` bigint(20) unsigned NOT NULL COMMENT '����id',
	`serverArea` int(11) NOT NULL COMMENT '����id',
	`serverGroup` int(11) NOT NULL COMMENT '��������id',
	`roleName` varchar(21) NOT NULL COMMENT '��ɫ��',
	`roleId` bigint(20) unsigned NOT NULL COMMENT '��ɫid',
	`roleJob` int(11) NOT NULL COMMENT '��ɫְҵ',
	`roleLevel` int(11) NOT NULL COMMENT '��ɫ�ȼ�',
	`roleMilitaryLvl` int(11) NOT NULL COMMENT '��ɫ���׵ȼ�',
	`roleVIPLvl` int(11) NOT NULL COMMENT '��ɫVIP�ȼ�',
	`type` int(11) NOT NULL COMMENT '����� ÿ������-0��ÿ��ǩ��-1���ɳ�����-2��������ʳ����������',
	`count` int(11) NOT NULL COMMENT '�������� ',
	`createtime` bigint(20) unsigned NOT NULL COMMENT '����ʱ��',
	`savetime` varchar(20) NOT NULL COMMENT '����ʱ��',
	`weekday` int(11)  COMMENT 'week�����',
	PRIMARY KEY (`id`,`weekday`)
) ENGINE = MyISAM DEFAULT CHARSET = utf8 COMMENT = '�������־'
partition by list(weekday)(
	partition  p0 values in (0),
	partition  p1 values in (1),
	partition  p2 values in (2),
	partition  p3 values in (3),
	partition  p4 values in (4),
	partition  p5 values in (5),
	partition  p6 values in (6),
	partition  p7 values in (7),
	partition  p8 values in (8),
	partition  p9 values in (9),
	partition  p10 values in (10),
	partition  p11 values in (11),
	partition  p12 values in (12),
	partition  p13 values in (13)
);
