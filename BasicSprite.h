#ifndef BASICSPRITE_H
#define BASICSPRITE_H

#include "QuadVert.h"

//base sprite class to be used in entities and buttons
class BasicSprite
{
public:
	QuadVert QV;
	//false for declaring without initializing, checked if true then draw
	bool init = false;
	//declare it naked without initializing
	BasicSprite();
	//Initialize entire image with desired location, texture, size
	BasicSprite(float x, float y, char* texture, int width, int height, int bpp);
	//Initialize image selection with desired location, texture, size
	BasicSprite(float x, float y, char* texture, int width, int height, int bpp, float* a);
	//Initialize image selection with desired location, texture, size
	void Initialize(float x, float y, char* texture, int width, int height, int bpp, float* a);
	//move the sprite location by x over time and y over time
	void MoveSprite(float ax, float ay, double time);
	~BasicSprite();
	//remember to call this, it draws the fuckin thing
	void Draw();
};

#endif