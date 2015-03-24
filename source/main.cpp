#include "KeyStater.h"
#include "BasicSprite.h"
#include "FontDraw.h"
#include "AnimSprite.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 720



int main()
{
	//Initialise key manager
	KeyStater Keys;

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
		//OpenGL didn't start-up! shutdown GLFW and return an error code
		glfwTerminate();
		return -1;
	}


	//creating text and sprites and UVs
	FontDraw thirdtext("ERROR^ERR*$@HUMAN*AR#//.HARMFUL TO HUMAN$PURGE(&%#", 100, 300);

	float rb[4] =
	{
		0.4, 0.4,
		0.45, 0.45
	};

	BasicSprite Rainbow(800, 200, "resources/rainbow.png", 64, 64, 4, rb);

	float ca[4] =
	{
		15, 20,
		24, 9
	};
	float cb[4] =
	{
		40, 75,
		9, 14
	};
	float cc[4] =
	{
		113, 27,
		20, 20
	};

	AnimSprite animsprite(100, 100, "resources/animtest.png", 30, 30, 4, ca, cb, cc, 224, 149, 0.1);

	BasicSprite Ian(500, 500, "resources/Ian.PNG", 32, 32, 3);
	
	//enableing alpha channel
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, .5);
	glEnable(GL_ALPHA);


	//initializing time
	glfwSetTime(0);
	//loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		double deltaTime = glfwGetTime();
		glfwSetTime(0);
		//Updating key handler
		Keys.Update();

		//Basic input checks and movement
		if (Keys.IsDown(VK_UP))
		{
			Ian.MoveSprite(0, 300, deltaTime);
		}
		if (Keys.IsDown(VK_DOWN))
		{
			Ian.MoveSprite(0, -300, deltaTime);
		}
		if (Keys.IsDown(VK_LEFT))
		{
			Ian.MoveSprite(-300, 0, deltaTime);
		}
		if (Keys.IsDown(VK_RIGHT))
		{
			Ian.MoveSprite(300, 0, deltaTime);
		}
		

		//draw code starts here
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//DRAW THING HERE
		animsprite.Draw(deltaTime);
		Rainbow.Draw();
		Ian.Draw();
		thirdtext.Draw();

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