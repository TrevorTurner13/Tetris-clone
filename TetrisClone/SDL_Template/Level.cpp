//#include "Level.h"
//
//void Level::StartStage() {
//    mStageStarted = true;
//}
//
//Level::Level(int stage, PlaySideBar* sideBar, Player* player) {
//    mTimer = Timer::Instance();
//    mSideBar = sideBar;
//    mSideBar->SetLevel(stage);
//
//    mStage = stage;
//    mStageStarted = false;
//
//    mPlayer = player;
//
//}
//
//Level::~Level() {
//    mTimer = nullptr;
//    mSideBar = nullptr;
//    mPlayer = nullptr;
//}
//
//void Level::Update() {
//    mPlayer->Active(true);
//    mPlayer->Visible(true);
//
//}
//
//void Level::Render() {
//
//}
