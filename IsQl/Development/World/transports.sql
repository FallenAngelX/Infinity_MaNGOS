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

-- Dumping structure for table mangos.transports
DROP TABLE IF EXISTS `transports`;
CREATE TABLE IF NOT EXISTS `transports` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `name` text,
  `period` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Transports';

-- Dumping data for table mangos.transports: 26 rows
DELETE FROM `transports`;
/*!40000 ALTER TABLE `transports` DISABLE KEYS */;
INSERT INTO `transports` (`entry`, `name`, `period`) VALUES
	(176495, 'Undercity, Tirisfal Glades and Grom\'gol Base Camp, Stranglethorn Vale ("The Purple Princess")', 315026),
	(176310, 'Stormwind Harbor and Auberdine, Darkshore ("Ship (The Bravery)")', 234510),
	(176244, 'Rut\'theran Village, Teldrassil and Auberdine, Darkshore ("The Moonspray")', 312317),
	(176231, 'Menethil Harbor, Wetlands and Theramore Isle, Dustwallow Marsh ("The Lady Mehley")', 230162),
	(175080, 'Orgrimmar, Durotar and Grom\'gol Base Camp, Stranglethorn Vale ("The Iron Eagle")', 248990),
	(164871, 'Orgrimmar, Durotar and Undercity, Tirisfal Glades ("The Thundercaller")', 239253),
	(20808, 'Steamwheedle Cartel ports, Ratchet and Booty Bay ("The Maiden\'s Fancy")', 231236),
	(177233, 'The Forgotten Coast, Feralas and Feathermoon Stronghold, Sardor Isle, Feralas ("Feathermoon Ferry")', 259747),
	(181646, 'Valaar\'s Berth, Azuremyst Isle and Auberdine, Darkshore ("Elune\'s Blessing")', 238707),
	(181688, 'Menethil Harbor, Wetlands and Valgarde, Howling Fjord ("Northspear")', 445534),
	(181689, 'Undercity, Tirisfal Glades and Vengeance Landing, Howling Fjord ("Zeppelin, Horde (Cloudkisser)")', 214579),
	(186238, 'Orgrimmar, Durotar and Warsong Hold, Borean Tundra ("Zeppelin, Horde (The Mighty Wind)")', 302705),
	(186371, 'Westguard Keep in Howling Fjord to bombard pirate ("Zeppelin")', 484212),
	(187038, 'Not Boardable - Cyrcling in Howling Fjord ("Sister Mercy")', 307953),
	(187568, 'Unu\'pe, Borean Tundra and Moa\'ki Harbor, Dragonblight ("Turtle (Walker of Waves)")', 445220),
	(188511, 'Moa\'ki Harbor and Kamagua ("Turtle (Green Island)")', 502354),
	(190536, 'Stormwing Harbor and Valiance Keep, Borean Tundra ("The Kraken")', 271979),
	(192241, 'Not boardable - Horde gunship patrolling above Icecrown ("Orgrim\'s Hammer")', 1431158),
	(192242, 'Not boardable - Alliance gunship patrolling above Icecrown ("The Skybreaker")', 1051388),
	(190549, 'Orgrimmar and Thunder Bluff', 566762),
	(201580, 'ICC Raid, The Skybreaker', 77527),
	(201581, 'ICC Raid, Orgrim\'s Hammer', 51584),
	(201834, 'Zeppelin, Horde (The Mighty Wind) (Icecrown Raid)', 154573),
	(201598, 'The Skybreaker', 23970),
	(195121, 'IOC - Alliance Gunship', 118797),
	(195276, 'IOC - Horde Gunship', 115661);
/*!40000 ALTER TABLE `transports` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
