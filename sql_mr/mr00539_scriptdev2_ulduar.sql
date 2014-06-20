/* ULDUAR from Xfurry*/
-- -1 603 000 ULDUAR

DELETE FROM `script_texts` WHERE `entry` = -1603013;
-- translate from lanc
INSERT INTO `script_texts` (entry, content_default, content_loc1, content_loc2, content_loc3, content_loc4, content_loc5, content_loc6, content_loc7, content_loc8, sound, type, language, emote, comment) VALUES
(-1603013,'Freya casts Strenghtened Iron Roots!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_iron roots');

/*
-- Ignis:
(-1603020, "Insolent whelps! Your blood will temper the weapons used to reclaim this world!", "","","","","","","","Мерзкие глупцы! Ваша кровь закалит оружие, которым был завоеван этот мир!",15564, 1, 0, 0, 'IgnisAggro'),
(-1603021, "Let the inferno consume you!", "","","","","","","","Да поглотит вас пламя преисподней!",15567, 1, 0, 0, 'Ignis Scorch1'),
(-1603022, "BURN! Burn in the makers fire!", "","","","","","","","Горите! Горите в огне творца!",15568, 1, 0, 0, 'Ignis scroch2'),
(-1603023, "I will burn away your impurities!", "","","","","","","","Пройдите очищение огнем!",15566, 1, 0, 0, 'Ignis Slagpot'),
(-1603024, 'Ignis the Furnace Master begins to cast Flame Jets!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_FLAME_JETS'),
(-1603025, "Arise, soldiers of the Iron Crucible! The Makers\' will be done!", "","","","","","","","Вперед, воины Железного Тетинга! Да свершиться воля творца!",15565, 1, 0, 0, 'Ignis summon'),
(-1603026, "More scraps for the scrapheap!", "","","","","","","","Тебе место в мусорной куче!",15569, 1, 0, 0, 'IgnisSlay1'),
(-1603027, "Your bones will serve as kindling!", "","","","","","","","Твой кости пойдут на растопку!",15570, 1, 0, 0, 'IgnisSlay2'),
(-1603028, "Let it be finished!", "","","","","","","","Покончим с этим!",15571, 1, 0, 0, 'IgnisBerserk'),
(-1603029, "I. Have. Failed.", "","","","","","","","Я... Проиграл...",15572, 1, 0, 0, 'Ignis death'),

-- razorscale
(-1603030,'Welcome, champions! All of our attempts at grounding her have failed. We could use a hand in bring her down with these harpoon guns.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Приветствую вас герои! Все наши попытки сбить ее не увенчались успехом. Нам бы пригодилась ваша помощь, гарпунных пушек на всех хватит.",15647,0,0,0,'razorscale intro - commander'),
(-1603031,'Give us a moment to prepare to build the turrets.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'razor aggro 1 - eng'),
(-1603032,'Be on the lookout! Mole machines will be surfacing soon with those nasty Iron dwarves aboard!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'razor aggro 2 - commander'),
(-1603033,'Ready to move out, keep those dwarves off of our backs!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'razor aggro 3 - eng'),
(-1603034,'Move! Quickly! She won\'t remain grounded for long.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Быстрее! Она скоро снова взлетит.",0,1,0,0,'razor ground - commander'),
(-1603035,'Razorscale takes a deep breath...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'razor deep breath'),
(-1603036,'Fires out! Let\'s rebuild those turrets!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'razor extinguish fires'),
(-1603337,'Harpoon Turret is ready for use!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_harpoon'),
(-1603338,'Razorscale grounded permanently!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_ground'),

-- Xt002
(-1603040,"You are bad... Toys... Very... Baaaaad!","","","","","","","","Плохие игрушки... Очень... Плохие!",15731,1,0,0,"XT-002 Death"),
(-1603041,"I'm tired of these toys. I don't want to play anymore!","","","","","","","","Какие скучные игрушки. Надоело играть!",15730,1,0,0,"XT-002 Berserk"),
(-1603042,"Time for a new game! My old toys will fight my new toys!","","","","","","","","Новые правила! Старые игрушки против новых!",15732,1,0,0,"XT-002 Adds"),
(-1603043,"I'm ready to play!","","","","","","","","Продолжаем игру!",15726,1,0,0,"XT-002 Heart Closed"),
(-1603044,"So tired. I will rest for just a moment!","","","","","","","","Я так устал. Отдохну чуток!",15725,1,0,0,"XT-002 Heart Opened"),
(-1603045,"I guess it doesn't bend that way.","","","","","","","","Наверное в эту сторону голова не гнулась.",15729,1,0,0,"XT-002 Slay 2"),
(-1603046,"I... I think I broke it.","","","","","","","","Кажется... Я сломал эту игрушку.",15728,1,0,0,"XT-002 Slay 1"),
(-1603047,"NO! NO! NO! NO! NO!","","","","","","","","Неееет! Нет! Нет! Нет! Нет!",15727,1,0,0,"XT-002 Tympanic Tantrum"),
(-1603048,"New toys? For me? I promise I won't break them this time!","","","","","","","","Новые игрушки? Для меня? Обещаю, в этот раз я их не поламаю!",15724,1,0,0,"XT-002 Aggro"),
(-1603049,'XT-002 Deconstructor\'s heart is exposed and leaking energy!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_expose_heart'),
(-1603050,'XT-002 Deconstructor consumes a scrapbot to repair himself.' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_repair'),

-- Iron Council
-- Molgeim
(-1603060,"Nothing short of total decimation will suffice!","","","","","","","","",15657,1,0,0,"MolgeimAggro"),
(-1603061, "The legacy of storms shall not be undone...", "","","","","","","","",15662, 1, 0, 0, "MolgeimDeath1"),
(-1603062, "What have you gained from my defeat? You are no less doomed, mortals...", "","","","","","","","",15663, 1, 0, 0, 'MolgeimDeath2'),
(-1603063, "Decipher this!", "","","","","","","","",15660, 1, 0, 0, 'MolgeimDeathRune'),
(-1603064, "Face the lightning surge!", "","","","","","","","",15661, 1, 0, 0, 'MolgeimSummon'),
(-1603065, "The world on suffers yet another insignificant loss!", "","","","","","","","",15658, 1, 0, 0, 'MolgeimSlay1'),
(-1603066, "Death is the price of your arrogance.", "","","","","","","","",15659, 1, 0, 0, 'MolgeimSlay2'),
(-1603067, "This meeting of the Assembly of Iron is adjourned!", "","","","","","","","",15664, 1, 0, 0, 'MolgeimBerserk'),
-- Steelbreaker
(-1603070, "You will not defeat the Assembly of Iron so easily, invaders!", "","","","","","","","",15674, 1, 0, 0, 'SteelAggro'),
(-1603071, "My death only serves to hasten your demise.", "","","","","","","","",15678, 1, 0, 0, 'SteelDeath1'),
(-1603072, "Impossible!", "","","","","","","","",15679, 1, 0, 0, 'SteelDeath2'),
(-1603073, "So fragile and weak!", "","","","","","","","",15675, 1, 0, 0, 'SteelSlay1'),
(-1603074, "Flesh... such a hindrance.", "","","","","","","","",15676, 1, 0, 0, 'SteelSlay2'),
(-1603075, "You seek the secrets of Ulduar? Then take them!", "","","","","","","","",15677, 1, 0, 0, 'SteelOverwhelming'),
(-1603076, "This meeting of the Assembly of Iron is adjourned!", "","","","","","","","",15680, 1, 0, 0, 'SteelBerserk'),
-- Brudir
(-1603080, "Whether the world\'s greatest gnats or the world\'s greatest heroes, you\'re still only mortal.", "","","","","","","","",15684, 1, 0, 0, 'BrundirAggro'),
(-1603081, "Stand still and stare into the light!", "","","","","","","","",15687, 1, 0, 0, 'BrundirWhirl'),
(-1603082, "The power of the storm lives on...", "","","","","","","","",15689, 1, 0, 0, 'BrundirDeath1'),
(-1603083, "You rush headlong into the maw of madness!", "","","","","","","","",15690, 1, 0, 0, 'BrundirDeath2'),
(-1603084, "A merciful kill!", "","","","","","","","",15685, 1, 0, 0, 'BrundirSlay1'),
(-1603085, "HAH!", "","","","","","","","",15686, 1, 0, 0, 'BrundirSlay2'),
(-1603086, "This meeting of the Assembly of Iron is adjourned!", "","","","","","","","",15691, 1, 0, 0, 'BrundirBerserk'),
(-1603087, "Let the storm clouds rise and rain down death from above!", "","","","","","","","",15688, 1, 0, 0, 'BrundirFly'),

-- Kologarn:
(-1603090, "None shall pass!", "","","","","","","","Вам не пройти!",15586, 1, 0, 0, 'KologarnAggro'),
(-1603091, "OBLIVION!", "","","","","","","","Забвение",15591, 1, 0, 0, 'Kologarn shockweave'),
(-1603092, "I will squeeze the life from you!", "","","","","","","","Я лишу тебя жизни!",15592, 1, 0, 0, 'Kologarn grab'),
(-1603093, "Just a scratch!", "","","","","","","","Царапина!",15589, 1, 0, 0, 'left arm lost'),
(-1603094, "Only a flesh wound!", "","","","","","","","Всего лиш плоть!",15590, 1, 0, 0, 'right arm lost'),
(-1603095, "KOL-THARISH!", "","","","","","","","Кол-Таариш!",15587, 1, 0, 0, 'KologarnSlay1'),
(-1603096, "YOU FAIL!", "","","","","","","","Тебе конец!",15588, 1, 0, 0, 'KologarnSlay2'),
(-1603097, "I am invincible!", "","","","","","","","Я не победим!",15594, 1, 0, 0, 'KologarnBerserk'),
(-1603098, "Master, they come...", "","","","","","","","Повелитель, они идут...",15593, 1, 0, 0, 'Kologarndeath'),
(-1603099,'The Right Arm has regrown!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_right hand'),
(-1603100,'The Left Arm has regrown!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_left hand'),
(-1603101,'Kologarn casts Stone Grip!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_stone grip'),

-- Auriaya:
(-1603110,"Some things are better left alone!","","","","","","","","Вы зря сюда заявились!",15473,1,0,0,"auriaya aggro"),
(-1603112,"The secret dies with you!","","","","","","","","Эта тайна умрет вместе с тобой!",15474,1,0,0,"auriaya Slay 1"),
(-1603111,"There is no escape!","","","","","","","","Спасения нет!",15475,1,0,0,"auriaya Slay 2"),
(-1603113,"You waste my time!","","","","","","","","Вы попусту тратите мое время!",15477,1,0,0,"auriaya berserk"),
(-1603114,"Auriaya screams in agony.","","","","","","","","Ааааааааааааааааааааа!",15476,2,0,0,"auriaya death"),
(-1603115,'Auriaya begins to cast Terrifying Screech.' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_screech'),
(-1603116,'Auriaya begins to activate the Feral Defender!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_defender'),

-- Hodir
(-1603120,"<Furious Roar>","","","","","","","","",15556,2,0,0,"Hodir Frozen Blows"),
(-1603121,"Winds of the north consume you!","","","","","","","","Да поглотят вас северные ветры!",15555,1,0,0,"Hodir Flash Freeze"),
(-1603122,"Welcome to the endless winter.","","","","","","","","Отправляйся туда, где вечная зима.",15554,1,0,0,"Hodir Slay 2"),
(-1603123,"Tragic. To come so far, only to fail.","","","","","","","","Как трагично. Проделать такой путь, чтобы умереть.",15553,1,0,0,"Hodir Slay 1"),
(-1603124,"I... I am released from his grasp... at last.","","","","","","","","Наконецто... Я... Свободен... От его оков.",15557,1,0,0,"Hodir Death"),
(-1603125,"You will suffer for this trespass!","","","","","","","","Вы будете наказаны за это вторжение!",15552,1,0,0,"Hodir Aggro"),
(-1603126,"The veil of winter will protect you, champions!","","","","","","","","Герои, вас защитит покров зимы!",15559,1,0,0,"Hodir yogg"),
(-1603127,"Enough! This ends now!","","","","","","","","Ну хватит! Больше вам не жить!",15558,1,0,0,"Hodir berserk"),
(-1603128,'Hodir begins to cast Flash Freeze!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_flash freeze'),
(-1603129,'Hodir gains Frozen Blows!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_frozen blows'),
-- (-1603130,????????????????,'EMOTE_SPEEDKILL'),

-- Freya: 
(-1603140,"The Conservatory must be protected!","","","","","","","","Нужно защитить оранжерею!",15526,1,0,0,"freya aggro"),
(-1603141,"Elders, grant me your strength!","","","","","","","","Древние, дайте мне силы!",15527,1,0,0,"freya aggro hard"),
(-1603142,"Eonar, your servant requires aid!","","","","","","","","Эонар, твоей прислужнице нужна помощь!",15528,1,0,0,"summon conservator"),
(-1603143,"Children, assist me!","","","","","","","","Помогите мне, дети мои!",15533,1,0,0,"summon trio"),
(-1603144,"The swarm of the elements shall overtake you!","","","","","","","","Вас захлестнет сила стихий!",15534,1,0,0,"summon lashers"),
(-1603145,"Forgive me.","","","","","","","","Прости меня.",15529,1,0,0,"freya slay1"),
(-1603146,"From your death springs life anew!","","","","","","","","Твоя смерть даст начало новой жизни!",15530,1,0,0,"freya slay2"),
(-1603147,"His hold on me dissipates. I can see clearly once more. Thank you, heroes.","","","","","","","","Он больше не властен надо мной. Мой взор снова ясен. Благадорю вас, герои.",15531,1,0,0,"freya Death"),
(-1603148,"You have strayed too far, wasted too much time!","","","","","","","","Вы проделали весь этот путь, впустую!",15532,1,0,0,"freya berserk"),
(-1603149,"Eonar, your servant calls for your blessing!","","","","","","","","Эонар, прошу тебя даруй свое благословение!",15535,1,0,0,"freya yogg"),

-- Brightleaf
(-1603160,"Matron, the Conservatory has been breached!","","","","","","","","",15483,1,0,0,"brightleaf aggro"),
(-1603161,"Fertilizer.","","","","","","","","",15485,1,0,0,"brightleaf slay1"),
(-1603162,"Your corpse will nourish the soil!","","","","","","","","",15486,1,0,0,"brightleaf slay2"),
(-1603163,"Matron, one has fallen!","","","","","","","","",15487,1,0,0,"brightleaf dead"),
-- Ironbranch
(-1603170,"Mortals have no place here!","","","","","","","","",15493,1,0,0,"ironbranch aggro"),
(-1603171,"I return you whence you came!","","","","","","","","",15494,1,0,0,"ironbranch slay1"),
(-1603172,"BEGONE!","","","","","","","","",15495,1,0,0,"ironbranch slay2"),
(-1603173,"Freya! They come for you.","","","","","","","","",15496,1,0,0,"summon trio"),
-- Stonebark
(-1603180,"This place will serve as your graveyard.","","","","","","","","",15500,1,0,0,"stonebark aggro"),
(-1603181,"<Angry roar>","","","","","","","","",15501,1,0,0,"stonebark slay1"),
(-1603182,"Such a waste.","","","","","","","","",15502,1,0,0,"stonebark slay2"),
(-1603183,"Matron, flee! They are ruthless....","","","","","","","","",15503,1,0,0,"stonebark death"),

-- Leviathan: needs intro & outro
(-1603002,"Threat assessment routine modified. Current target threat level: zero. Acquiring new target.","","","","","","","","Изменение в протоколе оценки угрозы. Уровень угрозы текущей цели: нулевой. Поиск новой цели.",15521,1,0,0,"Flame Leviathan Slay"),
(-1603003,"Total systems failure. Defense protocols breached. Leviathan Unit shutting down.","","","","","","","","Общий системный сбой. Отказ защитных протоколов. Боевая единица Левиафан завершает свою работу.",15520,1,0,0,"Flame Leviathan Death"),
(-1603004,"Hostile entities detected. Threat assessment protocol active. Primary target engaged. Time minus thirty seconds to re-evaluation.","","","","","","","","Обнаружены противники. Запуск протокола оценки угрозы. Главная цель выявлена. Повторный анализ через тридцать секунд.",15506,1,0,0,"Flame Leviathan Aggro"),
(-1603005,"Threat re-evaluated. Target assessment complete. Changing course.","","","","","","","","Повторный анализ угрозы - завершен. Оценка цели - проведена. Смена курса.",15507,1,0,0,"Flame Leviathan change1"),
(-1603006,"Pursuit objective modified. Changing course.","","","","","","","","Изменение цели преследования. Смена курса.",15508,1,0,0,"Flame Leviathan change2"),
(-1603007,"Hostile entity stratagem predicted. Rerouting battle function. Changing course.","","","","","","","","Вражеский маневр предупрежден. Перерасчет параметра боевых функций. Смена курса.",15509,1,0,0,"Flame Leviathan change3"),
(-1603008,"Unauthorized entity attempting circuit overload. Activating anti-personnel countermeasures.","","","","","","","","Несанкционированное вмешательство в работу. Активация системы подавления живой силы.",15516,1,0,0,"Flame Leviathan player on top"),
(-1603009,"System malfunction. Diverting power to support systems.","","","","","","","","Функциональный сбой. Активация резервных систем.",15517,1,0,0,"Flame Leviathan overload1"),
(-1603010,"Combat matrix overload. Powering do-o-o-own...","","","","","","","","Боевая матрица перегружена. Отключи....",15518,1,0,0,"Flame Leviathan overload2"),
(-1603011,"System restart required. Deactivating weapon systems.","","","","","","","","Требуется перезапуск. Отключение систем вооружения.",15519,1,0,0,"Flame Leviathan overload3"),
(-1603012,"Orbital countermeasures enabled.","","","","","","","","Система орбитального подавления - включена.",15510,1,0,0,"Flame Leviathan hard mode"),
(-1603013,"Alert! Static defense system failure. Orbital countermeasures disabled.","","","","","","","","Тревога! Сбой стационарных средств защиты. Система орбитального подавления - отключена.",15511,1,0,0,"Flame Leviathan towers down"),
(-1603014,"'Hodir's Fury' online. Acquiring target.","","","","","","","","Ярость Ходира - активирована. Поиск цели.",15512,1,0,0,"Flame Leviathan frost"),
(-1603015,"'Mimiron's Inferno' online. Acquiring target.","","","","","","","","Адский огонь Мимирона - активировано. Поиск цели.",15513,1,0,0,"Flame Leviathan fire"),
(-1603016,"'Thorim's Hammer' online. Acquiring target.","","","","","","","","Молот Торима - активирован. Поиск цели.",15515,1,0,0,"Flame Leviathan energy"),
(-1603017,"'Freya's Ward' online. Acquiring target.","","","","","","","","Оберег Фреи - активировано. Поиск цели.",15514,1,0,0,"Flame Leviathan nature"),
(-1603018,'PursueWarn' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_pursue'),

-- Thorim:
(-1603190,"Interlopers! You mortals who dare to interfere with my sport will pay... Wait--you...","","","","","","","","",15733,1,0,0,"thorim aggro 1"),
(-1603191,"I remember you... In the mountains... But you... what is this? Where am--","","","","","","","","",15734,1,0,0,"thorim aggro 2"),
(-1603192,"Behold the power of the storms and despair!","","","","","","","","",15735,1,0,0,"thorim special 1"),
(-1603193,"Do not hold back! Destroy them!","","","","","","","","",15736,1,0,0,"thorim special 2"),
(-1603194,"Have you begun to regret your intrusion?","","","","","","","","",15737,1,0,0,"thorim special 3"),
(-1603195,"Impertinent whelps! You dare challenge me atop my pedestal! I will crush you myself!","","","","","","","","",15738,1,0,0,"thorim jump"),
(-1603196,"Can't you at least put up a fight!?","","","","","","","","",15739,1,0,0,"thorim slay1"),
(-1603197,"Pathetic!","","","","","","","","",15740,1,0,0,"thorim slay2"),
(-1603198,"My patience has reached its limit!","","","","","","","","",15741,1,0,0,"Thorim berserk"),
(-1603199,"Failures! Weaklings!","","","","","","","","",15742,1,0,0,"thorim arena wipe"),
(-1603200,"Stay your arms! I yield!","","","","","","","","",15743,1,0,0,"thorim defeat"),
(-1603201,"I feel as though I am awakening from a nightmare, but the shadows in this place yet linger.","","","","","","","","",15744,1,0,0,"thorim outro n1"),
(-1603202,"Sif... was Sif here? Impossible--she died by my brother's hand. A dark nightmare indeed....","","","","","","","","",15745,1,0,0,"thorim outro n2"),
(-1603203,"I need time to reflect.... I will aid your cause if you should require it. I owe you at least that much. Farewell.","","","","","","","","",15746,1,0,0,"thorim outro n3"),
(-1603204,"You! Fiend! You are not my beloved! Be gone!","","","","","","","","",15747,1,0,0,"thorim outro hard1"),
(-1603205,"Behold the hand behind all the evil that has befallen Ulduar! Left my kingdom in ruins, corrupted my brother and slain my wife!","","","","","","","","",15748,1,0,0,"thorim outro hard2"),
(-1603206,"And now it falls to you, champions, to avenge us all! The task before you is great, but I will lend you my aid as I am able. You must prevail!","","","","","","","","",15749,1,0,0,"thorim outro hard3"),
-- (-1603207,"Golganneth, lend me your strengh! Grant my mortal allies the power of thunder!","","","","","","","","",15750,1,0,0,"thorim yogg"),

-- Sif:
(-1603210,"Thorim, my lord, why else would these invaders have come into your sanctum but to slay you? They must be stopped!","","","","","","","","",15668,1,0,0,"sif start"),
(-1603211,"Impossible! Lord Thorim, I will bring your foes a frigid death!","","","","","","","","",15670,1,0,0,"sif event"),
(-1603212,"These pathetic mortals are harmless, beneath my station. Dispose of them!","","","","","","","","",15669,1,0,0,"sif despawn"),
-- (-1603213,'Runic Colossus surrounds itself with a crackling Runic Barrier!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_barrier'),
-- (-1603214,'Ancient Rune Giant fortifies nearby allies with runic might!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_barrier'),

-- Mimiron:
(-1603220,"Oh, my! I wasn't expecting company! The workshop is such a mess! How embarrassing!","","","","","","","","Вот те на! Я не ждал гостей! Тут везде такой безпорядок! Как не ловко!",15611,1,0,0,"mimiron aggro"),
(-1603221,"Now why would you go and do something like that? Didn't you see the sign that said 'DO NOT PUSH THIS BUTTON!'? How will we finish testing with the self-destruct mechanism active?","","","","","","","","Так, зачем вы это сделали? Разве вы не видели табличку 'НЕ НАЖИМАЙТЕ ЭТУ КНОПКУ!'? Ну как мы сумеем завершить испытания при включенном механизме самоликвидации, ааа?",15629,1,0,0,"mimiron hard mode"),
(-1603222,"Oh, my! It would seem that we are out of time, my friends!","","","","","","","","Ааа! Очевидно наше время истекло, друзья мои!",15628,1,0,0,"mimiron berserk"),
(-1603223,"We haven't much time, friends! You're going to help me test out my latest and greatest creation. Now, before you change your minds, remember, that you kind of owe it to me after the mess you made with the XT-002.","","","","","","","","У нас мало времени, друзья! Вы поможете испытать новейшие и величайшие из моих изобретений, и учтите, после того что вы натворили с ХТ002, отказыватся просто не красиво.",15612,1,0,0,"tank active"),
(-1603224,"MEDIC!","","","","","","","","ДОКТОРА!",15613,1,0,0,"tank kill1"),
(-1603225,"I can fix that... or, maybe not! Sheesh, what a mess...","","","","","","","","Я могу починить это... а может и не могу! Ну и бардак...",15614,1,0,0,"tank kill2"),
(-1603226,"WONDERFUL! Positively marvelous results! Hull integrity at 98.9 percent! Barely a dent! Moving right along.","","","","","","","","Превосходно! Просто восхитительный результат! Целостность обшивки 98.9 процента! Почти что не царапинки! Продолжаем.",15615,1,0,0,"tank dead"),
(-1603227,"Behold the VX-001 Anti-personnel Assault Cannon! You might want to take cover.","","","","","","","","Представляю вам противопехотную штормовую пушку - VX-001! советую поискать укрытие.",15616,1,0,0,"torso active"),
(-1603228,"Fascinating. I think they call that a 'clean kill'.","","","","","","","","Потрясающе. Помоему это называется 'Прямо в яблочко'.",15617,1,0,0,"torso kill1"),
(-1603229,"Note to self: Cannon highly effective against flesh.","","","","","","","","Надо запомнить: Пушка крайне эффективна против созданий из плоти и крови.",15618,1,0,0,"torso kill2"),
(-1603230,"Thank you, friends! Your efforts have yielded some fantastic data! Now, where did I put-- oh, there it is!","","","","","","","","Спасибо друзья! Благодаря вам я получил ценнейшие сведения! Так, куда же я дел... ах, вот куда!",15619,1,0,0,"torso dead"),
(-1603231,"Isn't it beautiful? I call it the magnificent aerial command unit!","","","","","","","","Ха! Ха! Ха! Ха! Красота правда? Я называю это непревзойденной воздушной боевой единицей!",15620,1,0,0,"head active"),
(-1603232,"Outplayed!","","","","","","","","Обхитрил!",15621,1,0,0,"head kill1"),
(-1603233,"You can do better than that!","","","","","","","","Плохо стараешся!",15622,1,0,0,"head kill2"),
(-1603234,"Preliminary testing phase complete. Now comes the true test!!","","","","","","","","Фаза предварительной проверки завершена. Пора начать главный тест! Ха! Ха! Ха! Ха!",15623,1,0,0,"head defeat"),
(-1603235,"Gaze upon its magnificence! Bask in its glorious, um, glory! I present you... V-07-TR-0N!","","","","","","","","Насладитесь его великолепием! Грейтесь в его сияющем, эмм, сиянии! Перед вами потрясающий - V-07-ДР-ОН",15624,1,0,0,"robot active"),
(-1603236,"Prognosis: Negative!","","","","","","","","Прогноз: Негативный!",15625,1,0,0,"robot kill1"),
(-1603237,"You're not going to get up from that one, friend.","","","","","","","","От этого тебе не оправится, дружок.",15626,1,0,0,"robot kill2"),
(-1603238,"It would appear that I've made a slight miscalculation. I allowed my mind to be corrupted by the fiend in the prison, overriding my primary directive. All systems seem to be functional now. Clear.","","","","","","","","Очевидно я совершил не большую ошибку в расчетах. Пленный злодей затуманил мой разум и заставил меня отклониться от инструкций. Сейчас все системы в норме. Конец связи!",15627,1,0,0,"robot defeat"),
-- (-1603239,"Combat matrix enhanced. Behold wonderous rapidity!","","","","","","","","Боевая матрица разширена. Оо, какая невероятная скорость!",15630,1,0,0,"mimiron yogg"),
(-1603240,"Leviathan Mk II begins to cast Plasma Blast!" ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_plasma_blast'),
-- (-1606241,"Self-destruct sequence initiated.","","","","","","","","Отсчет времени до самоуничтожения начат.",15413,1,0,0,""),
-- (-1606242,"This area will self-destruct in ten minutes.","","","","","","","","Самоуничтожение области через десять минут.",15415,1,0,0,"mimiron "),
-- (-1606243,"This area will self-destruct in nine minutes.","","","","","","","","Самоуничтожение области через девять минут.",15416,1,0,0,"mimiron "),
-- (-1606244,"This area will self-destruct in eight minutes.","","","","","","","","Самоуничтожение области через восемь минут.",15417,1,0,0,"mimiron "),
-- (-1606245,"This area will self-destruct in seven minutes.","","","","","","","","Самоуничтожение области через семь минут.",15418,1,0,0,"mimiron "),
-- (-1606246,"This area will self-destruct in six minutes.","","","","","","","","Самоуничтожение области через шесть минут.",15419,1,0,0,"mimiron "),
-- (-1606247,"This area will self-destruct in five minutes.","","","","","","","","Самоуничтожение области через пять минут.",15420,1,0,0,"mimiron "),
-- (-1606248,"This area will self-destruct in four minutes.","","","","","","","","Самоуничтожение области через четыре минуты.",15421,1,0,0,"mimiron "),
-- (-1606249,"This area will self-destruct in three minutes.","","","","","","","","Самоуничтожение области через три минуты.",15422,1,0,0,"mimiron "),
-- (-1606250,"This area will self-destruct in two minutes.","","","","","","","","Самоуничтожение области через две минуты.",15423,1,0,0,"mimiron "),
-- (-1606251,"This area will self-destruct in one minute.","","","","","","","","Самоуничтожение области через одну минуту.",15424,1,0,0,"mimiron "),
-- (-1606252,"The self-destruction timer is over. Have a nice day.","","","","","","","","Отсчет времени до самоуничтожения завершен. Всего хорошего.",15425,1,0,0,"mimiron "),
-- (-1606253,"The self-destruction timer canceled. Exit code A905.","","","","","","","","Отсчет времени до самоуничтожения прерван. Код отмены А905.",15414,1,0,0,"mimiron "),

-- vezax
(-1603350,'Your destruction will herald a new age of suffering!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Ваша смерть возвестит новую эру страданий!",15542,1,0,0,'vezax aggro'),
(-1603351,'You thought to stand before the legions of death... and survive?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Тебе не выстоять перед легионом смерти...",15543,1,0,0,'vezax kill1'),
(-1603352,'Defiance... a flaw of mortality.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Неповиновение... Ха, ха, ха, ха, это слабость смертных.",15544,1,0,0,'vezax kill2'),
(-1603353,'The black blood of Yogg-Saron courses through me! I. AM. UNSTOPPABLE!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Во мне течет черная кровь Йогг-Сарона! Меня не остановить!",15545,1,0,0,'vezaz surge'),
(-1603354,'Oh, what horrors await....',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Ха! Ха! Ха! Ха... Какие ужасы вас ожидают...",15546,1,0,0,'vezax death'),
(-1603355,'Your defeat was inevitable!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Ваше поражение, было неизбежно!",15547,1,0,0,'vezax enrage'),
(-1603356,'Behold, now! Terror, absolute!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Познайте, же! Абсолютный, ужас!",15548,1,0,0,'vezax hard'),
(-1603357,'A cloud of saronite vapors coalesces nearby!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_vapors'),
(-1603358,'General Vezax roars and surges with dark might!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_surge'),
(-1603359,'The saronite vapors mass and swirl violently, merging into a monstrous form!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_animus'),

-- Yogg:
-- Sara:
(-1603360,'The time to strike at the head of the beast will soon be upon us! Focus your anger and hatred on his minions!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Скоро мы сразимся с главарем этих извергов! Обратите гнев и ненависть против его прислужников!",15775,1,0,0,'sara aggro'),
(-1603361,'Yes! YES! Show them no mercy! Give no pause to your attacks!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Да! ДА! Не щадите их! Бейте без промахов!",15773,1,0,0,'sara help1'),
(-1603362,'Let hatred and rage guide your blows!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Пусть ненависть и ярость направляют ваши удары!",15774,1,0,0,'sara help2'),
(-1603363,'Could they have been saved?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Был ли у них шанс на спасение?",15779,1,0,0,'sara kill1'),
(-1603364,'Powerless to act...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Какое безсилие...",15778,1,0,0,'sara kill 1'),
(-1603365,'Suffocate upon your own hate!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Задохнитесь в собственной ненависти!",15776,1,0,0,'sara yell1 p1'),
(-1603366,'Tremble, mortals, before the coming of the end!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Трепищите, смертные, конец близок!",15777,1,0,0,'sara yell2 p2'),
(-1603367,'Aaaaaaaaaaaaaaaaa... Help me!!! Please got to help me!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Ааааааааа... На помощь! Помогите отделаться от них!",15771,1,0,0,'sara prefight'),
(-1603368,'What do you want from me? Leave me alone!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Что вам нужно? Прочь от меня!",15772,1,0,0,'sara prefight2'),
(-1603369,'Weak-minded fools!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Вот тупица!",15780,4,0,0,'sara slay phase1'),

-- Yogg:
(-1603370,'I am the lucid dream. The monster in your nightmares. The fiend of a thousand faces. Cower before my true form. BOW DOWN BEFORE THE GOD OF DEATH!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Я... Это сон на яву. Чудовище из ваших кошмаров. Демон с тысячью лиц. Трепещите, ибо Я обретаю истинную форму. ПАДИТЕ ВНИЗ ПЕРЕД БОГОМ СМЕРТИ!",15754,1,0,0,'yogg p2 intro'),
(-1603371,'MADNESS WILL CONSUME YOU!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Безумие поглотит вас!",15756,1,0,0,'yogg vision'),
(-1603372,'Look upon the true face of death and know that your end comes soon!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Взгляните в истинное лицо смерти и знайте, что ваш конец близок!",15755,1,0,0,'yogg phase 3'),
(-1603373,'Hoohehehahahaha... AHAHAHAHAHAHA!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Уммхехехахахаха... ХАХАХАХАХАХАХАХА!",15757,1,0,0,'yogg slay1'),
(-1603374,'Eternal suffering awaits!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Впереди вечные страдания!",15758,1,0,0,'yogg slay2'),
(-1603375,'Your fate is sealed. The end of days is finally upon you and ALL who inhabit this miserable little seedling. Uulwi ifis halahs gag erh\'ongg w\'ssh.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Хахахахахаха! Вы обречены. Не вы, никто другой, не в силах избежать близящегося конца света. Ульви ифи Халаш гага вонг ущь.",15761,1,0,0,'yogg death'),
(-1603376,'Your will is no longer you own...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Вы теперь в моей власти...",15759,4,0,0,'yogg insanity1'),
(-1603377,'Destroy them minion, your master commands it!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Слуга убей их, исполни приказ хозяина!",15760,4,0,0,'yogg insanity2'),
(-1603378,'Portals open into Yogg-Saron\'s mind!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_vision_blast'),
(-1603379,'The illusion shatters and a path to the central chamber opens!' ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0,'EMOTE_shatter_blast'),
-- Visions:
-- stormwind v1
(-1603400,'Bad news sire. The clans are united under Blackhand in this assault. They will stand together until Stormwind has fallen.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15538,0,0,0,'v3 garona1'),
(-1603401,'Gul\'dan is bringing up his warlocks by nightfall. Until then, the Blackrock clan will be trying to take the Eastern Wall.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15539,0,0,0,'v3 garona2'),
(-1603402,'The orc leaders agree with your assessment.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'v3 garona3'),
-- (-1603403,'',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'v3 garona4'),
(-1603404,'A thousand deaths... ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15762,0,0,0,'v3 yogg1'),
(-1603405,'or one murder.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15763,0,0,0,'v3 yogg2'),
(-1603346,'Your petty quarrels only make me stronger!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15764,0,0,0,'v3 yogg3'),
(-1603347,'We will hold until the reinforcements come. As long as men with stout hearts are manning the walls and throne Stormwind will hold.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'v3 king llane1'),
-- dragons v2
(-1603390,'It is done... All have been given that which must be given. I now seal the Dragon Soul forever...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15631,0,0,0,'v2 neltharion1'),
(-1603391,'That terrible glow... should that be?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15784,0,0,0,'v2 ysera1'),
(-1603392,'For it to be as it must, yes.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15632,0,0,0,'v2 neltharion2'),
(-1603393,'It is a weapon like no other. It must be like no other.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15610,0,0,0,'v2 malygos1'),
(-1603394,'His brood learned their lesson before too long, you shall soon learn yours!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15765,0,0,0,'v2 yogg1'),
-- lich king v3
(-1603380,'Your resilience is admirable.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15598,0,0,0,'v1 lich king1'),
(-1603381,'Arrrrrrgh!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15470,1,0,0,'v1 champ1'),
(-1603382,'I\'m not afraid of you!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15471,0,0,0,'v1 champ2'),
(-1603383,'I will break you as I broke him.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15599,0,0,0,'v1 lich king2'),
(-1603384,'Yrr n\'lyeth... shuul anagg!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15766,0,0,0,'v1 yogg1'),
(-1603385,'He will learn... no king rules forever; only death is eternal!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,15767,0,0,0,'v1 yogg2'),
-- keepers yells
-- (-1603126,'',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'SAY_HODIR_ACTIVE'),
-- (-1603149,'',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'SAY_FREYA_ACTIVE'),
-- (-1603207,'',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'SAY_THORIM_ACTIVE'),
-- (-1603239,'',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'SAY_MIMIRON_ACTIVE'),

-- Alagon:
(-1603250,'Your actions are illogical. All possible results for this encounter have been calculated. The pantheon will receive the observer\'s message regardless outcome.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Ваши действия не логичны. Все возможные исходы этой схватки просчитаны. Пантеон получит сообщение от наблюдателя в любом случае.",15386,1,0,0,'Agro_algalon the observer'),
(-1603251,'See your world through my eyes. A universe so vast as to be immeasurable. Incomprehensible even to your greatest minds.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Взгляните на мир моими глазами. Узрите необьятную вселенную. Непостежимую даже для величайших умов.",15390,1,0,0,'Engaged for the first time algalon'),
(-1603252,'Witness the fury of cosmos!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Космос покарает вас!",15396,1,0,0,'BIG BANG 1_Algalon'),
(-1603253,'Behold the tools of creation!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Узрите чудо созидания!",15397,1,0,0,'BIG BANG 2_Algalon\r\n'),
(-1603254,'Beware!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Берегитесь!",15391,1,0,0,'Phase2_algalon\r\n'),
(-1603255,'Loss of life, unavoidable.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Жизнь, не может быть вечной.",15387,1,0,0,'Killing a player_alagalon\r\n'),
(-1603256,'I do what I must.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Я делаю то, что должен.",15388,1,0,0,'killing a player2_algalon\r\n'),
(-1603257,'You are... out of time.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Ваше время... Вышло.",15394,1,0,0,'BERSEKER_ALGALON'),
(-1603258,'The stars come to my aid.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Звезды помогут мне.",15392,1,0,0,'Summoning Collapsing Stars_Algalon1'),
(-1603259,'I lack the strength to transmit this signal. You must hurry. Find a place of power, close to the skies.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,"У меня нет сил, чтобы передать сигнал. Поторопитесь, найдите истоичник энергии. Ищите в небесах.",15403,1,0,0,'Summoning Collapsing Stars_Algalon2'),
(-1603260,"Trans-location complete. Commencing planetary analysis of Azeroth.","","","","","","","","Перемещение завершено. Запуск планитарного анализа Азерота.",15405,1,0,0,"Algalon intro1"),
(-1603261,"Stand back, mortals. I am not here to fight you.","","","","","","","","Смертные. Я здесь не для того, чтобы сражаться с вами.",15406,1,0,0,"Algalon intro2"),
(-1603262,"It is in the universe's best interest to re-originate this planet should my analysis find systemic corruption. Do not interfere.","","","","","","","","Для блага вселенной эту планету необходимо пересоздать. Я запускаю системный анализ, чтобы выявить зоны поражения. Не вмешивайтесь.",15407,1,0,0,"algalon intro3"),
(-1603263,"Analysis complete. There is partial corruption in the plane's life-support systems as well as complete corruption in most of the planet's defense mechanisms.","","","","","","","","Анализ завершен. Система жизнеобеспечения планеты частично поражена, большинство защитных механизмов поражены полностью.",15398,1,0,0,"algalon despawn1"),
(-1603264,"Begin uplink: Reply Code: 'Omega'. Planetary re-origination requested.","","","","","","","","Выход на связь. Код отклика: 'Омега'. Запрос на пересоздание планеты.",15399,1,0,0,"algalon despawn 2"),
(-1603265,"Farewell, mortals. Your bravery is admirable, for such flawed creatures.","","","","","","","","Прощайте, смертные. Я восхищаюсь вашей отвагой, несовершенные существа.",15400,1,0,0,"algalon despwnd 3"),
(-1603266,"I have seen worlds bathed in the Makers' flames. Their denizens fading without so much as a whimper. Entire planetary systems born and raised in the time that it takes your mortal hearts to beat once. Yet all throughout, my own heart, devoid of emotion... of empathy. I... have... felt... NOTHING! A million, million lives wasted. Had they all held within them your tenacity? Had they all loved life as you do?","","","","","","","","Я видел миры, охваченные пламенем творцов. Их жители гибли не успев издать ни звука. Я был свидетелм того, как Галактики рождались и умерали в мгновение ока, и все время Я оставался холодным... И безразличным... Я... Не чуствовал! Ничего! Триллионы загубленных судеб, неужели все они были подобны вам? Неужели все они так же любили жизнь?",15393,1,0,0,"algalon outro1"),
(-1603267,"Perhaps it is your imperfection that which grants you free will. That allows you to persevere against cosmically calculated odds. You prevailed where the Titans' own perfect creations have failed.","","","","","","","","Похоже ваша сила кроется именно в несовершенстве. Дарованная вам свобода воли позволяет принебрегать законами космоса и выходить победителями, тогда когда идеальные создания Титанов оказываются безсильными.",15401,1,0,0,"algalon outro 2"),
(-1603268,"I've rearranged the reply code. Your planet will be spared. I cannot be certain of my own calculations anymore.","","","","","","","","Я изменил код отклика. Ваша планета будет спасена. Я больше не могу полагаться на свои расчеты.",15402,1,0,0,"algalon outro 3"),
(-1603269,"Do not worry about my fate <name>. If the signal is not transmitted in time re-origination will proceed regardless. Save. Your. World.","","","","","","","","",15404,1,0,0,"algalon outro 5");
*/
-- Archivum dialogue: TODO:
-- Brann
-- Archivum
