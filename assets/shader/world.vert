#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;

out vec3 pass_normal;
out vec3 pass_frag;

uniform mat4 projection;
uniform mat4 view;

void main() {
    gl_Position = projection*view*vec4(vertex, 1.0);
    pass_normal = normal;
    pass_frag = vertex;
}
