#ifndef __GAMEOVER_H
#define __GAMEOVER_H

#include "PlayScreen.h"

using namespace SDLFramework;

class GameOver : public GameEntity {
private:
	AudioManager* mAudio;
	InputManager* mInput;

	GameEntity* mGameOver;
	PlaySideBar* mSideBar;
	PlayArea* mPlayArea;

	Texture* mGameOverTexture;
	Texture* mCursor;
	Texture* mPlease;
	Texture* mTry;
	Texture* mAgain;
	Texture* mContinue;
	Texture * mYes;
	Texture* mNo;

	SDL_Color mColor;

	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;

public:
	GameOver();
	~GameOver();

	void ChangeSelectedMode(int change);

	void Update() override;
	void Render() override;
};
#endif