#ifndef FONTDRAW_H
#define FONTDRAW_H

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include "BasicSprite.h"
struct CharVec
{
	int charid;
	int x;
	int y;
	int width;
	int height;
	int xoffset;
	int yoffset;
};

class FontDraw
{
private:
	CharVec charload[95];
public:

	FontDraw();
	~FontDraw();
};

#endif