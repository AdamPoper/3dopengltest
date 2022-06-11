#pragma once
#include "../glm/glm.hpp"

struct Vertex
{
	Vertex(const glm::vec3& pos, const glm::vec4& col)
		: position(pos), color(col)	{}
	glm::vec3 position;
	glm::vec4 color;
};
