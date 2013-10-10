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

/* ScriptData
SDName: boss_professor_putricide
SD%Complete: 95%
SDComment:  by michalpolko with special thanks to:
            mangosR2 team and all who are supporting us with feedback, testing and fixes
            TrinityCore for some info about spells IDs
            everybody whom I forgot to mention here ;)

SDCategory: Icecrown Citadel
EndScriptData */

#include "precompiled.h"
#include "icecrown_citadel.h"
#include "Vehicle.h"

enum BossSpells
{
    SPELL_BERSERK                   = 47008,

    // controlled abomination
    SPELL_MUTATED_TRANSFORMATION    = 70308,
    SPELL_EAT_OOZE                  = 72527,
    SPELL_REGURGITATED_OOZE         = 70539,
    SPELL_MUTATED_SLASH             = 70542,
 // SPELL_MUTATED_AURA              = 70405,
 // SPELL_ABOMINATION_POWER_DRAIN   = 70385, // prevents normal regen of abomination's power

    SPELL_UNSTABLE_EXPERIMENT       = 70351,
    SPELL_VOLATILE_EXPERIMENT       = 72842, // heroic
    SPELL_GREEN_OOZE_SUMMON         = 71412,
    SPELL_ORANGE_OOZE_SUMMON        = 71415,

    SPELL_OOZE_ADHESIVE             = 70447,
    SPELL_OOZE_ERUPTION             = 70492,

    SPELL_GASEOUS_BLOAT             = 70672,
    SPELL_EXPUNGED_GAS              = 70701,
    SPELL_GASEOUS_BLOAT_VISUAL      = 70215,

    SPELL_SLIME_PUDDLE              = 70341,
    SPELL_SLIME_PUDDLE_SUMMON       = 70342,
    SPELL_SLIME_PUDDLE_AURA         = 70343,
 // SPELL_SLIME_PUDDLE_TRIGGER      = 71424, // trigger summon spell from target?
 // SPELL_SLIME_PUDDLE_SUMMON_TRIG  = 71425,
    SPELL_GROW_STACKER              = 70345,
    SPELL_GROW_STACKER_GROW_AURA    = 70347,

    SPELL_MALLEABLE_GOO_MISSILE     = 70852,

    SPELL_CHOKING_GAS_BOMB          = 71255,
    SPELL_CHOKING_GAS_BOMB_AURA     = 71259,
    SPELL_CHOKING_GAS_BOMB_EXPL_AUR = 71280,
    SPELL_CHOKING_GAS_EXPLOSION     = 71279,

    // phase transitions
    SPELL_TEAR_GAS_1                = 71615,
    SPELL_TEAR_GAS                  = 71617,
    SPELL_TEAR_GAS_2                = 71618,
    SPELL_TEAR_GAS_PERIODIC_AURA    = 73170,
    SPELL_TEAR_GAS_CANCEL           = 71620,

    SPELL_CREATE_CONCOCTION         = 71621,
    SPELL_GUZZLE_POTIONS            = 71893,

    SPELL_MUTATED_PLAGUE            = 72451,

    // heroic
    SPELL_UNBOUND_PLAGUE            = 70911,
    SPELL_OOZE_VARIABLE             = 70352, // aura 303 - dont allow taking damage from attacker with linked aura303?
    SPELL_OOZE_VARIABLE_OOZE        = 74118, // anyway, implemented as hardcoded in script
    SPELL_GAS_VARIABLE              = 70353,
    SPELL_GAS_VARIABLE_GAS          = 74119,

    NPC_GREEN_ORANGE_OOZE_STALKER   = 37824, // casts orange and green visual spell and then summons add
    NPC_GROWING_OOZE_PUDDLE         = 37690,
    NPC_GROWING_OOZE_PUDDLE_TRIG    = 38234,
    NPC_CHOKING_GAS_BOMB            = 38159,
    NPC_VOLATILE_OOZE               = 37697,
    NPC_MUTATED_ABOMINATION_1       = 37672,
    NPC_MUTATED_ABOMINATION_2       = 38285,
    NPC_MALLEABLE_GOO               = 38556,

/*
    SPELL_OOZE_GAS_PROTECTION     = 70812,
    SPELL_OOZE_BEAM_PROTECTION    = 71530,
    SPELL_OOZE_TANK_PROTECTION    = 71770,

    SPELL_ORANGE_RADIATION        = 45857, //Additional visual

    QUEST_24749                   = 71518,
    SHADOW_INFUSION_AURA          = 71516,

    VIEW_1                        = 30881,
    VIEW_2                        = 30881,
    VIEW_3                        = 30993,
*/
};

