#ifndef SHADER_H
#define SHADER_H

// Project headers
#include "matrix.h"
#include "vector.h"

typedef struct
{
    unsigned int program;
} Shader;

Shader *constructShader(const char *vertexShaderPath, const char *fragmentShaderPath);
void destroyShader(Shader *shader);
void useShader(Shader *shader);
void setVectorUniform(Shader *shader, const char *name, Vector *vector);
void setMatrixUniform(Shader *shader, const char *name, Matrix *matrix);

#endif
