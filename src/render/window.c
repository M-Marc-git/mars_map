#include "window.h"

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void glfw_error_callback(int code, const char* info) {
    fprintf(stderr, "Erreur(%d): %s\n", code, info);
    exit(EXIT_FAILURE);
}

Window create_window(int width, int height, const char* title) {
    glfwSetErrorCallback(glfw_error_callback);

    glfwInit();

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window window = {
        .width = width,
        .height = height,
        .handle = glfwCreateWindow(window.width, window.height, title, NULL, NULL)
    };

    glfwMakeContextCurrent(window.handle);

    if(glewInit() != GLEW_OK) {
        fprintf(stderr, "Erreur initialisation OpenGL\n");
        glfwDestroyWindow(window.handle);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // OpenGL
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.f, 0.f, 0.f, 1.f);

    // GLFW

    return window;
}

int is_window_open(const Window* self) {
    glfwSwapBuffers(self->handle);
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    return !glfwWindowShouldClose(self->handle);
}

void destroy_window(Window* self) {
    glfwDestroyWindow(self->handle);
    glfwTerminate();
}
