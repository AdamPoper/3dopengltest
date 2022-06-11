#include "Shader.h"

Shader::Shader(const char* vs_path, const char* fs_path)
{
    m_renderID = glCreateProgram();
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	std::string vs_src, fs_src;
	readShader(vs_src, vs_path);
    readShader(fs_src, fs_path);
    compileShader(vs_src, vs);
    compileShader(fs_src, fs);
    glAttachShader(m_renderID, vs);
    glAttachShader(m_renderID, fs);
    glLinkProgram(m_renderID);
    glValidateProgram(m_renderID);
    glUseProgram(m_renderID);
    glDeleteShader(vs);
    glDeleteShader(fs);
}

void Shader::readShader(std::string& src, const char* filepath)
{
    std::string line;
    std::stringstream ss;
    std::ifstream stream(filepath);
    if (stream.fail())
        std::cout << "did not load " << filepath << std::endl;
    else
    {
        while (getline(stream, line))
            ss << line << '\n';
        src = ss.str();
    }
}

void Shader::compileShader(const std::string& src, GLuint shader)
{
    const char* c_str = src.c_str();
    glShaderSource(shader, 1, &c_str, nullptr);
    glCompileShader(shader);
}

void Shader::Bind() const
{
    glUseProgram(m_renderID);
}

void Shader::UnBind() const
{
    glUseProgram(0);
}

void Shader::setUniformMat4(const char* name, const glm::mat4& mat)
{
    int location = glGetUniformLocation(m_renderID, name);
    glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
}