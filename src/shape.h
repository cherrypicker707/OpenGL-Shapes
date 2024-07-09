#ifndef SHAPE_H
#define SHAPE_H

typedef struct {
  unsigned int vertexArrayObject, vertexCount;
} Shape;

Shape *constructCube();
void drawShape(Shape *shape);

#endif
