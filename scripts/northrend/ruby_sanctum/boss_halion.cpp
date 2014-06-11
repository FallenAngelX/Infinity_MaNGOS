/* Copyright (C) 2013 /dev/rsa for ScriptDev2 <http://www.scriptdev2.com/>
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

/* ScriptData
SDName: boss_halion
SD%Complete: 90%
SDComment: by notagain, corrected by /dev/rsa && ukulutl
SDCategory: Ruby Sanctum
EndScriptData */

#include "precompiled.h"
#include "ruby_sanctum.h"

enum
{
    //All
    SPELL_CLEAVE                                = 74524,
    SPELL_TWILIGHT_PRECISION                    = 78243, // Increases Halion's chance to hit by 5% and decreases all players' chance to dodge by 20%
    SPELL_BERSERK                               = 47008, // Increases the caster's attack and movement speeds by 150% and all damage it deals by 500% for 5 min.  Also grants immunity to Taunt effects.
    SPELL_START_PHASE2                          = 74808, // Phases the caster into the Twilight realm, leaving behind a large rift.
    SPELL_TWILIGHT_ENTER                        = 74807, // Phases the caster into the Twilight realm - phase 32
    SPELL_TWILIGHT_ENTER2                       = 74812, //
    SPELL_SUMMON_TWILIGHT_PORTAL                = 74809, //
    SPELL_TAIL_LASH                             = 74531, // A sweeping tail strike hits all enemies behind the caster, inflicting 3063 to 3937 damage and stunning them for 2 sec.
    SPELL_TWILIGHT_DIVISION                     = 75063, // Phases the caster, allowing him to exist and act simultaneously in both the material and Twilight realms.
    SPELL_TWILIGHT_CUTTER                       = 74768, // Inflicts 13,875 to 16,125 Shadow damage every second to players touched by the shadow beam
    //CORPOREALITY
    SPELL_CORPOREALITY_EVEN                     = 74826, // Deals & receives normal damage
    SPELL_CORPOREALITY_20I                      = 74827, // Damage dealt increased by 10% & Damage taken increased by 15%
    SPELL_CORPOREALITY_40I                      = 74828, // Damage dealt increased by 30% & Damage taken increased by 50%
    SPELL_CORPOREALITY_60I                      = 74829, // Damage dealt increased by 60% & Damage taken increased by 100%
    SPELL_CORPOREALITY_80I                      = 74830, // Damage dealt increased by 100% & Damage taken increased by 200%
    SPELL_CORPOREALITY_100I                     = 74831, // Damage dealt increased by 200% & Damage taken increased by 400%
    SPELL_CORPOREALITY_20D                      = 74832, // Damage dealt reduced by 10% & Damage taken reduced by 15%
    SPELL_CORPOREALITY_40D                      = 74833, // Damage dealt reduced by 30% & Damage taken reduced by 50%
    SPELL_CORPOREALITY_60D                      = 74834, // Damage dealt reduced by 60% & Damage taken reduced by 100%
    SPELL_CORPOREALITY_80D                      = 74835, // Damage dealt reduced by 100% & Damage taken reduced by 200%
    SPELL_CORPOREALITY_100D                     = 74836, // Damage dealt reduced by 200% & Damage taken reduced by 400%
    //METEOR STRIKE
    SPELL_METEOR                                = 74637, // Script Start (summon NPC_METEOR_STRIKE)
    SPELL_METEOR_IMPACT                         = 74641, // IMPACT ZONE FOR METEOR
    SPELL_METEOR_STRIKE                         = 74648, // Inflicts 18,750 to 21,250 Fire damage to enemies within 12 yards of the targeted area. Takes about 5 seconds to land.
    SPELL_METEOR_FLAME                          = 74718, // FLAME FROM METEOR
    //N10
    SPELL_FLAME_BREATH                          = 74525, // Inflicts 17,500 to 22,500 Fire damage to players in front of Halion
    SPELL_DARK_BREATH                           = 74806, // Inflicts 17,500 to 22,500 Shadow damage to players in front of Halion
    SPELL_DUSK_SHROUD                           = 75476, // Inflicts 3,000 Shadow damage every 2 seconds to everyone in the Twilight Realm
    //Combustion
    NPC_COMBUSTION                              = 40001,
    SPELL_MARK_OF_COMBUSTION                    = 74567, // Dummy effect only
    SPELL_FIERY_COMBUSTION                      = 74562, // Inflicts 4,000 Fire damage every 2 seconds for 30 seconds to a random raider. Every time Fiery Combustion does damage, it applies a stackable Mark of Combustion.
    SPELL_COMBUSTION_EXPLODE                    = 74607,
    SPELL_COMBUSTION_AURA                       = 74629,
    //Consumption
    NPC_CONSUMPTION                             = 40135,
    SPELL_MARK_OF_CONSUMPTION                   = 74795, // Dummy effect only
    SPELL_SOUL_CONSUMPTION                      = 74792, // Inflicts 4,000 Shadow damage every 2 seconds for 30 seconds to a random raider. Every time Soul Consumption does damage, it applies a stackable Mark of Consumption.
    SPELL_CONSUMPTION_EXPLODE                   = 74799,
    SPELL_CONSUMPTION_AURA                      = 74803,
    // Living Ember
    SPELL_AWAKEN_FLAMES                         = 75889,
    // Living Inferno
    SPELL_BLAZING_AURA                          = 75885,
    //Summons
    NPC_METEOR_STRIKE                           = 40029, //casts "impact zone" then meteor
    NPC_METEOR_STRIKE_1                         = 40041,
    NPC_METEOR_STRIKE_2                         = 40042,
    NPC_LIVING_INFERNO                          = 40681,
    NPC_LIVING_EMBER                            = 40683,

    FR_RADIUS                                   = 45,

    //SAYS
    SAY_HALION_SPAWN                = -1724024,
    SAY_HALION_AGGRO                = -1724025,
    SAY_HALION_SLAY_1               = -1724026,
    //SAY_HALION_SLAY_2               = -1666103, //17502 Ha Ha Ha!
    SAY_HALION_DEATH                = -1724027,
    SAY_HALION_BERSERK              = -1724028,
    SAY_HALION_FIREBALL             = -1724029,
    SAY_HALION_SPHERES              = -1724030,
    SAY_HALION_PHASE_2              = -1724031,
    SAY_HALION_PHASE_3              = -1724032,
    EMOTE_SPHERES                   = -1724033,
    EMOTE_OUT_OF_TWILIGHT           = -1724034,
    EMOTE_OUT_OF_PHYSICAL           = -1724035,
    EMOTE_INTO_TWILLIGHT            = -1724036,
    EMOTE_INTO_PHYSICAL             = -1724037,
    EMOTE_REGENERATE                = -1724038,
};

static LOCATION SpawnLoc[]=
{
    {3154.99f, 535.637f, 72.8887f},             // 0 - Halion spawn point (center)
    {3116.91f, 547.758f, 72.8887f},             // 1 - Portal 2
    {3183.96f, 525.440f, 72.8887f},             // 2 - Portal 3
};

/*######
## boss_halion_real (Physical version)
######*/
struct MANGOS_DLL_DECL boss_halion_realAI : public ScriptedAI
{
    boss_halion_realAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;
    bool m_bIntro;
    uint8 m_uiNextPoint;
    bool m_bMovementStarted;
    bool m_bEnrage;
    uint32 m_uiStage;
    uint32 m_uiTailLashTimer;
    uint32 m_uiCleaveTimer;
    uint32 m_uiFieryCombustionTimer;
    uint32 m_uiMeteorTimer;
    uint32 m_uiFlameBreathTimer;
    uint32 m_uiEnrageTimer;

