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

-- Dumping structure for table mangos.mail_level_reward
DROP TABLE IF EXISTS `mail_level_reward`;
CREATE TABLE IF NOT EXISTS `mail_level_reward` (
  `level` tinyint(3) unsigned NOT NULL default '0',
  `raceMask` mediumint(8) unsigned NOT NULL default '0',
  `mailTemplateId` mediumint(8) unsigned NOT NULL default '0',
  `senderEntry` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`level`,`raceMask`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Mail System';

-- Dumping data for table mangos.mail_level_reward: 24 rows
DELETE FROM `mail_level_reward`;
/*!40000 ALTER TABLE `mail_level_reward` DISABLE KEYS */;
INSERT INTO `mail_level_reward` (`level`, `raceMask`, `mailTemplateId`, `senderEntry`) VALUES
	(20, 512, 232, 16280),
	(20, 1024, 227, 20914),
	(20, 4, 226, 4772),
	(20, 64, 228, 7954),
	(20, 1, 224, 4732),
	(20, 8, 225, 4753),
	(20, 2, 231, 4752),
	(20, 32, 229, 3690),
	(20, 128, 230, 7953),
	(20, 16, 233, 4773),
	(40, 512, 272, 16280),
	(40, 1024, 273, 20914),
	(40, 4, 274, 4772),
	(40, 64, 275, 7954),
	(40, 1, 276, 4732),
	(40, 8, 277, 4753),
	(40, 2, 278, 4752),
	(40, 32, 279, 3690),
	(40, 128, 280, 7953),
	(40, 16, 281, 4773),
	(60, 690, 282, 35093),
	(60, 1101, 283, 35100),
	(70, 1101, 284, 35133),
	(70, 690, 285, 35135);
/*!40000 ALTER TABLE `mail_level_reward` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
