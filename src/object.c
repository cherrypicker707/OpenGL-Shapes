#include "object.h"
#include "matrix.h"
#include "shader.h"
#include "shape.h"
#include <stdlib.h>

Object *constructObject(Shape *shape, Shader *shader)
{
    Object *object = (Object *)malloc(sizeof(Object));

    object->shader = shader;
    object->shape = shape;
    object->scaling = constructScalingMatrix(constructVector(1.0f, 1.0f, 1.0f));
    object->rotation = constructRotationMatrix(constructVector(0.0f, 0.0f, 0.0f));
    object->translation = constructTranslationMatrix(constructVector(0.0f, 0.0f, 0.0f));

    return object;
}

void scaleObject(Object *object, Vector *scaling)
{
    object->scaling = constructScalingMatrix(scaling);
}

void rotateObject(Object *object, Vector *rotation)
{
    object->rotation = constructRotationMatrix(rotation);
}

void translateObject(Object *object, Vector *translation)
{
    object->translation = constructTranslationMatrix(translation);
}

void drawObject(Object *object)
{
    setMatrixUniform(object->shader, "scaling", object->scaling);
    setMatrixUniform(object->shader, "rotation", object->rotation);
    setMatrixUniform(object->shader, "translation", object->translation);
    drawShape(object->shape);
}
