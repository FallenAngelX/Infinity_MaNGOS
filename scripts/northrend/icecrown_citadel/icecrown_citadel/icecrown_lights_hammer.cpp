/* Copyright (C) 2013 by boxa for ScriptDev2_R2 <http://github.com/mangosR2/scriptdev2/>
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
SDName: icecrown_lights_hammer
SD%Complete: 100%
SDComment: ICC start event
SDCategory: Icecrown Citadel
EndScriptData */

/* ContentData
npc_tirion_fordring_lh
npc_the_damned_lh
EndContentData */

#include "precompiled.h"
#include "icecrown_citadel.h"

/*######
## npc_tirion_fordring_lh
######*/

enum
{
    // Highlord Tirion Fordring
    SAY_TIRION_INTRO_1              = -1020500,
    SAY_TIRION_INTRO_2              = -1020501,
    SAY_TIRION_INTRO_3              = -1020502,
    SAY_TIRION_INTRO_4              = -1020503,
    SAY_TIRION_INTRO_H_5            = -1020504,
    SAY_TIRION_INTRO_A_5            = -1020505,
    // The Lich King
    SAY_LK_INTRO_1                  = -1020506,
    SAY_LK_INTRO_2                  = -1020507,
    SAY_LK_INTRO_3                  = -1020508,
    SAY_LK_INTRO_4                  = -1020509,
    SAY_LK_INTRO_5                  = -1020510,
    // Highlord Bolvar Fordragon
    SAY_BOLVAR_INTRO_1              = -1020511,
    // High Overlord Saurfang
    SAY_SAURFANG_INTRO_1            = -1020512,
    SAY_SAURFANG_INTRO_2            = -1020513,
    SAY_SAURFANG_INTRO_3            = -1020514,
    SAY_SAURFANG_INTRO_4            = -1020515,
    // Muradin Bronzebeard
    SAY_MURADIN_INTRO_1             = -1020516,
    SAY_MURADIN_INTRO_2             = -1020517,
    SAY_MURADIN_INTRO_3             = -1020518,
    // Emotions
    EMOTE_EXCLAMATION               = -1020519,
    EMOTE_POINT_NOSHEATHE           = -1020520,
    EMOTE_TALK                      = -1020521,
    // Npcs
    NPC_ALLIANCE_COMMANDER          = 37190,
    NPC_KORKRON_GENERAL             = 37189,
    // Dialogue steps
    SELECT_NEXT_DIALOGUE            = 1,
    SAURFANG_INTRO_END              = 2,
    MURADIN_INTRO_END               = 3,
};

static const DialogueEntry iccIntroDialogue[] =
{
    // Common
    {SAY_TIRION_INTRO_1,    NPC_HIGHLORD_TIRION_FORDRING_LH,  4000},
    {EMOTE_EXCLAMATION,     NPC_HIGHLORD_TIRION_FORDRING_LH,  9000},
    {SAY_TIRION_INTRO_2,    NPC_HIGHLORD_TIRION_FORDRING_LH,  5000},
    {EMOTE_EXCLAMATION,     NPC_HIGHLORD_TIRION_FORDRING_LH, 11000},
    {SAY_TIRION_INTRO_3,    NPC_HIGHLORD_TIRION_FORDRING_LH,  4000},
    {SAY_LK_INTRO_1,        NPC_THE_LICH_KING_LH,               10},
    {EMOTE_POINT_NOSHEATHE, NPC_HIGHLORD_TIRION_FORDRING_LH, 13000},
    {SAY_TIRION_INTRO_4,    NPC_HIGHLORD_TIRION_FORDRING_LH,  8000},
    {SAY_LK_INTRO_2,        NPC_THE_LICH_KING_LH,            13000},
    {SAY_LK_INTRO_3,        NPC_THE_LICH_KING_LH,             9000},
    {SAY_LK_INTRO_4,        NPC_THE_LICH_KING_LH,            21000},
    {SAY_LK_INTRO_5,        NPC_THE_LICH_KING_LH,             5000},
    {SAY_BOLVAR_INTRO_1,    NPC_HIGHLORD_BOLVAR_FORDRAGON_LH, 6000},
    {SELECT_NEXT_DIALOGUE,  0,                                   0},
    // Horde
    {SAY_SAURFANG_INTRO_1,  NPC_SAURFANG_LH,                  6000},
    {SAY_TIRION_INTRO_H_5,  NPC_HIGHLORD_TIRION_FORDRING_LH,  8000},
    {SAY_SAURFANG_INTRO_2,  NPC_SAURFANG_LH,                 10000},
    {SAY_SAURFANG_INTRO_3,  NPC_SAURFANG_LH,                  9000},
    {SAY_SAURFANG_INTRO_4,  NPC_SAURFANG_LH,                 11000},
    {SAURFANG_INTRO_END,    0,                                   0},
    // Alliance
    {SAY_MURADIN_INTRO_1,   NPC_MURADIN_LH,                   2000},
    {EMOTE_TALK,            NPC_MURADIN_LH,                   2000},
    {EMOTE_EXCLAMATION,     NPC_MURADIN_LH,                   8000},
    {SAY_TIRION_INTRO_A_5,  NPC_HIGHLORD_TIRION_FORDRING_LH,  3000},
    {SAY_MURADIN_INTRO_2,   NPC_MURADIN_LH,                   4000},
    {SAY_MURADIN_INTRO_3,   NPC_MURADIN_LH,                   7000},
    {MURADIN_INTRO_END,     0,                                   0},
    {0, 0, 0},
};

