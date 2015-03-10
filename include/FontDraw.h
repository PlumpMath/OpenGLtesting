#ifndef FONTDRAW_H
#define FONTDRAW_H

#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include "BasicSprite.h"

///Base struct for holding individual font data

struct CharVec
{
	int x;
	int y;
	int width;
	int height;
	int xoffset;
	int yoffset;
	///initializes all parts of charvec to zero before setting, called in initializer of FontDraw, meant for chars the fontmap doesn't support, is handled when drawn
	void Zero();
	void Set(int ax, int ay, int aw, int ah, int axo, int ayo);
};

///class to draw the font

class FontDraw
{
private:
	///to store all the uv data for the characters
	CharVec charload[255];
public:
	///making a sprite for the fontmap
	BasicSprite* FontSprites;
	///the text to be drawn
	char* textToDraw;

	float x, y;

	///default uv values for default fontmap
	void setDefault();

	//call this to actually draw the text, handles out of bounds and non-existant chars on fontmap
	void Draw();
	/// initializes all char uv to zero then sets text to be drawn and position, then creates texture with default fontmap
	FontDraw(char *todraw, float x, float y);
	~FontDraw();
};

#endif