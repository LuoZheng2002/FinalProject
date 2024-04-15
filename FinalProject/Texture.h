#pragma once
#include<glad/glad.h>
#include<stb/stb_image.h>
#include"shaderClass.h"
class Texture
{
public:
	GLenum type;
	GLuint ID;

	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();

};

