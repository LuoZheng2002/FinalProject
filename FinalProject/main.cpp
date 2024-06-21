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

struct Bone
{
    float bone0;
    float bone1;
    float bone2;
};

struct Vertex
{
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float u;
    float v;
    float nx;
    float ny;
    float nz;
    Bone bone;
};

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    sizeof(Vertex);
    /*GLfloat vertices[] = {
        -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f/4, 2.0f/3,      0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 2.0f/4, 2.0f/3,      0.0f, 0.0f, 1.0f,
        -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f / 4, 1.0f / 3, 0.0f, 0.0f, 1.0f,
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 2.0f / 4, 1.0f / 3,  0.0f, 0.0f, 1.0f,

        1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 2.0f/4, 2.0f/3,       1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 3.0f/4, 2.0f/3,      1.0f, 0.0f, 0.0f,
        1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 2.0f / 4, 1.0f / 3,  1.0f, 0.0f, 0.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 3.0f / 4, 1.0f / 3, 1.0f, 0.0f, 0.0f,

        1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 3.0f / 4, 2.0f / 3,  0.0f, 0.0f, -1.0f,
        -1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 4.0f / 4, 2.0f / 3, 0.0f, 0.0f, -1.0f,
        1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 3.0f / 4, 1.0f / 3, 0.0f, 0.0f, -1.0f,
        -1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 4.0f / 4, 1.0f / 3, 0.0f, 0.0f, -1.0f,

        -1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f / 4, 2.0f / 3,  -1.0f, 0.0f, 0.0f, 
        -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f / 4, 2.0f / 3,  -1.0f, 0.0f, 0.0f,
        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f / 4, 1.0f / 3,  -1.0f, 0.0f, 0.0f,
        -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f / 4, 1.0f / 3,  -1.0f, 0.0f, 0.0f,

        -1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f/4, 3.0f/3,      0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 2.0f / 4, 3.0f / 3,   0.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f / 4, 2.0f / 3,   0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 2.0f / 4, 2.0f / 3,    0.0f, 1.0f, 0.0f,

        -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f / 4, 1.0f / 3,  0.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f / 4, 1.0f / 3,   0.0f, -1.0f, 0.0f,
        -1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f / 4, 0.0f / 3, 0.0f, -1.0f, 0.0f,
        1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 2.0f / 4, 0.0f / 3,  0.0f, -1.0f, 0.0f,
    };*/

    int stories = 12;
    float delta = 1.0f / stories;

    Vertex vertices[9 * 13] = {};
    for (int i = 0; i < 13; i++)
    {
        Bone bone[] = {
            {1.00f, 0.00f, 0.00f},// 1
            {0.90f, 0.10f, 0.00f},// 2
            {0.75f, 0.25f, 0.00f},// 3
            {0.50f, 0.50f, 0.00f},// 4
            {0.25f, 0.75f, 0.00f},// 5
            {0.10f, 0.90f, 0.00f},// 6
            {0.10f, 0.80f, 0.10f},// 7
            {0.00f, 0.90f, 0.10f},// 8
            {0.00f, 0.75f, 0.25f},// 9
            {0.00f, 0.50f, 0.50f},// 10
            {0.00f, 0.25f, 0.75f},// 11
            {0.00f, 0.10f, 0.90f},// 12
            {0.00f, 0.00f, 1.00f} // 13
        };
        vertices[9 * i] = { -0.5f, 0.0f + 6.0f * i / 12, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, delta * i,  -1.0f, 0.0f, 2.0f, bone[i]};
        vertices[9 * i + 1] = { 0.5f, 0.0f + 6.0f * i / 12, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f / 8, delta * i,     1.0f, 0.0f, 2.0f, bone[i]};
        vertices[9 * i + 2] = { 1.0f, 0.0f + 6.0f * i / 12, 0.5f, 1.0f, 1.0f, 1.0f, 2.0f / 8, delta * i, 2.0f, 0.0f, 1.0f, bone[i]};
        vertices[9 * i + 3] = {    1.0f, 0.0f + 6.0f * i / 12, -0.5f, 1.0f, 1.0f, 1.0f, 3.0f / 8, delta * i, 2.0f, 0.0f, -1.0f, bone[i]};
        vertices[9 * i + 4] = {   0.5f, 0.0f + 6.0f * i / 12, -1.0f, 1.0f, 1.0f, 1.0f, 4.0f / 8, delta * i, 1.0f, 0.0f, -2.0f , bone[i]};
        vertices[9 * i + 5] = {    -0.5f, 0.0f + 6.0f * i / 12, -1.0f, 1.0f, 1.0f, 1.0f, 5.0f / 8, delta * i, -1.0f, 0.0f, -2.0f, bone[i]};
        vertices[9 * i + 6] = {    -1.0f, 0.0f + 6.0f * i / 12, -0.5f, 1.0f, 1.0f, 1.0f, 6.0f / 8, delta * i, -2.0f, 0.0f, -1.0f , bone[i]};
        vertices[9 * i + 7] = {    -1.0f, 0.0f + 6.0f * i / 12, 0.5f, 1.0f, 1.0f, 1.0f, 7.0f / 8, delta * i, -2.0f, 0.0f, 1.0f , bone[i]};
        vertices[9 * i + 8] = {    -0.5f, 0.0f + 6.0f * i / 12, 1.0f, 1.0f, 1.0f, 1.0f, 8.0f / 8, delta * i, -1.0f, 0.0f, 2.0f , bone[i]};
    }

   /* GLfloat vertices[] =
    {
        0.0f, 0.5f / sqrt(3.0f) * 2, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f / sqrt(3.0f), 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
        0.5f, -0.5f / sqrt(3.0f), 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f
    };*/
    GLuint indices[8 * 2 * 12*3] = {};
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            indices[i * 8 * 2 * 3 + j * 2 * 3] = 9 * i + j;
            indices[i * 8 * 2 * 3 + j * 2 * 3 + 1] = 9 * i + j + 1;
            indices[i * 8 * 2 * 3 + j * 2 * 3 + 2] = 9 * i + j + 9;
            indices[i * 8 * 2 * 3 + j * 2 * 3 + 3] = 9 * i + j + 1;
            indices[i * 8 * 2 * 3 + j * 2 * 3 + 4] = 9 * i + j + 10;
            indices[i * 8 * 2 * 3 + j * 2 * 3 + 5] = 9 * i + j + 9;
        }
    }
    /*{
        0, 1, 9, 1, 10, 9,
        1, 2, 10, 2, 11, 10,
        2, 3, 11, 3, 12, 11,
        3, 4, 12, 4, 13, 12,
        4, 5, 13, 5, 14, 13,
        5, 6, 14, 6, 15, 14,
        6, 7, 15, 7, 16, 15,
        7, 8, 16, 8, 17, 16

    };*/
    //GLuint indices[] =
    //{
    //    0, 1, 2
    //};

    /*GLuint indices[] =
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
    };*/

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
    VBO VBO1((float*)(vertices),sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 14* sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 14 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 14 * sizeof(float), (void*)(6 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 14 * sizeof(float), (void*)(8 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 4, 3, GL_FLOAT, 14 * sizeof(float), (void*)(11 * sizeof(float)));
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    // Texture
    Texture popCat("Textures/grass_block.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    

    Texture tnt("Textures/sakiri.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    

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
    // glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shaderProgram.Activate();
        float currTime = glfwGetTime();


        float angle = currTime;



        glm::mat4 model = glm::mat4(1.0f);        
        
        model = glm::rotate(model, currTime , glm::vec3(0.0f, 1.0f, 0.0f));
        // model = glm::translate(model, glm::vec3(0.0f, 3.0f, -1.5f));
        glm::mat4 view = glm::mat4(1.0f); // start with identity matrix
        glm::mat4 proj = glm::mat4(1.0f); // start with identity matrix
        // view = glm::rotate(view, currTime, glm::vec3(0.0f, 1.0f, 0.0f));
        // view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
        glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), 0.2f*currTime, glm::vec3(0.0f, 1.0f, 0.0f));
        glm::vec3 eye = /*rotation * */glm::vec4(0.0f, 3.0f, 10.0f, 1.0f);
        view = glm::lookAt(eye, glm::vec3(1.0f, 3.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        // proj = glm::ortho(-2.0f, 2.0f, -2.0f, 2.0f, -10.0f, 10.0f);
        proj = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);

        tnt.texUnit(shaderProgram, "tex0", 0);
        tnt.Bind();

        int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, false, glm::value_ptr(model));
        int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
        glUniformMatrix4fv(viewLoc, 1, false, glm::value_ptr(view));
        int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
        glUniformMatrix4fv(projLoc, 1, false, glm::value_ptr(proj));

        glm::mat4 translation1 = glm::mat4(1.0f);
        translation1 = glm::translate(translation1, glm::vec3(0.0f, 2.0f, 0.0f));
        glm::mat4 translation2 = glm::mat4(1.0f);
        translation2 = glm::translate(translation2, glm::vec3(0.0f, 2.0f, 0.0f));

        glm::mat4 rotation1 = glm::mat4(1.0f);
        rotation1 = glm::rotate(rotation1, sin(3.14f * currTime), glm::vec3(0.0f, 0.0f, 1.0f));
        glm::mat4 rotation2 = glm::mat4(1.0f);
        rotation2 = glm::rotate(rotation2, 1.2f*cos(currTime), glm::vec3(1.0f, 0.0f, 0.0f));

        int translation1Loc = glGetUniformLocation(shaderProgram.ID, "translation1");
        glUniformMatrix4fv(translation1Loc, 1, false, glm::value_ptr(translation1));
        int translation2Loc = glGetUniformLocation(shaderProgram.ID, "translation2");
        glUniformMatrix4fv(translation2Loc, 1, false, glm::value_ptr(translation2));


        int rotation1Loc = glGetUniformLocation(shaderProgram.ID, "rotation1");
        glUniformMatrix4fv(rotation1Loc, 1, false, glm::value_ptr(rotation1));
        int rotation2Loc = glGetUniformLocation(shaderProgram.ID, "rotation2");
        glUniformMatrix4fv(rotation2Loc, 1, false, glm::value_ptr(rotation2));


        glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        glm::vec3 lightPos = glm::vec3(3.0f, 0.0f, 3.0f);
        glm::mat4 lightModel = glm::mat4(1.0f);
        lightModel = glm::translate(lightModel, lightPos);


        glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
        glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

        glUniform1f(uniID, 1.0f);
        
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 8*2*12*3, GL_UNSIGNED_INT, 0);


        /*model = glm::mat4(1.0f);

        glUniformMatrix4fv(modelLoc, 1, false, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, false, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, false, glm::value_ptr(proj));
        popCat.texUnit(shaderProgram, "tex0", 0);
        popCat.Bind();

        
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);*/

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
