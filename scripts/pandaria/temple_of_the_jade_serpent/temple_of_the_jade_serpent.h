/* Copyright (C) 2010 -2013 by /dev/rsa for ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_TEMPLEOFTHEJADESERPENT_H
#define DEF_TEMPLEOFTHEJADESERPENT_H

enum Spells
{
    SPELL_CORRUPTED_WATERS      = 106778,
    //Spells for Lorewalker Stonestep event.
    SPELL_SHA_CORRUPTION        = 107034, //On spawn: Lot of mobs and decoration
    //HAUNTING SHA SPELLS
    SPELL_SHA_EXPLOSION_2       = 111812,
    //ZAO SUNSEEKER SPELLS
    SPELL_SHA_CORRUPTION_2      = 123947,
    SPELL_SHOOT_SUN             = 112084, //10 52 00 - 11 26 50 - 11 52 35
    SPELL_SHOOT_SUN_2           = 112085,
    SPELL_SHA_CORRUPTION_3      = 120000, //OnSpawn: Jiang
    SPELL_HELLFIRE_ARROW        = 113017,
    //LOREWALKER STONESTEP SPELLS
    SPELL_JADE_BLAST            = 107035,
    SPELL_JADE_BLAST_2          = 107048,
    SPELL_ROOT_SELF             = 106822,
    SPELL_LOREWALKER_ALACRITY   = 122714, //To cast on players
    SPELL_MEDITATION            = 122715,
    //SCROLL SPELLS
    SPELL_SCROLL_FLOOR          = 107350, //On spawn
    SPELL_JADE_ENERGY           = 107384,
    SPELL_JADE_ENERGY_2         = 111452, //On spawn
    SPELL_DRAW_SHA_2            = 111393,
    SPELL_DRAW_SHA_3            = 111431,
    SPELL_SHA_BURNING           = 111588, //OnDied
    SPELL_SHA_EXPLOSION         = 111579, //OnDied
    SPELL_DEATH                 = 98391,  //OnDied
    //SUN SPELLS
    SPELL_DRAW_SHA              = 111395,
    SPELL_SUN                   = 107349,
    SPELL_GROW_LOW              = 104921,
    SPELL_GROW_HIGH             = 111701,
    SPELL_SUNFIRE_EXPLOSION     = 111737,
    SPELL_DUMMY_NUKE            = 105898, //11 00 04 - 11 07 05 - 11 40 22
    SPELL_SUNFIRE_BLAST         = 111853,
    SPELL_SUNFIRE_RAYS          = 107223, //09 26 28 - 09 46 29 - 10 06 46
    SPELL_EXTRACT_SHA           = 111764,
    SPELL_EXTRACT_SHA_2         = 111806,
    SPELL_EXTRACT_SHA_3         = 111807,
    SPELL_EXTRACT_SHA_4         = 111768,
    SPELL_UNKNOWN               = 105581,
    //JIANG SPELLS
    SPELL_JUGGLER_JIANG         = 114745, //OnSpawn: Jiang
    //THE SONGBIRD QUEEN SPELLS
    SPELL_SINGING_SONGBIRD      = 114789, //OnSpawn: Songbird
    //HAUNTING SHA SPELLS
    SPELL_HAUNTING_GAZE         = 114650, //OnSpawn
    //XIANG SPELLS
    SPELL_JUGGLER_XIANG         = 114718,
    //FISH SPELLS
    SPELL_WATER_BUBBLE          = 114549, //OnSpawn
    //ChannelSpell : 42808, 512
    
    SPELL_POSSESSED_BY_SHA      = 110164, //On Spawn
    SPELL_JADE_ESSENCE          = 106797, //AddAura on phase 2
    SPELL_TRANSFORM_VISUAL      = 74620, //When the dragon is dead, cast this and remove the possess aura.
    
    SPELL_FIGMENT_OF_DOUBT_2    = 106935,
    SPELL_COPY_WEAPON           = 41054,
    SPELL_COPY_WEAPON_2         = 41055,
    SPELL_BOUNDS_OF_REALITY_2   = 117665,
};

enum Creatures
{
    CREATURE_WISE_MARI              = 56448,

    CREATURE_SCROLL                 = 57080,
    CREATURE_ZAO_SUNSEEKER          = 58826,
    CREATURE_LOREWALKTER_STONESTEP  = 56843,
    CREATURE_SUN                    = 56915,
    CREATURE_SUN_TRIGGER            = 56861,
    CREATURE_HAUNTING_SHA_2         = 58856,

    CREATURE_STRIFE                 = 59726,
    CREATURE_PERIL                  = 59051,

    CREATURE_MINION_OF_DOUBTS       = 57109,
    CREATURE_LIU_FLAMEHEART         = 56732,
    CREATURE_YU_LON                 = 56762,
    CREATURE_JADE_FIRE              = 56893,

    CREATURE_FIGMENT_OF_DOUBT       = 56792,
    CREATURE_SHA_OF_DOUBT           = 56439,
};

enum GameObjects
{
    GAMEOBJECT_DOOR_WISE_MARI           = 213550,
    GAMEOBJECT_DOOR_LOREWALKER_STONSTEP = 213549,
    GAMEOBJECT_DOOR_LIU_FLAMEHEART      = 213548,
    GAMEOBJECT_DOOR_LIU_FLAMEHEART_2    = 213544,
};

enum Types
{
    TYPE_LOREWALKTER_STONESTEP               = 0,
    TYPE_NUMBER_SUN_DEFEATED                 = 1,
    TYPE_SET_SUNS_SELECTABLE                 = 2,
    TYPE_LOREWALKER_STONESTEP_TALK_AFTER_ZAO = 3,
    TYPE_SET_SCROLL_SELECTABLE               = 4,
    TYPE_GET_EVENT_LOREWALKER_STONESTEP      = 5,
    TYPE_LIU_FLAMEHEART_STATUS               = 6,
    TYPE_IS_WIPE                             = 7,
    TYPE_CLASS_FIGMENT                       = 8,
    TYPE_CLASS_FIGMENT_DIE                   = 9,
};

enum Status
{
    STATUS_LOREWALKER_STONESTEP_NONE        = 1,
    STATUS_LOREWALKER_STONESTEP_INTRO       = 2,
    STATUS_LOREWALKER_STONESTEP_SPAWN_SUNS  = 3,
    STATUS_LOREWALKER_STONESTEP_SPAWN_SUNS_2= 4,
    STATUS_LOREWALKER_STONESTEP_ZAO_COMBAT  = 5,
    STATUS_LOREWALKER_STONESTEP_FINISH      = 6,
};

#endif
