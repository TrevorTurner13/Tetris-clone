#include "Player.h"

//void Player::HandleMovement() {
//    if (mHeartBeatUpdate) {
//        mHeartBeatUpdate = false;
//        Position(Position() + Vector2(0.0, 48.0));
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
//        IsDown(true);
//    }
//    Position(pos);
//}
void Player::HandleMovement() {
    if (mHeartBeatUpdate) {
        mHeartBeatUpdate = false;
        Position(Position() + Vector2(0.0f, 48.0f));
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

    Vector2 pos = Position(Local);
    if (pos.x < mMoveBoundsX.x) {
        pos.x = mMoveBoundsX.x;
    }
    else if (pos.x > mMoveBoundsX.y) {
        pos.x = mMoveBoundsX.y;
    }
    if (pos.y < mMoveBoundsY.x) {
        pos.y = mMoveBoundsY.x;
    }
    else if (pos.y > mMoveBoundsY.y) {
        pos.y = mMoveBoundsY.y;
        //IsDown(true);
    }
    Position(pos);
}

struct Player::Block {
    Texture* mBlock;
    bool active;
};

struct Player::Shape {
    Texture* mBlock;
    bool matrix[4][4];
    double x, y;
    int size;
};

Player::Player() {
    mTimer = Timer::Instance();
    mInput = InputManager::Instance();
    mAudio = AudioManager::Instance();

    mVisible = true;
    mInPlay = true;
    mIsDown = false;
    mNextBlock = false;

    mScore = 0;

    mBlock = new Texture("TetrisBackground.png", 279, 15, 8, 8);
    mBlock->Parent(this);
    mBlock->Position(Vec2_Zero);
    mBlock->Scale(Vector2(6.0f, 6.0f));

    //Shape blocks[1] = { {{mBlock},
    //            {{0,0,1,0} // L BLOCK
    //            ,{1,1,1,0}
    //            ,{0,0,0,0}
    //            ,{0,0,0,0}
    //            },5,4,3} };
   
    mDropSpeed = Vector2(0.0f, 48.0f);
    mMove = Vector2(48.0f, 0.0f);
    mMoveSpeed = 330.0f;

    mMoveBoundsX = Vector2(117.0f, 549.0f);
    mMoveBoundsY = Vector2(0.0f, 840.0f);
     
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

void Player::NextBlock(bool nextBlock) {
    mNextBlock = nextBlock;
    Player mBlock();
    mNextBlock = false;
}

int Player::Score() {
    return mScore;
}

void Player::AddScore(int change) {
    mScore += change;
}

void Player::IsDown(bool isDown) {
    mIsDown = isDown;
    mInPlay = false;  
    AddScore(10);
    NextBlock(true);
}



void Player::Update() {
    mHeartBeatCurrent -= mTimer->DeltaTime();
    if (mHeartBeatCurrent <= 0) {
        mHeartBeatUpdate = true;
        mHeartBeatCurrent = mHeartBeat;
    }

    if (mIsDown) {
        mInPlay = false;
    }
    else {
        if (Active()) {
            HandleMovement();
        }
    }
}

void Player::Render() {
    if (mVisible) {
        mBlock->Render();
    }
    
}

