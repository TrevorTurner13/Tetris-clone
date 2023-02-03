#ifndef __PLAYER_H
#define __PLAYER_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "PlayArea.h"
//#include "Blocks.h"

using namespace SDLFramework;

class Player : public GameEntity {
private:
  
    Timer* mTimer;
    InputManager* mInput;
    AudioManager* mAudio;

    Texture* mBlock;
    PlayArea* mPlayArea;
    /*Blocks* mBlock;*/

    Texture* mShape[4][4];
    
    float mShapeWidth;
    float mShapeHeight;

    bool mVisible;
    bool mInPlay;
    bool mIsDown;
    bool mNextBlock;

    int mScore;

    float mMoveSpeed;
    Vector2 mDropSpeed;
    Vector2 mMove;
   
    Vector2 mMoveBoundsX;
    Vector2 mMoveBoundsY;

    float mHeartBeat = 1.0;
    float mHeartBeatCurrent = mHeartBeat;
    bool mHeartBeatUpdate = false;

    struct Block;
    struct Shape;

public:
    bool mShapeGrid[4][4];

    Player();
    ~Player();

    float GetPlayerGrid();
    void Visible(bool visible);
    void InPlay(bool inPlay);
    void NextBlock(bool nextBlock);
    void CheckShape();
    void HandleMovement();

    void UpdateShapeDimensions();

    int Score();
    void AddScore(int change);
    int pixelToGridX(float x);
    int pixelToGridY(float y);
   /* bool PlayerPositionOnGrid(Vector2 position);*/

    void IsDown(bool isDown);
    bool GetIsDown() { return mIsDown; }

    int min(int a, int b);
    int max(int a, int b);

    void rotate_shape();

    void Update() override;
    void Render() override;
};
#endif
