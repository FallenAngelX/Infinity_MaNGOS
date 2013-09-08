/* Copyright (C) 2006 - 2013 ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2011 - 2013 MangosR2 <http://github.com/mangosR2/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_SCARLETM_H
#define DEF_SCARLETM_H

enum
{
    MAX_ENCOUNTER                   = 2,

    TYPE_MOGRAINE_AND_WHITE_EVENT   = 1,
    TYPE_HALLOWSEND_EVENT           = 6,

    NPC_MOGRAINE                    = 3976,
    NPC_WHITEMANE                   = 3977,
    NPC_VORREL                      = 3981,
    NPC_INTERROGATOR_VISHAS         = 3983,

    NPC_HEAD                        = 23775,
    NPC_PUMPKIN_FIEND               = 23545,
    NPC_HEADLESS_HORSEMAN           = 23682,

    GO_WHITEMANE_DOOR               = 104600,

    SAY_TRIGGER_VORREL              = -1189015,
};

class MANGOS_DLL_DECL instance_scarlet_monastery : public ScriptedInstance
{
    public:
        instance_scarlet_monastery(Map* pMap);

        void Initialize() override;

        void OnCreatureCreate(Creature* pCreature) override;
        void OnCreatureDeath(Creature* pCreature) override;
        void OnObjectCreate(GameObject* pGo) override;

        void SetData(uint32 uiType, uint32 uiData) override;
        uint32 GetData(uint32 uiData) const override;

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
};

#endif
