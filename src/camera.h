#ifndef CAMERA_H
#define CAMERA_H

// Project headers
#include "matrix.h"
#include "shader.h"

typedef struct {
  Matrix *transformation;
  Shader *shader;
} Camera;

Camera *constructCamera(Shader *shader);
void updateCamera(Camera *camera);
void rotateCamera(Camera *camera, Vector *rotation);
void translateCamera(Camera *camera, Vector *translation);

#endif
