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
SDName: Icecrown
SD%Complete: 100
Quest Support: 13663, 13665, 13745, 13750, 13756, 13761, 13767, 13772, 13777, 13782, 13787, 14107
SDCategory: Icecrown
EndScriptData */

/* ContentData
npc_dame_evniki_kapsalis
npc_scourge_conventor
npc_fallen_hero_spirit
npc_valiants
npc_champions
npc_black_knights_gryphon
npc_saronite_mine_slave
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"
#include "TemporarySummon.h"

/*######
## npc_melee_target  //quests 13828,13829,13625,13677
######*/

struct MANGOS_DLL_DECL npc_melee_targetAI : public ScriptedAI
{
    npc_melee_targetAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint32 m_uiEvade_Timer;

    void Reset()
    {
        m_uiEvade_Timer = 5000;
        SetCombatMovement(false);
    }

    void DamageTaken(Unit* pDoneBy, uint32& uiDamage) override
    {
        if (uiDamage > m_creature->GetHealth())
            uiDamage = 0;
        m_uiEvade_Timer = 5000;
    }

    void SpellHit(Unit* pCaster, const SpellEntry* pSpell) override
    {
        if (pSpell->Id == 62544)
        {
            DoCastSpellIfCan(pCaster, 62709);
            if (Player* pPlayer = pCaster->GetCharmerOrOwnerPlayerOrPlayerItself())
                pPlayer->KilledMonsterCredit(33341);
        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (m_uiEvade_Timer < uiDiff)
        {
            m_uiEvade_Timer = 5000;
            m_creature->DeleteThreatList();
            m_creature->CombatStop(true);
        }
        else
            m_uiEvade_Timer -= uiDiff;
    }
};

CreatureAI* GetAI_npc_melee_target(Creature* pCreature)
{
    return new npc_melee_targetAI(pCreature);
}

/*######
## npc_ranged_target  //quests 13835,13838,13625,13677
######*/

struct MANGOS_DLL_DECL npc_ranged_targetAI : public ScriptedAI
{
    npc_ranged_targetAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint32 m_uiEvade_Timer;
    uint32 m_uiDefend_Timer;

    void Reset()
    {
        m_uiEvade_Timer  = 5000;
        m_uiDefend_Timer = 5000;

        SetCombatMovement(false);
    }

    void DamageTaken(Unit* pDoneBy, uint32& uiDamage) override
    {
        if (uiDamage > m_creature->GetHealth())
            uiDamage = 0;
        m_uiEvade_Timer = 5000;
    }

    void SpellHit(Unit* pCaster, const SpellEntry* pSpell) override
    {
        switch(pSpell->Id)
        {
            case 64342:
                if (!m_creature->HasAura(62719))
                {
                    if (Player* pPlayer = pCaster->GetCharmerOrOwnerPlayerOrPlayerItself())
                        pPlayer->KilledMonsterCredit(33339);
                    return;
                }
            case 63010:
                if (SpellAuraHolderPtr holder = m_creature->GetSpellAuraHolder(62719))
                {
                    if (holder->ModStackAmount(-1))
                        m_creature->RemoveSpellAuraHolder(holder, AURA_REMOVE_BY_SHIELD_BREAK);

                    m_uiDefend_Timer = 5000;
                }
        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (m_uiDefend_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, 62719);
            Aura* pAura = m_creature->GetAura(62719, EFFECT_INDEX_0);
            if (pAura && pAura->GetStackAmount() > 2)
                m_uiDefend_Timer = 50000;
            else
                m_uiDefend_Timer = 5000;
        }
        else
            m_uiDefend_Timer -= uiDiff;

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (m_uiEvade_Timer < uiDiff)
        {
            m_uiEvade_Timer = 5000;
            m_creature->DeleteThreatList();
            m_creature->CombatStop(true);
        }
        else
            m_uiEvade_Timer -= uiDiff;
    }
};

CreatureAI* GetAI_npc_ranged_target(Creature* pCreature)
{
    return new npc_ranged_targetAI(pCreature);
}

/*######
## npc_charge_target  //quests 13837,13839,13625,13677
######*/

struct MANGOS_DLL_DECL npc_charge_targetAI : public ScriptedAI
{
    npc_charge_targetAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint32 m_uiEvade_Timer;
    uint32 m_uiDefend_Timer;

