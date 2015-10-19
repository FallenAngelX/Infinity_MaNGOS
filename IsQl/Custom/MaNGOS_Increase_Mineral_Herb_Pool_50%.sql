-- update herb pools, setting limit to ~50% of herb max count
UPDATE `pool_template` SET `max_limit` = 30 WHERE `entry` IN (979,948,947);

UPDATE `pool_template` SET `max_limit` = 50 WHERE `entry` IN (997,991,987,986,984,971,969);

UPDATE `pool_template` SET `max_limit` = 75 WHERE `entry` IN (999,998,993,985,983,982,981,980,978,976,974,973,970,963,962,957,955,953);

UPDATE `pool_template` SET `max_limit` = 100 WHERE `entry` IN (989,956,954,952,950);

UPDATE `pool_template` SET `max_limit` = 150 WHERE `entry` IN (995,992,977,975,972,967,966,965,964,958,951,949);

UPDATE `pool_template` SET `max_limit` = 200 WHERE `entry` IN (996,994,968,961,960);

UPDATE `pool_template` SET `max_limit` = 250 WHERE `entry` IN (990,959);

UPDATE `pool_template` SET `max_limit` = 350 WHERE `entry` IN (988);

/* 
lookup herb pools with
SELECT * FROM pool_template WHERE description LIKE "%MASTER Herbs%";
lookup pool entries with
SELECT * FROM pool_gameobject WHERE pool_entry = <master-node-id>;
*/

-- increase mineral spawns to ~50% of max count

-- borean tundra, sholazar basin, storm peaks, howling fjord, dragonblight, zangarmarsh
UPDATE `pool_template` SET `max_limit` = 40 WHERE `entry` IN (895,899,898,894,893,889); 
-- icecrown
UPDATE `pool_template` SET `max_limit` = 90 WHERE `entry` IN (897,890); 
-- wintergrasp, hellfire peninsula
UPDATE `pool_template` SET `max_limit` = 30 WHERE `entry` IN (896,886); 
-- nagrand, terokkar, netherstorm, 
UPDATE `pool_template` SET `max_limit` = 65 WHERE `entry` IN (888,887); 
-- blades edge mountains, shadowmoon valley
UPDATE `pool_template` SET `max_limit` = 50 WHERE `entry` IN (885,884); 

/*
lookup mineral pool with
select * from pool_template where description like "%MASTER Minerals%";
lookup pool entries with
select * from pool_pool WHERE mother_pool = <master-node-id>;
*/

----------------------
----- Ore Pool ------
----------------------

-- Adjust Ore Pool max_limit below for Smaller or Larger Servers. Max Limit is spawned count on end... :)
--
-- Copper Adjust SQL
-- UPDATE pool_template SET max_limit=200 WHERE (entry=149); Eastern Kingdom (572 Max Count)
-- UPDATE pool_template SET max_limit=160 WHERE (entry=150); Kalimdor (456 Max Count)
-- UPDATE pool_template SET max_limit=80 WHERE (entry=151); Outland (225 Max Count)

-- Tin/Silver Adjust SQL
-- UPDATE pool_template SET max_limit=200 WHERE (entry=152); Eastern Kingdom  (3218 Max Count)
-- UPDATE pool_template SET max_limit=100 WHERE (entry=153); Kalimdor  (272 Max Count)
-- UPDATE pool_template SET max_limit=50 WHERE (entry=154); Outland  (81 Max Count)  

-- Iron/Gold Adjust SQL 
-- UPDATE pool_template SET max_limit=200 WHERE (entry=155); Eastern Kingdom  (3152 Max Count)
-- UPDATE pool_template SET max_limit=200 WHERE (entry=156); Kalimdor  (538 Max Count)

-- Mithril/Truesilver Adjust SQL 
-- UPDATE pool_template SET max_limit=200 WHERE (entry=157); Eastern Kingdom  (2903 Max Count)
-- UPDATE pool_template SET max_limit=130 WHERE (entry=158); Kalimdor  (367 Max Count)

-- Thorium/Dark Iron Adjust SQL 
-- UPDATE pool_template SET max_limit=200 WHERE (entry=159); Eastern Kingdom  (1425 Max Count)
-- UPDATE pool_template SET max_limit=160 WHERE (entry=160); Kalimdor  (402 Max Count)

-- Fel Iron/Adamantite/Khorium Adjust SQL 
-- UPDATE pool_template SET max_limit=250 WHERE (entry=161); Outland  (3093 Max Count)

-- Cobalt/Rich Cobalt Adjust SQL 
-- UPDATE pool_template SET max_limit=200 WHERE (entry=162); Northrend  (1426 Max Count)

