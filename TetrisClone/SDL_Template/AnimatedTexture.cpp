#include "AnimatedTexture.h"

namespace SDLFramework {
	void AnimatedTexture::RunAnimation() {
		if (!mAnimationDone) {
			mAnimationTimer += mTimer->DeltaTime();

			if (mAnimationTimer >= mAnimationSpeed) {
				if (mWrapMode == Loop) {
					// reset timer, accounting for extra time
					mAnimationTimer -= mAnimationSpeed;
				}
				else {
					mAnimationDone = true;
					// back up the timer to the last frame
					mAnimationTimer = mAnimationSpeed - mTimePerFrame;
				}
			}

			if (mAnimationDirection == Horizontal) {
				mSourceRect.x = mStartX + (int)(mAnimationTimer / mTimePerFrame) * mWidth;
			}
			else {
				mSourceRect.y = mStartY + (int)(mAnimationTimer / mTimePerFrame) * mHeight;
			}
		}
	}

	AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, AnimDir animationDir, bool managed)
		: Texture(filename, x, y, w, h, managed) {
		mTimer = Timer::Instance();

		mStartX = x;
		mStartY = y;

		mFrameCount = frameCount;
		mAnimationSpeed = animationSpeed;
		mTimePerFrame = mAnimationSpeed / mFrameCount;
		mAnimationTimer = 0.0f;

		mWrapMode = Loop;
		mAnimationDirection = animationDir;

		mAnimationDone = false;
	}

	AnimatedTexture::~AnimatedTexture() { }

	void AnimatedTexture::SetWrapMode(WrapMode wrapMode) {
		mWrapMode = wrapMode;
	}

	void AnimatedTexture::ResetAnimation() {
		mAnimationTimer = 0.0f;
		mAnimationDone = false;
	}

	bool AnimatedTexture::IsAnimating() {
		return !mAnimationDone;
	}

	void AnimatedTexture::Update() {
		RunAnimation();
	}
}