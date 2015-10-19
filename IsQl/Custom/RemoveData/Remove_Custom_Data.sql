-- Remove Data
DELETE FROM creature_template WHERE entry >= 100000 AND entry <= 100169;
DELETE FROM gameobject_template WHERE entry >= 500000 AND entry <= 500169;
DELETE FROM gameobject_template WHERE entry >= 1 AND entry <= 16; -- real game DB starts at id 17
DELETE FROM npc_vendor WHERE entry >= 100000 AND entry <= 100166;
DELETE FROM creature WHERE guid >= 500200 AND guid <= 500400;
DELETE FROM  gameobject WHERE guid >= 500200 AND guid <= 500300;

-- remove texts
DELETE FROM script_texts WHERE entry in (-1001007, -1001008);
DELETE FROM `gossip_texts` WHERE `entry` BETWEEN -3000773 AND -3000770;
DROP TABLE IF EXISTS `guildhalls`;
DROP TABLE IF EXISTS `teleportmaster_categories`;
DROP TABLE IF EXISTS `teleportmaster_locations`;

-- Remove spawns
DELETE FROM creature WHERE guid >= 500200 AND guid <= 500400;
DELETE FROM  gameobject WHERE guid >= 500200 AND guid <= 500300;
