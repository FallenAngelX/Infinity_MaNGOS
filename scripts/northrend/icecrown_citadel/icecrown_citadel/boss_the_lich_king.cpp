/* Copyright (C) 2006 - 2013 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
ScriptData
SDName: boss_the_lich_king
SD%Complete: 99%
SDComment:  by michalpolko with special thanks to:
            mangosR2 team and all who are supporting us with feedback, testing and fixes
            TrinityCore for some info about spells IDs
            everybody whom I forgot to mention here ;)

SDCategory: Icecrown Citadel
*/

#include "precompiled.h"
#include "icecrown_citadel.h"

enum BossSpells
{
    SPELL_BERSERK               = 47008,
    SPELL_SIT_EMOTE_NO_SHEATH   = 73220,
 // SPELL_PLAGUE_AVOIDANCE      = 72846,

    // Intro
    SPELL_ICE_LOCK              = 71614,

    // Outro
    SPELL_FURY_OF_FROSTMOURNE   = 72350,
 // SPELL_FURY_OF_FROSTMOURNE2  = 72351, // cannot resurect aura
    SPELL_RAISE_DEAD            = 71769,
    SPELL_SUMMON_BROKEN_FROSTMOURNE = 72406,
    SPELL_THROW_FROSTMOURNE     = 73017, // 1
    SPELL_BROKEN_FROSTMOURNE    = 72398, // 2
 // SPELL_SUMMON_FROSTMOURNE    = 72407, // 3 summon npc which casts 4 and 5 and LK enters this npc as vehicle
    SPELL_FROSTMOURNE_DESPAWN   = 72726, // 4
    SPELL_FROSTMOURNE_SPIRITS   = 72405, // 5
    SPELL_SOUL_BARRAGE          = 72305, // strangulation and sounds
 // SPELL_LK_CINEMATIC          = 73159,

    // Tirion
    SPELL_LIGHTS_BLESSING       = 71797, // after 5secs smashes Ice Lock

    // Terenas Menethil
    SPELL_MASS_RESURRECTION     = 72429, // dummy
 // SPELL_MASS_RESURRECTION2    = 72423, // actual res

    // Phase One
    SPELL_NECROTIC_PLAGUE       = 70337,
    SPELL_NECROTIC_PLAGUE_STACK = 70338,
    SPELL_INFEST                = 70541,
    SPELL_SUMMON_GHOULS         = 70358,
    SPELL_SUMMON_HORROR         = 70372,
    SPELL_SHADOW_TRAP           = 73539,

    // Phase transition
    SPELL_REMORSELESS_WINTER_1  = 68981,
    SPELL_REMORSELESS_WINTER_2  = 72259,
    SPELL_QUAKE                 = 72262,
    SPELL_PAIN_AND_SUFFERING    = 72133,
    SPELL_RAGING_SPIRIT         = 69200,
    SPELL_SUMMON_RAGING_SPIRIT  = 69201,
 // SPELL_SUMMON_ICE_SPHERE     = 69103,
    SPELL_ICE_SPHERE            = 69104, // missile and summon effect

    // Phase Two
    SPELL_SUMMON_VALKYR         = 69037,
 // SPELL_SUMMON_VALKYRS        = 74361, // 25man
    SPELL_SOUL_REAPER           = 69409,
    SPELL_DEFILE                = 72762,

    // Phase Three
    SPELL_VILE_SPIRITS          = 70498,
    SPELL_HARVEST_SOUL          = 68980, // stun aura and periodic damage, triggers summoning of vehicle
    SPELL_HARVEST_SOUL_TP_FM_N  = 72546, // teleports to Frostmourne Room and applies 60sec dummy aura (normal)
    SPELL_HARVEST_SOUL_TP_FM_H  = 73655, // teleports to Frostmourne Room and applies 60sec DoT aura (heroic)
    SPELL_HARVEST_SOUL_CLONE    = 71372,
    SPELL_HARVEST_SOULS         = 74296,
    SPELL_HARVESTED_SOUL_1      = 72679, // 10man N
    SPELL_HARVESTED_SOUL_2      = 74319, // 10man H
    SPELL_HARVESTED_SOUL_3      = 74318, // 25man N
    SPELL_HARVESTED_SOUL_4      = 74320, // 25man H

    SPELL_FROSTMOURNE_TP_VISUAL = 73078,

    // Shambling Horror
    SPELL_FRENZY                = 28747,
    SPELL_ENRAGE                = 72143,
    SPELL_SHOCKWAVE             = 72149,

    // Shadow Trap
    SPELL_SHADOW_TRAP_VISUAL    = 73530,
    SPELL_SHADOW_TRAP_AURA      = 73525,

    // Raging Spirit
    SPELL_SOUL_SHRIEK           = 69242,
    SPELL_RAGING_SPIRIT_VISUAL  = 69198, // clone effect (clone of player)

    // Ice Sphere
 // SPELL_ICE_SPHERE_VISUAL     = 69090,
    SPELL_ICE_BURST_AURA        = 69109,
 // SPELL_ICE_BURST             = 69108,
    SPELL_ICE_PULSE             = 69091,

    // Val'kyr Shadowguard
    SPELL_LIFE_SIPHON           = 73783,
    SPELL_VALKYR_CHARGE         = 74399,
    SPELL_HARVEST_SOUL_VEHICLE  = 68985,
    SPELL_EJECT_PASSENGERS      = 68576,
    SPELL_WINGS_OF_THE_DAMNED   = 74352,

    // Defile
    SPELL_DEFILE_AURA           = 72743,
 // SPELL_DEFILE_GROW           = 72756,

    // Vile Spirit and Wicked Spirit
    SPELL_SPIRIT_BURST_AURA     = 70502,

    // Spirit Warden
    SPELL_DARK_HUNGER           = 69383,
    SPELL_DESTROY_SOUL          = 74086,
    SPELL_SOUL_RIP              = 69397, // 3500, each next one x2 (maybe based on HP of target?)

    // Terenas in Frostmourne
    SPELL_RESTORE_SOUL          = 72595,
    SPELL_RESTORE_SOUL_HEROIC   = 73650,
    SPELL_LIGHTS_FAVOR          = 69382,
 // SPELL_SUMMON_SPIRIT_BOMBS_1 = 73581, // heroic only, summons Spirit Bomb every 1 sec
    SPELL_SUMMON_SPIRIT_BOMBS_2 = 74299, // 2 secs interval
    SPELL_SUMMON_SPIRIT_BOMB    = 74300, // aura doesnt work somehow, so we will use manual summoning

    // Spirit Bomb
    SPELL_SPIRIT_BOMB_VISUAL    = 73572,
    SPELL_EXPLOSION             = 73804,

    // NPCs
    NPC_SHADOW_TRAP             = 39137,
    NPC_FROSTMOURNE             = 38584,
    NPC_ICE_SPHERE              = 36633,
 // NPC_RAGING_SPIRIT           = 36701,
 // NPC_DEFILE                  = 38757,
    NPC_SPIRIT_WARDEN           = 36824,
    NPC_TERENAS_FM_NORMAL       = 36823,
    NPC_TERENAS_FM_HEROIC       = 39217,
    NPC_WICKED_SPIRIT           = 39190,
 // NPC_SPIRIT_BOMB             = 39189,
};

// talks
enum
{
    SAY_INTRO_1                 = -1631158,
    SAY_INTRO_2                 = -1631159,
    SAY_INTRO_3                 = -1631160,
    SAY_INTRO_4                 = -1631161,
    SAY_INTRO_5                 = -1631162,
    SAY_AGGRO                   = -1631163,
    SAY_REMORSELESS_WINTER      = -1631164,
    SAY_SHATTER_ARENA           = -1631165,
    SAY_SUMMON_VALKYR           = -1631166,
    SAY_HARVEST_SOUL            = -1631167,
    SAY_FM_TERENAS_AID_1        = -1631168,
    SAY_FM_TERENAS_AID_2        = -1631169,
    SAY_FM_TERENAS_AID_3        = -1631170,
    SAY_FM_PLAYER_ESCAPE        = -1631171,
    SAY_FM_PLAYER_DEATH         = -1631172,
    SAY_SPECIAL_1               = -1631173,
    SAY_SPECIAL_2               = -1631174,
    SAY_LAST_PHASE              = -1631175,
    SAY_SLAY_1                  = -1631176,
    SAY_SLAY_2                  = -1631177,
    SAY_ENRAGE                  = -1631178,
    SAY_OUTRO_1                 = -1631179,
    SAY_OUTRO_2                 = -1631180,
    SAY_OUTRO_3                 = -1631181,
    SAY_OUTRO_4                 = -1631182,
    SAY_OUTRO_5                 = -1631183,
    SAY_OUTRO_6                 = -1631184,
    SAY_OUTRO_7                 = -1631185,
    SAY_OUTRO_8                 = -1631186,
    SAY_OUTRO_9                 = -1631187,
    SAY_OUTRO_10                = -1631188,
    SAY_OUTRO_11                = -1631189,
    SAY_OUTRO_12                = -1631190,
    SAY_OUTRO_13                = -1631191,
    SAY_OUTRO_14                = -1631192,
};

enum Common
{
     FINAL_ARTHAS_MOVIE         = 16,
     EQUIP_FROSTMOURNE          = 49706,
};

enum Phase
{
    PHASE_ONE,                          // phase one
    PHASE_RUNNING_WINTER_ONE,           // running to center of platform to cast Remorseless Winter
    PHASE_WINTER_ONE,                   // Remorseless Winter aura and casting spells, summoning orbs and spirits
    PHASE_QUAKE_ONE,                    // casting Quake
    PHASE_TWO,                          // phase two with val'kyrs and some more spells
    PHASE_RUNNING_WINTER_TWO,           // running to center of platform to cast Remorseless Winter again
    PHASE_WINTER_TWO,                   // second Remorseless Winter phase
    PHASE_QUAKE_TWO,                    // second Quake casting
    PHASE_THREE,                        // phase three, casting Soul Harvest (Frostmourne phase)
    PHASE_IN_FROSTMOURNE,               // phase three, waiting untill whole raid leaves Frostmourne
    PHASE_CUTSCENE,                     // phase when LK kills raid, Terenas comes etc.
    PHASE_DEATH_AWAITS,                 // strangulating Lich King, raid group finishing him
};

enum
{
    POINT_TIRION_INTRO,
    POINT_TIRION_OUTRO,
    POINT_CENTER_LAND_LICH_KING,
    POINT_VALKYR_THROW,
    POINT_VALKYR_CENTER,
    POINT_TP_TO_FM,              // point where strangulate vehicle moves, after reaching player is teleported into frostmourne
    POINT_SPIRIT_BOMB,           // Spirit Bomb moving down
};

