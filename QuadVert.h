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

struct fUVs
{
	float UVx;
	float UVy;
};

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

	void Initialize(float x, float y, char* texture, int width, int height, int bpp);
	void Initialize(float x, float y, char* texture, int width, int height, int bpp, fUVs UV[4]);

	//create shader program
	GLuint uiProgramTextured;

	//find the position of the matrix variable in the shader so we can send info there later
	GLuint MatrixIDFlat;

	float *orthographicProjection;
	GLuint uiVBO;
	GLuint uiIBO;
	Vertex* myShape;
	float hold;
	QuadVert();
	~QuadVert();
};

#endif