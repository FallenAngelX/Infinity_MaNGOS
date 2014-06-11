-- Gundrak
UPDATE creature_template SET UnitFlags = UnitFlags &~ 33600 WHERE `entry` IN (29307, 31365);
UPDATE creature_template SET `ScriptName` = 'mob_sladran_constrictor' WHERE `entry` = 29713;
UPDATE creature_template SET `ScriptName` = 'mob_sladran_snake_wrap' WHERE `entry` = 29742;
