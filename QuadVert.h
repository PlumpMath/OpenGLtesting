#ifndef QUADVERT_H
#define QUADVERT_H

#include <GL\glew.h>
#include <GL\wglew.h>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <SOIL.h>
#include <iostream>
#include <GLFW\glfw3.h>
#include <vector>
#include <string>
#include <fstream>

#define SPRITE_DEFAULT 0
#define SPRITE_NONE 1

GLuint CreateShader(GLenum a_eShaderType, const char *a_strShaderFile);

GLuint CreateProgram(const char *a_vertex, const char *a_frag);

unsigned int loadTexture(const char* a_pFilename, int & a_iWidth, int & a_iHeight, int & a_iBPP);

float* getOrtho(float left, float right, float bottom, float top, float a_fNear, float a_fFar);

//256 BY 256 ONLY, used by default for fontsheet
float* getOGL(float ax, float ay, float aw, float ah);

//UPPER LEFT CORNER OF SELECTION IN RELATION TO UPPER LEFT CORNER OF IMAGE, X, Y, W, H, IMAGE W, IMAGE H
float* getOGL(float ax, float ay, float aw, float ah, int iwidth, int iheight);

//vertex struct to hold position, color, uv data
struct Vertex
{
	float fPositions[4];
	float fColours[4];
	float fUVs[2];
};

struct QuadVert
{

public:
	GLuint uiTextureId;
	float *orthographicProjection;
	GLuint uiProgramTextured;
	GLuint MatrixIDFlat;
	GLuint uiVBO;
	GLuint uiIBO;
	Vertex* myShape;

	//Initialize entire image with desired location, texture, size
	void Initialize(float x, float y, char* texture, int width, int height, int bpp);

	//Initialize image selection with desired location, texture, size
	void Initialize(float x, float y, char* texture, int width, int height, int bpp, float* a);


	QuadVert();
	~QuadVert();
};

#endif