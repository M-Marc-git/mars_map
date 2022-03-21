#include "vector2.h"

#include <math.h>

Vector2f add_vector2f(const Vector2f v0, const Vector2f v1) {
    return (Vector2f) {v0.x+v1.x, v0.y+v1.y};
}

Vector2f sub_vector2f(const Vector2f v0, const Vector2f v1) {
    return (Vector2f) {v0.x-v1.x, v0.y-v1.y};
}

Vector2f mul_vector2f(const Vector2f v, const float f) {
    return (Vector2f) {v.x*f, v.y*f};
}

Vector2f div_vector2f(const Vector2f v, const float f) {
    return (Vector2f) {v.x/f, v.y/f};
}

float dot_product_vector2f(Vector2f v0, Vector2f v1) {
    return v0.x*v1.x + v0.y*v1.y;
}

float squared_lenght_vector2f(const Vector2f v) {
    return v.x*v.x + v.y*v.y;
}

float lenght_vector2f(const Vector2f v) {
    return sqrtf(squared_lenght_vector2f(v));
}

Vector2f normalize_vector2f(const Vector2f v) {
    float norm = lenght_vector2f(v);

    return (Vector2f) {v.x/norm, v.y/norm};
}

