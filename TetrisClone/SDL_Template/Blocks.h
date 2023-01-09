//#ifndef __BLOCKS_H
//#define __BLOCKS_H
//#include "AnimatedTexture.h"
//#include "AudioManager.h"
//#include "InputManager.h"
//#include "Timer.h"
//
//using namespace SDLFramework;
//
//class Blocks : public GameEntity {
//private:
//	InputManager* mInput;
//	AudioManager* mAudio;
//	Timer* mTimer;
//
//	bool mVisible;
//	
//	int mScore;
//
//	Texture* mSBlock;
//	Texture* mZBlock;
//	Texture* mLBlock;
//	Texture* mJBlock;
//	Texture* mOBlock;
//	Texture* mTBlock;
//	Texture* mIBlock;
//
//	float mMoveSpeed;
//	Vector2 mMoveBounds;
//
//	void HandleMovement();
//	
//public:
//	Blocks();
//	~Blocks();
//
//	void Visible(bool visible);
//	bool IsAnimating();
//
//	int Score();
//	void AddScore(int change);
//	void WasDown();
//
//	struct block {
//		Texture* mBlock;
//		bool active;
//	};
//
//	struct shape {
//		Texture* mBlock;
//		bool matrix[4][4];
//		double x, y;
//		int size;
//	};
//	shape reverseCols(shape s);
//	shape Transpose(shape s);
//	void Rotate();
//
//	void Update() override;
//	void Render() override;
//};
//
//#endif
