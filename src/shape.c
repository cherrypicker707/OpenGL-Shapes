// Project Headers
#include "shape.h"

// Standard library headers
// #include <stdio.h>
#include <stdlib.h>

// Third party headers
#include <glad/glad.h>

Shape *constructCube()
{
    float vertexData[144];
    for (int i = 0; i < 24; i++)
    {
        int f = i / 8;
        int d = (i / 4) % 2;
        int o = i % 4;

        vertexData[6 * i + (f + 0) % 3] = 2 * d - 1;
        // FIX: replace '<' with '/'
        vertexData[6 * i + (f + 1) % 3] = 2 * (o > 1) - 1;
        vertexData[6 * i + (f + 2) % 3] = 2 * (o % 2) - 1;
        vertexData[6 * i + 3] = 0;
        vertexData[6 * i + 4] = 0;
        vertexData[6 * i + 5] = 0;
        vertexData[6 * i + 3 + f] = 2 * d - 1;

        // printf("%f %f %f -> %f %f %f\n", vertexData[6 * i + 0], vertexData[6 * i + 1], vertexData[6 * i + 2],
        //        vertexData[6 * i + 3], vertexData[6 * i + 4], vertexData[6 * i + 5]);
    }

    unsigned int indexData[36];
    for (int i = 0; i < 6; i++)
    {
        indexData[6 * i + 0] = 4 * i + 0;
        indexData[6 * i + 1] = 4 * i + 1;
        indexData[6 * i + 2] = 4 * i + 2;
        indexData[6 * i + 3] = 4 * i + 1;
        indexData[6 * i + 4] = 4 * i + 2;
        indexData[6 * i + 5] = 4 * i + 3;
    }

    unsigned int vertexArrayObject, vertexBufferObject, elementBufferObject;
    glGenVertexArrays(1, &vertexArrayObject);
    glGenBuffers(1, &vertexBufferObject);
    glGenBuffers(1, &elementBufferObject);

    glBindVertexArray(vertexArrayObject);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, 144 * sizeof(float), vertexData, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(unsigned int), indexData, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    Shape *cube = (Shape *)malloc(sizeof(Shape));
    cube->vertexArrayObject = vertexArrayObject;
    cube->vertexCount = 36;

    return cube;
}

void drawShape(Shape *shape)
{
    glBindVertexArray(shape->vertexArrayObject);
    glDrawElements(GL_TRIANGLES, shape->vertexCount, GL_UNSIGNED_INT, 0);
}
