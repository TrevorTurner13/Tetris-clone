#include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager* ScreenManager::Instance() {
    if (sInstance == nullptr) {
        sInstance = new ScreenManager();
    }

    return sInstance;
}

void ScreenManager::Release() {
    delete sInstance;
    sInstance = nullptr;
}

ScreenManager::ScreenManager() {
    mInput = InputManager::Instance();
    mAudio = AudioManager::Instance();

    mNintendoScreen = new NintendoScreen();
    mLegalScreen = new LegalScreen();
    mStartScreen = new StartScreen();
    mPlayScreen = new PlayScreen();
    mGameOver = new GameOver();
    mCurrentScreen = NINTENDO;
}

ScreenManager::~ScreenManager() {
    mInput = nullptr;
    mAudio = nullptr;

    delete mNintendoScreen;
    mNintendoScreen = nullptr;
    delete mLegalScreen;
    mLegalScreen = nullptr;
    delete mStartScreen;
    mStartScreen = nullptr;
    delete mPlayScreen;
    mPlayScreen = nullptr;
    delete mGameOver;
    mGameOver = nullptr;

}

void ScreenManager::Update() {

    switch (mCurrentScreen) {
    case NINTENDO:
        mNintendoScreen->Update();
        if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {
            mCurrentScreen = LEGAL;
        }
        break;
    case LEGAL:
        mLegalScreen->Update();
        if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {
            mCurrentScreen = START;
            mAudio->PlayMusic("Music/01. Title.mp3", -1);
        }
        break;
    case START:
        mStartScreen->Update();
        if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {
            mCurrentScreen = PLAY;
            mAudio->PauseMusic();
            mAudio->PlayMusic("Music/03. A-Type Music (Korobeiniki).mp3", -1);
            mPlayScreen->StartNewGame();
        }

        break;
    case PLAY:
        mPlayScreen->Update();
        if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
            mCurrentScreen = START;
            mAudio->PauseMusic();
            mAudio->PlayMusic("Music/01. Title.mp3", -1);
        }
        if (mPlayScreen->GetGameOver() && mPlayScreen->GetLevel()->GetGameOverRow() < 0) {
            mCurrentScreen = GAMEOVER;
            mAudio->PlayMusic("Music/18. Game Over.mp3", -1);
            mAudio->PauseMusic();
            mAudio->PlayMusic("Music/05. C-Type Music.mp3", -1);
        }

        break;

    case GAMEOVER:
        mGameOver->Update();
        if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {
            mCurrentScreen = PLAY;
            mAudio->PauseMusic();
            mAudio->PlayMusic("Music/03. A-Type Music (Korobeiniki).mp3", -1);
            mPlayScreen->StartNewGame();
        }
        if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
            mCurrentScreen = START;
            mAudio->PlayMusic("Music/01. Title.mp3", -1);
        }
      
    }
}

void ScreenManager::Render() {

    switch (mCurrentScreen) {
    case NINTENDO:
        mNintendoScreen->Render();
        break;
    case LEGAL:
        mLegalScreen->Render();
        break;
    case START:
        mStartScreen->Render();
        break;
    case PLAY:
        mPlayScreen->Render();
        break;
    case GAMEOVER:
        mGameOver->Render();
    }
}
