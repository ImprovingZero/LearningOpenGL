#pragma once

#include<iostream>
#include<fstream>
#include<string>

#include<glew.h>
#include<glfw3.h>

#include<glm.hpp>
#include<vec2.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat2x4.hpp>
#include<gtc\type_ptr.hpp>

class Shader
{
private:
	GLuint id;

	std::string loadShaderSource(char* fileName);
	GLuint loadShader(GLenum type, char* filename);
	void linkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader);

public:
	Shader(char* vertexFile, char*fragmentFile, char* geometryFile = "");
	~Shader();
	
	//Set uniform functions
	void use();
	void unuse();
	void set1f(GLfloat value, const GLchar* name);
	void setVec2f(glm::fvec2 valuse, const GLchar* name);
	void setVec3f(glm::fvec3 valuse, const GLchar* name);
	void setVec4f(glm::fvec4 valuse, const GLchar* name);

	void set1i(GLint value, const GLchar* name);
	void setVec2i(glm::ivec2 valuse, const GLchar* name);
	void setVec3i(glm::ivec3 valuse, const GLchar* name);
	void setVec4i(glm::ivec4 valuse, const GLchar* name);

	void setMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose = GL_FALSE);
	void setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose = GL_FALSE);
};