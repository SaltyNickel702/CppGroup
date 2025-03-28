#include "Game.h"

using namespace Game;

//Private namespace
namespace {
	void windowResizeCallback(GLFWwindow* window, int width, int height) { //for when the window gets resized
		glViewport(0, 0, width, height);
	}

	//Input Handeling
	bool keysDown[GLFW_KEY_LAST-GLFW_KEY_SPACE];
	vector<function<void()>> functionCalls[GLFW_KEY_LAST-GLFW_KEY_SPACE];
	void processInput(GLFWwindow* window) {
		//esc key closes app (temporary)
		if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);


		//Adding/removing keys to keysDown | If new key is added, call callback functions
		for (int i = GLFW_KEY_SPACE; i < GLFW_KEY_LAST; i++) {
			bool isDown = keyDown(i);
			if (isDown) {
				bool previous = keysDown[i-33]; //
				if (!previous) {
					vector<function<void()>> funcs = functionCalls[i-33];
					for (const function<void()> func : funcs) {
						func();
					}
				}
				keysDown[i-33] = true;
			} else keysDown[i-33] = false;
		}
	}
}

//Exported Game namespace
namespace Game {
	GLFWwindow* window = nullptr;

	unsigned int genTexture (string ImgName) { //make sure to set active texture before loading
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		string ImgRel = "./assets/textures/" + ImgName;
		int width, height, nrChannels;
		unsigned char *data = stbi_load(ImgRel.c_str(), &width, &height, &nrChannels, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		} else {
			cout << "Failed to Load Texture" << endl;
		}
		stbi_image_free(data);
		glBindTexture(GL_TEXTURE_2D, 0);
		return texture;
	}

	int init(int w, int h) {
		//Initialize
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Set Version
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Use core version of OpenGL
		// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //FOR MACOS


		//Create GLFW window
		window = glfwCreateWindow(w, h, "Craftmine", NULL, NULL); //Size, title, monitor, shared recourses
		if (window == NULL) {
			cout << "Failed to create GLFW window" << endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);


		//Initialize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			cout << "Failed to initialize GLAD" << endl;
			return -1;
		}

		//Sets GL Viewport (camera)
		glViewport(0, 0, w, h);
		glfwSetFramebufferSizeCallback(window,windowResizeCallback); //assigns callback function



		//Shader Compilation + triangle test

		
		Shader shaderProgram("basicVert.glsl","basicFrag.glsl");


		//Create Model
		vector<float> vertices {
			-0.5f,-0.5f,0.0f,	1.0f,0.0f,0.0f,	0.0f,1.0f,		//bottom left
			-0.5f,0.5f,0.0f, 	0.0f,1.0f,0.0f,	0.0f,0.0f,		//Top Left
			0.5f,-0.5f,0.0f,	0.0f,0.0f,1.0f,	1.0f,1.0f,		//Bottom Right
			0.5f,0.5f,0.0f,		1.0f,1.0f,1.0f,	1.0f,0.0f		//Top Right
		};
		vector<unsigned int> attr {
			3,3,2
		};
		vector<unsigned int> indices {
			0, 2, 1,
			1, 2, 3
		};
		Model m1(vertices, indices, attr);


		//Create Textures
		glActiveTexture(GL_TEXTURE0);
		unsigned int texture1 = Game::genTexture("GrassSide.png");

		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//Render loop
		glEnable(GL_DEPTH_TEST);
		while(!glfwWindowShouldClose(window)) {
			processInput(window);

			//RENDERING
			glClearColor(.1f,.5f,.4f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
			
			glUseProgram(shaderProgram.ID);
			float timeValue = glfwGetTime();
			glUniform1f(glGetUniformLocation(shaderProgram.ID,"time"),timeValue);
	

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D,texture1);
			
			glBindVertexArray(m1.VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	
			glfwSwapBuffers(window); //updates screen buffer
			glfwPollEvents(); //Check for inputs
		}
		glfwTerminate();

		return 0;
	}

	bool keyDown (int key) {
		return glfwGetKey(window, key) == GLFW_PRESS;
	}
	void addKeydownCallback(int key, const function<void()>& func) {
		functionCalls[key-33].push_back(func);
	}
}