// talks
enum
{
    SAY_AGGRO                   = -1631092,
    SAY_AIRLOCK                 = -1631093,
    SAY_PHASE_CHANGE            = -1631094,
    SAY_TRANSFORM_1             = -1631095,
    SAY_TRANSFORM_2             = -1631096,
    SAY_SLAY_1                  = -1631097,
    SAY_SLAY_2                  = -1631098,
    SAY_BERSERK                 = -1631099,
    SAY_DEATH                   = -1631100,

    // during other fights
    SAY_SLIME_FLOW_1            = -1631074,
    SAY_SLIME_FLOW_2            = -1631075,
    SAY_BLIGHT                  = -1631083,
    SAY_FESTERGUT_DEATH         = -1631091,
    SAY_ROTFACE_DEATH           = -1631080,
};

static LOCATION SpawnLoc[]=
{
    {4356.779785f, 3263.510010f, 389.398010f, 1.586f},  // 0 Putricide start point o=1.586
    {4295.081055f, 3188.883545f, 389.330261f, 4.270f},  // 1 Puticide Festergut say, o=4.27
    {4417.302246f, 3188.219971f, 389.332520f, 5.102f},  // 2 Putricide Rotface say o=5.102
    {4388.1f, 3213.29f, 408.7399f, 3.8397f},            // 3 Ooze stalker - green
    {4324.7212f, 3214.6428f, 408.7399f, 5.5764f},       // 4 Ooze stalker - orange
};

#define POINT_PUTRICIDE_SPAWN 1

enum Phases
{
    PHASE_ONE,
    PHASE_RUNNING_ONE,
    PHASE_TRANSITION_ONE,
    PHASE_TWO,
    PHASE_RUNNING_TWO,
    PHASE_TRANSITION_TWO,
    PHASE_THREE
};

/**
 * boss_professor_putricide
 */
struct MANGOS_DLL_DECL boss_professor_putricideAI : public base_icc_bossAI
{
    boss_professor_putricideAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiPhase;

    uint32 m_uiHealthCheckTimer;
    uint32 m_uiTransitionTimer;
    uint32 m_uiEnrageTimer;
    uint32 m_uiPuddleTimer;
    uint32 m_uiUnstableExperimentTimer;
    uint32 m_uiMalleableGooTimer;
    uint32 m_uiChokingGasBombTimer;
    uint32 m_uiMutatedPlagueTimer;
    uint32 m_uiUnboundPlagueTimer;

    // used to determine whether he is assisting one of his pupils or having his own encounter
    bool m_bIsAssistingOnly;

    bool m_bIsGreenOoze; // green or orange ooze to summon

    std::list<Creature*> SummonEntryList;

    void Reset() override
    {
        m_uiPhase                   = PHASE_ONE;
        m_bIsAssistingOnly          = false;
        SetCombatMovement(true);

        m_bIsGreenOoze              = true; // first ooze summoned is always green

        m_uiHealthCheckTimer        = 1000;
        m_uiEnrageTimer             = 10 * MINUTE * IN_MILLISECONDS;
        m_uiPuddleTimer             = 10000;
        m_uiUnstableExperimentTimer = 20000;
        m_uiMalleableGooTimer       = 5000;
        m_uiChokingGasBombTimer     = urand(10000, 15000);
        m_uiMutatedPlagueTimer      = 0;
        m_uiUnboundPlagueTimer      = 10000;
    }

    void DamageTaken(Unit* /*pDealer*/, uint32& uiDamage) override
    {
        if (m_bIsAssistingOnly)
            uiDamage = 0;
    }

