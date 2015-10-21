-- Vehicle accessory

ALTER TABLE `vehicle_accessory`
    ADD COLUMN `flags` int(10) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'various flags' AFTER `accessory_entry`,
    ADD COLUMN `offset_x` FLOAT NOT NULL DEFAULT '0' COMMENT 'custom passenger offset X' AFTER `flags`,
    ADD COLUMN `offset_y` FLOAT NOT NULL DEFAULT '0' COMMENT 'custom passenger offset Y' AFTER `offset_x`,
    ADD COLUMN `offset_z` FLOAT NOT NULL DEFAULT '0' COMMENT 'custom passenger offset Z' AFTER `offset_y`,
    ADD COLUMN `offset_o` FLOAT NOT NULL DEFAULT '0' COMMENT 'custom passenger offset O' AFTER `offset_z`;

-- table structure fix (for compatibility with changes from 
RENAME TABLE `vehicle_accessory` TO `temp_vehicle_accessory`;

CREATE TABLE `vehicle_accessory` (
    `vehicle_entry` int(10) UNSIGNED NOT NULL COMMENT 'entry of the npc who has some accessory as vehicle',
    `seat` mediumint(8) UNSIGNED NOT NULL COMMENT 'onto which seat shall the passenger be boarded',
    `accessory_entry` int(10) UNSIGNED NOT NULL COMMENT 'entry of the passenger that is to be boarded',
    `flags` int(10) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'various flags',
    `offset_x` FLOAT NOT NULL DEFAULT '0' COMMENT 'custom passenger offset X',
    `offset_y` FLOAT NOT NULL DEFAULT '0' COMMENT 'custom passenger offset Y',
    `offset_z` FLOAT NOT NULL DEFAULT '0' COMMENT 'custom passenger offset Z',
    `offset_o` FLOAT NOT NULL DEFAULT '0' COMMENT 'custom passenger offset O',
    `comment` varchar(255) NOT NULL,
     PRIMARY KEY  (`vehicle_entry`, `seat`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Vehicle Accessory (passengers that are auto-boarded onto a vehicle)';

INSERT INTO `vehicle_accessory` (`vehicle_entry`, `seat`, `accessory_entry`, `flags`, `offset_x`, `offset_y`, `offset_z`, `offset_o`, `comment`)
    SELECT `vehicle_entry`, `seat`, `accessory_entry`, `flags`, `offset_x`, `offset_y`, `offset_z`, `offset_o`, `comment`
    FROM `temp_vehicle_accessory`;
DROP TABLE `temp_vehicle_accessory`;

--
-- `vehicle_accessory`
--
UPDATE `vehicle_accessory` SET `flags` = 1 WHERE `vehicle_entry` IN (27626, 28312, 32627, 32930, 33109, 33060, 33113, 33114, 36678, 33214, 33778, 33687, 28018, 28614, 35069, 34776);

-- Hardcoded item Id's. Hide vehicle accessory.
UPDATE vehicle_accessory SET flags = flags | 2 WHERE accessory_entry IN (33114, 33167);