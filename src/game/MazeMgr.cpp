#include "Common.h"
#include "ObjectMgr.h"
#include "MazeMgr.h"

MazeMgr::MazeMgr() :
m_uiSize(0),
m_Maze(NULL)
{
}

MazeMgr::~MazeMgr()
{
    DeleteMazeData();
}

void MazeMgr::Initialize(uint8 uiSize)
{
    // Alte Daten freigeben
    DeleteMazeData();

    if (uiSize < 9 || uiSize % 2 == 0)
        return;

    // Neue Groesse speichern
    m_uiSize = uiSize;

    // Unser dynamisches zweidimensionales Zellenarray
    m_Maze = new MazeCell*[uiSize];
    for (uint8 i = 0; i < uiSize; ++i)
        m_Maze[i] = new MazeCell[uiSize];

    for (uint8 i = 0; i < m_uiSize; ++i)
    {
        for (uint8 j = 0; j < m_uiSize; ++j)
        {
            m_Maze[i][j].bVisited = false;
            m_Maze[i][j].bTopWall = true;
            m_Maze[i][j].bBotWall = true;
            m_Maze[i][j].bLeftWall = true;
            m_Maze[i][j].bRightWall = true;
            m_Maze[i][j].bWall = true;
        }
    }

    for (uint8 i = 1; i < m_uiSize - 1; ++i)
    {
        for (uint8 j = 1; j < m_uiSize - 1; ++j)
        {
            m_Maze[1][j].bTopWall = false;
            m_Maze[uiSize - 2][j].bBotWall = false;
        }

        m_Maze[i][1].bLeftWall = false;
        m_Maze[i][uiSize - 2].bRightWall = false;
    }

    DEBUG_LOG("MazeMgr: Labyrinth erfolgreich mit %u Einheiten initialisiert!", uiSize);
}

