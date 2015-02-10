#ifndef BASICSPRITE_H
#define BASICSPRITE_H

#include "QuadVert.h"

class BasicSprite
{
public:
	QuadVert QV;
	BasicSprite(float x, float y, char* texture, int width, int height, int bpp);
	void MoveSprite(bool);
	BasicSprite();
	~BasicSprite();
	void Draw();
};

#endif