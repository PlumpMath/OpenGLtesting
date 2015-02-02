#include <GL\glew.h>
//#include <GL\wglew.h>

#include "KeyStater.h"

#include <glm/fwd.hpp>
#include <glm/glm.hpp>

#include <SOIL.h>

#include <iostream>

#include <GLFW\glfw3.h>
#include <vector>
#include <string>
#include <fstream>
#include "Utils.h"

int main()
{
	//Initialise GLFW

	if (!glfwInit())
	{
		return -1;
	}

	//create a windowed mode window and it's OpenGL context
	GLFWwindow* window;
	window = glfwCreateWindow(windowWidth, windowHeight, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	//make the window's context current
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		// OpenGL didn't start-up! shutdown GLFW and return an error code
		glfwTerminate();
		return -1;
	}


	//loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		Update();

		//draw code goes here
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);




		//swap front and back buffers
		glfwSwapBuffers(window);

		//poll for and process events
		glfwPollEvents();
		if (Keys.IsPressed(VK_ESCAPE))
			glfwSetWindowShouldClose(window, GL_TRUE);
	}

	glfwTerminate();
	return 0;
}

void Update()
{
	Keys.Update();

}