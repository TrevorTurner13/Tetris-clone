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

    Texture* mShapeTexture[4][4];
    bool mLShape[4][4] = { {0,0,1,0} // L BLOCK
                       ,{1,1,1,0}
                       ,{0,0,0,0}
                       ,{0,0,0,0}
    };
    bool mZShape[4][4] = { {1,1,0,0} // Z BLOCK
                        ,{0,1,1,0}
                        ,{0,0,0,0}
                        ,{0,0,0,0}
    };
    bool mIShape[4][4] = { {1,1,1,1,} // I BLOCK
                        ,{0,0,0,0}
                        ,{0,0,0,0}
                        ,{0,0,0,0}
    };
    // J BLOCK
    bool mJShape[4][4] = { {1,0,0,0}
                        ,{1,1,1,0}
                        ,{0,0,0,0}
                        ,{0,0,0,0}
    };
    // O BLOCK
    bool mOShape[4][4] = { {1,1,0,0}
                        ,{1,1,0,0}
                        ,{0,0,0,0}
                        ,{0,0,0,0}
    };
    // S BLOCK
    bool mSShape[4][4] = { {0,1,1,0}
                        ,{1,1,0,0}
                        ,{0,0,0,0}
                        ,{0,0,0,0}
    };
    // T BLOCK
    bool mTShape[4][4] = { {0,1,0,0}
                        ,{1,1,1,0}
                        ,{0,0,0,0}
                        ,{0,0,0,0}
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

   /* struct Block {
        Texture* mBlock;
        bool active;
    };

    struct Shape {
        Texture* mBlock[4][4];
        bool matrix[4][4];
        double x, y;
        int size;
    };
    
    Shape currentShape{};
    Shape blocks{};*/

   /* Texture* reverseCols(Texture* s);
    Texture* transpose(Texture* s);
    void Rotate();*/

    
    void HandleMovement();

    void UpdateShapeDimensions();

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
