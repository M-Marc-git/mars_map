#include "input.h"

#include "input.h"

#include <stdio.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

static char key_status[GLFW_KEY_LAST];

void init_input() {
    for(unsigned int it=0; it < GLFW_KEY_LAST; it++) {
        key_status[it] = 0;
    }
}

void set_key(int key, int status) {
    key_status[key] = status;
}

int get_key(int key) {
    return key_status[key];
}
