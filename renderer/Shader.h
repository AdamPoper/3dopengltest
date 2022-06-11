#pragma once

#include <GL/glew.h>
#include "../glm/glm.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	Shader(const char* vs_path, const char* fs_path);

	void setUniformMat4(const char* name, const glm::mat4& mat);

	void Bind() const;

	void UnBind() const;

private:

	void readShader(std::string& src, const char* path);

	void compileShader(const std::string& src, GLuint shader);

private:
	GLuint m_renderID;
};