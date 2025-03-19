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

	int init(int w, int h) {
		// Initialize GLFW
		if (!glfwInit()) {
			std::cerr << "Failed to initialize GLFW!" << std::endl;
			return -1;
		}
	
		// Set GLFW version
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
		// Create a windowed GLFW window
		GLFWwindow* window = glfwCreateWindow(w, h, "GLFW and GLAD App", nullptr, nullptr);
		if (!window) {
			std::cerr << "Failed to create GLFW window!" << std::endl;
			glfwTerminate();
			return -1;
		}
	
		// Make the window's context current
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, windowResizeCallback);
	
		// Initialize GLAD to load OpenGL functions
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "Failed to initialize GLAD!" << std::endl;
			return -1;
		}
	
		// Render loop
		while (!glfwWindowShouldClose(window)) {
			// Process input
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
				glfwSetWindowShouldClose(window, true);
			}
	
			// Rendering commands
			glClearColor(.5, .75f, .2f, 1.0f); // Black background
			glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
	
			// Swap buffers and poll events
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	
		// Clean up
		glfwDestroyWindow(window);
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