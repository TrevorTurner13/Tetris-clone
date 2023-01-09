#include "Legal.h"

LegalScreen::LegalScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	mLegalScreen = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT* 0.5f);
	mLegal = new Texture("TetrisGameboy.png", 3, 3, 160, 144);

	mLegalScreen->Parent(this);
	mLegal->Parent(mLegalScreen);

	mLegal->Position(Graphics::SCREEN_WIDTH * 0.0f, 0.0f);
	mLegal->Scale(Vector2(6.0f, 6.0f));
	

}

LegalScreen::~LegalScreen() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mLegalScreen;
	mLegalScreen = nullptr;
	delete mLegal;
	mLegal = nullptr;
}

void LegalScreen::Update() {
	mLegal->Update();
}

void LegalScreen::Render() {
	mLegal->Render();
}