    void Reset()
    {
        if(!m_pInstance)
            return;
        m_creature->SetRespawnDelay(7*DAY);

        if (m_creature->isAlive())
        {
            m_pInstance->SetData(TYPE_HALION, NOT_STARTED);
            m_pInstance->SetData(TYPE_HALION_EVENT, FAIL);
        }

        m_uiStage = 0;
        m_uiNextPoint = 0;
        m_uiTailLashTimer = 10000;
        m_uiCleaveTimer = urand(5000, 10000);
        m_uiFieryCombustionTimer = 15000;
        m_uiMeteorTimer = 20000;
        m_uiEnrageTimer = 8*MINUTE*IN_MILLISECONDS;
        m_bIntro = false;
        m_bEnrage = false;
        SetCombatMovement(true);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        if (GameObject* pGoPortal = m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_1))
               pGoPortal->Delete();
        if (GameObject* pGoPortal = m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_2))
               pGoPortal->Delete();
        if (GameObject* pGoPortal = m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_3))
               pGoPortal->Delete();
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (!m_pInstance)
            return;

        if (!pWho || pWho->GetTypeId() != TYPEID_PLAYER)
            return;

        if (!m_bIntro && pWho->IsWithinDistInMap(m_creature, 60.0f))
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
            DoScriptText(SAY_HALION_SPAWN,m_creature);
            m_bIntro = true;
            m_creature->SetActiveObjectState(true);
        }

        if (m_bIntro && !m_creature->isInCombat() && pWho->IsWithinDistInMap(m_creature, 20.0f))
            AttackStart(pWho);

        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void JustReachedHome() override
    {
        if (!m_pInstance)
            return;

        if (m_pInstance->GetData(TYPE_HALION_EVENT) != FAIL)
            return

        ScriptedAI::JustReachedHome();
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_pInstance->SetData(TYPE_HALION, FAIL);

        m_creature->SetActiveObjectState(false);
    }

    void EnterEvadeMode() override
    {

        if (!m_pInstance)
            return;

        if (m_pInstance->GetData(TYPE_HALION_EVENT) != FAIL)
            return;

        ScriptedAI::EnterEvadeMode();

        m_creature->SetActiveObjectState(false);
    }

    void EndBattle()
    {
        // remove all encounter auras
        Map *pMap = m_creature->GetMap();
        if(pMap)
        {
            Map::PlayerList const &players = pMap->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                if(itr->getSource()->HasAura(SPELL_TWILIGHT_ENTER))
                    itr->getSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_ENTER);

                if(itr->getSource()->HasAura(SPELL_MARK_OF_COMBUSTION))
                    itr->getSource()->RemoveAurasDueToSpell(SPELL_MARK_OF_COMBUSTION);

                if(itr->getSource()->HasAura(SPELL_FIERY_COMBUSTION))
                    itr->getSource()->RemoveAurasDueToSpell(SPELL_FIERY_COMBUSTION);

                if(itr->getSource()->HasAura(SPELL_MARK_OF_CONSUMPTION))
                    itr->getSource()->RemoveAurasDueToSpell(SPELL_MARK_OF_CONSUMPTION);

                if(itr->getSource()->HasAura(SPELL_SOUL_CONSUMPTION))
                    itr->getSource()->RemoveAurasDueToSpell(SPELL_SOUL_CONSUMPTION);
            }
        }

        // remove temporary objects and creatures
        if(Creature* pControl = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_CONTROL))
            pControl->ForcedDespawn();

        if(GameObject* pGoPortal = m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_1))
            pGoPortal->Delete();

        if(GameObject* pGoPortal = m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_2))
            pGoPortal->Delete();

        if(GameObject* pGoPortal = m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_3))
            pGoPortal->Delete();
    }

    void JustDied(Unit* pKiller) override
    {
        if (!m_pInstance)
            return;
        
         m_creature->SetActiveObjectState(false);

        if (Creature* pclone = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_TWILIGHT))
        {
            if (!pclone->isAlive())
            {
                m_pInstance->SetData(TYPE_HALION, DONE);
                m_creature->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                m_pInstance->SetData(TYPE_COUNTER, COUNTER_OFF);
                DoScriptText(SAY_HALION_DEATH,m_creature);
                EndBattle();
            }
            else
            {
                m_creature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                pKiller->DealDamage(pclone, pclone->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
            }
        }
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            DoScriptText(SAY_HALION_SLAY_1 - urand(0,1), m_creature, pVictim);
    }

    void Aggro(Unit* pWho)
    {
        if (!m_pInstance)
            return;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->CastSpell(m_creature, SPELL_TWILIGHT_PRECISION, true);
        m_creature->SetInCombatWithZone();
        m_pInstance->SetData(TYPE_HALION, IN_PROGRESS);
        DoScriptText(SAY_HALION_AGGRO,m_creature);
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (!m_pInstance)
            return;

        if (type != POINT_MOTION_TYPE || !m_bMovementStarted)
            return;

        if (id == m_uiNextPoint)
        {
            m_creature->GetMotionMaster()->MovementExpired();
            m_bMovementStarted = false;
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
        }
    }

    void StartMovement(uint32 id)
    {
        m_uiNextPoint = id;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->GetMotionMaster()->Clear();
        m_creature->GetMotionMaster()->MovePoint(id, SpawnLoc[id].x, SpawnLoc[id].y, SpawnLoc[id].z);
        m_bMovementStarted = true;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance)
            return;

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (m_uiEnrageTimer < uiDiff  && !m_bEnrage)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BERSERK) == CAST_OK)
            {
                DoScriptText(SAY_HALION_BERSERK, m_creature);
                m_uiEnrageTimer = 8*MINUTE*IN_MILLISECONDS;
                m_bEnrage = true;
            }
        }
        else m_uiEnrageTimer -= uiDiff;

        switch (m_uiStage)
        {
            case 0: //PHASE 1 PHYSICAL REALM
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                // Tail Lash
                if (m_uiTailLashTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature, SPELL_TAIL_LASH) == CAST_OK)
                        m_uiTailLashTimer = urand(15000, 25000);
                }
                else m_uiTailLashTimer -= uiDiff;

                // Cleave
                if (m_uiCleaveTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_CLEAVE) == CAST_OK)
                        m_uiCleaveTimer = urand(10000, 15000);
                }
                else m_uiCleaveTimer -= uiDiff;

                // Flame Breath
                if (m_uiFlameBreathTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_FLAME_BREATH) == CAST_OK)
                        m_uiFlameBreathTimer = urand(15000, 20000);
                }
                else m_uiFlameBreathTimer -= uiDiff;

                // Fiery Combustion
                if (m_uiFieryCombustionTimer < uiDiff)
                {
                    if (Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                    {
                        if (DoCastSpellIfCan(pTarget, SPELL_FIERY_COMBUSTION) == CAST_OK)
                            m_uiFieryCombustionTimer = 25000;
                    }
                }
                else m_uiFieryCombustionTimer -= uiDiff;

                // Meteor
                if (m_uiMeteorTimer < uiDiff)
                {
                    if (Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
                    {
                        if (DoCastSpellIfCan(pTarget, SPELL_METEOR) == CAST_OK)
                        {
                            m_uiMeteorTimer = 25000;
                            DoScriptText(SAY_HALION_FIREBALL, m_creature);
                        }
                    }
                }
                else m_uiMeteorTimer -= uiDiff;

                if (m_creature->GetHealthPercent() < 75.0f)
                    m_uiStage = 1;

                break;
            case 1: 
                if (m_creature->IsNonMeleeSpellCasted(true))
                    return;

                m_creature->AttackStop();
                m_creature->InterruptNonMeleeSpells(true);
                DoScriptText(SAY_HALION_PHASE_2,m_creature);
                SetCombatMovement(false);
                StartMovement(0);
                m_uiStage = 2;

                {
                    Creature* pControl = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_CONTROL);
                    if (!pControl)
                        pControl = m_creature->SummonCreature(NPC_HALION_CONTROL, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z, 0, TEMPSUMMON_MANUAL_DESPAWN, 0);
                    else if (!pControl->isAlive())
                        pControl->Respawn();

                    pControl->SetActiveObjectState(true);
                    pControl->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    m_creature->SetInCombatWith(pControl);
                    pControl->SetInCombatWith(m_creature);
                }

                break;
            case 2:
                if (m_bMovementStarted)
                    return;

                if (GameObject* pGoPortal = m_creature->SummonGameobject(GO_HALION_PORTAL_1, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z, 0, 0))
                      pGoPortal->SetPhaseMask(31,true);
                if (GameObject* pGoRing = m_pInstance->GetSingleGameObjectFromStorage(GO_FLAME_RING))
                      pGoRing->SetPhaseMask(65535,true);

                m_uiStage = 3;

                break;
            case 3:
                if (m_creature->IsNonMeleeSpellCasted(false))
                    return;

                m_creature->SetActiveObjectState(true);
                m_creature->CastSpell(m_creature, SPELL_START_PHASE2, true);
                m_uiStage = 4;

                break;
            case 4:
                if (!m_creature->IsNonMeleeSpellCasted(false))
                {
                    if (Creature* pControl = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_CONTROL))
                    {
                        m_creature->SetInCombatWith(pControl);
                        pControl->SetInCombatWith(m_creature);
                    }

                    Creature* pTwilight = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_TWILIGHT);
                    if (!pTwilight)
                        pTwilight = m_creature->SummonCreature(NPC_HALION_TWILIGHT, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z, 0, TEMPSUMMON_MANUAL_DESPAWN, 1000);
                    else if (!pTwilight->isAlive())
                        pTwilight->Respawn();

                    pTwilight->SetCreatorGuid(ObjectGuid());
                    m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    m_uiStage = 5;
                }

                break;
            case 5: // HALION awaiting end battle in TWILIGHT REALM
                if (m_pInstance->GetData(TYPE_HALION_EVENT) == IN_PROGRESS)
                {
                    m_pInstance->SetData(TYPE_HALION_EVENT, SPECIAL);
                    m_creature->RemoveAurasDueToSpell(SPELL_START_PHASE2);

                    if (Creature* pControl = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_CONTROL))
                    {
                        m_creature->SetInCombatWith(pControl);
                        pControl->SetInCombatWith(m_creature);
                    }

                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    m_creature->SetHealth(m_creature->GetMaxHealth()/2);
                    m_creature->SetInCombatWithZone();
                    m_uiStage = 6;
                }

                break;
            case 6: // Switch to phase 3
                DoScriptText(SAY_HALION_PHASE_3,m_creature);
                m_uiStage = 7;

                break;
            case 7:
                if (m_creature->IsNonMeleeSpellCasted(false))
                    return;

                if (m_creature->getVictim()->GetTypeId() != TYPEID_PLAYER)
                    return;

                SetCombatMovement(true);
                m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                m_uiStage = 8;

                break;
            case 8: //PHASE 3 BOTH REALMS
                if ((!m_creature->getVictim()->GetObjectGuid().IsPlayer()) && (!m_creature->getVictim()->GetObjectGuid().IsPet()))
                {
                    if (Creature* pClone = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_TWILIGHT))
                    {
                        pClone->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
                else if ((m_creature->getVictim()->GetTypeId() == TYPEID_PLAYER) || (m_creature->getVictim()->GetObjectGuid().IsPet()))
                {
                    if (Creature* pClone = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_TWILIGHT))
                    {
                        pClone->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    }
                }

                // Tail Lash
                if (m_uiTailLashTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature, SPELL_TAIL_LASH) == CAST_OK)
                        m_uiTailLashTimer = urand(15000, 25000);
                }
                else m_uiTailLashTimer -= uiDiff;

                // Cleave
                if (m_uiCleaveTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_CLEAVE) == CAST_OK)
                        m_uiCleaveTimer = urand(10000, 15000);
                }
                else m_uiCleaveTimer -= uiDiff;

                // Flame Breath
                if (m_uiFlameBreathTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_FLAME_BREATH) == CAST_OK)
                        m_uiFlameBreathTimer = urand(15000, 20000);
                }
                else m_uiFlameBreathTimer -= uiDiff;

                // Fiery Combustion
                if (m_uiFieryCombustionTimer < uiDiff)
                {
                    if (Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_FIERY_COMBUSTION, SELECT_FLAG_PLAYER))
                    {
                        if (DoCastSpellIfCan(pTarget, SPELL_FIERY_COMBUSTION) == CAST_OK)
                            m_uiFieryCombustionTimer = 25000;
                    }
                }
                else m_uiFieryCombustionTimer -= uiDiff;

                // Meteor
                if (m_uiMeteorTimer < uiDiff)
                {
                    if (Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
                    {
                       if (DoCastSpellIfCan(pTarget, SPELL_METEOR) == CAST_OK)
                       {
                           m_uiMeteorTimer = 25000;
                           DoScriptText(SAY_HALION_FIREBALL, m_creature);
                        }
                    }
                }
                else m_uiMeteorTimer -= uiDiff;

                break;
            default:
                break;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_halion_real(Creature* pCreature)
{
    return new boss_halion_realAI(pCreature);
}

/*######
## boss_halion_twilight (Twilight version)
######*/

struct MANGOS_DLL_DECL boss_halion_twilightAI : public ScriptedAI
{
    boss_halion_twilightAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;
    uint32 m_uiStage;
    bool m_bIntro;
    bool m_bEnrage;
    uint32 m_uiTailLashTimer;
    uint32 m_uiCleaveTimer;
    uint32 m_uiDarkBreathTimer;
    uint32 m_uiSoulConsumptionTimer;

    void Reset()
    {
        if(!m_pInstance)
            return;

        m_creature->SetRespawnDelay(7*DAY);
        m_uiStage = 0;
        m_uiTailLashTimer = 10000;
        m_uiCleaveTimer = urand(5000, 10000);
        m_uiDarkBreathTimer = 15000;
        m_uiSoulConsumptionTimer = 20000;
        m_bIntro = false;
        m_bEnrage = false;
        m_creature->SetInCombatWithZone();
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);

        if (Creature* pControl = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_CONTROL))
        {
            m_creature->SetInCombatWith(pControl);
            pControl->SetInCombatWith(m_creature);
        }

        Creature* pFocus = m_pInstance->GetSingleCreatureFromStorage(NPC_ORB_ROTATION_FOCUS);
        if (!pFocus)
             pFocus = m_creature->SummonCreature(NPC_ORB_ROTATION_FOCUS, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z, 0, TEMPSUMMON_MANUAL_DESPAWN, 1000);
        else if (!pFocus->isAlive())
             pFocus->Respawn();

        if (Creature* pReal = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_REAL))
            if (pReal->isAlive())
                m_creature->SetHealth(pReal->GetHealth());

        if (!m_creature->HasAura(SPELL_TWILIGHT_ENTER))
             m_creature->CastSpell(m_creature, SPELL_TWILIGHT_ENTER, true);
    }

    void JustReachedHome() override
    {
        if (!m_pInstance)
            return;

        if (m_pInstance->GetData(TYPE_HALION_EVENT) != FAIL || m_uiStage == 0)
            return;

        ScriptedAI::JustReachedHome();
    }

    void EnterEvadeMode() override
    {
        if (!m_pInstance)
            return;

        if (m_pInstance->GetData(TYPE_HALION_EVENT) != FAIL || m_uiStage == 0)
            return;

        ScriptedAI::EnterEvadeMode();
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (!m_pInstance)
            return;

        if (!pWho || pWho->GetTypeId() != TYPEID_PLAYER)
            return;

        if (!m_bIntro && pWho->IsWithinDistInMap(m_creature, 20.0f))
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
            m_bIntro = true;
            AttackStart(pWho);
            m_uiStage = 1;
            m_creature->CastSpell(m_creature, SPELL_TWILIGHT_PRECISION, true);
            if (Creature* pReal = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_REAL))
                if (pReal->isAlive())
                   m_creature->SetHealth(pReal->GetHealth());
        }

        ScriptedAI::MoveInLineOfSight(pWho);
    }

    void EndBattle()
    {
        // remove all encounter auras
        Map *pMap = m_creature->GetMap();
        if(pMap)
        {
            Map::PlayerList const &players = pMap->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                if(itr->getSource()->HasAura(SPELL_TWILIGHT_ENTER))
                    itr->getSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_ENTER);

                if(itr->getSource()->HasAura(SPELL_MARK_OF_COMBUSTION))
                    itr->getSource()->RemoveAurasDueToSpell(SPELL_MARK_OF_COMBUSTION);

                if(itr->getSource()->HasAura(SPELL_FIERY_COMBUSTION))
                    itr->getSource()->RemoveAurasDueToSpell(SPELL_FIERY_COMBUSTION);

                if(itr->getSource()->HasAura(SPELL_MARK_OF_CONSUMPTION))
                    itr->getSource()->RemoveAurasDueToSpell(SPELL_MARK_OF_CONSUMPTION);

                if(itr->getSource()->HasAura(SPELL_SOUL_CONSUMPTION))
                    itr->getSource()->RemoveAurasDueToSpell(SPELL_SOUL_CONSUMPTION);
            }
        }

        // remove temporal objects and creatures
        if(Creature* pControl = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_CONTROL))
            pControl->ForcedDespawn();

        if(GameObject* pGoPortal = m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_1))
            pGoPortal->Delete();

        if(GameObject* pGoPortal = m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_2))
            pGoPortal->Delete();

        if(GameObject* pGoPortal = m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_3))
            pGoPortal->Delete();
    }

    void JustDied(Unit* pKiller) override
    {
        if (!m_pInstance)
            return;

        if (Creature* pReal = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_REAL))
        {
            if (!pReal->isAlive())
            {
                m_pInstance->SetData(TYPE_HALION, DONE);
                pReal->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                m_pInstance->SetData(TYPE_COUNTER, COUNTER_OFF);
                DoScriptText(SAY_HALION_DEATH, m_creature);
                EndBattle();
            }
            else pKiller->DealDamage(pReal, pReal->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
        }

        m_creature->SetVisibility(VISIBILITY_OFF);
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            DoScriptText(SAY_HALION_SLAY_1 - urand(0,1), m_creature, pVictim);
    }

    void Aggro(Unit* pWho)
    {
        if (!m_pInstance)
            return;
    }

    void UpdateAI(const uint32 uiDiff) override
    {

        if (!m_creature->HasAura(SPELL_TWILIGHT_ENTER))
             m_creature->CastSpell(m_creature, SPELL_TWILIGHT_ENTER, true);

        if (!m_pInstance || m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS || m_pInstance->GetData(TYPE_HALION_EVENT) == FAIL)
              m_creature->ForcedDespawn();

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        switch (m_uiStage)
        {
            case 0:
                break;
            case 1:           //SPAWNED - Twilight realm
                if (!m_creature->HasAura(SPELL_DUSK_SHROUD))
                    m_creature->CastSpell(m_creature, SPELL_DUSK_SHROUD, true);

                // Tail Lash
                if (m_uiTailLashTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature, SPELL_TAIL_LASH) == CAST_OK)
                        m_uiTailLashTimer = urand(15000, 25000);
                }
                else m_uiTailLashTimer -= uiDiff;

                // Cleave
                if (m_uiCleaveTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_CLEAVE) == CAST_OK)
                        m_uiCleaveTimer = urand(10000, 15000);
                }
                else m_uiCleaveTimer -= uiDiff;

                // Dark Breath
                if (m_uiDarkBreathTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_DARK_BREATH) == CAST_OK)
                        m_uiDarkBreathTimer = urand(15000, 20000);
                }
                else m_uiDarkBreathTimer -= uiDiff;

                // Soul Consumption
                if (m_uiSoulConsumptionTimer < uiDiff)
                {
                    if (Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_SOUL_CONSUMPTION, SELECT_FLAG_PLAYER))
                    {
                        if (DoCastSpellIfCan(pTarget, SPELL_SOUL_CONSUMPTION) == CAST_OK)
                            m_uiSoulConsumptionTimer = 25000;
                    }
                }
                else m_uiSoulConsumptionTimer -= uiDiff;

                if (m_creature->GetHealthPercent() < 50.0f)
                    m_uiStage = 2;

                break;
            case 2:           //To two realms
                m_pInstance->SetData(TYPE_HALION_EVENT, IN_PROGRESS);
                DoScriptText(SAY_HALION_PHASE_3,m_creature);

                if (GameObject *pGoPortal1 = m_creature->SummonGameobject(GO_HALION_PORTAL_2, SpawnLoc[1].x, SpawnLoc[1].y, SpawnLoc[1].z, 0, 0))
                    pGoPortal1->SetPhaseMask(32,true);

                if (GameObject *pGoPortal2 = m_creature->SummonGameobject(GO_HALION_PORTAL_3, SpawnLoc[2].x, SpawnLoc[2].y, SpawnLoc[2].z, 0, 0))
                    pGoPortal2->SetPhaseMask(32,true);

                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                m_uiStage = 3;

                break;
            case 3: //PHASE 3 BOTH REALMS
                if ((!m_creature->getVictim()->GetObjectGuid().IsPlayer()) && (!m_creature->getVictim()->GetObjectGuid().IsPet()))
                {
                    if (Creature* pReal = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_REAL))
                    {
                        pReal->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
                else if ((m_creature->getVictim()->GetObjectGuid().IsPlayer()) || (m_creature->getVictim()->GetObjectGuid().IsPet()))
                {
                    if (Creature* pReal = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_REAL))
                        pReal->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }

                if (!m_creature->HasAura(SPELL_DUSK_SHROUD))
                    m_creature->CastSpell(m_creature, SPELL_DUSK_SHROUD, true);

                // Tail Lash
                if (m_uiTailLashTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature, SPELL_TAIL_LASH) == CAST_OK)
                        m_uiTailLashTimer = urand(15000, 25000);
                }
                else m_uiTailLashTimer -= uiDiff;

                // Cleave
                if (m_uiCleaveTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_CLEAVE) == CAST_OK)
                        m_uiCleaveTimer = urand(10000, 15000);
                }
                else m_uiCleaveTimer -= uiDiff;

                // Dark Breath
                if (m_uiDarkBreathTimer < uiDiff)
                {
                    if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_DARK_BREATH) == CAST_OK)
                        m_uiDarkBreathTimer = urand(15000, 20000);
                }
                else m_uiDarkBreathTimer -= uiDiff;

                // Soul Consumption
                if (m_uiSoulConsumptionTimer < uiDiff)
                {
                    if (Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_SOUL_CONSUMPTION, SELECT_FLAG_PLAYER))
                    {
                        if (DoCastSpellIfCan(pTarget, SPELL_SOUL_CONSUMPTION) == CAST_OK)
                            m_uiSoulConsumptionTimer = 25000;
                    }
                }
                else m_uiSoulConsumptionTimer -= uiDiff;

                break;
            default:
                break;
        }

        if (Creature* pReal = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_REAL))
        {
            if(pReal->HasAura(SPELL_BERSERK) && !m_bEnrage)
                if (DoCastSpellIfCan(m_creature, SPELL_BERSERK) == CAST_OK)
                    m_bEnrage = true;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_halion_twilight(Creature* pCreature)
{
    return new boss_halion_twilightAI(pCreature);
}

struct MANGOS_DLL_DECL mob_halion_meteorAI : public ScriptedAI
{
    mob_halion_meteorAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_uiMapDifficulty = pCreature->GetMap()->GetDifficulty();
        m_bIsHeroic = m_uiMapDifficulty > RAID_DIFFICULTY_25MAN_NORMAL;
        m_bIs25Man = (m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_NORMAL || m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_HEROIC);
        Reset();
    }

    ScriptedInstance *m_pInstance;
    Difficulty m_uiMapDifficulty;
    bool m_bIsHeroic;
    bool m_bIs25Man;
    float direction, x, y, radius;
    uint32 m_uiWaitTimer;
    bool m_bStrike;

    void Reset()
    {
        DoCastSpellIfCan(m_creature, SPELL_METEOR_IMPACT, CAST_TRIGGERED);
        m_creature->SetRespawnDelay(7*DAY);
        SetCombatMovement(false);

        m_creature->SetInCombatWithZone();
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_uiWaitTimer = 6000;
        m_bStrike = false;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (m_uiWaitTimer < uiDiff && !m_bStrike)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_METEOR_STRIKE) == CAST_OK)
            {
                if (m_bIsHeroic)
                    m_creature->SummonCreature(NPC_LIVING_INFERNO, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(),0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);

                direction = 2.0f*M_PI_F*((float)urand(0,15)/16.0f);
                radius = 0.0f;
                for(uint8 i = 0; i < 10; ++i)
                {
                    radius += 5.0f;
                    m_creature->GetNearPoint2D(x, y, radius, direction);
                    m_creature->SummonCreature(NPC_METEOR_STRIKE_1, x, y, m_creature->GetPositionZ(),0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                    if (m_bIsHeroic && m_bIs25Man && (i%4) == 0)
                        m_creature->SummonCreature(NPC_LIVING_EMBER, x, y, m_creature->GetPositionZ(),0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->GetNearPoint2D(x, y, radius, direction+M_PI_F);
                    m_creature->SummonCreature(NPC_METEOR_STRIKE_1, x, y, m_creature->GetPositionZ(),0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                    if (m_bIsHeroic && m_bIs25Man && (i%4) == 0)
                        m_creature->SummonCreature(NPC_LIVING_EMBER, x, y, m_creature->GetPositionZ(),0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
                }
                direction += M_PI_F/4;
                radius = 0.0f;
                for(uint8 i = 0; i < 10; ++i)
                {
                    radius += 5.0f;
                    m_creature->GetNearPoint2D(x, y, radius, direction);
                    m_creature->SummonCreature(NPC_METEOR_STRIKE_1, x, y, m_creature->GetPositionZ(),0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                    if (m_bIsHeroic && m_bIs25Man && (i%4) == 0)
                        m_creature->SummonCreature(NPC_LIVING_EMBER, x, y, m_creature->GetPositionZ(),0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->GetNearPoint2D(x, y, radius, direction+M_PI_F);
                    m_creature->SummonCreature(NPC_METEOR_STRIKE_1, x, y, m_creature->GetPositionZ(),0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000);
                    if (m_bIsHeroic && m_bIs25Man && (i%4) == 0)
                        m_creature->SummonCreature(NPC_LIVING_EMBER, x, y, m_creature->GetPositionZ(),0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
                }
                m_creature->ForcedDespawn(10000);
                m_bStrike = true;
                m_uiWaitTimer = 1000;
            }
        }
        else
            m_uiWaitTimer -= uiDiff;
    }
};

CreatureAI* GetAI_mob_halion_meteor(Creature* pCreature)
{
    return new mob_halion_meteorAI(pCreature);
}

struct MANGOS_DLL_DECL mob_halion_flameAI : public ScriptedAI
{
    mob_halion_flameAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance *m_pInstance;

    void Reset()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetDisplayId(11686);
        m_creature->SetRespawnDelay(7*DAY);
        SetCombatMovement(false);
        m_creature->SetInCombatWithZone();
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
              m_creature->ForcedDespawn();

        if (!m_creature->HasAura(SPELL_METEOR_FLAME))
            m_creature->CastSpell(m_creature, SPELL_METEOR_FLAME, true);
    }

};

CreatureAI* GetAI_mob_halion_flame(Creature* pCreature)
{
    return new mob_halion_flameAI(pCreature);
};

struct MANGOS_DLL_DECL mob_living_emberAI : public ScriptedAI
{
    mob_living_emberAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_uiMapDifficulty = pCreature->GetMap()->GetDifficulty();
        m_bIsHeroic = m_uiMapDifficulty > RAID_DIFFICULTY_25MAN_NORMAL;
        m_bIs25Man = (m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_NORMAL || m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_HEROIC);
        Reset();
    }

    ScriptedInstance *m_pInstance;
    Difficulty m_uiMapDifficulty;
    bool m_bIsHeroic;
    bool m_bIs25Man;
    uint32 m_uiWaitTimer;

    void Reset()
    {
        m_uiWaitTimer = 6000;
    }

    void Aggro(Unit *pWho)
    {
        SetCombatMovement(false);
        m_creature->SetInCombatWithZone();
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
              m_creature->ForcedDespawn();

        if (m_uiWaitTimer < uiDiff)
        {
            if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
                m_creature->ForcedDespawn();

            SetCombatMovement(true);
            DoMeleeAttackIfReady();

            m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
        }
        else m_uiWaitTimer -= uiDiff;
    }
};

CreatureAI* GetAI_mob_living_ember(Creature* pCreature)
{
    return new mob_living_emberAI(pCreature);
};

struct MANGOS_DLL_DECL mob_living_infernoAI : public ScriptedAI
{
    mob_living_infernoAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_uiMapDifficulty = pCreature->GetMap()->GetDifficulty();
        m_bIsHeroic = m_uiMapDifficulty > RAID_DIFFICULTY_25MAN_NORMAL;
        m_bIs25Man = (m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_NORMAL || m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_HEROIC);
        Reset();
    }

    ScriptedInstance *m_pInstance;
    Difficulty m_uiMapDifficulty;
    bool m_bIsHeroic;
    bool m_bIs25Man;
    uint32 m_uiWaitTimer;

    void Reset()
    {
        m_uiWaitTimer = 6000;
    }

    void Aggro(Unit *pWho)
    {
        SetCombatMovement(false);
        m_creature->SetInCombatWithZone();
        m_creature->CastSpell(m_creature, SPELL_BLAZING_AURA, true);
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
              m_creature->ForcedDespawn();

        if (m_uiWaitTimer < uiDiff)
        {
            if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
                m_creature->ForcedDespawn();

            if (!m_creature->HasAura(SPELL_BLAZING_AURA))
                m_creature->CastSpell(m_creature, SPELL_BLAZING_AURA, true);

            SetCombatMovement(true);
            DoMeleeAttackIfReady();

            m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
        }
        else m_uiWaitTimer -= uiDiff;
    }
};

CreatureAI* GetAI_mob_living_inferno(Creature* pCreature)
{
    return new mob_living_infernoAI(pCreature);
};

struct HalionBuffLine
{
    float uiDiff;                // Health uiDiff in percent
    uint32 real, twilight;       // Buff pair
    uint8 disp_corp;             // Displayed Corporeality
};

static HalionBuffLine Buff[]=
{
    {-10.0f, SPELL_CORPOREALITY_100D , SPELL_CORPOREALITY_100I , 0   },
    {-8.0f,  SPELL_CORPOREALITY_80D  , SPELL_CORPOREALITY_80I  , 10  },
    {-6.0f,  SPELL_CORPOREALITY_60D  , SPELL_CORPOREALITY_60I  , 20  },
    {-4.0f,  SPELL_CORPOREALITY_40D  , SPELL_CORPOREALITY_40I  , 30  },
    {-2.0f,  SPELL_CORPOREALITY_20D  , SPELL_CORPOREALITY_20I  , 40  },
    {-1.0f,  SPELL_CORPOREALITY_EVEN , SPELL_CORPOREALITY_EVEN , 50  },
    {1.0f,   SPELL_CORPOREALITY_EVEN , SPELL_CORPOREALITY_EVEN , 50  },
    {2.0f,   SPELL_CORPOREALITY_20I  , SPELL_CORPOREALITY_20D  , 60  },
    {4.0f,   SPELL_CORPOREALITY_40I  , SPELL_CORPOREALITY_40D  , 70  },
    {6.0f,   SPELL_CORPOREALITY_60I  , SPELL_CORPOREALITY_60D  , 80  },
    {8.0f,   SPELL_CORPOREALITY_80I  , SPELL_CORPOREALITY_80D  , 90  },
    {10.0f,  SPELL_CORPOREALITY_100I , SPELL_CORPOREALITY_100D , 100 },
};

struct MANGOS_DLL_DECL mob_halion_controlAI : public ScriptedAI
{
    mob_halion_controlAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_uiMapDifficulty = pCreature->GetMap()->GetDifficulty();
        m_bIsHeroic = m_uiMapDifficulty > RAID_DIFFICULTY_25MAN_NORMAL;
        m_bIs25Man = (m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_NORMAL || m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_HEROIC);
        Reset();
    }

    ScriptedInstance* m_pInstance;
    Difficulty m_uiMapDifficulty;
    bool m_bIsHeroic;
    bool m_bIs25Man;

    uint32 m_lastBuffReal, m_lastBuffTwilight;
    uint32 m_corporealityTimer;
    bool wipe;

    bool p_Last;

    float p_RealDamage, p_TwilightDamage;
    float p_LastHP;

    float p_RealCorp, p_TwilightCorp;

    void Reset()
    {
        if (!m_pInstance) 
           return;

        m_creature->SetDisplayId(11686);
        m_creature->SetPhaseMask(65535, true);
        m_creature->SetRespawnDelay(7*DAY);
        SetCombatMovement(false);
        m_lastBuffReal = 0;
        m_lastBuffTwilight = 0;
        m_corporealityTimer = 5000;
        wipe = false;
        m_creature->SetActiveObjectState(true);
        m_pInstance->SetData(TYPE_COUNTER, COUNTER_OFF);
        m_pInstance->SetData(TYPE_HALION_EVENT, NOT_STARTED);

        p_Last = false;
        p_RealDamage = p_TwilightDamage = 0;
        p_RealCorp = p_TwilightCorp = m_bIs25Man ? (m_bIsHeroic ? 29284500 : 20220000) : (m_bIsHeroic ? 7669500 : 5578000);
    }

    void AttackStart(Unit *who)
    {
        //ignore all attackstart commands
        return;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
              m_creature->ForcedDespawn();

        if (!m_pInstance)
            return;

        wipe = true;

        Map *pMap = m_creature->GetMap();
        if(!pMap) return;
        
        Map::PlayerList const &players = pMap->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            if(itr->getSource()->isAlive())
            {
                wipe = false;
                break;
            }
        }

        if (wipe) 
        {
            m_pInstance->SetData(TYPE_HALION_EVENT, FAIL);
            m_pInstance->SetData(TYPE_HALION, FAIL);
            m_creature->ForcedDespawn();
        }

        if(!m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_1))
        {
            if (GameObject* pGoPortal1 = m_creature->SummonGameobject(GO_HALION_PORTAL_1, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z, 0, 0))
                pGoPortal1->SetPhaseMask(31,true);
        }

        if (m_pInstance->GetData(TYPE_HALION_EVENT) != SPECIAL) return;

        if(!m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_2))
        {
            if (GameObject *pGoPortal2 = m_creature->SummonGameobject(GO_HALION_PORTAL_2, SpawnLoc[1].x, SpawnLoc[1].y, SpawnLoc[1].z, 0, 0))
                pGoPortal2->SetPhaseMask(32,true);
        }

        if(!m_pInstance->GetSingleGameObjectFromStorage(GO_HALION_PORTAL_3))
        {
            if (GameObject *pGoPortal3 = m_creature->SummonGameobject(GO_HALION_PORTAL_3, SpawnLoc[2].x, SpawnLoc[2].y, SpawnLoc[2].z, 0, 0))
                pGoPortal3->SetPhaseMask(32,true);
        }

        Creature* pHalionReal = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_REAL);
        Creature* pHalionTwilight = m_pInstance->GetSingleCreatureFromStorage(NPC_HALION_TWILIGHT);

        if (!pHalionTwilight || !pHalionReal)
            return;

        pHalionTwilight->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        // CORPOREALITY
        if (m_corporealityTimer <= uiDiff)
        {
            // calculate damage for corporeality
            float p_RealHP = (pHalionReal && pHalionReal->isAlive()) ? pHalionReal->GetHealth() : 0.0f;
            float p_TwilightHP = (pHalionTwilight && pHalionTwilight->isAlive()) ? pHalionTwilight->GetHealth() : 0.0f;        
          
            if(!p_Last)
            {
                p_LastHP = p_RealHP >= p_TwilightHP ? p_RealHP : p_TwilightHP;
                p_Last = true;
            }

            if(pHalionTwilight->isAlive() && pHalionReal->isAlive())
            {
                p_RealDamage = p_LastHP - p_RealHP;
                p_TwilightDamage = p_LastHP - p_TwilightHP;

                p_LastHP = p_RealHP >= p_TwilightHP ? p_TwilightHP - p_RealDamage : p_RealHP - p_TwilightDamage;
                p_LastHP = p_LastHP > 0 ? p_LastHP : 1;

                pHalionReal->SetHealth(p_LastHP);
                pHalionTwilight->SetHealth(p_LastHP);
            }  

            p_TwilightCorp -= p_TwilightDamage;
            p_RealCorp -= p_RealDamage;

            // calculate corporeality (halion hp %)
            float m_uiDiff = 
                (p_RealCorp     / (m_bIs25Man ? (m_bIsHeroic ? 585690 : 404400) : (m_bIsHeroic ? 153390 : 111560)))
                -
                (p_TwilightCorp / (m_bIs25Man ? (m_bIsHeroic ? 585690 : 404400) : (m_bIsHeroic ? 153390 : 111560)));

            uint8 buffnum = 0;
            if (m_uiDiff <= Buff[0].uiDiff)
            {
                buffnum = 0;
            }
            else
            {
                for (uint8 i = 0; i < 11; i++)
                {
                    if (m_uiDiff >= Buff[i].uiDiff)
                    {
                        buffnum = i+1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
          
            if (!m_lastBuffReal || m_lastBuffReal != Buff[buffnum].real)
            {
                if (m_lastBuffReal)
                {
                    pHalionReal->RemoveAurasDueToSpell(m_lastBuffReal);                          
                }
            
                if(Buff[buffnum].real > m_lastBuffReal) DoScriptText(EMOTE_OUT_OF_TWILIGHT, pHalionTwilight);

                pHalionReal->CastSpell(pHalionReal, Buff[buffnum].real, true);             
                m_lastBuffReal = Buff[buffnum].real;
            }

            if (!m_lastBuffTwilight || m_lastBuffTwilight != Buff[buffnum].twilight)
            {
                if (m_lastBuffTwilight)
                {
                    pHalionTwilight->RemoveAurasDueToSpell(m_lastBuffTwilight);                                 
                }

                if(Buff[buffnum].twilight > m_lastBuffTwilight) DoScriptText(EMOTE_OUT_OF_PHYSICAL, pHalionReal);

                pHalionTwilight->CastSpell(pHalionTwilight, Buff[buffnum].twilight, true);                      
                m_lastBuffTwilight = Buff[buffnum].twilight;
            }

            m_pInstance->SetData(TYPE_COUNTER, (uint32)Buff[buffnum].disp_corp);

            m_corporealityTimer = 5000;
        }
        else  m_corporealityTimer -= uiDiff; 
    }

};

CreatureAI* GetAI_mob_halion_control(Creature* pCreature)
{
    return new mob_halion_controlAI(pCreature);
};

struct MANGOS_DLL_DECL mob_orb_rotation_focusAI : public ScriptedAI
{
    mob_orb_rotation_focusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_bIsHeroic = pCreature->GetMap()->GetDifficulty() > RAID_DIFFICULTY_25MAN_NORMAL;
        Reset();
    }

    ScriptedInstance* m_pInstance;
    bool m_bIsHeroic;

    uint32 m_timer;
    float m_direction, m_nextdirection;
    bool m_warning;

    void Reset()
    {
        m_creature->SetDisplayId(11686);
        m_creature->SetRespawnDelay(7*DAY);
        m_creature->SetPhaseMask(65535, true);
        SetCombatMovement(false);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_direction = 0.0f;
        m_nextdirection = 0.0f;
        m_timer = 30000;
        m_warning = false;

        Creature* pPulsar1 = m_pInstance->GetSingleCreatureFromStorage(NPC_SHADOW_PULSAR_N);
        if (!pPulsar1 )
        {
            float x,y;
            m_creature->GetNearPoint2D(x, y, FR_RADIUS, m_direction);
            pPulsar1 = m_creature->SummonCreature(NPC_SHADOW_PULSAR_N, x, y, m_creature->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN, 5000);
        } 
        else if (!pPulsar1->isAlive()) pPulsar1->Respawn();

        Creature* pPulsar2 = m_pInstance->GetSingleCreatureFromStorage(NPC_SHADOW_PULSAR_S);
        if (!pPulsar2)
        {
            float x,y;
            m_creature->GetNearPoint2D(x, y, FR_RADIUS, m_direction + M_PI_F);
            pPulsar2 = m_creature->SummonCreature(NPC_SHADOW_PULSAR_S, x, y, m_creature->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN, 5000);
        } 
        else if (!pPulsar2->isAlive()) pPulsar2->Respawn();

        if(m_bIsHeroic)
        {/* TODO:
            Creature* pPulsar3 = m_pInstance->GetSingleCreatureFromStorage(NPC_SHADOW_PULSAR_E);
            if (!pPulsar3)
            {
                float x,y;
                m_creature->GetNearPoint2D(x, y, FR_RADIUS, m_direction + M_PI_F);
                pPulsar3 = m_creature->SummonCreature(NPC_SHADOW_PULSAR_E, x, y, m_creature->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN, 5000);
            } 
            else if (!pPulsar3->isAlive()) pPulsar3->Respawn();

            Creature* pPulsar4 = m_pInstance->GetSingleCreatureFromStorage(NPC_SHADOW_PULSAR_W);
            if (!pPulsar4)
            {
                float x,y;
                m_creature->GetNearPoint2D(x, y, FR_RADIUS, m_direction + M_PI_F);
                pPulsar4 = m_creature->SummonCreature(NPC_SHADOW_PULSAR_W, x, y, m_creature->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN, 5000);
            } 
            else if (!pPulsar4->isAlive()) pPulsar4->Respawn();
      */}
    }

    void AttackStart(Unit *who)
    {
        //ignore all attackstart commands
        return;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
              m_creature->ForcedDespawn();

        if (m_pInstance->GetData(DATA_ORB_S) == DONE && m_pInstance->GetData(DATA_ORB_N) == DONE)
        {
            m_direction = m_nextdirection;
            m_nextdirection = (m_direction - M_PI_F/64.0f);

            if (m_nextdirection < 0.0f ) m_nextdirection = m_nextdirection + 2.0f*M_PI_F;

            m_pInstance->SetData(DATA_ORB_DIRECTION, (uint32)(m_nextdirection*1000));
            m_pInstance->SetData(DATA_ORB_N, SPECIAL);
            m_pInstance->SetData(DATA_ORB_S, SPECIAL);
            debug_log("EventMGR: creature %u send direction %u ",m_creature->GetEntry(),m_pInstance->GetData(DATA_ORB_DIRECTION));
        }

        if (m_timer - 6000 <= uiDiff && !m_warning)
        {
            DoScriptText(EMOTE_SPHERES, m_creature);
            m_warning = true;
        }

        if (m_timer <= uiDiff)
        {
            float x,y;
            m_creature->GetNearPoint2D(x, y, FR_RADIUS, m_nextdirection);
            m_creature->SummonCreature(NPC_ORB_CARRIER, x, y, m_creature->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN, 5000);
            m_timer = 30000;
            m_warning = false;

            //cast twilight cutter
            Creature* pPulsar1 = m_pInstance->GetSingleCreatureFromStorage(NPC_SHADOW_PULSAR_N);
            Creature* pPulsar2 = m_pInstance->GetSingleCreatureFromStorage(NPC_SHADOW_PULSAR_S);
            if(pPulsar1 && pPulsar2)
            {
                // uncomment when implemented in core
                //pPulsar1->CastSpell(pPulsar2, SPELL_TWILIGHT_CUTTER, true);
            }
            
            if(m_bIsHeroic)
            {/* TODO:
                Creature* pPulsar3 = m_pInstance->GetSingleCreatureFromStorage(NPC_SHADOW_PULSAR_E);
                Creature* pPulsar4 = m_pInstance->GetSingleCreatureFromStorage(NPC_SHADOW_PULSAR_W);
                if(pPulsar3 && pPulsar4)
                {
                    pPulsar3->CastSpell(pPulsar4, SPELL_TWILIGHT_CUTTER, true);
                }*/
            }
        }   
        else m_timer -= uiDiff;
    }
};

