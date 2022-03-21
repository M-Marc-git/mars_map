#include "matrix4.h"

#include <math.h>

Matrix4f add_matrix4f(const Matrix4f m0, const Matrix4f m1) {
    Matrix4f ret;
    float* mat = (float*)&ret;
    float* _m0 = (float*)&m0;
    float* _m1 = (float*)&m1;

    for(unsigned int it=0; it < 16; it++) {
        mat[it] = _m0[it]+_m1[it];
    }

    return ret;
}

Matrix4f sub_matrix4f(const Matrix4f m0, const Matrix4f m1) {
    Matrix4f ret;
    float* mat = (float*)&ret;
    float* _m0 = (float*)&m0;
    float* _m1 = (float*)&m1;

    for(unsigned int it=0; it < 16; it++) {
        mat[it] = _m0[it]-_m1[it];
    }

    return ret;
}

Matrix4f mul_matrix4f(const Matrix4f m0, const Matrix4f m1) {
    Matrix4f ret;
    ret.m11 = m0.m11*m1.m11 + m0.m12*m1.m21 + m0.m13*m1.m31 + m0.m14*m1.m41;
	ret.m12 = m0.m11*m1.m12 + m0.m12*m1.m22 + m0.m13*m1.m32 + m0.m14*m1.m42;
    ret.m13 = m0.m11*m1.m13 + m0.m12*m1.m23 + m0.m13*m1.m33 + m0.m14*m1.m43;
	ret.m14 = m0.m11*m1.m14 + m0.m12*m1.m24 + m0.m13*m1.m34 + m0.m14*m1.m44;

	ret.m21 = m0.m21*m1.m11 + m0.m22*m1.m21 + m0.m23*m1.m31 + m0.m24*m1.m41;
	ret.m22 = m0.m21*m1.m12 + m0.m22*m1.m22 + m0.m23*m1.m32 + m0.m24*m1.m42;
	ret.m23 = m0.m21*m1.m13 + m0.m22*m1.m23 + m0.m23*m1.m33 + m0.m24*m1.m43;
	ret.m24 = m0.m21*m1.m14 + m0.m22*m1.m24 + m0.m23*m1.m34 + m0.m24*m1.m44;

	ret.m31 = m0.m31*m1.m11 + m0.m32*m1.m21 + m0.m33*m1.m31 + m0.m34*m1.m41;
	ret.m32 = m0.m31*m1.m12 + m0.m32*m1.m22 + m0.m33*m1.m32 + m0.m34*m1.m42;
	ret.m33 = m0.m31*m1.m13 + m0.m32*m1.m23 + m0.m33*m1.m33 + m0.m34*m1.m43;
	ret.m34 = m0.m31*m1.m14 + m0.m32*m1.m24 + m0.m33*m1.m34 + m0.m34*m1.m44;

	ret.m41 = m0.m41*m1.m11 + m0.m42*m1.m21 + m0.m43*m1.m31 + m0.m44*m1.m41;
	ret.m42 = m0.m41*m1.m12 + m0.m42*m1.m22 + m0.m43*m1.m32 + m0.m44*m1.m42;
	ret.m43 = m0.m41*m1.m13 + m0.m42*m1.m23 + m0.m43*m1.m33 + m0.m44*m1.m43;
	ret.m44 = m0.m41*m1.m14 + m0.m42*m1.m24 + m0.m43*m1.m34 + m0.m44*m1.m44;

    return ret;
}

Matrix4f mul_scalar_matrix4f(const Matrix4f m, const float f) {
    Matrix4f ret;
    float* mat = (float*)&ret;
    float* _m0 = (float*)&m;

    for(unsigned int it=0; it < 16; it++) {
        mat[it] = _m0[it]*f;
    }

    return ret;
}

Matrix4f div_scalar_matrix4f(const Matrix4f m, const float f) {
    Matrix4f ret;
    float* mat = (float*)&ret;
    float* _m0 = (float*)&m;

    for(unsigned int it=0; it < 16; it++) {
        mat[it] = _m0[it]/f;
    }

    return ret;
}

Matrix4f perspectiv_matrix(float fov, float aspect, float near, float far) {
    float tan_half_fov = tanf((fov*M_PI/360));

    Matrix4f matrix = IDENTITY;
    matrix.m11 = 1.f/(aspect*tan_half_fov);
    matrix.m22 = 1.f/tan_half_fov;
    matrix.m33 = -(far+near)/(far-near);
    matrix.m34 = -1.f;
    matrix.m43 = -(2.f*far*near)/(far-near);

    return matrix;
}

Matrix4f ortho_matrix(float x, float y, float width, float height) {
    Matrix4f matrix = IDENTITY;

    matrix.m11 = 2.f/(width-x);
    matrix.m22 = 2.f/(y-height);
    matrix.m41 = -(width+x)/(width-x);
    matrix.m42 = -(y+height)/(y-height);

    return matrix;
}

Matrix4f look_at_matrix(const Vector3f eye, const Vector3f center, const Vector3f up) {
    const Vector3f f = normalize_vector3f(sub_vector3f(center, eye));
    const Vector3f s = normalize_vector3f(cross_product(f, up));
    const Vector3f u = cross_product(s, f);

    Matrix4f matrix = IDENTITY;
    matrix.m11 = s.x;
    matrix.m21 = s.y;
    matrix.m31 = s.z;

    matrix.m12 = u.x;
    matrix.m22 = u.y;
    matrix.m32 = u.z;

    matrix.m13 = -f.x;
    matrix.m23 = -f.y;
    matrix.m33 = -f.z;

    matrix.m41 = -dot_product(s, eye);
    matrix.m42 = -dot_product(u, eye);
    matrix.m43 = -dot_product(f, eye);

    return matrix;
}
