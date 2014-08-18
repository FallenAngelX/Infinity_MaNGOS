
SET @ENTRY_MINIGOB = 32838;
SET @GUID_MINIGOB  = 54553;

SET @EVENT_ID      = 105;

SET @MAIL_TEMPLATE = 264;
SET @MAIL_ITEM     = 44817;

-- mail loot
DELETE FROM `mail_loot_template` WHERE `entry` = @MAIL_TEMPLATE;
INSERT INTO `mail_loot_template` (`entry`, `item`) VALUES (@MAIL_TEMPLATE, @MAIL_ITEM);

-- creature script
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = @ENTRY_MINIGOB;
UPDATE `creature_template` SET AIName = '', `ScriptName`='npc_minigob_manabonk' WHERE `entry` = @ENTRY_MINIGOB;

-- creature spawn
DELETE FROM `creature` WHERE `id` = @ENTRY_MINIGOB;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(@GUID_MINIGOB, @ENTRY_MINIGOB, 571, 1, 65535, 0, 0, 5854.42, 660.31, 647.512, 3.71924, 300, 0, 0, 3347, 8139, 0, 0);

-- game event to spawn the npc
DELETE FROM `game_event_creature` WHERE `guid` = @GUID_MINIGOB;
INSERT INTO `game_event_creature` (`guid`, `event`) VALUES
(@GUID_MINIGOB, @EVENT_ID);

DELETE FROM `game_event` WHERE `entry` = @EVENT_ID;
INSERT INTO `game_event` (`entry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`) VALUES
(@EVENT_ID, '2014-08-19 00:10:00', '2020-12-31 01:00:00', 30, 5, 0, 'Dalaran: Minigob Manabonk');
