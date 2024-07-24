#ifndef OBJECT_H
#define OBJECT_H

#include "matrix.h"
#include "shape.h"

typedef struct {
  Shape *shape;
  Matrix *scaling;
  Matrix *rotation;
  Matrix *translation;
} Object;

Object *constructObject(Shape *shape);
Object *scaleObject(Shape *shape);
Object *rotateObject(Shape *shape);
Object *translateObject(Shape *shape);

#endif
