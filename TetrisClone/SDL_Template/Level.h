//#ifndef __LEVEL_H
//#define __LEVEL_H
//#include "PlaySideBar.h"
//#include "Player.h"
//
//class Level : public GameEntity {
//public:
//    enum LevelStates { Running, Finished, GameOver };
//
//private:
//    Timer* mTimer;
//    GameEntity* mPlayArea;
//    PlaySideBar* mSideBar;
//    Player* mPlayer;
//
//    int mStage;
//    bool mStageStarted;
//
//    float mLabelTimer;
//
//    Scoreboard* mStageNumber;
//    float mStageSpeedUpdate;
//
//    void StartStage();
//
//public:
//    Level(int stage, PlaySideBar* sideBar, Player* player);
//    ~Level();
//
//    void Update() override;
//    void Render() override;
//};
//#endif