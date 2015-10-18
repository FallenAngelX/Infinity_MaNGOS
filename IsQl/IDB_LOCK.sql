SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `I_DataBase_version`;
CREATE TABLE `I_DataBase_version` (
  `version` varchar(120) NOT NULL,
  `r00` bit(1) default NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='This is a lock to keep I_DB as Idiot Proof as Possible';

INSERT INTO `I_DataBase_version` VALUES ('r00', null);

--- FallenAngelX
/*ALTER TABLE I_DataBase_version CHANGE COLUMN r00 r01 bit;
REPLACE INTO `I_DataBase_version` (`version`) VALUES ('r01');

UPDATE db_version SET `cache_id`= 'r01';
UPDATE db_version SET `version`= 'I_DataBase_r01';