#pragma once

#include<iostream>
#include<string>

#include<glew.h>
#include<glfw3.h>

#include<SOIL2.h>


class Texture
{
private:
	GLuint id;
	int height;
	int weight;
	unsigned int type;
	GLint textureUnit;
public:
	Texture(const char* fileName, GLenum type, GLint teture_unit);
	~Texture();

	inline GLuint getID() const{ return this->id; }
	inline GLuint getTextureUnit() const{ return this->textureUnit; }
	void bind();
	void unbind();
	void loadFromFile(const char* fileName);
};