CreatureAI* GetAI_mob_orb_rotation_focus(Creature* pCreature)
{
    return new mob_orb_rotation_focusAI(pCreature);
};

struct MANGOS_DLL_DECL mob_halion_orbAI : public ScriptedAI
{
    mob_halion_orbAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
        Reset();
    }

    ScriptedInstance *m_pInstance;
    float m_direction,m_delta;
    uint32 m_flag;
    uint32 m_flag1;
    bool m_bMovementStarted;
    Creature* focus;
    uint32 m_uiNextPoint;

    void Reset()
    {
        if (!m_pInstance) 
            return;

        m_creature->SetRespawnDelay(7*DAY);
        SetCombatMovement(false);
        m_creature->SetPhaseMask(32, true);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        if (m_creature->GetEntry() == NPC_SHADOW_PULSAR_N)
        {
            m_flag = DATA_ORB_N;
            m_delta = 0.0f;
        } 
        else if (m_creature->GetEntry() == NPC_SHADOW_PULSAR_S)
        {
            m_flag = DATA_ORB_S;
            m_delta = M_PI_F;
        }

        m_direction = 0.0f;
        m_uiNextPoint = 0;
        m_bMovementStarted = false;
        m_pInstance->SetData(m_flag, DONE);
        debug_log("EventMGR: creature %u assume m_flag %u ",m_creature->GetEntry(),m_flag);
    }

    void AttackStart(Unit *who)
    {
        //ignore all attackstart commands
        return;
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (!m_pInstance) return;

        if (type != POINT_MOTION_TYPE || !m_bMovementStarted) return;

        if (id == m_uiNextPoint) 
        {
            m_creature->GetMotionMaster()->MovementExpired();
            m_bMovementStarted = false;
            m_pInstance->SetData(m_flag, DONE);
        }
    }

    void StartMovement(uint32 id)
    {
        if (!m_pInstance) 
            return;

        m_uiNextPoint = id;
        float x,y;
        m_pInstance->SetData(m_flag, IN_PROGRESS);
        m_bMovementStarted = true;
        m_direction = ((float)m_pInstance->GetData(DATA_ORB_DIRECTION)/1000 + m_delta);

        if (m_direction > 2.0f*M_PI_F)
            m_direction = m_direction - 2.0f*M_PI_F;

        focus = m_pInstance->GetSingleCreatureFromStorage(NPC_ORB_ROTATION_FOCUS);
        if (focus)
        {
            focus->GetNearPoint2D(x, y, FR_RADIUS, m_direction);
        }
        else 
        {
            m_creature->ForcedDespawn();
        }

        m_creature->GetMotionMaster()->Clear();
        m_creature->GetMotionMaster()->MovePoint(id, x, y,  m_creature->GetPositionZ());
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
              m_creature->ForcedDespawn();

        if (!m_bMovementStarted && m_pInstance->GetData(m_flag) == SPECIAL)
        {
            StartMovement(1);
        }

    }
};

