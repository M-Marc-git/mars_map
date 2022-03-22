#version 330 core

in vec3 pass_normal;
in vec3 pass_frag;

out vec4 frag_color;

void main() {
    vec3 ground_color = vec3(1.0, 0.0, 0.0);
    vec3 light_color = vec3(1.0, 1.0, 1.0);
    vec3 light_position = vec3(0.0, 10000000.0, 0.0);
    float ambiant_intensity = 0.1;

    // AMBIANT
    vec3 ambiant_light = ambiant_intensity*light_color;

    // DIFFUSE
    float diffuse_intensity = max(dot(normalize(pass_frag - light_color), pass_normal), 0.0);
    vec3 diffuse_light = diffuse_intensity*light_color;

    // FINAL
    vec3 final_light = (ambiant_light+diffuse_light);
    vec3 final_color = final_light*ground_color;
    frag_color = vec4(final_color, 1.0);
}
