#ifndef GAME_H
#define GAME_H

//External Libraries
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <functional>
#include <vector>
#include "lib/FastNoiseLite.h"

//Project Classes
#include "chunk.h"
#include "world.h"


using namespace std;


namespace Game {
	extern GLFWwindow* window;
	int init(int w, int h);
	bool keyDown(int GLFWkey); //is key held Down
	void addKeydownCallback(int GLFWkey, const function<void()>& func); //triggers passed in function when key is pressed
}

#endif