struct MANGOS_DLL_DECL npc_tirion_fordring_lhAI : public ScriptedAI, private DialogueHelper
{
    npc_tirion_fordring_lhAI(Creature* pCreature) : ScriptedAI(pCreature), DialogueHelper(iccIntroDialogue)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        InitializeDialogueHelper(m_pInstance);
        Reset();
    }

    ScriptedInstance* m_pInstance;

    enum
    {
        STAGE_IDLE  = 0,
        STAGE_WAIT  = 1,
        STAGE_START = 2
    };

    uint32 m_stage;

    void Reset() override
    {
        m_stage = (m_pInstance && m_pInstance->GetData(TYPE_ICC_INTRO) != DONE) ? STAGE_WAIT : STAGE_IDLE;

        if (m_stage != STAGE_IDLE)
            m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        else // if already completed intro
        {
            HideChiefAndFollowers(NPC_SAURFANG_LH, NPC_KORKRON_GENERAL);
            HideChiefAndFollowers(NPC_MURADIN_LH, NPC_ALLIANCE_COMMANDER);
        }
    }

    void HideChiefAndFollowers(uint32 chiefId, uint32 followerId)
    {
        if (!m_pInstance)
            return;

        Creature* pChief = m_pInstance->GetSingleCreatureFromStorage(chiefId);
        if (!pChief)
            return;

        pChief->SetVisibility(VISIBILITY_OFF);

        std::list<Creature*> followers;
        GetCreatureListWithEntryInGrid(followers, pChief, followerId, 10.0f);

        if (followers.empty())
            return;

        for (std::list<Creature*>::const_iterator itr = followers.begin(); itr != followers.end(); ++itr)
        {
            if (Creature* pFollower = *itr)
                pFollower->SetVisibility(VISIBILITY_OFF);
        }
    }

    void MoveToInstanceExit(uint32 chiefId, uint32 followerId)
    {
        if (!m_pInstance)
            return;

        m_stage = STAGE_IDLE;

        Creature* pChief = m_pInstance->GetSingleCreatureFromStorage(chiefId);
        if (!pChief)
            return;

        if (GameObject* pPortal = m_pInstance->GetSingleGameObjectFromStorage(GO_INSTANCE_PORTAL))
        {
            std::list<Creature*> followers;
            GetCreatureListWithEntryInGrid(followers, pChief, followerId, 10.0f);

            if (!followers.empty())
            {
                for (std::list<Creature*>::const_iterator itr = followers.begin(); itr != followers.end(); ++itr)
                {
                    if (Creature* pFollower = *itr)
                    {
                        pFollower->SetWalk(false);
                        pFollower->addUnitState(UNIT_STAT_IGNORE_PATHFINDING);
                        pFollower->GetMotionMaster()->MoveFollow(pChief, 5.0f, pFollower->GetAngle(pChief));
                        pFollower->ForcedDespawn(15000);
                    }
                }
            }

            pChief->SetWalk(false);
            pChief->GetMotionMaster()->MovePoint(0, pPortal->GetPositionX(), pPortal->GetPositionY(), pPortal->GetPositionZ());
        }

        pChief->ForcedDespawn(15000);

        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        m_pInstance->SetData(TYPE_ICC_INTRO, DONE);
    }

    void ReceiveAIEvent(AIEventType eventType, Creature* pSender, Unit* /*pInvoker*/, uint32 /*uiMiscValue*/) override
    {
        if (!m_pInstance)
            return;

        if (m_stage != STAGE_IDLE && eventType == AI_EVENT_CUSTOM_A && pSender->GetEntry() == NPC_DAMNED)
        {
            if (m_stage++ == STAGE_START)
                StartNextDialogueText(SAY_TIRION_INTRO_1);
        }
    }

    void JustDidDialogueStep(int32 iEntry) override
    {
        if (!m_pInstance)
            return;

        switch (iEntry)
        {
            case SELECT_NEXT_DIALOGUE:
                if (Player* pPlayer = m_pInstance->GetPlayerInMap())
                    StartNextDialogueText(pPlayer->GetTeam() == HORDE ? SAY_SAURFANG_INTRO_1 : SAY_MURADIN_INTRO_1);
                else
                    m_stage = STAGE_IDLE;
                break;
            case SAURFANG_INTRO_END:
                MoveToInstanceExit(NPC_SAURFANG_LH, NPC_KORKRON_GENERAL);
                break;
            case MURADIN_INTRO_END:
                MoveToInstanceExit(NPC_MURADIN_LH, NPC_ALLIANCE_COMMANDER);
                break;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_pInstance && m_stage != STAGE_IDLE)
            DialogueUpdate(uiDiff);
    }
};

