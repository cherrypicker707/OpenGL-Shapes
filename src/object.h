#ifndef OBJECT_H
#define OBJECT_H

#include "matrix.h"
#include "shader.h"
#include "shape.h"

typedef struct
{
    Shader *shader;
    Shape *shape;
    Matrix *scaling;
    Matrix *rotation;
    Matrix *translation;
    Vector *color;
} Object;

Object *constructObject(Shape *shape, Shader *shader);
void scaleObject(Object *object, Vector *scaling);
void rotateObject(Object *object, Vector *rotation);
void translateObject(Object *object, Vector *translation);
void colorObject(Object *object, Vector *color);
void drawObject(Object *object);

#endif