static LOCATION SpawnLoc[] =
{
    {463.0f,     -2124.0f,      840.86f},    // 0 Lich King Intro
    {503.15652f, -2124.516602f, 840.86f},    // 1 Center of the platform
    {451.32f,    -2087.85f,     840.86f},    // 2 Val'kyr drop point right to Frozen Throne
    {449.60f,    -2161.71f,     840.86f},    // 3 Val'kyr drop point left to Frozen Throne
    {494.313f,   -2523.079f,    1049.87f}    // 4 center of platform inside Frostmourne
};

static LOCATION TirionLoc[] =
{
    {489.5f,     -2125.0f,      840.86f},     // 0 POINT_TIRION_INTRO
    {495.0f,     -2124.516602f, 840.86f},     // 1 POINT_TIRION_OUTRO
    {529.85302f, -2124.709961f, 840.86f},     // 2 Teleporter
};

#define GOSSIP_TIRION_START_EVENT "We are prepared, Highlord. Let us battle for the fate of Azeroth! For the light of dawn!"

/**
 * Tirion
 */
struct MANGOS_DLL_DECL boss_tirion_iccAI : public base_icc_bossAI
{
    boss_tirion_iccAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        Reset();
    }

    uint8  m_uiEventStep;
    uint32 m_uiEventTimer;
    ObjectGuid m_guidTerenas;
    ObjectGuid m_guidFrostmourne;

    bool m_bDebuggingEvent;

    void Reset() override
    {
        m_uiEventTimer = 0;
        m_guidTerenas.Clear();
        m_guidFrostmourne.Clear();
        m_bDebuggingEvent = false;
        if (m_pInstance && m_pInstance->GetData(TYPE_LICH_KING) != DONE)
            m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        else
            m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    }

    void EnterEvadeMode() override
    {
        if (m_pInstance)
        {
            if (m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
                base_icc_bossAI::EnterEvadeMode();
        }
    }

    void JustReachedHome() override
    {
        Reset();
    }

    void DoSetDebuggingEvent(bool bStatus)
    {
        m_bDebuggingEvent = bStatus;
    }

    void DoStartEvent()
    {
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        m_creature->SetWalk(true);
        m_creature->GetMotionMaster()->MovePoint(POINT_TIRION_INTRO, TirionLoc[0].x, TirionLoc[0].y, TirionLoc[0].z, false);
    }

    void DoPauseEvent()
    {
        m_uiEventTimer = 0;
    }

    void DoNextEventStep(uint32 uiTimer = 1)
    {
        ++m_uiEventStep;
        m_uiEventTimer = uiTimer;
    }

    void DoLichKingText(int32 iText)
    {
        if (m_pInstance)
        {
            if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                DoScriptText(iText, pLichKing);
        }
    }

    void DoLichKingEmote(uint32 uiEmote)
    {
        if (m_pInstance)
        {
            if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                pLichKing->HandleEmote(uiEmote);
        }
    }

    void MovementInform(uint32 uiMovementType, uint32 uiData) override
    {
        if (uiMovementType != POINT_MOTION_TYPE)
            return;

        switch (uiData)
        {
            case POINT_TIRION_INTRO:
            {
                m_uiEventStep = 0;
                m_uiEventTimer = 2000;
                break;
            }
            case POINT_TIRION_OUTRO:
            {
                m_creature->GetMotionMaster()->Clear();
                m_creature->MonsterMoveToDestination(SpawnLoc[1].x + 8.0f, SpawnLoc[1].y, SpawnLoc[1].z, m_creature->GetOrientation(), 8.0f, 05.0f);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_SPECIALATTACK1H);
                DoNextEventStep(1500);
                break;
            }
        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_uiEventTimer == 0)
            return;

        // events
        if (m_uiEventTimer <= uiDiff)
        {
            switch (m_uiEventStep)
            {
                case 0:
                {
                    SetCombatMovement(false);
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        if (m_creature->Attack(pLichKing, true))
                        {
                            m_creature->AddThreat(pLichKing);
                            m_creature->SetInCombatWith(pLichKing);
                        }
                        pLichKing->SetWalk(true);
                        pLichKing->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                        pLichKing->SetStandState(UNIT_STAND_STATE_STAND);
                        pLichKing->GetMotionMaster()->MovePoint(0, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z);
                    }
                    DoLichKingText(SAY_INTRO_1);
                    DoNextEventStep(14000);
                    break;
                }
                case 1:
                {
                    DoScriptText(SAY_INTRO_2, m_creature);
                    DoNextEventStep(7000);
                    break;
                }
                case 2:
                {
                    DoLichKingText(SAY_INTRO_3);
                    DoNextEventStep(4000);
                    break;
                }
                case 3:
                {
                    DoLichKingEmote(EMOTE_ONESHOT_SHOUT);
                    DoNextEventStep(4000);
                    break;
                }
                case 4:
                {
                    DoLichKingEmote(EMOTE_ONESHOT_POINT);
                    DoNextEventStep(4000);
                    break;
                }
                case 5:
                {
                    DoLichKingEmote(EMOTE_ONESHOT_SHOUT);
                    DoNextEventStep(10000);
                    break;
                }
                case 6:
                {
                    DoScriptText(SAY_INTRO_4, m_creature);
                    m_creature->HandleEmote(EMOTE_ONESHOT_POINT);
                    DoNextEventStep(4000);
                    break;
                }
                case 7:
                {
                    SetCombatMovement(true, true);
                    DoNextEventStep(1000);
                    break;
                }
                case 8:
                {
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        pLichKing->CastSpell(m_creature, SPELL_ICE_LOCK, false);
                        DoScriptText(SAY_INTRO_5, pLichKing);
                    }
                    DoNextEventStep(1000);
                    break;
                }
                case 9:
                {
                    DoPauseEvent(); // battle with Lich King
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        pLichKing->RemoveAllAuras();
                        pLichKing->SetWalk(false);
                        pLichKing->SetVirtualItem(VIRTUAL_ITEM_SLOT_0, EQUIP_FROSTMOURNE);
                        pLichKing->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
                        if (m_bDebuggingEvent) // Debug
                            DoNextEventStep(5000);
                        else
                        {
                            pLichKing->SetInCombatWithZone();
                            if (!pLichKing->SelectHostileTarget())
                                pLichKing->AI()->EnterEvadeMode();
                        }
                    }
                    break;
                }
                // *** ENDING INTRO ***
                case 10:
                {
                    SetCombatMovement(false, true);
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        pLichKing->AI()->SetCombatMovement(false, true);
                        pLichKing->CastSpell(pLichKing, SPELL_FURY_OF_FROSTMOURNE, true);
                    }
                    DoScriptText(SAY_LAST_PHASE, m_creature);
                    DoNextEventStep(17000);
                    break;
                }
                case 11:
                {
                    DoLichKingText(SAY_OUTRO_1);
                    DoNextEventStep(26000);
                    break;
                }
                case 12:
                {
                    DoLichKingText(SAY_OUTRO_2);
                    DoNextEventStep(10000);
                    break;
                }
                case 13:
                {
                    DoLichKingText(SAY_OUTRO_3);
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                        pLichKing->SetFacingToObject(m_creature);
                    DoNextEventStep(23000);
                    break;
                }
                case 14:
                {
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        DoScriptText(SAY_OUTRO_4, pLichKing);
                        pLichKing->GetMotionMaster()->MovePoint(POINT_CENTER_LAND_LICH_KING, SpawnLoc[1].x, SpawnLoc[1].y, SpawnLoc[1].z, false);
                    }
                    DoNextEventStep(27000);
                    break;
                }
                case 15:
                {
                    DoLichKingText(SAY_OUTRO_5);
                    DoNextEventStep(12000);
                    break;
                }
                case 16:
                {
                    DoScriptText(SAY_OUTRO_6, m_creature);
                    DoNextEventStep(8000);
                    break;
                }
                case 17:
                {
                    DoCastSpellIfCan(m_creature, SPELL_LIGHTS_BLESSING, CAST_TRIGGERED);
                    DoNextEventStep(5000);
                    break;
                }
                case 18:
                {
                    m_creature->RemoveAurasDueToSpell(SPELL_ICE_LOCK);

                    // run to Lich King
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        m_creature->SetWalk(false);
                        m_creature->GetMotionMaster()->MovePoint(POINT_TIRION_OUTRO, TirionLoc[1].x, TirionLoc[1].y, TirionLoc[1].z, false);
                    }
                    DoPauseEvent(); // wait for arriving at Lich King and attack him
                    break;
                }
                case 19:
                {
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        pLichKing->CastSpell(pLichKing, SPELL_FROSTMOURNE_DESPAWN, false);
                        pLichKing->CastSpell(pLichKing, SPELL_SUMMON_BROKEN_FROSTMOURNE, false);
                        DoScriptText(SAY_OUTRO_7, pLichKing);
                    }
                    DoNextEventStep(3500);
                    break;
                }
                case 20:
                {
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        pLichKing->CastSpell(pLichKing, 73021, false);
                        pLichKing->CastSpell(pLichKing, SPELL_THROW_FROSTMOURNE, false);
                        pLichKing->SetVirtualItem(VIRTUAL_ITEM_SLOT_0, 0);
                        m_creature->SetFacingToObject(pLichKing);
                    }
                    DoNextEventStep(1000);
                    break;
                }
                case 21:
                {
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {

                        float x, y, z;
                        pLichKing->GetClosePoint(x, y, z, pLichKing->GetObjectBoundingRadius(), 3.0f, pLichKing->GetOrientation());
                        if (Creature* pFrostmourne = m_creature->SummonCreature(NPC_FROSTMOURNE, x, y, z, 0.0f, TEMPSUMMON_MANUAL_DESPAWN, 0))
                        {
                            pFrostmourne->CastSpell(pFrostmourne, SPELL_BROKEN_FROSTMOURNE, false);
                            m_guidFrostmourne = pFrostmourne->GetObjectGuid();
                        }
                    }

                    DoNextEventStep(4000);
                    break;
                }
                case 22:
                {
                    DoScriptText(SAY_OUTRO_8, m_creature);
                    m_creature->RemoveAllAuras();
                    m_creature->GetMotionMaster()->Clear();
                    m_creature->MonsterMoveToDestination(TirionLoc[2].x, TirionLoc[2].y, TirionLoc[2].z, m_creature->GetOrientation(), 12.0f, 3.0f);

                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        if (Creature* pFrostmourne = m_pInstance->instance->GetCreature(m_guidFrostmourne))
                        {
                            float x, y, z;
                            pFrostmourne->GetPosition(x, y, z);
                            pFrostmourne->CastSpell(pFrostmourne, SPELL_FROSTMOURNE_SPIRITS, false);
                            pLichKing->CastSpell(pLichKing, SPELL_SOUL_BARRAGE, false);
                            pLichKing->SetLevitate(true);
                            pLichKing->GetMotionMaster()->Clear();
                            pLichKing->MonsterMoveWithSpeed(x, y, z + 2.0f, 2.0f, false);
                        }
                    }

                    DoNextEventStep(5000);
                    break;
                }
                case 23:
                {
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        float x, y, z;
                        pLichKing->GetClosePoint(x, y, z, pLichKing->GetObjectBoundingRadius(), 6.0f, pLichKing->GetAngle(m_creature) + 1.0f);

                        if (Creature* pTerenas = m_creature->SummonCreature(NPC_MENETHIL, x, y, z, 0.0f, TEMPSUMMON_MANUAL_DESPAWN, 0))
                        {
                            m_guidTerenas = pTerenas->GetObjectGuid();
                            pTerenas->SetFacingToObject(pLichKing);
                            DoScriptText(SAY_OUTRO_9, pTerenas);
                        }
                    }

                    DoNextEventStep(10000);
                    break;
                }
                case 24:
                {
                    if (Creature* pTerenas = m_pInstance->instance->GetCreature(m_guidTerenas))
                    {
                        DoScriptText(SAY_OUTRO_10, pTerenas);
                        pTerenas->CastSpell(pTerenas, SPELL_MASS_RESURRECTION, false);
                    }

                    DoNextEventStep(6000);
                    break;
                }
                case 25:
                {
                    DoScriptText(SAY_OUTRO_11, m_creature);
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                       if (Creature* pTerenas = m_pInstance->instance->GetCreature(m_guidTerenas))
                            pTerenas->AI()->AttackStart(pLichKing);

                        m_creature->GetMotionMaster()->Clear();
                        SetCombatMovement(true, true);
                        AttackStart(pLichKing);
                    }
                    DoNextEventStep(6000);
                    break;
                }
                case 26:
                {
                    DoLichKingText(SAY_OUTRO_12);
                    DoNextEventStep(9000);
                    break;
                }
                case 27:
                {
                    DoLichKingText(SAY_OUTRO_13);
                    DoPauseEvent(); // wait until Lich King is dead
                    if (m_bDebuggingEvent) // Debug
                        DoNextEventStep(10000);
                    break;
                }
                case 28:
                {
                    DoNextEventStep(8000);
                    break;
                }
                case 29:
                {
                    if (Creature* pFrostmourne = m_pInstance->instance->GetCreature(m_guidFrostmourne))
                        pFrostmourne->ForcedDespawn(2000);
                    if (Creature* pTerenas = m_pInstance->instance->GetCreature(m_guidTerenas))
                        pTerenas->ForcedDespawn(2000);
                    // play cinematic
                    Map::PlayerList const& list = m_pInstance->instance->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = list.begin(); itr != list.end(); ++itr)
                    {
                        itr->getSource()->SendMovieStart(FINAL_ARTHAS_MOVIE);
                    }
                    DoPauseEvent(); // Finish
                    if (m_bDebuggingEvent) // Debug
                    {
                        if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                        {
                            pLichKing->SetLevitate(false);
                            DoSetDebuggingEvent(false);
                            pLichKing->AI()->EnterEvadeMode();
                        }
                        base_icc_bossAI::EnterEvadeMode();
                    }
                    break;
                }
            }
        }
        else
            m_uiEventTimer -= uiDiff;

        if (IsCombatMovement())
            DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_tirion_icc(Creature* pCreature)
{
    return new boss_tirion_iccAI(pCreature);
}

