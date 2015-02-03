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
	GLuint vao;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	float vertices[8];
};

#endif