/* Copyright (C) 2010 /dev/rsa for ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: boss_zarithrian
SD%Complete: 90%
SDComment: by /dev/rsa && notagain && ukulutl
SDCategory: Ruby Sanctum
EndScriptData */

// Need correct timers

#include "precompiled.h"
#include "ruby_sanctum.h"

enum BossSpells
{
    SPELL_CALL_FLAMECALLER           = 74398,
    SPELL_CLEAVE_ARMOR               = 74367,
    SPELL_IMTIMIDATING_ROAR          = 74384,
    SPELL_LAVA_GOUT                  = 74394,
    SPELL_BLAST_NOVA                 = 74392,

    NPC_FLAMECALLER                  = 39814,
};

enum Equipment
{
    EQUIP_MAIN           = 47156,
    EQUIP_OFFHAND        = 51812,
    EQUIP_RANGED         = EQUIP_NO_CHANGE,
    EQUIP_DONE           = EQUIP_NO_CHANGE,
};

static Locations SpawnLoc[]=
{
    {3008.552734f, 530.471680f, 89.195290f},     // 0 - Zarithrian start point, o = 6,16
    {3014.313477f, 486.453735f, 89.255096f},     // 1 - Mob spawn 1
    {3025.324951f, 580.588501f, 88.593185f},     // 2 - Mob spawn 2
};

enum
{
    SAY_AGGRO           = -1666200,
    SAY_SLAY_1          = -1666201,
    SAY_SLAY_2          = -1666202,
    SAY_DEATH           = -1666203,
    SAY_SUMMON          = -1666204,
};

#define FLAMECALLTIME 25000
#define CLEAVEARMORTIME 10000
#define IMTIMIDATINGROARTIME 15000

struct MANGOS_DLL_DECL boss_zarithrianAI : public ScriptedAI
{
    boss_zarithrianAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance *pInstance;
    
    uint32 m_uiCallFlamecallerTimer;
    uint32 m_uiCleaveArmorTimer;
    uint32 m_uiImtimidatingRoarTimer;

    void Reset()
    {
        if(!pInstance)
            return;

        m_uiCallFlamecallerTimer = FLAMECALLTIME;
        m_uiCleaveArmorTimer = CLEAVEARMORTIME;
        m_uiImtimidatingRoarTimer = IMTIMIDATINGROARTIME;

        if (m_creature->isAlive())
        {
            pInstance->SetData(TYPE_ZARITHRIAN, NOT_STARTED);
            //m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }
    }

    void MoveInLineOfSight(Unit* pWho)
    {
        ScriptedAI::MoveInLineOfSight(pWho);

        /*if (        pInstance->GetData(TYPE_XERESTRASZA) == DONE 
             &&     pInstance->GetData(TYPE_BALTHARUS) == DONE 
             &&     pInstance->GetData(TYPE_RAGEFIRE) == DONE
        ){   
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }   */    
    }

    void KilledUnit(Unit* pVictim)
    {
        switch (urand(0,1))
        {
            case 0:
                DoScriptText(SAY_SLAY_1,m_creature,pVictim);
                break;

            case 1:
                DoScriptText(SAY_SLAY_2,m_creature,pVictim);
                break;
        }
    }

    void JustReachedHome()
    {
        if (!pInstance) 
            return;

        pInstance->SetData(TYPE_ZARITHRIAN, FAIL);
    }

    void JustSummoned(Creature* summoned)
    {
        if(!pInstance || !summoned) 
            return;

        summoned->SetInCombatWithZone();

        /*if (Unit* pTarget = doSelectRandomPlayerAtRange(60.0f))
        {
            summoned->AddThreat(pTarget, 100.0f);
            summoned->GetMotionMaster()->MoveChase(pTarget);
        }*/

    }

    void Aggro(Unit *who)
    {
        if(!pInstance) 
            return;

        SetEquipmentSlots(false, EQUIP_MAIN, EQUIP_OFFHAND, EQUIP_RANGED);
        pInstance->SetData(TYPE_ZARITHRIAN, IN_PROGRESS);
        DoScriptText(SAY_AGGRO,m_creature);
    }

    void JustDied(Unit *killer)
    {
        if(!pInstance) 
            return;

        pInstance->SetData(TYPE_ZARITHRIAN, DONE);
        DoScriptText(SAY_DEATH,m_creature);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        /** Summon Flamecaller **/
        if (m_uiCallFlamecallerTimer <= uiDiff)
        {
            Creature *flamecaller1 = m_creature->SummonCreature(NPC_FLAMECALLER, SpawnLoc[1].x, SpawnLoc[1].y, SpawnLoc[1].z, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 2000);
            Creature *flamecaller2 = m_creature->SummonCreature(NPC_FLAMECALLER, SpawnLoc[2].x, SpawnLoc[2].y, SpawnLoc[2].z, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 2000);

            if(flamecaller1 && flamecaller2)
            {
                DoScriptText(SAY_SUMMON,m_creature);
                m_uiCallFlamecallerTimer = FLAMECALLTIME;
            }
        }
        else m_uiCallFlamecallerTimer -= uiDiff;

        /** Cleave Armor **/
        if (m_uiCleaveArmorTimer <= uiDiff)
        {
            if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_CLEAVE_ARMOR) == CAST_OK)
            {
                m_uiCleaveArmorTimer = CLEAVEARMORTIME;
            }
        }
        else m_uiCleaveArmorTimer -= uiDiff;

