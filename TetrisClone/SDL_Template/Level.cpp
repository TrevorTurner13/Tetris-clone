#include "Level.h"

void Level::StartStage() {
    mStageStarted = true;
}

//void Level::HandleMovement() {
//    if (mHeartBeatUpdate) {
//        mHeartBeatUpdate = false;
//        Position(Position() + mGrid[1][0]);
//    }
//
//    if (mInput->KeyPressed(SDL_SCANCODE_RIGHT)) {
//        Position(Position() + mMove);
//
//    }
//    else if (mInput->KeyPressed(SDL_SCANCODE_LEFT)) {
//        Position(Position() - mMove);
//    }
//    else if (mInput->KeyPressed(SDL_SCANCODE_DOWN)) {
//        Position(Position() + mDropSpeed);
//    }
//
//    Vector2 pos = Position(Local);
//    if (pos.x < mMoveBoundsX.x) {
//        pos.x = mMoveBoundsX.x;
//    }
//    else if (pos.x > mMoveBoundsX.y) {
//        pos.x = mMoveBoundsX.y;
//    }
//    if (pos.y < mMoveBoundsY.x) {
//        pos.y = mMoveBoundsY.x;
//    }
//    else if (pos.y > mMoveBoundsY.y) {
//        pos.y = mMoveBoundsY.y;
//        //IsDown(true);
//    }
//    Position(pos);
//}

Level::Level(int stage, PlaySideBar* sideBar, Player* player) {
    mTimer = Timer::Instance();
    mSideBar = sideBar;
    mSideBar->SetLevel(stage);

    mStage = stage;
    mStageStarted = false;

    mPlayer = player;
   /* mPlayer->Position(mGrid[0][5]);
    

    mMove = mGrid[0][1];*/
    //mBlock = new Texture("TetrisBackground.png", 279, 15, 8, 8);
    //mBlock->Parent(this);
    //mBlock->Position(Vec2_Zero);
    //mBlock->Scale(Vector2(6.0f, 6.0f));

    //for (int i = 0; i < 18; ++i) {
    //    for (int j = 0; j < 10; ++j) {
    //        mGrid[i][j] = false;
    //        //mPlayer->Position(mGrid[0][5]);
    //        mGridDisplay[i][j] = new Texture("TetrisBackground.png", 279, 15, 8, 8);
    //        mGridDisplay[i][j]->Parent(this);
    //        mGridDisplay[i][j]->Position(117 + (j * 48), 24 + (i * 48));
    //        mGridDisplay[i][j]->Scale(Vector2(6.0f, 6.0f));
    //        
    //    }
    //}
}

Level::~Level() {
    mTimer = nullptr;
    mSideBar = nullptr;
    mPlayer = nullptr;
}

void Level::Update() {
    mPlayer->Active(true);
    mPlayer->Visible(true);

}

void Level::Render() {
   /* for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (mGrid[i][j]) {
                mGridDisplay[i][j]->Active(true);
                mGridDisplay[i][j]->Render();
            }
            else {
                mGridDisplay[i][j]->Active(false);   
            }
        }
    }*/
}

//void Level::CheckForLines() {
//    for (int i = 0; i < 18; ++i) {
//        if (mGrid[i][0] &&
//            mGrid[i][1] &&
//            mGrid[i][2] &&
//            mGrid[i][3] &&
//            mGrid[i][4] &&
//            mGrid[i][5] &&
//            mGrid[i][6] &&
//            mGrid[i][7] &&
//            mGrid[i][8] &&
//            mGrid[i][9]) {
//            // we have a line
//        }
//    }
//}
