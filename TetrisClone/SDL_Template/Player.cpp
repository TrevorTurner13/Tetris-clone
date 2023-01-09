#include "Player.h"

void Player::HandleMovement() {
    Translate(Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
    if (mInput->KeyDown(SDL_SCANCODE_RIGHT)) {
        Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
    }
    else if (mInput->KeyDown(SDL_SCANCODE_LEFT)) {
        Translate(-Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
    }
    else if (mInput->KeyDown(SDL_SCANCODE_DOWN)) {
        Translate(Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
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
        mIsDown = true;
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

    mScore = 0;

    mBlock = new Texture("TetrisBackground.png", 279, 15, 8, 8);
    mBlock->Parent(this);
    mBlock->Position(Vec2_Zero);
    mBlock->Scale(Vector2(6.0f, 6.0f));

    mMoveSpeed = 48.0f;

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
    
    mScore += 10;
}



void Player::Update() {
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

