#include "PlayScreen.h"

PlayScreen::PlayScreen() {
    	
    mTimer = Timer::Instance();
    mAudio = AudioManager::Instance();
	mInput = InputManager::Instance();

    mPlayScreen = new GameEntity(Graphics::SCREEN_WIDTH * 0.0f, Graphics::SCREEN_HEIGHT * 0.0f);
    mPlayScreen->Parent(this);
    
    mSideBar = new PlaySideBar();
    mSideBar->Parent(this);
    mSideBar->Position(Graphics::SCREEN_WIDTH * 0.825f, Graphics::SCREEN_HEIGHT * 0.5f);

    mPlayArea = new PlayArea();//new Texture("TetrisBackground.png", 0, 0, 105, 144);
    mPlayArea->Parent(mPlayScreen);
    mPlayArea->Position(Graphics::SCREEN_WIDTH * 0.325f, Graphics::SCREEN_HEIGHT * 0.5f);


    mLevel = nullptr;
    mBlock = nullptr;
    mBlock1 = nullptr;

    mScore = 0;
    mCurrentStage = 0;
    mGameStarted = false;
    mLevelStarted = false;
    mGameOver = false;
}

PlayScreen::~PlayScreen() {
    mTimer = nullptr;
    mAudio = nullptr;

    delete mPlayScreen;
    mPlayScreen = nullptr;

    delete mSideBar;
    mSideBar = nullptr;

    delete mPlayArea;
    mPlayArea = nullptr;

    delete mLevel;
    mLevel = nullptr;

    delete mBlock;
    mBlock = nullptr;

    delete mBlock1;
    mBlock1 = nullptr;

}


void PlayScreen::Update() {
    mPlayArea->Update();
    mSideBar->Update();
    if (mLevel != nullptr) {
        mLevel->Update();
    }
    if (mGameStarted && !mGameOver) {
        if (!mLevelStarted) {
            StartNextLevel();
        }
        if (mCurrentStage > 0) {
            mSideBar->Update();
        }
        mBlock->Update();
        mBlock1->Update();
        if (mBlock->Active()) {
            if (mBlock->GetIsDown()) {
                mLevel->SetGridPointTrue(mBlock->pixelToGridX(mBlock->Position().x), mBlock->pixelToGridY(mBlock->Position().y), mBlock->currentShape.mGrid);
                mLevel->CheckForLines();
                NextBlock();
                mSideBar->GetLines();
                mBlock->SetHeartbeat(mSideBar->GetLevels());
                mBlock1->SetHeartbeat(mSideBar->GetLevels());
                mBlock->Update();
                mBlock1->Update();
            }
        }
        if (mBlock1->Active()) {
            if (mBlock1->GetIsDown()) {
                mLevel->SetGridPointTrue(mBlock1->pixelToGridX(mBlock1->Position().x), mBlock1->pixelToGridY(mBlock1->Position().y), mBlock1->currentShape.mGrid);
                mLevel->CheckForLines();
                NextBlock();
                mSideBar->GetLines();
                mBlock->SetHeartbeat(mSideBar->GetLevels());
                mBlock1->SetHeartbeat(mSideBar->GetLevels());
                mBlock->Update();
                mBlock1->Update();
            }
        }
    }
    else {
        if (!Mix_PlayingMusic()) {
            mGameStarted = true;
        }

    }

    if(mGameOver) {
        GameOver();
    }
   
}

void PlayScreen::Render() {
    mPlayArea->Render();
    mSideBar->Render();

    if (mGameStarted && mLevelStarted) {
        mLevel->Render();
    }
   
    if (mGameStarted && !mGameOver) {

        if (mLevelStarted) {
            mLevel->Render();
        }

        mBlock->Render();
        mBlock1->Render();
    }
    
}

void PlayScreen::StartNewGame() {
    mGameOver = false;
    //delete mPlayScreen;
    //mPlayScreen = nullptr;
    //mPlayScreen = new PlayScreen;
    mSideBar->SetLines(0);
    mSideBar->SetLevel(mSideBar->GetLines());
    mGameStarted = true;
    mLevelStarted = false;
    mCurrentStage = 0;

    delete mBlock;
    mBlock = new Player();
    mBlock->Parent(this);
    mBlock->Position(309.0f, 24.0f);
    mBlock->Active(true);  

    delete mBlock1;
    mBlock1 = new Player();
    if (mBlock1->IShape()) {
        mBlock1->Position(750.0f, 710.0f);
    }
    else {
        mBlock1->Position(780.0f, 695.0f);
    }
    mBlock1->Parent(this);
    mBlock1->Position(780.0, 695.0f);
    mBlock1->Active(false);

    mSideBar->SetScore(0);
    mSideBar->SetLines(0);
    mSideBar->SetLevel(0);
}

void PlayScreen::StartNextLevel() {
    mCurrentStage += 1;
    mLevelStarted = true;

    delete mLevel;
    mLevel = new Level(mCurrentStage, mSideBar, mBlock);

    mBlock->SetCopyGrid(mLevel->mPlayGrid);
    mBlock1->SetCopyGrid(mLevel->mPlayGrid);
}

void PlayScreen::NextBlock() {
    if (mLevel->CheckGridTrue(2, 3) || 
        mLevel->CheckGridTrue(2, 4) ||
        mLevel->CheckGridTrue(2, 5) ||
        mLevel->CheckGridTrue(2, 6) ||
        mLevel->CheckGridTrue(2, 7)) {
        mGameOver = true;
    }
    else {
        if (mBlock->Active()) {
            mLevel->AddScore(100);
            mSideBar->SetScore(mLevel->Score());
            mBlock->Active(false);

            mBlock1->Position(309.0f, 24.0f);
            mBlock1->Active(true);
            delete mBlock;
            mBlock = new Player();
            if (mBlock->IShape()) {
                mBlock->Position(750.0f, 710.0f);
            }
            else {
                mBlock->Position(780.0f, 695.0f);
            }
            mBlock->Parent(this);
            mBlock->Active(false);
        }

        else if (mBlock1->Active()) {
            mLevel->AddScore(100);
            mSideBar->SetScore(mLevel->Score());
            mBlock1->Active(false);

            mBlock->Position(309.0f, 24.0f);
            mBlock->Active(true);
            delete mBlock1;
            mBlock1 = new Player();
            if (mBlock1->IShape()) {
                mBlock1->Position(750.0f, 710.0f);
            }
            else {
                mBlock1->Position(780.0f, 695.0f);
            }
            mBlock1->Parent(this);
            mBlock1->Active(false);
            
        }

        mBlock1->SetCopyGrid(mLevel->mPlayGrid);
        mBlock->SetCopyGrid(mLevel->mPlayGrid);
    }
}


void PlayScreen::GameOver() {
    mLevel->SetLevelGameOver(true);   
}

