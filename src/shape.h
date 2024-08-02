#ifndef SHAPE_H
#define SHAPE_H

typedef struct
{
    unsigned int vertexArrayObject;
    unsigned int vertexBufferObject;
    unsigned int elementBufferObject;
    unsigned int vertexCount;
} Shape;

Shape *constructCube();
void destroyShape(Shape *shape);
void drawShape(Shape *shape);

#endif
