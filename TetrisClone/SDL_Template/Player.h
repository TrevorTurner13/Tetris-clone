#ifndef __PLAYER_H
#define __PLAYER_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "PlayArea.h"

using namespace SDLFramework;

class Player : public GameEntity {
public:
    struct Shape {
        bool mGrid[4][4];
        int size;
    };

    Shape currentShape;
    Shape tempShape;

private:
    Timer* mTimer;
    InputManager* mInput;
    AudioManager* mAudio;

    Texture* mBlock;
    PlayArea* mPlayArea;
    Texture* mShapeTexture[4][4];

    Shape mLShape;
    Shape mZShape;
    Shape mIShape;
    Shape mJShape;
    Shape mOShape;
    Shape mSShape;
    Shape mTShape;

    const int NUM_ARRAYS[7] = { 0, 1, 2, 3, 4, 5, 6 };
   
    float mShapeWidth;
    float mShapeHeight;

    bool mVisible;
    bool mIsDown;
    bool mCurrentShapeIsIShape;
    
    Vector2 mMove;   
    Vector2 mMoveBoundsX;
    Vector2 mMoveBoundsY;

    float mHeartBeat;
    float mHeartBeatFast;
    float mHeartBeatSlow;
    float mHeartBeatCurrent;
    bool mHeartBeatUpdate;
    
    bool mPlayGridCopy[18][10];

    
public:
    Player();
    ~Player();

    void Visible(bool visible);
    void SetHeartbeat(int levels);
    float GetHeartBeat() { return mHeartBeat; }
    void SetCopyGrid(bool playGrid[18][10]);
    
    void HandleMovement();

    void UpdateShapeDimensions();

    Shape reverseCols(Shape s);
    Shape transpose(Shape s);
    Shape translate(Shape s);
    void Rotate();

    int pixelToGridX(float x);
    int pixelToGridY(float y);

    void IsDown(bool isDown);
    bool GetIsDown() { return mIsDown; }

    int min(int a, int b);
    int max(int a, int b);

    bool CheckCollisionGPT();
    bool CheckCollisionLeft();
    bool CheckCollisionRight();
    //bool CheckCopyGridTrue(int x, int y);

    void Update() override;
    void Render() override;
};
#endif
