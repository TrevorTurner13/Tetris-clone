#ifndef __LEGAL_H
#define __LEGAL_H
#include "Texture.h"
#include "AudioManager.h"
#include "Timer.h"

using namespace SDLFramework;

class LegalScreen : public GameEntity {

private:
    Timer* mTimer;
    AudioManager* mAudio;

    GameEntity* mLegalScreen;

    Texture* mLegal;

public:
    LegalScreen();
    ~LegalScreen();

    void Update() override;
    void Render() override;
};
#endif