    void Reset()
    {
        m_uiEvade_Timer  = 5000;
        m_uiDefend_Timer = 5000;

        SetCombatMovement(false);
    }

    void DamageTaken(Unit* pDoneBy, uint32& uiDamage) override
    {
        if (uiDamage > m_creature->GetHealth())
            uiDamage = 0;
        m_uiEvade_Timer = 5000;
    }

    void SpellHit(Unit* pCaster, const SpellEntry* pSpell) override
    {
        switch(pSpell->Id)
        {
            case 63010:
                if (!m_creature->HasAura(64100))
                {
                    if (Player* pPlayer = pCaster->GetCharmerOrOwnerPlayerOrPlayerItself())
                        pPlayer->KilledMonsterCredit(33340);
                    return;
                }
            case 64342:
                if (m_creature->HasAura(64100))
                {
                    m_creature->RemoveAurasDueToSpell(64100);
                    m_uiDefend_Timer = 5000;
                }

        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (m_uiDefend_Timer < uiDiff)
        {
            if (!m_creature->HasAura(64100))
                DoCastSpellIfCan(m_creature, 64100);
            m_uiDefend_Timer = 5000;
        }
        else
            m_uiDefend_Timer -= uiDiff;

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (m_uiEvade_Timer < uiDiff)
        {
            m_uiEvade_Timer = 5000;
            m_creature->DeleteThreatList();
            m_creature->CombatStop(true);
        }
        else
            m_uiEvade_Timer -= uiDiff;
    }
};

CreatureAI* GetAI_npc_charge_target(Creature* pCreature)
{
    return new npc_charge_targetAI(pCreature);
}

/*#####
## npc_black_knights_gryphon
#####*/
 
struct MANGOS_DLL_DECL npc_black_knights_gryphonAI : public npc_escortAI
{
    npc_black_knights_gryphonAI(Creature* pCreature) : npc_escortAI(pCreature) { Reset(); }
 
    void Reset() { }
 
    void SpellHit(Unit* pCaster, const SpellEntry* pSpell) override
    {
        if (m_creature->IsTemporarySummon())
            if (Player* pPlayer = m_creature->GetMap()->GetPlayer(((TemporarySummon*)m_creature)->GetSummonerGuid()))
                pPlayer->KilledMonsterCredit(m_creature->GetEntry(), m_creature->GetObjectGuid());
 
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetSpeedRate(MOVE_RUN, 3.0f);
        Start(true, ((Player*)pCaster));
    }
 
    void WaypointReached(uint32 uiPointId) override
    {
        switch(uiPointId)
        {
            case 0:
                SetRun();
                break;
            case 10:
                m_creature->SetLevitate(true);
                m_creature->SetSpeedRate(MOVE_RUN, 6.0f);
                break;
            case 15:
                //if (Player* pPlayer = GetPlayerForEscort())
                    //hack to prevent Player's death
                  //  pPlayer->CastSpell(pPlayer, 64505, true);
                    break;
            case 16:
                m_creature->ForcedDespawn(2000);
                return;
            default:
                break;
        }
    }
};
 
CreatureAI* GetAI_npc_black_knights_gryphon(Creature* pCreature)
{
    return new npc_black_knights_gryphonAI(pCreature);
}

/*######
## npc_scourge_conventor  //quest 14107
######*/

// grip of scourge still needs implented and used

enum QuestFate // shared enum by conventor mob and fallen hero mob
{
    QUEST_THE_FATE_OF_THE_FALLEN        = 14107,
    NPC_FALLEN_HERO_SPIRIT              = 32149,
    NPC_FALLEN_HERO_SPIRIT_PROXY        = 35055,
};

enum
{
    SPELL_CONE_OF_COLD              = 20828,
    SPELL_FORST_NOVA                = 11831,
    SPELL_FROSTBOLT                 = 20822,
    SPELL_GRIP_OF_THE_SCOURGE       = 60212,     // spell casted by mob
};

struct MANGOS_DLL_DECL npc_scourge_conventorAI : public ScriptedAI
{
    npc_scourge_conventorAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint32 m_uiConeofCold_Timer;
    uint32 m_uiFrostNova_Timer;
    uint32 m_uiFrostBolt_Timer;
    //uint32 m_uiGrip_Timer;

