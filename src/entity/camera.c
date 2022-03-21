#include "camera.h"

#include <math.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "event/input.h"

Camera create_camera(Vector3f position, Vector2f rotation) {
    Camera camera = {
        .position = position,
        .rotation = rotation
    };

    float rad_pitch = camera.rotation.x*M_PI/180.f;
    float rad_yaw = camera.rotation.y*M_PI/180.f;

    float cos_pitch = cosf(rad_pitch);

    camera.forward.x = cosf(rad_yaw)*cos_pitch;
    camera.forward.y = sinf(rad_pitch);
    camera.forward.z = sinf(rad_yaw)*cos_pitch;

    camera.right = normalize_vector3f(cross_product(camera.forward, (Vector3f){0.f, 1.f, 0.f}));

    return camera;
}

void update_camera(Camera* camera) {
    if(get_key(GLFW_KEY_W)) {
        camera->position = sub_vector3f(camera->position, camera->forward);
    }
    if(get_key(GLFW_KEY_S)) {
        camera->position = add_vector3f(camera->position, camera->forward);
    }
    if(get_key(GLFW_KEY_A)) {
        camera->position = sub_vector3f(camera->position, camera->right);
    }
    if(get_key(GLFW_KEY_D)) {
        camera->position = add_vector3f(camera->position, camera->right);
    }
}

Matrix4f get_camera_view_matrix(const Camera* camera) {
    return look_at_matrix(camera->position, add_vector3f(camera->position, camera->forward), (Vector3f){0.f, 1.f, 0.f});
}