CreatureAI* GetAI_mob_halion_orb(Creature* pCreature)
{
    return new mob_halion_orbAI(pCreature);
}

struct MANGOS_DLL_DECL mob_orb_carrierAI : public ScriptedAI
{
    mob_orb_carrierAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
        Reset();
    }

    ScriptedInstance* m_pInstance;
    bool m_bMovementStarted;

    void Reset()
    {
        m_creature->SetRespawnDelay(7*DAY);
        SetCombatMovement(false);
        m_creature->SetPhaseMask(32, true);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_bMovementStarted = false;
        m_creature->SetWalk(false);
        m_creature->SetSpeedRate(MOVE_RUN, 6.0f);
    }

    void AttackStart(Unit* pWho) override
    {
        return;
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (!m_pInstance) return;

        if (type != POINT_MOTION_TYPE || !m_bMovementStarted) return;

        if (id == 1) 
        {
            m_creature->GetMotionMaster()->MovementExpired();
            m_bMovementStarted = false;
            m_creature->ForcedDespawn();
        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
              m_creature->ForcedDespawn();

        if (!m_bMovementStarted)
        {
            float x,y;
            float m_direction = ((float)m_pInstance->GetData(DATA_ORB_DIRECTION)/1000.0f + M_PI_F - M_PI_F/32.0f);

            if (m_direction > 2.0f*M_PI_F) m_direction = m_direction - 2.0f*M_PI_F;

            if (Creature* focus = m_pInstance->GetSingleCreatureFromStorage(NPC_ORB_ROTATION_FOCUS))
                focus->GetNearPoint2D(x, y, FR_RADIUS, m_direction);
            else 
                m_creature->ForcedDespawn();

            m_creature->GetMotionMaster()->Clear();
            m_creature->GetMotionMaster()->MovePoint(1, x, y,  m_creature->GetPositionZ());
            m_bMovementStarted = true;
        }

    }

};

