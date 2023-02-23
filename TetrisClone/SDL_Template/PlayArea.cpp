#include "PlayArea.h"

PlayArea::PlayArea() {

    mPlayArea = new Texture("TetrisBackground.png", 0, 0, 105, 144);
    mPlayArea->Parent(this);
    mPlayArea->Scale(Vector2(6.0f, 6.0f));
}

PlayArea::~PlayArea() {
    delete mPlayArea;
    mPlayArea = nullptr;
}

void PlayArea::Update() {
   
}

void PlayArea::Render() {
    mPlayArea->Render();
}
