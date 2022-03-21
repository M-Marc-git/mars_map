#include "vector3.h"

#include <math.h>

Vector3f add_vector3f(const Vector3f v0, const Vector3f v1) {
    return (Vector3f) {v0.x+v1.x, v0.y+v1.y, v0.z+v1.z};
}

Vector3f sub_vector3f(const Vector3f v0, const Vector3f v1) {
    return (Vector3f) {v0.x-v1.x, v0.y-v1.y, v0.z-v1.z};
}

Vector3f mul_vector3f(const Vector3f v, const float f) {
    return (Vector3f) {v.x*f, v.y*f, v.z*f};
}

Vector3f div_vector3f(const Vector3f v, const float f) {
    return (Vector3f) {v.x/f, v.y/f, v.z/f};
}

Vector3f cross_product(Vector3f v0, Vector3f v1) {
    return (Vector3f) {
        v0.y*v1.z - v0.z*v1.y,
        v0.z*v1.x - v0.x*v1.z,
        v0.x*v1.y - v0.y*v1.x
    };
}

float dot_product(Vector3f v0, Vector3f v1) {
    return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z;
}

float squared_lenght_vector3f(const Vector3f v) {
    return v.x*v.x + v.y*v.y + v.z*v.z;
}

float lenght_vector3f(const Vector3f v) {
    return sqrtf(squared_lenght_vector3f(v));
}

Vector3f normalize_vector3f(const Vector3f v) {
    float norm = lenght_vector3f(v);

    return (Vector3f) {v.x/norm, v.y/norm, v.z/norm};
}
