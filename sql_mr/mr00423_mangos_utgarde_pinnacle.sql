-- svala
DELETE FROM spell_script_target WHERE entry = 59930;
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(59930, 1, 26555);

UPDATE `creature_template` SET `FactionAlliance` = 35, `FactionHorde` = 35 WHERE `entry` = 27327;
UPDATE `creature_template` SET `FactionAlliance` = 35, `FactionHorde` = 35 WHERE `entry` = 30805;
UPDATE `creature_template` SET `FactionAlliance` = 14, `FactionHorde` = 14, `InhabitType` = 7  WHERE `entry` = 27273;
UPDATE `creature_template` SET `FactionAlliance` = 14, `FactionHorde` = 14, `InhabitType` = 7  WHERE `entry` = 30771;

-- skadi
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` = 26893;
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` = 30775;
