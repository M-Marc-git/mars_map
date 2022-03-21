/**
 * \file array.h
 * \brief Gestion des VertexArray OpenGL
 * \author Marc__M
 */ 
#ifndef RENDER_ARRAY
#define RENDER_ARRAY

#include "buffer.h"

typedef struct VertexArray {
    unsigned int vao;
    unsigned int ebo;
    int dynamic;
    unsigned int buffer_count;
    unsigned int vertex_count;
} VertexArray;

/**
 * \brief Generation d'un VertexArrayObject(VAO)
 * \param dynamic 0 ou 1 selon changements prévus
 */ 
VertexArray create_vertex_array(int dynamic);

/**
 * \brief Destruction d'un VAO
 * \param self VAO à détruire
 */ 
void destroy_vertex_array(VertexArray* self);

/**
 * \brief Ajout d'un tampon(VBO) dans le VAO
 * \param self le VAO utilisé
 * \param id l'identifiant auquel il est ajouté
 * \param count le nombre de valeur par sommet
 * \param buffer le tampon à ajouter
 */ 
void add_vertex_buffer_to_array(VertexArray* self, unsigned int id, unsigned int count, const VertexBuffer* buffer);

/**
 * \brief Ajout d'un tampon d'index pour le VAO
 * \param self le VAO utilisé
 * \param index le tampon d'index
 * \param size la taille du tampon
 */ 
void set_index_buffer_to_array(VertexArray* self, void* index, unsigned int size);

/**
 * \brief Utilisation du VAO passé en argumenet
 * \param self le VAO à utilisé
 */ 
void bind_vertex_array(const VertexArray* self);

/**
 * \brief Désactivation du VAO passé en argument
 * \param self le VAO à désactivé
 */ 
void unbind_vertex_array(const VertexArray* self);

/**
 * \brief Effectue un rendu du VAO
 * \param self le VAO à rendre
 */ 
void draw_vertex_array(const VertexArray* self);

#endif //RENDER_ARRAY
 