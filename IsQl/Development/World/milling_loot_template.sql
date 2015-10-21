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

-- Dumping structure for table mangos.milling_loot_template
DROP TABLE IF EXISTS `milling_loot_template`;
CREATE TABLE IF NOT EXISTS `milling_loot_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `item` mediumint(8) unsigned NOT NULL default '0',
  `ChanceOrQuestChance` float NOT NULL default '100',
  `groupid` tinyint(3) unsigned NOT NULL default '0',
  `mincountOrRef` mediumint(9) NOT NULL default '1',
  `maxcount` tinyint(3) unsigned NOT NULL default '1',
  `condition_id` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';

-- Dumping data for table mangos.milling_loot_template: 45 rows
DELETE FROM `milling_loot_template`;
/*!40000 ALTER TABLE `milling_loot_template` DISABLE KEYS */;
INSERT INTO `milling_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `groupid`, `mincountOrRef`, `maxcount`, `condition_id`) VALUES
	(2449, 11900, 100, 0, -11900, 1, 0),
	(2447, 11900, 100, 0, -11900, 1, 0),
	(765, 11900, 100, 0, -11900, 1, 0),
	(2450, 11901, 100, 0, -11901, 1, 0),
	(2453, 11901, 100, 0, -11901, 1, 0),
	(785, 11901, 100, 0, -11901, 1, 0),
	(3820, 11901, 100, 0, -11901, 1, 0),
	(2452, 11901, 100, 0, -11901, 1, 0),
	(3369, 11902, 100, 0, -11902, 1, 0),
	(3356, 11902, 100, 0, -11902, 1, 0),
	(3357, 11902, 100, 0, -11902, 1, 0),
	(3355, 11902, 100, 0, -11902, 1, 0),
	(3818, 11903, 100, 0, -11903, 1, 0),
	(3821, 11903, 100, 0, -11903, 1, 0),
	(3358, 11903, 100, 0, -11903, 1, 0),
	(3819, 11903, 100, 0, -11903, 1, 0),
	(8836, 11904, 100, 0, -11904, 1, 0),
	(8839, 11904, 100, 0, -11904, 1, 0),
	(4625, 11904, 100, 0, -11904, 1, 0),
	(8845, 11904, 100, 0, -11904, 1, 0),
	(8846, 11904, 100, 0, -11904, 1, 0),
	(8831, 11904, 100, 0, -11904, 1, 0),
	(8838, 11904, 100, 0, -11904, 1, 0),
	(13463, 11905, 100, 0, -11905, 1, 0),
	(13464, 11905, 100, 0, -11905, 1, 0),
	(13467, 11905, 100, 0, -11905, 1, 0),
	(13465, 11905, 100, 0, -11905, 1, 0),
	(13466, 11905, 100, 0, -11905, 1, 0),
	(22790, 11906, 100, 0, -11906, 1, 0),
	(22786, 11906, 100, 0, -11906, 1, 0),
	(22785, 11906, 100, 0, -11906, 1, 0),
	(22793, 11906, 100, 0, -11906, 1, 0),
	(22791, 11906, 100, 0, -11906, 1, 0),
	(22792, 11906, 100, 0, -11906, 1, 0),
	(22787, 11906, 100, 0, -11906, 1, 0),
	(22789, 11906, 100, 0, -11906, 1, 0),
	(36903, 11907, 100, 0, -11907, 1, 0),
	(37921, 11907, 100, 0, -11907, 1, 0),
	(36901, 11907, 100, 0, -11907, 1, 0),
	(36906, 11907, 100, 0, -11907, 1, 0),
	(36905, 11907, 100, 0, -11907, 1, 0),
	(36907, 11907, 100, 0, -11907, 1, 0),
	(36904, 11907, 100, 0, -11907, 1, 0),
	(39970, 11907, 100, 0, -11907, 1, 0),
	(39969, 11907, 100, 0, -11907, 1, 0);
/*!40000 ALTER TABLE `milling_loot_template` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
