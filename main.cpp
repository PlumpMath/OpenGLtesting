#include "KeyStater.h"
#include "BasicSprite.h"
#include "AnimSprite.h"
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 720





KeyStater Keys;

//declaring vertex struct



int main()
{
	//Initialise GLFW

	if (!glfwInit())
	{
		return -1;
	}
	//create a windowed mode window and it's OpenGL context
	GLFWwindow* window;
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, ":ian:   :revolver: :honkman:", NULL, NULL);
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

	char* char_a = "fuckinshitm8y";
	char char_b = char_a[13];
	int int_a = (int)char_b; 
	BasicSprite Ian(500, 500, "Ian.PNG", 32, 32, 4);
	BasicSprite Rainbow(800, 200, "rainbow.png", 64, 64, 4);
	BasicSprite FontMapTest(0, 0, "defaultfont.png", 256, 256, 3);


	glfwSetTime(0);
	//loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		Keys.Update();
		/*
		if (Keys.IsDown(VK_UP))
		{
			for (int i = 0; i < 4; i++)
			{
				myShape[i].fPositions[1] += .1f;
			}
			glBindBuffer(GL_ARRAY_BUFFER, uiVBO);
			GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
			//copy data to graphics card
			memcpy(vBuffer, myShape, sizeof(Vertex)* 3);
			//unmap and unbind buffer
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		if (Keys.IsDown(VK_DOWN))
		{
			for (int i = 0; i < 4; i++)
			{
				myShape[i].fPositions[1] -= .1f;
			}
			glBindBuffer(GL_ARRAY_BUFFER, uiVBO);
			GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
			//copy data to graphics card
			memcpy(vBuffer, myShape, sizeof(Vertex)* 3);
			//unmap and unbind buffer
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		if (Keys.IsDown(VK_LEFT))
		{
			for (int i = 0; i < 4; i++)
			{
				myShape[i].fPositions[0] -= .1f;
			}
			glBindBuffer(GL_ARRAY_BUFFER, uiVBO);
			GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
			//copy data to graphics card
			memcpy(vBuffer, myShape, sizeof(Vertex)* 3);
			//unmap and unbind buffer
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		if (Keys.IsDown(VK_RIGHT))
		{
			for (int i = 0; i < 4; i++)
			{
				myShape[i].fPositions[0] += .1f;
			}
			glBindBuffer(GL_ARRAY_BUFFER, uiVBO);
			GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
			//copy data to graphics card
			memcpy(vBuffer, myShape, sizeof(Vertex)* 3);
			//unmap and unbind buffer
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		*/

		//draw code starts here
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//DRAW THINGS HERE
		Ian.Draw();
		Rainbow.Draw();
		FontMapTest.Draw();
		//swap front and back buffers
		glfwSwapBuffers(window);

		//poll for and process events
		glfwPollEvents();
		if (Keys.IsPressed(VK_ESCAPE))
			glfwSetWindowShouldClose(window, GL_TRUE);
		glfwSetTime(0);
	}


	glDeleteBuffers(1, &Ian.QV.uiIBO);

	glfwTerminate();
	return 0;
}