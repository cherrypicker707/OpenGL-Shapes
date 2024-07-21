// Project headers
#include "matrix.h"
#include "shader.h"
#include "shape.h"
#include "vector.h"
#include "window.h"

// Standard library headers
#include <assert.h>
#include <stdbool.h>

// Third party headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <glad/glad.h>

// Constants
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main()
{
    Window *window = constructWindow("Thing", WINDOW_WIDTH, WINDOW_HEIGHT);
    Shader *shader = constructShader("../res/vertexShader.glsl", "../res/fragmentShader.glsl");

    useShader(shader);

    Shape *cube = constructCube();

    setMatrixUniform(shader, "scaling", constructScalingMatrix(constructVector(0.5f, 0.5f, 0.5f)));
    setMatrixUniform(shader, "rotation", constructRotationMatrix(constructVector(0.0f, 0.0f, 0.0f)));
    setMatrixUniform(shader, "translation", constructTranslationMatrix(constructVector(0.0f, 0.0f, 5.0f)));
    setMatrixUniform(shader, "camera", constructIdentityMatrix());
    setMatrixUniform(shader, "projection",
                     constructPerspectiveMatrix((float)WINDOW_HEIGHT / (float)WINDOW_WIDTH, 120.0f, 0.01f, 10.0f));

    while (isWindowOpen(window))
    {
        handleEvents(window);

        clearWindow(0.0f, 0.0f, 0.0f);
        drawShape(cube);
        refreshWindow(window);
    }

    return 0;
}
