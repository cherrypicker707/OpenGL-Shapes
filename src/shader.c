// Project headers
#include "shader.h"
#include "file.h"

// Standard library headers
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

// Third party headers
#include <glad/glad.h>

static unsigned int compileShader(const char *path, unsigned int type)
{
    unsigned int shader = glCreateShader(type);

    const char *source = getFileContent(path);
    glShaderSource(shader, 1, &source, NULL);

    glCompileShader(shader);

    int status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    assert(status);

    return shader;
}

static unsigned int linkProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
    unsigned int program = glCreateProgram();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    int status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    assert(status);

    return program;
}

Shader *constructShader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    unsigned int vertexShader = compileShader(vertexShaderPath, GL_VERTEX_SHADER);
    unsigned int fragmentShader = compileShader(fragmentShaderPath, GL_FRAGMENT_SHADER);

    unsigned int program = linkProgram(vertexShader, fragmentShader);

    Shader *shader = (Shader *)malloc(sizeof(Shader));
    shader->program = program;

    return shader;
}

void useShader(Shader *shader)
{
    glUseProgram(shader->program);
}

void setVectorUniform(Shader *shader, const char *name, Vector *vector)
{
    glUniform3fv(glGetUniformLocation(shader->program, name), 1, vector->component);
}

void setMatrixUniform(Shader *shader, const char *name, Matrix *matrix)
{
    glUniformMatrix4fv(glGetUniformLocation(shader->program, name), 1, GL_FALSE, matrix->entry);
}
