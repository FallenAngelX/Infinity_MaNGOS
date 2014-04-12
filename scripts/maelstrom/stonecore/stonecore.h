/* Copyright (C) 2006 - 2013 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_STONECORE_H
#define DEF_STONECORE_H

enum
{
    TYPE_CORBORUS   = 0,
    TYPE_SLABHIDE   = 1,
    TYPE_OZRUK      = 2,
    TYPE_AZIL       = 3,

    MAX_ENCOUNTER   = 4,
};

enum CreatureIds
{
    // Dungeon Bosses

    BOSS_CORBORUS                  = 43438,
    BOSS_SLABHIDE                  = 43214,
    BOSS_OZRUK                     = 42188,
    BOSS_HIGH_PRIESTESS_AZIL       = 42333,

    // Trash mobs

    NPC_CRYSTALSPAWN_GIANT         = 42810,
    NPC_IMP                        = 43014,
    NPC_MILLHOUSE_MANASTORM        = 43391,
    NPC_ROCK_BORER                 = 43917,
    NPC_ROCK_BORER2                = 42845,
    NPC_STONECORE_BERSERKER        = 43430,
    NPC_STONECORE_BRUISER          = 42692,
    NPC_STONECORE_EARTHSHAPER      = 43537,
    NPC_STONECORE_FLAYER           = 42808,
    NPC_MAGMALORD                  = 42789,
    NPC_RIFT_CONJURER              = 42691,
    NPC_STONECORE_SENTRY           = 42695,
    NPC_STONECORE_WARBRINGER       = 42696,

    // Various NPCs

    NPC_EARTHWARDEN_YRSA           = 50048,
    NPC_STONECORE_TELEPORTER1      = 51396,
    NPC_STONECORE_TELEPORTER2      = 51397,
};

enum GameObjectIds
{
    GO_BROKEN_PILLAR               = 207407,
    GO_TWILIGHT_DOCUMENTS          = 207415,
};

#endif