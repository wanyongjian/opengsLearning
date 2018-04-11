//
//  main.cpp
//  opengl
//
//  Created by 万 on 2018/4/10.
//  Copyright © 2018年 万. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void framebuffer_size(GLFWwindow* window,int width,int height){
    glViewport(0, 0, width, height);
}

void getKey(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}
//int main(int argc, const char * argv[]) {
//    glfwInit();
//    //    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    GLFWwindow *window = glfwCreateWindow(500, 500, "hello Opengl", NULL, NULL);
//    glfwMakeContextCurrent(window);
//    glViewport(0, 0, 500, 500);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size);
//    
//    while(!glfwWindowShouldClose(window)){
//        getKey(window);
//        glClearColor(0.2, 0.1, 1, 1);
//        glClear(GL_COLOR_BUFFER_BIT);
//        
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//    glfwTerminate();
//    return 0;
//}


//
//void Render(void)
//{
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT
//    glBegin(GL_TRIANGLES);
//    {
//        glColor3f(1.0,0.0,0.0);
//        glVertex2f(0, .5);
//        glColor3f(0.0,1.0,0.0);
//        glVertex2f(-.5,-.5);
//        glColor3f(0.0, 0.0, 1.0);
//        glVertex2f(.5, -.5);
//    }
//    glEnd();
//}
//
//int main(int argc, const char * argv[]) {
//    GLFWwindow* win;
//    if(!glfwInit()){
//        return -1;
//    }
//    win = glfwCreateWindow(640, 480, "OpenGL Base Project", NULL, NULL);
//    if(!win)
//    {
//        glfwTerminate();
//        exit(EXIT_FAILURE);
//    }
//    if(!glewInit())
//    {
//        return -1;
//    }
//    glfwMakeContextCurrent(win);
//    while(!glfwWindowShouldClose(win)){
//        Render();
//        glfwSwapBuffers(win);
//        glfwPollEvents();
//    }
//    glfwTerminate();
//    exit(EXIT_SUCCESS);
//    return 0;
//}


