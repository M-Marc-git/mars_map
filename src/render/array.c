#include "array.h"

#include <GL/glew.h>

VertexArray create_vertex_array(int dynamic) {
    VertexArray array = {
        .vao = 0,
        .ebo = 0,
        .dynamic = 0,
        .buffer_count = 0,
        .vertex_count = 0
    };

    glGenVertexArrays(1, &array.vao);

    return array;
}

void destroy_vertex_array(VertexArray* self) {
    if(self->ebo != 0) {
        glDeleteBuffers(1, &self->ebo);
    }
    glDeleteVertexArrays(1, &self->vao);
}

void add_vertex_buffer_to_array(VertexArray* self, unsigned int id, unsigned int count, const VertexBuffer* buffer) {
    bind_vertex_array(self);
    bind_vertex_buffer(buffer);

    glVertexAttribPointer(id, count, GL_FLOAT, GL_FALSE, 0, 0);

    unbind_vertex_buffer(buffer);
    unbind_vertex_array(self);

    self->buffer_count++;
}

void set_index_buffer_to_array(VertexArray* self, void* index, unsigned int size) {
    bind_vertex_array(self);

    glGenBuffers(1, &self->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, index, self->dynamic?GL_DYNAMIC_DRAW:GL_STATIC_DRAW);

    unbind_vertex_array(self);

    self->vertex_count = size/sizeof(int);
}

void bind_vertex_array(const VertexArray* self) {
    glBindVertexArray(self->vao);

    for(unsigned int it=0; it < self->buffer_count; it++) {
        glEnableVertexAttribArray(it);
    }
}

void unbind_vertex_array(const VertexArray* self) {
    for(unsigned int it=0; it < self->buffer_count; it++) {
        glDisableVertexAttribArray(it);
    }

    glBindVertexArray(0);
}

void draw_vertex_array(const VertexArray* self) {
    glDrawElements(GL_TRIANGLES, self->vertex_count, GL_UNSIGNED_INT, 0);
}
