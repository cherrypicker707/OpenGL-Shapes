#include "matrix.h"
#include <stdlib.h>

#define e(r, c) 4 * c + r

Matrix *constructIdentityMatrix()
{
    Matrix *matrix = (Matrix *)calloc(16, sizeof(float));

    for (int i = 0; i < 4; i++)
        matrix->entry[e(i, i)] = 1.0f;

    return matrix;
}
