#include "KeyStater.h"
#include "BasicSprite.h"
#include "FontDraw.h"
#include "AnimSprite.h"

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

	float _a[4] =
	{
		15, 20,
		24, 9
	};
	float _b[4] =
	{
		40, 75,
		9, 14
	};
	float _c[4] =
	{
		113, 27,
		20, 20
	};

	AnimSprite animsprite(100, 100, "animtest.png", 30, 30, 4, _a, _b, _c, 224, 149);

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
		
		if (Keys.IsDown(VK_UP))
		{
			Ian.MoveSprite(0, 1);
		}
		if (Keys.IsDown(VK_DOWN))
		{
			Ian.MoveSprite(0, -1);
		}
		if (Keys.IsDown(VK_LEFT))
		{
			Ian.MoveSprite(-1, 0);
		}
		if (Keys.IsDown(VK_RIGHT))
		{
			Ian.MoveSprite(1, 0);
		}
		

		//draw code starts here
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//DRAW THING HERE
		animsprite.Draw(glfwGetTime());
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