-- -1 608 000 VIOLET HOLD
DELETE FROM `script_texts` WHERE entry BETWEEN -1608071 AND -1608029;
INSERT IGNORE INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
-- Erekem
(-1608066, '...', 14222, 1, 0, 'erekem SAY_SLAY_1'),
(-1608067, 'Precious life ... wasted.', 14223, 1, 0, 'erekem SAY_SLAY_2'),
(-1608068, 'Only strong ... survive.', 14224, 1, 0, 'erekem SAY_SLAY_3'),
-- Ichoron
(-1608069, 'I... am fury... unrestrained!', 14239, 1, 0, 'ichoron SAY_SPAWN'),
-- Xevozz
(-1608070, 'It seems my freedom must be bought with blood...', 14499, 1, 0, 'xevozz SAY_AGGRO'),
(-1608071, 'Nothing personal.', 14504, 1, 0, 'xevozz SAY_SLAY_1'),
(-1608029, 'Business concluded.', 14505, 1, 0, 'xevozz SAY_SLAY_2'),
(-1608030, 'Profit!', 14506, 1, 0, 'xevozz SAY_SLAY_3'),
(-1608031, 'This is an... unrecoverable... loss.', 14507, 1, 0, 'xevozz SAY_DEATH'),
(-1608033, 'It would seem that a renegotiation is in order.', 14503, 1, 0, 'xevozz SAY_CHARGED'),
(-1608034, 'The air teems with latent energy... quite the harvest!', 14501, 1, 0, 'xevozz SAY_REPEAT_SUMMON_1'),
(-1608035, 'Plentiful, exploitable resources... primed for acquisition!', 14502, 1, 0, 'xevozz SAY_REPEAT_SUMMON_2'),
(-1608036, 'Intriguing... a high quantity of arcane energy is near. Time for some prospecting...', 14500, 1, 0, 'xevozz SAY_SUMMON_ENERGY'),
-- Zuramat
(-1608037, 'Eradicate.', 13996, 1, 0, 'zuramat SAY_AGGRO'),
(-1608038, 'More... energy.', 13999, 1, 0, 'zuramat SAY_SLAY_1'),
(-1608039, 'Relinquish.', 14000, 1, 0, 'zuramat SAY_SLAY_2'),
(-1608040, 'Fall... to shadow.', 14001, 1, 0, 'zuramat SAY_SLAY_3'),
(-1608041, 'Disperse.', 14002, 1, 0, 'zuramat SAY_DEATH'),
(-1608043, 'Know... my... pain.', 13997, 1, 0, 'zuramat SAY_SHIELD'),
(-1608044, 'Gaze... into the void.', 13998, 1, 0, 'zuramat SAY_WHISPER'),
-- Cyanigosa
(-1608045,'A valiant defense, but this city must be razed. I will fulfill Malygos wishes myself!', 13946, 1, 0,'A_VH_Cyanigosa_Spawn'),
(-1608046,'We finish this now, champions of Kirin Tor!',13947,1,0,'A_VH_Cyanigosa_Aggro'),
(-1608047,'Shiver and die!',13948,1,0,'A_VH_Cyanigosa_BreathAttack'),
(-1608048,'The world has forgotten what true magic is! Let this be a reminder!',13949,1,0,'A_VH_Cyanigosa_SpecialAttack01'),
(-1608049,'Who among you can withstand my power?',13950,1,0,'A_VH_Cyanigosa_SpecialAttack02'),
(-1608050,'Am I interrupting?',13951,1,0,'A_VH_Cyanigosa_Disruption'),
(-1608051,'I will end the Kirin Tor!',13952,1,0,'A_VH_Cyanigosa_Slay01'),
(-1608052,'Dalaran will fall!',13953,1,0,'A_VH_Cyanigosa_Slay02'),
(-1608053,'So ends your defiance of the Spell-Weaver!',13954,1,0,'A_VH_Cyanigosa_Slay03'),
(-1608054,'Perhaps... we have... underestimated... you.',13955,1,0,'A_VH_Cyanigosa_Death01'),
-- Azures
(-1608055,'The Kirin Tor must be stopped!',0,0,0,'AZURE_SAY_AGGRO_1'),
(-1608056,'Dalaran must fall!',0,0,0,'AZURE_SAY_AGGRO_2'),
(-1608057,'The Nexus War will not be stopped!',0,0,0,'AZURE_SAY_AGGRO_3'),
(-1608058,'For the Spellweaver!',0,0,0,'AZURE_SAY_AGGRO_4'),
(-1608059,'The destruction of Dalaran is inevitable!',0,1,0,'Portal Keeper/Guardian AGGRO_1'),
(-1608060,'The portal has stabilized! Attack!',0,1,0,'Portal Keeper/Guardian AGGRO_2'),
(-1608064,'The way into Dalaran has been opened!',0,1,0,'Portal Guardian AGGRO_3'),
(-1608061,'More portals will take this one\'s place!',0,1,0,'Portal Keeper/Guardian DEATH_1'),
(-1608062,'Why do you defend the Kirin Tor...',0,1,0,'Portal Keeper/Guardian DEATH_2'),
(-1608063,'My death will not stop the invasion!',0,1,0,'Portal Keeper/Guardian DEATH_2'),
(-1608065,'Destroy all who stand against us!',0,0,0,'Azure Captain AGGRO_1');

