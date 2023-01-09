#include "Blocks.h"

Blocks::Blocks() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	/*mVisible = false;

	mScore = 0;*/

	mSBlock = new Texture("TetrisBackground.png", 279, 15, 8, 8);
	mZBlock = new Texture("TetrisBackground.png", 204, 16, 8, 8);
	mLBlock = new Texture("TetrisBackground.png", 179, 40, 8, 8);
	mJBlock = new Texture("TetrisBackground.png", 238, 15, 8, 8);
	mOBlock = new Texture("TetrisBackground.png", 179, 16, 8, 8);
	mTBlock = new Texture("TetrisBackground.png", 213, 40, 8, 8);
	mIBlock = new Texture("TetrisBackground.png", 244, 46, 8, 8);

	shape blocks[7] = { {{mLBlock},
		{{0,0,1,0} // L BLOCK
		,{1,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}
		},5,4,3}
		,{{mZBlock}, // Z BLOCK
		{{1,1,0,0}
		,{0,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}
		},5,4,3}
		,{{mIBlock}, // I BLOCK
		{{1,1,1,1,}
		,{0,0,0,0}
		,{0,0,0,0}
		,{0,0,0,0}
		},5,4,4}
		,{{mJBlock}, // J BLOCK
		{{1,0,0,0}
		,{1,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}
		},5,4,3}
		,{{mOBlock}, // O BLOCK
		{{1,1,0,0}
		,{1,1,0,0}
		,{0,0,0,0}
		,{0,0,0,0}
		},5,4,2}
		,{{mSBlock}, // S BLOCK
		{{0,1,1,0}
		,{1,1,0,0}
		,{0,0,0,0}
		,{0,0,0,0}
		},5,4,3}
		,{{mTBlock }, // T BLOCK
		{{0,1,0,0}
		,{1,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}
		},5,4,3} };

	mSBlock->Parent(this);
	mZBlock->Parent(this);
	mLBlock->Parent(this);
	mJBlock->Parent(this);
	mOBlock->Parent(this);
	mTBlock->Parent(this);
	mIBlock->Parent(this);
	/*mSBlock->Position(100.0f, 0.0f);
	mZBlock->Position(100.0f, 0.0f);
	mLBlock->Position(100.0f, 0.0f);
	mJBlock->Position(100.0f, 0.0f);
	mOBlock->Position(100.0f, 0.0f);
	mTBlock->Position(100.0f, 0.0f);
	mIBlock->Position(100.0f, 0.0f);*/

	/*mMoveSpeed = 100.0f;
	mMoveBounds = Vector2(50.0f, 500.0f);*/
}

Blocks::~Blocks() {

	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;

	delete mSBlock;
	mSBlock = nullptr;
	delete mZBlock;
	mZBlock = nullptr;
	delete mLBlock;
	mLBlock = nullptr;
	delete mJBlock;
	mJBlock = nullptr;
	delete mOBlock;
	mOBlock = nullptr;
	delete mTBlock;
	mTBlock = nullptr;
	delete mIBlock;
	mIBlock = nullptr;
}

//void Blocks::HandleMovement() {
//	if (mInput->KeyDown(SDL_SCANCODE_RIGHT)) {
//		Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
//	}
//	else if (mInput->KeyDown(SDL_SCANCODE_LEFT)) {
//		Translate(-Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
//	}
//	else if (mInput->KeyDown(SDL_SCANCODE_DOWN)) {
//		Translate(-Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
//	}
//	Vector2 pos = Position(Local);
//	if (pos.x < mMoveBounds.x + mSBlock->ScaledDimensions().x * 0.5f) {
//		pos.x = mMoveBounds.x + mSBlock ->ScaledDimensions().x * 0.5f;
//	}
//	else if (pos.x > mMoveBounds.y - mSBlock->ScaledDimensions().x * 0.5f) {
//		pos.x = mMoveBounds.y - mSBlock->ScaledDimensions().x * 0.5f;
//	}
//
//	Position(pos);
//}


//void Blocks::Visible(bool visible) {
//	mVisible = visible;
//}
//int Blocks::Score() {
//	return mScore;
//}
//
//void Blocks::AddScore(int change) {
//	mScore += change;
//}
//
//void Blocks::WasDown() {
//
//}


//Blocks::shape reverseCols(Blocks::shape s) {
//	Blocks::shape tmp = s;
//	for (int i = 0; i < s.size; i++) {
//		for (int j = 0; j < s.size / 2; j++) {
//			bool t = s.matrix[i][j];
//			tmp.matrix[i][j] = s.matrix[i][s.size - j - 1];
//			tmp.matrix[i][s.size - j - 1] = t;
//		}
//	}
//	return tmp;
//}
//
//Blocks::shape transpose(Blocks::shape s) {
//	Blocks::shape tmp = s;
//	for (int i = 0; i < s.size; i++) {
//		for (int j = 0; j < s.size; j++) {
//			tmp.matrix[i][j] = s.matrix[j][i];
//		}
//	}
//	return tmp;
//}
//
//void Rotate() {
//	currentBlock = reverseCols(transpose(currentBlock));
//}

void Blocks::Update() {
	/*if (Active()) {
		HandleMovement();
	}*/
}

void Blocks::Render() {
	//if (mVisible) {
	//	mSBlock->Render();
	//}
}