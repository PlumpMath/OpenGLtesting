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
	charload[32].Set(0, 0, 10, 0, 0, 0);
	charload[33].Set(124, 65, 2, 20, 8, 6);
	charload[34].Set(216, 78, 8, 8, 6, 6);
	charload[35].Set(76, 25, 16, 20, 2, 6);
	charload[36].Set(64, 0, 14, 24, 2, 6);
	charload[37].Set(93, 25, 16, 20, 2, 6);
	charload[38].Set(110, 23, 16, 20, 2, 6);
	charload[39].Set(250, 63, 2, 8, 8, 6);
	charload[40].Set(33, 0, 6, 26, 8, 6);
	charload[41].Set(47, 0, 6, 26, 6, 6);
	charload[42].Set(186, 80, 14, 10, 2, 10);
	charload[43].Set(126, 86, 14, 14, 2, 10);
	charload[44].Set(0, 105, 8, 6, 6, 22);
	charload[45].Set(38, 105, 12, 2, 4, 16);
	charload[46].Set(14, 105, 4, 4, 8, 22);
	charload[47].Set(164, 63, 16, 16, 2, 8);
	charload[48].Set(65, 69, 12, 20, 4, 6);
	charload[49].Set(113, 67, 10, 20, 6, 6);
	charload[50].Set(39, 69, 12, 20, 4, 6);
	charload[51].Set(13, 69, 12, 20, 4, 6);
	charload[52].Set(0, 69, 12, 20, 4, 6);
	charload[53].Set(208, 42, 12, 20, 4, 6);
	charload[54].Set(52, 69, 12, 20, 4, 6);
	charload[55].Set(78, 69, 12, 20, 4, 6);
	charload[56].Set(26, 69, 12, 20, 4, 6);
	charload[57].Set(195, 42, 12, 20, 4, 6);
	charload[58].Set(245, 63, 4, 14, 8, 12);
	charload[59].Set(198, 63, 8, 16, 6, 12);
	charload[60].Set(153, 63, 10, 18, 4, 8);
	charload[61].Set(240, 78, 12, 6, 4, 14);
	charload[62].Set(142, 63, 10, 18, 4, 8);
	charload[63].Set(234, 42, 12, 20, 4, 6);
	charload[64].Set(94, 0, 16, 22, 2, 6);
	charload[65].Set(19, 27, 18, 20, 0, 6);
	charload[66].Set(225, 21, 14, 20, 2, 6);
	charload[67].Set(240, 21, 14, 20, 2, 6);
	charload[68].Set(0, 48, 14, 20, 2, 6);
	charload[69].Set(150, 42, 14, 20, 2, 6);
	charload[70].Set(165, 42, 14, 20, 2, 6);
	charload[71].Set(161, 21, 16, 20, 2, 6);
	charload[72].Set(0, 27, 18, 20, 0, 6);
	charload[73].Set(102, 67, 10, 20, 4, 6);
	charload[74].Set(144, 21, 16, 20, 2, 6);
	charload[75].Set(127, 21, 16, 20, 2, 6);
	charload[76].Set(15, 48, 14, 20, 2, 6);
	charload[77].Set(225, 0, 18, 20, 0, 6);
	charload[78].Set(206, 0, 18, 20, 0, 6);
	charload[79].Set(210, 21, 14, 20, 2, 6);
	charload[80].Set(90, 46, 14, 20, 2, 6);
	charload[81].Set(79, 0, 14, 24, 2, 6);
	charload[82].Set(178, 21, 16, 20, 2, 6);
	charload[83].Set(195, 21, 14, 20, 2, 6);
	charload[84].Set(149, 0, 18, 20, 0, 6);
	charload[85].Set(130, 0, 18, 20, 0, 6);
	charload[86].Set(38, 27, 18, 20, 0, 6);
	charload[87].Set(111, 0, 18, 20, 0, 6);
	charload[88].Set(187, 0, 18, 20, 0, 6);
	charload[89].Set(168, 0, 18, 20, 0, 6);
	charload[90].Set(135, 42, 14, 20, 2, 6);
	charload[91].Set(54, 0, 6, 26, 8, 6);
	charload[92].Set(181, 63, 16, 16, 2, 8);
	charload[93].Set(40, 0, 6, 26, 6, 6);
	charload[94].Set(201, 80, 14, 8, 2, 6);
	charload[95].Set(19, 105, 18, 2, 0, 28);
	charload[96].Set(9, 105, 4, 4, 6, 6);
	charload[97].Set(51, 90, 14, 14, 2, 12);
	charload[98].Set(30, 48, 14, 20, 2, 6);
	charload[99].Set(66, 90, 14, 14, 2, 12);
	charload[100].Set(45, 48, 14, 20, 2, 6);
	charload[101].Set(81, 90, 14, 14, 2, 12);
	charload[102].Set(221, 42, 12, 20, 4, 6);
	charload[103].Set(60, 48, 14, 20, 2, 12);
	charload[104].Set(75, 48, 14, 20, 2, 6);
	charload[105].Set(244, 0, 10, 20, 4, 6);
	charload[106].Set(11, 0, 10, 26, 2, 6);
	charload[107].Set(180, 42, 14, 20, 2, 6);
	charload[108].Set(91, 67, 10, 20, 4, 6);
	charload[109].Set(207, 63, 18, 14, 0, 12);
	charload[110].Set(96, 88, 14, 14, 2, 12);
	charload[111].Set(111, 88, 14, 14, 2, 12);
	charload[112].Set(105, 46, 14, 20, 2, 12);
	charload[113].Set(120, 44, 14, 20, 2, 12);
	charload[114].Set(19, 90, 16, 14, 2, 12);
	charload[115].Set(141, 84, 14, 14, 2, 12);
	charload[116].Set(127, 65, 14, 18, 2, 8);
	charload[117].Set(156, 82, 14, 14, 2, 12);
	charload[118].Set(0, 90, 18, 14, 0, 12);
	charload[119].Set(226, 63, 18, 14, 0, 12);
	charload[120].Set(171, 80, 14, 14, 2, 12);
	charload[121].Set(57, 27, 18, 20, 0, 12);
	charload[122].Set(36, 90, 14, 14, 2, 12);
	charload[123].Set(22, 0, 10, 26, 4, 6);
	charload[124].Set(61, 0, 2, 26, 8, 6);
	charload[125].Set(0, 0, 10, 26, 6, 6);
	charload[126].Set(225, 78, 14, 6, 2, 6);
	charload[127].Set(247, 42, 6, 20, 6, 6);
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
			tx += charload[(int)textToDraw[ii - 1]].width + 2;
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
