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

-- Dumping structure for table characters.playerbot_saved_data
DROP TABLE IF EXISTS `playerbot_saved_data`;
CREATE TABLE IF NOT EXISTS `playerbot_saved_data` (
  `guid` int(11) unsigned NOT NULL default '0',
  `combat_order` int(11) unsigned NOT NULL default '0',
  `primary_target` int(11) unsigned NOT NULL default '0',
  `secondary_target` int(11) unsigned NOT NULL default '0',
  `pname` varchar(12) NOT NULL default '',
  `sname` varchar(12) NOT NULL default '',
  `combat_delay` int(11) unsigned NOT NULL default '0',
  `auto_follow` int(11) unsigned NOT NULL default '1',
  `autoequip` tinyint(1) NOT NULL default '0',
  PRIMARY KEY  (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Persistent Playerbot settings per alt';

-- Dumping data for table characters.playerbot_saved_data: 0 rows
DELETE FROM `playerbot_saved_data`;
/*!40000 ALTER TABLE `playerbot_saved_data` DISABLE KEYS */;
/*!40000 ALTER TABLE `playerbot_saved_data` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
