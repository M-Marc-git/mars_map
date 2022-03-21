#ifndef ENTITY_CAMERA
#define ENTITY_CAMERA

#include "math/matrix4.h"
#include "math/vector2.h"
#include "math/vector3.h"

typedef struct Camera {
    Vector3f position;
    Vector2f rotation;

    Vector3f forward;
    Vector3f right;
} Camera;

Camera create_camera(Vector3f position, Vector2f rotation);
void update_camera(Camera* camera);
Matrix4f get_camera_view_matrix(const Camera* camera);

#endif //ENTITY_CAMERA
