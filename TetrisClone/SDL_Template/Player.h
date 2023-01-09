#ifndef __PLAYER_H
#define __PLAYER_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
//#include "Blocks.h"

using namespace SDLFramework;

class Player : public GameEntity {
private:
    Timer* mTimer;
    InputManager* mInput;
    AudioManager* mAudio;

    Texture* mBlock;
    /*Blocks* mBlock;*/

    bool mVisible;
    bool mInPlay;
    bool mIsDown;
    bool mNextBlock;

    int mScore;

    float mMoveSpeed;
    Vector2 mMove;
    Vector2 mMoveBoundsX;
    Vector2 mMoveBoundsY;

    void HandleMovement();

public:
    Player();
    ~Player();

    struct Block {
        Texture* mBlock;
        bool active;
    };

    struct Shape {
        Texture* mBlock;
        bool matrix[4][4];
        double x, y;
        int size;
    };

    Shape DisplayShape();

    void Visible(bool visible);
    void InPlay(bool inPlay);
    void NextBlock(bool nextBlock);

    int Score();
    void AddScore(int change);

    void IsDown(bool isDown);

    void Update() override;
    void Render() override;
};
#endif
