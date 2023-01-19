#ifndef __LEVEL_H
#define __LEVEL_H
#include "PlaySideBar.h"
#include "Player.h"
#include "PlayArea.h"

class Level : public GameEntity {
public:
    enum LevelStates { Running, Finished, GameOver };

private:
    //const int ROWS = 18;
    //const int COLUMNS = 10;

    Timer* mTimer;
    GameEntity* mPlayArea;
    PlaySideBar* mSideBar;
    Player* mPlayer;

    Texture* mBlock;

    bool mGrid[18][10];
    Texture* mGridDisplay[18][10];

    int mStage;
    bool mStageStarted;

    float mLabelTimer;

    Scoreboard* mStageNumber;
    float mStageSpeedUpdate;

    Vector2 gridPosition;

public:
    Level(int stage, PlaySideBar* sideBar, Player* player);
    ~Level();

    void StartStage();
    void CheckForLines();
    bool CheckGridTrue(int x, int y);
    void SetGridPointTrue(int x, int y);

    void Update() override;
    void Render() override;
};
#endif