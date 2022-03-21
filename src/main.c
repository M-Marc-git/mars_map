#include <stdio.h>

#include "render/window.h"
#include "render/array.h"
#include "render/buffer.h"
#include "render/shader.h"

int main() {
    Window window = create_window(1024, 768, "Mars Map");

    float vertex[] = {
        0.5f, 0.5f, 0.f,
        0.5f, -0.5f, 0.f,
        -0.5f, -0.5f, 0.f,
        -0.5f, 0.5f, 0.f
    };

    unsigned int index[] = {
        0, 1, 2,
        2, 3, 0
    };

    Shader shader = create_shader("assets/shader/world.vert", "assets/shader/world.frag");

    VertexArray array = create_vertex_array(0);
    VertexBuffer vertex_buffer = create_vertex_buffer(vertex, sizeof(vertex), 0);

    add_vertex_buffer_to_array(&array, 0, 3, &vertex_buffer);
    set_index_buffer_to_array(&array, index, sizeof(index));

    while(is_window_open(&window)) {
        bind_shader(&shader);
        bind_vertex_array(&array);
        draw_vertex_array(&array);
        unbind_vertex_array(&array);
        unbind_shader();
    }

    destroy_vertex_buffer(&vertex_buffer);
    destroy_vertex_array(&array);
    destroy_shader(&shader);
    destroy_window(&window);
    return 0;
}