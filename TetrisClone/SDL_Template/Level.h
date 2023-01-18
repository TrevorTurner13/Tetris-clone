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
    /*InputManager* mInput;*/
    GameEntity* mPlayArea;
    PlaySideBar* mSideBar;
    Player* mPlayer;

    /*Texture* mBlock;

    bool mGrid[18][10];
    Texture* mGridDisplay[18][10];*/

    int mStage;
    bool mStageStarted;

    float mLabelTimer;

    Scoreboard* mStageNumber;
    float mStageSpeedUpdate;

   /* float mMoveSpeed;
    Vector2 mDropSpeed;
    Vector2 mMove;

    Vector2 mMoveBoundsX;
    Vector2 mMoveBoundsY;

    float mHeartBeat = 1.0;
    float mHeartBeatCurrent = mHeartBeat;
    bool mHeartBeatUpdate = false;*/

    /*void HandleMovement();*/
    void StartStage();
    void CheckForLines();
    void CheckPlayerPosition();
    void SetGridPointTrue();

   

public:
    Level(int stage, PlaySideBar* sideBar, Player* player);
    ~Level();

    void Update() override;
    void Render() override;
};
#endif