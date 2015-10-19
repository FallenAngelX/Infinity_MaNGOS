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

-- Dumping structure for table characters.calendar_invites
DROP TABLE IF EXISTS `calendar_invites`;
CREATE TABLE IF NOT EXISTS `calendar_invites` (
  `inviteId` bigint(10) unsigned NOT NULL default '0',
  `eventId` bigint(10) unsigned NOT NULL default '0',
  `inviteeGuid` int(10) unsigned NOT NULL default '0',
  `senderGuid` int(3) unsigned NOT NULL default '0',
  `status` tinyint(10) unsigned NOT NULL default '0',
  `lastUpdateTime` int(10) unsigned NOT NULL default '0',
  `rank` tinyint(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`inviteId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- Dumping data for table characters.calendar_invites: 0 rows
DELETE FROM `calendar_invites`;
/*!40000 ALTER TABLE `calendar_invites` DISABLE KEYS */;
/*!40000 ALTER TABLE `calendar_invites` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
