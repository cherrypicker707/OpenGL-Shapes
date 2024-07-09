// Project headers
#include "matrix.h"

// Standard library headers
#include <math.h>
#include <stdlib.h>

#define e(r, c) 4 * (c) + (r)

Matrix *constructMatrix()
{
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->entry = (float *)calloc(16, sizeof(float));

    return matrix;
}

Matrix *constructIdentityMatrix()
{
    Matrix *matrix = constructMatrix();

    for (int i = 0; i < 4; i++)
        matrix->entry[e(i, i)] = 1.0f;

    return matrix;
}

Matrix *constructScalingMatrix(Vector *scaling)
{
    Matrix *matrix = constructIdentityMatrix();

    for (int i = 0; i < 3; i++)
        matrix->entry[e(i, i)] *= scaling->component[i];

    return matrix;
}

Matrix *constructRotationMatrix(Vector *rotation)
{
    Matrix *factor[3];

    for (int i = 0; i < 3; i++)
        factor[i] = constructIdentityMatrix();

    for (int i = 0; i < 3; i++)
    {
        factor[i]->entry[e((i + 1) % 3, (i + 1) % 3)] = cos(rotation->component[i]);
        factor[i]->entry[e((i + 1) % 3, (i + 2) % 3)] = -sin(rotation->component[i]);
        factor[i]->entry[e((i + 2) % 3, (i + 1) % 3)] = sin(rotation->component[i]);
        factor[i]->entry[e((i + 2) % 3, (i + 2) % 3)] = cos(rotation->component[i]);
    }

    Matrix *matrix = constructIdentityMatrix();

    for (int i = 0; i < 3; i++)
        matrix = matrixProduct(matrix, factor[i]);

    return matrix;
}

Matrix *constructTranslationMatrix(Vector *translation)
{
    Matrix *matrix = constructIdentityMatrix();

    for (int i = 0; i < 3; i++)
        matrix->entry[e(i, 3)] = translation->component[i];

    return matrix;
}

Matrix *matrixProduct(Matrix *left, Matrix *right)
{
    Matrix *matrix = constructMatrix();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
                matrix->entry[e(i, j)] += left->entry[e(i, k)] * right->entry[e(k, j)];
        }
    }

    return matrix;
}
