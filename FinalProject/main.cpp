#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<stb/stb_image.h>
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Texture.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

const uint32_t windowWidth = 800;
const uint32_t windowHeight = 800;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] = {
        -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f/4, 2.0f/3,
        1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 2.0f/4, 2.0f/3,
        -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f / 4, 1.0f / 3,
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 2.0f / 4, 1.0f / 3,

        1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 2.0f/4, 2.0f/3,
        1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 3.0f/4, 2.0f/3,
        1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f / 4, 1.0f / 3,
        1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 3.0f / 4, 1.0f / 3,

        1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 3.0f / 4, 2.0f / 3,
        -1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 4.0f / 4, 2.0f / 3,
        1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 3.0f / 4, 1.0f / 3,
        -1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 4.0f / 4, 1.0f / 3,

        -1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f / 4, 2.0f / 3,
        -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f / 4, 2.0f / 3,
        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f / 4, 1.0f / 3,
        -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f / 4, 1.0f / 3,

        -1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f/4, 3.0f/3,
        1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 2.0f / 4, 3.0f / 3,
        -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f / 4, 2.0f / 3,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 2.0f / 4, 2.0f / 3,

        -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f / 4, 1.0f / 3,
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f / 4, 1.0f / 3,
        -1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f / 4, 0.0f / 3,
        1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 2.0f / 4, 0.0f / 3,
    };



    GLuint indices[] =
    {
        0, 2, 1,
        1, 2, 3,
        4, 6, 5,
        5, 6, 7,
        8, 10, 9,
        9, 10, 11,
        12, 14, 13,
        13, 14, 15,
        16, 18, 17,
        17, 18, 19,
        20, 22, 21,
        21, 22, 23
    };

    GLFWwindow* window = glfwCreateWindow(800, 800, "MATH214 Final Project", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();


    glViewport(0, 0, 800, 800);

    Shader shaderProgram("Shaders/default.vert", "Shaders/default.frag");
    VAO VAO1;
    VAO1.Bind();
    VBO VBO1(vertices,sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8* sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    // Texture
    Texture popCat("Textures/grass_block.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    popCat.texUnit(shaderProgram, "tex0", 0);




    // Original code from the tutorial
    /*Texture popCat("pop_cat.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    popCat.texUnit(shaderProgram, "tex0", 0);*/

    // float flatcolor[] = {1.0f, 1.0f, 1.0f, 1.0f}
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);
   

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    double prevTime = glfwGetTime();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shaderProgram.Activate();

        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 proj = glm::mat4(1.0f);
        double currTime = glfwGetTime();
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
        proj = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
        model = glm::rotate(model, glm::radians(45.0f), glm::vec3(1.0f, 1.0f, 0.0f));

        int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, false, glm::value_ptr(model));
        int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
        glUniformMatrix4fv(viewLoc, 1, false, glm::value_ptr(view));
        int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
        glUniformMatrix4fv(projLoc, 1, false, glm::value_ptr(proj));

        glUniform1f(uniID, 1.0f);
        popCat.Bind();
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    popCat.Delete();
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
    std::cout << "Hello World!\n";
    return 0;
}
