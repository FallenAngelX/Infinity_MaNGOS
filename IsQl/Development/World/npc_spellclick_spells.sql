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

-- Dumping structure for table mangos.npc_spellclick_spells
DROP TABLE IF EXISTS `npc_spellclick_spells`;
CREATE TABLE IF NOT EXISTS `npc_spellclick_spells` (
  `npc_entry` int(10) unsigned NOT NULL COMMENT 'reference to creature_template',
  `spell_id` int(10) unsigned NOT NULL COMMENT 'spell which should be casted ',
  `quest_start` mediumint(8) unsigned NOT NULL COMMENT 'reference to quest_template',
  `quest_start_active` tinyint(1) unsigned NOT NULL default '0',
  `quest_end` mediumint(8) unsigned NOT NULL default '0',
  `cast_flags` tinyint(3) unsigned NOT NULL COMMENT 'first bit defines caster: 1=player, 0=creature; second bit defines target, same mapping as caster bit',
  `condition_id` mediumint(8) unsigned NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- Dumping data for table mangos.npc_spellclick_spells: 68 rows
DELETE FROM `npc_spellclick_spells`;
/*!40000 ALTER TABLE `npc_spellclick_spells` DISABLE KEYS */;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`, `condition_id`) VALUES
	(28162, 51026, 12519, 1, 12519, 1, 0),
	(26477, 61832, 12000, 1, 12000, 1, 0),
	(29488, 54568, 12670, 1, 0, 3, 0),
	(29501, 54575, 12670, 1, 0, 3, 0),
	(28203, 50918, 12527, 1, 12527, 1, 0),
	(26200, 46167, 11960, 1, 11960, 1, 0),
	(26477, 61832, 11999, 1, 11999, 1, 0),
	(28202, 50926, 12527, 1, 12527, 1, 0),
	(26421, 47575, 12096, 1, 12096, 1, 0),
	(26421, 47575, 12092, 1, 12092, 1, 0),
	(29856, 55364, 12643, 1, 12643, 1, 0),
	(29856, 55364, 12629, 1, 12629, 1, 0),
	(28161, 51961, 12702, 1, 12702, 1, 0),
	(28161, 51961, 12532, 1, 12532, 1, 0),
	(28389, 51592, 12605, 1, 12605, 1, 0),
	(24896, 50400, 11509, 1, 11509, 3, 0),
	(36557, 67830, 0, 0, 0, 1, 0),
	(25841, 46166, 11795, 1, 0, 3, 0),
	(25841, 46362, 11887, 1, 0, 3, 0),
	(33498, 63126, 13654, 1, 13654, 3, 0),
	(29598, 54768, 12851, 1, 12851, 3, 0),
	(27258, 48365, 12237, 1, 12237, 3, 0),
	(32790, 57654, 13073, 1, 13073, 1, 0),
	(24418, 43768, 11390, 1, 11390, 1, 0),
	(24418, 43768, 11391, 1, 11391, 1, 0),
	(25743, 46260, 11879, 1, 11879, 1, 0),
	(27587, 49078, 12326, 1, 12326, 1, 0),
	(27714, 49584, 12457, 1, 12457, 1, 0),
	(27850, 60968, 0, 0, 0, 3, 0),
	(27881, 60968, 0, 0, 0, 1, 0),
	(28094, 60968, 0, 0, 0, 1, 0),
	(28312, 60968, 0, 0, 0, 1, 0),
	(28319, 60968, 0, 0, 0, 1, 0),
	(28605, 52263, 12680, 1, 12680, 1, 0),
	(28606, 52263, 12680, 1, 12680, 1, 0),
	(28607, 52263, 12680, 1, 12680, 1, 0),
	(28670, 52196, 0, 0, 0, 0, 0),
	(28833, 52447, 12701, 1, 12701, 1, 0),
	(28887, 52447, 12701, 1, 12701, 1, 0),
	(30236, 57573, 0, 0, 0, 1, 0),
	(32627, 60968, 0, 0, 0, 1, 0),
	(32629, 60968, 0, 0, 0, 1, 0),
	(32633, 61424, 0, 0, 0, 0, 0),
	(32640, 61424, 0, 0, 0, 0, 0),
	(24083, 55074, 0, 0, 0, 1, 0),
	(26523, 48296, 12218, 1, 12218, 1, 0),
	(27626, 49138, 0, 0, 0, 1, 0),
	(28710, 46598, 0, 0, 0, 1, 0),
	(29579, 46598, 0, 0, 0, 1, 0),
	(28782, 52349, 12687, 1, 12687, 1, 0),
	(33060, 65031, 0, 0, 0, 1, 920),
	(33062, 65030, 0, 0, 0, 1, 920),
	(34045, 65030, 0, 0, 0, 1, 920),
	(33109, 62309, 0, 0, 0, 1, 920),
	(33067, 65031, 0, 0, 0, 1, 920),
	(33167, 46598, 0, 0, 0, 1, 920),
	(34072, 0, 0, 0, 0, 0, 0),
	(29708, 55028, 12856, 1, 12856, 1, 0),
	(26503, 0, 0, 0, 0, 0, 950),
	(26809, 0, 0, 0, 0, 0, 953),
	(33498, 63125, 0, 0, 0, 1, 964),
	(30066, 62503, 12953, 1, 12953, 1, 0),
	(36558, 67830, 0, 0, 0, 1, 0),
	(34567, 65684, 0, 0, 0, 1, 0),
	(34568, 65686, 0, 0, 0, 1, 0),
	(27354, 62309, 12270, 1, 12270, 1, 0),
	(27354, 62309, 12244, 1, 12244, 1, 0),
	(27496, 60944, 0, 0, 0, 1, 1010);
/*!40000 ALTER TABLE `npc_spellclick_spells` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
