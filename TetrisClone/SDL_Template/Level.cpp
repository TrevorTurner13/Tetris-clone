#include "Level.h"

void Level::StartStage() {
    mStageStarted = true;
}


Level::Level(int stage, PlaySideBar* sideBar, Player* player) {
    mTimer = Timer::Instance();
    mSideBar = sideBar;
    mSideBar->SetLevel(stage);

    mStage = stage;
    mStageStarted = false;

    mPlayer = player;
    

    mBlock = new Texture("TetrisBackground.png", 279, 15, 8, 8);
    mBlock->Parent(this);
    mBlock->Position(Vec2_Zero);
    mBlock->Scale(Vector2(6.0f, 6.0f));

    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 10; ++j) {
            mGrid[i][j] = false;
            //mPlayer->Position(mGrid[0][5]);
            mGridDisplay[i][j] = new Texture("TetrisBackground.png", 279, 15, 8, 8);
            mGridDisplay[i][j]->Parent(this);
            mGridDisplay[i][j]->Position(117 + (j * 48), 24 + (i * 48));
            mGridDisplay[i][j]->Scale(Vector2(6.0f, 6.0f));
            
        }
    }
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
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (mGrid[i][j]) {
                mGridDisplay[i][j]->Active(true);
                mGridDisplay[i][j]->Render();
               
            }
            else {
                mGridDisplay[i][j]->Active(false);   
            }
        }
    }
}

void Level::CheckForLines() {
    for (int i = 0; i < 18; ++i) {
        if (mGrid[i][0] &&
            mGrid[i][1] &&
            mGrid[i][2] &&
            mGrid[i][3] &&
            mGrid[i][4] &&
            mGrid[i][5] &&
            mGrid[i][6] &&
            mGrid[i][7] &&
            mGrid[i][8] &&
            mGrid[i][9]) {
            // we have a line
            //remove line
            mGrid[i][0] = false;
            mGrid[i][1] = false;
            mGrid[i][2] = false;
            mGrid[i][3] = false;
            mGrid[i][4] = false;
            mGrid[i][5] = false;
            mGrid[i][6] = false;
            mGrid[i][7] = false;
            mGrid[i][8] = false;
            mGrid[i][9] = false;
            //DropLines();
            for (int j = 0; j < 10; ++j) {
                if (!mGrid[i][0] &&
                    !mGrid[i][1] &&
                    !mGrid[i][2] &&
                    !mGrid[i][3] &&
                    !mGrid[i][4] &&
                    !mGrid[i][5] &&
                    !mGrid[i][6] &&
                    !mGrid[i][7] &&
                    !mGrid[i][8] &&
                    !mGrid[i][9]) {
                    do {
                        if (mGrid[i - 1][j]) {
                            mGrid[i][j] = true;
                            mGrid[i - 1][j] = false;
                        }
                        if (j < 9) {
                            ++j;
                        }
                        else {
                            break;
                        }
                    } while (j < 10);
                }
            }           
        }
    }
}

void Level::DropLines() {
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (!mGrid[i][0] &&
                !mGrid[i][1] &&
                !mGrid[i][2] &&
                !mGrid[i][3] &&
                !mGrid[i][4] &&
                !mGrid[i][5] &&
                !mGrid[i][6] &&
                !mGrid[i][7] &&
                !mGrid[i][8] &&
                !mGrid[i][9] &&
                mGrid[i - 1][j]) {
                mGrid[i][j] = true;
                mGrid[i - 1][j] = false;
                if (i <= 18) {
                    ++i;
                }
                else {
                    break;
                }
                if (i <= 18) {
                    ++i;
                }
                else {
                    break;
                }
            }
           
            /*mGridDisplay[i - 1][0]->Position(mGridDisplay[i - 1][0]->Position().x, mGridDisplay[i - 1][0]->Position().y + 1);
            mGridDisplay[i - 1][1]->Position(mGridDisplay[i - 1][1]->Position().x, mGridDisplay[i - 1][1]->Position().y + 1);
            mGridDisplay[i - 1][2]->Position(mGridDisplay[i - 1][2]->Position().x, mGridDisplay[i - 1][2]->Position().y + 1);
            mGridDisplay[i - 1][3]->Position(mGridDisplay[i - 1][3]->Position().x, mGridDisplay[i - 1][3]->Position().y + 1);
            mGridDisplay[i - 1][4]->Position(mGridDisplay[i - 1][4]->Position().x, mGridDisplay[i - 1][4]->Position().y + 1);
            mGridDisplay[i - 1][5]->Position(mGridDisplay[i - 1][5]->Position().x, mGridDisplay[i - 1][5]->Position().y + 1);
            mGridDisplay[i - 1][6]->Position(mGridDisplay[i - 1][6]->Position().x, mGridDisplay[i - 1][6]->Position().y + 1);
            mGridDisplay[i - 1][7]->Position(mGridDisplay[i - 1][7]->Position().x, mGridDisplay[i - 1][7]->Position().y + 1);
            mGridDisplay[i - 1][8]->Position(mGridDisplay[i - 1][8]->Position().x, mGridDisplay[i - 1][8]->Position().y + 1);
            mGridDisplay[i - 1][9]->Position(mGridDisplay[i - 1][9]->Position().x, mGridDisplay[i - 1][9]->Position().y + 1);*/
        }
    }
}

bool Level::CheckGridTrue(int x, int y) {
    if (mGrid[x][y]) {
       
        return true;
    }
    else {
        return false;
    }
}

void Level::SetGridPointTrue(int x, int y) {
    mGrid[y][x] = true;
}

