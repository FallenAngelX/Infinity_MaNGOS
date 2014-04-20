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
SDName: boss_priestess_azil
SD%Complete: 0
SDComment: Placeholder
SDCategory: Stonecore
EndScriptData */

#include "precompiled.h"
#include "stonecore.h"

struct MANGOS_DLL_DECL boss_princeless_azilAI : public ScriptedAI
{
    boss_princeless_azilAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        //m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        //m_bIsRegularMode = pCreature->GetMap()->IsRegularDifficulty();
        Reset();
    };

    void Reset() {};
};

CreatureAI* GetAI_boss_priestess_azil(Creature* pCreature)
{
    return new boss_princeless_azilAI(pCreature);
};

void AddSC_boss_priestess_azil()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_princeless_azil";
    pNewScript->GetAI = &GetAI_boss_priestess_azil;
    pNewScript->RegisterSelf();
}
