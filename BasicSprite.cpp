#include "BasicSprite.h"

BasicSprite::BasicSprite()
{
	QV.set(-0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, 0.5f, 0.5f);
	glGenBuffers(1, &QV.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, QV.vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(QV.verts()), QV.verts(), GL_DYNAMIC_DRAW);

	QV.vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(QV.vertexShader, 1, &QV.vertexSource, NULL);
	glCompileShader(QV.vertexShader);

	QV.fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(QV.fragmentShader, 1, &QV.fragmentSource, NULL);
	glCompileShader(QV.vertexShader);

	QV.shaderProgram = glCreateProgram();
	glAttachShader(QV.shaderProgram, QV.vertexShader);
	glAttachShader(QV.shaderProgram, QV.fragmentShader);

}


BasicSprite::~BasicSprite()
{
}
