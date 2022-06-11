#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(uint32_t* data, uint32_t count)
{
	m_buffer = data;
	m_size = sizeof(uint32_t) * count;
	glGenBuffers(1, &m_renderID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_size, (const void*)data, GL_STATIC_DRAW);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderID);
}

void IndexBuffer::UnBind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}