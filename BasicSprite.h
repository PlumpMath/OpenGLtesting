#ifndef BASICSPRITE_H
#define BASICSPRITE_H

#include "QuadVert.h"

//base sprite class
//to be used in entities and such
class BasicSprite
{
public:
	QuadVert QV;
	bool init = false;
	BasicSprite();
	BasicSprite(float x, float y, char* texture, int width, int height, int bpp);
	BasicSprite(float x, float y, char* texture, int width, int height, int bpp, float* a);
	//void Initialize(float x, float y, char* texture, int width, int height, int bpp);
	void Initialize(float x, float y, char* texture, int width, int height, int bpp, float* a);
	void MoveSprite(int b);
	~BasicSprite();
	void Draw();
};

#endif