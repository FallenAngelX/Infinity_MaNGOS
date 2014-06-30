-- first clean 
-- YTDB cleanup
DELETE FROM `creature` WHERE `map` = 609 AND `guid` IN (116863);
DELETE FROM `creature` WHERE `map` = 609 AND `id` IN (29219,29206,29190);
UPDATE `creature_template` SET `UnitFlags` = 0, `CreatureTypeFlags` = 8 WHERE entry IN (29174,29182,29186,29190,29206,29176,29177,29181);
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'generic_creature' WHERE `entry` = 29178;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'generic_creature' WHERE `entry` = 29179;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'generic_creature' WHERE `entry` = 29180;

-- ------------
-- Special npcs
-- ------------

UPDATE `creature_template` SET `ScriptName` = 'npc_valkyr_battle_maiden' WHERE `entry` = '28534';

-- ------------------------
-- QUEST::DAWN OF THE LIGHT
-- ------------------------
-- remove the four static uneeded spawn around chapel --  spawned during event not static plus they respawn during event
DELETE FROM `creature` WHERE `id`=29174;

-- remove static rayne--  spawned during event not static plus they respawn during event
DELETE FROM `creature` WHERE `id`=29181;

-- remove static rimblat--  spawned during event not static plus they respawn during event
DELETE FROM `creature` WHERE `id`=29182;

-- remove static krofax--  spawned during event not static plus they respawn during event
DELETE FROM `creature` WHERE `id`=29176;

-- remove static eligor--  spawned during event not static plus they respawn during event
DELETE FROM `creature` WHERE `id`=29177;

-- remove static tyrosus--  spawned during event not static plus they respawn during event
DELETE FROM `creature` WHERE `id`=29178;

-- remove static leon--  spawned during event not static plus they respawn during event
DELETE FROM `creature` WHERE `id`=29179;

-- remove stativ duke--  spawned during event not static plus they respawn during event
DELETE FROM `creature` WHERE `id`=29180;

UPDATE `creature_template` SET `AIName` = '', `ScriptName`='npc_minibosses_dawn_of_light' WHERE `entry` IN (29199,29204,29200);
UPDATE `creature_template` SET `AIName` = '', `ScriptName`='mob_acherus_ghoul' WHERE `entry`='29219';
UPDATE `creature_template` SET `AIName` = '', `ScriptName`='mob_warrior_of_the_frozen_wastes' WHERE `entry`='29206';

-- ----------------------------
-- Quest:: An End To All Things
-- ----------------------------

-- Frostbrood Vanquisher
DELETE FROM `creature_spell` WHERE `guid` IN (28670);
INSERT INTO `creature_spell` (`guid`, `spell`, `index`, `active`, `disabled`, `flags`) VALUES
(28670, 53114, 0, 0, 0, 0),
(28670, 53110, 1, 0, 0, 0);

-- -----------------------------
-- Quest::Ambush at the overlook
-- -----------------------------
UPDATE `creature_template` SET `ScriptName`='mob_scarlet_courier' WHERE `entry`='29076';

-- ----------------------
-- Quest::Bloody Breakout
-- ----------------------
UPDATE `creature_template` SET `MechanicImmuneMask` = 12582928 WHERE `entry` = 28912; 
UPDATE `creature_template` SET `MechanicImmuneMask` = 12582928 WHERE `entry` = 28447;

-- tweak Valroth EAI
DELETE FROM `creature_ai_scripts` WHERE `id` IN (2900101, 2900112);
INSERT INTO `creature_ai_scripts` VALUES 
('2900101', '29001', '1', '0', '100', '0', '0', '0', '0', '0', '21', '1', '1', '0', '22', '0', '0', '0', '0', '0', '0', '0', 'High Inquisitor Valroth - Set Phase to 0 on Spawn'),
('2900112', '29001', '0', '0', '100', '1', '2000', '10000', '7500', '10000', '11', '52922', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'High Inquisitor Valroth - Cast Inquisitor_penance');

UPDATE `gameobject_template` SET `castBarCaption` = 'Valroth\'s Remains' WHERE `entry` = 191092;  -- caption bar message when looting remains

UPDATE `creature_template` SET `EquipmentTemplateId` = 0 WHERE `entry` = 28912;     -- tabled half dead version shouldnt be carrying a axe
UPDATE `creature_template` SET `EquipmentTemplateId` = 488 WHERE `entry` = 28447;   -- this is model with axe

UPDATE `creature_equip_template` SET `equipentry1` = 38633, `equipentry2` = 0 WHERE `entry` = 488; -- make sure axe is right

