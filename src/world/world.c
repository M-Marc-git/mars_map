#include "world.h"

#include <stdio.h>

World create_world() {
    World world;
    unsigned int it=0;
    for(int i=-RENDER_DISTANCE; i <= RENDER_DISTANCE; i++) {
        for(int j=-RENDER_DISTANCE; j <= RENDER_DISTANCE; j++) {
            world.chunks[it++] = create_chunk(i, j);
        }
    }

    return world;
}

void update_world(World* world, int x, int z) {
    int chunk_x = -x/CHUNK_SIZE;
    int chunk_z = z/CHUNK_SIZE;

    for(unsigned int it=0; it <(RENDER_DISTANCE*2+1)*(RENDER_DISTANCE*2+1); it++) {
        if(world->chunks[it].x < chunk_x-RENDER_DISTANCE) {
            int pos_z = world->chunks[it].z;
            destroy_chunk(&world->chunks[it]);
            world->chunks[it] = create_chunk(chunk_x+RENDER_DISTANCE, pos_z);
        }
        else if(world->chunks[it].x > chunk_x+RENDER_DISTANCE) {
            int pos_z = world->chunks[it].z;
            destroy_chunk(&world->chunks[it]);
            world->chunks[it] = create_chunk(chunk_x-RENDER_DISTANCE, pos_z);
        }

        if(world->chunks[it].z < chunk_z-RENDER_DISTANCE) {
            int pos_x = world->chunks[it].x;
            destroy_chunk(&world->chunks[it]);
            world->chunks[it] = create_chunk(pos_x, chunk_z+RENDER_DISTANCE);
        }
        else if(world->chunks[it].z > chunk_z+RENDER_DISTANCE) {
            int pos_x = world->chunks[it].x;
            destroy_chunk(&world->chunks[it]);
            world->chunks[it] = create_chunk(pos_x, chunk_z-RENDER_DISTANCE);
        }
    }
}

void render_world(World* world) {
    for(unsigned int it=0; it < (RENDER_DISTANCE*2+1)*(RENDER_DISTANCE*2+1); it++) {
        draw_chunk(&world->chunks[it]);
    }
}

void destroy_world(World* world) {
    for(unsigned int it=0; it < (RENDER_DISTANCE*2+1)*(RENDER_DISTANCE*2+1); it++) {
        destroy_chunk(&world->chunks[it]);
    }
}
