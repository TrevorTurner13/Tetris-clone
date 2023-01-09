#ifndef __SCOREBOARD_H
#define __SCOREBOARD_H
#include "Texture.h"
#include <vector>

using namespace SDLFramework;

class Scoreboard : public GameEntity {
private:
    std::vector<Texture*> mScore;

    SDL_Color mColor;

public:
    Scoreboard();
    Scoreboard(SDL_Color color);
    ~Scoreboard();

    void Score(int score);

    void Render();

private:
    void ClearBoard();
};
#endif
