// Project headers
#include "vector.h"

// Standard library headers
#include <stdlib.h>

Vector *constructVector(float x, float y, float z)
{
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    vector->component = (float *)malloc(3 * sizeof(float));

    vector->component[0] = x;
    vector->component[1] = y;
    vector->component[2] = z;

    return vector;
}

void scaleVector(Vector *vector, float scalar)
{
    for (int i = 0; i < 3; i++)
        vector->component[i] *= scalar;
}

void addVector(Vector *vector, Vector *other)
{
    for (int i = 0; i < 3; i++)
        vector->component[i] += other->component[i];
}
