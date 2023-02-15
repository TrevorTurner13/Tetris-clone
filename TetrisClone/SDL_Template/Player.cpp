#include "Player.h"

void Player::HandleMovement() {
    
    if (mHeartBeatUpdate) {
        mHeartBeatUpdate = false;
        Position(Position() + Vector2(0.0, 48.0));
        
        if (CheckCollisionGPT()) {
            IsDown(true);
        }
    }

    if (mInput->KeyPressed(SDL_SCANCODE_RIGHT)) {
        if (!CheckCollisionRight()) {
            Position(Position() + mMove);
        }
    }
    else if (mInput->KeyPressed(SDL_SCANCODE_LEFT)) {
        if (!CheckCollisionLeft()) {
            Position(Position() - mMove);
        }
    }
    else if (mInput->KeyPressed(SDL_SCANCODE_DOWN)) {
        Position(Position() + mDropSpeed);
        if (CheckCollisionGPT()) {
            IsDown(true);
        }

    }
    else if (mInput->KeyPressed(SDL_SCANCODE_UP)) {
        Rotate();
        UpdateShapeDimensions();
    }
    
    Vector2 pos = Position(World);
    
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

    std::cout << "Position x: " << Position().x << std::endl;

    Position(pos);
}
    

Player::Player() {
    mTimer = Timer::Instance();
    mInput = InputManager::Instance();
    mAudio = AudioManager::Instance();

    mVisible = true;
    mIsDown = false;
    mNextBlock = false;
    mCurrentShapeIsIShape = false;

    mShapeWidth = 0;
    mShapeHeight = 0; 

    int randomIndex = rand() % NUM_ARRAYS[6];
    switch (randomIndex) {
    case 0:
        currentShape = mLShape;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mShapeTexture[i][j] = new Texture("TetrisBackground.png", 179, 40, 8, 8);
                mShapeTexture[i][j]->Parent(this);
                mShapeTexture[i][j]->Position(j * 48, i * 48);
                mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
            }
        }
        break;
    case 1:
        currentShape = mZShape;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mShapeTexture[i][j] = new Texture("TetrisBackground.png", 204, 16, 8, 8);
                mShapeTexture[i][j]->Parent(this);
                mShapeTexture[i][j]->Position(j * 48, i * 48);
                mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
            }
        }
        break;
    case 2:
        currentShape = mIShape;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mShapeTexture[i][j] = new Texture("TetrisBackground.png", 244, 46, 8, 8);
                mShapeTexture[i][j]->Parent(this);
                mShapeTexture[i][j]->Position(j * 48, i * 48);
                mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
                mCurrentShapeIsIShape = true;
            }
        }
        break;
    case 3:
        currentShape = mJShape;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mShapeTexture[i][j] = new Texture("TetrisBackground.png", 238, 15, 8, 8);
                mShapeTexture[i][j]->Parent(this);
                mShapeTexture[i][j]->Position(j * 48, i * 48);
                mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
            }
        }
        break;
    case 4:
        currentShape = mOShape;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mShapeTexture[i][j] = new Texture("TetrisBackground.png", 179, 16, 8, 8);
                mShapeTexture[i][j]->Parent(this);
                mShapeTexture[i][j]->Position(j * 48, i * 48);
                mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
            }
        }
        break;
    case 5:
        currentShape = mSShape;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mShapeTexture[i][j] = new Texture("TetrisBackground.png", 279, 15, 8, 8);
                mShapeTexture[i][j]->Parent(this);
                mShapeTexture[i][j]->Position(j * 48, i * 48);
                mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
            }
        }
        break;
    case 6:
        currentShape = mTShape;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mShapeTexture[i][j] = new Texture("TetrisBackground.png", 213, 40, 8, 8);
                mShapeTexture[i][j]->Parent(this);
                mShapeTexture[i][j]->Position(j * 48, i * 48);
                mShapeTexture[i][j]->Scale(Vector2(6.0f, 6.0f));
            }
        }
        break;
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


