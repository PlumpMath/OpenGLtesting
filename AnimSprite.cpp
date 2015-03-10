#include "AnimSprite.h"

void AnimSprite::CutUV()
{
	//cut out the UVs
	sprite.QV.myShape[0].fUVs[0] = frame[curFrame][2];	//X2
	sprite.QV.myShape[0].fUVs[1] = frame[curFrame][3];	//Y2
	//TOP RIGHT

	sprite.QV.myShape[1].fUVs[0] = frame[curFrame][2];	//X2
	sprite.QV.myShape[1].fUVs[1] = frame[curFrame][1];	//Y1
	//BOTTOM RIGHT

	sprite.QV.myShape[2].fUVs[0] = frame[curFrame][0];	//X1
	sprite.QV.myShape[2].fUVs[1] = frame[curFrame][1];	//Y1
	//BOTTOM LEFT

	sprite.QV.myShape[3].fUVs[0] = frame[curFrame][0];	//X1
	sprite.QV.myShape[3].fUVs[1] = frame[curFrame][3];	//Y2
	//TOP LEFT


	glBindBuffer(GL_ARRAY_BUFFER, sprite.QV.uiVBO);
	GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	//copy data to graphics card
	memcpy(vBuffer, sprite.QV.myShape, sizeof(Vertex)* 4);
	//unmap and unbind buffer
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void AnimSprite::Draw(double time)
{
	delay += time;
	if (delay > frameTime)
	{
		delay = 0;
		if (curFrame == 0)
		{
			curFrame = 1;
			CutUV();
		}
		else if (curFrame == 1)
		{
			curFrame = 2;
			CutUV();
		}
		else if (curFrame == 2)
		{
			curFrame = 0;
			CutUV();
		}
	}
	sprite.Draw();
}

AnimSprite::AnimSprite()
{

}

AnimSprite::AnimSprite(float x, float y, char* texture, int width, int height, int bpp, float* a, float* b, float* c, int _w, int _h, double aframetime)
{
	curFrame = 0;
	delay = 0;
	frameTime = aframetime;
	a = getOGL(a[0], a[1], a[2], a[3], _w, _h);
	b = getOGL(b[0], b[1], b[2], b[3], _w, _h);
	c = getOGL(c[0], c[1], c[2], c[3], _w, _h);

	for (int i = 0; i < 4; i++)
	{
		frame[0][i] = a[i];
		frame[1][i] = b[i];
		frame[2][i] = c[i];
	}
	sprite.Initialize(x, y, texture, width, height, bpp, a);
}

AnimSprite::~AnimSprite()
{

}