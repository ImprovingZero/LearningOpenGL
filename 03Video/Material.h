#pragma once

#include<glew.h>
#include<glfw3.h>

#include<glm.hpp>
#include<vec2.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat2x4.hpp>
#include<gtc\type_ptr.hpp>

#include"Shader.h"

class Material
{
private:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	GLint diffuseTex;
	GLint specularTex;
public:
	Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
		GLint diffuseTex, GLint specularTex);
	~Material();

	//Functions;
	void sendToShader(Shader& program);

};