    void KilledUnit(Unit* /*pVictim*/) override
    {
        DoScriptText(SAY_SLAY_1 - urand(0, 1), m_creature);
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (!m_pInstance)
            return;

        if (m_pInstance->GetData(TYPE_FESTERGUT) == IN_PROGRESS || m_pInstance->GetData(TYPE_ROTFACE) == IN_PROGRESS)
        {
            SetCombatMovement(false, true);
            m_bIsAssistingOnly = true;
            return;
        }

        m_pInstance->SetData(TYPE_PROFESSOR_PUTRICIDE, IN_PROGRESS);
        DoScriptText(SAY_AGGRO, m_creature);
        // Make table interactable
        if (GameObject* pGOTable = m_pInstance->GetSingleGameObjectFromStorage(GO_DRINK_ME_TABLE))
            pGOTable->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_PROFESSOR_PUTRICIDE, DONE);

        DoScriptText(SAY_DEATH, m_creature);

        DoRemoveBossEffects();
    }

    void DoRemoveMutatedAmobination(bool bRestoreTable)
    {
        Map* pMap = m_creature->GetMap();
        Map::PlayerList const& players = pMap->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            if (Player* pPlayer = itr->getSource())
            {
                if (pPlayer->GetVehicle())
                    pPlayer->ExitVehicle();
            }
        }

        if (m_pInstance)
        {
            if (GameObject* pGOTable = m_pInstance->GetSingleGameObjectFromStorage(GO_DRINK_ME_TABLE))
            {
                if (bRestoreTable)
                    pGOTable->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
                else
                    pGOTable->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
            }
        }
    }

    void DoRemoveBossEffects()
    {
        DoRemoveMutatedAmobination(false);

        SummonEntryList.clear();
        GetCreatureListWithEntryInGrid(SummonEntryList, m_creature, NPC_GROWING_OOZE_PUDDLE, 100.0f);

        for (std::list<Creature*>::iterator itr = SummonEntryList.begin(); itr != SummonEntryList.end(); ++itr)
        {
           if ((*itr)->isAlive())
                (*itr)->ForcedDespawn();
        }

        Map* pMap = m_creature->GetMap();
        Map::PlayerList const& players = pMap->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            if (Player* pPlayer = itr->getSource())
            {
                pPlayer->RemoveAurasDueToSpell(SPELL_GAS_VARIABLE);
                pPlayer->RemoveAurasDueToSpell(SPELL_GAS_VARIABLE_GAS);
                pPlayer->RemoveAurasDueToSpell(SPELL_MUTATED_PLAGUE);
            }
        }
    }

    void JustReachedHome() override
    {
        if (m_pInstance && !m_bIsAssistingOnly)
            m_pInstance->SetData(TYPE_PROFESSOR_PUTRICIDE, FAIL);

        if (VehicleKitPtr pKit = m_creature->GetVehicleKit())
        {
            pKit->RemoveAllPassengers();
            pKit->Reset();
        }

        // some weird bug with not regenerating health after wipe ;/
        m_creature->SetHealth(m_creature->GetMaxHealth());
        DoRemoveBossEffects();
    }

    void MovementInform(uint32 uiMovementType, uint32 uiData) override
    {
        if (uiMovementType != POINT_MOTION_TYPE || uiData != POINT_PUTRICIDE_SPAWN)
            return;
        if (m_uiPhase != PHASE_RUNNING_ONE && m_uiPhase != PHASE_RUNNING_TWO)
            return;

        if (m_bIsHeroic)
        {
            DoScriptText(SAY_PHASE_CHANGE, m_creature);
            m_uiTransitionTimer = 30000;
        }
        else
        {
            DoCastSpellIfCan(m_creature, m_uiPhase == PHASE_RUNNING_ONE ? SPELL_CREATE_CONCOCTION : SPELL_GUZZLE_POTIONS);
            DoScriptText(m_uiPhase == PHASE_RUNNING_ONE ? SAY_TRANSFORM_1 : SAY_TRANSFORM_2, m_creature);
            m_uiTransitionTimer = 15000;
        }

        // counter for entering next phase
        m_uiPhase = m_uiPhase == PHASE_RUNNING_ONE ? PHASE_TRANSITION_ONE : PHASE_TRANSITION_TWO;
    }

    void DoExperiment(bool green, bool orange)
    {
        if (green)
        {
            if (m_creature->SummonCreature(NPC_GREEN_ORANGE_OOZE_STALKER, SpawnLoc[3].x, SpawnLoc[3].y, SpawnLoc[3].z, SpawnLoc[3].o, TEMPSUMMON_TIMED_DESPAWN, 10000))
                DoCastSpellIfCan(m_creature, SPELL_GREEN_OOZE_SUMMON, CAST_TRIGGERED);
        }

        if (orange)
        {
            if (m_creature->SummonCreature(NPC_GREEN_ORANGE_OOZE_STALKER, SpawnLoc[4].x, SpawnLoc[4].y, SpawnLoc[4].z, SpawnLoc[4].o, TEMPSUMMON_TIMED_DESPAWN, 10000))
                DoCastSpellIfCan(m_creature, SPELL_ORANGE_OOZE_SUMMON, CAST_TRIGGERED);
        }

        // variable
        if (green && orange && m_bIs25Man)
            DoVariable();
    }

    void DoVariable()
    {
        bool bToggle = true;

        Map::PlayerList const& players = m_creature->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            if (Player* pPlayer = itr->getSource())
            {
                if (!pPlayer->GetVehicle() && pPlayer->isAlive())
                {
                    pPlayer->CastSpell(pPlayer, bToggle ? SPELL_GAS_VARIABLE : SPELL_OOZE_VARIABLE, true);
                    bToggle = !bToggle;
                }
            }
        }
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (!m_creature->isInCombat())
            return;
        if (pSummoned->GetEntry() != NPC_GREEN_ORANGE_OOZE_STALKER)
            pSummoned->SetInCombatWithZone();
    }

    void UpdateSlimePuddle(const uint32 uiDiff)
    {
        if (m_uiPuddleTimer <= uiDiff)
        {
            for (uint8 i = 0; i < 2; ++i)
            {
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_SLIME_PUDDLE_SUMMON, SELECT_FLAG_PLAYER))
                    DoCastSpellIfCan(pTarget, SPELL_SLIME_PUDDLE, CAST_TRIGGERED);
            }
            m_uiPuddleTimer = 30000;
        }
        else
            m_uiPuddleTimer -= uiDiff;
    }

    void UpdateUnstableExperiment(const uint32 uiDiff)
    {
        if (m_uiUnstableExperimentTimer <= uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_UNSTABLE_EXPERIMENT) == CAST_OK)
            {
                DoExperiment(m_bIsGreenOoze, !m_bIsGreenOoze);
                m_uiUnstableExperimentTimer = 30000;
                m_bIsGreenOoze = !m_bIsGreenOoze;
            }
        }
        else
            m_uiUnstableExperimentTimer -= uiDiff;
    }

    void UpdateUnboundPlague(const uint32 uiDiff)
    {
        if (!m_bIsHeroic)
            return;
        if (m_uiUnboundPlagueTimer <= uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, SPELL_UNBOUND_PLAGUE, SELECT_FLAG_PLAYER))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_UNBOUND_PLAGUE) == CAST_OK)
                    m_uiUnboundPlagueTimer = 70000;
            }
        }
        else
            m_uiUnboundPlagueTimer -= uiDiff;
    }

    void UpdateSwitchPhaseIntro(const uint32 uiDiff)
    {
        if (!m_pInstance)
            return;

        if (m_uiHealthCheckTimer <= uiDiff)
        {
            float fSwitchHealthPercent = m_uiPhase == PHASE_ONE ? 80.0f : 35.0f;
            if (m_creature->GetHealthPercent() <= fSwitchHealthPercent)
            {
                SetCombatMovement(false, true);
                if (m_bIsHeroic)
                {
                    DoCastSpellIfCan(m_creature, SPELL_VOLATILE_EXPERIMENT);
                    DoExperiment(true, true);
                    DoScriptText(SAY_PHASE_CHANGE, m_creature);
                }
                else
                {
                    DoCastSpellIfCan(m_creature, SPELL_TEAR_GAS, CAST_TRIGGERED);
                    DoCastSpellIfCan(m_creature, SPELL_TEAR_GAS_1, CAST_TRIGGERED);
                }

                m_pInstance->SetData(TYPE_PROFESSOR_PUTRICIDE, SPECIAL);

                m_uiPhase = m_uiPhase == PHASE_ONE ? PHASE_RUNNING_ONE : PHASE_RUNNING_TWO;
                m_creature->GetMotionMaster()->MovePoint(POINT_PUTRICIDE_SPAWN, SpawnLoc[0].x, SpawnLoc[0].y, SpawnLoc[0].z);

                if (m_uiPhase == PHASE_RUNNING_TWO)
                    DoRemoveMutatedAmobination(false);
            }
            m_uiHealthCheckTimer = 1000;
        }
        else
            m_uiHealthCheckTimer -= uiDiff;
    }

    void UpdateMalleableGoo(const uint32 uiDiff)
    {
        if (m_uiMalleableGooTimer <= uiDiff)
        {
            for (uint8 i = 0; i < (m_bIs25Man ? 2 : 1); ++i)
            {
                if (Unit* pTarget = SelectRandomRangedTarget(m_creature))
                {
                    float x, y, z;
                    pTarget->GetPosition(x, y, z);
                    if (Creature* pTrigger = m_creature->SummonCreature(NPC_MALLEABLE_GOO, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 20000))
                    {
                        m_creature->CastSpell(pTrigger, SPELL_MALLEABLE_GOO_MISSILE, true);
                        m_uiMalleableGooTimer = 20000;
                    }
                }
            }
        }
        else
            m_uiMalleableGooTimer -= uiDiff;
    }

    void UpdateChokingGasBomb(const uint32 uiDiff)
    {
        if (m_uiChokingGasBombTimer <= uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_CHOKING_GAS_BOMB) == CAST_OK)
                m_uiChokingGasBombTimer = urand(25000, 30000);
        }
        else
            m_uiChokingGasBombTimer -= uiDiff;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (m_bIsAssistingOnly)
            return;

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        // Enrage
        if (m_uiEnrageTimer <= uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BERSERK) == CAST_OK)
            {
                DoScriptText(SAY_BERSERK, m_creature);
                m_uiEnrageTimer = 30 * MINUTE * IN_MILLISECONDS;
            }
        }
        else
            m_uiEnrageTimer -= uiDiff;

        switch (m_uiPhase)
        {
            case PHASE_ONE:
            {
                UpdateSlimePuddle(uiDiff);
                UpdateUnstableExperiment(uiDiff);
                UpdateUnboundPlague(uiDiff);
                UpdateSwitchPhaseIntro(uiDiff);
                break;
            }
            case PHASE_TWO:
            {
                UpdateSlimePuddle(uiDiff);
                UpdateUnstableExperiment(uiDiff);
                UpdateUnboundPlague(uiDiff);
                UpdateMalleableGoo(uiDiff);
                UpdateChokingGasBomb(uiDiff);
                UpdateSwitchPhaseIntro(uiDiff);
                break;
            }
            case PHASE_THREE:
            {
                UpdateSlimePuddle(uiDiff);
                UpdateMalleableGoo(uiDiff);
                UpdateChokingGasBomb(uiDiff);
                UpdateUnboundPlague(uiDiff);

                // Mutated Plague (proc cooldown for creatures doesn't work)
                if (m_uiMutatedPlagueTimer <= uiDiff)
                {
                    if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_MUTATED_PLAGUE) == CAST_OK)
                        m_uiMutatedPlagueTimer = 10000;
                }
                else
                    m_uiMutatedPlagueTimer -= uiDiff;

                break;
            }
            case PHASE_TRANSITION_ONE:
            case PHASE_TRANSITION_TWO:
            {
                if (m_uiTransitionTimer <= uiDiff)
                {
                    if (m_pInstance)
                        m_pInstance->SetData(TYPE_PROFESSOR_PUTRICIDE, IN_PROGRESS);

                    if (m_bIsHeroic)
                    {
                        DoCastSpellIfCan(m_creature, m_uiPhase == PHASE_TRANSITION_ONE ? SPELL_CREATE_CONCOCTION : SPELL_GUZZLE_POTIONS);
                        DoScriptText(m_uiPhase == PHASE_TRANSITION_ONE ? SAY_TRANSFORM_1 : SAY_TRANSFORM_2, m_creature);
                    }
                    else
                        DoCastSpellIfCan(m_creature, SPELL_TEAR_GAS_CANCEL, CAST_TRIGGERED);

                    m_uiPhase = m_uiPhase == PHASE_TRANSITION_ONE ? PHASE_TWO : PHASE_THREE;
                    m_creature->GetMotionMaster()->Clear();
                    SetCombatMovement(true, true);
                }
                else
                    m_uiTransitionTimer -= uiDiff;

                return;
            }
            case PHASE_RUNNING_ONE:
            case PHASE_RUNNING_TWO:
                // wait for arriving at the table (during phase transition)
                return;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_professor_putricide(Creature* pCreature)
{
    return new boss_professor_putricideAI(pCreature);
}

