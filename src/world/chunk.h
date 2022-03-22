/**
 * \file chunk.h
 * \brief Implementation des tronçons
 */ 
#ifndef WORLD_CHUNK
#define WORLD_CHUNK

#define CHUNK_SIZE 64

#include "render/array.h"
#include "render/buffer.h"

typedef struct Chunk {
    VertexArray array;
    VertexBuffer vertex;
    VertexBuffer normal;

    int x, z;
} Chunk;

/**
 * \brief Création d'un tronçons au coordonnées x*CHUNK_SIZE, z*CHUNK_SIZE
 * \return nouveau tronçon
 */ 
Chunk create_chunk(int x, int z);

/**
 * \brief Affiche un tronçon
 * \param chunk le tronçon à afficher
 */ 
void draw_chunk(const Chunk* chunk);

/**
 * \brief Détruit un tronçon
 * \param chunk le tronçon à détruire
 */ 
void destroy_chunk(Chunk* chunk);

#endif //WORLD_CHUNK