UPDATE `creature_template_addon` SET `auras` = '52894' WHERE `entry` = 28447;    -- spawned entry should have anti zone magic field

-- tweaked crimsons EAIs
DELETE FROM `creature_ai_scripts` WHERE `id` IN (2900701, 2900702, 2900703);
INSERT INTO `creature_ai_scripts` VALUES ('2900701', '29007', '4', '0', '100', '0', '0', '0', '0', '0', '11', '15498', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '');
INSERT INTO `creature_ai_scripts` VALUES ('2900702', '29007', '0', '0', '100', '1', '1000', '4000', '1000', '4000', '11', '15498', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '');
INSERT INTO `creature_ai_scripts` VALUES ('2900703', '29007', '11', '0', '100', '1', '0', '0', '0', '0', '11', '34809', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '');

-- -----------------------------------------------------
-- Quest how to win friends and how to influence enemies
-- -----------------------------------------------------
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_crusade_persuaded' WHERE `entry` IN (28939,28610);   -- 28640 scarlet crusader needs to be added

-- ---------------------------------------------------------------
-- Quest Death comes From a High
-- ---------------------------------------------------------------
-- Eye of acherus

-- Use proper Hunter's Mark Visual Only
REPLACE INTO `creature_template_addon` (`entry`,`auras`) VALUES
(28525, '64328'),
(28542, '64328'),
(28543, '64328'),
(28544, '64328'); -- aura=51859 and b2_0_sheath=1 in YTDB

UPDATE `creature_template` SET `ScriptName` = 'npc_eye_of_acherus' WHERE `entry` = 28511;

-- -----------------------------------------------------------------------------
-- Quest  Death's Changelle --
-- -----------------------------------------------------------------------------
 
-- bug olrun - is out of interaction reach for smaller races  --
UPDATE `creature` SET `position_x` = 2371.77, `position_y` = -5788.7, `position_z` = 155.61 WHERE `guid` = 96309;

