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
SDName: boss_ozruk
SD%Complete: 0
SDComment: Placeholder
SDCategory: Stonecore
EndScriptData */

#include "precompiled.h"
#include "stonecore.h"

struct MANGOS_DLL_DECL boss_ozrukAI : public ScriptedAI
{
    boss_ozrukAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        //m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        //m_bIsRegularMode = pCreature->GetMap()->IsRegularDifficulty();
        Reset();
    };

    void Reset() {};
};

CreatureAI* GetAI_boss_ozruk(Creature* pCreature)
{
    return new boss_ozrukAI(pCreature);
};

struct MANGOS_DLL_DECL npc_ruptureAI : public ScriptedAI // 51422
{
    npc_ruptureAI(Creature* creature) : ScriptedAI(creature)
    {
        //m_pInstance = (ScriptedInstance*)creature->GetInstanceData();
        //timerAura    = 100;
    };
    void Reset() {};
};

CreatureAI* GetAI_npc_rupture(Creature* pCreature)
{
    return new npc_ruptureAI(pCreature);
};

void AddSC_boss_ozruk()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_ozruk";
    pNewScript->GetAI = &GetAI_boss_ozruk;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_rupture";
    pNewScript->GetAI = &GetAI_npc_rupture;
    pNewScript->RegisterSelf();
}