bool GossipHello_boss_tirion_icc(Player* pPlayer, Creature* pCreature)
{
    ScriptedInstance* pInstance = (ScriptedInstance*)pCreature->GetInstanceData();

    if (!pInstance)
        return true;

    if (pInstance->GetData(TYPE_LICH_KING) != NOT_STARTED &&
        pInstance->GetData(TYPE_LICH_KING) != FAIL )
    {
        return true;
    }

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TIRION_START_EVENT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
    if (pPlayer->isGameMaster())
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Debug event", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->SEND_GOSSIP_MENU(15290, pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_boss_tirion_icc(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    boss_tirion_iccAI* pTirionAI = dynamic_cast<boss_tirion_iccAI*>(pCreature->AI());
    if (!pTirionAI)
        return true;

    pTirionAI->DoSetDebuggingEvent(false);

    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            if (pPlayer->isGameMaster())
                pTirionAI->DoSetDebuggingEvent(true);
            // no break
        case GOSSIP_ACTION_INFO_DEF:
            pTirionAI->DoStartEvent();
        break;
    }
    pPlayer->CLOSE_GOSSIP_MENU();
    return true;
}


/**
 * The Lich King
 */
struct MANGOS_DLL_DECL boss_the_lich_king_iccAI : public base_icc_bossAI
{
    boss_the_lich_king_iccAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        Reset();
        m_uiPlatformOriginalFlag = 0;
        m_bPillarsDestroyed = false;
        m_bIsFirstAttempt = true;
    }

    Phase  m_uiPhase;
    uint32 m_uiPhaseTimer;
    uint32 m_uiBerserkTimer;
    uint32 m_uiGhoulsTimer;
    uint32 m_uiHorrorTimer;
    uint32 m_uiNecroticPlagueTimer;
    uint32 m_uiInfestTimer;
    uint32 m_uiShadowTrapTimer;
    uint32 m_uiPainSufferingTimer;
    uint32 m_uiRagingSpiritTimer;
    uint32 m_uiIceSphereTimer;
    uint32 m_uiValkyrTimer;
    uint32 m_uiDefileTimer;
    uint32 m_uiSoulReaperTimer;
    uint32 m_uiHarvestSoulTimer;
    uint32 m_uiFrostmournePhaseTimer;
    uint32 m_uiVileSpiritsTimer;

    uint32 m_uiPlatformOriginalFlag;
    uint32 m_uiRespawnPlatformTimer;
    uint32 m_uiDestroyPillarsTimer;
    bool m_bPillarsDestroyed;
    bool m_bPlatformDestroyed;
    bool m_bIsFirstAttempt;

    void Reset() override
    {
        m_uiPhase               = PHASE_ONE;
        m_uiBerserkTimer        = 15 * MINUTE * IN_MILLISECONDS;
        m_uiGhoulsTimer         = 13000;
        m_uiHorrorTimer         = 21000;
        m_uiInfestTimer         = 20000;
        m_uiNecroticPlagueTimer = 23000;
        m_uiShadowTrapTimer     = 15000;
        m_uiPainSufferingTimer  = 6000;
        m_uiRagingSpiritTimer   = 20000;
        m_uiIceSphereTimer      = 6000;
        m_uiValkyrTimer         = 10000;
        m_uiDefileTimer         = 30000;
        m_uiSoulReaperTimer     = 25000;
        m_uiHarvestSoulTimer    = 5000;
        m_uiVileSpiritsTimer    = 20000;
        m_uiDestroyPillarsTimer = 3000;
        m_uiRespawnPlatformTimer= 3000;

        DoRespawnPlatform();
        SetCombatMovement(true);

        m_bPlatformDestroyed = false;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (!m_bIsFirstAttempt)
            DoScriptText(SAY_AGGRO, m_creature); // say aggro if this is another attempt

        if (!m_pInstance)
            return;

        m_pInstance->SetData(TYPE_LICH_KING, IN_PROGRESS);

        if (Creature* pTirion = m_pInstance->GetSingleCreatureFromStorage(NPC_TIRION))
        {
            if (boss_tirion_iccAI* pTirionAI = dynamic_cast<boss_tirion_iccAI*>(pTirion->AI()))
            {
                if (pTirionAI->m_bDebuggingEvent)
                    m_uiPhase = PHASE_DEATH_AWAITS;
            }
        }
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (m_creature->isInCombat())
            ScriptedAI::MoveInLineOfSight(pWho);
    }

    void KilledUnit(Unit* pWho) override
    {
        if (pWho->GetTypeId() == TYPEID_PLAYER && m_uiPhase != PHASE_DEATH_AWAITS)
            DoScriptText(urand(0, 1) ? SAY_SLAY_1 : SAY_SLAY_2, m_creature);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_LICH_KING, DONE);

        DoScriptText(SAY_OUTRO_14, m_creature);

        m_creature->GetMotionMaster()->MoveFall();

        // finish event, after around 8 seconds play cinematic
        if (m_pInstance)
        {
            if (Creature* pTirion = m_pInstance->GetSingleCreatureFromStorage(NPC_TIRION))
            {
                if (boss_tirion_iccAI* pTirionAI = dynamic_cast<boss_tirion_iccAI*>(pTirion->AI()))
                    pTirionAI->DoNextEventStep();
            }
        }
    }

    void EnterEvadeMode() override
    {
        if (m_pInstance)
        {
            if (Creature* pTirion = m_pInstance->GetSingleCreatureFromStorage(NPC_TIRION))
            {
                if (boss_tirion_iccAI* pTirionAI = dynamic_cast<boss_tirion_iccAI*>(pTirion->AI()))
                {
                    if (pTirionAI->m_bDebuggingEvent)
                        return;
                }
            }
        }
        base_icc_bossAI::EnterEvadeMode();
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_LICH_KING, FAIL);
            m_pInstance->SetData(TYPE_FROSTMOURNE_ROOM, NOT_STARTED);
            if (Creature* pTirion = m_pInstance->GetSingleCreatureFromStorage(NPC_TIRION))
            {
                pTirion->RemoveAllAuras();
                pTirion->DeleteThreatList();
                pTirion->CombatStop(true);
                if (pTirion->isAlive())
                    pTirion->GetMotionMaster()->MoveTargetedHome();
            }
        }

        m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SIT);
        m_creature->SetStandState(UNIT_STAND_STATE_SIT);
        DoCastSpellIfCan(m_creature, SPELL_SIT_EMOTE_NO_SHEATH, CAST_TRIGGERED);
        m_creature->SetVirtualItem(VIRTUAL_ITEM_SLOT_0, 0);

        m_bIsFirstAttempt = false;
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_ICE_SPHERE)
        {
            pSummoned->SetInCombatWithZone();

            if (Unit* pTarget = SelectTargetForIceSphere())
            {
                pSummoned->AddThreat(pTarget, 100000.0f);
                pSummoned->AI()->AttackStart(pTarget);
                pSummoned->CastSpell(pSummoned, SPELL_ICE_BURST_AURA, true);
                pSummoned->CastSpell(pTarget, SPELL_ICE_PULSE, false);
            }
        }
    }

    void MovementInform(uint32 uiMovementType, uint32 uiData) override
    {
        if (uiMovementType != POINT_MOTION_TYPE)
            return;

        switch (uiData)
        {
            case POINT_CENTER_LAND_LICH_KING:
            {
                switch (m_uiPhase)
                {
                    case PHASE_RUNNING_WINTER_ONE:
                    {
                        DoScriptText(SAY_REMORSELESS_WINTER, m_creature);
                        DoCastSpellIfCan(m_creature, SPELL_REMORSELESS_WINTER_1);
                        m_uiPhase               = PHASE_WINTER_ONE;
                        m_uiPhaseTimer          = 62000;
                        // set phase initial timers
                        m_uiPainSufferingTimer  = 6000;
                        m_uiRagingSpiritTimer   = 20000;
                        m_uiIceSphereTimer      = 6000;

                        // on heroic despawn Shadow Traps
                        if (m_bIsHeroic)
                            DoDespawnShadowTraps();
                        break;
                    }
                    case PHASE_RUNNING_WINTER_TWO:
                    {
                        DoScriptText(SAY_REMORSELESS_WINTER, m_creature);
                        DoCastSpellIfCan(m_creature, SPELL_REMORSELESS_WINTER_2);
                        m_uiRespawnPlatformTimer = 3000; // respawn platform after spell is cast
                        m_uiPhase                = PHASE_WINTER_TWO;
                        m_uiPhaseTimer           = 62000;
                        // set phase initial timers
                        m_uiPainSufferingTimer   = 6000;
                        m_uiRagingSpiritTimer    = 15000;
                        m_uiIceSphereTimer       = 6000;
                        break;
                    }
                    case PHASE_DEATH_AWAITS:
                    case PHASE_ONE: // Only possible in debugging
                    {
                        DoCastSpellIfCan(m_creature, SPELL_RAISE_DEAD);
                        break;
                    }
                }
                break;
            }
        }
    }

    void DamageTaken(Unit* /*pDealer*/, uint32& uiDamage) override
    {
        // Prevent exploit (Heroic)
        if (m_uiPhase == PHASE_IN_FROSTMOURNE)
            uiDamage = 0;
    }

    void DoDestroyPlatform()
    {
        if (!m_pInstance)
            return;

        if (GameObject* pGoFloor = m_pInstance->GetSingleGameObjectFromStorage(GO_ARTHAS_PLATFORM))
        {
             pGoFloor->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED | GO_FLAG_NODESPAWN);
             m_uiPlatformOriginalFlag = pGoFloor->GetUInt32Value(GAMEOBJECT_BYTES_1);
             pGoFloor->SetUInt32Value(GAMEOBJECT_BYTES_1, 8449);
        }

        if (GameObject* pGo = m_pInstance->GetSingleGameObjectFromStorage(GO_FROSTY_WIND))
            pGo->SetGoState(GO_STATE_READY);
        if (GameObject* pGo = m_pInstance->GetSingleGameObjectFromStorage(GO_SNOW_EDGE))
            pGo->SetGoState(GO_STATE_READY);

        m_bPlatformDestroyed = true;
    }

    void DoRespawnPlatform()
    {
        if (!m_pInstance)
            return;

        if (!m_bPlatformDestroyed)
            return;

        if (GameObject* pGoFloor = m_pInstance->GetSingleGameObjectFromStorage(GO_ARTHAS_PLATFORM))
        {
            pGoFloor->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED | GO_FLAG_NODESPAWN);
            pGoFloor->SetUInt32Value(GAMEOBJECT_BYTES_1, m_uiPlatformOriginalFlag);
        }

        if (GameObject* pGo = m_pInstance->GetSingleGameObjectFromStorage(GO_FROSTY_WIND))
            pGo->SetGoState(GO_STATE_ACTIVE);
        if (GameObject* pGo = m_pInstance->GetSingleGameObjectFromStorage(GO_SNOW_EDGE))
            pGo->SetGoState(GO_STATE_ACTIVE);

        m_bPlatformDestroyed = false;
    }

    void DoDespawnShadowTraps()
    {
        std::list<Creature*> lTraps;
        GetCreatureListWithEntryInGrid(lTraps, m_creature, NPC_SHADOW_TRAP, 120.0f);
        if (!lTraps.empty())
        {
            for (std::list<Creature*>::iterator i = lTraps.begin(); i != lTraps.end();)
            {
                std::list<Creature*>::iterator next = i;
                ++next;
                if (*i)
                    (*i)->ForcedDespawn();

                i = next;
            }
        }
    }

    Unit* SelectTargetForIceSphere()
    {
        std::list<ObjectGuid> lPotentialTargets;
        const ThreatList& threatList = m_creature->getThreatManager().getThreatList();
        for (ThreatList::const_iterator itr = threatList.begin();itr != threatList.end(); ++itr)
        {
            if (Unit* pVictim = m_creature->GetMap()->GetUnit((*itr)->getUnitGuid()))
            {
                if (!pVictim->HasAuraOfDifficulty(SPELL_ICE_PULSE))
                    lPotentialTargets.push_back((*itr)->getUnitGuid());
            }
        }

        if (!lPotentialTargets.empty())
        {
            std::list<ObjectGuid>::iterator i = lPotentialTargets.begin();
            std::advance(i, urand(0, lPotentialTargets.size() - 1));
            return m_creature->GetMap()->GetUnit(*i);
        }
        else
            return m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_ICE_PULSE, SELECT_FLAG_PLAYER);
    }

    void DoPrepareFrostmourneRoom()
    {
        // Terenas + Spirit Warden
        if (!m_bIsHeroic)
        {
            m_creature->SummonCreature(NPC_TERENAS_FM_NORMAL, SpawnLoc[4].x - 5.0f, SpawnLoc[4].y, SpawnLoc[4].z, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 68000, true);
            m_creature->SummonCreature(NPC_SPIRIT_WARDEN, SpawnLoc[4].x + 5.0f, SpawnLoc[4].y, SpawnLoc[4].z, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 68000, true);
        }
        // Terenas + Spirit Bombs and Spirits
        else
        {
            m_creature->SummonCreature(NPC_TERENAS_FM_HEROIC, SpawnLoc[4].x, SpawnLoc[4].y, SpawnLoc[4].z, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 48000, true);
        }

        if (m_pInstance)
            m_pInstance->SetData(TYPE_FROSTMOURNE_ROOM, IN_PROGRESS);
    }

    void SpellHit(Unit* /*pCaster*/, const SpellEntry* pSpell) override
    {
        if (pSpell->Id == SPELL_HARVESTED_SOUL_1 ||
            pSpell->Id == SPELL_HARVESTED_SOUL_2 ||
            pSpell->Id == SPELL_HARVESTED_SOUL_3 ||
            pSpell->Id == SPELL_HARVESTED_SOUL_4)
        {
            DoScriptText(SAY_FM_PLAYER_DEATH, m_creature);
        }
    }

    void UpdateInfest(const uint32 uiDiff)
    {
        if (m_uiInfestTimer <= uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_INFEST) == CAST_OK)
                m_uiInfestTimer = urand(20000, 25000);
        }
        else
            m_uiInfestTimer -= uiDiff;
    }

    void UpdateSoulReaper(const uint32 uiDiff)
    {
        if (m_uiSoulReaperTimer <= uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_SOUL_REAPER) == CAST_OK)
                m_uiSoulReaperTimer = 30000;
        }
        else
            m_uiSoulReaperTimer -= uiDiff;
    }

    void UpdateDefile(const uint32 uiDiff)
    {
        if (m_uiDefileTimer > uiDiff)
        {
            m_uiDefileTimer -= uiDiff;
            return;
        }
        std::list<ObjectGuid> lPotentialTargets;
        const ThreatList& threatList = m_creature->getThreatManager().getThreatList();
        for (ThreatList::const_iterator itr = threatList.begin();itr != threatList.end(); ++itr)
        {
            if (Unit* pVictim = m_creature->GetMap()->GetUnit((*itr)->getUnitGuid()))
            {
                if (pVictim->GetTypeId() == TYPEID_PLAYER && !pVictim->GetVehicle())
                    lPotentialTargets.push_back((*itr)->getUnitGuid());
            }
        }

        Unit* pTarget = NULL;
        if (!lPotentialTargets.empty())
        {
            std::list<ObjectGuid>::iterator i = lPotentialTargets.begin();
            std::advance(i, urand(0, lPotentialTargets.size() - 1));
            pTarget = m_creature->GetMap()->GetUnit(*i);
        }

        if (!pTarget)
            pTarget =  m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, SPELL_DEFILE, SELECT_FLAG_PLAYER);

        if (pTarget && DoCastSpellIfCan(pTarget, SPELL_DEFILE) == CAST_OK)
            m_uiDefileTimer = 30000;
    }

    void UpdateNecroticPlague(const uint32 uiDiff)
    {
        if (m_uiNecroticPlagueTimer > uiDiff)
        {
            m_uiNecroticPlagueTimer -= uiDiff;
            return;
        }

        std::list<ObjectGuid> lPotentialTargets;
        const ThreatList& threatList = m_creature->getThreatManager().getThreatList();
        for (ThreatList::const_iterator itr = threatList.begin();itr != threatList.end(); ++itr)
        {
            if (Unit* pVictim = m_creature->GetMap()->GetUnit((*itr)->getUnitGuid()))
            {
                if (pVictim != m_creature->getVictim() &&
                    !pVictim->HasAuraOfDifficulty(SPELL_NECROTIC_PLAGUE) &&
                    !pVictim->HasAuraOfDifficulty(SPELL_NECROTIC_PLAGUE_STACK))
                {
                    lPotentialTargets.push_back((*itr)->getUnitGuid());
                }
            }
        }

        if (lPotentialTargets.empty())
            return;
        std::list<ObjectGuid>::iterator i = lPotentialTargets.begin();
        std::advance(i, urand(0, lPotentialTargets.size() - 1));
        Unit* pTarget = m_creature->GetMap()->GetUnit(*i);

        if (pTarget && DoCastSpellIfCan(pTarget, SPELL_NECROTIC_PLAGUE) == CAST_OK)
            m_uiNecroticPlagueTimer = 30000;
    }

    void UpdateDestroyPillars(const uint32 uiDiff)
    {
        if (m_bPillarsDestroyed)
            return;

        if (m_uiDestroyPillarsTimer > uiDiff)
        {
            m_uiDestroyPillarsTimer -= uiDiff;
            return;
        }
        m_bPillarsDestroyed = true;

        if (m_pInstance)
            return;

        if (GameObject* pGo = m_pInstance->GetSingleGameObjectFromStorage(GO_ICESHARD_1))
            pGo->SetGoState(GO_STATE_ACTIVE);
        if (GameObject* pGo = m_pInstance->GetSingleGameObjectFromStorage(GO_ICESHARD_2))
            pGo->SetGoState(GO_STATE_ACTIVE);
        if (GameObject* pGo = m_pInstance->GetSingleGameObjectFromStorage(GO_ICESHARD_3))
            pGo->SetGoState(GO_STATE_ACTIVE);
        if (GameObject* pGo = m_pInstance->GetSingleGameObjectFromStorage(GO_ICESHARD_4))
            pGo->SetGoState(GO_STATE_ACTIVE);
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (m_uiPhase != PHASE_DEATH_AWAITS && m_uiPhase != PHASE_IN_FROSTMOURNE)
        {
            // check evade
            if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
                return;

            // Berserk
            if (m_uiBerserkTimer <= uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_BERSERK) == CAST_OK)
                {
                    DoScriptText(SAY_ENRAGE, m_creature);
                    m_uiBerserkTimer = 30 * MINUTE * IN_MILLISECONDS;
                }
            }
            else
                m_uiBerserkTimer -= uiDiff;
        }

        switch (m_uiPhase)
        {
            case PHASE_ONE:
            {
                // check HP
                if (m_creature->GetHealthPercent() <= 70.0f)
                {
                    // phase transition
                    SetCombatMovement(false, true);
                    m_creature->GetMotionMaster()->MovePoint(POINT_CENTER_LAND_LICH_KING, SpawnLoc[1].x, SpawnLoc[1].y, SpawnLoc[1].z);
                    m_uiPhase = PHASE_RUNNING_WINTER_ONE;
                    return;
                }

                // Infest
                UpdateInfest(uiDiff);

                // Necrotic Plague
                UpdateNecroticPlague(uiDiff);

                // Summon Ghouls
                if (m_uiGhoulsTimer <= uiDiff)
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_GHOULS) == CAST_OK)
                        m_uiGhoulsTimer = 32000;
                }
                else
                    m_uiGhoulsTimer -= uiDiff;

                // Summon Shambling Horror
                if (m_uiHorrorTimer <= uiDiff)
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_HORROR) == CAST_OK)
                        m_uiHorrorTimer = 60000;
                }
                else
                    m_uiHorrorTimer -= uiDiff;

                // Shadow Trap (heroic)
                if (m_bIsHeroic)
                {
                    if (m_uiShadowTrapTimer <= uiDiff)
                    {
                        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, SPELL_SHADOW_TRAP, SELECT_FLAG_PLAYER))
                        {
                            if (DoCastSpellIfCan(pTarget, SPELL_SHADOW_TRAP) == CAST_OK)
                                m_uiShadowTrapTimer = 15000;
                        }
                    }
                    else
                        m_uiShadowTrapTimer -= uiDiff;
                }

                DoMeleeAttackIfReady();
                break;
            }
            case PHASE_RUNNING_WINTER_ONE:
            case PHASE_RUNNING_WINTER_TWO:
            {
                // wait for waypoint arrival
                break;
            }
            case PHASE_WINTER_ONE:
            case PHASE_WINTER_TWO:
            {
                if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
                    return;

                // phase end timer
                if (m_uiPhaseTimer <= uiDiff)
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_QUAKE) == CAST_OK)
                    {
                        DoScriptText(SAY_SHATTER_ARENA, m_creature);
                        m_uiPhase = (m_uiPhase == PHASE_WINTER_ONE ? PHASE_QUAKE_ONE : PHASE_QUAKE_TWO);
                        m_uiPhaseTimer = 6500;
                    }
                }
                else
                    m_uiPhaseTimer -= uiDiff;

                // destroy pillars
                UpdateDestroyPillars(uiDiff);

                // respawning platform
                if (m_bPlatformDestroyed)
                {
                    if (m_uiRespawnPlatformTimer <= uiDiff)
                    {
                        DoRespawnPlatform();
                    }
                    else
                        m_uiRespawnPlatformTimer -= uiDiff;
                }

                // Pain and Suffering
                if (m_uiPainSufferingTimer <= uiDiff)
                {
                    if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_PAIN_AND_SUFFERING, SELECT_FLAG_PLAYER))
                    {
                        if (DoCastSpellIfCan(pTarget, SPELL_PAIN_AND_SUFFERING, CAST_TRIGGERED) == CAST_OK)
                            m_uiPainSufferingTimer = urand(1500, 3000);
                    }
                }
                else
                    m_uiPainSufferingTimer -= uiDiff;

                // Summon Ice Sphere
                if (m_uiIceSphereTimer <= uiDiff)
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_ICE_SPHERE) == CAST_OK)
                        m_uiIceSphereTimer = 6000;
                }
                else
                    m_uiIceSphereTimer -= uiDiff;

                // Summon Raging Spirit
                if (m_uiRagingSpiritTimer <= uiDiff)
                {
                    if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_RAGING_SPIRIT, SELECT_FLAG_PLAYER))
                    {
                        // some targeting issues with script effect spell
                        // but we dont need it in sd2 ;)
                        // if (DoCastSpellIfCan(m_creature, SPELL_RAGING_SPIRIT, CAST_TRIGGERED) == CAST_OK)

                        pTarget->CastSpell(pTarget, SPELL_SUMMON_RAGING_SPIRIT, true);
                        m_uiRagingSpiritTimer = (m_uiPhase == PHASE_WINTER_ONE ? 20000 : 15000);
                    }
                }
                else
                    m_uiRagingSpiritTimer -= uiDiff;

                break;
            }
            case PHASE_QUAKE_ONE:
            case PHASE_QUAKE_TWO:
            {
                // Casting Quake spell - phase end timer
                if (m_uiPhaseTimer <= uiDiff)
                {
                    DoDestroyPlatform();
                    m_uiPhase = (m_uiPhase == PHASE_QUAKE_ONE ? PHASE_TWO : PHASE_THREE);
                    m_creature->GetMotionMaster()->Clear();
                    SetCombatMovement(true, true);
                    return;
                }
                else
                    m_uiPhaseTimer -= uiDiff;

                break;
            }
            case PHASE_TWO:
            {
                // check HP
                if (m_creature->GetHealthPercent() <= 40.0f)
                {
                    // phase transition
                    SetCombatMovement(false, true);
                    m_creature->GetMotionMaster()->MovePoint(POINT_CENTER_LAND_LICH_KING, SpawnLoc[1].x, SpawnLoc[1].y, SpawnLoc[1].z);
                    m_uiPhaseTimer = 60000;
                    m_uiPhase = PHASE_RUNNING_WINTER_TWO;
                }

                // Infest
                UpdateInfest(uiDiff);

                // Soul Reaper
                UpdateSoulReaper(uiDiff);

                // Defile
                UpdateDefile(uiDiff);

                // Summon Val'kyr
                if (m_uiValkyrTimer <= uiDiff)
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_VALKYR) == CAST_OK)
                    {
                        DoScriptText(SAY_SUMMON_VALKYR, m_creature);
                        m_uiValkyrTimer = 50000;
                    }
                }
                else
                    m_uiValkyrTimer -= uiDiff;

                DoMeleeAttackIfReady();
                break;
            }
            case PHASE_THREE:
            {
                // check HP
                if (m_creature->GetHealthPercent() <= 10.0f)
                {
                    m_uiPhase = PHASE_DEATH_AWAITS;

                    // tell Tirion to continue the event
                    if (m_pInstance)
                    {
                        if (Creature* pTirion = m_pInstance->GetSingleCreatureFromStorage(NPC_TIRION))
                        {
                            if (boss_tirion_iccAI* pTirionAI = dynamic_cast<boss_tirion_iccAI*>(pTirion->AI()))
                                pTirionAI->DoNextEventStep();
                        }
                    }

                    return;
                }

                // Soul Reaper
                UpdateSoulReaper(uiDiff);

                // Defile
                UpdateDefile(uiDiff);

                // Harvest Soul
                if (m_uiHarvestSoulTimer <= uiDiff)
                {
                    Unit* pTarget = NULL;
                    if (m_bIsHeroic)
                        pTarget = m_creature;
                    else
                        pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, SPELL_HARVEST_SOUL, SELECT_FLAG_PLAYER);

                    if (pTarget)
                    {
                        if (DoCastSpellIfCan(pTarget, m_bIsHeroic ? SPELL_HARVEST_SOULS : SPELL_HARVEST_SOUL) == CAST_OK)
                        {
                            DoScriptText(SAY_HARVEST_SOUL, m_creature);
                            m_uiHarvestSoulTimer = m_bIsHeroic ? 120000 : 70000;
                            DoPrepareFrostmourneRoom();

                            if (m_bIsHeroic)
                            {
                                m_uiPhase = PHASE_IN_FROSTMOURNE;
                                SetCombatMovement(false, true);
                                m_uiFrostmournePhaseTimer = 47000;
                                m_uiDefileTimer = 1000;
                            }
                        }
                    }
                }
                else
                    m_uiHarvestSoulTimer -= uiDiff;

                // Vile Spirits (start moving after 15seconds)
                if (m_uiVileSpiritsTimer <= uiDiff)
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_VILE_SPIRITS) == CAST_OK)
                        m_uiVileSpiritsTimer = 30000;
                }
                else
                    m_uiVileSpiritsTimer -= uiDiff;

                DoMeleeAttackIfReady();
                break;
            }
            case PHASE_IN_FROSTMOURNE:
            {
                // check if players are alive before entering evade mode?
                // wait until they leave Frostmourne
                if (m_uiFrostmournePhaseTimer <= uiDiff)
                {
                    if (m_pInstance)
                    {
                        if (m_pInstance->GetData(TYPE_FROSTMOURNE_ROOM) == IN_PROGRESS)
                        {
                            m_pInstance->SetData(TYPE_FROSTMOURNE_ROOM, DONE);
                            m_uiFrostmournePhaseTimer = 2000; // Wait for teleport all players.
                        }
                        else
                        {
                            m_uiPhase = PHASE_THREE;
                            m_creature->SetInCombatWithZone();
                            SetCombatMovement(true, true);
                        }
                    }
                }
                else
                    m_uiFrostmournePhaseTimer -= uiDiff;

                break;
            }
            case PHASE_DEATH_AWAITS:
            {
                // wait for swift death
                break;
            }
        }
    }
};

