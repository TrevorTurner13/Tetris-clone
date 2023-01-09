#include "NintendoScreen.h"


NintendoScreen::NintendoScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	
	mNintendoScreen = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	mBackground = new Texture("Nintendo Gameboy logo.png", 20, 0, 7, 6);
	mNintendoLogo = new Texture("Nintendo Gameboy logo.png", 0, 0, 104, 16);

	mNintendoScreen->Parent(this);
	mBackground->Parent(mNintendoScreen);
	mNintendoLogo->Parent(mNintendoScreen);

	mBackground->Position(-Graphics::SCREEN_WIDTH, -Graphics::SCREEN_HEIGHT);
	mBackground->Scale(Vector2(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT));

	mNintendoLogo->Position(Graphics::SCREEN_WIDTH * 0.0f, 0.0f);
	mNintendoLogo->Scale(Vector2(6.0f, 6.0f));

	mAnimationStartPos = Vector2(0.0f, -Graphics::SCREEN_HEIGHT);
	mAnimationEndPos = Vec2_Zero;
	mAnimationTotalTime = 5.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;
	
	Position(mAnimationStartPos);

}

NintendoScreen::~NintendoScreen() {
	delete mBackground;
	mBackground = nullptr;
	delete mNintendoScreen;
	mNintendoScreen = nullptr;
	delete mNintendoLogo;
	mNintendoLogo = nullptr;
}

void NintendoScreen::Update() {
	if (!mAnimationDone) {

		mAnimationTimer += mTimer->DeltaTime();
		Position(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));

		if (mAnimationTimer >= mAnimationTotalTime) {
			mAnimationDone = true;
			mAudio->PlaySFX("SFX/Coin.wav", 0, -1);
		}
	}
}

void NintendoScreen::Render() {
	mBackground->Render();
	mNintendoLogo->Render();
}