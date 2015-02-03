#include "QuadVert.h"


QuadVert::QuadVert()
{
	vertices[0] = -0.5f;
	vertices[1] = 0.5f;
	vertices[2] = -0.5f;
	vertices[3] = -0.5f;
	vertices[4] = 0.5f;
	vertices[5] = -0.5f;
	vertices[6] = 0.5f;
	vertices[7] = 0.5f;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(vertexShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glBindFragDataLocation(shaderProgram, 0, "outColor");

	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");

	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(posAttrib);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

}


QuadVert::~QuadVert()
{
}