-- Saronite/Titanium Adjust SQL 
-- UPDATE pool_template SET max_limit=200 WHERE (entry=163); Northrend  (4097 Max Count)

-- Ancient Gem Vein Pool
-- UPDATE pool_template SET max_limit=8 WHERE (entry=164); Hyjal  (23 Max Count)

----------------------
----- Herb Pool ------
----------------------

-- Adjust Herb Pool max_limit below for Smaller or Larger Servers. Max Limit is spawned count on end... :)

-- Peacebloom Pool Eastern Kingdom [273 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=165);

-- Peacebloom Pool Kalimdor [350 Max Count]           
-- UPDATE pool_template SET max_limit=100 WHERE (entry=166);

-- Peacebloom Pool Outland [241 Max Count]                                            
-- UPDATE pool_template SET max_limit=100 WHERE (entry=167);                           
                                      
-- Silverleaf Pool Eastern Kingdom [517 Max Count]
-- UPDATE pool_template SET max_limit=180 WHERE (entry=168);                           
                                                                                                   
-- Silverleaf Pool Kalimdor [531 Max Count]
-- UPDATE pool_template SET max_limit=180 WHERE (entry=169);                           
                                                                                                          
-- Silverleaf Pool Outland [138 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=170);                           
                                                                                                            
-- Bloodthistle Pool Eversong Woods [31 Max Count]
-- UPDATE pool_template SET max_limit=15 WHERE (entry=171);                           
                                                                                                            
-- Earthroot Pool Eastern Kingdom [207 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=172);                           
                                                                                                          
-- Earthroot Pool Kalimador [305 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=173);                           
                                                                                                  
-- Earthroot Pool Outland [65 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=174);                           
                                                                                                            
-- Mageroyal Pool Eastern Kingdom [95 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=175);                           
                                                                                   
-- Mageroyal Pool Kalimador [384 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=176);                           
                                        
-- Mageroyal Pool Outland [136 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=177);                           
                                       
-- Bruiseweed Pool Eastern Kingdom [540 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=178);                           
                                       
-- Bruiseweed Pool Kalimador [440 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=179);                           
                                        
-- Grave Moss Pool Eastern Kingdom [56 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=180);                           

-- Grave Moss Pool Kalimador [19 Max Count]
-- UPDATE pool_template SET max_limit=15 WHERE (entry=181);                           
                                       
-- Wild Steelbloom Pool Eastern Kingdom [225 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=182);                           
                                       
-- Wild Steelbloom Pool Kalimador [164 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=183);                           

-- Kingsblood Pool Eastern Kingdom [95 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=184);                           
                                   
-- Kingsblood Pool Kalimador [59 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=185);                           

-- Liferoot Pool Eastern Kingdom [190 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=186);                           
                                     
-- Liferoot Pool Kalimador [31 Max Count]
-- UPDATE pool_template SET max_limit=20 WHERE (entry=187);                           
                                        
-- Fadeleaf Pool Eastern Kingdom [210 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=188); 

-- Fadeleaf Pool Kalimador [68 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=189);                           
                                      
-- Goldthorn Pool Eastern Kingdom [507 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=190);                           

-- Goldthorn Pool Kalimador [107 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=191);                           

-- Khadgar's Whisker Pool Eastern Kingdom [351 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=192);                           

-- Wintersbite Pool Eastern Kingdom [26 Max Count]
-- UPDATE pool_template SET max_limit=15 WHERE (entry=193);                           

-- Firebloom Pool Eastern Kingdom [80 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=194);                           

-- Firebloom Pool Kalimador [45 Max Count]
-- UPDATE pool_template SET max_limit=35 WHERE (entry=195);                           

-- Purple Lotus Pool Eastern Kingdom [30 Max Count]
-- UPDATE pool_template SET max_limit=20 WHERE (entry=196);                           

-- Purple Lotus Pool Kalimador [129 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=197);                           

-- Arthas' Tears Pool Eastern Kingdom [55 Max Count]
-- UPDATE pool_template SET max_limit=30 WHERE (entry=198);                           

-- Arthas' Tears Pool Kalimador [27 Max Count]
-- UPDATE pool_template SET max_limit=15 WHERE (entry=199);                           
                                         
-- Sungrass Pool Eastern Kingdom [148 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=200);                           

-- Sungrass Pool Kalimador [116 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=201);                           

-- Blindweed Pool Eastern Kingdom [112 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=202);                           

-- Blindweed Pool Kalimador [16 Max Count]
-- UPDATE pool_template SET max_limit=16 WHERE (entry=203);                           

-- Blindweed Pool Outland [63 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=204);                           

