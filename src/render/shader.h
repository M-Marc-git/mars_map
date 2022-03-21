/**
 * \file shader.h
 * \brief Implementation des shaders OpenGL
 * \author Marc__M
 */ 
#ifndef RENDER_SHADER
#define RENDER_SHADER

#include "math/matrix4.h"
#include "math/vector3.h"

typedef struct Shader {
    unsigned int program_id;
    unsigned int vertex_id;
    unsigned int fragment_id;
} Shader;

/**
 * \brief création d'un shader
 * \param vertex_file position du fichier source du Vertex Shader
 * \param fragment_file position du fichier source du Fragment Shader
 */ 
Shader create_shader(const char* vertex_file, const char* fragment_file);

/**
 * \brief Récupération de l'emplacement d'une variable uniforme
 * \param shader le shader auquel on récupère l'emplacement
 * \param name le nom de la variable
 * \return l'emplacement de la variable
 */ 
unsigned int get_uniform_location_shader(const Shader* shader, const char* name);

/**
 * \brief Charge une matrice d'ordre 4 dans le shader
 * \param location l'emplacement de chargement
 * \param matrix la matrice à charger
 */ 
void shader_load_uniform_matrix4f(const unsigned int location, const Matrix4f matrix);

/**
 * \brief Charge un vecteur 3D dans le shader
 * \param location l'emplacement de chargement
 * \param vector le vecteur à charger
 */ 
void shader_load_uniform_vector3f(const unsigned int location, const Vector3f vector);

/**
 * \brief Activation d'un shader
 * \param self le shader à utiliser
 */ 
void bind_shader(const Shader* self);

/**
 * \brief Désactivation des shader
 */ 
void unbind_shader();

/**
 * \brief Déstruction d'un shader
 * \param self le shader à détruire
 */ 
void destroy_shader(Shader* self);

#endif //RENDER_SHADER
