#ifndef FONTDRAW_H
#define FONTDRAW_H

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include "BasicSprite.h"
#include "libs\tinyxml2-master\tinyxml2.h"

struct CharVec
{
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
	CharVec charload[255];
public:
	BasicSprite FontSprites;
	FontDraw(char *todraw, float x, float y);
	~FontDraw();
};

#endif