CreatureAI* GetAI_boss_the_lich_king_icc(Creature* pCreature)
{
    return new boss_the_lich_king_iccAI(pCreature);
}

/**
 * Drudge Ghoul
 */
struct MANGOS_DLL_DECL mob_drudge_ghoulAI : public base_icc_bossAI
{
    mob_drudge_ghoulAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiReadyTimer;
    bool m_bIsReady;
    bool m_bIsSpawned;

    void Reset() override
    {
        m_bIsReady          = false;
        m_bIsSpawned        = false;
        m_uiReadyTimer      = 5000;
        m_creature->SetVisibility(VISIBILITY_OFF);
    }

    void AttackStart(Unit* pWho) override
    {
        if (!m_bIsReady)
            return;
        else
            base_icc_bossAI::AttackStart(pWho);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        m_creature->ForcedDespawn(5000);
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_bIsReady)
        {
            if (!m_bIsSpawned)
            {
                m_creature->SetVisibility(VISIBILITY_ON);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                m_bIsSpawned = true;
            }

            if (m_uiReadyTimer <= uiDiff)
            {
                m_bIsReady = true;
                m_creature->SetInCombatWithZone();
            }
            else
                m_uiReadyTimer -= uiDiff;

            return;
        }

        if (!m_pInstance || m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_drudge_ghoul(Creature* pCreature)
{
    return new mob_drudge_ghoulAI(pCreature);
}

/**
 * Shambling Horror
 */
struct MANGOS_DLL_DECL mob_shambling_horrorAI : public base_icc_bossAI
{
    mob_shambling_horrorAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiShockwaveTimer;
    uint32 m_uiEnrageTimer;
    uint32 m_uiReadyTimer;
    bool m_bHasCastFrenzy;
    bool m_bIsReady;
    bool m_bIsSpawned;

    void Reset() override
    {
        m_bIsReady          = false;
        m_bIsSpawned        = false;
        m_uiReadyTimer      = 5000;

        m_uiShockwaveTimer  = 12000;
        m_uiEnrageTimer     = 6000;
        m_bHasCastFrenzy    = false;
        m_creature->SetVisibility(VISIBILITY_OFF);
    }

    void AttackStart(Unit* pWho) override
    {
        if (!m_bIsReady)
            return;
        else
            base_icc_bossAI::AttackStart(pWho);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        m_creature->ForcedDespawn(5000);
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_bIsReady)
        {
            if (!m_bIsSpawned)
            {
                m_creature->SetVisibility(VISIBILITY_ON);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                m_bIsSpawned = true;
            }

            if (m_uiReadyTimer <= uiDiff)
            {
                m_bIsReady = true;
                m_creature->SetInCombatWithZone();
            }
            else
                m_uiReadyTimer -= uiDiff;

            return;
        }

        if (!m_pInstance || m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        // Frenzy on heroic
        if (m_bIsHeroic)
        {
            if (!m_bHasCastFrenzy)
            {
                if (m_creature->GetHealthPercent() <= 20.0f)
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
                        m_bHasCastFrenzy = true;
                }
            }
        }

        // Enrage
        if (m_uiEnrageTimer <= uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_ENRAGE) == CAST_OK)
            {
                m_uiEnrageTimer = 20000;
                m_uiShockwaveTimer = urand(5000, 7000);
            }
        }
        else
            m_uiEnrageTimer -= uiDiff;

