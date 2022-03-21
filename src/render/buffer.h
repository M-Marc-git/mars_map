/**
 * \file buffer.h
 * \brief Gestion des VertexBuffer OpenGL
 * \author Marc__M
 */ 
#ifndef RENDER_BUFFER
#define RENDER_BUFFER

typedef struct VertexBuffer {
    unsigned int vbo;
    int dynamic;
} VertexBuffer;

/**
 * \brief Generation d'un VertexBuffer (VBO)
 * \param data données contenues par le VBO
 * \param size la taille totale des données
 * \param dynamic 0 ou 1 selon la fréquence de changement prévue
 */ 
VertexBuffer create_vertex_buffer(void* data, unsigned int size, int dynamic);

/**
 * \brief Détruit le VBO passé en argument
 * \param self le VBO à détruire
 */ 
void destroy_vertex_buffer(const VertexBuffer* self);

/**
 * \brief Met des données dans le VBO
 * \param self le VBO dans lequel charger les données
 * \param data les données à charger
 * \param size la taille des données à charger
 */ 
void set_data_to_vertex_buffer(const VertexBuffer* self, void* data, unsigned int size);

/**
 * \brief Activation d'un VBO
 * \param self le VBO à activer
 */ 
void bind_vertex_buffer(const VertexBuffer* self);

/**
 * \brief désactivation d'un VBO
 * \param self le VBO à désactiver
 */ 
void unbind_vertex_buffer(const VertexBuffer* self);

#endif //RENDER_BUFFER
