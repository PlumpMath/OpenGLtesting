#include "BasicSprite.h"


BasicSprite::BasicSprite(float x, float y, char* texture, int width, int height, int bpp)
{
	init = true;
	QV.Initialize(x, y, texture, width, height, bpp);
}

BasicSprite::BasicSprite()
{

}

BasicSprite::BasicSprite(float x, float y, char* texture, int width, int height, int bpp, float* a)
{
	init = true;
	QV.Initialize(x, y, texture, width, height, bpp, a);
}

void BasicSprite::Initialize(float x, float y, char* texture, int width, int height, int bpp, float* a)
{
	init = true;
	QV.Initialize(x, y, texture, width, height, bpp, a);
}

BasicSprite::~BasicSprite()
{
}

void BasicSprite::Draw()
{
	//bind Texture
	glBindTexture(GL_TEXTURE_2D, QV.uiTextureId);
	glBindBuffer(GL_ARRAY_BUFFER, QV.uiVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, QV.uiIBO);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float)* 4));

	//now we have UVs to worry about, we need to send that info to the graphics card too
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float)* 8));

	//enable shaders
	glUseProgram(QV.uiProgramTextured);

	glBindBuffer(GL_ARRAY_BUFFER, QV.uiVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, QV.uiIBO);

	glUniformMatrix4fv(QV.MatrixIDFlat, 1, GL_FALSE, QV.orthographicProjection);

	//enable the vertex array states
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	/*Since the data is in the same array, we need to specify the gap between
	vertices (A whole Vertex structure instance) and the offset of the data
	from the beginning of the structure instance. The positions are at the
	start, so their offset is 0. But the colours are after the positions, so
	they are offset by the size of the position data */
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float)* 4));

	//draw to the screen
	glDrawArrays(GL_QUADS, 0, 4);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void BasicSprite::MoveSprite(float ax, float ay, double time)
{
	ax *= time;
	ay *= time;
	for (int i = 0; i < 4; i++)
	{
		QV.myShape[i].fPositions[0] += ax;
		QV.myShape[i].fPositions[1] += ay;
	}

	glBindBuffer(GL_ARRAY_BUFFER, QV.uiVBO);
	GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	//copy data to graphics card
	memcpy(vBuffer, QV.myShape, sizeof(Vertex)* 4);
	//unmap and unbind buffer
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}