CreatureAI* GetAI_mob_orb_carrier(Creature* pCreature)
{
    return new mob_orb_carrierAI(pCreature);
};

struct MANGOS_DLL_DECL mob_soul_consumptionAI : public ScriptedAI
{
    mob_soul_consumptionAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
        m_uiMapDifficulty = pCreature->GetMap()->GetDifficulty();
        m_bIsHeroic = m_uiMapDifficulty > RAID_DIFFICULTY_25MAN_NORMAL;
        m_bIs25Man = (m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_NORMAL || m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_HEROIC);
        Reset();
    }

    ScriptedInstance* m_pInstance;
    bool m_bIsHeroic;
    bool m_bIs25Man;
    Difficulty m_uiMapDifficulty;

    void Reset()
    {
        if (!m_bIsHeroic)
            m_creature->SetPhaseMask(32,true);
        else
            m_creature->SetPhaseMask(65535,true);

        SetCombatMovement(false);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->CastSpell(m_creature, SPELL_CONSUMPTION_AURA, true);
    }

    void AttackStart(Unit* pWho) override
    {
        return;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if(m_pInstance && m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        m_creature->ForcedDespawn(20000);
    }
};

CreatureAI* GetAI_mob_soul_consumption(Creature* pCreature)
{
    return new mob_soul_consumptionAI(pCreature);
};

