#include "mars_map.h"

#include <stdio.h>
#include <stdlib.h>

MarsMap* create_mars_map() {
    MarsMap* map = malloc(sizeof(MarsMap));
    map->window = create_window(1024, 768, "Mars Map");
    map->world_shader.shader = create_shader("assets/shader/world.vert", "assets/shader/world.frag");
    map->camera = create_camera((Vector3f){0.f, 2.f, 0.f}, (Vector2f){0.f, 0.f});
    map->world = create_world();

    bind_shader(&map->world_shader.shader);
    map->world_shader.projection_location = get_uniform_location_shader(&map->world_shader.shader, "projection");
    map->world_shader.view_location = get_uniform_location_shader(&map->world_shader.shader, "view");
    map->world_shader.light_color_position = get_uniform_location_shader(&map->world_shader.shader, "light_color");
    map->world_shader.light_position_location = get_uniform_location_shader(&map->world_shader.shader, "light_position");
    shader_load_uniform_matrix4f(map->world_shader.projection_location, perspectiv_matrix(70, 4.f/3.f, 0.1f, 1000.f));
    shader_load_uniform_vector3f(map->world_shader.light_color_position, (Vector3f){1.f, 1.f, 1.f});
    unbind_shader();
    return map;
}

void run_mars_map(MarsMap* map) {
    while(is_window_open(&map->window)) {
        bind_shader(&map->world_shader.shader);
        shader_load_uniform_vector3f(map->world_shader.light_position_location, (Vector3f){map->camera.position.x, map->camera.position.y, map->camera.position.z});
        shader_load_uniform_matrix4f(map->world_shader.view_location, get_camera_view_matrix(&map->camera));

        render_world(&map->world);

        unbind_shader(&map->world_shader.shader);

        update_camera(&map->camera);
        update_world(&map->world, map->camera.position.x, map->camera.position.z);
    }
}

void destroy_mars_map(MarsMap* map) {
    destroy_world(&map->world);
    destroy_shader(&map->world_shader.shader);
    destroy_window(&map->window);
    free(map);
}
