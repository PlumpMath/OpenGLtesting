#ifndef BASICSPRITE_H
#define BASICSPRITE_H

#include "QuadVert.h"

class BasicSprite
{
public:
	QuadVert QV;
	BasicSprite(float, float, char*, int, int, int);
	void MoveSprite(bool);
	BasicSprite();
	~BasicSprite();
	void Draw();
};

#endif