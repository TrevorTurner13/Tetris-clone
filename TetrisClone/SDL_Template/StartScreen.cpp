#include "StartScreen.h"

StartScreen::StartScreen() {
    mTimer = Timer::Instance();
    mInput = InputManager::Instance();
    mAudio = AudioManager::Instance();
    // Title Bar Entities
    mTitleBar = new GameEntity(Graphics::SCREEN_WIDTH* 0.5f, 175.0f);
    mTetrisLogo = new Texture("TetrisGameboy.png", 169, 11, 154, 48, false);

    mTitleBar->Parent(this);
    mTetrisLogo->Parent(mTitleBar);

    mTetrisLogo->Position(Graphics::SCREEN_WIDTH * 0.0f, 0.0f);
    mTetrisLogo->Scale(Vector2(6.0f, 6.0f));
    // Title Image Entities
    mTitleImage = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 463.0f);
    mTetrisImage = new Texture("TetrisGameboy.png", 169, 59, 154, 48, false);

    mTitleImage->Parent(this);
    mTetrisImage->Parent(mTitleImage);
   
    mTetrisImage->Position(Graphics::SCREEN_WIDTH * 0.0f, 0.0f);
    mTetrisImage->Scale(Vector2(6.0f, 6.0f));
    // Play Mode Entities
    mPlayModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.0f, 776.0f);
    mBackground = new Texture("TetrisGameboy.png", 166, 113, 15, 34, false);
    mOnePlayerMode = new Texture("1 Player", "emulogic.ttf", 32, { 0, 0, 0 });
    mTwoPlayerMode = new Texture("2 Player", "emulogic.ttf", 32, { 0, 0, 0 });
    mNintendoCopyright = new Texture("TetrisGameboy.png", 198, 131, 96, 8, false);
    mCursor = new Texture("Cursor.png");
   
    mPlayModes->Parent(this);
    mBackground->Parent(mPlayModes);
    mOnePlayerMode->Parent(mPlayModes);
    mTwoPlayerMode->Parent(mPlayModes);
    mNintendoCopyright->Parent(mPlayModes);
    mCursor->Parent(mPlayModes);

    mBackground->Position(Graphics::SCREEN_WIDTH * 0.5f, 0.0f);
    mBackground->Scale(Vector2(100.0f, 8.0f));
    mOnePlayerMode->Position(Graphics::SCREEN_WIDTH * 0.25f, -100.0f);
    mOnePlayerMode->Scale(Vector2(1.2f, 1.0f));
    mTwoPlayerMode->Position(Graphics::SCREEN_WIDTH * 0.75f, -100.0f);
    mTwoPlayerMode->Scale(Vector2(1.2f, 1.0f));
    mNintendoCopyright->Position(Graphics::SCREEN_WIDTH * 0.5f, 0.0f);
    mNintendoCopyright->Scale(Vector2(6.0f, 5.0f));
    mCursor->Position(Graphics::SCREEN_WIDTH * 0.05f, -100.0f);

    mCursorStartPos = mCursor->Position(Local);
    mCursorOffset = Vector2(Graphics::SCREEN_WIDTH * 0.5f, 0.0f);
    mSelectedMode = 0;

}

StartScreen::~StartScreen() {
    delete mTitleBar;
    mTitleBar = nullptr;
    delete mTetrisLogo;
    mTetrisLogo = nullptr;

    delete mTitleImage;
    mTitleImage = nullptr;
    delete mTetrisImage;
    mTetrisImage = nullptr;

    // play mode entities
    delete mPlayModes;
    mPlayModes = nullptr;
    delete mBackground;
    mBackground = nullptr;
    delete mOnePlayerMode;
    mOnePlayerMode = nullptr;
    delete mTwoPlayerMode;
    mTwoPlayerMode = nullptr;
    delete mNintendoCopyright;
    mNintendoCopyright = nullptr;
    delete mCursor;
    mCursor = nullptr;

}

void StartScreen::Update() {
    if (mInput->KeyPressed(SDL_SCANCODE_LEFT)) {
        ChangeSelectedMode(1);
    }
    else if (mInput->KeyPressed(SDL_SCANCODE_RIGHT)) {
        ChangeSelectedMode(-1);
    }

    mTitleBar->Update();
    mTitleImage->Update();
    mPlayModes->Update();
}


void StartScreen::Render() {
    mTetrisLogo->Render();
    mTetrisImage->Render();
    mBackground->Render();
    mOnePlayerMode->Render();
    mTwoPlayerMode->Render();
    mNintendoCopyright->Render();
    mCursor->Render();

}

void StartScreen::ChangeSelectedMode(int change) {
    mSelectedMode += change;

    if (mSelectedMode < 0) {
        mSelectedMode = 1;
    }
    else if (mSelectedMode > 1) {
        mSelectedMode = 0;
    }

    mCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}
