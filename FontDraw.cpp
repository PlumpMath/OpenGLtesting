#include "FontDraw.h"


void CharVec::Set(int ax, int ay, int aw, int ah, int axo, int ayo)
{
	x = ax;
	y = ay;
	width = aw;
	height = ah;
	xoffset = axo;
	yoffset = ayo;
}

void CharVec::Zero()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	xoffset = 0;
	yoffset = 0;
}

void FontDraw::setDefault()
{
	int i = 97;
	charload[i].Set(51,90,14,14,2,12);
	i++;
	charload[i].Set(30,48,14,20,2,6);
	i++;
	charload[i].Set(66,90,14,14,2,12);	//99
	//do 100 through 122
}

FontDraw::FontDraw(char *todraw, float ax, float ay)
{
	for (int i = 0; i < 255; i++)
	{
		charload[i].Zero();
	}

	textToDraw = todraw;
	x = ax;
	y = ay;

	setDefault();

	FontSprites = new BasicSprite[strlen(textToDraw)];
	
	//OFFSETS STILL NEEDED
	for (int i = 0; i < strlen(textToDraw); i++)
	{
		float tx = x;
		for (int ii = i; ii > 0; ii--)
		{
			tx += charload[(int)textToDraw[ii - 1]].width;
		}

		FontSprites[i].Initialize(tx, y, "defaultfont.png", charload[(int)textToDraw[i]].width, charload[(int)textToDraw[i]].height, 3, getOGL(charload[(int)textToDraw[i]].x, charload[(int)textToDraw[i]].y, charload[(int)textToDraw[i]].width, charload[(int)textToDraw[i]].height));
	}

}

void FontDraw::Draw()
{
	for (int i = 0; i < strlen(textToDraw); i++)
	{
		FontSprites[i].Draw();
	}
}

FontDraw::~FontDraw()
{
}
