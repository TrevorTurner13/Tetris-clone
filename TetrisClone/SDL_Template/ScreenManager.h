#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H
#include "StartScreen.h"
#include "NintendoScreen.h"
#include "Legal.h"
#include "PlayScreen.h"

class ScreenManager {
private:
    static ScreenManager* sInstance;

    enum Screens { NINTENDO, LEGAL, START, PLAY };
    Screens mCurrentScreen;

    InputManager* mInput;
    AudioManager* mAudio;

    NintendoScreen* mNintendoScreen;
    LegalScreen* mLegalScreen;
    StartScreen* mStartScreen;
    PlayScreen* mPlayScreen;

public:
    static ScreenManager* Instance();
    static void Release();

    void Update();
    void Render();

private:
    ScreenManager();
    ~ScreenManager();
};
#endif
