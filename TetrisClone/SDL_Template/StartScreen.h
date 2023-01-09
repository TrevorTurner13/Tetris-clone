#ifndef __STARTSCREEN_H
#define __STARTSCREEN_H
#include "Texture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Timer.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {

private:
    Timer* mTimer;
    InputManager* mInput;
    AudioManager* mAudio;
    // Title bar Entities
    GameEntity* mTitleBar;
    Texture* mTetrisLogo;
    // Title Image Entities
    GameEntity* mTitleImage;
    Texture* mTetrisImage;
    // Play Mode Entities
    GameEntity* mPlayModes;
    Texture* mBackground;
    Texture* mOnePlayerMode;
    Texture* mTwoPlayerMode;
    Texture* mNintendoCopyright;
    Texture* mCursor;

    Vector2 mCursorStartPos;
    Vector2 mCursorOffset;
    int mSelectedMode;


public:
    StartScreen();
    ~StartScreen();

    void ChangeSelectedMode(int change);

    void Update() override;
    void Render() override;

};
#endif