#include "Player.h"

void Player::HandleMovement() {
    if (mInput->KeyDown(SDL_SCANCODE_RIGHT)) {
        Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
    }
    else if (mInput->KeyDown(SDL_SCANCODE_LEFT)) {
        Translate(-Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
    }

    Vector2 pos = Position(Local);
    if (pos.x < mMoveBounds.x) {
        pos.x = mMoveBounds.x;
    }
    else if (pos.x > mMoveBounds.y) {
        pos.x = mMoveBounds.y;
    }

    Position(pos);
}

Player::Player() {
    mTimer = Timer::Instance();
    mInput = InputManager::Instance();
    mAudio = AudioManager::Instance();

    mVisible = true;
    //mInPlay = true;
   /* mIsDown = false;
    mNextBlock = false;*/

    mScore = 0;

    mBlock = new Texture("TetrisBackground.png", 279, 15, 8, 8);
    mBlock->Parent(this);
    mBlock->Position(Vec2_Zero);
    mBlock->Scale(Vector2(6.0f, 6.0f));

    mMoveSpeed = 300.0f;
    mMoveBounds = Vector2(0.0f, 800.0f);

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

//void Player::InPlay(bool inPlay) {
//    mInPlay = inPlay;
//}
//
//void Player::NextBlock(bool nextBlock) {
//    mNextBlock = nextBlock;
//}

int Player::Score() {
    return mScore;
}

void Player::AddScore(int change) {
    mScore += change;
}

//void Player::IsDown(bool isDown) {
//    mIsDown = isDown;
//    mScore += 10;
//}



void Player::Update() {
   /* if (mIsDown) {
        mInPlay = false;
    }
    else {*/
        if (Active()) {
            HandleMovement();
        }
   /* }*/
}

void Player::Render() {
    if (mVisible) {
        mBlock->Render();
    }
    
}

