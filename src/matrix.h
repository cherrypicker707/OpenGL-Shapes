#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
  float *entry;
} Matrix;

Matrix *constructIdentityMatrix();

#endif
