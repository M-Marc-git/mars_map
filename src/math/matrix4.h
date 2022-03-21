/**
 * \file matrix4.h
 * \brief Implementation d'une matrice d'ordre 4
 * \author Marc__M
 */ 
#ifndef MATH_MATRIX4
#define MATH_MATRIX4

#include "vector3.h"

typedef struct Matrix4f {
    float m11, m12, m13, m14;
	float m21, m22, m23, m24;
	float m31, m32, m33, m34;
	float m41, m42, m43, m44;
} Matrix4f;

/**
 * \brief Ajout de 2 matrices d'odre 4
 * \param m0 première matrice
 * \param m1 seconde matrice
 */ 
Matrix4f add_matrix4f(const Matrix4f m0, const Matrix4f m1);

/**
 * \brief Soustraction de 2 matrices d'ordre 4
 * \param m0 première matrice
 * \param m1 seconde matrice
 */ 
Matrix4f sub_matrix4f(const Matrix4f m0, const Matrix4f m1);

/**
 * \brief Multiplication de 2 matrices d'ordre 4
 * \param m0 première matrice
 * \param m1 seconde matrice
 */ 
Matrix4f mul_matrix4f(const Matrix4f m0, const Matrix4f m1);

/**
 * \brief multiplication d'une matrice par un réel
 * \param m matrice
 * \param f réel
 */ 
Matrix4f mul_scalar_matrix4f(const Matrix4f m, const float f);

/**
 * \brief division d'une matrice par un réel
 * \param m matrice
 * \param f réel
 */ 
Matrix4f div_scalar_matrix4f(const Matrix4f m, const float f);

/**
 * \brief Generation d'une matrice de projection en perspective 
 * \param fov angle de vision
 * \param aspect largeur de la fenetre divisé par hauteur de la fenetre
 * \param near plus proche distance rendue
 * \param far distance rendue la plus éloignée
 */ 
Matrix4f perspectiv_matrix(float fov, float aspect, float near, float far);

/**
 * \brief Generation d'une matrice de projection orthographique
 * \param x bord de gauche
 * \param y bord du haut
 * \param width largeur
 * \param height hauteur
 */ 
Matrix4f ortho_matrix(float x, float y, float width, float height);

/**
 * \brief Generation d'une matrice de vue
 * \param eye position de l'observateur
 * \param center point regardé
 * \param up vecteur indiquant le haut utilisé
 */ 
Matrix4f look_at_matrix(const Vector3f eye, const Vector3f center, const Vector3f up);

#define IDENTITY (Matrix4f) {                                                 \
    1.f, 0.f, 0.f, 0.f,                                                       \
    0.f, 1.f, 0.f, 0.f,                                                       \
    0.f, 0.f, 1.f, 0.f,                                                       \
    0.f, 0.f, 0.f, 1.f                                                        \
}

#define ZERO (Matrix4f) {                                                     \
    0.f, 0.f, 0.f, 0.f,                                                       \
    0.f, 0.f, 0.f, 0.f,                                                       \
    0.f, 0.f, 0.f, 0.f,                                                       \
    0.f, 0.f, 0.f, 0.f                                                        \
}

#endif //MATH_MATRIX4
