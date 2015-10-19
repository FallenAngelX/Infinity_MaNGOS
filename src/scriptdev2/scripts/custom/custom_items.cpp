/* Copyright (C) 2009 - 2011 Project Dark-iCE <http://projectSD2.clanice.com/>
 * Copyright (C) 2015 Infinity_MaNGOS
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
SDName: custom_items
SD%Complete: 100
SDComment: Containts different custom Items. Check the code to know what they do. (Don't forget to apply SQL files!)
EndScriptData */

#include "precompiled.h"
#include "../../shared/Config/Config.h"
#include "../../config.h"
#include "Group.h"

extern DatabaseMysql WorldDatabase;
extern DatabaseType CharacterDatabase;
extern Config IMaNGOSConfig;



// Talent Points Giving Item
bool ItemUse_custom_item_talentstone(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
	Config IMaNGOSConfig;
	if (!IMaNGOSConfig.SetSource(_MANGOSD_CONFIG))
		error_log("IMaNGOS: Unable to open configuration file");

    if ((pPlayer->isInCombat()) || (pPlayer->IsTaxiFlying()) || (pPlayer->isDead()))
    {
        pPlayer->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
        return false;
    }
    else
    {
        pPlayer->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
        pPlayer->SetFreeTalentPoints(pPlayer->GetFreeTalentPoints()+(IMaNGOSConfig.GetFloatDefault("Item_TalentPointStoneAddTalents",0)));
        pPlayer->SendTalentsInfoData(false);
        return true;
    }
}

// Cooldown Removing Item
bool ItemUse_custom_item_cooldownremover(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
	Config IMaNGOSConfig;
	if (!IMaNGOSConfig.SetSource(_MANGOSD_CONFIG))
		error_log("IMaNGOS: Unable to open configuration file");

    bool CooldownRemoverInfinte = IMaNGOSConfig.GetBoolDefault("Item_CooldownRemoverInfinte", true);

    if(CooldownRemoverInfinte)
    {
        pPlayer->RemoveAllSpellCooldown();
        return false;
    }
    else
    {
        pPlayer->RemoveAllSpellCooldown();
        return true;
    }
}

// Invicible Mount Teaching Item
bool ItemUse_custom_item_invinciblemount(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
    if ((pPlayer->isInCombat()) || (pPlayer->IsTaxiFlying()) || (pPlayer->isDead()))
    {
        pPlayer->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
        return false;
    }
    else
    {
        pPlayer->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
        pPlayer->learnSpell(72284, false);
        return true;
    }
}

// Level Giving Item
bool ItemUse_custom_item_levelplayer(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
	Config IMaNGOSConfig;
	if (!IMaNGOSConfig.SetSource(_MANGOSD_CONFIG))
		error_log("IMaNGOS: Unable to open configuration file");

    if ((pPlayer->isInCombat()) || (pPlayer->IsTaxiFlying()) || (pPlayer->isDead()))
    {
        pPlayer->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
        return false;
    }
    else
    {
        if((pPlayer->getLevel()) <= (IMaNGOSConfig.GetFloatDefault("LevelUpItemSafeLevel",0)))
        {
            pPlayer->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
            pPlayer->GiveLevel((pPlayer->getLevel())+(IMaNGOSConfig.GetFloatDefault("LevelUpItemAddLevel",0)));
            return true;
        }
        else
        {
            pPlayer->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
            return false;
        }
    }
}

// Metamorphosis Teaching Item
bool ItemUse_custom_item_metamorphosisspell(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
    if ((pPlayer->isInCombat()) || (pPlayer->IsTaxiFlying()) || (pPlayer->isDead()))
    {
        pPlayer->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
        return false;
    }
    else
    {
        pPlayer->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
        pPlayer->learnSpell(59672, false);
        return true;
    }
}

