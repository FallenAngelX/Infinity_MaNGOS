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
SDName: icecrown_teleport
SD%Complete: 100%
SDComment: by /dev/rsa
SDCategory: Icecrown Citadel
EndScriptData */
#include "precompiled.h"
#include "icecrown_citadel.h"

enum 
{
    PORTALS_COUNT = 7
};

struct t_Locations
{
    int textNum;
    uint32 spellID;
    bool state;
    bool active;
    uint32 encounter;
};

static t_Locations PortalLoc[]=
{
    {-3631600, 70781, true,  true, TYPE_TELEPORT},
    {-3631601, 70856, false, true, TYPE_MARROWGAR},
    {-3631602, 70857, false, true, TYPE_LADY_DEATHWHISPER},
    {-3631603, 70858, false, true, TYPE_LADY_DEATHWHISPER /*TYPE_FLIGHT_WAR*/},
    {-3631604, 70859, false, true, TYPE_DEATHBRINGER_SAURFANG},
    {-3631606, 70861, false, true, TYPE_VALITHRIA},
    {-3631607, 70860, false, true, TYPE_KINGS_OF_ICC}
};


bool GOGossipSelect_go_icecrown_teleporter(Player* pPlayer, GameObject* pGo, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
        return false;

    if (pPlayer->IsInCombat()) 
        return false;

    pPlayer->CastSpell(pPlayer, PortalLoc[action].spellID, false);

    pPlayer->CLOSE_GOSSIP_MENU();
    return true;
}

bool GOGossipHello_go_icecrown_teleporter(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance* pInstance = (ScriptedInstance*)pGo->GetInstanceData();

    if (!pInstance || !pPlayer)
        return false;
    if (pPlayer->isInCombat())
        return true;

    for (uint8 i = 0; i < PORTALS_COUNT; ++i)
    {
        if (PortalLoc[i].active == true && (PortalLoc[i].state == true || pInstance->GetData(PortalLoc[i].encounter) == DONE || pPlayer->isGameMaster()))
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_TAXI, PortalLoc[i].textNum, GOSSIP_SENDER_MAIN, i);
    }

    pPlayer->SEND_GOSSIP_MENU(TELEPORT_GOSSIP_MESSAGE, pGo->GetObjectGuid());
    return true;
}

bool GOHello_go_plague_sigil(Player* pPlayer, GameObject* pGo)
{
    instance_icecrown_citadel* pInstance = (instance_icecrown_citadel*)pGo->GetInstanceData();

    if(!pInstance)
        return false;

    if (pInstance->GetData(TYPE_FESTERGUT) == DONE &&
        pInstance->GetData(TYPE_ROTFACE) == DONE)
    {
        pInstance->DoOpenDoor(GO_SCIENTIST_DOOR_ORANGE, true);
        pInstance->DoOpenDoor(GO_SCIENTIST_DOOR_GREEN, true);
        pInstance->DoOpenDoor(GO_SCIENTIST_DOOR_COLLISION);
    }
    return true;
}

bool GOHello_go_bloodwing_sigil(Player* player, GameObject* pGo)
{
    instance_icecrown_citadel* pInstance = (instance_icecrown_citadel*)pGo->GetInstanceData();

    if (!pInstance)
        return false;

    if (pInstance->GetData(TYPE_DEATHBRINGER_SAURFANG) == DONE)
        pInstance->DoOpenDoor(GO_BLOODWING_DOOR);

    return true;
}

bool GOHello_go_frostwing_sigil(Player* pPlayer, GameObject* pGo)
{
    instance_icecrown_citadel* pInstance = (instance_icecrown_citadel*)pGo->GetInstanceData();
    if (!pInstance)
        return false;

    if (pInstance->GetData(TYPE_DEATHBRINGER_SAURFANG) == DONE)
        pInstance->DoOpenDoor(GO_FROSTWING_DOOR);

    return true;
}


void AddSC_icecrown_teleporter()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "go_icecrown_teleporter";
    pNewScript->pGossipHelloGO  = &GOGossipHello_go_icecrown_teleporter;
    pNewScript->pGossipSelectGO = &GOGossipSelect_go_icecrown_teleporter;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_plague_sigil";
    pNewScript->pGOUse = &GOHello_go_plague_sigil;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_bloodwing_sigil";
    pNewScript->pGOUse = &GOHello_go_bloodwing_sigil;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_frostwing_sigil";
    pNewScript->pGOUse = &GOHello_go_frostwing_sigil;
    pNewScript->RegisterSelf();
}
