#version 410 core

in vec3 fragTexCoord;

uniform sampler3D volumeData;
uniform vec4 vertexColor;
uniform float useTexture;

out vec4 color;

void main() {
    // Replicate the single red channel to RGB so the slice renders greyscale.
    float v = texture(volumeData, fragTexCoord).r;
    color = vertexColor + useTexture * vec4(v, v, v, 1.0);
}
