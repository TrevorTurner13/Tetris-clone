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
    //mPlayArea->Scale(Vector2(6.0f, 6.0f));

    mLevel = nullptr;
    mBlock = nullptr;
    mBlock1 = nullptr;

    mScore = 0;
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
    
    if (mGameStarted) {
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
    
    //mBlock->Update();
}

void PlayScreen::Render() {
    mPlayArea->Render();
    mSideBar->Render();
   // mBlock->Render();

    if (mGameStarted && mLevelStarted) {
        mLevel->Render();
    }

    if (mGameStarted) {

        if (mLevelStarted) {
            mLevel->Render();
        }

        mBlock->Render();
        mBlock1->Render();
    }
    
}

void PlayScreen::StartNewGame() {
    mSideBar->SetLines(0);
    mSideBar->SetLevel(mSideBar->GetLines());
    mGameStarted = true;
    mLevelStarted = false;
    mCurrentStage = 0;

    mAudio->PauseMusic();
    mAudio->PlayMusic("Music/03. A-Type Music (Korobeiniki).mp3", -1);

    delete mBlock;
    mBlock = new Player();
    mBlock->Parent(this);
    mBlock->Position(357.0f, 24.0f);
    mBlock->Active(true);

    delete mBlock1;
    mBlock1 = new Player();
    mBlock1->Parent(this);
    mBlock1->Position(780.0, 680.0f);
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
}

void PlayScreen::NextBlock() {
    if (mBlock->Active()) {
        mLevel->AddScore(100);
        mSideBar->SetScore(mLevel->Score());
        mBlock->Active(false);
        
        mBlock1->Position(357.0f, 24.0f);
        mBlock1->Active(true);
        delete mBlock;
        mBlock = new Player();
        mBlock->Parent(this);
        mBlock->Position(780.0f, 680.0f);
        mBlock->Active(false);       
    }

    else if (mBlock1->Active()) {
        mLevel->AddScore(100);
        mSideBar->SetScore(mLevel->Score());
        mBlock1->Active(false);
       
        mBlock->Position(357.0f, 24.0f);
        mBlock->Active(true);
        delete mBlock1;
        mBlock1 = new Player();
        mBlock1->Parent(this);
        mBlock1->Position(780.0f, 680.0f);
        mBlock1->Active(false);
    }

    mBlock1->SetCopyGrid(mLevel->mPlayGrid);
    mBlock->SetCopyGrid(mLevel->mPlayGrid);
    
}

