#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Texture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Timer.h"
#include "Scoreboard.h"
#include "Blocks.h"
#include "PlaySideBar.h"
#include "Level.h"
#include "Player.h"
#include "PlayArea.h"

using namespace SDLFramework;

class PlayScreen : public GameEntity {

private:
    Timer* mTimer;
    InputManager* mInput;
    AudioManager* mAudio;

    GameEntity* mPlayScreen;
    PlaySideBar* mSideBar;
    PlayArea* mPlayArea;
    Player* mBlock;
    Player* mBlock1;
   
    bool mGameStarted;

    int mScore;

    Level* mLevel;
    bool mLevelStarted;
    int mCurrentStage;

    void StartNextLevel();
    void NextBlock();

public:
    PlayScreen();
    ~PlayScreen();

    bool GameOver();

    void StartNewGame();

    void Update() override;
    void Render() override;

};
#endif