/**
 * mob_icc_gas_cloud
 */
struct MANGOS_DLL_DECL mob_icc_gas_cloudAI : public base_icc_bossAI
{
    mob_icc_gas_cloudAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        m_bIsVariable = false;
        if (m_pInstance)
        {
            if (m_pInstance->GetData(TYPE_PROFESSOR_PUTRICIDE) == SPECIAL)
            {
                DoCastSpellIfCan(m_creature, SPELL_GAS_VARIABLE_GAS, CAST_TRIGGERED);
                m_bIsVariable = true;
            }
        }
        m_creature->SetSpeedRate(MOVE_RUN, 1.0f);
        Reset();
    }

    uint32 m_uiMoveTimer;
    bool m_bIsVariable;

    void Reset() override
    {
        m_uiMoveTimer = 0;
        SetCombatMovement(false);
        DoCastSpellIfCan(m_creature, SPELL_GASEOUS_BLOAT_VISUAL, CAST_TRIGGERED);
        DoSelectTarget();
        m_creature->SetInCombatWithZone();
    }

    void DamageTaken(Unit* pDealer, uint32& uiDamage) override
    {
        if (!m_bIsVariable)
            return;
        if (pDealer->HasAuraOfDifficulty(SPELL_GAS_VARIABLE))
        {
            uiDamage = 0;
            return;
        }

        // remove variable debuffs
        if (uiDamage >= m_creature->GetHealth())
        {
            ThreatList const& tList = m_creature->getThreatManager().getThreatList();

            for (ThreatList::const_iterator itr = tList.begin(); itr != tList.end(); ++itr)
            {
                if (!(*itr)->getUnitGuid().IsPlayer())
                    continue;

                if (Unit* pPlayer = m_creature->GetMap()->GetUnit((*itr)->getUnitGuid()))
                    pPlayer->RemoveAurasDueToSpell(SPELL_GAS_VARIABLE);
            }
        }
    }

    void DoSelectTarget()
    {
        if (!m_pInstance)
            return;
        m_creature->FixateTarget(NULL); // Clear target
        if (Creature* pProf = m_pInstance->GetSingleCreatureFromStorage(NPC_PROFESSOR_PUTRICIDE))
        {
            Unit* pTarget = NULL;

            pTarget = pProf->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, SPELL_GASEOUS_BLOAT, SELECT_FLAG_PLAYER);
            if (!pTarget)
                pTarget = pProf->getVictim();

            if (pTarget)
            {
                if (DoCastSpellIfCan(pTarget, SPELL_GASEOUS_BLOAT) == CAST_OK)
                    m_creature->FixateTarget(pTarget);
            }
        }
        m_uiMoveTimer = 3000; // 3 sec cast
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (m_pInstance)
        {
            uint32 uiData = m_pInstance->GetData(TYPE_PROFESSOR_PUTRICIDE);
            if (uiData != IN_PROGRESS && uiData != SPECIAL)
                m_creature->ForcedDespawn();
            if (!m_bIsVariable && uiData == SPECIAL)
            {
                if (IsCombatMovement())
                    SetCombatMovement(false, true);
                m_uiMoveTimer = 1;
            }
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim() || !m_creature->GetFixatedTarget())
        {
            DoSelectTarget();
            return;
        }

        if (m_uiMoveTimer)
        {
            if (m_uiMoveTimer <= uiDiff)
            {
                SetCombatMovement(true, true);
                m_uiMoveTimer = 0;
            }
            else
                m_uiMoveTimer -= uiDiff;
        }

        if (!m_uiMoveTimer && m_creature->GetDistance(m_creature->getVictim()) <= 4.0f)
        {
            m_creature->getVictim()->CastSpell(m_creature->getVictim(), SPELL_EXPUNGED_GAS, true);
            m_creature->InterruptSpell(CURRENT_CHANNELED_SPELL);
            SetCombatMovement(false, true);
            DoSelectTarget();
        }
    }
};

