-- missing trainer_class for enable gossip menu
UPDATE `creature_template` SET `trainer_type` = 3, `trainer_class` = 3 WHERE `subname` = 'Pet Trainer';

-- Pet (same pet and pet summon) spells correct (only for use with pet scaling system!)

-- Need correct spellcasting for this!
-- UPDATE creature_template SET spell1 = 12470, spell2 = 57984 WHERE entry = 15438;
DELETE FROM `creature_template_spells` WHERE `entry` = 15352;
UPDATE `creature_template_spells` SET `spell1` = 40133 WHERE `entry` = 15439;
UPDATE `creature_template_spells` SET `spell1` = 40132 WHERE `entry` = 15430;

DELETE FROM `dbscripts_on_event` WHERE `id` IN (14859,14858);
INSERT INTO `dbscripts_on_event`
    (`id`, `delay`, `command`, `datalong`, `datalong2`, `buddy_entry`, `search_radius`, `data_flags`, `dataint`, `dataint2`, `x`, `y`, `z`, `o`, `comments`)
VALUES
    (14858, 1, 15, 33663, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 'Summon greater Earth elemental'),
    (14859, 1, 15, 32982, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 'Summon greater Fire  elemental');

-- Valkyr guardian
UPDATE `creature_template` SET `minmana` = '6500', `maxmana` = '6500' WHERE `entry` =38391;
REPLACE INTO `creature_template_spells` SET `entry` = 38391, `spell1` = 71841;

-- Mirror Image
UPDATE `creature_template` SET `speed_walk` = 2.5, `modelid_3` = 11686, `minlevel` = 80, `maxlevel` = 80, `equipment_id` = 0 WHERE `entry` = 31216;
REPLACE INTO `creature_template_spells` SET `entry` = 31216, `spell1` = 59637;
REPLACE INTO `creature_template_spells` SET `entry` = 31216, `spell2` = 59638;

-- DK Gargoyle
REPLACE INTO `creature_template_spells` SET `entry` = 27829, `spell1` = 51963;
REPLACE INTO `creature_template_spells` SET `entry` = 27829, `spell2` = 43375;

/* Stoneclaw Totem */
REPLACE INTO creature_spell (guid, spell, `index`, active, disabled, flags) VALUES 
('3579', '55328', '1', '0', '0', '0'),
('3911', '55329', '1', '0', '0', '0'),
('3912', '55330', '1', '0', '0', '0'),
('3913', '55332', '1', '0', '0', '0'),
('7398', '55333', '1', '0', '0', '0'),
('7399', '55335', '1', '0', '0', '0'),
('15478', '55278', '1', '0', '0', '0'),
('31120', '58589', '1', '0', '0', '0'),
('31121', '58590', '1', '0', '0', '0'),
('31122', '58591', '1', '0', '0', '0');

-- Raise Ally
DELETE FROM `creature_spell` WHERE `guid` IN (30230);
INSERT INTO `creature_spell` (`guid`, `spell`, `index`, `active`, `disabled`, `flags`) VALUES
(30230, 62225, 0, 0, 0, 0),
(30230, 47480, 1, 0, 0, 0),
(30230, 47481, 2, 0, 0, 0),
(30230, 47482, 3, 0, 0, 0),
(30230, 47484, 4, 0, 0, 0),
(30230, 67886, 5, 0, 0, 0);