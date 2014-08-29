
ALTER TABLE `game_event`
  ADD COLUMN `silent` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'Don''t show in event announce'
  AFTER `description`;

UPDATE `game_event`
   SET `silent` = 1
   WHERE `entry` IN (13, 16, 17, 23, 24, 25, 27, 28, 31, 33, 39, 43, 44, 48, 62, 63, 70, 71, 72);