CreatureAI* GetAI_mob_icc_gas_cloud(Creature* pCreature)
{
    return new mob_icc_gas_cloudAI(pCreature);
}

/**
 * mob_icc_volatile_ooze
 */
struct MANGOS_DLL_DECL mob_icc_volatile_oozeAI : public base_icc_bossAI
{
    mob_icc_volatile_oozeAI(Creature* pCreature) : base_icc_bossAI(pCreature)
    {
        m_bIsVariable = false;
        if (m_pInstance)
        {
            if (m_pInstance->GetData(TYPE_PROFESSOR_PUTRICIDE) == SPECIAL)
            {
                DoCastSpellIfCan(m_creature, SPELL_OOZE_VARIABLE_OOZE, CAST_TRIGGERED);
                m_bIsVariable = true;
            }
        }
        m_creature->SetSpeedRate(MOVE_RUN, 1.0f);
        Reset();
    }

    uint32 m_uiMoveTimer;
    bool m_bIsVariable;

    void Reset() override
    {
        m_uiMoveTimer   = 0;
        SetCombatMovement(false);
        DoSelectTarget();
        m_creature->SetInCombatWithZone();
    }

    void DamageTaken(Unit* pDealer, uint32& uiDamage) override
    {
        if (!m_bIsVariable)
            return;
        if (pDealer->HasAuraOfDifficulty(SPELL_OOZE_VARIABLE))
        {
            uiDamage = 0;
            return;
        }

        // remove variable debuffs
        if (uiDamage >= m_creature->GetHealth())
        {
            ThreatList const& tList = m_creature->getThreatManager().getThreatList();

            for (ThreatList::const_iterator itr = tList.begin(); itr != tList.end(); ++itr)
            {
                if (!(*itr)->getUnitGuid().IsPlayer())
                    continue;

                if (Unit* pTmp = m_creature->GetMap()->GetUnit((*itr)->getUnitGuid()))
                    pTmp->RemoveAurasDueToSpell(SPELL_OOZE_VARIABLE);
            }
        }
    }

