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
    InputManager* mInput;
    Timer* mTimer;
    GameEntity* mPlayArea;
    PlaySideBar* mSideBar;
    Player* mPlayer;

    Texture* mBlock;

    bool mPlayGrid[18][10];
    Texture* mGridDisplay[18][10];

    int mStage;
    bool mStageStarted;

    float mLabelTimer;

    Scoreboard* mStageNumber;
    float mStageSpeedUpdate;
    int mScore = 0;

    Vector2 gridPosition;

    //float mMoveSpeed;
    //Vector2 mDropSpeed;
    //Vector2 mMove;

    //Vector2 mMoveBoundsX;
    //Vector2 mMoveBoundsY;

    //float mHeartBeat = 1.0;
    //float mHeartBeatCurrent = mHeartBeat;
    //bool mHeartBeatUpdate = false;
    //bool mInPlay;
    //bool mIsDown;
public:
    Level(int stage, PlaySideBar* sideBar, Player* player);
    ~Level();

    int Score() { return mScore; }
    void AddScore(int change);
    void StartStage();
    void CheckForLines();
    void DropLines();
    bool CheckGridTrue(int x, int y);
    void SetGridPointTrue(int x, int y, bool shape[4][4]);
    /*void HandleMovement();
    void IsDown(bool isDown);
    bool GetIsDown() { return mIsDown; }*/

    void Update() override;
    void Render() override;
};
#endif