void MazeMgr::GenerateMaze(uint8 uiStartCellX, uint8 uiStartCellY)
{
    // Es darf kein bereits generiertes Labyrinth nochmal uebergeneriert werden
    if (!m_uiSize || !m_Maze || !m_Maze[1][1].bWall)
        return;

    // An geraden Zellpositionen befindet sich _immer_ eine Wand
    if (!uiStartCellX || uiStartCellX % 2 == 0 ||
        !uiStartCellY || uiStartCellY % 2 == 0)
        return;

    // Anzahl der bisher besuchten Zellen
    uint32 uiVisitedCells = 1;
    // Anzahl der Zellen (Ohne Rand)
    uint32 uiTotalCells = ((m_uiSize - 1) / 2) * ((m_uiSize - 1) / 2);
    // Brauchen wir zum zuf. Generieren
    uint8 uiDirectionOrder[4] = { 0, 1, 2, 3 };

    // Startposition eintragen
    m_Maze[uiStartCellX][uiStartCellY].bVisited = true;
    m_Maze[uiStartCellX][uiStartCellY].bWall = false;

    std::stack<int> sBacktrackX;
    std::stack<int> sBacktrackY;

    // Zufallszahlengeneration aktualisieren
    srand(time(NULL));

    while (uiVisitedCells < uiTotalCells)
    {
        if ((uiStartCellY - 2 > -1 && !m_Maze[uiStartCellY - 2][uiStartCellX].bVisited && m_Maze[uiStartCellY][uiStartCellX].bTopWall && m_Maze[uiStartCellY - 2][uiStartCellX].bBotWall) ||
            (uiStartCellY + 2 < m_uiSize && !m_Maze[uiStartCellY + 2][uiStartCellX].bVisited && m_Maze[uiStartCellY][uiStartCellX].bBotWall && m_Maze[uiStartCellY + 2][uiStartCellX].bTopWall) ||
            (uiStartCellX - 2 > -1 && !m_Maze[uiStartCellY][uiStartCellX - 2].bVisited && m_Maze[uiStartCellY][uiStartCellX].bLeftWall && m_Maze[uiStartCellY][uiStartCellX - 2].bRightWall) ||
            (uiStartCellX + 2 < m_uiSize && !m_Maze[uiStartCellY][uiStartCellX + 2].bVisited && m_Maze[uiStartCellY][uiStartCellX].bRightWall && m_Maze[uiStartCellY][uiStartCellX + 2].bLeftWall))
        {
            // Zuf. Reihenfolge generieren
            for (uint8 i = 0; i < 4; ++i)
            {
                uint8 uiIdx = std::rand() % 4;

                if (uiIdx == i)
                    continue;

                uint8 uiHelp = uiDirectionOrder[i];
                uiDirectionOrder[i] = uiDirectionOrder[uiIdx];
                uiDirectionOrder[uiIdx] = uiHelp;
            }

            for (uint8 i = 0; i < 4; ++i)
            {
                /* Rauf
                 */
                if (uiDirectionOrder[i] == 0 && uiStartCellY > 1)
                {
                    if (!m_Maze[uiStartCellY - 2][uiStartCellX].bVisited)
                    {
                        m_Maze[uiStartCellY - 1][uiStartCellX].bVisited = true;
                        m_Maze[uiStartCellY - 1][uiStartCellX].bWall = false;
                        m_Maze[uiStartCellY][uiStartCellX].bTopWall = false;

                        sBacktrackX.push(uiStartCellX);
                        sBacktrackY.push(uiStartCellY);

                        uiStartCellY -= 2; // Zur naechsten Zelle
                        m_Maze[uiStartCellY][uiStartCellX].bVisited = true;
                        m_Maze[uiStartCellY][uiStartCellX].bWall = false;
                        m_Maze[uiStartCellY][uiStartCellX].bBotWall = false;

                        ++uiVisitedCells;
                    }
                    else
                        continue;
                }
                /* Runter
                 */
                else if (uiDirectionOrder[i] == 1 && uiStartCellY < m_uiSize - 2)
                {
                    if (!m_Maze[uiStartCellY + 2][uiStartCellX].bVisited)
                    {
                        m_Maze[uiStartCellY + 1][uiStartCellX].bVisited = true;
                        m_Maze[uiStartCellY + 1][uiStartCellX].bWall = false;
                        m_Maze[uiStartCellY][uiStartCellX].bBotWall = false;

                        sBacktrackX.push(uiStartCellX);
                        sBacktrackY.push(uiStartCellY);

                        uiStartCellY += 2; // Zur naechsten Zelle
                        m_Maze[uiStartCellY][uiStartCellX].bVisited = true;
                        m_Maze[uiStartCellY][uiStartCellX].bWall = false;
                        m_Maze[uiStartCellY][uiStartCellX].bTopWall = false;

                        ++uiVisitedCells;
                    }
                    else
                        continue;
                }
                /* Links
                 */
                else if (uiDirectionOrder[i] == 2 && uiStartCellX > 1)
                {
                    if (!m_Maze[uiStartCellY][uiStartCellX - 2].bVisited)
                    {
                        m_Maze[uiStartCellY][uiStartCellX - 1].bVisited = true;
                        m_Maze[uiStartCellY][uiStartCellX - 1].bWall = false;
                        m_Maze[uiStartCellY][uiStartCellX].bLeftWall = false;

                        sBacktrackX.push(uiStartCellX);
                        sBacktrackY.push(uiStartCellY);

                        uiStartCellX -= 2; // Zur naechsten Zelle
                        m_Maze[uiStartCellY][uiStartCellX].bVisited = true;
                        m_Maze[uiStartCellY][uiStartCellX].bWall = false;
                        m_Maze[uiStartCellY][uiStartCellX].bRightWall = false;

                        ++uiVisitedCells;
                    }
                    else
                        continue;
                }
                /* Rechts
                 */
                else if (uiDirectionOrder[i] == 3 && uiStartCellX < m_uiSize - 2)
                {
                    if (!m_Maze[uiStartCellY][uiStartCellX + 2].bVisited)
                    {
                        m_Maze[uiStartCellY][uiStartCellX + 1].bVisited = true;
                        m_Maze[uiStartCellY][uiStartCellX + 1].bWall = false;
                        m_Maze[uiStartCellY][uiStartCellX].bRightWall = false;

                        sBacktrackX.push(uiStartCellX);
                        sBacktrackY.push(uiStartCellY);

                        uiStartCellX += 2; // Zur naechsten Zelle
                        m_Maze[uiStartCellY][uiStartCellX].bVisited = true;
                        m_Maze[uiStartCellY][uiStartCellX].bWall = false;
                        m_Maze[uiStartCellY][uiStartCellX].bLeftWall = false;

                        ++uiVisitedCells;
                    }
                    else
                        continue;
                }
            }
        }
        else
        {
            uiStartCellX = sBacktrackX.top();
            sBacktrackX.pop();

            uiStartCellY = sBacktrackY.top();
            sBacktrackY.pop();
        }
    }

    DEBUG_LOG("MazeMgr: Labyrinth fertig generiert!");
}

