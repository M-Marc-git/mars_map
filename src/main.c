#include <stdio.h>

#include "entity/camera.h"

#include "event/input.h"

#include "render/window.h"
#include "render/array.h"
#include "render/buffer.h"
#include "render/shader.h"

int main() {
    init_input();
    Window window = create_window(1024, 768, "Mars Map");

    float vertex[] = {
        0.5f, 0.5f, 0.5f,
        0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f,

        0.5f, 0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f,

        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f,
        -0.5f, 0.5f, 0.5f,

        0.5f, -0.5f, 0.5f,
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, 0.5f,

        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, 0.5f,

        -0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, 0.5f,
    };

    unsigned int index[] = {
        0, 1, 2,
        2, 3, 0,

        4, 5, 6,
        6, 7, 4,

        8, 9, 10,
        10, 11, 8,

        12, 13, 14,
        14, 15, 12,

        16, 17, 18,
        18, 19, 16,

        20, 21, 22,
        22, 23, 20
    };

    Camera camera = create_camera((Vector3f){0.f, 0.f, 0.f}, (Vector2f){0.f, 0.f});

    Shader shader = create_shader("assets/shader/world.vert", "assets/shader/world.frag");
    unsigned int shader_view_location = get_uniform_location_shader(&shader, "view");
    bind_shader(&shader);
    shader_load_uniform_matrix4f(get_uniform_location_shader(&shader, "projection"), perspectiv_matrix(70.f, 4.f/3.f, 0.1f, 1000.f));
    unbind_shader();

    VertexArray array = create_vertex_array(0);
    VertexBuffer vertex_buffer = create_vertex_buffer(vertex, sizeof(vertex), 0);

    add_vertex_buffer_to_array(&array, 0, 3, &vertex_buffer);
    set_index_buffer_to_array(&array, index, sizeof(index));

    while(is_window_open(&window)) {
        bind_shader(&shader);
        shader_load_uniform_matrix4f(shader_view_location, get_camera_view_matrix(&camera));
        bind_vertex_array(&array);
        draw_vertex_array(&array);
        unbind_vertex_array(&array);
        unbind_shader();

        update_camera(&camera);
    }

    destroy_vertex_buffer(&vertex_buffer);
    destroy_vertex_array(&array);
    destroy_shader(&shader);
    destroy_window(&window);
    return 0;
}