    void DoSelectTarget()
    {
        if (!m_pInstance)
            return;
        m_creature->FixateTarget(NULL); // Clear target
        if (Creature* pProf = m_pInstance->GetSingleCreatureFromStorage(NPC_PROFESSOR_PUTRICIDE))
        {
            Unit* pTarget = NULL;

            pTarget = pProf->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, SPELL_OOZE_ADHESIVE, SELECT_FLAG_PLAYER);
            if (!pTarget)
                pTarget = pProf->getVictim();

            if (pTarget)
            {
                if (DoCastSpellIfCan(pTarget, SPELL_OOZE_ADHESIVE) == CAST_OK)
                {
                    m_creature->FixateTarget(pTarget);
                    m_uiMoveTimer = 3000; // 3 sec cast
                }
            }
        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (m_pInstance)
        {
            uint32 uiData = m_pInstance->GetData(TYPE_PROFESSOR_PUTRICIDE);
            if (uiData != IN_PROGRESS && uiData != SPECIAL)
                m_creature->ForcedDespawn();
            if (!m_bIsVariable && uiData == SPECIAL)
            {
                if (IsCombatMovement())
                    SetCombatMovement(false, true);
                m_uiMoveTimer = 1;
                return;
            }
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim() || !m_creature->GetFixatedTarget())
        {
            DoSelectTarget();
            return;
        }

        if (m_uiMoveTimer)
        {
            if (m_uiMoveTimer <= uiDiff)
            {
                SetCombatMovement(true, true);
                m_uiMoveTimer = 0;
            }
            else
                m_uiMoveTimer -= uiDiff;
        }

        if (!m_uiMoveTimer && m_creature->GetDistance(m_creature->getVictim()) <= 4.0f)
        {
            m_creature->InterruptSpell(CURRENT_CHANNELED_SPELL);
            DoCastSpellIfCan(m_creature, SPELL_OOZE_ERUPTION);
            SetCombatMovement(false, true);
            DoSelectTarget();
        }
    }
};
CreatureAI* GetAI_mob_icc_volatile_ooze(Creature* pCreature)
{
    return new mob_icc_volatile_oozeAI(pCreature);
}

