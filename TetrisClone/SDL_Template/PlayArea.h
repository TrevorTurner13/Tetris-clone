#ifndef __PLAYAREA_H
#define __PLAYAREA_H

#include "Texture.h"

using namespace SDLFramework;

class PlayArea : public GameEntity {
private:
	Texture* mPlayArea;

public:
	PlayArea();
	~PlayArea();

	void Update() override;
	void Render() override;
};



#endif