struct MANGOS_DLL_DECL mob_fiery_combustionAI : public ScriptedAI
{
    mob_fiery_combustionAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
        m_uiMapDifficulty = pCreature->GetMap()->GetDifficulty();
        m_bIsHeroic = m_uiMapDifficulty > RAID_DIFFICULTY_25MAN_NORMAL;
        m_bIs25Man = (m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_NORMAL || m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_HEROIC);
        Reset();
    }

    ScriptedInstance* m_pInstance;
    bool m_bIsHeroic;
    bool m_bIs25Man;
    Difficulty m_uiMapDifficulty;

    void Reset()
    {
        if (!m_bIsHeroic)
            m_creature->SetPhaseMask(31,true);
        else
            m_creature->SetPhaseMask(65535,true);

        SetCombatMovement(false);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->CastSpell(m_creature, SPELL_COMBUSTION_AURA, true);
    }

    void AttackStart(Unit* pWho) override
    {
        return;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if(m_pInstance && m_pInstance->GetData(TYPE_HALION) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        m_creature->ForcedDespawn(20000);
    }

};

CreatureAI* GetAI_mob_fiery_combustion(Creature* pCreature)
{
    return new mob_fiery_combustionAI(pCreature);
};


bool GOHello_go_halion_portal_twilight(Player *player, GameObject* pGo)
{
    ScriptedInstance* m_pInstance = (ScriptedInstance*)pGo->GetInstanceData();

    if(!m_pInstance) return false;

    player->CastSpell(player,SPELL_TWILIGHT_ENTER,false);

    return true;
}

