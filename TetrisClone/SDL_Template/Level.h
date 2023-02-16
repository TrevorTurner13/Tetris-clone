#ifndef __LEVEL_H
#define __LEVEL_H
#include "PlaySideBar.h"
#include "Player.h"
#include "PlayArea.h"

class Level : public GameEntity {
public:
    enum LevelStates { Running, Finished, GameOver };
    bool mPlayGrid[18][10];
private:
    InputManager* mInput;
    AudioManager* mAudio;
    Timer* mTimer;
    GameEntity* mPlayArea;
    PlaySideBar* mSideBar;
    Player* mPlayer;

    Texture* mBlock;

    
    Texture* mGridDisplay[18][10];

    int mStage;
    bool mStageStarted;

    int mScore = 0;

    Vector2 gridPosition;

public:
    Level(int stage, PlaySideBar* sideBar, Player* player);
    ~Level();
    
    int Score() { return mScore; }
    void AddScore(int change);
    void StartStage();
    void CheckForLines();
    bool CheckGridTrue(int x, int y);
    void SetGridPointTrue(int x, int y, bool shape[4][4]);

    void Update() override;
    void Render() override;
};
#endif