// Banker NPC Summoning Item
bool ItemUse_custom_item_summonbanker(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
	Config IMaNGOSConfig;
	if (!IMaNGOSConfig.SetSource(_MANGOSD_CONFIG))
		error_log("IMaNGOS: Unable to open configuration file");

    if ((pPlayer->isInCombat()) || (pPlayer->IsTaxiFlying()) || (pPlayer->isDead()))
    {
        pPlayer->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
        return false;
    }
    else
    {
        pPlayer->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
        pPlayer->SummonCreature((IMaNGOSConfig.GetFloatDefault("Item_SummonBankerEntryID",0)),pPlayer->GetPositionX(), pPlayer->GetPositionY()+5, pPlayer->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,60000);
        return true;
    }
}

// Tele NPC Summoning Item
bool ItemUse_custom_item_summontelenpc(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
	Config IMaNGOSConfig;
	if (!IMaNGOSConfig.SetSource(_MANGOSD_CONFIG))
		error_log("IMaNGOS: Unable to open configuration file");

    if ((pPlayer->isInCombat()) || (pPlayer->IsTaxiFlying()) || (pPlayer->isDead()))
    {
        pPlayer->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
        return false;
    }
    else
    {
        pPlayer->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
        pPlayer->SummonCreature((IMaNGOSConfig.GetFloatDefault("Item_SummonTeleportMasterEntryID",0)), pPlayer->GetPositionX() ,pPlayer->GetPositionY()+5, pPlayer->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,60000);
        return true;
    }
}

// Instance reset Item
bool ItemUse_item_instance_cdremover(Player* pPlayer, Item* pItem, const SpellCastTargets &pTargets)
{
if ((pPlayer->isInCombat()) || (pPlayer->IsTaxiFlying()) || (pPlayer->isDead()))
{
pPlayer->SendEquipError(EQUIP_ERR_NOT_IN_COMBAT, pItem, NULL);
return false;
}
if (pPlayer->IsMounted())
{
pPlayer->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, pItem, NULL);
return true;
}
{

// Group *pGroup = _player->GetGroup();
//pGroup->ResetInstances(INSTANCE_RESET_ALL, true,_player);
if(pPlayer->GetGroup())
   pPlayer->GetGroup()->ResetInstances (INSTANCE_RESET_ALL, true,pPlayer);
   pPlayer->ResetInstances(INSTANCE_RESET_ALL, true);

//pPlayer->DestroyItemCount(pItem->GetEntry(),1,true);   // uncomment this to make item destory itself after use
return true;
}
}

void AddSC_custom_items()
{
    Script* pNewScript;

    pNewScript                   = new Script;
    pNewScript->Name             = "custom_item_talentstone";
    pNewScript->pItemUse         = &ItemUse_custom_item_talentstone;
    pNewScript->RegisterSelf(false);

    pNewScript                   = new Script;
    pNewScript->Name             = "custom_item_cooldownremover";
    pNewScript->pItemUse         = &ItemUse_custom_item_cooldownremover;
    pNewScript->RegisterSelf(false);

    pNewScript                   = new Script;
    pNewScript->Name             = "custom_item_invinciblemount";
    pNewScript->pItemUse         = &ItemUse_custom_item_invinciblemount;
    pNewScript->RegisterSelf(false);

    pNewScript                   = new Script;
    pNewScript->Name             = "custom_item_levelplayer";
    pNewScript->pItemUse         = &ItemUse_custom_item_levelplayer;
    pNewScript->RegisterSelf(false);

    pNewScript                   = new Script;
    pNewScript->Name             = "custom_item_metamorphosisspell";
    pNewScript->pItemUse         = &ItemUse_custom_item_metamorphosisspell;
    pNewScript->RegisterSelf(false);

    pNewScript                   = new Script;
    pNewScript->Name             = "custom_item_summonbanker";
    pNewScript->pItemUse         = &ItemUse_custom_item_summonbanker;
    pNewScript->RegisterSelf(false);

    pNewScript                   = new Script;
    pNewScript->Name             = "custom_item_summontelenpc";
    pNewScript->pItemUse         = &ItemUse_custom_item_summontelenpc;
    pNewScript->RegisterSelf(false);

    pNewScript                   = new Script;
    pNewScript->Name             = "custom_item_instance_remove";
    pNewScript->pItemUse         = &ItemUse_item_instance_cdremover;
    pNewScript->RegisterSelf(false);
}