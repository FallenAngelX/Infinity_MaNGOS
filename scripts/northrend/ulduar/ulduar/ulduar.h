/* Copyright (C) 2006 - 2013 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_ULDUAR_H
#define DEF_ULDUAR_H

enum
{

    // Main boss types
    TYPE_LEVIATHAN              = 0,
    TYPE_IGNIS                  = 1,
    TYPE_RAZORSCALE             = 2,
    TYPE_XT002                  = 3,
    TYPE_ASSEMBLY               = 4,
    TYPE_KOLOGARN               = 5,
    TYPE_AURIAYA                = 6,
    TYPE_MIMIRON                = 7,
    TYPE_HODIR                  = 8,
    TYPE_THORIM                 = 9,
    TYPE_FREYA                  = 10,
    TYPE_VEZAX                  = 11,
    TYPE_YOGGSARON              = 12,
    TYPE_ALGALON                = 13,

    // Hard mode boss types
    // Used for hard mode bosses only
    TYPE_LEVIATHAN_DIFFICULTY   = 20,
    TYPE_XT002_HARD             = 21,
    TYPE_MIMIRON_HARD           = 23,
    TYPE_HODIR_HARD             = 24,
    TYPE_THORIM_HARD            = 25,
    TYPE_FREYA_HARD             = 26, // this means 3 elders up
    TYPE_VEZAX_HARD             = 27,
    TYPE_YOGGSARON_HARD         = 28,
    TYPE_YOGGSARON_HARD_4       = 29,

    // Keeper types
    // Used to store the keepers which will be used at yogg
    TYPE_KEEPER_HODIR           = 30,
    TYPE_KEEPER_FREYA           = 31,
    TYPE_KEEPER_THORIM          = 32,
    TYPE_KEEPER_MIMIRON         = 33,

    // teleporters
    TYPE_LEVIATHAN_TP           = 40,
    TYPE_XT002_TP               = 41,
    TYPE_MIMIRON_TP             = 42,

    //other-> these won't be saved to db
    TYPE_RUNE_GIANT             = 50,
    TYPE_RUNIC_COLOSSUS         = 51,
    TYPE_LEVIATHAN_MK           = 52,
    TYPE_VX001                  = 53,
    TYPE_AERIAL_UNIT            = 54,
    TYPE_YOGG_BRAIN             = 55,
    TYPE_MIMIRON_PHASE          = 56,
    TYPE_YOGG_PHASE             = 57,
    TYPE_VISION_PHASE           = 58,

    MAX_ENCOUNTER               = 59,

    NPC_KEEPER_OF_NORGANNON     = 33686,
    NPC_BRANN_BRONZEBEARD       = 33579,

    // The siege of ulduar
    VEHICLE_SIEGE              = 33060,
    VEHICLE_CHOPPER            = 33062,
    VEHICLE_DEMOLISHER         = 33109,

    NPC_LEVIATHAN               = 33113,
    NPC_WARD_OF_LIFE            = 34275,
    NPC_WRITHING_LASHER         = 33387,

    NPC_IGNIS                   = 33118,
    NPC_IRON_CONSTRUCT          = 33121,

    NPC_RAZORSCALE              = 33186,
    NPC_COMMANDER               = 33210,

    NPC_XT002                   = 33293,
    NPC_XT_TOY_PILE             = 33337,


    // The antechamber of ulduar
    NPC_STEELBREAKER            = 32867,
    NPC_RUNEMASTER_MOLGEIM      = 32927,
    NPC_STORMCALLER_BRUNDIR     = 32857,
    NPC_KOLOGARN                = 32930,
    NPC_RIGHT_ARM               = 32934,
    NPC_LEFT_ARM                = 32933,
    NPC_KOLOGARN_BRIDGE_DUMMY   = 34297,

    NPC_AURIAYA                 = 33515,
    NPC_SANCTUM_SENTRY          = 34014,
    NPC_FERAL_DEFENDER          = 34035,

    // The keepers of ulduar
    NPC_MIMIRON                 = 33350,
    NPC_LEVIATHAN_MK            = 33432,
    NPC_VX001                   = 33651,
    NPC_AERIAL_UNIT             = 33670,
    NPC_HODIR                   = 32845,
    NPC_HELPER_DRUID            = 32941,
    NPC_HELPER_SHAMAN           = 32950,
    NPC_HELPER_MAGE             = 32946,
    NPC_HELPER_PRIEST           = 32948,
    NPC_THORIM                  = 32865,

    // Thorim event npcs
    NPC_RUNIC_COLOSSUS          = 32872,
    NPC_RIGHT_HAND_TRIGGER      = 33140,
    NPC_LEFT_HAND_TRIGGER       = 33141,
    NPC_RUNE_GIANT              = 32873,
    NPC_JORMUNGAR_BEHEMOTH      = 32882,
    NPC_CAPTAIN_ALY             = 32908,
    NPC_CAPTAIN_HORDE           = 32907,
    NPC_MERCENARY_ALY           = 32885,
    NPC_MERCENARY_HORDE         = 32883,
    NPC_THUNDER_ORB             = 33378,    // npc used to cast charged orb

    NPC_FREYA                   = 32906,
    NPC_BRIGHTLEAF              = 32915,
    NPC_IRONBRACH               = 32913,
    NPC_STONEBARK               = 32914,

    // The descent into madness
    NPC_VEZAX                   = 33271,
    NPC_ANIMUS                  = 33524,
    NPC_YOGGSARON               = 33288,

    // Celestial planetarium
    NPC_ALGALON                 = 32871,
    NPC_SARA                    = 33134,
    NPC_YOGG_BRAIN              = 33890, 
    NPC_OMINOUS_CLOUD           = 33292,

    // Keepers helpers spawned during Yogg Saron encounter
    THORIM_IMAGE                = 33413,
    MIMIRON_IMAGE               = 33412,
    HODIR_IMAGE                 = 33411,
    FREYA_IMAGE                 = 33410,

    // Keepers spawned in the central hall after releaseed from Yogg's enslavement
    KEEPER_FREYA                = 33241,
    KEEPER_HODIR                = 33213,
    KEEPER_MIMIRON              = 33244,
    KEEPER_THORIM               = 33242, 

    // Loot chests
    // Kologarn
    GO_CACHE_OF_LIVING_STONE    = 195046,
    GO_CACHE_OF_LIVING_STONE_H  = 195047,
    // Hodir
    GO_CACHE_OF_WINTER          = 194307,
    GO_CACHE_OF_WINTER_H        = 194308,
    GO_CACHE_OF_RARE_WINTER     = 194200,
    GO_CACHE_OF_RARE_WINTER_H   = 194201,
    // Thorim
    GO_CACHE_OF_STORMS          = 194312,
    GO_CACHE_OF_RARE_STORMS     = 194313,
    GO_CACHE_OF_STORMS_H        = 194315,
    GO_CACHE_OF_RARE_STORMS_H   = 194314,
    // Alagon
    GO_GIFT_OF_OBSERVER_H       = 194821,
    GO_GIFT_OF_OBSERVER         = 194822,
    GO_GIFT_OF_OBSERVER_HH      = 194823,  // unk
    // Freya -> each chest is for a mode
    // 10 man
    GO_FREYA_GIFT               = 194324,  // 10 normal
    GO_FREYA_GIFT_HARD          = 194327,  // 10 3 elders
    // 25 man
    GO_FREYA_GIFT_H             = 194328,  // 25 normal
    GO_FREYA_GIFT_HARD_H        = 194331,  // 25 3 elders
    // Mimiron
    GO_CACHE_OF_INOV            = 194789,
    GO_CACHE_OF_INOV_H          = 194956,
    GO_CACHE_OF_INOV_HARD       = 194957,
    GO_CACHE_OF_INOV_HARD_H     = 194958,

    // Doors and other Objects
    // The siege
    GO_LIGHTNING_DOOR           = 194905,
    GO_SHIELD_WALL              = 194416,
    GO_LEVIATHAN_GATE           = 194630,
    GO_XT002_GATE               = 194631,
    GO_BROKEN_HARPOON           = 194565,
    // archivum
    // Antechamber
    GO_KOLOGARN_BRIDGE          = 194232,
    GO_SHATTERED_DOOR           = 194553,
    GO_IRON_ENTRANCE_DOOR       = 194554,
    GO_ARCHIVUM_DOOR            = 194556,
    GO_ARCHIVUM_CONSOLE         = 194555,

    // Planetarium
    GO_CELESTIAL_ACCES          = 194628,
    GO_CELESTIAL_ACCES_H        = 194752,
    GO_CELESTIAL_DOOR           = 194767,
    GO_UNIVERSE_FLOOR_ARCHIVUM  = 194715,
    GO_UNIVERSE_FLOOR_CELESTIAL = 194716,
    GO_AZEROTH_GLOBE            = 194148,

    // The keepers
    // Hodir
    GO_HODIR_EXIT               = 194634,
    GO_HODIR_ICE_WALL           = 194441,
    GO_HODIR_ENTER              = 194442,
    // Mimiron
    GO_MIMIRON_BUTTON           = 194739,                   // Used to start hard mode
    GO_MIMIRON_TRAM             = 194675,
    GO_MIMIRON_DOOR_1           = 194774,
    GO_MIMIRON_DOOR_2           = 194775,
    GO_MIMIRON_DOOR_3           = 194776,
    GO_MIMIRON_TEL1             = 194741,                   // Used to summon mobs in phase 3
    GO_MIMIRON_TEL2             = 194742,
    GO_MIMIRON_TEL3             = 194743,
    GO_MIMIRON_TEL4             = 194744,
    GO_MIMIRON_TEL5             = 194740,
    GO_MIMIRON_TEL6             = 194746,
    GO_MIMIRON_TEL7             = 194747,
    GO_MIMIRON_TEL8             = 194748,
    GO_MIMIRON_TEL9             = 194745,
    GO_MIMIRON_ELEVATOR         = 194749,                   // Central elevator
    // Thorim
    GO_DARK_IRON_PORTCULIS      = 194560,                   // Door from the arena to the hallway
    GO_RUNED_STONE_DOOR         = 194557,                   // Door after the runic colossus
    GO_THORIM_STONE_DOOR        = 194558,                   // Door after the ancient rune giant
    GO_LIGHTNING_FIELD          = 194559,                   // Arena exit door
    GO_DOOR_LEVER               = 194264,                   // In front of the door

    // Descent to madness
    GO_ANCIENT_GATE             = 194255,                   // Door upstairs before vezax, opens when all keepers are freed
    GO_VEZAX_GATE               = 194750,                   // Door after vezax
    GO_YOGG_GATE                = 194773,                   // Yogg-Saron chamber door
    GO_BRAIN_DOOR1              = 194635,                   // Brain chamber doors
    GO_BRAIN_DOOR2              = 194636,
    GO_BRAIN_DOOR3              = 194637,

    //Tower
    GO_TOWER_OF_FROST           = 194370,
    GO_TOWER_OF_FLAME           = 194371,
    GO_TOWER_OF_LIFE            = 194375,
    GO_TOWER_OF_STORMS          = 194377,

    // Repair
    RX_214_REPAIR               = 194261,
    RX_214_REPAIR_TRAP          = 194262,

    ACHIEV_IRON_COUNCIL         = 2888,
    ACHIEV_IRON_COUNCIL_H       = 2889,

    ACHIEV_KEEPERS              = 2890,
    ACHIEV_KEEPERS_H            = 2891,

    ACHIEV_CELESTIAL_DEFENDER   = 3259,     // realm first algalon
    SPELL_ALGALON_ACHIEV_TRIGG  = 65184,
    ACHIEV_DEATHS_DEMISE        = 3117,     // realm first yogg

    // World state used for algalon timer
    WORLD_STATE_TIMER           = 4132,
    WORLD_STATE_TIMER_COUNT     = 4131,

    // achievements
    TYPE_ACHIEV_SHATTERED               = 0,
    TYPE_ACHIEV_QUICK_SHAVE                ,
    TYPE_ACHIEV_IRON_DWARF_MEDIUM_RARE     ,
    TYPE_ACHIEV_NERF_ENGINEERING           ,
    TYPE_ACHIEV_HEARTBREAKER               ,
    TYPE_ACHIEV_YOU_BRUNDIR                ,
    TYPE_ACHIEV_YOU_MOLGEIM                ,
    TYPE_ACHIEV_YOU_STEELBREAKER           ,
    TYPE_ACHIEV_DISARMED                   ,
    TYPE_ACHIEV_OPEN_ARMS                  ,
    TYPE_ACHIEV_IF_LOOKS_COULD_KILL        ,
    TYPE_ACHIEV_RUBBLE_AND_ROLL            ,
    TYPE_ACHIEV_NINE_LIVES                 ,
    TYPE_ACHIEV_CRAZY_CAT_LADY             ,
    TYPE_ACHIEV_CHEESE_FREEZE              ,   // Hodir
    TYPE_ACHIEV_COOLEST_FRIEND             ,
    TYPE_ACHIEV_RARE_CACHE                 ,
    TYPE_ACHIEV_SIFFED                     ,   // Thorim
    TYPE_ACHIEV_LOSE_YOUR_ILLUSION         ,
    TYPE_ACHIEV_BACK_TO_NATURE             ,   // Freya
    TYPE_ACHIEV_KNOCK_WOOD                 ,
    TYPE_ACHIEV_KNOCK_KNOCK_WOOD           ,
    TYPE_ACHIEV_KNOCK_KNOCK_KNOCK_WOOD     ,
    TYPE_ACHIEV_FIREFIGHTER                ,
    TYPE_ACHIEV_MORNING_SARONITE           ,
    TYPE_ACHIEV_THREE_LIGHTS               ,
    TYPE_ACHIEV_TWO_LIGHTS                 ,
    TYPE_ACHIEV_ONE_LIGHT                  ,
    TYPE_ACHIEV_ALONE                      ,

    MAX_SPECIAL_ACHIEV_CRITS               ,  // End achiev

    ACHIEV_CRIT_SHATTERED                            = 10068, // Ignis, achievs 2925, 2926
    ACHIEV_CRIT_SHATTERED_H                          = 10069,
    ACHIEV_CRIT_QUICK_SHAVE                          = 10062, // Razorscale, achievs 2919, 2921
    ACHIEV_CRIT_QUICK_SHAVE_H                        = 10063,
    ACHIEV_CRIT_IRON_DWARF_MEDIUM_RARE               = 10066, // Razorscale, achievs 2923, 2924
    ACHIEV_CRIT_IRON_DWARF_MEDIUM_RARE_H             = 10067,
    ACHIEV_CRIT_NERF_ENGINEERING                     = 10074, // XT-002 Deconstructor, achievs 2931, 2932
    ACHIEV_CRIT_NERF_ENGINEERING_H                   = 10075,
    ACHIEV_CRIT_HEARTBREAKER                         = 10221, // XT-002 Deconstructor, achievs 3058, 3059
    ACHIEV_CRIT_HEARTBREAKER_H                       = 10220,

    ACHIEV_CRIT_YOU_BRUNDIR                          = 10083, // Iron Council, achievs 2940, 2943
    ACHIEV_CRIT_YOU_BRUNDIR_H                        = 10086,
    ACHIEV_CRIT_YOU_MOLGEIM                          = 10082, // Iron Council, achievs 2939, 2942
    ACHIEV_CRIT_YOU_MOLGEIM_H                        = 10085,
    ACHIEV_CRIT_YOU_STEELBREAKER                     = 10084, // Iron Council, achievs 2941, 2944
    ACHIEV_CRIT_YOU_STEELBREAKER_H                   = 10087,
    ACHIEV_CRIT_BUT_I_AM_ON_YOUR_SIDE_BRUNDIR        = 10418, // Iron Council, achiev 2945 
    ACHIEV_CRIT_BUT_I_AM_ON_YOUR_SIDE_MOLGEIM        = 10088,
    ACHIEV_CRIT_BUT_I_AM_ON_YOUR_SIDE_STEELBREAKER   = 10419,
    ACHIEV_CRIT_BUT_I_AM_ON_YOUR_SIDE_BRUNDIR_H      = 10089, // Iron Council, achiev 2946
    ACHIEV_CRIT_BUT_I_AM_ON_YOUR_SIDE_MOLGEIM_H      = 10421,
    ACHIEV_CRIT_BUT_I_AM_ON_YOUR_SIDE_STEELBREAKER_H = 10420,
    // Kologarn
    ACHIEV_CRIT_DISARMED                 = 10284,   // achiev 2953
    ACHIEV_CRIT_DISARMED_H               = 10722,   // achiev 2954
    ACHIEV_CRIT_OPEN_ARMS                = 10285,   // achiev 2951
    ACHIEV_CRIT_OPEN_ARMS_H              = 10095,   // achiev 2952
    ACHIEV_IF_LOOKS_COULD_KILL           = 10286,   // achiev 2955
    ACHIEV_IF_LOOKS_COULD_KILL_H         = 10099,   // achiev 2956
    ACHIEV_CRIT_RUBBLE_AND_ROLL          = 10290,   // achiev 2959
    ACHIEV_CRIT_RUBBLE_AND_ROLL_H        = 10133,   // achiev 2960
    // Auriaya
    ACHIEV_CRIT_NINE_LIVES               = 10399,   // achiev 3076
    ACHIEV_CRIT_NINE_LIVES_H             = 10243,   // achiev 3077
    ACHIEV_CRIT_CRAZY_CAT_LADY           = 10400,   // achiev 3006
    ACHIEV_CRIT_CRAZY_CAT_LADY_H         = 10184,   // achiev 3007
    // Hodir
    ACHIEV_CRIT_CHEESE_FREEZE            = 10259,   // achiev 2961
    ACHIEV_CRIT_CHEESE_FREEZE_H          = 10261,   // achiev 2962
    ACHIEV_CRIT_COOLEST_FRIEND           = 10258,   // achiev 2963
    ACHIEV_CRIT_COOLEST_FRIEND_H         = 10260,   // achiev 2965
    ACHIEV_CRIT_RARE_CACHE               = 10452,   // achiev 3182
    ACHIEV_CRIT_RARE_CACHE_H             = 10458,   // achiev 3184
    //Thorim
    ACHIEV_CRIT_SIFFED                   = 10289,   // achiev 2977
    ACHIEV_CRIT_SIFFED_H                 = 10314,   // achiev 2978
    ACHIEV_CRIT_LOSE_YOUR_ILLUSION       = 10440,   // achiev 3176
    ACHIEV_CRIT_LOSE_YOUR_ILLUSION_H     = 10457,   // achiev 3183
    // Freya
    ACHIEV_CRIT_BACK_TO_NATURE           = 10445,   // achiev 2982
    ACHIEV_CRIT_BACK_TO_NATURE_H         = 10758,   // achiev 2983
    ACHIEV_CRIT_KNOCK_WOOD               = 10447,   // achiev 3177
    ACHIEV_CRIT_KNOCK_WOOD_H             = 10459,   // achiev 3185
    ACHIEV_CRIT_KNOCK_KNOCK_WOOD         = 10448,   // achiev 3178
    ACHIEV_CRIT_KNOCK_KNOCK_WOOD_H       = 10460,   // achiev 3186
    ACHIEV_CRIT_KNOCK_KNOCK_KNOCK_WOOD   = 10449,   // achiev 3179
    ACHIEV_CRIT_KNOCK_KNOCK_KNOCK_WOOD_H = 10461,   // achiev 3187
    // Mimiron
    ACHIEV_CRIT_FIREFIGHTER              = 10450,   // achiev 3180
    ACHIEV_CRIT_FIREFIGHTER_H            = 10463,   // achiev 3189
    // Vezax
    ACHIEV_CRIT_SARONITE_N               = 10451,   // General Vezax, achievs 3181, 3188
    ACHIEV_CRIT_SARONITE_H               = 10462,
    // Yogg
    ACHIEV_CRIT_THREE_LIGHTS             = 10410,   // achiev 3157
    ACHIEV_CRIT_THREE_LIGHTS_H           = 10414,   // achiev 3161
    ACHIEV_CRIT_TWO_LIGHTS               = 10388,   // achiev 3141
    ACHIEV_CRIT_TWO_LIGHTS_H             = 10415,   // achiev 3162
    ACHIEV_CRIT_ONE_LIGHT                = 10409,   // achiev 3158
    ACHIEV_CRIT_ONE_LIGHT_H              = 10416,   // achiev 3163
    ACHIEV_CRIT_ALONE                    = 10412,   // achiev 3159
    ACHIEV_CRIT_ALONE_H                  = 10417,   // achiev 3164


    // Timed achievement criterias
    ACHIEV_START_IGNIS_ID       = 20951,
    ACHIEV_START_XT_002_ID      = 21027,
    ACHIEV_START_YOGG_SARON_ID  = 21001,

    // SPELLS
    // Special Auras for Achievments
    SPELL_IRON_BOOT_AURA        = 58501,
    SPELL_RUNIC_SMASH_DMG       = 62465,

    // Difficulty
    NONE_DIFFICULTY    = 0,
    EASY_DIFFICULTY       ,
    HARD_DIFFICULTY       ,
    HARD_DIFFICULTY_1_DONE,
    HARD_DIFFICULTY_2_DONE,
    HARD_DIFFICULTY_3_DONE,
    HARD_DIFFICULTY_4_DONE
};

enum ExplosionSide
{
    LEFT_EXPLOSION  = 0,
    RIGHT_EXPLOSION = 1,
    NO_EXPLOSION    = 2,
};

class MANGOS_DLL_DECL instance_ulduar : public ScriptedInstance
{
    public:
        instance_ulduar(Map* pMap);
        ~instance_ulduar() {}

        void Initialize() override;
        bool IsEncounterInProgress() const override;

        void OnCreatureCreate(Creature* pCreature) override;
        void OnCreatureDeath(Creature* pCreature) override;
        void OnObjectCreate(GameObject* pGo) override;

        void OnPlayerEnterArea(Player* Player, uint32 uiNewAreaId, uint32 uiOldAreaId) override;

        void SetData(uint32 uiType, uint32 uiData) override;
        uint32 GetData(uint32 uiType) const override;

        const char* Save() const override;
        void Load(const char* chrIn) override;

        void Update(uint32 uiDiff) override;

        void SetSpecialAchievementCriteria(uint32 uiType, bool bIsMet);
        bool CheckAchievementCriteriaMeet(uint32 uiCriteriaId, Player const* pSource, Unit const* pTarget, uint32 uiMiscValue1 /* = 0*/) const override;
        // Dummy, leave till correct solution for hardmode found
        bool CheckConditionCriteriaMeet(Player const* pPlayer, uint32 uiInstanceConditionId, WorldObject const* pConditionSource, ConditionSource conditionSourceType) const override;

        void OpenDoor(uint32 uiEntry);
        void CloseDoor(uint32 uiEntry);
        void DoOpenMadnessDoorIfCan();
        void OpenXtDoor();
        void CheckIronCouncil();
        void CheckKeepers();
        void SpawnFriendlyKeeper(uint32 uiWho);
        void SortHandTrigger(Creature* pCreature);
        void DoColossusExplosion(ExplosionSide explosionSide);

        GuidList m_lXtToyPileGuids;
        GuidList m_lThorimMobsGuids;
        GuidList m_lHandTriggerGuids[2][10];
        GuidList m_lLowerOrbs;
        GuidList m_lUpperOrbs;
        GuidList m_lCloudGuids;
        GuidList m_lSanctumSentryGuids;

        GuidVector m_lBrokenHarpoonGUID;


    protected:
        // initialize the encouter variables
        std::string m_strInstData;
        uint32 m_auiEncounter[MAX_ENCOUNTER];

        bool m_abAchievCriteria[MAX_SPECIAL_ACHIEV_CRITS];

        uint32  m_uiShatterTimer;        // Ignis Achievement
        bool    m_bOneIsDeath;

        ExplosionSide m_explosionSide;
        uint8         m_uiExplosionRow;
        uint32        m_uiExplosionTimer;

        GuidList m_lIronConstructsGuids;
};

#endif
