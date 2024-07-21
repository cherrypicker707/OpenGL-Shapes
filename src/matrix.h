#ifndef MATRIX_H
#define MATRIX_H

// Project headers
#include "vector.h"

typedef struct {
  float *entry;
} Matrix;

Matrix *constructMatrix();
Matrix *constructIdentityMatrix();
Matrix *constructScalingMatrix(Vector *scaling);
Matrix *constructRotationMatrix(Vector *rotation);
Matrix *constructTranslationMatrix(Vector *translation);
Matrix *constructPerspectiveMatrix(float aspect, float fieldOfView, float near,
                                   float far);
Matrix *matrixProduct(Matrix *left, Matrix *right);

#endif
