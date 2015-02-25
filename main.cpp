#include "KeyStater.h"
#include "BasicSprite.h"
#include "FontDraw.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 720

KeyStater Keys;

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
	
	FontDraw thirdtext("abcba", 500, 300);

	float rb[4] =
	{
		.4, .4,
		.45, .45
	};

	BasicSprite Rainbow(800, 200, "rainbow.png", 64, 64, 4, rb);



	BasicSprite Ian(500, 500, "Ian.PNG", 32, 32, 3);
	
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, .5);
	glEnable(GL_ALPHA);

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
		Rainbow.Draw();
		Ian.Draw();
		thirdtext.Draw();

		//swap front and back buffers
		glfwSwapBuffers(window);

		//poll for and process events
		glfwPollEvents();
		if (Keys.IsPressed(VK_ESCAPE))
			glfwSetWindowShouldClose(window, GL_TRUE);
		glfwSetTime(0);
	}



	glfwTerminate();
	return 0;
}