void Player::IsDown(bool isDown) {
    mIsDown = isDown;
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
                if (currentShape.mGrid[i][j]) {
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
    switch (levels) {
    case 1: 
        mHeartBeat = 1.5;
        break;
    case 2:
        mHeartBeat = 1.4;
        break;
    case 3:
        mHeartBeat = 1.3;
        break;
    case 4:
        mHeartBeat = 1.2;
        break;
    case 5:
        mHeartBeat = 1.1;
        break;
    case 6:
        mHeartBeat = 1;
        break;
    case 7:
        mHeartBeat = 0.95;
        break;
    case 8:
        mHeartBeat = 0.9;
        break;
    case 9:
        mHeartBeat = 0.85;
        break;
    case 10:
        mHeartBeat = 0.8;
        break;
    case 11:
        mHeartBeat = 0.75;
        break;
    case 12:
        mHeartBeat = 0.7;
        break;
    case 13:
        mHeartBeat = 0.65;
        break;
    case 14:
        mHeartBeat = 0.6;
        break;
    case 15:
        mHeartBeat = 0.55;
        break;
    case 16:
        mHeartBeat = 0.5;
        break;
    case 17:
        mHeartBeat = 0.45;
        break;
    case 18:
        mHeartBeat = 0.4;
        break;
    case 19:
        mHeartBeat = 0.35;
        break;
    case 20:
        mHeartBeat = 0.3;
        break;
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
            if (currentShape.mGrid[row][col]) {
                min_col = min(min_col, col);
                max_col = max(max_col, col);
                min_row = min(min_row, row);
                max_row = max(max_row, row);
            }
        }
    }

    width = (max_col - min_col + 1) * 48;
    height = (max_row - min_row + 1) * 48;

    std::cout << "x position: " << Position().x << "     Width: " << width << "    Height : " << height << std::endl;
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

Player::Shape Player::reverseCols(Shape s) {
    tempShape = s;
    for (int i = 0; i < s.size; i++) {
    	for (int j = 0; j < s.size / 2; j++) {
    		bool t = s.mGrid[i][j];
            tempShape.mGrid[i][j] = s.mGrid[i][s.size - j - 1];
            tempShape.mGrid[i][s.size - j - 1] = t;
    	}
    }
    return tempShape;
}
    
Player::Shape Player::transpose(Shape s) {
    tempShape = s;
    for (int i = 0; i < s.size; i++) {
    	for (int j = 0; j < s.size; j++) {
    		tempShape.mGrid[i][j] = s.mGrid[j][i];
    	}
    }
    tempShape.size = s.size;
    return tempShape;
}

Player::Shape Player::translate(Shape s) {
    tempShape = s;
    bool leftColumnEmpty = true;
    for (int i = 0; i < 4; i++) {
        if (tempShape.mGrid[i][0]) {
            leftColumnEmpty = false;
            break;
        }
    }
    if (leftColumnEmpty) {
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                tempShape.mGrid[i][j - 1] = tempShape.mGrid[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            tempShape.mGrid[i][2] = false;
        }
    }
    return tempShape;
}
    
void Player::Rotate() {
    if (mCurrentShapeIsIShape) {
        currentShape = transpose(currentShape);
    }
    else {
        currentShape = translate(reverseCols(transpose(currentShape)));
    }
}

//bool Player::CheckCopyGridTrue(int x, int y) {
//    for (int row = 0; row < 4; ++row) {
//        for (int col = 0; col < 4; ++col) {
//            int playfield_row = row + y;
//            int playfield_col = col + x;
//            if (playfield_row >= 0 && playfield_row < 18 && playfield_col >= 0 && playfield_col < 10) {
//                if (currentShape.mGrid[row][col]) {
//                    if (mPlayGridCopy[playfield_row][playfield_col]) {
//                        return true;
//                    }
//                }
//            }
//            else {
//                return false;
//            }
//        }
//    }
//}

void Player::SetCopyGrid(bool playGrid[18][10]) {
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 10; ++j) {
            mPlayGridCopy[i][j] = playGrid[i][j];
        }
    }
    
}

bool Player::CheckCollisionGPT() {
    // Check for collisions between the falling shape and the playfield
    bool hasCollision = false;
    int shapeX = pixelToGridX(Position().x);
    int shapeY = pixelToGridY(Position().y);
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (currentShape.mGrid[y][x]) {
                int playfieldX = shapeX + x;
                int playfieldY = shapeY + y;
                if (playfieldX < 0 || playfieldX >= 10 ||
                    playfieldY < 0 || playfieldY >= 18 ||
                    mPlayGridCopy[playfieldY + 1][playfieldX]) {
                    hasCollision = true;
                    break;
                }
            }
        }
        if (hasCollision) {
            break;
        }
    }
    return hasCollision;
}

bool Player::CheckCollisionRight() {
    // Check for collisions between the falling shape and the playfield
    bool hasCollision = false;
    int shapeX = pixelToGridX(Position().x);
    int shapeY = pixelToGridY(Position().y);
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (currentShape.mGrid[y][x]) {
                int playfieldX = shapeX + x;
                int playfieldY = shapeY + y;
                if (playfieldX < 0 || playfieldX >= 10 ||
                    playfieldY < 0 || playfieldY >= 18 ||
                    mPlayGridCopy[playfieldY][playfieldX + 1]) {
                    hasCollision = true;
                    break;
                }
            }
        }
        if (hasCollision) {
            break;
        }
    }
    return hasCollision;
}

bool Player::CheckCollisionLeft() {
    // Check for collisions between the falling shape and the playfield
    bool hasCollision = false;
    int shapeX = pixelToGridX(Position().x);
    int shapeY = pixelToGridY(Position().y);
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (currentShape.mGrid[y][x]) {
                int playfieldX = shapeX + x;
                int playfieldY = shapeY + y;
                if (playfieldX < 0 || playfieldX >= 10 ||
                    playfieldY < 0 || playfieldY >= 18 ||
                    mPlayGridCopy[playfieldY][playfieldX - 1]) {
                    hasCollision = true;
                    break;
                }
            }
        }
        if (hasCollision) {
            break;
        }
    }
    return hasCollision;
}