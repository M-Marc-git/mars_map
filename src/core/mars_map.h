/**
 * \file mars_map.h
 * \brief Implementation generale de la projection
 */ 
#ifndef CORE_MARS_MAP
#define CORE_MARS_MAP

#include "entity/camera.h"

#include "render/shader.h"
#include "render/window.h"

#include "world/world.h"

typedef struct MarsMap {
    Window window;
    struct WorldShader {
        Shader shader;
        unsigned int view_location;
        unsigned int projection_location;
    } world_shader;

    Camera camera;

    World world;
} MarsMap;

/**
 * \brief Création de la projection
 */ 
MarsMap* create_mars_map();

/**
 * \brief Execution de la projection
 * \param map projection à effectuer
 */ 
void run_mars_map(MarsMap* map);

/**
 * \brief Destruction de la projection
 * \param map la projection à détruire
 */ 
void destroy_mars_map(MarsMap* map);

#endif //CORE_MARS_MAP
