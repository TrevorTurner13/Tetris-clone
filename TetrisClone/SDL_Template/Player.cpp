#include "Player.h"

void Player::HandleMovement() {
    if (mHeartBeatUpdate) {
        mHeartBeatUpdate = false;
        Position(Position() + Vector2(0.0, 48.0));
    }

    if (mInput->KeyPressed(SDL_SCANCODE_RIGHT)) {
        Position(Position() + mMove);

    }
    else if (mInput->KeyPressed(SDL_SCANCODE_LEFT)) {
        Position(Position() - mMove);
    }
    else if (mInput->KeyPressed(SDL_SCANCODE_DOWN)) {
        Position(Position() + mDropSpeed);
    }
    else if (mInput->KeyPressed(SDL_SCANCODE_UP)) {
       
       rotate_shape();
        UpdateShapeDimensions();
    }
    
    Vector2 pos = Position(Local);
    
    if (pos.x < mMoveBoundsX.x) {
        pos.x = mMoveBoundsX.x;
    }
    else if (pos.x + mShapeWidth > mMoveBoundsX.y) {
        pos.x = mMoveBoundsX.y - mShapeWidth;
    }
    if (pos.y < mMoveBoundsY.x) {
        pos.y = mMoveBoundsY.x;
    }
    else if (pos.y + mShapeHeight > mMoveBoundsY.y) {
        pos.y = mMoveBoundsY.y - mShapeHeight;
        IsDown(true);
    }
    Position(pos);
}
    

Player::Player() {
    mTimer = Timer::Instance();
    mInput = InputManager::Instance();
    mAudio = AudioManager::Instance();

    mVisible = true;
    mInPlay = true;
    mIsDown = false;
    mNextBlock = false;

    mShapeWidth = 0;
    mShapeHeight = 0; 

     for (int i = 0; i < 4; ++i) {
         for (int j = 0; j < 4; ++j) {
             mShapeGrid[i][j] = false;
         }
     }

     bool mLShape[4][4] = { {0,0,1,0} // L BLOCK
                        ,{1,1,1,0}
                        ,{0,0,0,0}
                        ,{0,0,0,0}
     };
     bool mZShape[4][4] = { {1,1,0,0} // Z BLOCK
                         ,{0,1,1,0}
                         ,{0,0,0,0}
                         ,{0,0,0,0}
     };
     bool mIShape[4][4] = { {1,1,1,1,} // I BLOCK
                         ,{0,0,0,0}
                         ,{0,0,0,0}
                         ,{0,0,0,0}
     };
     // J BLOCK
     bool mJShape[4][4] = { {1,0,0,0}
                         ,{1,1,1,0}
                         ,{0,0,0,0}
                         ,{0,0,0,0}
     };
     // O BLOCK
     bool mOShape[4][4] = { {1,1,0,0}
                         ,{1,1,0,0}
                         ,{0,0,0,0}
                         ,{0,0,0,0}
     };
     // S BLOCK
     bool mSShape[4][4] = { {0,1,1,0}
                         ,{1,1,0,0}
                         ,{0,0,0,0}
                         ,{0,0,0,0}
     };
     // T BLOCK
     bool mTShape[4][4] = { {0,1,0,0}
                         ,{1,1,1,0}
                         ,{0,0,0,0}
                         ,{0,0,0,0}
     };

     /*bool mTempShape[4][4] = {{0,0,1,0} 
                             ,{1,1,1,0}
                             ,{0,0,0,0}
                             ,{0,0,0,0}
                             };
   */

     for (int i = 0; i < 4; ++i) {
         for (int j = 0; j < 4; ++j) {
             srand(time(NULL));
             int randomIndex = rand() % NUM_ARRAYS[6];
             switch (randomIndex) {
             case 0:
                 mShapeGrid[i][j] = mLShape[i][j];
                 mShapeTexture[i][j] = new Texture("TetrisBackground.png", 179, 40, 8, 8);
                 mShapeTexture[i][j]->Parent(this);
                 mShapeTexture[i][j]->Position(j * 48, i * 48);
                 mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
                 break;
             case 1:
                 mShapeGrid[i][j] = mZShape[i][j];
                 mShapeTexture[i][j] = new Texture("TetrisBackground.png", 204, 16, 8, 8);
                 mShapeTexture[i][j]->Parent(this);
                 mShapeTexture[i][j]->Position(j * 48, i * 48);
                 mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
                 break;
             case 2:
                 mShapeGrid[i][j] = mIShape[i][j];
                 mShapeTexture[i][j] = new Texture("TetrisBackground.png", 244, 46, 8, 8);
                 mShapeTexture[i][j]->Parent(this);
                 mShapeTexture[i][j]->Position(j * 48, i * 48);
                 mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
                 break;
             case 3:
                 mShapeGrid[i][j] = mJShape[i][j];
                 mShapeTexture[i][j] = new Texture("TetrisBackground.png", 238, 15, 8, 8);
                 mShapeTexture[i][j]->Parent(this);
                 mShapeTexture[i][j]->Position(j * 48, i * 48);
                 mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
                 break;
             case 4:
                 mShapeGrid[i][j] = mOShape[i][j];
                 mShapeTexture[i][j] = new Texture("TetrisBackground.png", 179, 16, 8, 8);
                 mShapeTexture[i][j]->Parent(this);
                 mShapeTexture[i][j]->Position(j * 48, i * 48);
                 mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
                 break;
             case 5:
                 mShapeGrid[i][j] = mSShape[i][j];
                 mShapeTexture[i][j] = new Texture("TetrisBackground.png", 279, 15, 8, 8);
                 mShapeTexture[i][j]->Parent(this);
                 mShapeTexture[i][j]->Position(j * 48, i * 48);
                 mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
                 break;
             case 6:
                 mShapeGrid[i][j] = mTShape[i][j];
                 mShapeTexture[i][j] = new Texture("TetrisBackground.png", 213, 40, 8, 8);
                 mShapeTexture[i][j]->Parent(this);
                 mShapeTexture[i][j]->Position(j * 48, i * 48);
                 mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
                 break;
             }
         }
     }
     UpdateShapeDimensions();

    mDropSpeed = Vector2(0.0f, 48.0f);
    mMove = Vector2(48.0f, 0.0f);
    mMoveSpeed = 330.0f;

    mMoveBoundsX = Vector2(117.0f, 597.0f);
    mMoveBoundsY = Vector2(0.0f, 888.0f);
     
}

