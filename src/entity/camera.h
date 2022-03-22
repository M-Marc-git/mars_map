/**
 * \file camera.h
 * \brief Implementation d'une camera FPS
 * \author Marc__M
 */ 
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

/**
 * \brief Création d'une camera
 * \param position position initiale de la camera
 * \param rotation rotation initiale de la camera
 * \return nouvelle camera
 */ 
Camera create_camera(Vector3f position, Vector2f rotation);

/**
 * \brief Mise à jour de la camera d'après les donnés des entrés utilisateur
 * \param camera la camera à mettre à jour
 */ 
void update_camera(Camera* camera);

/**
 * \brief Récuperation de la matrice de vue de la camera
 * \param camera la camera concernée
 * \return matrice de vue
 */ 
Matrix4f get_camera_view_matrix(const Camera* camera);

#endif //ENTITY_CAMERA
