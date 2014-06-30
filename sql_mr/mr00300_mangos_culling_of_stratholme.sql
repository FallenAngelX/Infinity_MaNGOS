-- ------------------------------
-- Instance CoS                 -
-- ------------------------------

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_mike' WHERE entry = 30571;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_chromi_start' WHERE entry=26527;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_roger' WHERE entry=27903;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_morigan' WHERE entry=27877;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = '' WHERE entry=30996;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_stratholme_crates' WHERE entry=27827;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_jena' WHERE entry=27885;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_malcolm' WHERE entry=27891;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_bartleby_cs' WHERE entry=27907;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_chromi_middle' WHERE entry=27915;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_uther' WHERE entry=26528;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_arthas' WHERE entry=26499;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_arthas_priest' WHERE entry IN (70004, 70005);
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_arthas_marine' WHERE entry IN (70000, 70001, 70002, 70003);
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_dark_conversion' WHERE entry IN (31127, 31126, 28167, 28169);
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_cs_gnoul' WHERE entry=28249;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_cs_necromancer' WHERE entry=28200;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_cs_field' WHERE entry=27734;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_cs_acolyte' WHERE entry=27731;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_cs_butcher' WHERE entry=27736;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_meathook' WHERE entry=26529;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_salramm' WHERE entry=26530;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_salramm_gnoul' WHERE entry=27733;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_lord_epoch' WHERE entry=26532;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_malganis' WHERE entry=26533;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_time_riftCS' WHERE entry=28409;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_infinite_corruptor' WHERE entry=32273;

-- ACID CLEAN UP
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=26499);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=26529);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=26499);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=26530);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=26532);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=26533);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=27731);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=27734);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=27736);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=28200);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=28249);
DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=32273);

-- Clean up ACID texts
DELETE FROM `creature_ai_texts` WHERE  `entry`=-841;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-842;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-843;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-844;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-845;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-846;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-847;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-848;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-849;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-850;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-851;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-852;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-853;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-854;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-855;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-856;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-857;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-858;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-859;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-860;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-861;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-862;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-863;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-864;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-865;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-866;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-867;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-868;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-869;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-870;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-871;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-872;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-873;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-874;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-875;
DELETE FROM `creature_ai_texts` WHERE  `entry`=-876;

-- Quest fix  ( if you already had quest done should be able to do it again you can in off blizz ... soo)
-- Xploitable
-- UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE `entry` = 13151;
-- UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE `entry` = 13149;

-- remove already spawned third chromi for summon after mal ganis is dead
DELETE FROM `creature` WHERE `id`=30997;

-- ----------------------------------------
-- spell scripts and ect spell_area_stuff -
-- ----------------------------------------

REPLACE INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_start_active`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`) VALUES
('35481','4100','0','0','0','0','0','1','1'), -- cause careate two spell with different racemask fore one area
('35480','4100','0','0','0','0','0','0','1'); -- cause careate two spell with different racemask fore one area

-- ----------------------------
-- Creature Stuff             -
-- ----------------------------

UPDATE `creature_template` SET `ModelId2` = 24769 WHERE `entry` = 27747;
UPDATE `creature_template` SET `ModelId2` = 24768 WHERE `entry` = 27745;
UPDATE `creature_template` SET `ModelId2` = 24949 WHERE `entry` = 26499;

UPDATE `creature` SET `spawntimesecs`= 36000 WHERE `id` IN (31127, 31126, 28167, 28169);

-- Remove old versions
DELETE FROM `creature` WHERE `id` IN (27731,27734,28249,27736,27915,30571,26499,26497,26528,27891,27892,27884,32273,28439);

-- DB error corrections for above sql query
DELETE FROM `creature_movement` WHERE (`id`='138237' AND `point`='1') OR (`id`='138237' AND `point`='2') OR (`id`='138238' AND `point`='1') OR (`id`='138238' AND `point`='2') OR (`id`='138239' AND `point`='1') OR (`id`='138239' AND `point`='2') OR (`id`='138239' AND `point`='3') OR (`id`='138239' AND `point`='4');
DELETE FROM `creature_movement` WHERE (`id`='138288' AND `point`='1') OR (`id`='138288' AND `point`='2') OR (`id`='138289' AND `point`='1') OR (`id`='138289' AND `point`='2');

