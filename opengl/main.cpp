//
//  main.cpp
//  opengl
//
//  Created by 万 on 2018/4/10.
//  Copyright © 2018年 万. All rights reserved.
//

#include <iostream>
#include <GLFW/glfw3.h>
//#include <glad/glad.h>
#include <OpenGL/gl3.h>
#include <math.h>
#include "shader_s.h"

//const char *vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec3 aColor;\n"
//"out vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"   ourColor = aColor;\n"
//"}\0";
//
//const char *fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(ourColor,1.0);\n"
//"}\n\0";


int main(int argc, const char * argv[]) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
    
    GLFWwindow *window = glfwCreateWindow(500, 500, "hello", NULL, NULL);
    glfwMakeContextCurrent(window);
    
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
    Shader ourShader("/Users/wan/Desktop/工作台/opengl/opengl/vertexShader.vs", "/Users/wan/Desktop/工作台/opengl/opengl/fragmentShader.vs");
    
//    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertex_shader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertex_shader);
//
//    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragment_shader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragment_shader);
//
//    GLuint shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertex_shader);
//    glAttachShader(shaderProgram, fragment_shader);
//    glLinkProgram(shaderProgram);
//
//    glDeleteShader(vertex_shader);
//    glDeleteShader(fragment_shader);
    
    float vertices[] = {
        // 位置              // 颜色
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
    };
    
    unsigned int vbo,vao;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    /**
     缓存标识符标识当前活动的GPU内存,当你想配置某一块内存或者你想绘制这一块内存的内容时，你需要调用GLBindbuffer函数，并且该函数第二个参数要设置成你想操作内存的标识，然后接下来的操作都是针对这一块内存进行的，操作完过后记得再次调用GLBindBuffer(GL_ARRAY_BUFFER,0),将当前活动内存设置为空，非必需，但是这样做会是个好习惯*/
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        ourShader.use();
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(ourShader.ID, "gColor");
        glUniform4f(vertexColorLocation, 0.f, greenValue, 0.f, 1);
//        glUseProgram(shaderProgram);
        //更新uniform颜色
//        float timeValue = glfwGetTime();
//        float greenValue = sin(timeValue) / 2.0f + 0.5f;
//        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//        glUniform4f(vertexColorLocation, 0.f, greenValue, 0.f, 1);
        
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    glDeleteBuffers(1, &vbo);
    glfwTerminate();
    return 0;
}


