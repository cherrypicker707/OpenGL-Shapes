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

void destroyCamera(Camera *camera)
{
    destroyMatrix(camera->position);
    camera->position = NULL;

    destroyMatrix(camera->normal);
    camera->normal = NULL;

    destroyVector(camera->rotation);
    camera->rotation = NULL;

    destroyVector(camera->translation);
    camera->translation = NULL;

    camera->shader = NULL;

    free(camera);
}

void updateCamera(Camera *camera)
{
    Matrix *rotationMatrix = constructRotationMatrix(camera->rotation);
    camera->position = matrixProduct(rotationMatrix, camera->position);
    camera->normal = matrixProduct(rotationMatrix, camera->normal);
    destroyMatrix(rotationMatrix);
    rotationMatrix = NULL;
    camera->rotation = constructVector(0.0f, 0.0f, 0.0f);

    Matrix *translationMatrix = constructTranslationMatrix(camera->translation);
    camera->position = matrixProduct(translationMatrix, camera->position);
    destroyMatrix(translationMatrix);
    translationMatrix = NULL;
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
