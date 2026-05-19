#version 410 core

layout (location = 0) in vec3 vertexPos;
layout (location = 1) in vec3 vertexNorm;

out vec3 fragColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 vertexColor;

const vec3 lightColor = vec3(1.0);
const vec3 lightPos = vec3(1.0);

void main() {
    gl_Position = projection * view * model * vec4(vertexPos, 1.0);
    vec3 pos = gl_Position.xyz;

    // TODO: apply gouraud shading instead of this line
    fragColor = vertexColor;
}