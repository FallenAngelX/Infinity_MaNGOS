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

-- Dumping structure for table mangos.npc_vendor_template
DROP TABLE IF EXISTS `npc_vendor_template`;
CREATE TABLE IF NOT EXISTS `npc_vendor_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `item` mediumint(8) unsigned NOT NULL default '0',
  `maxcount` tinyint(3) unsigned NOT NULL default '0',
  `incrtime` int(10) unsigned NOT NULL default '0',
  `ExtendedCost` mediumint(8) unsigned NOT NULL default '0',
  `condition_id` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`item`,`ExtendedCost`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Npc System';

-- Dumping data for table mangos.npc_vendor_template: 41 rows
DELETE FROM `npc_vendor_template`;
/*!40000 ALTER TABLE `npc_vendor_template` DISABLE KEYS */;
INSERT INTO `npc_vendor_template` (`entry`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `condition_id`) VALUES
	(33238, 44605, 0, 0, 0, 0),
	(33238, 33451, 0, 0, 0, 0),
	(33238, 33454, 0, 0, 0, 0),
	(33238, 35954, 0, 0, 0, 0),
	(33238, 33443, 0, 0, 0, 0),
	(33238, 33449, 0, 0, 0, 0),
	(33238, 33452, 0, 0, 0, 0),
	(33238, 35949, 0, 0, 0, 0),
	(33238, 22148, 0, 0, 0, 0),
	(33238, 16583, 0, 0, 0, 0),
	(33238, 21177, 0, 0, 0, 0),
	(33238, 17026, 0, 0, 0, 0),
	(33238, 17020, 0, 0, 0, 0),
	(33238, 5565, 0, 0, 0, 0),
	(33238, 37201, 0, 0, 0, 0),
	(33238, 17021, 0, 0, 0, 0),
	(33238, 17028, 0, 0, 0, 0),
	(33238, 17032, 0, 0, 0, 0),
	(33238, 17030, 0, 0, 0, 0),
	(33238, 17033, 0, 0, 0, 0),
	(33238, 17034, 0, 0, 0, 0),
	(33238, 17031, 0, 0, 0, 0),
	(33238, 4470, 0, 0, 0, 0),
	(5, 17402, 0, 0, 0, 0),
	(5, 17403, 0, 0, 0, 0),
	(5, 17404, 0, 0, 0, 0),
	(5, 17405, 0, 0, 0, 0),
	(5, 17406, 0, 0, 0, 0),
	(5, 17407, 0, 0, 0, 0),
	(5, 17408, 0, 0, 0, 0),
	(5, 34410, 0, 0, 0, 0),
	(5, 34412, 0, 0, 0, 0),
	(6, 17194, 0, 0, 0, 0),
	(6, 17196, 0, 0, 0, 0),
	(6, 17200, 0, 0, 0, 0),
	(6, 17201, 0, 0, 0, 0),
	(6, 17202, 0, 0, 0, 0),
	(6, 17303, 0, 0, 0, 0),
	(6, 17304, 0, 0, 0, 0),
	(6, 17307, 0, 0, 0, 0),
	(6, 17344, 0, 0, 0, 0);
/*!40000 ALTER TABLE `npc_vendor_template` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
