/**
 * \file world.h
 * \brief Gestion du monde
 * \author Marc__M
 */ 
#ifndef WORLD_WORLD
#define WORLD_WORLD

#include "chunk.h"

#define RENDER_DISTANCE 4

typedef struct World {
    Chunk chunks[(RENDER_DISTANCE*2+1)*(RENDER_DISTANCE*2+1)];
} World;

/**
 * \brief Création d'un monde
 */ 
World create_world();

/**
 * \brief Mise à jour du monde en fonction de la position de la camera
 * \param world le monde à mettre à jour
 * \param x la position x de la camera
 * \param z la position z de la camera
 */ 
void update_world(World* world, int x, int z);

/**
 * \brief Effectu un rendu du monde
 * \param world le monde à rendre
 */ 
void render_world(World* world);

/**
 * \brief Detruit le monde
 * \param world le monde à détruire
 */ 
void destroy_world(World* world);

#endif //WORLD_WORLD
