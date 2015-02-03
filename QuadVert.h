#ifndef QUADVERT_H
#define QUADVERT_H

#include <GL\glew.h>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <SOIL.h>
#include <iostream>
#include <GLFW\glfw3.h>
#include <vector>
#include <string>
#include <fstream>



class QuadVert
{
public:
	const char *vertexSource =
		"#version 150"
		"in vec2 position;"
		"void main()"
		"{"
		"gl_Position = vec4(position, 0.0, 1.0);"
		"}";
	const char *fragmentSource =
		"#version 150"
		"out vec4 outColor;"
		"void main()"
		"{"
		"outColor = vec4(1.0, 1.0, 1.0, 1.0);"
		"}";
	QuadVert();
	~QuadVert();
	GLuint vbo;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	float x[4];
	float y[4];
	void set(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3);

	float *verts();
};

#endif