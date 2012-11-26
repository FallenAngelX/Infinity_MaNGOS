-- ------------------------------------- --
-- ------- I am a temporary file ------- --
-- After a month my data will be deleted --
-- ------------------------------------- --
-- ===================================== --

-- ---------- --
-- 2012-11-26 --
-- ---------- --
/*
mob_erekem_guard -> npc_erekem_guard
npc_violet_portal -> npc_teleportation_portal
npc_door_seal_vh -> npc_door_seal
mob_soul_fragment -> npc_corrupted_soul_fragment
boss_ragefire -> boss_saviana
boss_colossus -> boss_drakkari_colossus
boss_drakari_elemental -> boss_drakkari_elemental
*/
UPDATE creature_template SET ScriptName = 'npc_erekem_guard' WHERE `entry`= 29395;
UPDATE creature_template SET ScriptName = 'npc_teleportation_portal' WHERE `entry` = 31011;
UPDATE creature_template SET ScriptName = 'npc_door_seal' WHERE `entry` = 30896;
UPDATE creature_template SET ScriptName = 'npc_corrupted_soul_fragment' WHERE `entry` = 36535;
UPDATE creature_template SET ScriptName = 'boss_saviana' WHERE `entry` = 39747;
UPDATE creature_template SET ScriptName = 'boss_drakkari_colossus' WHERE `entry` = 29307;
UPDATE creature_template SET ScriptName = 'boss_drakkari_elemental' WHERE `entry` = 29573;