// passive mob AI struct
struct MANGOS_DLL_DECL mob_choking_gas_bombAI : public ScriptedAI
{
    mob_choking_gas_bombAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        SetCombatMovement(false);
        pCreature->CastSpell(pCreature, SPELL_CHOKING_GAS_BOMB_AURA, true);
        pCreature->CastSpell(pCreature, SPELL_CHOKING_GAS_BOMB_EXPL_AUR, true);
        pCreature->ForcedDespawn(12000);
    }

    void Reset() override {}
    void AttackStart(Unit* /*pWho*/) override {}

    void DamageTaken(Unit* /*pDealer*/, uint32& uiDamage) override
    {
        uiDamage = 0;
    }
};

CreatureAI* GetAI_mob_choking_gas_bomb(Creature* pCreature)
{
    return new mob_choking_gas_bombAI(pCreature);
}

// passive mob AI struct
struct MANGOS_DLL_DECL mob_ooze_puddleAI : public ScriptedAI
{
    mob_ooze_puddleAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        SetCombatMovement(false);
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_creature->SetObjectScale(0.2f);
        DoCastSpellIfCan(m_creature, SPELL_GROW_STACKER, CAST_TRIGGERED);
        m_creature->CastSpell(m_creature, SPELL_SLIME_PUDDLE_AURA, true);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
    }

    ScriptedInstance* m_pInstance;

    void Reset() override {}
    void AttackStart(Unit* /*pWho*/) override {}

    void UpdateAI(const uint32 /*uiDiff*/) override
    {
        if (m_pInstance)
        {
            uint32 data = m_pInstance->GetData(TYPE_PROFESSOR_PUTRICIDE);
            if (data == SPECIAL)
            {
                // don't grow while Putricide is mutating between phases
                return;
            }
            else if (data != IN_PROGRESS)
                m_creature->ForcedDespawn();
        }
    }
};
CreatureAI* GetAI_mob_ooze_puddle(Creature* pCreature)
{
    return new mob_ooze_puddleAI(pCreature);
}

