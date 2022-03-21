/**
 * \file vector3.h
 * \brief Implementation d'un vecteur 3D
 * \author Marc__M
 */ 
#ifndef MATH_VECTOR3
#define MATH_VECTOR3

typedef struct Vector3f {
    float x;
    float y;
    float z;
} Vector3f;

/**
 * \brief addition de deux vecteur
 * \param v0 premier vecteur
 * \param v1 second vecteur
 * \return v0 + v1
 */ 
Vector3f add_vector3f(const Vector3f v0, const Vector3f v1);

/**
 * \brief addition de deux vecteur
 * \param v0 premier vecteur
 * \param v1 second vecteur
 * \return v0 - v1
 */ 
Vector3f sub_vector3f(const Vector3f v0, const Vector3f v1);

/**
 * \brief multiplication d'un vecteur par un réel
 * \param v vecteur
 * \param f réel
 * \return f*v
 */ 
Vector3f mul_vector3f(const Vector3f v, const float f);

/**
 * \brief division d'un vecteur par un réel
 * \param v vecteur
 * \param f réel
 * \return (1/f)*v
 */ 
Vector3f div_vector3f(const Vector3f v, const float f);

/**
 * \brief produit vectoriel de deux vecteurs
 * \param v0 premier vecteur
 * \param v1 second vecteur
 */ 
Vector3f cross_product(Vector3f v0, Vector3f v1);

/**
 * \brief produit scalaire de deux vectuer
 * \param v0 premier vecteur
 * \param v1 second vecteur
 * \return v0.v1
 */ 
float dot_product(Vector3f v0, Vector3f v1);

/**
 * \brief carré de la norme d'un vecteur
 * \param v vecteur
 * \return ||v||^2
 */ 
float squared_lenght_vector3f(const Vector3f v);

/**
 * \brief norme d'un vecteur
 * \param v vecteur
 * \return ||v||
 */ 
float lenght_vector3f(const Vector3f v);

/**
 * \brief donne au vecteur une norme de 1
 * \param v le vecteur auquel donné une norme de 1
 */
Vector3f normalize_vector3f(const Vector3f v);

#endif //MATH_VECTOR3
