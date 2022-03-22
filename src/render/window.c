#include "window.h"

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "event/input.h"

void glfw_error_callback(int code, const char* info) {
    fprintf(stderr, "Erreur(%d): %s\n", code, info);
    exit(EXIT_FAILURE);
}

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    static unsigned int draw_mode = GL_FILL;
    if(action == GLFW_PRESS) {
        set_key(key, 1);
    } else if(action == GLFW_RELEASE) {
        set_key(key, 0);

        if(key == GLFW_KEY_Q) {
            if(draw_mode == GL_FILL) {
                draw_mode = GL_LINE;
            } else {
                draw_mode = GL_FILL;
            }

            glPolygonMode(GL_FRONT_AND_BACK, draw_mode);
        }
    }
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
    glfwSetKeyCallback(window.handle, glfw_key_callback);

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
