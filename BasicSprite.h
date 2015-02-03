#ifndef BASICSPRITE_H
#define BASICSPRITE_H

#include "QuadVert.h"

class BasicSprite
{
public:
	QuadVert QV;
	BasicSprite();
	~BasicSprite();
	void Draw();
};

#endif