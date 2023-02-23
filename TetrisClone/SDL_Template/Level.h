#ifndef __LEVEL_H
#define __LEVEL_H
#include "PlaySideBar.h"
#include "Player.h"
#include "PlayArea.h"

class Level : public GameEntity {
public:
    bool mPlayGrid[18][10];
private:
    InputManager* mInput;
    AudioManager* mAudio;
    Timer* mTimer;

    PlaySideBar* mSideBar;
    Texture* mBlock;
    Texture* mGridDisplay[18][10];
   
    int mStage;
    bool mStageStarted;

    int mScore;

    bool mLevelGameOver;
    
    float mGameOverTimer;
    float mGameOverCurrent;
    bool mGameOverUpdate;
    int mGameOverRow;

public:
    Level(int stage, PlaySideBar* sideBar);
    ~Level();
    
    int Score() { return mScore; }
    int GetGameOverRow() { return mGameOverRow; }
    void AddScore(int change);
    void StartStage();
    void CheckForLines();
    bool CheckGridTrue(int x, int y);
    void SetGridPointTrue(int x, int y, bool shape[4][4]);

    void SetLevelGameOver(bool gameOver);
    void GameOverGridSet();

    void Update() override;
    void Render() override;
};
#endif