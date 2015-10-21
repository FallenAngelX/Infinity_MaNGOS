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

-- Dumping structure for table mangos.game_event_quest
DROP TABLE IF EXISTS `game_event_quest`;
CREATE TABLE IF NOT EXISTS `game_event_quest` (
  `quest` mediumint(8) unsigned NOT NULL default '0' COMMENT 'entry from quest_template',
  `event` smallint(5) unsigned NOT NULL default '0' COMMENT 'entry from game_event',
  PRIMARY KEY  (`quest`,`event`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Game event system';

-- Dumping data for table mangos.game_event_quest: 38 rows
DELETE FROM `game_event_quest`;
/*!40000 ALTER TABLE `game_event_quest` DISABLE KEYS */;
INSERT INTO `game_event_quest` (`quest`, `event`) VALUES
	(171, 10),
	(172, 10),
	(1468, 10),
	(8356, 12),
	(8860, 6),
	(8861, 6),
	(8980, 8),
	(8981, 8),
	(8983, 8),
	(8993, 8),
	(9024, 8),
	(9025, 8),
	(9027, 8),
	(10942, 10),
	(10943, 10),
	(10968, 10),
	(11356, 12),
	(11357, 12),
	(11441, 26),
	(11446, 26),
	(11970, 1),
	(11971, 1),
	(12752, 17),
	(12753, 17),
	(12772, 17),
	(12775, 17),
	(12777, 17),
	(12782, 17),
	(12783, 17),
	(12784, 17),
	(12808, 17),
	(12811, 17),
	(13484, 28),
	(14022, 37),
	(14036, 37),
	(24803, 24),
	(24806, 24),
	(24806, 40);
/*!40000 ALTER TABLE `game_event_quest` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
