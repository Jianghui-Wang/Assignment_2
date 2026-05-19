#include "vbocube.h"

#include "glad/glad.h" 

VBOCube::VBOCube() {}

void VBOCube::init()
{
    float side = 1.f;

    float v[24*3] = {
            // Front
            -side, -side, side,
            side, -side, side,
            side,  side, side,
            -side,  side, side,
            // Right
            side, -side, side,
            side, -side, -side,
            side,  side, -side,
            side,  side, side,
            // Back
            -side, -side, -side,
            -side,  side, -side,
            side,  side, -side,
            side, -side, -side,
            // Left
            -side, -side, side,
            -side,  side, side,
            -side,  side, -side,
            -side, -side, -side,
            // Bottom
            -side, -side, side,
            -side, -side, -side,
            side, -side, -side,
            side, -side, side,
            // Top
            -side,  side, side,
            side,  side, side,
            side,  side, -side,
            -side,  side, -side
    };

    float n[24*3] = {
            // Front
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            // Right
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            // Back
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            // Left
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            // Bottom
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            // Top
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
    };

    GLuint el[] = {
            0,1,2,0,2,3,
            4,5,6,4,6,7,
            8,9,10,8,10,11,
            12,13,14,12,14,15,
            16,17,18,16,18,19,
            20,21,22,20,22,23
    };

    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    unsigned int handle[3];
    glGenBuffers(3, handle);
    // position
    glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
    glBufferData(GL_ARRAY_BUFFER, 24 * 3 * sizeof(float), v, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    // normal
    glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
    glBufferData(GL_ARRAY_BUFFER, 24 * 3 * sizeof(float), n, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);

    // topology
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(GLuint), el, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void VBOCube::render() {
    glBindVertexArray(vaoHandle);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
