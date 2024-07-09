#ifndef SHADER_H
#define SHADER_H

typedef struct {
  unsigned int program;
} Shader;

Shader *constructShader(const char *vertexShaderPath,
                        const char *fragmentShaderPath);
void useShader(Shader *shader);

#endif
