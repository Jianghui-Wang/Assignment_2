#version 410 core

layout (location = 0) in vec2 vertexPos;
layout (location = 1) in vec3 vertexTexCoord;

out vec3 fragTexCoord;

uniform mat4 texCoordTransform;
uniform mat4 model;

void main() {
    gl_Position = model * vec4(vertexPos, 0, 1.0);
    fragTexCoord = (texCoordTransform * vec4(vertexTexCoord, 1)).xyz;
}