        // Shockwave
        if (m_uiShockwaveTimer <= uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_SHOCKWAVE) == CAST_OK)
                m_uiShockwaveTimer = 20000;
        }
        else
            m_uiShockwaveTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_shambling_horror(Creature* pCreature)
{
    return new mob_shambling_horrorAI(pCreature);
}

/**
 * Shadow Trap
 */
struct MANGOS_DLL_DECL mob_shadow_trapAI : public base_icc_bossAI
{
    mob_shadow_trapAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        SetCombatMovement(false);
        DoCastSpellIfCan(m_creature, SPELL_SHADOW_TRAP_VISUAL, CAST_TRIGGERED);
        m_uiShadowTrapTimer = 5000;
    }

    uint32 m_uiShadowTrapTimer;

    void Reset() override {}

    void DamageTaken(Unit* /*pDealer*/, uint32& uiDamage) override
    {
        uiDamage = 0;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        // Shadow Trap
        if (m_uiShadowTrapTimer)
        {
            if (m_uiShadowTrapTimer <= uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_SHADOW_TRAP_AURA) == CAST_OK)
                {
                    m_creature->RemoveAurasDueToSpell(SPELL_SHADOW_TRAP_VISUAL);
                    m_uiShadowTrapTimer = 0;
                }
            }
            else
                m_uiShadowTrapTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_mob_shadow_trap(Creature* pCreature)
{
    return new mob_shadow_trapAI(pCreature);
}

