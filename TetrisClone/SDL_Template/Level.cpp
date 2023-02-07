#include "Level.h"

void Level::StartStage() {
    mStageStarted = true;
}

Level::Level(int stage, PlaySideBar* sideBar, Player* player) {
    mInput = InputManager::Instance();
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
            mPlayGrid[i][j] = false;
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
            if (mPlayGrid[i][j]) {
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
        if (mPlayGrid[i][0] &&
            mPlayGrid[i][1] &&
            mPlayGrid[i][2] &&
            mPlayGrid[i][3] &&
            mPlayGrid[i][4] &&
            mPlayGrid[i][5] &&
            mPlayGrid[i][6] &&
            mPlayGrid[i][7] &&
            mPlayGrid[i][8] &&
            mPlayGrid[i][9]) {
            // we have a line
            //remove line
            mPlayGrid[i][0] = false;
            mPlayGrid[i][1] = false;
            mPlayGrid[i][2] = false;
            mPlayGrid[i][3] = false;
            mPlayGrid[i][4] = false;
            mPlayGrid[i][5] = false;
            mPlayGrid[i][6] = false;
            mPlayGrid[i][7] = false;
            mPlayGrid[i][8] = false;
            mPlayGrid[i][9] = false;
            AddScore(1000);
            mSideBar->SetScore(mScore);
            mSideBar->SetLines(mSideBar->GetLines() + 1);
            mSideBar->SetLevel(mSideBar->GetLines());
            mPlayer->SetHeartbeat(mSideBar->GetLevels());
            //DropLines();
            do {
                for (int j = 0; j < 10; ++j) {
                    if (!mPlayGrid[i][0] &&
                        !mPlayGrid[i][1] &&
                        !mPlayGrid[i][2] &&
                        !mPlayGrid[i][3] &&
                        !mPlayGrid[i][4] &&
                        !mPlayGrid[i][5] &&
                        !mPlayGrid[i][6] &&
                        !mPlayGrid[i][7] &&
                        !mPlayGrid[i][8] &&
                        !mPlayGrid[i][9]) {
                        do {
                            if (mPlayGrid[i - 1][j]) {
                                mPlayGrid[i][j] = true;
                                mPlayGrid[i - 1][j] = false;

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
                if (i > 0) {
                    --i;
                }
                else {
                    break;
                }
            } while (i > 0);
        }
    }
}

void Level::DropLines() {
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (!mPlayGrid[i][0] &&
                !mPlayGrid[i][1] &&
                !mPlayGrid[i][2] &&
                !mPlayGrid[i][3] &&
                !mPlayGrid[i][4] &&
                !mPlayGrid[i][5] &&
                !mPlayGrid[i][6] &&
                !mPlayGrid[i][7] &&
                !mPlayGrid[i][8] &&
                !mPlayGrid[i][9]) {
                do {
                    if (mPlayGrid[i - 1][j]) {
                        mPlayGrid[i][j] = true;
                        mPlayGrid[i - 1][j] = false;
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

bool Level::CheckGridTrue(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (mPlayGrid[x][y]) {

                return true;
            }
            else {
                return false;
            }
        }
    }
}

//bool Level::CompareGrids() {
//    for (int i = 0; i < 18; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            for (int k = 0; k < 4; ++k) {
//                for (int l = 0; l < 4; ++l) {
//                    if (mPlayer->pixelToGridX(mPlayer->Position().x) == i && mPlayer->pixelToGridY(mPlayer->Position().y) == j && mPlayer->mShapeGrid[k][l] && mPlayGrid[i][j]) {
//                        return true;
//                    }
//                    else {
//                        return false;
//                    }
//                }
//            }
//        }
//    }
//}

void Level::SetGridPointTrue(int x, int y, bool shape[4][4]) {
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            int playfield_row = row + y;
            int playfield_col = col + x;
            if (playfield_row >= 0 && playfield_row < 18 && playfield_col >= 0 && playfield_col < 10) {
                if (shape[row][col]) {
                    mPlayGrid[playfield_row][playfield_col] = shape[row][col];
                }
            }
        }
    }
}

void Level::AddScore(int change) {
    mScore += change;
}

