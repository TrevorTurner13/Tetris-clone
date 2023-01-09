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

    mPlayArea = new Texture("TetrisBackground.png", 0, 0, 105, 144);
    mPlayArea->Parent(mPlayScreen);
    mPlayArea->Position(Graphics::SCREEN_WIDTH * 0.325f, Graphics::SCREEN_HEIGHT * 0.5f);
    mPlayArea->Scale(Vector2(6.0f, 6.0f));

    mPlayer = nullptr;
    /*mScore = new Scoreboard();
    mLevel = new Scoreboard();
    mLines = new Scoreboard();*/
   // mBlock = nullptr;

    
   
   /* mScore->Parent(mPlayScreen);
    mLevel->Parent(mPlayScreen);
    mLines->Parent(mPlayScreen);*/

    

   /* mScore->Position(Graphics::SCREEN_WIDTH * 0.88f, 95.0f);
    mLevel->Position(Graphics::SCREEN_WIDTH * 0.85f, 290.0f);
    mLines->Position(Graphics::SCREEN_WIDTH * 0.85f, 435.0f);*/
  //  mBlock->Position(Graphics::SCREEN_WIDTH * 0.5f, 500.0f);
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

    delete mPlayer;
    mPlayer = nullptr;


    /*delete mScore;
    mScore = nullptr;
    delete mLevel;
    mLevel = nullptr;
    delete mLines;
    mLines = nullptr;*/
    //delete mBlock;
    //mBlock = nullptr;
}


void PlayScreen::Update() {
    mPlayArea->Update();
    mSideBar->Update();

    if (mGameStarted) {
        if (!mLevelStarted) {
            StartNextLevel();
        }
        else {
            mLevel->Update();
        }

        if (mCurrentStage > 0) {
            mSideBar->Update();
        }
        mPlayer->Update();
    }
    else {
        if (!Mix_PlayingMusic()) {
            mGameStarted = true;
        }
    }
    /* mScore->Update();
    mLevel->Update();
    mLines->Update();*/
    /*if (mGameStarted) {
        mBlock->Update();
    }*/
}

void PlayScreen::Render() {
    mPlayArea->Render();
    mSideBar->Render();

    if (mGameStarted && mLevelStarted) {
        mLevel->Render();
    }

    if (mGameStarted) {

        if (mLevelStarted) {
            mLevel->Render();
        }

        mPlayer->Render();
    }

    /*mScore->Render();
    mLevel->Render();
    mLines->Render();*/
   // mBlock->Render();
}

void PlayScreen::StartNewGame() {
    mSideBar->SetLines(0);
    mSideBar->SetLevel(mSideBar->GetLines());
    mGameStarted = false;
    mLevelStarted = false;
    mCurrentStage = 0;

    mAudio->PauseMusic();
    mAudio->PlayMusic("Music/03. A-Type Music (Korobeiniki).mp3", -1);

    delete mPlayer;
    mPlayer = new Player();
    mPlayer->Parent(this);
    mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.2f);
    mPlayer->Active(false);

    mSideBar->SetScore(0);
    mSideBar->SetLines(0);
    mSideBar->SetLevel(0);
   
}

void PlayScreen::StartNextLevel() {
    mCurrentStage += 1;
    mLevelStarted = true;

    delete mLevel;
    mLevel = new Level(mCurrentStage, mSideBar, mPlayer);
}