/**
 * Ice Sphere
 */
struct MANGOS_DLL_DECL mob_ice_sphere_iccAI : public base_icc_bossAI
{
    mob_ice_sphere_iccAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        m_creature->SetWalk(true);
        m_creature->SetSpeedRate(MOVE_WALK, 1.1f);
    }

    void Reset() override {}

    void JustDied(Unit* /*pKiller*/) override
    {
        m_creature->ForcedDespawn();
    }

    void UpdateAI(const uint32 /*uiDiff*/) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            m_creature->ForcedDespawn();
    }
};

CreatureAI* GetAI_mob_ice_sphere_icc(Creature* pCreature)
{
    return new mob_ice_sphere_iccAI(pCreature);
}

/**
 * Raging Spirit
 */
struct MANGOS_DLL_DECL mob_raging_spiritAI : public base_icc_bossAI
{
    mob_raging_spiritAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiSoulShriekTimer;
    bool m_bHasCloned;

    void Reset() override
    {
        m_uiSoulShriekTimer = 8000;
        m_bHasCloned = false;
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        m_creature->ForcedDespawn(5000);
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (!m_bHasCloned)
        {
            if (Unit* pCreator = m_creature->GetCreator())
            {
                pCreator->CastSpell(m_creature, SPELL_RAGING_SPIRIT_VISUAL, true);
                m_bHasCloned = true;
            }
        }

        // Soul Shriek
        if (m_uiSoulShriekTimer <= uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_SOUL_SHRIEK) == CAST_OK)
                m_uiSoulShriekTimer = 10000;
        }
        else
            m_uiSoulShriekTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_raging_spirit(Creature* pCreature)
{
    return new mob_raging_spiritAI(pCreature);
}

/**
 * Val'kyr Shadowguard
 */
struct MANGOS_DLL_DECL mob_valkyr_shadowguardAI : public base_icc_bossAI
{
    mob_valkyr_shadowguardAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        Reset();
        m_creature->SetLevitate(true);
        m_creature->SetByteValue(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        m_creature->NearTeleportTo(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ() + 15.0f, 0.0f);
    }

    uint32 m_uiCatchTimer;
    uint32 m_uiLifeSiphonTimer;
    bool m_bIsFree;
    bool m_bIsCastingLifeSiphon;

    ObjectGuid m_TargetGUID;

    void Reset() override
    {
        m_bIsFree              = true;
        m_bIsCastingLifeSiphon = false;
        m_uiCatchTimer         = 2000;
        m_uiLifeSiphonTimer    = 2000;
        m_TargetGUID           = ObjectGuid();

        SetCombatMovement(false);
        DoCastSpellIfCan(m_creature, SPELL_WINGS_OF_THE_DAMNED, CAST_TRIGGERED);
    }

    void AttackStart(Unit* pWho) override
    {
        if (m_bIsCastingLifeSiphon)
            base_icc_bossAI::AttackStart(pWho);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        m_creature->ForcedDespawn(5000);
    }

    bool DoCatchTarget()
    {
        m_TargetGUID = ObjectGuid();
        if (m_pInstance)
        {
            if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
            {
                // search for proper target
                std::list<ObjectGuid> lPotentialTargets;
                ThreatList const& lThreatList = pLichKing->getThreatManager().getThreatList();

                if (!lThreatList.empty())
                {
                    for (ThreatList::const_iterator i = lThreatList.begin(); i != lThreatList.end(); ++i)
                    {
                        if (Unit* pTmp = m_pInstance->instance->GetUnit((*i)->getUnitGuid()))
                        {
                            if (pTmp != pLichKing->getVictim() &&
                                pTmp->GetTypeId() == TYPEID_PLAYER &&
                                !pTmp->GetVehicle() &&
                                pTmp->GetDistance2d(SpawnLoc[1].x, SpawnLoc[1].y) < 52.0f &&
                                pTmp->GetPositionZ() > SpawnLoc[1].z - 2.0f)
                            {
                                lPotentialTargets.push_back(pTmp->GetObjectGuid());
                            }
                        }
                    }
                }

                // select random target
                if (!lPotentialTargets.empty())
                {
                    std::list<ObjectGuid>::iterator i = lPotentialTargets.begin();
                    std::advance(i, urand(0, lPotentialTargets.size() - 1));

                    m_TargetGUID = (*i);
                    if (m_TargetGUID != ObjectGuid())
                        return true;
                }
            }
        }

        return false;
    }

    void DoFlyAway(Unit* pTarget)
    {
        float curX, curY, curZ;
        float destX, destY;
        pTarget->GetPosition(curX, curY, curZ);

        // don't fly into Frozen Throne
        if (curX < 480.0f)
        {
            if (curY > -2124.0f)
                m_creature->GetMotionMaster()->MovePoint(POINT_VALKYR_THROW, SpawnLoc[2].x, SpawnLoc[2].y, SpawnLoc[2].z + 3.0f, false);
            else
                m_creature->GetMotionMaster()->MovePoint(POINT_VALKYR_THROW, SpawnLoc[3].x, SpawnLoc[3].y, SpawnLoc[3].z + 3.0f, false);

            return;
        }

        // angle to center
        float angle = pTarget->GetAngle(SpawnLoc[1].x, SpawnLoc[1].y);
        // angle away from center
        angle += M_PI_F;
        if (angle > 2 * M_PI_F)
            angle -= (2 * M_PI_F);

        // don't fly into Frozen Throne
        if (angle < 3.8f && angle > 2.3f)
        {
            if (angle > 3.05f)
                angle = 3.8f;
            else
                angle = 2.3f;
        }

        float fDistToCenter = pTarget->GetDistance2d(SpawnLoc[1].x, SpawnLoc[1].y);
        float fDist = 60.0f - fDistToCenter;

        pTarget->GetNearPoint2D(destX, destY, fDist, angle);
        m_creature->GetMotionMaster()->MovePoint(POINT_VALKYR_THROW, destX, destY, SpawnLoc[1].z + 3.0f, false);
    }

    void DoThrowAndGoBack()
    {
        DoCastSpellIfCan(m_creature, SPELL_EJECT_PASSENGERS, CAST_TRIGGERED);
        m_creature->GetMotionMaster()->Clear();
        m_creature->GetMotionMaster()->MovePoint(POINT_VALKYR_CENTER, SpawnLoc[1].x + frand(-3.0f, 3.0f), SpawnLoc[1].y + frand(-3.0f, 3.0f), SpawnLoc[1].z + 12.0f, false);
    }

