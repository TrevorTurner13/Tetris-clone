#ifndef __PLAYSIDEBAR_H
#define __PLAYSIDEBAR_H
#include "Timer.h"
#include "Scoreboard.h"
#include "AudioManager.h"


class PlaySideBar : public GameEntity {
private:
    Timer* mTimer;
    AudioManager* mAudio;

    Texture* mBackground; 

    Scoreboard* mScore;
    Scoreboard* mLevelsLabel;
    int mLevels;
    Scoreboard* mLinesLabel;
    int mLines;

    void LevelUp();

public:
    PlaySideBar();
    ~PlaySideBar();

    void SetScore(int score);
    void SetLevel(int levels);
    void SetLines(int lines);
    int GetLines() { return mLines; }
    int GetLevels() { return mLevels; }

    void Update() override;
    void Render() override;
};
#endif