-- Ghost Mushroom Pool Eastern Kingdom [25 Max Count]
-- UPDATE pool_template SET max_limit=25 WHERE (entry=205);                           

-- Ghost Mushroom Pool Kalimador [9 Max Count]
-- UPDATE pool_template SET max_limit=5 WHERE (entry=206);                           

-- Ghost Mushroom Pool Outland [11 Max Count]
-- UPDATE pool_template SET max_limit=7 WHERE (entry=207);                           

-- Gromsblood Pool Eastern Kingdom [19 Max Count]
-- UPDATE pool_template SET max_limit=10 WHERE (entry=208);                           

-- Gromsblood Pool Kalimador [84 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=209);                           

-- Golden Sansam Pool Eastern Kingdom [87 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=210);                           

-- Golden Sansam Pool Kalimador [231 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=211);                           

-- Golden Sansam Pool Outland [118 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=212);                           

-- Dreamfoil Pool Eastern Kingdom [137 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=213);                           

-- Dreamfoil Pool Kalimador [262 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=214);                           

-- Dreamfoil Pool Outland [67 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=215);                           

-- Mountain Silversage Pool Eastern Kingdom [23 Max Count]
-- UPDATE pool_template SET max_limit=16 WHERE (entry=216);                           

-- Mountain Silversage Pool Kalamidor [185 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=217);                           

-- Mountain Silversage Pool Outland [57 Max Count]
-- UPDATE pool_template SET max_limit=42 WHERE (entry=218);                           

-- Plaguebloom Pool Eastern Kingdom [198 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=219);                           

-- Plaguebloom Pool Kalimador [70 Max Count]
-- UPDATE pool_template SET max_limit=45 WHERE (entry=220);                           

-- Frozen Herb Pool Outland [430 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=221);                           

-- Icecap Pool Kalimador [129 Max Count]
-- UPDATE pool_template SET max_limit=80 WHERE (entry=222);                           

-- Black Lotus Pool Eastern Kingdom [26 Max Count]
-- UPDATE pool_template SET max_limit=16 WHERE (entry=223);                           

-- Black Lotus Pool Kalimador [19 Max Count]
-- UPDATE pool_template SET max_limit=10 WHERE (entry=224);                           

-- Felweed Pool Outland[243 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=225);                           

-- Dreaming Glory Pool Outland [123 Max Count]
-- UPDATE pool_template SET max_limit=85 WHERE (entry=226);                           

-- Ragveil Pool Outland [172 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=227);                           

-- Flame Cap Pool Outland[73 Max Count]
-- UPDATE pool_template SET max_limit=50 WHERE (entry=228);                           

-- Terocone Pool Outland [156 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=229);                           

-- Ancient Lichen Pool Outland [29 Max Count]
-- UPDATE pool_template SET max_limit=15 WHERE (entry=230);                           

-- Ancient Lichen Pool Steam Vault [4 Max Count]
-- UPDATE pool_template SET max_limit=2 WHERE (entry=231);                           

-- Ancient Lichen Pool Shadow Lab [20 Max Count]
-- UPDATE pool_template SET max_limit=10 WHERE (entry=232);                           

-- Ancient Lichen Pool Mana Tomb [18 Max Count]
-- UPDATE pool_template SET max_limit=9 WHERE (entry=233);                           
      
-- Ancient Lichen Pool Auchenai Crypts [15 Max Count]
-- UPDATE pool_template SET max_limit=8 WHERE (entry=234);                           

-- Goldclover Pool Northrend [607 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=235);                           

-- Netherbloom Pool Outland [206 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=236);                           

-- Tiger Lily Pool Northrend [230 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=237);                           

-- Adder's Tongue Pool Northrend[251 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=238);                           

-- Lichbloom Pool Northrend [631 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=239);                           

-- Icethorn Pool Northrend [626 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=240);                           

-- Briarthorn Pool Eastern Kingdom [174 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=241);                           

-- Briarthorn Pool Kalimador [199 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=242);                           

-- Briarthorn Pool Outland [6 Max Count]
-- UPDATE pool_template SET max_limit=4 WHERE (entry=243);                           

-- Stranglekelp Pool Eastern Kingdom [111 Max Count]
-- UPDATE pool_template SET max_limit=75 WHERE (entry=244);                           

-- Stranglekelp Pool Kalimador [280 Max Count]
-- UPDATE pool_template SET max_limit=100 WHERE (entry=245);                           

-- Stranglekelp Pool Outland [4 Max Count]
-- UPDATE pool_template SET max_limit=2 WHERE (entry=246);                           

-- Frost Lotus Pool Northrend [91 Max Count]
-- UPDATE pool_template SET max_limit=48 WHERE (entry=247);                           

