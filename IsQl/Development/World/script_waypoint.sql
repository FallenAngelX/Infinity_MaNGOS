-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               5.0.45-community-nt - MySQL Community Edition (GPL)
-- Server OS:                    Win32
-- HeidiSQL Version:             9.3.0.4984
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

-- Dumping structure for table mangos.script_waypoint
DROP TABLE IF EXISTS `script_waypoint`;
CREATE TABLE IF NOT EXISTS `script_waypoint` (
  `entry` mediumint(8) unsigned NOT NULL default '0' COMMENT 'creature_template entry',
  `pointid` mediumint(8) unsigned NOT NULL default '0',
  `location_x` float NOT NULL default '0',
  `location_y` float NOT NULL default '0',
  `location_z` float NOT NULL default '0',
  `waittime` int(10) unsigned NOT NULL default '0' COMMENT 'waittime in millisecs',
  `point_comment` text,
  PRIMARY KEY  (`entry`,`pointid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Script Creature waypoints';

-- Dumping data for table mangos.script_waypoint: 0 rows
DELETE FROM `script_waypoint`;
/*!40000 ALTER TABLE `script_waypoint` DISABLE KEYS */;
/*!40000 ALTER TABLE `script_waypoint` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