    void MovementInform(uint32 uiMovementType, uint32 uiData) override
    {
        if (uiMovementType == EFFECT_MOTION_TYPE)
        {
            if (!m_pInstance)
                return;
            Unit* pTarget = m_pInstance->instance->GetUnit(m_TargetGUID);
            if (pTarget &&
                pTarget->isAlive() &&
                !pTarget->GetVehicle() &&
                pTarget->GetDistance2d(SpawnLoc[1].x, SpawnLoc[1].y) < 52.0f &&
                pTarget->GetPositionZ() > SpawnLoc[1].z - 2.0f)
            {
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                pTarget->CastSpell(m_creature, SPELL_HARVEST_SOUL_VEHICLE, true);
                DoFlyAway(pTarget);
                return;
            }
            // try again fast!
            m_bIsFree      = true;
            m_uiCatchTimer = 0;
            DoThrowAndGoBack();
            return;
        }

        if (uiMovementType != POINT_MOTION_TYPE)
            return;

        switch (uiData)
        {
            case POINT_VALKYR_THROW:
            {
                DoThrowAndGoBack();
                break;
            }
            case POINT_VALKYR_CENTER:
            {
                m_bIsFree = true;
                break;
            }
        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        // on heroic start casting Life Siphon at 50% HP
        if (!m_bIsCastingLifeSiphon && m_bIsHeroic && m_creature->GetHealthPercent() <= 50.0f)
        {
            m_bIsCastingLifeSiphon = true;
            m_creature->SetInCombatWithZone();
            DoThrowAndGoBack();
        }

        if (!m_bIsFree)
            return;

        if (m_pInstance && m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        if (!m_bIsCastingLifeSiphon)
        {
            if (m_uiCatchTimer <= uiDiff)
            {
                if (m_pInstance && DoCatchTarget())
                {
                    Unit* pTarget = m_pInstance->instance->GetUnit(m_TargetGUID);
                    if (pTarget)
                    {
                        m_creature->GetMotionMaster()->Clear();
                        if (DoCastSpellIfCan(pTarget, SPELL_VALKYR_CHARGE, CAST_TRIGGERED) == CAST_OK)
                            m_bIsFree = false;
                    }
                }
                m_uiCatchTimer = urand(1000, 3000);
            }
            else
                m_uiCatchTimer -= uiDiff;

            return;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        // Life Siphon
        if (m_uiLifeSiphonTimer <= uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_LIFE_SIPHON) == CAST_OK)
                m_uiLifeSiphonTimer = 5000;
        }
        else
            m_uiLifeSiphonTimer -= uiDiff;
    }
};

CreatureAI* GetAI_mob_valkyr_shadowguard(Creature* pCreature)
{
    return new mob_valkyr_shadowguardAI(pCreature);
}

/**
 * Defile
 */
struct MANGOS_DLL_DECL mob_defiler_iccAI : public base_icc_bossAI
{
    mob_defiler_iccAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        SetCombatMovement(false);
        DoCastSpellIfCan(m_creature, SPELL_DEFILE_AURA, CAST_TRIGGERED);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED); // don't turn around
        // "lasts 30 seconds"
        m_creature->ForcedDespawn(30000);
    }

    void Reset() override {}
    void AttackStart(Unit* /*pWho*/) override {}
    void UpdateAI(const uint32 /*uiDiff*/) override {}
};

CreatureAI* GetAI_mob_defiler_icc(Creature* pCreature)
{
    return new mob_defiler_iccAI(pCreature);
}

/**
 * Vile Spirit
 */
struct MANGOS_DLL_DECL  mob_vile_spiritAI : public base_icc_bossAI
{
    mob_vile_spiritAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        SetCombatMovement(false);
        m_creature->SetLevitate(true);
        m_creature->SetByteValue(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        m_creature->SetInCombatWithZone();
        m_creature->GetMotionMaster()->Clear();
        m_creature->NearTeleportTo(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ() + 15.0f, 0.0f);
        m_creature->GetMotionMaster()->MovePoint(1, m_creature->GetPositionX() + frand(-3.0f, 3.0f), m_creature->GetPositionY() + frand(-3.0f, 3.0f), m_creature->GetPositionZ(), false);
        DoCastSpellIfCan(m_creature, SPELL_SPIRIT_BURST_AURA, CAST_TRIGGERED);

        m_bIsWickedSpirit = m_creature->GetEntry() == NPC_WICKED_SPIRIT;

        if (m_bIsWickedSpirit)
            m_creature->ForcedDespawn(41000);

        Reset();
    }

    bool m_bIsReady;
    bool m_bIsWickedSpirit;
    uint32 m_uiReadyTimer;
    uint32 m_uiSummonSpiritBombTimer;

    void Reset() override
    {
        m_bIsReady = false;
        m_uiReadyTimer = m_bIsWickedSpirit ? urand(7000, 15000) : 15000;
        m_uiSummonSpiritBombTimer = urand(1000, 10000);
    }

    void MovementInform(uint32 uiMovementType, uint32 uiData) override
    {
        if (uiMovementType != POINT_MOTION_TYPE)
            return;

        if (m_bIsReady)
            return;

        if (uiData == 1)
            m_creature->GetMotionMaster()->MovePoint(1, m_creature->GetPositionX() + frand(-3.0f, 3.0f), m_creature->GetPositionY() + frand(-3.0f, 3.0f), m_creature->GetPositionZ(), false);
    }

    Unit* SelectTarget()
    {
        if (m_pInstance)
        {
            if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
            {
                // search for proper target
                std::list<ObjectGuid> lPotentialTargets;
                ThreatList const& lThreatList = pLichKing->getThreatManager().getThreatList();

                if (!lThreatList.empty())
                {
                    for (ThreatList::const_iterator i = lThreatList.begin(); i != lThreatList.end(); ++i)
                    {
                        if (Unit* pTmp = m_pInstance->instance->GetUnit((*i)->getUnitGuid()))
                        {
                            if (pTmp != pLichKing->getVictim() &&
                                pTmp->GetTypeId() == TYPEID_PLAYER &&
                                !pTmp->GetVehicle())
                            {
                                lPotentialTargets.push_back(pTmp->GetObjectGuid());
                            }
                        }
                    }
                }

                // select random target
                if (!lPotentialTargets.empty())
                {
                    std::list<ObjectGuid>::iterator i = lPotentialTargets.begin();
                    std::advance(i, urand(0, lPotentialTargets.size() - 1));

                    if (Unit* pTarget = m_pInstance->instance->GetUnit(*i))
                        return pTarget;
                }
            }
        }

        return NULL;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
        {
            m_creature->ForcedDespawn();
            return;
        }

        if (m_bIsWickedSpirit)
        {
            // Summon Spirit Bomb
            if (m_uiSummonSpiritBombTimer <= uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_SUMMON_SPIRIT_BOMB, CAST_TRIGGERED) == CAST_OK)
                    m_uiSummonSpiritBombTimer = 3000;
            }
            else
                m_uiSummonSpiritBombTimer -= uiDiff;
        }

        // start chasing timer
        if (!m_bIsReady)
        {
            if (m_uiReadyTimer <= uiDiff)
            {
                Unit* pTarget = NULL;

                m_creature->SetInCombatWithZone();

                if (m_bIsWickedSpirit)
                    pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_SPIRIT_BURST_AURA, SELECT_FLAG_PLAYER);
                else
                    pTarget = SelectTarget();

                if (pTarget)
                {
                    DoResetThreat();
                    m_creature->AddThreat(pTarget, 100000.0f);
                    m_bIsReady = true;
                    m_creature->StopMoving();
                    m_creature->GetMotionMaster()->Clear();
                    SetCombatMovement(true);

                    if (m_bIsWickedSpirit)
                        m_creature->SetWalk(true);

                    AttackStart(pTarget);
                }
            }
            else
                m_uiReadyTimer -= uiDiff;

        }
    }
};

CreatureAI* GetAI_mob_vile_spirit(Creature* pCreature)
{
    return new mob_vile_spiritAI(pCreature);
}


