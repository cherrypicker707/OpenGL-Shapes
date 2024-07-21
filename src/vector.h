#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
  float *component;
} Vector;

Vector *constructVector(float x, float y, float z);
void scaleVector(Vector *vector, float scalar);

#endif
