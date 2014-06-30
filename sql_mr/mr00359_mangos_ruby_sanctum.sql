-- Ruby sanctum
-- Halion
UPDATE `creature_template` SET `ScriptName`='boss_halion_real', `AIName` ='' WHERE `entry`=39863;
UPDATE `creature_template` SET `ScriptName`='boss_halion_twilight', `AIName` ='' WHERE `entry`=40142;
UPDATE `creature_template` SET `ScriptName`='mob_halion_meteor', `AIName` ='' WHERE `entry` = 40029;
UPDATE `creature_template` SET `ScriptName`='mob_halion_flame', `AIName` ='' WHERE `entry` IN (40041);
UPDATE `creature_template` SET `ScriptName`='mob_halion_control', `AIName` ='' WHERE `entry` IN (40146);
UPDATE `creature_template` SET `ScriptName`='mob_halion_orb', `AIName` ='' WHERE `entry` IN (40083,40100);
UPDATE `creature_template` SET `ScriptName`='mob_orb_rotation_focus', `AIName` ='' WHERE `entry` = 40091;
UPDATE `creature_template` SET `ScriptName`='mob_orb_carrier', `AIName` ='' WHERE `entry` = 40081;
UPDATE `creature_template` SET `ScriptName`='mob_fiery_combustion', `AIName` ='' WHERE `entry` = 40001;
UPDATE `creature_template` SET `ScriptName`='mob_soul_consumption', `AIName` ='' WHERE `entry` = 40135;
#
UPDATE `gameobject_template` SET `data10` = 74807, `ScriptName` = 'go_halion_portal_twilight' WHERE `entry` IN (202794,202795);
UPDATE `gameobject_template` SET `ScriptName` = 'go_halion_portal_real' WHERE `entry` = 202796;

-- Baltharus
UPDATE `creature_template` SET `DamageMultiplier` = 80  WHERE `entry` = 39751;
UPDATE `creature_template` SET `ScriptName`='mob_baltharus_clone', `AIName` ='', `DamageMultiplier` = 80  WHERE `entry` = 39899;
INSERT IGNORE INTO `creature_template` (`Entry`, `DifficultyEntry1`, `DifficultyEntry2`, `DifficultyEntry3`, `KillCredit1`, `KillCredit2`, `ModelId1`, `ModelId2`, `ModelId3`, `ModelId4`, `Name`, `SubName`, `IconName`, `GossipMenuId`, `MinLevel`, `MaxLevel`, `MinLevelHealth`, `MaxLevelHealth`, `MinLevelMana`, `MaxLevelMana`, `Armor`, `FactionAlliance`, `FactionHorde`, `NpcFlags`, `SpeedWalk`, `SpeedRun`, `Scale`, `Rank`, `MinMeleeDmg`, `MaxMeleeDmg`, `DamageSchool`, `MeleeAttackPower`, `DamageMultiplier`, `MeleeBaseAttackTime`, `RangedBaseAttackTime`, `UnitClass`, `UnitFlags`, `DynamicFlags`, `Family`, `TrainerType`, `TrainerSpell`, `TrainerClass`, `TrainerRace`, `MinRangedDmg`, `MaxRangedDmg`, `RangedAttackPower`, `CreatureType`, `CreatureTypeFlags`, `LootId`, `PickpocketLootId`, `SkinningLootId`, `ResistanceHoly`, `ResistanceFire`, `ResistanceNature`, `ResistanceFrost`, `ResistanceShadow`, `ResistanceArcane`, `PetSpellDataId`, `MinLootGold`, `MaxLootGold`, `AIName`, `MovementType`, `InhabitType`, `RegenerateStats`, `RacialLeader`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `MovementTemplateId`, `HealthMultiplier`, `EquipmentTemplateId`, `MechanicImmuneMask`, `ExtraFlags`, `ScriptName`) VALUES
(16, 0, 0, 0, 0, 0, 11686, 0, 11686, 0, 'Baltharus Target Dummy', '', NULL, 0, 1, 1, 25, 27, 0, 0, 17, 35, 35, 0, 1, 1.14286, 1, 0, 1, 2, 0, 0, 1, 2000, 2000, 1, 33554432, 0, 0, 0, 0, 0, 0, 1, 2, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 258, '');

-- Zarithian
UPDATE `creature` SET `position_x` = '3008.552734',`position_y` = '530.471680',`position_z` = '89.195290',`orientation` = '6.16' WHERE `id` = 39746;
UPDATE `creature_template` SET `ScriptName` = 'mob_flamecaller_ruby', `AIName` ='' WHERE `entry`=39814;

-- Saviana Ragefire
DELETE FROM `spell_script_target` WHERE `entry` IN (74455);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES 
('74455', '1', '39747');

-- Xerestrasza
UPDATE `creature_template` SET `ScriptName`='mob_xerestrasza', `AIName` ='' WHERE `entry`=40429;

-- Mobs
UPDATE `creature_template` SET `ScriptName` = 'mob_living_ember' WHERE `entry` IN ('40683');
UPDATE `creature_template` SET `ScriptName` = 'mob_living_inferno' WHERE `entry` IN ('40681');
