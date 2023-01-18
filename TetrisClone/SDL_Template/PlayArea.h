#ifndef __PLAYAREA_H
#define __PLAYAREA_H

#include "Texture.h"

using namespace SDLFramework;

class PlayArea : public GameEntity {
private:
	Texture* mPlayArea;

	Texture* mBlock;

	bool mGrid[18][10];
	Texture* mGridDisplay[18][10];

public:
	PlayArea();
	~PlayArea();

	
	void CheckForLines();

	void Update() override;
	void Render() override;
};



#endif
