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

    struct Shape {
        bool mGrid[4][4];
        int size;
    };

    Shape currentShape;

    Texture* mShapeTexture[4][4];
    Shape mLShape = {
        { 
            {0,0,1,0}, // L BLOCK
            {1,1,1,0},
            {0,0,0,0},
            {0,0,0,0} 
        }, 3 
    };

    Shape mZShape = {
        {
            {1,1,0,0}, // Z BLOCK
            {0,1,1,0},
            {0,0,0,0},
            {0,0,0,0} 
        }, 3 
    };
    
    Shape mIShape = { 
        {
            {1,1,1,1,}, // I BLOCK
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
        }, 4
    };

    // J BLOCK
    Shape mJShape = { 
        {
            {1,0,0,0},
            {1,1,1,0},
            {0,0,0,0},
            {0,0,0,0}
        }, 3
    };

    // O BLOCK
    Shape mOShape = { 
        {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0}
        }, 2
    };

    // S BLOCK
    Shape mSShape = { 
        {
            {0,1,1,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0}
        }, 3
    };

    // T BLOCK
    Shape mTShape = { 
        {
            {0,1,0,0},
            {1,1,1,0},
            {0,0,0,0},
            {0,0,0,0}
        }, 3
    };

    bool temp[4][4];

    const int NUM_ARRAYS[7] = { 0, 1, 2, 3, 4, 5, 6 };
   
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
    
public:
    bool mShapeGrid[4][4];
    
    Player();
    ~Player();

    void Visible(bool visible);
    void InPlay(bool inPlay);

    void SetHeartbeat(int levels);
    float GetHeartBeat() { return mHeartBeat; }
    
    void HandleMovement();

    void UpdateShapeDimensions();

    Shape reverseCols(Shape s);
    Shape transpose(Shape s);
    void Rotate();

    int pixelToGridX(float x);
    int pixelToGridY(float y);
   /* bool PlayerPositionOnGrid(Vector2 position);*/

    void IsDown(bool isDown);
    bool GetIsDown() { return mIsDown; }

    int min(int a, int b);
    int max(int a, int b);

    //void rotate_shape();

    void Update() override;
    void Render() override;
};
#endif