// mob Mutated Abomination
struct MANGOS_DLL_DECL mob_mutated_amobinationAI : public ScriptedAI
{
    mob_mutated_amobinationAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        SetCombatMovement(false);
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    void Reset() override
    {
        m_creature->SetPower(POWER_ENERGY, 0);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_pInstance && m_pInstance->GetData(TYPE_PROFESSOR_PUTRICIDE) != DONE)
        {
            // Possibly remove GO_FLAG_NO_INTERACT when amob dies is not blizz-like
            if (GameObject* pGOTable = m_pInstance->GetSingleGameObjectFromStorage(GO_DRINK_ME_TABLE))
                pGOTable->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
        }
    }
};

CreatureAI* GetAI_mob_mutated_amobination(Creature* pCreature)
{
    return new mob_mutated_amobinationAI(pCreature);
}

// GO Drink Me!
bool GOUse_go_drink_me(Player* pPlayer, GameObject* pGameObject)
{
    pGameObject->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
    pPlayer->CastSpell(pPlayer, SPELL_MUTATED_TRANSFORMATION, true);
    return true;
}

void AddSC_boss_professor_putricide()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "boss_professor_putricide";
    pNewScript->GetAI = &GetAI_boss_professor_putricide;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_icc_volatile_ooze";
    pNewScript->GetAI = &GetAI_mob_icc_volatile_ooze;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_icc_gas_cloud";
    pNewScript->GetAI = &GetAI_mob_icc_gas_cloud;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_choking_gas_bomb";
    pNewScript->GetAI = &GetAI_mob_choking_gas_bomb;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_ooze_puddle";
    pNewScript->GetAI = &GetAI_mob_ooze_puddle;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "mob_mutated_amobination";
    pNewScript->GetAI = &GetAI_mob_mutated_amobination;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_drink_me";
    pNewScript->pGOUse = &GOUse_go_drink_me;
    pNewScript->RegisterSelf();
}
