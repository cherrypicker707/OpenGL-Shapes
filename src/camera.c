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

    camera->rotation = constructIdentityMatrix();
    camera->translation = constructIdentityMatrix();
    camera->shader = shader;

    updateCamera(camera);

    return camera;
}

void updateCamera(Camera *camera)
{
    setMatrixUniform(camera->shader, "cameraRotation", camera->rotation);
    setMatrixUniform(camera->shader, "cameraTranslation", camera->translation);
}

void rotateCamera(Camera *camera, Vector *rotation)
{
    scaleVector(rotation, -1.0f);
    Matrix *matrix = constructRotationMatrix(rotation);

    camera->rotation = matrixProduct(matrix, camera->rotation);

    updateCamera(camera);
}

void translateCamera(Camera *camera, Vector *translation)
{
    scaleVector(translation, -1.0f);
    Matrix *matrix = constructTranslationMatrix(translation);

    camera->translation = matrixProduct(matrix, camera->translation);

    updateCamera(camera);
}
