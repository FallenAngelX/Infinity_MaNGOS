#ifndef MAZE_MANAGER_H
#define MAZE_MANAGER_H

#include "Policies/Singleton.h"
#include "SharedDefines.h"

struct MazeCell
{
    bool bVisited;
    bool bTopWall;
    bool bBotWall;
    bool bLeftWall;
    bool bRightWall;
    bool bWall;
};

class MazeMgr
{
    public:
        MazeMgr();
        ~MazeMgr();

        void Initialize(uint8 uiSize);
        void GenerateMaze(uint8 uiStartCellX, uint8 uiStartCellY);
        void AddMazeToWorld(Player* pCreator, bool bSmallBoxes = true, uint8 uiHeightLevel = 0);
        void AddGameObject(Map* pMap, uint32 uiPhaseMask, const GameObjectInfo* pInfo, float fPositionX, float fPositionY, float fPositionZ);
        void DeleteMazeData();
        void Undo(Map* pMap);

    private:
        uint8 m_uiSize;
        MazeCell** m_Maze;
        std::list<ObjectGuid> m_UndoGuids;
};

#define sMazeMgr MaNGOS::Singleton<MazeMgr>::Instance()
#endif
