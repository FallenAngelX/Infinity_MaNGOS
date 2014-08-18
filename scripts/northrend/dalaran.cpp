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
SDName: Dalaran
SD%Complete: 100
SDComment:
SDCategory: Dalaran
EndScriptData */

/* ContentData
npc_dalaran_guardian_mage
npc_minigob_manabonk
EndContentData */

#include "precompiled.h"
#include "Mail.h"

/*#####
# npc_dalaran_guardian_mage
#####*/

enum
{
    SPELL_TRESPASSER_H          = 54028,
    SPELL_TRESPASSER_A          = 54029,

    // Exception auras - used for quests 20439 and 24451
    SPELL_COVENANT_DISGUISE_1   = 70971,
    SPELL_COVENANT_DISGUISE_2   = 70972,
    SPELL_SUNREAVER_DISGUISE_1  = 70973,
    SPELL_SUNREAVER_DISGUISE_2  = 70974,

    AREA_ID_SUNREAVER           = 4616,
    AREA_ID_SILVER_ENCLAVE      = 4740
};

struct MANGOS_DLL_DECL npc_dalaran_guardian_mageAI : public ScriptedAI
{
    npc_dalaran_guardian_mageAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    void Reset() override {}
    void AttackedBy(Unit* /*pAttacker*/) override {}

    void MoveInLineOfSight(Unit* pWho) override
    {
        if (m_creature->GetDistanceZ(pWho) > CREATURE_Z_ATTACK_RANGE)
            return;

        if (pWho->isTargetableForAttack() && m_creature->IsHostileTo(pWho))
        {
            // exception for quests 20439 and 24451
            if (pWho->HasAura(SPELL_COVENANT_DISGUISE_1) || pWho->HasAura(SPELL_COVENANT_DISGUISE_2) ||
                    pWho->HasAura(SPELL_SUNREAVER_DISGUISE_1) || pWho->HasAura(SPELL_SUNREAVER_DISGUISE_2))
                return;

            if (m_creature->IsWithinDistInMap(pWho, m_creature->GetAttackDistance(pWho)) && m_creature->IsWithinLOSInMap(pWho))
            {
                if (Player* pPlayer = pWho->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    // it's mentioned that pet may also be teleported, if so, we need to tune script to apply to those in addition.

                    if (pPlayer->GetAreaId() == AREA_ID_SILVER_ENCLAVE)
                        DoCastSpellIfCan(pPlayer, SPELL_TRESPASSER_A);
                    else if (pPlayer->GetAreaId() == AREA_ID_SUNREAVER)
                        DoCastSpellIfCan(pPlayer, SPELL_TRESPASSER_H);
                }
            }
        }
    }

    void UpdateAI(uint32 const /*uiDiff*/) override {}

    static CreatureAI* GetAI(Creature* pCreature)
    {
        return new npc_dalaran_guardian_mageAI(pCreature);
    }
};

/*#####
# npc_minigob_manabonk
#####*/

enum
{
    ZONE_DALARAN            = 4395,

    SPELL_MANABONKED        = 61834,
    SPELL_TELEPORT_VISUAL   = 51347,
    SPELL_IMPROVED_BLINK    = 61995,

    MAIL_MINIGOB_ENTRY      = 264,
};

struct MANGOS_DLL_DECL npc_minigob_manabonkAI : public ScriptedAI
{
    npc_minigob_manabonkAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    TTimer m_eventTimer;
    uint32 m_eventStage;

    void Reset() override
    {
        self->SetVisibility(VISIBILITY_OFF);

        m_eventTimer.Reset(1000);
        m_eventStage = 0;
    }

    Player* SelectPlayerInDalaran()
    {
        std::list<Player*> lPlayers;

        Map::PlayerList const& players = self->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            if (Player* pPlayer = itr->getSource())
            {
                if (pPlayer->GetZoneId() == ZONE_DALARAN && !pPlayer->IsFlying() && !pPlayer->IsMounted() && !pPlayer->isGameMaster())
                    lPlayers.push_back(pPlayer);
            }
        }

        if (lPlayers.empty())
            return NULL;

        std::list<Player*>::iterator itr = lPlayers.begin();
        std::advance(itr, urand(0, lPlayers.size() - 1));

        return *itr;
    }

    void SendMailToPlayer(Player* pPlayer)
    {
        MailDraft(MAIL_MINIGOB_ENTRY)
            .SendMailTo(pPlayer, MailSender(MAIL_CREATURE, self->GetEntry()));
    }

    void EnterCombat(Unit* /*pEnemy*/) override {}
    void MoveInLineOfSight(Unit* /*pWho*/) override {}

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_eventTimer.IsSet() || !m_eventTimer.Expired(uiDiff))
            return;

        switch (m_eventStage)
        {
            case 0:
                if (Player* pPlayer = SelectPlayerInDalaran())
                {
                    self->SetVisibility(VISIBILITY_ON);
                    self->CastSpell(self, SPELL_TELEPORT_VISUAL, false);

                    float x, y, z;
                    pPlayer->GetClosePoint(x, y, z, 0.0f, 5.0f);
                    self->NearTeleportTo(x, y, z, -pPlayer->GetOrientation());

                    self->CastSpell(pPlayer, SPELL_MANABONKED, false);
                    SendMailToPlayer(pPlayer);
                }
                else
                {
                    m_eventTimer.Reset(0);
                    self->ForcedDespawn();
                    return;
                }

                m_eventTimer.Reset(3000);
                m_eventStage++;
                break;
            case 1:
                self->CastSpell(self, SPELL_IMPROVED_BLINK, false);

                float x, y, z;
                self->GetClosePoint(x, y, z, 0.0f, frand(15.0f, 40.0f));
                self->GetMotionMaster()->MovePoint(0, x, y, z);

                m_eventTimer.Reset(2500);
                m_eventStage++;
                break;
            case 2:
                self->CastSpell(self, SPELL_TELEPORT_VISUAL, false);

                m_eventTimer.Reset(500);
                m_eventStage++;
                break;
            case 3:
                m_eventTimer.Reset(0);

                self->SetVisibility(VISIBILITY_OFF);
                self->ForcedDespawn();
                break;
        }
    }

    static CreatureAI* GetAI(Creature* pCreature)
    {
        return new npc_minigob_manabonkAI(pCreature);
    }
};

void AddSC_dalaran()
{
    AutoScript s;
    s.newScript("npc_dalaran_guardian_mage", &npc_dalaran_guardian_mageAI::GetAI);
    s.newScript("npc_minigob_manabonk", &npc_minigob_manabonkAI::GetAI);
}
