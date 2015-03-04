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
	//float x, float y, char* texture, int width, int height, int bpp, float* a

	void CutUV();
	void Update(double time);
	void Draw(double time);

	AnimSprite();
	AnimSprite(float x, float y, char* texture, int width, int height, int bpp, float* a, float* b, float* c, int _w, int _h);
	~AnimSprite();
};

#endif