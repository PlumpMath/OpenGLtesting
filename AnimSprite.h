#ifndef _ANIMSPRITE_H_
#define _ANIMSPRITE_H_

#include "BasicSprite.h"

///class to hold and handle animated sprites

class AnimSprite
{
public:
	///giving it a sprite
	BasicSprite sprite;
	///current frame as an int
	int curFrame;
	///time needed to switch frames
	double frameTime;
	///time since frame switch
	double delay;
	///UV data for frames
	float frame[3][4];

	///called in draw if delay is larger than frameTime, changes the UVs to next frame
	void CutUV();
	///draw's the sprite
	void Draw(double time);

	///empty initializer
	AnimSprite();
	///position, texture, draw size, bpp, UVs, image size, animation speed
	AnimSprite(float x, float y, char* texture, int width, int height, int bpp, float* a, float* b, float* c, int _w, int _h, double aframetime);
	~AnimSprite();
};

#endif