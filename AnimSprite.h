#ifndef _ANIMSPRITE_H_
#define _ANIMSPRITE_H_

#include "BasicSprite.h"

class AnimSprite
{
public:
	BasicSprite sprite;
	int curFrame;
	double delay;
	float frame[3][4];

	//called in update if frame is to change, changes the UVs to next frame
	void CutUV();
	//call this ever frame to update the
	void Draw(double time);

	AnimSprite();
	AnimSprite(float x, float y, char* texture, int width, int height, int bpp, float* a, float* b, float* c, int _w, int _h);
	~AnimSprite();
};

#endif