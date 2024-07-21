// Project headers
#include "camera.h"
#include "matrix.h"
#include "shader.h"

// Standard library headers
#include <stdlib.h>

Camera *constructCamera(Shader *shader)
{
    Camera *camera = (Camera *)malloc(sizeof(Camera));

    camera->transformation = constructIdentityMatrix();
    camera->shader = shader;

    updateCamera(camera);

    return camera;
}

void updateCamera(Camera *camera)
{
    setMatrixUniform(camera->shader, "camera", camera->transformation);
}

void rotateCamera(Camera *camera, Vector *rotation)
{
    Matrix *matrix = constructRotationMatrix(rotation);

    camera->transformation = matrixProduct(matrix, camera->transformation);

    updateCamera(camera);
}

void translateCamera(Camera *camera, Vector *translation)
{
    Matrix *matrix = constructTranslationMatrix(translation);

    camera->transformation = matrixProduct(matrix, camera->transformation);

    updateCamera(camera);
}
