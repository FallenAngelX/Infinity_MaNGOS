-- ------------------------------------- --
-- ------- I am a temporary file ------- --
-- After a month my data will be deleted --
-- ------------------------------------- --
-- ===================================== --

-- ---------- --
-- 2013-10-10 --
-- ---------- --
-- sd2_mr0631
DELETE FROM `creature_template_addon` WHERE `entry` = 38285;
UPDATE `creature_template_addon` SET `auras` = '70385 70405' WHERE `entry` IN(37672);

-- ---------- --
-- 2013-10-14 --
-- ---------- --
-- sd2_mr0632
DELETE FROM `creature` WHERE `id` = 36658;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES
(49051, 36658, 658, 3, 1, 0, 0,1018.38, 167.25, 628.157, 5.2709, 86400, 0, 0, 653828, 0, 0, 0);

-- ---------- --
-- 2013-10-20 --
-- ---------- --
-- sd2_mr0633
SET @ConditionEntry := 1807;
REPLACE INTO `conditions` (`condition_entry`, `type`, `value1`, `value2`) VALUES
(@ConditionEntry    , 18, 0, 0), -- INSTANCE_CONDITION_ID_NORMAL_MODE
(@ConditionEntry + 1, 18, 1, 0), -- INSTANCE_CONDITION_ID_HARD_MODE
(@ConditionEntry + 2, 18, 2, 0), -- INSTANCE_CONDITION_ID_HARD_MODE_2
(@ConditionEntry + 3, 18, 3, 0), -- INSTANCE_CONDITION_ID_HARD_MODE_3
(@ConditionEntry + 4, 18, 4, 0); -- INSTANCE_CONDITION_ID_HARD_MODE_4
