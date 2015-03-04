#include "QuadVert.h"

GLuint CreateShader(GLenum a_eShaderType, const char *a_strShaderFile)
{
	std::string strShaderCode;
	//open shader file
	std::ifstream shaderStream(a_strShaderFile);
	//if that worked ok, load file line by line
	if (shaderStream.is_open())
	{
		std::string Line = "";
		while (std::getline(shaderStream, Line))
		{
			strShaderCode += "\n" + Line;
		}
		shaderStream.close();
	}


	//convert to cstring
	char const *szShaderSourcePointer = strShaderCode.c_str();

	//create shader ID
	GLuint uiShader = glCreateShader(a_eShaderType);
	//load source code
	glShaderSource(uiShader, 1, &szShaderSourcePointer, NULL);

	//compile shader
	glCompileShader(uiShader);

	//check for compilation errors and output them
	GLint iStatus;
	glGetShaderiv(uiShader, GL_COMPILE_STATUS, &iStatus);
	if (iStatus == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(uiShader, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(uiShader, infoLogLength, NULL, strInfoLog);

		const char *strShaderType = NULL;
		switch (a_eShaderType)
		{
		case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
		case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
		}

		fprintf(stderr, "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
		delete[] strInfoLog;
	}

	return uiShader;
}

GLuint CreateProgram(const char *a_vertex, const char *a_frag)
{
	std::vector<GLuint> shaderList;

	shaderList.push_back(CreateShader(GL_VERTEX_SHADER, a_vertex));
	shaderList.push_back(CreateShader(GL_FRAGMENT_SHADER, a_frag));

	//create shader program ID
	GLuint uiProgram = glCreateProgram();

	//attach shaders
	for (auto shader = shaderList.begin(); shader != shaderList.end(); shader++)
		glAttachShader(uiProgram, *shader);

	//link program
	glLinkProgram(uiProgram);

	//check for link errors and output them
	GLint status;
	glGetProgramiv(uiProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(uiProgram, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(uiProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}

	for (auto shader = shaderList.begin(); shader != shaderList.end(); shader++)
	{
		glDetachShader(uiProgram, *shader);
		glDeleteShader(*shader);
	}

	return uiProgram;
}

unsigned int loadTexture(const char* a_pFilename, int & a_iWidth, int & a_iHeight, int & a_iBPP)
{
	unsigned int uiTextureID = 0;
	//check file exists
	if (a_pFilename != nullptr)
	{
		//read in image data from file
		unsigned char* pImageData = SOIL_load_image(a_pFilename, &a_iWidth, &a_iHeight, &a_iBPP, SOIL_LOAD_AUTO);

		//check for successful read
		if (pImageData)
		{
			//create opengl texture handle
			uiTextureID = SOIL_create_OGL_texture(pImageData, a_iWidth, a_iHeight, a_iBPP,
				SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
			//clear what was read in from file now that it is stored in the handle
			SOIL_free_image_data(pImageData);
		}

		//check for errors
		if (uiTextureID == 0)
		{
			std::cerr << "SOIL loading error: " << SOIL_last_result() << std::endl;
		}
		return uiTextureID;
	}
}

//256 BY 256 ONLY
float* getOGL(float ax, float ay, float aw, float ah)
{
	//Takes the x, y, width, and height of desired section of the image and returns the correct UV
	float * rf = new float[4];

	rf[0] = ax / 256;					//X1
	rf[3] = (256 - ay) / 256;			//Y1
	rf[2] = (ax + aw) / 256;			//X2
	rf[1] = ((256 - ay) - ah) / 256;	//Y2

	return rf;
}

//UPPER LEFT CORNER OF SELECTION IN RELATION TO UPPER LEFT CORNER OF IMAGE, X, Y, W, H, IMAGE W, IMAGE H
float* getOGL(float ax, float ay, float aw, float ah, int iw, int ih)
{
	//Takes the x, y, width, and height of desired section of the image and returns the correct UV
	float * rf = new float[4];

	rf[0] = ax / iw;					//X1
	rf[3] = (ih - ay) / ih;				//Y1
	rf[2] = (ax + aw) / iw;				//X2
	rf[1] = ((ih - ay) - ah) / ih;		//Y2

	return rf;
}

float* getOrtho(float left, float right, float bottom, float top, float a_fNear, float a_fFar)
{
	//to correspond with mat4 in the shader
	//ideally this function would be part of your matrix class
	//however I wasn't willing to write your matrix class for you just to show you this
	//so here we are in array format!
	//add this to your matrix class as a challenge if you like!
	float* toReturn = new float[12];
	toReturn[0] = 2.0 / (right - left);;
	toReturn[1] = toReturn[2] = toReturn[3] = toReturn[4] = 0;
	toReturn[5] = 2.0 / (top - bottom);
	toReturn[6] = toReturn[7] = toReturn[8] = toReturn[9] = 0;
	toReturn[10] = 2.0 / (a_fFar - a_fNear);
	toReturn[11] = 0;
	toReturn[12] = -1 * ((right + left) / (right - left));
	toReturn[13] = -1 * ((top + bottom) / (top - bottom));
	toReturn[14] = -1 * ((a_fFar + a_fNear) / (a_fFar - a_fNear));
	toReturn[15] = 1;
	return toReturn;
}

QuadVert::QuadVert()
{

}

void QuadVert::Initialize(float x, float y, char* texture, int width, int height, int bpp)
{
	myShape = new Vertex[4];
	myShape[0].fPositions[0] = x + width;
	myShape[0].fPositions[1] = y + height;
	myShape[1].fPositions[0] = x + width;
	myShape[1].fPositions[1] = y;
	myShape[2].fPositions[0] = x;
	myShape[2].fPositions[1] = y;
	myShape[3].fPositions[0] = x;
	myShape[3].fPositions[1] = y + height;

	for (int i = 0; i < 4; i++)
	{
		myShape[i].fPositions[2] = 0.0f;
		myShape[i].fPositions[3] = 1.0f;
		myShape[i].fColours[0] = 1.0f;
		myShape[i].fColours[1] = 1.0f;
		myShape[i].fColours[2] = 1.0f;
		myShape[i].fColours[3] = 1.0f;
	}
	//set up the UVs
	myShape[0].fUVs[0] = 1.0f;	//X2
	myShape[0].fUVs[1] = 1.0f;	//Y2
	//TOP RIGHT

	myShape[1].fUVs[0] = 1.0f;	//X2
	myShape[1].fUVs[1] = 0.0f;	//Y1
	//BOTTOM RIGHT

	myShape[2].fUVs[0] = 0.0f;	//X1
	myShape[2].fUVs[1] = 0.0f;	//Y1
	//BOTTOM LEFT

	myShape[3].fUVs[0] = 0.0f;	//X1
	myShape[3].fUVs[1] = 1.0f;	//Y2
	//TOP LEFT

	glGenBuffers(1, &uiVBO);

	if (uiVBO != 0)
	{
		//bind VBO
		glBindBuffer(GL_ARRAY_BUFFER, uiVBO);
		//allocate space for vertices on the graphics card
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)* 4, NULL, GL_STATIC_DRAW);
		//get pointer to allocated space on the graphics card
		GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		//copy data to graphics card
		memcpy(vBuffer, myShape, sizeof(Vertex)* 4);
		//unmap and unbind buffer
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	glGenBuffers(1, &uiIBO);

	//check it succeeded
	if (uiIBO != 0)
	{
		//bind IBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, uiIBO);
		//allocate space for index info on the graphics card
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(char), NULL, GL_STATIC_DRAW);
		//get pointer to newly allocated space on the graphics card
		GLvoid* iBuffer = glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);
		//specify the order we'd like to draw our vertices.
		//In this case they are in sequential order
		for (int i = 0; i < 4; i++)
		{
			((char*)iBuffer)[i] = i;
		}
		//unmap and unbind
		glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	uiTextureId = loadTexture(texture, width, height, bpp);
	uiProgramTextured = CreateProgram("VertexShader.glsl", "TexturedFragmentShader.glsl");
	MatrixIDFlat = glGetUniformLocation(uiProgramTextured, "MVP");
	orthographicProjection = getOrtho(0, 1024, 0, 720, 0, 100);


	
}

void QuadVert::Initialize(float x, float y, char* texture, int width, int height, int bpp, float* a)
{
	myShape = new Vertex[4];
	myShape[0].fPositions[0] = x + width;
	myShape[0].fPositions[1] = y + height;
	myShape[1].fPositions[0] = x + width;
	myShape[1].fPositions[1] = y;
	myShape[2].fPositions[0] = x;
	myShape[2].fPositions[1] = y;
	myShape[3].fPositions[0] = x;
	myShape[3].fPositions[1] = y + height;

	for (int i = 0; i < 4; i++)
	{
		myShape[i].fPositions[2] = 0.0f;
		myShape[i].fPositions[3] = 1.0f;
		myShape[i].fColours[0] = 1.0f;
		myShape[i].fColours[1] = 1.0f;
		myShape[i].fColours[2] = 1.0f;
		myShape[i].fColours[3] = 1.0f;
	}
	//set up the UVs
	myShape[0].fUVs[0] = a[2];	//X2
	myShape[0].fUVs[1] = a[3];	//Y2
	//TOP RIGHT

	myShape[1].fUVs[0] = a[2];	//X2
	myShape[1].fUVs[1] = a[1];	//Y1
	//BOTTOM RIGHT

	myShape[2].fUVs[0] = a[0];	//X1
	myShape[2].fUVs[1] = a[1];	//Y1
	//BOTTOM LEFT

	myShape[3].fUVs[0] = a[0];	//X1
	myShape[3].fUVs[1] = a[3];	//Y2
	//TOP LEFT

	glGenBuffers(1, &uiVBO);

	if (uiVBO != 0)
	{
		//bind VBO
		glBindBuffer(GL_ARRAY_BUFFER, uiVBO);
		//allocate space for vertices on the graphics card
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)* 4, NULL, GL_STATIC_DRAW);
		//get pointer to allocated space on the graphics card
		GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		//copy data to graphics card
		memcpy(vBuffer, myShape, sizeof(Vertex)* 4);
		//unmap and unbind buffer
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	glGenBuffers(1, &uiIBO);

	//check it succeeded
	if (uiIBO != 0)
	{
		//bind IBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, uiIBO);
		//allocate space for index info on the graphics card
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(char), NULL, GL_STATIC_DRAW);
		//get pointer to newly allocated space on the graphics card
		GLvoid* iBuffer = glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);
		//specify the order we'd like to draw our vertices.
		//In this case they are in sequential order
		for (int i = 0; i < 4; i++)
		{
			((char*)iBuffer)[i] = i;
		}
		//unmap and unbind
		glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	uiTextureId = loadTexture(texture, width, height, bpp);
	uiProgramTextured = CreateProgram("VertexShader.glsl", "TexturedFragmentShader.glsl");
	MatrixIDFlat = glGetUniformLocation(uiProgramTextured, "MVP");
	orthographicProjection = getOrtho(0, 1024, 0, 720, 0, 100);



}


QuadVert::~QuadVert()
{
}