    void Reset()
    {
        m_uiConeofCold_Timer  = 10000;
        m_uiFrostNova_Timer    = 11000;
        m_uiFrostBolt_Timer    = 9000;
        //m_uiGrip_Timer = 10000;
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (m_uiConeofCold_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->getVictim(),SPELL_CONE_OF_COLD);
            m_uiConeofCold_Timer = 10000;
        }
        else
            m_uiConeofCold_Timer -= uiDiff;

        if (m_uiFrostNova_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->getVictim(),SPELL_FORST_NOVA);
            m_uiFrostNova_Timer = 11000;
        }
        else
            m_uiFrostNova_Timer -= uiDiff;

        if (m_uiFrostBolt_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->getVictim(),SPELL_FROSTBOLT);
            m_uiFrostBolt_Timer = 9000;
        }
        else
            m_uiFrostBolt_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_npc_scourge_conventor(Creature* pCreature)
{
    return new npc_scourge_conventorAI(pCreature);
}

/*######
## npc_fallen_hero_spirit  //quest 14107
######*/

enum
{
    SAY_BLESS_1                         = -1999819,
    SAY_BLESS_2                         = -1999820,
    SAY_BLESS_3                         = -1999821,
    SAY_BLESS_4                         = -1999822,
    SAY_BLESS_5                         = -1999823,

    SPELL_STRIKE                        = 11976,
    SPELL_BLESSING_OF_PEACE             = 66719,     //spell casted from relic of light
    GRIP_OF_THE_SCOURGE_AURA            = 60231      //might need server side spell script support (when mob has this spell it's immune to fate of light spell)
};


struct MANGOS_DLL_DECL npc_fallen_hero_spiritAI : public ScriptedAI
{
    npc_fallen_hero_spiritAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint32 m_uiStrike_Timer;

    void Reset()
    {
        m_uiStrike_Timer = 10000;
    }

