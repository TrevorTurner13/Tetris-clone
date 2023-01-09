#ifndef __NINTENDOSCREEN_H
#define __NINTENDOSCREEN_H
#include "Texture.h"
#include "AudioManager.h"
#include "Timer.h"

using namespace SDLFramework;

class NintendoScreen : public GameEntity {

private:
    Timer* mTimer;
    AudioManager* mAudio;

    GameEntity* mNintendoScreen;
    Texture* mBackground;
    Texture* mNintendoLogo;

    // Screen Animation Variables
    Vector2 mAnimationStartPos;
    Vector2 mAnimationEndPos;
    float mAnimationTotalTime;
    float mAnimationTimer;
    bool mAnimationDone;


public:
    NintendoScreen();
    ~NintendoScreen();

    void Update() override;
    void Render() override;


};
#endif