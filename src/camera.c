// Project headers
#include "camera.h"
#include "matrix.h"
#include "shader.h"
#include "vector.h"

// Standard library headers
#include <stdlib.h>

Camera *constructCamera(Shader *shader)
{
    Camera *camera = (Camera *)malloc(sizeof(Camera));

    camera->position = constructIdentityMatrix();
    camera->normal = constructIdentityMatrix();
    camera->rotation = constructVector(0.0f, 0.0f, 0.0f);
    camera->translation = constructVector(0.0f, 0.0f, 0.0f);
    camera->shader = shader;

    updateCamera(camera);

    return camera;
}

void updateCamera(Camera *camera)
{
    camera->position = matrixProduct(constructRotationMatrix(camera->rotation), camera->position);
    camera->normal = matrixProduct(constructRotationMatrix(camera->rotation), camera->normal);
    camera->rotation = constructVector(0.0f, 0.0f, 0.0f);

    camera->position = matrixProduct(constructTranslationMatrix(camera->translation), camera->position);
    camera->translation = constructVector(0.0f, 0.0f, 0.0f);

    setMatrixUniform(camera->shader, "camera", camera->position);
    setMatrixUniform(camera->shader, "cameraNormal", camera->normal);
}

void rotateCamera(Camera *camera, Vector *rotation)
{
    scaleVector(rotation, -1.0f);
    addVector(camera->rotation, rotation);
}

void translateCamera(Camera *camera, Vector *translation)
{
    scaleVector(translation, -1.0f);
    addVector(camera->translation, translation);
}
