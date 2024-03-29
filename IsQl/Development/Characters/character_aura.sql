-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               5.0.45-community-nt - MySQL Community Edition (GPL)
-- Server OS:                    Win32
-- HeidiSQL Version:             7.0.0.4312
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

-- Dumping structure for table characters.character_aura
DROP TABLE IF EXISTS `character_aura`;
CREATE TABLE IF NOT EXISTS `character_aura` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `caster_guid` bigint(20) unsigned NOT NULL default '0' COMMENT 'Full Global Unique Identifier',
  `item_guid` int(11) unsigned NOT NULL default '0',
  `spell` int(11) unsigned NOT NULL default '0',
  `stackcount` int(11) unsigned NOT NULL default '1',
  `remaincharges` int(11) unsigned NOT NULL default '0',
  `basepoints0` int(11) NOT NULL default '0',
  `basepoints1` int(11) NOT NULL default '0',
  `basepoints2` int(11) NOT NULL default '0',
  `periodictime0` int(11) unsigned NOT NULL default '0',
  `periodictime1` int(11) unsigned NOT NULL default '0',
  `periodictime2` int(11) unsigned NOT NULL default '0',
  `maxduration` int(11) NOT NULL default '0',
  `remaintime` int(11) NOT NULL default '0',
  `effIndexMask` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`caster_guid`,`item_guid`,`spell`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

-- Dumping data for table characters.character_aura: 0 rows
DELETE FROM `character_aura`;
/*!40000 ALTER TABLE `character_aura` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_aura` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