struct MANGOS_DLL_DECL mob_strangulate_vehicleAI : public base_icc_bossAI
{
    mob_strangulate_vehicleAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        SetCombatMovement(false);
        m_creature->SetWalk(true);
        m_bIsSetUp = false;
        m_bHasMoved = false;
        m_bHasTeleported = false;
        m_uiMoveTimer = 2000;
        m_uiTeleportTimer = 6000;
    }

    bool m_bIsSetUp;
    bool m_bHasMoved;
    bool m_bHasTeleported;
    uint32 m_uiMoveTimer;
    uint32 m_uiTeleportTimer;

    void Reset() override {}
    void AttackStart(Unit* /*pWho*/) override{}

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            m_creature->ForcedDespawn();
        else
        {
            if (m_pInstance->GetData(TYPE_FROSTMOURNE_ROOM) != IN_PROGRESS)
            {
                if (Unit* pCreator = m_creature->GetCreator())
                {
                    pCreator->NearTeleportTo(m_creature->GetPosition(), TELE_TO_NOT_LEAVE_COMBAT);
                    if (m_pInstance->GetData(TYPE_FROSTMOURNE_ROOM) != DONE
                        && pCreator->HasAuraOfDifficulty(SPELL_HARVEST_SOUL_TP_FM_N))
                    {
                        pCreator->CastSpell(pCreator, SPELL_HARVESTED_SOUL_1, false);
                    }
                    // remove Harvest Soul aura
                    pCreator->RemoveAurasDueToSpell(SPELL_HARVEST_SOUL_TP_FM_N);
                    pCreator->RemoveAurasDueToSpell(SPELL_HARVEST_SOUL_TP_FM_H);
                    m_creature->ForcedDespawn(1000);
                    return;
                }
            }
        }

        if (!m_bIsSetUp)
        {
            if (Unit* pCreator = m_creature->GetCreator())
            {
                pCreator->CastSpell(m_creature, SPELL_HARVEST_SOUL_VEHICLE, true);
                m_bIsSetUp = true;
            }
        }

        // move timer
        if (!m_bHasMoved)
        {
            if (m_uiMoveTimer <= uiDiff)
            {
                if (m_pInstance)
                {
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                    {
                        float x, y, z;
                        pLichKing->GetNearPoint(m_creature, x, y, z, m_creature->GetObjectBoundingRadius(), 8.0f, pLichKing->GetAngle(m_creature));
                        m_creature->GetMotionMaster()->MovePoint(POINT_TP_TO_FM, x, y, z, false);
                    }
                }
                m_bHasMoved = true;
            }
            else
                m_uiMoveTimer -= uiDiff;
        }

        // teleport timer
        if (!m_bHasTeleported)
        {
            if (m_uiTeleportTimer <= uiDiff)
            {
                if (m_pInstance)
                {
                    if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                        pLichKing->InterruptSpell(CURRENT_CHANNELED_SPELL);
                }

                if (Unit* pCreator = m_creature->GetCreator())
                {
                    // because it causes player to walk afterwards...
                    m_creature->SetWalk(false);

                    DoCastSpellIfCan(m_creature, SPELL_EJECT_PASSENGERS, CAST_TRIGGERED);
                    if (pCreator->isAlive())
                    {
                        pCreator->CastSpell(m_creature, SPELL_HARVEST_SOUL_CLONE, true);
                        pCreator->CastSpell(pCreator, SPELL_FROSTMOURNE_TP_VISUAL, true);
                        pCreator->CastSpell(pCreator, (m_bIsHeroic ? SPELL_HARVEST_SOUL_TP_FM_H : SPELL_HARVEST_SOUL_TP_FM_N), false);
                    }
                    else
                    {
                        m_creature->ForcedDespawn();
                        return;
                    }
                }

                m_bHasTeleported = true;
            }
            else
                m_uiTeleportTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_mob_strangulate_vehicle(Creature* pCreature)
{
    return new mob_strangulate_vehicleAI(pCreature);
}

/**
 * Terenas Menethil in Frostmourne
 */
struct MANGOS_DLL_DECL npc_terenas_fmAI : public base_icc_bossAI
{
    npc_terenas_fmAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        m_uiSayPhase = 0;
        m_uiSayTimer = 6000;
        m_uiSummonWickedSpiritsTimer = 7000;
        m_uiSummonSpiritBombTimer = 7000;
        m_bHasReleasedPlayer = false;
    }

    uint32 m_uiSayTimer;
    uint32 m_uiSayPhase;
    uint32 m_uiSummonWickedSpiritsTimer;
    uint32 m_uiSummonSpiritBombTimer;
    bool m_bHasReleasedPlayer;

    void Reset() override {}

    void Aggro(Unit* /*pWho*/) override
    {
        DoCastSpellIfCan(m_creature, SPELL_LIGHTS_FAVOR, CAST_TRIGGERED);
        m_creature->SetHealthPercent(50.0f);
    }

    void EnterEvadeMode() override
    {
        if (!m_bHasReleasedPlayer)
        {
            m_bHasReleasedPlayer = true;
            DoCastSpellIfCan(m_creature, SPELL_RESTORE_SOUL);
            m_uiSayPhase = 5;
            m_uiSayTimer = 2000;
        }
    }

    void JustDied(Unit* pKiller) override
    {
        if (pKiller->GetEntry() == NPC_SPIRIT_WARDEN)
        {
            pKiller->CastSpell(pKiller, SPELL_DESTROY_SOUL, true);

            if (m_pInstance)
                m_pInstance->SetData(TYPE_FROSTMOURNE_ROOM, FAIL);

            ((Creature*)pKiller)->ForcedDespawn(2000);
        }
    }

    void DoSummonWickedSpirits(uint32 count)
    {
        for (uint32 i = 0; i < count; ++i)
        {
            float x, y, z;
            m_creature->GetPosition(x, y, z);

            z += 15.0f;
            x += frand(-25.0f, 25.0f);
            y += frand(-25.0f, 25.0f);

            m_creature->SummonCreature(NPC_WICKED_SPIRIT, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 41000);
        }
    }

    void DamageTaken(Unit* /*pDealer*/, uint32& uiDamage) override
    {
        if (m_bIsHeroic)
            uiDamage = 0;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (m_uiSayTimer <= uiDiff)
        {
            switch (m_uiSayPhase)
            {
                case 0:
                    if (!m_bIsHeroic)
                    {
                        if (Creature* pSpirit = GetClosestCreatureWithEntry(m_creature, NPC_SPIRIT_WARDEN, 20.0f))
                        {
                            AttackStart(pSpirit);
                            pSpirit->AI()->AttackStart(m_creature);
                            pSpirit->AddThreat(m_creature, 100000.0f);
                        }
                    }
                    else
                    {
                        DoSummonWickedSpirits(15);
                        m_uiSummonWickedSpiritsTimer = 15000;
                        // summon Spirit Bomb every 2 seconds
                        // aura doesnt work?;/
                        // DoCastSpellIfCan(m_creature, SPELL_SUMMON_SPIRIT_BOMBS_2, CAST_TRIGGERED);
                        DoCastSpellIfCan(m_creature, SPELL_RESTORE_SOUL_HEROIC);
                    }
                    ++m_uiSayPhase;
                    m_uiSayTimer = 1000;
                    break;
                case 1:
                    DoScriptText(SAY_FM_TERENAS_AID_1, m_creature);
                    ++m_uiSayPhase;
                    m_uiSayTimer = 8000;
                    break;
                case 2:
                    DoScriptText(SAY_FM_TERENAS_AID_2, m_creature);
                    ++m_uiSayPhase;
                    m_uiSayTimer = 12000;
                    break;
                case 3:
                    DoScriptText(SAY_FM_TERENAS_AID_3, m_creature);
                    ++m_uiSayPhase;
                    break;
                case 4:
                    // fight
                    break;
                case 5:
                    // release soul
                    if (m_pInstance)
                    {
                        m_pInstance->SetData(TYPE_FROSTMOURNE_ROOM, DONE);

                        if (Creature* pLichKing = m_pInstance->GetSingleCreatureFromStorage(NPC_LICH_KING))
                            DoScriptText(SAY_FM_PLAYER_ESCAPE, pLichKing);
                    }
                    m_creature->ForcedDespawn(5000);
                    ++m_uiSayPhase;
                    break;
                default:
                    break;
            }
        }
        else
            m_uiSayTimer -= uiDiff;

        if (!m_pInstance || m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        if (m_bIsHeroic)
        {
            // Summon Wicked Spirits
            if (m_uiSummonWickedSpiritsTimer <= uiDiff)
            {
                DoSummonWickedSpirits(1);
                m_uiSummonWickedSpiritsTimer = 1000;
            }
            else
                m_uiSummonWickedSpiritsTimer -= uiDiff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_terenas_fm(Creature* pCreature)
{
    return new npc_terenas_fmAI(pCreature);
}


/**
 * Spirit Warden
 */
struct MANGOS_DLL_DECL mob_spirit_wardenAI : public base_icc_bossAI
{
    mob_spirit_wardenAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiSoulRipTimer;
    uint32 m_uiHarvestedSoulTimer;

    void Reset() override
    {
        DoCastSpellIfCan(m_creature, SPELL_DARK_HUNGER, CAST_TRIGGERED);
        m_uiSoulRipTimer = 12000;
        m_uiHarvestedSoulTimer = 61000;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (m_pInstance && m_pInstance->GetData(TYPE_LICH_KING) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        // Soul Rip
        if (m_uiSoulRipTimer <= uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_SOUL_RIP) == CAST_OK)
                m_uiSoulRipTimer = 20000;
        }
        else
            m_uiSoulRipTimer -= uiDiff;

        // Harvest Soul 60sec aura wears off
        if (m_uiHarvestedSoulTimer <= uiDiff)
        {
            if (m_pInstance)
                m_pInstance->SetData(TYPE_FROSTMOURNE_ROOM, FAIL);

            m_uiHarvestedSoulTimer = 60000;
        }
        else
            m_uiHarvestedSoulTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_spirit_warden(Creature* pCreature)
{
    return new mob_spirit_wardenAI(pCreature);
}

/**
 * Spirit Bomb
 */
struct MANGOS_DLL_DECL mob_spirit_bombAI : public base_icc_bossAI
{
    mob_spirit_bombAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        SetCombatMovement(false);
        m_creature->SetLevitate(true);
        m_creature->SetInCombatWithZone();

        float x, y, z;
        m_creature->GetPosition(x, y, z);

        m_creature->NearTeleportTo(x, y, z + 20.0f, 0.0f);
        m_creature->GetMotionMaster()->MovePoint(POINT_SPIRIT_BOMB, x, y, z, false);
        DoCastSpellIfCan(m_creature, SPELL_SPIRIT_BOMB_VISUAL, CAST_TRIGGERED);
    }

    void Reset() override {}

    void MovementInform(uint32 uiMovementType, uint32 uiData) override
    {
        if (uiMovementType != POINT_MOTION_TYPE)
            return;

        if (uiData == POINT_SPIRIT_BOMB)
        {
            DoCastSpellIfCan(m_creature, SPELL_EXPLOSION);
            m_creature->ForcedDespawn(1000);
        }
    }

    void UpdateAI(const uint32 /*uiDiff*/) override {}
};

CreatureAI* GetAI_mob_spirit_bomb(Creature* pCreature)
{
    return new mob_spirit_bombAI(pCreature);
}


void AddSC_boss_lich_king_icc()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_the_lich_king_icc";
    pNewScript->GetAI = &GetAI_boss_the_lich_king_icc;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "boss_tirion_icc";
    pNewScript->GetAI = &GetAI_boss_tirion_icc;
    pNewScript->pGossipHello = &GossipHello_boss_tirion_icc;
    pNewScript->pGossipSelect = &GossipSelect_boss_tirion_icc;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_ice_sphere_icc";
    pNewScript->GetAI = &GetAI_mob_ice_sphere_icc;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_shambling_horror";
    pNewScript->GetAI = &GetAI_mob_shambling_horror;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_drudge_ghoul";
    pNewScript->GetAI = &GetAI_mob_drudge_ghoul;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_shadow_trap";
    pNewScript->GetAI = &GetAI_mob_shadow_trap;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_raging_spirit";
    pNewScript->GetAI = &GetAI_mob_raging_spirit;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_valkyr_shadowguard";
    pNewScript->GetAI = &GetAI_mob_valkyr_shadowguard;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_defiler_icc";
    pNewScript->GetAI = &GetAI_mob_defiler_icc;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_vile_spirit";
    pNewScript->GetAI = &GetAI_mob_vile_spirit;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_strangulate_vehicle";
    pNewScript->GetAI = &GetAI_mob_strangulate_vehicle;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_terenas_fm";
    pNewScript->GetAI = &GetAI_npc_terenas_fm;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_spirit_warden";
    pNewScript->GetAI = &GetAI_mob_spirit_warden;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_spirit_bomb";
    pNewScript->GetAI = &GetAI_mob_spirit_bomb;
    pNewScript->RegisterSelf();
}