-- Add Whats needed --
DELETE FROM `creature` WHERE `id` in (26497, 26528, 27891, 27892, 32273, 28439);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(600114, 26497, 595, 3, 1, 0, 1221, 1896.39, 1292.91, 143.711, 0.016332, 300, 0, 0, 100800, 88140, 0, 0),
(600115, 26528, 595, 3, 1, 0, 1819, 1761.42, 1285.75, 139.945, 4.93874, 300, 0, 0, 126000, 59910, 0, 0),
(600116, 27891, 595, 3, 1, 0, 0, 1603.38, 805.988, 123.272, 1.90688, 300, 0, 0, 8982, 0, 0, 0),
(600117, 27892, 595, 3, 1, 0, 0, 1602.3, 809.385, 123.454, 5.02884, 300, 0, 0, 8982, 0, 0, 0),
(600118, 32273, 595, 3, 1, 0, 1839, 2330.93, 1275.59, 132.848, 3.60489, 300, 0, 0, 417911, 0, 0, 0),
(600119, 28439, 595, 3, 1, 0, 0, 2336.56, 1277.9, 132.885, 3.47923, 300, 0, 0, 1, 0, 0, 0);


-- added some npc s of my own for micro management
-- footman
DELETE FROM `creature_template` WHERE `entry` IN (10, 11, 12, 13);
INSERT INTO `creature_template` (`Entry`, `Name`, `SubName`, `IconName`, `MinLevel`, `MaxLevel`, `DifficultyEntry1`, `DifficultyEntry2`, `DifficultyEntry3`, `ModelId1`, `ModelId2`, `ModelId3`, `ModelId4`, `FactionAlliance`, `FactionHorde`, `Scale`, `Family`, `CreatureType`, `InhabitType`, `RegenerateStats`, `RacialLeader`, `NpcFlags`, `UnitFlags`, `DynamicFlags`, `ExtraFlags`, `CreatureTypeFlags`, `SpeedWalk`, `SpeedRun`, `UnitClass`, `Rank`, `Expansion`, `HealthMultiplier`, `PowerMultiplier`, `DamageMultiplier`, `DamageVariance`, `ArmorMultiplier`, `ExperienceMultiplier`, `MinLevelHealth`, `MaxLevelHealth`, `MinLevelMana`, `MaxLevelMana`, `MinMeleeDmg`, `MaxMeleeDmg`, `MinRangedDmg`, `MaxRangedDmg`, `Armor`, `MeleeAttackPower`, `RangedAttackPower`, `MeleeBaseAttackTime`, `RangedBaseAttackTime`, `DamageSchool`, `MinLootGold`, `MaxLootGold`, `LootId`, `PickpocketLootId`, `SkinningLootId`, `KillCredit1`, `KillCredit2`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `MechanicImmuneMask`, `ResistanceHoly`, `ResistanceFire`, `ResistanceNature`, `ResistanceFrost`, `ResistanceShadow`, `ResistanceArcane`, `PetSpellDataId`, `MovementType`, `MovementTemplateId`, `TrainerType`, `TrainerSpell`, `TrainerClass`, `TrainerRace`, `TrainerTemplateId`, `VendorTemplateId`, `EquipmentTemplateId`, `VehicleTemplateId`, `GossipMenuId`, `AIName`, `ScriptName`) VALUES
(10,'Lordaeron Footman','','','80','80','0','0','0','24768','24768','0','0','2076','2076','1','0','7','3','3','0','0','0','0','0','0','1','1.14286','1','1','-1','1','1','2.7','1','1','1','12600','12600','0','0','420','630','336','504','9730','157','126','2000','2000','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','223','0','0','','npc_arthas_marine'),
(11,'Lordaeron Footman','','','80','80','0','0','0','24768','24768','0','0','2076','2076','1','0','7','3','3','0','0','0','0','0','0','1','1.14286','1','1','-1','1','1','2.7','1','1','1','12600','12600','0','0','420','630','336','504','9730','157','126','2000','2000','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','223','0','0','','npc_arthas_marine'),
(12,'Lordaeron Footman','','','80','80','0','0','0','24768','24768','0','0','2076','2076','1','0','7','3','3','0','0','0','0','0','0','1','1.14286','1','1','-1','1','1','2.7','1','1','1','12600','12600','0','0','420','630','336','504','9730','157','126','2000','2000','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','223','0','0','','npc_arthas_marine'),
(13,'Lordaeron Footman','','','80','80','0','0','0','24768','24768','0','0','2076','2076','1','0','7','3','3','0','0','0','0','0','0','1','1.14286','1','1','-1','1','1','2.7','1','1','1','12600','12600','0','0','420','630','336','504','9730','157','126','2000','2000','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','223','0','0','','npc_arthas_marine');

