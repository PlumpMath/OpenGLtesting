#include "QuadVert.h"


QuadVert::QuadVert()
{

}
void QuadVert::Initialize(float x, float y, char* texture, int width, int height, int bpp)
{
	myShape = new Vertex[4];
	myShape[0].fPositions[0] = x + width;
	myShape[0].fPositions[1] = y + height;
	myShape[1].fPositions[0] = x + width;
	myShape[1].fPositions[1] = y;
	myShape[2].fPositions[0] = x;
	myShape[2].fPositions[1] = y;
	myShape[3].fPositions[0] = x;
	myShape[3].fPositions[1] = y + height;

	for (int i = 0; i < 4; i++)
	{
		myShape[i].fPositions[2] = 0.0f;
		myShape[i].fPositions[3] = 1.0f;
		myShape[i].fColours[0] = 1.0f;
		myShape[i].fColours[1] = 1.0f;
		myShape[i].fColours[2] = 1.0f;
		myShape[i].fColours[3] = 1.0f;
	}
	//set up the UVs
	myShape[0].fUVs[0] = 1.0f;
	myShape[0].fUVs[1] = 1.0f;
	myShape[1].fUVs[0] = 1.0f;
	myShape[1].fUVs[1] = 0.0f;
	myShape[2].fUVs[0] = 0.0f;
	myShape[2].fUVs[1] = 0.0f;
	myShape[3].fUVs[0] = 0.0f;
	myShape[3].fUVs[1] = 1.0f;

	glGenBuffers(1, &uiVBO);

	if (uiVBO != 0)
	{
		//bind VBO
		glBindBuffer(GL_ARRAY_BUFFER, uiVBO);
		//allocate space for vertices on the graphics card
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)* 4, NULL, GL_STATIC_DRAW);
		//get pointer to allocated space on the graphics card
		GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		//copy data to graphics card
		memcpy(vBuffer, myShape, sizeof(Vertex)* 4);
		//unmap and unbind buffer
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	glGenBuffers(1, &uiIBO);

	//check it succeeded
	if (uiIBO != 0)
	{
		//bind IBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, uiIBO);
		//allocate space for index info on the graphics card
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(char), NULL, GL_STATIC_DRAW);
		//get pointer to newly allocated space on the graphics card
		GLvoid* iBuffer = glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);
		//specify the order we'd like to draw our vertices.
		//In this case they are in sequential order
		for (int i = 0; i < 4; i++)
		{
			((char*)iBuffer)[i] = i;
		}
		//unmap and unbind
		glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	uiTextureId = loadTexture(texture, width, height, bpp);
	uiProgramTextured = CreateProgram("VertexShader.glsl", "TexturedFragmentShader.glsl");
	MatrixIDFlat = glGetUniformLocation(uiProgramTextured, "MVP");
	orthographicProjection = getOrtho(0, 1024, 0, 720, 0, 100);


	
}


QuadVert::~QuadVert()
{
}
