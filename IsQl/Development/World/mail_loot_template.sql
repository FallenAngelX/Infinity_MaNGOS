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

-- Dumping structure for table mangos.mail_loot_template
DROP TABLE IF EXISTS `mail_loot_template`;
CREATE TABLE IF NOT EXISTS `mail_loot_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `item` mediumint(8) unsigned NOT NULL default '0',
  `ChanceOrQuestChance` float NOT NULL default '100',
  `groupid` tinyint(3) unsigned NOT NULL default '0',
  `mincountOrRef` mediumint(9) NOT NULL default '1',
  `maxcount` tinyint(3) unsigned NOT NULL default '1',
  `condition_id` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';

-- Dumping data for table mangos.mail_loot_template: 83 rows
DELETE FROM `mail_loot_template`;
/*!40000 ALTER TABLE `mail_loot_template` DISABLE KEYS */;
INSERT INTO `mail_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `groupid`, `mincountOrRef`, `maxcount`, `condition_id`) VALUES
	(87, 6529, 100, 0, 1, 1, 0),
	(119, 15564, 100, 0, 1, 1, 0),
	(120, 15564, 100, 0, 1, 1, 0),
	(180, 24132, 100, 0, 1, 1, 0),
	(103, 11422, 100, 0, 1, 1, 0),
	(99, 11423, 100, 0, 1, 1, 0),
	(104, 11422, 100, 0, 1, 1, 0),
	(100, 11423, 100, 0, 1, 1, 0),
	(92, 20469, 100, 0, 1, 1, 0),
	(93, 20469, 100, 0, 1, 1, 0),
	(98, 13158, 100, 0, 1, 1, 0),
	(109, 19858, 100, 0, 1, 1, 0),
	(113, 19697, 100, 0, 1, 1, 0),
	(111, 19697, 100, 0, 1, 1, 0),
	(183, 31698, 100, 0, 1, 1, 0),
	(84, 21746, 100, 0, 1, 1, 0),
	(85, 21746, 100, 0, 1, 1, 0),
	(86, 21746, 100, 0, 1, 1, 0),
	(88, 21746, 100, 0, 1, 1, 0),
	(89, 21746, 100, 0, 1, 1, 0),
	(90, 21746, 100, 0, 1, 1, 0),
	(91, 21746, 100, 0, 1, 1, 0),
	(92, 21746, 100, 0, 1, 1, 0),
	(95, 21746, 100, 0, 1, 1, 0),
	(96, 21746, 100, 0, 1, 1, 0),
	(97, 21746, 100, 0, 1, 1, 0),
	(121, 21746, 100, 0, 1, 1, 0),
	(124, 21746, 100, 0, 1, 1, 0),
	(125, 21746, 100, 0, 1, 1, 0),
	(126, 21746, 100, 0, 1, 1, 0),
	(127, 21746, 100, 0, 1, 1, 0),
	(128, 21746, 100, 0, 1, 1, 0),
	(129, 21746, 100, 0, 1, 1, 0),
	(130, 21746, 100, 0, 1, 1, 0),
	(131, 21746, 100, 0, 1, 1, 0),
	(132, 21746, 100, 0, 1, 1, 0),
	(133, 21746, 100, 0, 1, 1, 0),
	(134, 21746, 100, 0, 1, 1, 0),
	(135, 21746, 100, 0, 1, 1, 0),
	(136, 21746, 100, 0, 1, 1, 0),
	(137, 21746, 100, 0, 1, 1, 0),
	(138, 21746, 100, 0, 1, 1, 0),
	(139, 21746, 100, 0, 1, 1, 0),
	(140, 21746, 100, 0, 1, 1, 0),
	(141, 21746, 100, 0, 1, 1, 0),
	(142, 21746, 100, 0, 1, 1, 0),
	(143, 21746, 100, 0, 1, 1, 0),
	(144, 21746, 100, 0, 1, 1, 0),
	(145, 21746, 100, 0, 1, 1, 0),
	(146, 21746, 100, 0, 1, 1, 0),
	(147, 21746, 100, 0, 1, 1, 0),
	(148, 21746, 100, 0, 1, 1, 0),
	(149, 21746, 100, 0, 1, 1, 0),
	(150, 21746, 100, 0, 1, 1, 0),
	(151, 21746, 100, 0, 1, 1, 0),
	(152, 21746, 100, 0, 1, 1, 0),
	(153, 21746, 100, 0, 1, 1, 0),
	(154, 21746, 100, 0, 1, 1, 0),
	(155, 21746, 100, 0, 1, 1, 0),
	(156, 21746, 100, 0, 1, 1, 0),
	(157, 21746, 100, 0, 1, 1, 0),
	(158, 21746, 100, 0, 1, 1, 0),
	(159, 21746, 100, 0, 1, 1, 0),
	(160, 21746, 100, 0, 1, 1, 0),
	(168, 21746, 100, 0, 1, 1, 0),
	(94, 20469, 100, 0, 1, 1, 0),
	(102, 17685, 100, 0, 1, 1, 0),
	(118, 17685, 100, 0, 1, 1, 0),
	(122, 21216, 100, 0, 1, 1, 0),
	(161, 21216, 100, 0, 1, 1, 0),
	(108, 17712, 100, 0, 1, 1, 0),
	(117, 17712, 100, 0, 1, 1, 0),
	(236, 39317, 100, 0, 1, 1, 0),
	(231, 46880, 100, 0, 1, 1, 0),
	(232, 46882, 100, 0, 1, 1, 0),
	(225, 46876, 100, 0, 1, 1, 0),
	(224, 46875, 100, 0, 1, 1, 0),
	(227, 46879, 100, 0, 1, 1, 0),
	(226, 46877, 100, 0, 1, 1, 0),
	(228, 46878, 100, 0, 1, 1, 0),
	(229, 46884, 100, 0, 1, 1, 0),
	(233, 46881, 100, 0, 1, 1, 0),
	(230, 46883, 100, 0, 1, 1, 0);
/*!40000 ALTER TABLE `mail_loot_template` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