-- Talandra's Rose Pool Northrend [99 Max Count]
-- UPDATE pool_template SET max_limit=49 WHERE (entry=248);                           

-- Talandra's Rose Pool Uldar [6 Max Count]
-- UPDATE pool_template SET max_limit=3 WHERE (entry=249);                           

-- Nightmare Vine Pool Outland [57 Max Count]
-- UPDATE pool_template SET max_limit=35 WHERE (entry=250);                           

-- Mana Thistle Pool Outland [34 Max Count]
-- UPDATE pool_template SET max_limit=20 WHERE (entry=251);  


------------------------
----- School Pool ------
------------------------


-- Borean Man O' War School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=18 WHERE (entry=256); (36 Max Count)

-- Dragonfin Angelfish School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=12 WHERE (entry=257); (32 Max Count)

-- Glassfin Minnow School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=9 WHERE (entry=258); (17 Max Count)

-- Moonglow Cuttlefish School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=8 WHERE (entry=259); (24 Max Count)

-- School of Darter Pool Adjust SQL
-- UPDATE pool_template SET max_limit=9 WHERE (entry=260); (19 Max Count)

-- Mudfish School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=5 WHERE (entry=261); (9 Max Count)

-- Sporefish School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=20 WHERE (entry=262); (83 Max Count)

-- Greater Sagefish School Adjust SQL
-- UPDATE pool_template SET max_limit=20 WHERE (entry=263); (43 Max Count)

-- Musselback Sculpin School Adjust SQL
-- UPDATE pool_template SET max_limit=9 WHERE (entry=264); (27 Max Count)

-- Nettlefish School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=20 WHERE (entry=265); (54 Max Count)

-- Lesser Sagefish School Adjust SQL
-- UPDATE pool_template SET max_limit=32 WHERE (entry=266); (92 Max Count)

-- Sagefish School Adjust SQL
-- UPDATE pool_template SET max_limit=17 WHERE (entry=267); (37 Max Count)

-- Lesser Oily Blackmouth School Adjust SQL
-- UPDATE pool_template SET max_limit=36 WHERE (entry=268); (92 Max Count)

-- Sparse Oily Blackmouth School Adjust SQL
-- UPDATE pool_template SET max_limit=24 WHERE (entry=269); (49 Max Count)

-- Oily Blackmouth School Adjust SQL
-- UPDATE pool_template SET max_limit=13 WHERE (entry=270); (27 Max Count)

-- Teeming Oily Blackmouth School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=13 WHERE (entry=271); (26 Max Count)

-- Abundant Oily Blackmouth School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=10 WHERE (entry=272); (20 Max Count)

-- Sparse Firefin Snapper School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=24 WHERE (entry=273); (49 Max Count)

-- Firefin Snapper School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=16 WHERE (entry=274); (46 Max Count)

-- Teeming Firefin Snapper School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=12 WHERE (entry=275); (27 Max Count)

-- Abundant Firefin Snapper School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=8 WHERE (entry=276); (22 Max Count)

-- Stonescale Eel Swarm Pool Adjust SQL
-- UPDATE pool_template SET max_limit=22 WHERE (entry=277); (44 Max Count)

-- Imperial Manta Ray School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=75 WHERE (entry=278); (204 Max Count)

-- School of Tastyfish Pool Adjust SQL
-- UPDATE pool_template SET max_limit=20 WHERE (entry=279); (52 Max Count)

-- Deep Sea Monsterbelly School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=10 WHERE (entry=280); (28 Max Count)

-- Glacial Salmon School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=26 WHERE (entry=281); (71 Max Count)

-- Fangtooth Herring School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=32 WHERE (entry=282); (84 Max Count)

-- Schooner Wreckage Pool Adjust SQL
-- UPDATE pool_template SET max_limit=24 WHERE (entry=283); (49 Max Count)

-- Brackish Mixed School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=40 WHERE (entry=284); (84 Max Count)

-- Waterlogged Wreckage Pool Adjust SQL
-- UPDATE pool_template SET max_limit=16 WHERE (entry=285); (27 Max Count)

-- Highland Mixed School Pool Adjust SQL
-- UPDATE pool_template SET max_limit=5 WHERE (entry=286); (9 Max Count)

-- Bloodsail Wreckage Pool Adjust SQL
-- UPDATE pool_template SET max_limit=9 WHERE (entry=287); (16 Max Count)

-- Floating Wreckage Pool Adjust SQL
-- UPDATE pool_template SET max_limit=10 WHERE (entry=288); (20 Max Count)

-- Floating Debris Pool Adjust SQL
-- UPDATE pool_template SET max_limit=60 WHERE (entry=289); (92 Max Count)