-- --------------------------------------------------------------------
-- Quest Fix Noth Special Brew  (dk starting area quest fix 12716/12717
-- ---------------------------------------------------------------------
UPDATE `quest_template` SET `ExclusiveGroup` = 12716 WHERE `entry` = 12716; -- in YTDB is -12716

-- -------------------------------
-- Quest Into the Realm of Shadows
-- -------------------------------

UPDATE `creature_template` SET `UnitFlags` = 0 WHERE `entry` = 28782;

UPDATE `quest_template` SET `SrcSpell` = 52359, `ReqCreatureOrGOId1` = 28768, `ReqCreatureOrGOCount1` = 1, `ReqSpellCast1` = 0 WHERE `entry` = 12687;

-- DELETE FROM creature_involvedrelation WHERE quest IN (12687); -- this cause drop id 28653 from YTDB
INSERT IGNORE INTO creature_involvedrelation (id, quest) VALUES
(28788, 12687);

UPDATE creature_template SET `NpcFlags` = 2 WHERE entry = 28788;

-- EventAI
UPDATE creature_template SET AIName='EventAI' WHERE entry = 28768;

DELETE FROM creature_ai_scripts WHERE creature_id = 28768;
INSERT INTO creature_ai_scripts VALUES 
('2876801','28768','4','0','100','0','0','0','0','0','1','-780','0','0','0','0','0','0','0','0','0','0','Dark Rider of Acherus - Yell on Aggro'),
('2876802','28768','0','0','100','1','0','1500','6000','9000','11','52372','1','0','0','0','0','0','0','0','0','0','Dark Rider of Acherus - Cast Icy Touch'),
('2876803','28768','0','0','100','1','3000','7000','6000','9000','11','50688','1','0','0','0','0','0','0','0','0','0','Dark Rider of Acherus - Cast Plague Strike'),
('2876804','28768','0','0','100','1','6000','10000','6000','9000','11','52374','1','0','0','0','0','0','0','0','0','0','Dark Rider of Acherus - Cast Blood Strike'),
('2876805','28768','9','0','100','1','5','30','2000','2000','11','52356','1','0','0','0','0','0','0','0','0','0','Dark Rider of Acherus - Cast Throw'),
('2876806','28768','6','0','100','0','0','0','0','0','12','28782','0','10000','15','12687','6','0','43','0','0','0','Dark Rider of Acherus - Spawn Deathcharger of Acherus and Set Quest Event Complete and Dismount on Death');

-- quest 12687
-- riders are on vehicle accessory
DELETE FROM `creature` WHERE id = 28768;
DELETE FROM vehicle_accessory WHERE vehicle_entry = 28782;
INSERT INTO vehicle_accessory  (`vehicle_entry`, `seat`, `accessory_entry`,`comment`) VALUES
(28782, 0, 28768, 'Acherus Deathcharger - Dark Rider of Acherus');

DELETE FROM spell_script_target WHERE entry = 52349;
INSERT INTO spell_script_target (`entry`, `type`, `targetEntry`) VALUES
(52349,1,28782);

DELETE FROM npc_spellclick_spells where npc_entry = 28782;
INSERT INTO npc_spellclick_spells (npc_entry, spell_id, quest_start, cast_flags) values
(28782, 52349, 0, 2);

DELETE FROM dbscripts_on_spell where id = 52361;
INSERT INTO dbscripts_on_spell (id, command, datalong, data_flags, comments) values
(52361, 14, 52349, 6, 'remove Overtake aura'),
(52361, 14, 52693, 6, 'remove Realm of Shadows aura');

DELETE FROM `creature` WHERE id = 28782;
DELETE FROM `creature_template_addon` WHERE entry = 28782;

UPDATE `npc_spellclick_spells` SET `spell_id` = 46598, `quest_start` = 0, `quest_start_active` = 0, `quest_end` = 0 WHERE `npc_entry` = 28782; -- cause corrupt Q12687 from YTDB

-- -----------------------------------
-- Quest The Gift That Keeps On Giving
-- -----------------------------------

-- item spell script targets (Scarlet Miners)
DELETE FROM `spell_script_target` WHERE entry = 52479;
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(52479, 1, 28819),
(52479, 1, 28822),
(52479, 1, 28891);

DELETE FROM `spell_script_target` WHERE entry = 52514;
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(52514, 1, 28845);

-- EventAI for ghost needs tweaked and double checked
UPDATE `creature_template` SET `AIName` = 'EventAI', `ScriptName` = '' WHERE `entry` = 28846;

DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 28846;
INSERT INTO `creature_ai_scripts` VALUES
(2884601, 28846, 11, 0, 100, 0, 0, 0, 0, 0, 1, -286100, -286101, -286102, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Ghost - Random say at spawn");

DELETE FROM `creature_ai_texts` WHERE `entry` IN (-286102, -286101, -286100);
INSERT INTO `creature_ai_texts` (`entry`, `content_default`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-286100, "Die, Scourge filth!", "Сдохни, отродье Плети!", 0, 0, 0, 0, "Scarlet Ghost SAY1"),
(-286101, "It won't be that easy, friend!", "Это не будет просто, друг!", 0, 0, 0, 0, "Scarlet Ghost SAY2"),
(-286102, "I'll take you with me!", "Я заберу тебя с собой!", 0, 0, 0, 0, "Scarlet Ghost SAY3");

-- fix to take Quest Item Away at end of quest
UPDATE `quest_template` SET `ReqItemId1` = 39253, `ReqItemCount1` = 1 WHERE `entry` = 12698;

/* Q:12678 If Chaos Drives, Let Suffering Hold The Reins */
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_scarlet_miner' WHERE `entry` = 28841;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_mine_car' WHERE `entry` = 28817;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_scourge_gryphon' WHERE `entry` = 28864;
UPDATE `gameobject_template` SET `ScriptName` = 'go_inconspicous_mine_car' WHERE `entry` = 190767;
UPDATE `creature_template` SET `MechanicImmuneMask` = 0, `ExtraFlags` = 0 WHERE `entry` = 28864;

-- fixed dispaly of mine car
UPDATE `creature_template` SET `ModelId2` = 25703 WHERE `entry` = 28817;

/* Scourge Gryphon */
UPDATE `creature_template` SET `SpeedRun` = 2 WHERE `entry` = 28864;

DELETE FROM `creature_template_addon` WHERE `entry` = 28864;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `b2_0_sheath`, `b2_1_pvp_state`, `emote`, `moveflags`, `auras`) VALUES
(28864, 0, 0, 0, 0, 0, 0, '61453');

/* Scarlet Cannon */
UPDATE `creature_template` SET `VehicleTemplateId` = 79 WHERE `entry` IN (28833);
DELETE FROM `creature_spell` WHERE `guid` IN (28833);
INSERT INTO `creature_spell` (`guid`, `spell`, `index`, `active`, `disabled`, `flags`) VALUES
(28833, 52435, 0, 0, 0, 0),
(28833, 52576, 1, 0, 0, 0),
(28833, 52588, 4, 0, 0, 0);

DELETE FROM `creature_spell` WHERE `guid` IN (28887);
INSERT INTO `creature_spell` (`guid`, `spell`, `index`, `active`, `disabled`, `flags`) VALUES
(28887, 52435, 0, 0, 0, 0),
(28887, 52576, 1, 0, 0, 0),
(28887, 52588, 4, 0, 0, 0);

UPDATE `creature_template` SET `UnitFlags` = 772, `MinMeleeDmg` = 685, `MaxMeleeDmg` = 715, `Armor` = 3232, `MeleeAttackPower` = 214 WHERE `entry` = 28833;
UPDATE `creature_template` SET `MinLevelHealth` = 26140, `MaxLevelHealth` = 26140, `MinLevelMana` = 0, `MaxLevelMana` = 0, `UnitFlags` = 772, `MinLevel` = 55, `MaxLevel` = 55, `MinMeleeDmg` = 685, `MaxMeleeDmg` = 715, `Armor` = 3232, `MeleeAttackPower` = 214 WHERE `entry` = 28887;
INSERT IGNORE INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(52576, 1, 28834),
(52576, 1, 28886),
(52576, 1, 28850);

-- -------------------------------------
-- ACID scripts for Scarlet Enclave mobs
-- -------------------------------------

-- EventAI scripts name set
UPDATE `creature_template` SET `AIName` = "EventAI", `ScriptName` = "" WHERE entry IN (28834, 28892, 28856, 28850, 29104, 28941, 28942, 28577, 28576, 28557);

-- script_texts
DELETE FROM `creature_ai_texts` WHERE `entry` BETWEEN -286099 AND -286092;
INSERT INTO `creature_ai_texts` (`entry`, `content_default`, `comment`) VALUES
(-286099, "You don't have to do this! Nobody has to die!", "Scarlet Peasant - Say Fear01"),
(-286098, "Let me live! I'll do whatever you say!", "Scarlet Peasant - Say Fear02"),
(-286097, "Ugh... I... I think I pooped...", "Scarlet Peasant - Say Fear03"),
(-286096, "I picked the wrong day to quit drinkin'!", "Scarlet Peasant - Say Fear04"),
(-286095, "Don't kill me! I only took this job for benefits!", "Scarlet Peasant - Say Fear05"),
(-286094, "Have mercy, sir!", "Citizen of Heavenshire - Say Aggro1"),
(-286093, "You may take my life, but you won't take my freedom!", "Citizen of Heavenshire - Say Enrage1"),
(-286092, "DIE!", "Citizen of Heavenshire - Say Enrage2");

-- EVENTAI scripts
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (28834, 28856, 28850, 29104, 28941, 28942, 28577, 28576, 28557, 28892);
INSERT INTO `creature_ai_scripts` VALUES
-- Scarlet Defender
(2883401, 28834, 0, 0, 100, 1, 0, 0, 3000, 3000, 11, 52566, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Defender - Cast Shoot"),
-- Scarlet Guardian
(2885601, 28856, 4, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 0, "Scarlet Guardian - Stop moving and set Phase 2 on aggro"),
(2885602, 28856, 9, 1, 100, 0, 10, 150, 0, 0, 21, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 0, "Scarlet Guardian - Stop moving and set Phase 2 at 10yd range"),
(2885603, 28856, 0, 1, 100, 1, 3000, 3000, 3000, 3000, 11, 25710, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Guardian - Cast Heroic Strike(Phase 1)"),
(2885604, 28856, 0, 2, 100, 1, 0, 0, 3000, 3000, 11, 52566, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Guardian - Cast Shoot(Phase 2)"),
(2885605, 28856, 9, 2, 100, 0, 0, 10, 0, 0, 21, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, "Scarlet Guardian - Set Phase 1 at less then 10yd (Phase 2)"),
(2885606, 28856, 9, 0, 100, 0, 150, 300, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Guardian - Evade 150yd"),
-- Scarlet Land Cannon
(2885001, 28850, 0, 0, 100, 1, 0, 0, 3000, 3000, 11, 52539, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Cannon - Cast Cannonball"),
(2885002, 28850, 9, 0, 100, 0, 150, 300, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Cannon - Evade 150yd"),
-- Scarlet Balista
(2910401, 29104, 0, 0, 100, 1, 0, 0, 3000, 3000, 11, 53117, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Balista - Cast Ballista assault"),
(2910402, 29104, 9, 0, 100, 0, 150, 300, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Balista - Evade 150yd"),
-- Citizens of New Avalon -- needs tweaked
(2894101, 28941, 11, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Avalon - Spawn set Phase 1"),
(2894102, 28941, 0, 0, 80, 1, 0, 0, 10000, 10000, 11, 52716, 1, 1, 22, 2, 0, 0, 1, -286094, -286099, -286095, "Citizen of New Avalon - On Aggro: Escape in fear and set Phase 2"),
(2894103, 28941, 0, 0, 20, 1, 0, 0, 10000, 10000, 11, 52262, 1, 1, 22, 2, 0, 0, 1, -286093, -286092, 0, "Citizens of New Avalon - On Aggro: Enrage and set Phase 2"),
(2894201, 28942, 11, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Avalon - Spawn set Phase 1"),
(2894202, 28942, 0, 0, 80, 1, 0, 0, 10000, 10000, 11, 52716, 1, 1, 22, 2, 0, 0, 1, -286094, -286099, -286096, "Citizen of New Avalon - On Aggro: Escape in fear and set Phase 2"),
(2894203, 28942, 0, 0, 20, 1, 0, 0, 10000, 10000, 11, 52262, 1, 1, 22, 2, 0, 0, 1, -286093, -286092, 0, "Citizens of New Avalon - On Aggro: Enrage and set Phase 2"),
-- Citizens of Havenshire -- needs tweaked
(2857601, 28576, 11, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Citizen of New Havenshire - Spawn set Phase 1"),
(2857602, 28576, 4, 0, 80, 0, 0, 0, 0, 0, 11, 52716, 1, 1, 1, -286094, -286099, -286096, 0, 0, 0, 0, "Citizen of Havenshire - On Aggro: Beg for mercy"),
(2857603, 28576, 0, 0, 100, 1, 0, 0, 1000, 1000, 20, 0, 0, 0, 21, 0, 0, 0, 5, 20, 0, 0, "Citizen of Havenshire - Cower (Phase 3)"),
(2857604, 28576, 4, 0, 20, 0, 0, 0, 0, 0, 11, 52262, 1, 1, 1, -286093, -286092, 0, 0, 0, 0, 0, "Citizens of Havenshire - On Aggro: Enrage"),
(2857605, 28576, 7, 0, 100, 0, 0, 0, 0, 0, 5, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, "Citizens of Havenshire - Reset State"),

(2857701, 28577, 11, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Citizen of Havenshire - Spawn set Phase 1"),
(2857702, 28577, 4, 0, 80, 0, 0, 0, 0, 0, 11, 52716, 1, 1, 1, -286094, -286099, -286095, 22, 3, 0, 0, "Citizen of Havenshire - On Aggro: Beg for mercy"),
(2857703, 28577, 0, 0, 100, 1, 0, 0, 1000, 1000, 20, 0, 0, 0, 5, 431, 0, 0, 21, 0, 0, 0, "Citizen of Havenshire - Cower (Phase 3)"),
(2857704, 28577, 4, 0, 20, 0, 0, 0, 0, 0, 11, 52262, 1, 1, 1, -286093, -286092, 0, 0, 0, 0, 0, "Citizens of Havenshire - On Aggro: Enrage"),
(2857705, 28577, 7, 0, 100, 0, 0, 0, 0, 0, 5, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, "Citizens of Havenshire - Reset State"),
-- Scarlet Peasant -- needs tweaked
(2855701, 28557, 11, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Peasant - Spawn set Phase 1"),
(2855702, 28557, 4, 1, 80, 0, 0, 0, 0, 0, 11, 52716, 1, 1, 1, -286099, -286098, -286097, 22, 2, 0, 0, "Scarlet Peasant - On Aggro: Beg for mercy"),
(2855703, 28557, 0, 0, 100, 1, 0, 0, 1000, 1000, 20, 0, 0, 0, 5, 20, 0, 0, 21, 0, 0, 0, "Scarlet Peasant - Cower (Phase 2)"),
(2855704, 28557, 7, 0, 100, 0, 0, 0, 0, 0, 5, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, "Scarlet Peasant - Reset State"),
(2889201, 28892, 11, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Scarlet Peasant - Spawn set Phase 1"),
(2889202, 28892, 4, 1, 80, 0, 0, 0, 0, 0, 11, 52716, 1, 1, 1, -286099, -286098, -286097, 22, 2, 0, 0, "Scarlet Peasant - On Aggro: Beg for mercy"),
(2889203, 28892, 0, 0, 100, 1, 0, 0, 1000, 1000, 20, 0, 0, 0, 5, 20, 0, 0, 21, 0, 0, 0, "Scarlet Peasant - Cower (Phase 2)"),
(2889204, 28892, 7, 0, 100, 0, 0, 0, 0, 0, 5, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, "Scarlet Peasant - Reset State");

-- end of EventAI
-- -----------------------------------------------------------------------------------------------------------------------------------------------------