    void SpellHit(Unit* pCaster, const SpellEntry* pSpell) override
    {
        // if (m_creature->HasAura(GRIP_OF_THE_SCOURGE_AURA))
        //     return fasle;

        if (pCaster->GetTypeId() == TYPEID_PLAYER && m_creature->isAlive() && ((pSpell->Id == SPELL_BLESSING_OF_PEACE)))
        {
            if (((Player*)pCaster)->GetQuestStatus(QUEST_THE_FATE_OF_THE_FALLEN) == QUEST_STATUS_INCOMPLETE)
            {
                ((Player*)pCaster)->KilledMonsterCredit(NPC_FALLEN_HERO_SPIRIT_PROXY);
                m_creature->ForcedDespawn();
                switch(urand(0, 4))
                {
                    case 0: DoScriptText(SAY_BLESS_1, m_creature); break;
                    case 1: DoScriptText(SAY_BLESS_2, m_creature); break;
                    case 2: DoScriptText(SAY_BLESS_3, m_creature); break;
                    case 3: DoScriptText(SAY_BLESS_4, m_creature); break;
                    case 4: DoScriptText(SAY_BLESS_5, m_creature); break;
                }
            }
        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (m_uiStrike_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->getVictim(),SPELL_STRIKE);
            m_uiStrike_Timer = 10000;
        }
        else
            m_uiStrike_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_npc_fallen_hero_spirit(Creature* pCreature)
{
    return new npc_fallen_hero_spiritAI(pCreature);
}

/*#####
## npc_valiants
#####*/

enum
{
    SAY_DEFEATED          = -1999824,
    SPELL_VCHARGE         = 63010,
    SPELL_VSHIELDBREAKER  = 65147,

    SPELL_MOUNTED_MELEE_VICTORY = 62724,
};

struct MANGOS_DLL_DECL npc_valiantsAI : public ScriptedAI
{
   npc_valiantsAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    //uint32 m_uiVCHARGE_Timer;
    //uint32 m_uiVSHIELDBREAKER_Timer;

    void Reset()
    {
       //m_uiVCHARGE_Timer          = 2000;  need correct timers
       //m_uiVSHIELDBREAKER_Timer   = 5000;  need correct timers
    }

    void DamageTaken(Unit* pDoneBy, uint32& uiDamage) override
    {
        if (uiDamage > m_creature->GetHealth())
        {
            uiDamage = 5;

            if (Unit* pPlayer = pDoneBy->GetCharmerOrOwnerPlayerOrPlayerItself())
                pPlayer->CastSpell(pPlayer, SPELL_MOUNTED_MELEE_VICTORY, true);

            DoScriptText(SAY_DEFEATED, m_creature);
            EnterEvadeMode();
        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
       /* {    STILL HAVE ATTACK SPELLS TO DO
        }*/

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_valiants(Creature* pCreature)
{
    return new npc_valiantsAI(pCreature);
}

/*#####
## npc_champions
#####*/

enum
{
    // spells are defined above
    SPELL_CHAMP_MOUNTED_MELEE_VICTORY = 63596,
};

struct MANGOS_DLL_DECL npc_championsAI : public ScriptedAI
{
   npc_championsAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    //uint32 m_uiVCHARGE_Timer;
    //uint32 m_uiVSHIELDBREAKER_Timer;

    void Reset()
    {
       //m_uiVCHARGE_Timer          = 2000;  need correct timers
       //m_uiVSHIELDBREAKER_Timer   = 5000;  need correct timers
    }

    void DamageTaken(Unit* pDoneBy, uint32& uiDamage) override
    {
        if (uiDamage > m_creature->GetHealth())
        {
            uiDamage = 5;

            if (Unit* pPlayer = pDoneBy->GetCharmerOrOwnerPlayerOrPlayerItself())
                pPlayer->CastSpell(pPlayer, SPELL_CHAMP_MOUNTED_MELEE_VICTORY, true);

            DoScriptText(SAY_DEFEATED, m_creature);
            EnterEvadeMode();
        }
    }

    void UpdateAI(const uint32 uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
       /* {    STILL HAVE ATTACK SPELLS TO DO
        }*/

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_champions(Creature* pCreature)
{
    return new npc_championsAI(pCreature);
}

/*######
## npc_saronite_mine_slave
######*/

enum
{
    SAY_MINER_SUICIDE_1                 = -1001117,
    SAY_MINER_SUICIDE_2                 = -1001118,
    SAY_MINER_SUICIDE_3                 = -1001119,
    SAY_MINER_SUICIDE_4                 = -1001120,
    SAY_MINER_SUICIDE_5                 = -1001121,
    SAY_MINER_SUICIDE_6                 = -1001122,
    SAY_MINER_SUICIDE_7                 = -1001123,
    SAY_MINER_SUICIDE_8                 = -1001124,

    GOSSIP_ITEM_SLAVE_FREE              = -3000113,
    TEXT_ID                             = 14068,

    NPC_SARONITE_KILL_CREDIT_BUNNY      = 31866,

    FACTION_HOSTILE                     = 14,

    QUEST_SLAVES_TO_SARONITE_A          = 13300,
    QUEST_SLAVES_TO_SARONITE_H          = 13302,
};

static const float afPointSlaveSalvation[3] = {7030.59f, 1866.73f, 533.94f};
static const float afPointSlaveSuicide1[3] = {6965.99f, 2051.44f, 519.49f};
static const float afPointSlaveSuicide2[3] = {6920.47f, 1973.46f, 523.38f};
static const float afPointSlaveSuicide3[3] = {6915.35f, 2026.35f, 518.53f};

bool GossipHello_npc_saronite_mine_slave(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_SLAVES_TO_SARONITE_A) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(QUEST_SLAVES_TO_SARONITE_H) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, GOSSIP_ITEM_SLAVE_FREE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    pPlayer->SEND_GOSSIP_MENU(TEXT_ID, pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_npc_saronite_mine_slave(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction != GOSSIP_ACTION_INFO_DEF + 1)
        return false;

    pPlayer->CLOSE_GOSSIP_MENU();

    switch (urand(0, 5))
    {
        case 0:
        case 1:
        case 2:
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            pPlayer->KilledMonsterCredit(NPC_SARONITE_KILL_CREDIT_BUNNY);

            pCreature->SetWalk(false);
            pCreature->GetMotionMaster()->MovePoint(0, afPointSlaveSalvation[0], afPointSlaveSalvation[1], afPointSlaveSalvation[2]);
            pCreature->ForcedDespawn(20000);
            break;
        case 3:
        case 4:
            pCreature->SetFactionTemporary(FACTION_HOSTILE, TEMPFACTION_RESTORE_RESPAWN | TEMPFACTION_RESTORE_REACH_HOME);
            pCreature->AI()->AttackStart(pPlayer);
            break;
        case 5:
            switch (urand(0, 7))
            {
                case 0: DoScriptText(SAY_MINER_SUICIDE_1, pCreature); break;
                case 1: DoScriptText(SAY_MINER_SUICIDE_2, pCreature); break;
                case 2: DoScriptText(SAY_MINER_SUICIDE_3, pCreature); break;
                case 3: DoScriptText(SAY_MINER_SUICIDE_4, pCreature); break;
                case 4: DoScriptText(SAY_MINER_SUICIDE_5, pCreature); break;
                case 5: DoScriptText(SAY_MINER_SUICIDE_6, pCreature); break;
                case 6: DoScriptText(SAY_MINER_SUICIDE_7, pCreature); break;
                case 7: DoScriptText(SAY_MINER_SUICIDE_8, pCreature); break;
            }

            pCreature->SetWalk(false);
            switch (urand(0, 2))
            {
                case 0:
                    pCreature->GetMotionMaster()->MovePoint(0, afPointSlaveSuicide1[0], afPointSlaveSuicide1[1], afPointSlaveSuicide1[2]);
                    break;
                case 1:
                    pCreature->GetMotionMaster()->MovePoint(0, afPointSlaveSuicide2[0], afPointSlaveSuicide2[1], afPointSlaveSuicide2[2]);
                    break;
                 case 2:
                    pCreature->GetMotionMaster()->MovePoint(0, afPointSlaveSuicide3[0], afPointSlaveSuicide3[1], afPointSlaveSuicide3[2]);
                    break;
            }
            pCreature->ForcedDespawn(20000);
            break;
    }

    return true;
}

void AddSC_icecrown()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "npc_melee_target";
    pNewScript->GetAI = &GetAI_npc_melee_target;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_ranged_target";
    pNewScript->GetAI = &GetAI_npc_ranged_target;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_charge_target";
    pNewScript->GetAI = &GetAI_npc_charge_target;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_saronite_mine_slave";
    pNewScript->pGossipHello = &GossipHello_npc_saronite_mine_slave;
    pNewScript->pGossipSelect = &GossipSelect_npc_saronite_mine_slave;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_black_knights_gryphon";
    pNewScript->GetAI = &GetAI_npc_black_knights_gryphon;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_scourge_conventor";
    pNewScript->GetAI = &GetAI_npc_scourge_conventor;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_fallen_hero_spirit";
    pNewScript->GetAI = &GetAI_npc_fallen_hero_spirit;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_valiants";
    pNewScript->GetAI = &GetAI_npc_valiants;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_champions";
    pNewScript->GetAI = &GetAI_npc_champions;
    pNewScript->RegisterSelf();
}
