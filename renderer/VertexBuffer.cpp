#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(Vertex* data, uint32_t count)
{
	m_buffer = data;
	m_size = sizeof(Vertex) * count;
	glGenBuffers(1, &m_renderID);
	glBindBuffer(GL_ARRAY_BUFFER, m_renderID);
	glBufferData(GL_ARRAY_BUFFER, m_size, (const void*)data, GL_STATIC_DRAW);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_renderID);
}

void VertexBuffer::UnBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}