bool GOHello_go_halion_portal_real(Player *player, GameObject* pGo)
{
    ScriptedInstance* m_pInstance = (ScriptedInstance*)pGo->GetInstanceData();

    if(!m_pInstance) return false;

    player->RemoveAurasDueToSpell(SPELL_TWILIGHT_ENTER);

    return true;
}

void AddSC_boss_halion()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_halion_real";
    newscript->GetAI = &GetAI_boss_halion_real;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_halion_twilight";
    newscript->GetAI = &GetAI_boss_halion_twilight;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_halion_meteor";
    newscript->GetAI = &GetAI_mob_halion_meteor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_halion_flame";
    newscript->GetAI = &GetAI_mob_halion_flame;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_living_ember";
    newscript->GetAI = &GetAI_mob_living_ember;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_living_inferno";
    newscript->GetAI = &GetAI_mob_living_inferno;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_halion_orb";
    newscript->GetAI = &GetAI_mob_halion_orb;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_halion_control";
    newscript->GetAI = &GetAI_mob_halion_control;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_orb_rotation_focus";
    newscript->GetAI = &GetAI_mob_orb_rotation_focus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_orb_carrier";
    newscript->GetAI = &GetAI_mob_orb_carrier;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_soul_consumption";
    newscript->GetAI = &GetAI_mob_soul_consumption;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_fiery_combustion";
    newscript->GetAI = &GetAI_mob_fiery_combustion;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_halion_portal_twilight";
    newscript->pGOUse  = &GOHello_go_halion_portal_twilight;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_halion_portal_real";
    newscript->pGOUse  = &GOHello_go_halion_portal_real;
    newscript->RegisterSelf();
}
