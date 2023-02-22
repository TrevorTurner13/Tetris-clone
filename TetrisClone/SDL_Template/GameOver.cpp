#include "GameOver.h"

GameOver::GameOver() {
	mAudio = AudioManager::Instance();
	mInput = InputManager::Instance();

    mColor = { 0, 0, 0 };

    mGameOver = new GameEntity(Graphics::SCREEN_WIDTH * 0.0f, Graphics::SCREEN_HEIGHT * 0.0f);
    mGameOver->Parent(this);

    mSideBar = new PlaySideBar();
    mSideBar->Parent(this);
    mSideBar->Position(Graphics::SCREEN_WIDTH * 0.825f, Graphics::SCREEN_HEIGHT * 0.5f);

    mPlayArea = new PlayArea();
    mPlayArea->Parent(mGameOver);
    mPlayArea->Position(Graphics::SCREEN_WIDTH * 0.325f, Graphics::SCREEN_HEIGHT * 0.5f);

    mGameOverTexture = new Texture("GameOver.jpg", 1, 2, 172, 149);
    mGameOverTexture->Parent(this);
    mGameOverTexture->Position(325.0f, 200.0f);
    mGameOverTexture->Scale(Vector2(1.55f, 1.55f));

    mPlease = new Texture("PLEASE", "emulogic.ttf", 32, mColor);
    mPlease->Parent(this);
    mPlease->Position(250.0f, 400.0f);

    mTry = new Texture("TRY", "emulogic.ttf", 32, mColor);
    mTry->Parent(this);
    mTry->Position(350.0f, 450.0f);

    mAgain = new Texture("AGAIN", "emulogic.ttf", 32, mColor);
    mAgain->Parent(this);
    mAgain->Position(450.0f, 500.0f);

    mContinue = new Texture("CONTINUE?", "emulogic.ttf", 32, mColor);
    mContinue->Parent(this);
    mContinue->Position(250.0f, 600.0f);

    mYes = new Texture("YES: ENTER", "emulogic.ttf", 32, mColor);
    mYes->Parent(this);
    mYes->Position(290.0f, 700.0f);

    mNo = new Texture("NO: ESCAPE", "emulogic.ttf", 32, mColor);
    mNo->Parent(this);
    mNo->Position(300.0f, 800.0f);

    mCursor = new Texture("Cursor.png");
    mCursor->Position(Graphics::SCREEN_WIDTH * 0.05f, -100.0f);
    mCursor->Parent(mGameOver);
    mCursorStartPos = mCursor->Position(Local);
    mCursorOffset = Vector2(Graphics::SCREEN_WIDTH * 0.5f, 0.0f);
    mSelectedMode = 0;

}

GameOver::~GameOver() {
    delete mNo;
    mNo = nullptr;

    delete mYes;
    mYes = nullptr;
    
    delete mContinue;
    mContinue = nullptr;
    
    delete mAgain;
    mAgain = nullptr;
    
    delete mTry;
    mTry = nullptr;
    
    delete mPlease;
    mPlease = nullptr;
    
    delete mGameOverTexture;
    mGameOverTexture = nullptr;
    
    delete mPlayArea;
    mPlayArea = nullptr;
    
    delete mSideBar;
    mSideBar = nullptr;
    
    delete mGameOver;
    mGameOver = nullptr;
}

void GameOver::Update() {
    if (mInput->KeyPressed(SDL_SCANCODE_LEFT)) {
        mAudio->PlaySFX("SFX/Tetris (GB) (17)-menu_sound.wav", 0, -1);
        ChangeSelectedMode(1);

    }
    else if (mInput->KeyPressed(SDL_SCANCODE_RIGHT)) {
        mAudio->PlaySFX("SFX/Tetris (GB) (17)-menu_sound.wav", 0, -1);
        ChangeSelectedMode(-1);

    }

}

void GameOver::Render() {
    mGameOver->Render();
    mSideBar->Render();
    mPlayArea->Render();
    mGameOverTexture->Render();
    mPlease->Render();
    mTry->Render();
    mAgain->Render();
    mContinue->Render();
    mYes->Render();
    mNo->Render();
}

void GameOver::ChangeSelectedMode(int change) {
    mSelectedMode += change;

    if (mSelectedMode < 0) {
        mSelectedMode = 1;
    }
    else if (mSelectedMode > 1) {
        mSelectedMode = 0;
    }

    mCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}