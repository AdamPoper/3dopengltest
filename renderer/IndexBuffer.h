#pragma once
#include <GL/glew.h>
#include <iostream>

class IndexBuffer
{
public:
	IndexBuffer(uint32_t* data, uint32_t count);

	void Bind() const;

	void UnBind() const;

private:
	GLuint m_renderID;
	uint32_t* m_buffer;
	size_t m_size;
};