#include "Player.h"

Player::Player() {
    mTimer = Timer::Instance();
    mInput = InputManager::Instance();
    mAudio = AudioManager::Instance();

    mVisible = false;
    mInPlay = false;
    mIsDown = false;
    mNextBlock = false;

    mScore = 0;

    mBlock = new Blocks();
    mBlock->Parent(this);
    mBlock->Position(100.0f, 300.0f);

    mMoveSpeed = 100.0f;
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

void Player::InPlay(bool inPlay) {
    mInPlay = inPlay;
}

void Player::NextBlock(bool nextBlock) {
    mNextBlock = nextBlock;
}

int Player::Score() {
    return mScore;
}

void Player::AddScore(int change) {
    mScore += change;
}

void Player::IsDown(bool isDown) {
    mIsDown = isDown;
    mScore += 10;
}

void Player::HandleMovement() {
    if (mInput->KeyDown(SDL_SCANCODE_RIGHT)) {
        Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
    }
    else if (mInput->KeyDown(SDL_SCANCODE_LEFT)) {
        Translate(-Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
    }

    Vector2 pos = Position(Local);
    /*if (pos.x < mMoveBounds.x + mBlock->ScaledDimensions().x * 0.5f) {
        pos.x = mMoveBounds.x + mBlock->ScaledDimensions().x * 0.5f;
    }
    else if (pos.x > mMoveBounds.y - mBlock->ScaledDimensions().x * 0.5f) {
        pos.x = mMoveBounds.y - mBlock->ScaledDimensions().x * 0.5f;
    }*/

    Position(pos);
}

void Player::Update() {
    if (mIsDown) {
    }
    else {
        if (Active()) {
            HandleMovement();
        }
    }
}

void Player::Render() {
    if (mVisible) {
       /* if (mAnimating) {
            mDeathAnimation->Render();
        }*/
       /* else {*/
            mBlock->Render();
        /*}*/
    }
}

