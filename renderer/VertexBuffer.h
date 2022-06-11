#pragma once
#include <GL/glew.h>
#include <iostream>
#include "Vertex.h"

class VertexBuffer
{
public:
	VertexBuffer(Vertex* data, uint32_t count);

	void Bind() const;
	
	void UnBind() const;

private:
	GLuint m_renderID;
	Vertex* m_buffer;
	size_t m_size;
};