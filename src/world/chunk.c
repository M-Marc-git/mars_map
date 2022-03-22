#include "chunk.h"

#include <stdio.h>
#include <stdlib.h>

Chunk create_chunk(int x, int z) {
    float* vertex = malloc(CHUNK_SIZE*CHUNK_SIZE*3*sizeof(float));
    float* normal = malloc(CHUNK_SIZE*CHUNK_SIZE*3*sizeof(float));
    unsigned int* index = malloc((CHUNK_SIZE-1)*(CHUNK_SIZE-1)*6*sizeof(int));

    unsigned int it=0;
    for(int i=0; i < CHUNK_SIZE; i++) {
        for(int j=0; j < CHUNK_SIZE; j++) {
            vertex[3*it+0] = i + (CHUNK_SIZE-1)*x;
            vertex[3*it+1] = 0;
            vertex[3*it+2] = j + (CHUNK_SIZE-1)*z;

            normal[3*it+0] = 0;
            normal[3*it+1] = 1;
            normal[3*it+2] = 0;

            it++;
        }
    }

    it=0;
    for(unsigned int i=0; i<CHUNK_SIZE-1; i++){
		for(unsigned int j=0; j<CHUNK_SIZE-1; j++){
			unsigned int topLeft = (i*CHUNK_SIZE)+j;
			unsigned int topRight = topLeft + 1;
			unsigned int bottomLeft = ((i+1)*CHUNK_SIZE)+j;
			unsigned int bottomRight = bottomLeft + 1;
				
            index[it++] = topLeft;
			index[it++] = bottomLeft;
			index[it++] = topRight;
            index[it++] = topRight;
			index[it++] = bottomLeft;
			index[it++] = bottomRight;
		}
	}

    Chunk chunk = {
        .array = create_vertex_array(0),
        .vertex = create_vertex_buffer(vertex, CHUNK_SIZE*CHUNK_SIZE*3*sizeof(float), 0),
        .normal = create_vertex_buffer(normal, CHUNK_SIZE*CHUNK_SIZE*3*sizeof(float), 0),

        .x = x,
        .z = z
    };

    add_vertex_buffer_to_array(&chunk.array, 0, 3, &chunk.vertex);
    add_vertex_buffer_to_array(&chunk.array, 1, 3, &chunk.normal);
    set_index_buffer_to_array(&chunk.array, index, (CHUNK_SIZE-1)*(CHUNK_SIZE-1)*6*sizeof(int));

    free(vertex);
    free(normal);
    free(index);

    return chunk;
}

void draw_chunk(const Chunk* chunk) {
    bind_vertex_array(&chunk->array);
    draw_vertex_array(&chunk->array);
    unbind_vertex_array(&chunk->array);
}

void destroy_chunk(Chunk* chunk) {
    destroy_vertex_array(&chunk->array);
    destroy_vertex_buffer(&chunk->vertex);
    destroy_vertex_buffer(&chunk->normal);
}
