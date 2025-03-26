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

	unsigned int genTexture (string ImgName) {
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	int init(int w, int h) {
		//Initialize
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Set Version
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Use core version of OpenGL
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //FOR MACOS


		//Create GLFW window
		window = glfwCreateWindow(w, h, "OpenGL Test", NULL, NULL); //Size, title, monitor, shared recourses
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


		//Assign how to read vertex data
		//Triangle Verteces
		float vertices[] = {
			-0.5,-0.5,0, 1.0f,0.0f,0.0f,
			0.5,-0.5,0,  0.0f,1.0f,0.0f,
			0,0.5,0,     0.0f,0.0f,1.0f
		};
		unsigned int indices[] = {
			0, 1, 2,
		};

		unsigned int VBO, VAO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		glBindVertexArray(VAO); //editing VAO

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 6 * sizeof(float),(void*)(3* sizeof(float)));
		glEnableVertexAttribArray(1);

		
		//Unbind data
		glBindBuffer(GL_ARRAY_BUFFER, 0); 
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); 
		glBindVertexArray(0);



		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//Render loop
		while(!glfwWindowShouldClose(window)) {
			processInput(window);

			//RENDERING
			glClearColor(.1f,.5f,.4f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
	
			float timeValue = glfwGetTime();
			glUniform1f(glGetUniformLocation(shaderProgram.ID,"time"),timeValue);

			
			glUseProgram(shaderProgram.ID);
			glBindVertexArray(VAO);
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