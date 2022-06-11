#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <array>
#include <thread>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "renderer/VertexBuffer.h"
#include "renderer/IndexBuffer.h"
#include "renderer/VertexArray.h"
#include "renderer/Shader.h"
#include "renderer/window.h"

#include "tools/TimeStep.h"

#define HEIGHT 600.0f
#define WIDTH 800.0f

int main()
{
    Window window(WIDTH, HEIGHT, "Hello World");

    if (glewInit() == GLEW_OK)
        std::cout << "glew ok" << std::endl;

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, WIDTH, HEIGHT);   
    
    //glm::mat4 projection = glm::perspective(glm::radians(90.0f), WIDTH / HEIGHT, 0.1f, 100.0f);
    
    glm::mat4 model(1.0f);          
   
    std::array<glm::vec3, 4> positions = {
        glm::vec3(-0.5f,  0.5f, -0.5f), // 0
        glm::vec3( 0.5f,  0.5f, -0.5f), // 1
        glm::vec3( 0.5f, -0.5f, -0.5f), // 2

        glm::vec3(-0.5f, -0.5f, -0.5f), // 3
       //glm::vec3(-0.5f, -0.5f,  0.5f), // 4
       //glm::vec3( 0.5f, -0.5f,  0.5f), // 5
       //glm::vec3( 0.5f,  0.5f,  0.5f), // 6
       //glm::vec3(-0.5f,  0.5f,  0.5f), // 7
    };   
    
    std::array<Vertex, 6> vertices = {
        Vertex(positions[0], glm::vec4(1.0f, 0.6f, 0.0f, 1.0f)),
        Vertex(positions[1], glm::vec4(1.0f, 0.6f, 0.0f, 1.0f)),
        Vertex(positions[2], glm::vec4(1.0f, 0.6f, 0.0f, 1.0f)),
        Vertex(positions[0], glm::vec4(1.0f, 0.6f, 0.0f, 1.0f)),
        Vertex(positions[2], glm::vec4(1.0f, 0.6f, 0.0f, 1.0f)),
        Vertex(positions[3], glm::vec4(1.0f, 0.6f, 0.0f, 1.0f)),

        //Vertex(positions[2], glm::vec4(1.0f, 0.0f, 0.6f, 1.0f)),
        //Vertex(positions[3], glm::vec4(1.0f, 0.0f, 0.6f, 1.0f)),
        //Vertex(positions[4], glm::vec4(1.0f, 0.0f, 0.6f, 1.0f)),
        //Vertex(positions[2], glm::vec4(1.0f, 0.0f, 0.6f, 1.0f)),
        //Vertex(positions[4], glm::vec4(1.0f, 0.0f, 0.6f, 1.0f)),
        //Vertex(positions[5], glm::vec4(1.0f, 0.0f, 0.6f, 1.0f)),
        //
        //Vertex(positions[1], glm::vec4(1.0f, 0.5f, 0.3f, 1.0f)),
        //Vertex(positions[2], glm::vec4(1.0f, 0.5f, 0.3f, 1.0f)),
        //Vertex(positions[5], glm::vec4(1.0f, 0.5f, 0.3f, 1.0f)),
        //Vertex(positions[1], glm::vec4(1.0f, 0.5f, 0.3f, 1.0f)),
        //Vertex(positions[5], glm::vec4(1.0f, 0.5f, 0.3f, 1.0f)),
        //Vertex(positions[6], glm::vec4(1.0f, 0.5f, 0.3f, 1.0f)),
        //
        //Vertex(positions[4], glm::vec4(2.0f, 0.3f, 0.9f, 1.0f)),
        //Vertex(positions[5], glm::vec4(2.0f, 0.3f, 0.9f, 1.0f)),
        //Vertex(positions[6], glm::vec4(2.0f, 0.3f, 0.9f, 1.0f)),
        //Vertex(positions[4], glm::vec4(2.0f, 0.3f, 0.9f, 1.0f)),
        //Vertex(positions[6], glm::vec4(2.0f, 0.3f, 0.9f, 1.0f)),
        //Vertex(positions[7], glm::vec4(2.0f, 0.3f, 0.9f, 1.0f)),
        //
        //Vertex(positions[0], glm::vec4(0.2f, 0.2f, 1.0f, 1.0f)),
        //Vertex(positions[3], glm::vec4(0.2f, 0.2f, 1.0f, 1.0f)),
        //Vertex(positions[4], glm::vec4(0.2f, 0.2f, 1.0f, 1.0f)),
        //Vertex(positions[0], glm::vec4(0.2f, 0.2f, 1.0f, 1.0f)),
        //Vertex(positions[4], glm::vec4(0.2f, 0.2f, 1.0f, 1.0f)),
        //Vertex(positions[7], glm::vec4(0.2f, 0.2f, 1.0f, 1.0f)),
        //
        //Vertex(positions[0], glm::vec4(0.2f, 0.9f, 0.5f, 1.0f)),
        //Vertex(positions[1], glm::vec4(0.2f, 0.9f, 0.5f, 1.0f)),
        //Vertex(positions[6], glm::vec4(0.2f, 0.9f, 0.5f, 1.0f)),
        //Vertex(positions[0], glm::vec4(0.2f, 0.9f, 0.5f, 1.0f)),
        //Vertex(positions[6], glm::vec4(0.2f, 0.9f, 0.5f, 1.0f)),
        //Vertex(positions[7], glm::vec4(0.2f, 0.9f, 0.5f, 1.0f)),
    };

    std::array<uint32_t, 12> indices = {
         0, 1, 2,
         0, 2, 3,

         2, 3, 4,
         2, 4, 5
    };    

    Shader shaderProgram("assets/shaders/vertexshader.shader", "assets/shaders/fragmentshader.shader");

    VertexArray vao;

    VertexBuffer vbo(vertices.data(), vertices.size());
    //IndexBuffer ibo(indices.data(), indices.size());
    //ibo.UnBind();
    
    // position
    vao.push(3, GL_FLOAT, GL_FALSE);

    // color
    vao.push(4, GL_FLOAT, GL_FALSE);
    
    float speed = 5.0f;
     
    TimeStep ts;

    while (window.isOpen())
    {            
        ts.stop();
        ts.start();
    
        if (Window::isKeyPressed(KEY_W))
            window.getCamera().moveForward(ts);
        if (Window::isKeyPressed(KEY_S))
            window.getCamera().moveBackward(ts);
        if (Window::isKeyPressed(KEY_A))
            window.getCamera().strafeLeft(ts);
        if (Window::isKeyPressed(KEY_D))
            window.getCamera().strafeRight(ts);

        window.getCamera().onUpdate();

        shaderProgram.setUniformMat4("u_projection", window.getCamera().getProjection());
        shaderProgram.setUniformMat4("u_view", window.getCamera().getView());
        shaderProgram.setUniformMat4("u_model", model);

        shaderProgram.Bind();
        vao.Bind();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.1f, 0.2f, 0.2f, 1.0f);

        glDrawArrays(GL_TRIANGLES, 0, vertices.size());
        window.OnUpdate();
    }

    return 0;
}