Player::~Player() {
    mTimer = nullptr;
    mInput = nullptr;
    mAudio = nullptr;

    delete mBlock;
    mBlock = nullptr;

}

void Player::Visible(bool visible) {
    mVisible = visible;
}

void Player::InPlay(bool inPlay) {
    mInPlay = inPlay;

}

//void Player::NextBlock(bool nextBlock) {
//    mNextBlock = nextBlock;
//    Player mBlock();
//    mNextBlock = false;
//}
//
//int Player::Score() {
//    return mScore;
//}
//
//void Player::AddScore(int change) {
//    mScore += change;
//}

void Player::IsDown(bool isDown) {
    mIsDown = isDown;
    mInPlay = false;  
}



void Player::Update() {
    if (Active()) {
        mHeartBeatCurrent -= mTimer->DeltaTime();
        if (mHeartBeatCurrent <= 0) {
            mHeartBeatUpdate = true;
            mHeartBeatCurrent = mHeartBeat;
        }

        if (mIsDown) {
            Active(false);
        }
        else {
            if (Active()) {
                HandleMovement();
            }
        }
    }
}

void Player::Render() {
    if (mVisible) {
       //mBlock->Render();
       for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (mShapeGrid[i][j]) {
                    mShapeTexture[i][j]->Active(true);
                    mShapeTexture[i][j]->Render();
                }
                else {
                    mShapeTexture[i][j]->Active(false);
                }
            }
        }
    }

}

void Player::SetHeartbeat(int levels) {
    static const int requiredLevels[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
    };
    while (levels = requiredLevels[levels]) {
        mHeartBeat = GetHeartBeat() - .5;
    }
}

int Player::pixelToGridX(float x) {
    int gridX = (x - 117) / 48;

    return gridX;
}

int Player::pixelToGridY(float y) {
    int gridY = (y - 24) / 48;

    return gridY;
}

void Player::UpdateShapeDimensions() {
    float width = 0;
    float height = 0;
    
    int min_col = INT_MAX, max_col = INT_MIN, min_row = INT_MAX, max_row = INT_MIN;
    
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (mShapeGrid[row][col]) {
                min_col = min(min_col, col);
                max_col = max(max_col, col);
                min_row = min(min_row, row);
                max_row = max(max_row, row);
            }
        }
    }

    width = (max_col - min_col + 1) * 48;
    height = (max_row - min_row + 1) * 48;

    std::cout << "Width: " << width << "    Height: " << height << std::endl;
    mShapeWidth = width;
    mShapeHeight = height;
}

int Player::min(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int Player::max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

//bool ** Player::GetShape() {
//    return mShapeGrid;
//}

void Player::rotate_shape() {
    // check if shape is square or line
    // if not
    bool temp[4][4];
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            temp[col][2 - row] = mShapeGrid[row][col];
        }
    }
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            mShapeGrid[row][col] = temp[row][col];
        }
    }
}

//void Player::rotate_shape() {
//    bool temp[4][4];
//    int center_row = 1;
//    int center_col = 1;
//    for (int row = 0; row < 4; ++row) {
//        for (int col = 0; col < 4; ++col) {
//            int rotated_row = center_row + (col - center_col);
//            int rotated_col = center_col - (row - center_row);
//            temp[rotated_row][rotated_col] = mShapeGrid[row][col];
//        }
//    }
//    for (int row = 0; row < 4; ++row) {
//        for (int col = 0; col < 4; ++col) {
//            mShapeGrid[row][col] = temp[row][col];
//        }
//    }
//}

//Player::Shape Player::reverseCols(Shape s) {
//    	Shape tmp = s;
//    	for (int i = 0; i < s.size; i++) {
//    		for (int j = 0; j < s.size / 2; j++) {
//    			bool t = s.matrix[i][j];
//    			tmp.matrix[i][j] = s.matrix[i][s.size - j - 1];
//    			tmp.matrix[i][s.size - j - 1] = t;
//    		}
//    	}
//    	return tmp;
//    }
//    
//Player::Shape Player::transpose(Shape s) {
//    	Shape tmp = s;
//    	for (int i = 0; i < s.size; i++) {
//    		for (int j = 0; j < s.size; j++) {
//    			tmp.matrix[i][j] = s.matrix[j][i];
//    		}
//    	}
//    	return tmp;
//    }
//    
//void Player::Rotate() {
//    	currentShape = reverseCols(transpose(currentShape));
//    }