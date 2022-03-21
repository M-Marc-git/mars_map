/**
 * \file vector2.h
 * \brief Implementation d'un vecteur 2D
 * \author Marc__M
 */ 
#ifndef MATH_VECTOR2
#define MATH_VECTOR2

typedef struct Vector2f {
    float x;
    float y;
} Vector2f;

/**
 * \brief addition de deux vecteur
 * \param v0 premier vecteur
 * \param v1 second vecteur
 * \return v0 + v1
 */ 
Vector2f add_vector2f(const Vector2f v0, const Vector2f v1);

/**
 * \brief addition de deux vecteur
 * \param v0 premier vecteur
 * \param v1 second vecteur
 * \return v0 - v1
 */ 
Vector2f sub_vector2f(const Vector2f v0, const Vector2f v1);

/**
 * \brief multiplication d'un vecteur par un réel
 * \param v vecteur
 * \param f réel
 * \return f*v
 */ 
Vector2f mul_vector2f(const Vector2f v, const float f);

/**
 * \brief division d'un vecteur par un réel
 * \param v vecteur
 * \param f réel
 * \return (1/f)*v
 */ 
Vector2f div_vector2f(const Vector2f v, const float f);

/**
 * \brief produit scalaire de deux vectuer
 * \param v0 premier vecteur
 * \param v1 second vecteur
 * \return v0.v1
 */ 
float dot_product_vector2f(Vector2f v0, Vector2f v1);

/**
 * \brief carré de la norme d'un vecteur
 * \param v vecteur
 * \return ||v||^2
 */ 
float squared_lenght_vector2f(const Vector2f v);

/**
 * \brief norme d'un vecteur
 * \param v vecteur
 * \return ||v||
 */ 
float lenght_vector2f(const Vector2f v);

/**
 * \brief donne au vecteur une norme de 1
 * \param v le vecteur auquel donné une norme de 1
 */
Vector2f normalize_vector2f(const Vector2f v);

#endif //MATH_VECTOR2