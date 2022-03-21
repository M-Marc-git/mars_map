#include "shader.h"

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

unsigned int compile_shader(unsigned int type, const char* file_name) {
    unsigned int shader = glCreateShader(type);
    FILE* file = fopen(file_name, "r");
    size_t file_len = 0;
    char* shader_source = NULL;

    if(file == NULL) {
        fprintf(stdout, "Erreur ouverture fichier: %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    file_len = ftell(file);
    rewind(file);

    shader_source = malloc(file_len+1);

    for(size_t it=0; it < file_len; it++) {
        shader_source[it] = fgetc(file);
    }
    shader_source[file_len] = '\0';

    const char* src = shader_source;
    glShaderSource(shader, 1, &src, 0);
    glCompileShader(shader);

    free(shader_source);
    fclose(file);
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(success == 0) {
        char log[512];
        glGetShaderInfoLog(shader, 512, 0, log);

        fprintf(stdout, "Erreur(%s):\n%s", type==GL_VERTEX_SHADER?"Vertex Shader":"Fragment Shader", log);
        exit(EXIT_FAILURE);
    }

    return shader;
}

Shader create_shader(const char* vertex_file, const char* fragment_file) {
    Shader shader = {
        .vertex_id = compile_shader(GL_VERTEX_SHADER, vertex_file),
        .fragment_id = compile_shader(GL_FRAGMENT_SHADER, fragment_file),
        .program_id = glCreateProgram()
    };

    glAttachShader(shader.program_id, shader.vertex_id);
    glAttachShader(shader.program_id, shader.fragment_id);
    glLinkProgram(shader.program_id);

    return shader;
}

unsigned int get_uniform_location_shader(const Shader* shader, const char* name) {
    return glGetUniformLocation(shader->program_id, name);
}

void shader_load_uniform_matrix4f(const unsigned int location, const Matrix4f matrix) {
    glUniformMatrix4fv(location, 1, GL_FALSE, (float*)&matrix);
}

void shader_load_uniform_vector3f(const unsigned int location, const Vector3f vector) {
    glUniform3f(location, vector.x, vector.y, vector.z);
}

void bind_shader(const Shader* self) {
    glUseProgram(self->program_id);
}

void unbind_shader() {
    glUseProgram(0);
}

void destroy_shader(Shader* self) {
    glDeleteShader(self->vertex_id);
    glDeleteShader(self->fragment_id);
    glDeleteProgram(self->program_id);
}