CreatureAI* GetAI_npc_tirion_fordring_lh(Creature* pCreature)
{
    return new npc_tirion_fordring_lhAI(pCreature);
}

/*######
## npc_the_damned_lh
######*/

enum
{
    SPELL_BONE_FLURRY     = 59697,
    SPELL_SHATTERED_BONES = 70961
};

struct MANGOS_DLL_DECL npc_the_damned_lhAI : public ScriptedAI
{
    npc_the_damned_lhAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    TTimer m_boneFlurryTimer;
    bool onceShatteredBones;

    void Reset() override
    {
        m_boneFlurryTimer.Reset(10000, 15000);
        onceShatteredBones = false;
    }

    void DamageTaken(Unit* /*pDoneBy*/, uint32& uiDamage) override
    {
        if (!onceShatteredBones && uiDamage >= m_creature->GetHealth())
        {
            onceShatteredBones = true;
            m_creature->CastSpell(m_creature, SPELL_SHATTERED_BONES, false);
            uiDamage = 0;
        }
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_pInstance && m_pInstance->GetData(TYPE_ICC_INTRO) != DONE)
        {
            if (Creature* pFordring = m_pInstance->GetSingleCreatureFromStorage(NPC_HIGHLORD_TIRION_FORDRING_LH))
                SendAIEvent(AI_EVENT_CUSTOM_A, NULL, pFordring);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!SelectVictim())
            return;

        if (m_boneFlurryTimer.Expired(uiDiff))
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BONE_FLURRY) == CAST_OK)
                m_boneFlurryTimer.Reset(20000, 25000);
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_the_damned_lh(Creature* pCreature)
{
    return new npc_the_damned_lhAI(pCreature);
}

/*######
## Register scripts
######*/

void AddSC_icecrown_lights_hammer()
{
    AutoScript s;
    s.newScript("npc_tirion_fordring_lh")->GetAI = &GetAI_npc_tirion_fordring_lh;
    s.newScript("npc_the_damned_lh")->GetAI = &GetAI_npc_the_damned_lh;
}
