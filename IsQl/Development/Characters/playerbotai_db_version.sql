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

-- Dumping structure for table characters.playerbotai_db_version
DROP TABLE IF EXISTS `playerbotai_db_version`;
CREATE TABLE IF NOT EXISTS `playerbotai_db_version` (
  `version` varchar(120) default NULL,
  `required_7_playerbotai_quest_autocomplete` bit(1) default NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Used DB version notes';

-- Dumping data for table characters.playerbotai_db_version: 1 rows
DELETE FROM `playerbotai_db_version`;
/*!40000 ALTER TABLE `playerbotai_db_version` DISABLE KEYS */;
INSERT INTO `playerbotai_db_version` (`version`, `required_7_playerbotai_quest_autocomplete`) VALUES
	('PlayerbotAI default database.', NULL);
/*!40000 ALTER TABLE `playerbotai_db_version` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