        /** Imtimidating Roar **/
        if (m_uiImtimidatingRoarTimer <= uiDiff)
        {
            if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_IMTIMIDATING_ROAR) == CAST_OK)
            {
                m_uiImtimidatingRoarTimer = IMTIMIDATINGROARTIME;
            }
        }
        else m_uiImtimidatingRoarTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_zarithrian(Creature* pCreature)
{
    return new boss_zarithrianAI(pCreature);
};

#define LAVAGOUTTIME 3000
#define BLASTNOVATIME 10000

struct MANGOS_DLL_DECL mob_flamecaller_rubyAI : public ScriptedAI
{
    mob_flamecaller_rubyAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());
        Reset();
    }

    ScriptedInstance *pInstance;
    uint32 m_uiLavaGoutTimer;
    uint32 m_uiBlastNovaTimer;

    void Reset()
    {
        if(!pInstance) 
            return;

        m_creature->SetRespawnDelay(7*DAY);
        m_uiLavaGoutTimer = LAVAGOUTTIME;
        m_uiBlastNovaTimer = BLASTNOVATIME;
    }

    void UpdateAI(const uint32 uiDiff)
    {

        if (pInstance && pInstance->GetData(TYPE_ZARITHRIAN) != IN_PROGRESS)
            m_creature->ForcedDespawn();

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        /** Blast Nova **/
        if (m_uiBlastNovaTimer <= uiDiff)
        {
            if(DoCastSpellIfCan(m_creature, SPELL_BLAST_NOVA) == CAST_OK)
            {
                m_uiBlastNovaTimer = BLASTNOVATIME;
            }
        }
        else m_uiBlastNovaTimer -= uiDiff;

        /** Lava Gout **/
        if (m_uiLavaGoutTimer <= uiDiff)
        {
            if(DoCastSpellIfCan(m_creature->getVictim(), SPELL_LAVA_GOUT) == CAST_OK)
            {
                m_uiLavaGoutTimer = LAVAGOUTTIME;
            }
        }
        else m_uiLavaGoutTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_flamecaller_ruby(Creature* pCreature)
{
    return new mob_flamecaller_rubyAI(pCreature);
};

void AddSC_boss_zarithrian()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_zarithrian";
    newscript->GetAI = &GetAI_boss_zarithrian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_flamecaller_ruby";
    newscript->GetAI = &GetAI_mob_flamecaller_ruby;
    newscript->RegisterSelf();
}
