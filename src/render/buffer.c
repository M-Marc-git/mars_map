#include "buffer.h"

#include <GL/glew.h>

VertexBuffer create_vertex_buffer(void* data, unsigned int size, int dynamic) {
    VertexBuffer buffer = {
        .dynamic = dynamic,
        .vbo = 0
    };

    glGenBuffers(1, &buffer.vbo);
    set_data_to_vertex_buffer(&buffer, data, size);

    return buffer;
}

void set_data_to_vertex_buffer(const VertexBuffer* self, void* data, unsigned int size) {
    bind_vertex_buffer(self);

    glBufferData(GL_ARRAY_BUFFER, size, data, self->dynamic?GL_DYNAMIC_DRAW:GL_STATIC_DRAW);

    unbind_vertex_buffer(self);
}

void destroy_vertex_buffer(const VertexBuffer* self) {
    glDeleteBuffers(1, &self->vbo);
}

void bind_vertex_buffer(const VertexBuffer* self) {
    glBindBuffer(GL_ARRAY_BUFFER, self->vbo);
}

void unbind_vertex_buffer(const VertexBuffer* self) {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
