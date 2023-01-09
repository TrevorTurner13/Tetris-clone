#include "PlaySideBar.h"

PlaySideBar::PlaySideBar() {
    mTimer = Timer::Instance();
    mAudio = AudioManager::Instance();

    mBackground = new Texture("TetrisBackground.png", 105, 0, 55, 144);
    mBackground->Parent(this);
    mBackground->Scale(Vector2(6.0f, 6.0f));

    mScore = new Scoreboard();
    mScore->Parent(this);
    mScore->Position(Graphics::SCREEN_WIDTH * 0.125f, -Graphics::SCREEN_HEIGHT * 0.31f);

    mLevelsLabel = new Scoreboard();
    mLevelsLabel->Parent(this);
    mLevelsLabel->Position(Graphics::SCREEN_WIDTH* 0.1f, -Graphics::SCREEN_HEIGHT * 0.075f);
    mLevels = 0;

    mLinesLabel = new Scoreboard();
    mLinesLabel->Parent(this);
    mLinesLabel->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.085f);
    mLines = 0;
}

PlaySideBar::~PlaySideBar() {
    mTimer = nullptr;
    mAudio = nullptr;

    delete mBackground;
    mBackground = nullptr;

    delete mScore;
    mScore = nullptr;
    delete mLevelsLabel;
    mLevelsLabel = nullptr;
    delete mLinesLabel;
    mLinesLabel = nullptr;

   
}

void PlaySideBar::Update() {
}

void PlaySideBar::Render() {
    mBackground->Render();
    mScore->Render();
    mLevelsLabel->Render();
    mLinesLabel->Render();
}

void PlaySideBar::SetScore(int score) {
    mScore->Score(score);
}

void PlaySideBar::SetLevel(int lines) {
    static const int requiredLines[] = {
        0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110 , 120, 130, 140, 150, 160, 170, 180, 190, 200
    };
    while (lines >= requiredLines[mLevels]) {
        ++mLevels;
    }
    mLevelsLabel->Score(mLevels);
}

void PlaySideBar::SetLines(int lines) {
    mLinesLabel->Score(lines);

}
//void PlaySideBar::ClearLevels() {
//    SetLevel(0);
//}
//
//void PlaySideBar::UpdateLevels() {
//    if (mLines >= 200)
//}