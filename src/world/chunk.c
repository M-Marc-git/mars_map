#include "chunk.h"

#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "math/vector3.h"

float get_height(unsigned char* height, int x, int z) {
    if(x < 0 || z < 0 || x == CHUNK_SIZE || z == CHUNK_SIZE || height == NULL) {
        return 0;
    }
    int begin = 3*z*CHUNK_SIZE+x;

    int final_height = 0;
    final_height = height[begin] << 16 |
        height[begin+1] << 8 | height[begin+2];
    
    return (float)final_height/(float)0x00ffffff*AMPLITUDE;
}

Chunk create_chunk(int x, int z) {
    unsigned char* height;
    if(x < 0 || z < 0 || x > 179 || z > 99) {
        height = NULL;
    } else {
        char title[256];
        int w, h, c;
        sprintf(title, "assets/world/world_%d_%d.jpg", x, z);
        height = stbi_load(title, &w, &h, &c, 0);
    }
    
    float* vertex = malloc(CHUNK_SIZE*CHUNK_SIZE*3*sizeof(float));
    float* normal = malloc(CHUNK_SIZE*CHUNK_SIZE*3*sizeof(float));
    unsigned int* index = malloc((CHUNK_SIZE-1)*(CHUNK_SIZE-1)*6*sizeof(int));

    unsigned int it=0;
    for(int i=0; i < CHUNK_SIZE; i++) {
        for(int j=0; j < CHUNK_SIZE; j++) {
            vertex[3*it+0] = i + (CHUNK_SIZE-1)*x;
            vertex[3*it+1] = get_height(height, i, j);
            vertex[3*it+2] = j + (CHUNK_SIZE-1)*z;

            Vector3f normal_vec = {
                .x = get_height(height, i-1, j)-get_height(height, i+1, j),
                .y = 2.f,
                .z = get_height(height, i, j-1)-get_height(height, i, j+1)
            };
            normal_vec = normalize_vector3f(normal_vec);

            normal[3*it+0] = normal_vec.x;
            normal[3*it+1] = normal_vec.y;
            normal[3*it+2] = normal_vec.z;

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

    stbi_image_free(height);
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