void MazeMgr::AddMazeToWorld(Player* pCreator, bool bSmallBoxes, uint8 uiHeightLevel)
{
    if (!pCreator)
        return;

    Map* pMap = pCreator->GetMap();
    uint32 uiPhaseMask = pCreator->GetPhaseMask();

    const float fStepSizeX = (bSmallBoxes) ? 4.00f : 8.00f;
    const float fStepSizeY = (bSmallBoxes) ? 4.27f : 8.54f;
    const float fStepSizeZ = (bSmallBoxes) ? 4.00f : 8.00f;

    const GameObjectInfo* pWallObjectInfo[3] = { ObjectMgr::GetGameObjectInfo((bSmallBoxes) ? 600001 : 600006), ObjectMgr::GetGameObjectInfo((bSmallBoxes) ? 600002 : 600007), ObjectMgr::GetGameObjectInfo((bSmallBoxes) ? 600003 : 600008) };

    // GameobjectInfo Validate Checks
    for (uint8 i = 0; i < 3; ++i)
    {
        if (!pWallObjectInfo[i])
            return;

        if (pWallObjectInfo[i]->displayId && !sGameObjectDisplayInfoStore.LookupEntry(pWallObjectInfo[i]->displayId))
            return;
    }

    // "Undo" Liste leeren
    m_UndoGuids.clear();

    float fPositionX = pCreator->GetPositionX();
    float fPositionY = pCreator->GetPositionY();
    const float fStartPositionY = pCreator->GetPositionY();
    const float fPositionZ = pCreator->GetPositionZ() + fStepSizeZ * uiHeightLevel;

    for (uint8 i = 0; i < m_uiSize; ++i, fPositionX += fStepSizeX, fPositionY = fStartPositionY)
    {
        for (uint8 j = 0; j < m_uiSize; ++j, fPositionY += fStepSizeY)
        {
            if (m_Maze[i][j].bWall)
                AddGameObject(pMap, uiPhaseMask, pWallObjectInfo[std::rand() % 3], fPositionX, fPositionY, fPositionZ);
        }
    }

    DEBUG_LOG("MazeMgr: Labyrinth erfolgreich gesetzt! Breite: %u", m_uiSize);
}

void MazeMgr::AddGameObject(Map* pMap, uint32 uiPhaseMask, const GameObjectInfo* pInfo, float fPositionX, float fPositionY, float fPositionZ)
{
    if (!pMap || !pInfo)
        return;

    uint32 uiGameObjectLowGuid = sObjectMgr.GenerateStaticGameObjectLowGuid();
    if (!uiGameObjectLowGuid)
        return;

    GameObject* pObj = new GameObject;

    if (pObj->Create(uiGameObjectLowGuid, pInfo->id, pMap, uiPhaseMask, fPositionX, fPositionY, fPositionZ, 0.0f))
    {
        // fill the gameobject data and save to the db
        pObj->SaveToDB(pMap->GetId(), (1 << pMap->GetSpawnMode()), uiPhaseMask);

        // this will generate a new guid if the object is in an instance
        if (!pObj->LoadFromDB(uiGameObjectLowGuid, pMap))
        {
            delete pObj;
            return;
        }

        pMap->Add(pObj);
        sObjectMgr.AddGameobjectToGrid(uiGameObjectLowGuid, sObjectMgr.GetGOData(uiGameObjectLowGuid));

        m_UndoGuids.push_back(pObj->GetObjectGuid());
    }
    else
        delete pObj;
}

void MazeMgr::DeleteMazeData()
{
    for (uint8 i = 0; i < m_uiSize; ++i)
        delete[] m_Maze[i];

    delete[] m_Maze;

    m_uiSize = 0;
    m_Maze = NULL;
}

void MazeMgr::Undo(Map* pMap)
{
    if (!pMap)
        return;

    GameObject* pObj = NULL;

    for (std::list<ObjectGuid>::const_iterator itr = m_UndoGuids.begin(); itr != m_UndoGuids.end(); ++itr)
    {
        pObj = pMap->GetGameObject(*itr);

        if (pObj)
        {
            pObj->SetRespawnTime(0); // not save respawn time
            pObj->Delete();
            pObj->DeleteFromDB();
        }
    }

    m_UndoGuids.clear();

    DEBUG_LOG("MazeMgr: Letzten Schritt zurueckgesetzt.");
}
