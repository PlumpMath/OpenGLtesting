#ifndef BASICSPRITE_H
#define BASICSPRITE_H

#include "QuadVert.h"

class BasicSprite
{
public:
	QuadVert QV;
	bool init = false;
	BasicSprite();
	BasicSprite(float x, float y, char* texture, int width, int height, int bpp);
	BasicSprite(float x, float y, char* texture, int width, int height, int bpp, fUVs UV[4]);
	//void Initialize(float x, float y, char* texture, int width, int height, int bpp);
	void Initialize(float x, float y, char* texture, int width, int height, int bpp, fUVs UV[4]);
	void MoveSprite(bool);
	~BasicSprite();
	void Draw();
};

#endif