#include "PlayArea.h"

PlayArea::PlayArea() {

    mPlayArea = new Texture("TetrisBackground.png", 0, 0, 105, 144);
    mPlayArea->Parent(this);
    //mPlayArea->Position(Graphics::SCREEN_WIDTH * 0.325f, Graphics::SCREEN_HEIGHT * 0.5f);
    mPlayArea->Scale(Vector2(6.0f, 6.0f));

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

PlayArea::~PlayArea() {
    delete mPlayArea;
    mPlayArea = nullptr;
}

void PlayArea::Update() {
   
}

void PlayArea::Render() {
    mPlayArea->Render();
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

void PlayArea::CheckForLines() {
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
        }
    }
}
