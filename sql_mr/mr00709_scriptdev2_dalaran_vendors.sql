
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN
  (28714,28715,28718,28721,28723,28725,28726,28727,28989,28994,28997,29491,29523,33027);

UPDATE `creature_template` SET AIName = '', `ScriptName`='npc_dalaran_vendor' WHERE `entry` IN
  (28714,28715,28718,28721,28723,28725,28726,28727,28989,28994,28997,29491,29523,33027);

INSERT INTO script_texts
  (entry, content_default, content_loc8, sound, type, language, emote, comment)
VALUES
  (-1020384, "Welcome.", "Добро пожаловать.", 0, 0, 0, 3, "SAY_VENDOR_1"),
  (-1020385, "Welcome!", "Добро пожаловать!", 0, 0, 0, 3, "SAY_VENDOR_2"),
  (-1020386, "Welcome. May I help you find something?", "Добро пожаловать. Могу ли я вам помочь что то найти?", 0, 0, 0, 3, "SAY_VENDOR_3"),
  (-1020387, "Greetings.", "Приветствую.", 0, 0, 0, 3, "SAY_VENDOR_4"),
  (-1020388, "Greetings, $C.", "Приветствую $C.", 0, 0, 0, 3, "SAY_VENDOR_5"),
  (-1020389, "Greetings! Please have a look around.", "Приветствую! Пожалуйста, посмотрите вокруг.", 0, 0, 0, 3, "SAY_VENDOR_6"),
  (-1020390, "Let me know if you need help finding anything, $C.", "Дайте мне знать, если вам нужна помощь найти что-нибудь, $C.", 0, 0, 0, 3, "SAY_VENDOR_7");
