#ifndef GAME_H
#define GAME_H

//External Libraries
#include <iostream>
#include <glad.h>
#include <glfw3.h>
#include <thread>
#include <functional>
#include <vector>

//Project Classes
#include "chunk.h"


using namespace std;


namespace Game {
	extern GLFWwindow* window;
	int createWindow(int w, int h);
	bool keyDown(int GLFWkey); //Is key Held Down
	void addKeydownCallback(int GLFWkey, const function<void()>& func); //Triggers passed in function when key is pressed
}

#endif GAME_H