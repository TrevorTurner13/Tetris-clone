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
    /*mScore->Render();
    mLevel->Render();
    mLines->Render();*/
   // mBlock->Render();
}

void PlayScreen::StartNewGame() {
    mSideBar->SetScore(30000);
    mSideBar->SetLines(0);
    mSideBar->SetLevel(0);
}
