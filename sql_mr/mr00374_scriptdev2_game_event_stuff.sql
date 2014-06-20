-- -------------------------------
-- headless horseman event texts -
-- -------------------------------

DELETE FROM script_texts WHERE entry BETWEEN -1110006 AND -1110001;
INSERT INTO script_texts (entry, content_default, TYPE, sound) VALUES
(-1110001, "Prepare yourselves, the bells have tolled! Shelter your weak, your young and your old! Each of you shall pay the final sum. Cry for mercy, the reckoning has come!",1,11966),
(-1110002, "The sky is dark. The fire burns. You strive in vain as Fate's wheel turns.",1,12570),
(-1110003, "The town still burns, a cleansing fire! Time is short, I'll soon retire!",1,12571),

(-1110004, "Fire consumes! You've tried and failed. Let there be no doubt, justice prevailed!",1,11967),
(-1110005, "My flames have died, left not a spark. I shall send you myself, to the lifeless dark.",1,11968);

-- ------------------------------
-- Pilgrim's bounty event texts -
-- ------------------------------

DELETE FROM `script_texts` WHERE `entry` in (-1730001, -1730002, -1730003, -1730004);
INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc8`, `type`, `comment`) VALUES
(-1730001, 'Turkey Hunter!', 'Охотник на индеек!', 3, 'Pilgrim\'s Bounty - 10 Wild Turkeys killed'),
(-1730002, 'Turkey Domination!', 'Повелитель индеек!', 3, 'Pilgrim\'s Bounty - 20 Wild Turkeys killed'),
(-1730003, 'Turkey Slaughter!', 'Истребитель индеек!', 3, 'Pilgrim\'s Bounty - 30 Wild Turkeys killed'),
(-1730004, 'TURKEY TRIUMPH!', 'ТРИУМФ НАД ИНДЕЙКАМИ!', 3, 'Pilgrim\'s Bounty - 40 Wild Turkeys killed');
