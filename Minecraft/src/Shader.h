#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;


#ifndef SHADER_H
#define SHADER_H

class Shader {
	public:
		unsigned int ID;

		Shader(const string vertexPath, const string fragmentPath) {
			string vertexCode;
			string fragmentCode;

			ifstream vShader;
			ifstream fShader;

			vShader.exceptions(ifstream::failbit | ifstream::badbit);
			fShader.exceptions(ifstream::failbit | ifstream::badbit);

			//Read Files
			try {
				vShader.open(vertexPath);
				fShader.open(fragmentPath);

				stringstream vShaderStream, fShaderStream;
				vShaderStream << vShader.rdbuf();
				fShaderStream << fShader.rdbuf();

				vShader.close();
				fShader.close();

				vertexCode = vShaderStream.str();
				fragmentCode = fShaderStream.str();
			} catch (ifstream::failure e) {
				cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" <<endl;
			}
			const char* vertexCString = vertexCode.c_str();
			const char* fragmentCString = fragmentCode.c_str();


			//Compile Shaders
			unsigned int vertex, fragment;
			int success;
			char infoLog[512];

			//Vertex
			vertex = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertex,1,&vertexCString,NULL);
			glCompileShader(vertex);

			glGetShaderiv(vertex,GL_COMPILE_STATUS,&success);
			if (!success) {
				glGetShaderInfoLog(vertex,512,NULL,infoLog);
				cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
			}

			//fragment
			fragment = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragment,1,&fragmentCString,NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment,GL_COMPILE_STATUS,&success);
			if (!success) {
				glGetShaderInfoLog(fragment,512,NULL,infoLog);
				cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
			}

			
			//Program Creation
			ID = glCreateProgram();
			glAttachShader(ID,vertex);
			glAttachShader(ID,fragment);
			glLinkProgram(ID);

			glGetProgramiv(ID,GL_LINK_STATUS,&success);
			if (!success) {
				glGetShaderInfoLog(fragment,512,NULL,infoLog);
				cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
			}


			glDeleteShader(vertex);
			glDeleteShader(fragment);
		};
};

#endif