REPLACE INTO `creature_template_spells` (`entry`, `spell1`, `spell2`) VALUES
(10, 52317, 25710),
(11, 52317, 25710),
(12, 52317, 25710),
(13, 52317, 25710);

-- micro manage spawn w/ news one in there recyling old guids
DELETE FROM `creature` WHERE `id` IN (10, 11, 12, 13);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(600120, 10, 595, 3, 1, 0, 0, 2042.13, 1293.14, 143.336, 4.64258, 300, 0, 0, 12600, 0, 0, 0),
(600121, 11, 595, 3, 1, 0, 0, 2046.71, 1281.91, 143.321, 1.51844, 300, 0, 0, 12600, 0, 0, 0),
(600122, 12, 595, 3, 1, 0, 0, 2041.97, 1281.66, 143.554, 1.62316, 300, 0, 0, 12600, 0, 0, 0),
(600123, 13, 595, 3, 1, 0, 0, 2046.86, 1293.33, 143.132, 4.7822, 300, 0, 0, 12600, 0, 0, 0);

-- priest
DELETE FROM `creature_template` WHERE `entry` IN(14, 15);
INSERT INTO `creature_template` (`Entry`, `Name`, `SubName`, `IconName`, `MinLevel`, `MaxLevel`, `DifficultyEntry1`, `DifficultyEntry2`, `DifficultyEntry3`, `ModelId1`, `ModelId2`, `ModelId3`, `ModelId4`, `FactionAlliance`, `FactionHorde`, `Scale`, `Family`, `CreatureType`, `InhabitType`, `RegenerateStats`, `RacialLeader`, `NpcFlags`, `UnitFlags`, `DynamicFlags`, `ExtraFlags`, `CreatureTypeFlags`, `SpeedWalk`, `SpeedRun`, `UnitClass`, `Rank`, `Expansion`, `HealthMultiplier`, `PowerMultiplier`, `DamageMultiplier`, `DamageVariance`, `ArmorMultiplier`, `ExperienceMultiplier`, `MinLevelHealth`, `MaxLevelHealth`, `MinLevelMana`, `MaxLevelMana`, `MinMeleeDmg`, `MaxMeleeDmg`, `MinRangedDmg`, `MaxRangedDmg`, `Armor`, `MeleeAttackPower`, `RangedAttackPower`, `MeleeBaseAttackTime`, `RangedBaseAttackTime`, `DamageSchool`, `MinLootGold`, `MaxLootGold`, `LootId`, `PickpocketLootId`, `SkinningLootId`, `KillCredit1`, `KillCredit2`, `QuestItem1`, `QuestItem2`, `QuestItem3`, `QuestItem4`, `QuestItem5`, `QuestItem6`, `MechanicImmuneMask`, `ResistanceHoly`, `ResistanceFire`, `ResistanceNature`, `ResistanceFrost`, `ResistanceShadow`, `ResistanceArcane`, `PetSpellDataId`, `MovementType`, `MovementTemplateId`, `TrainerType`, `TrainerSpell`, `TrainerClass`, `TrainerRace`, `TrainerTemplateId`, `VendorTemplateId`, `EquipmentTemplateId`, `VehicleTemplateId`, `GossipMenuId`, `AIName`, `ScriptName`) VALUES
(14,'High Elf Mage-Priest','','','80','80','0','0','0','24769','0','0','0','2076','2076','1','0','7','3','3','0','0','0','0','0','0','1','1.14286','8','1','-1','1','1','2.9','1','1','1','10080','10080','8814','8814','307','459','246','367','7784','115','92','2000','2000','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','14','0','0','','npc_arthas_priest'),
(15,'High Elf Mage-Priest','','','80','80','0','0','0','24769','0','0','0','2076','2076','1','0','7','3','3','0','0','0','0','0','0','1','1.14286','8','1','-1','1','1','2.9','1','1','1','10080','10080','8814','8814','307','459','246','367','7784','115','92','2000','2000','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','14','0','0','','npc_arthas_priest');

REPLACE INTO `creature_template_spells` (`entry`, `spell1`) VALUES
(14, 34232),
(15, 34232);

-- micro manage spawn w/ news one in there recyling old guids
DELETE FROM `creature` WHERE `id` IN (14, 15);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(600124, 14, 595, 3, 1, 0, 0, 2037.91, 1293.03, 143.499, 4.72984, 300, 0, 0, 10080, 8814, 0, 0),
(600125, 15, 595, 3, 1, 0, 0, 2037.59, 1281.81, 143.666, 1.48353, 300, 0, 0, 10080, 8814, 0, 0);

-- end of this
