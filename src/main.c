// Project headers
#include "shader.h"
#include "shape.h"
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

    while (isWindowOpen(window))
    {
        handleEvents(window);

        clearWindow(0.0f, 0.0f, 0.0f);
        drawShape(cube);
        refreshWindow(window);
    }

    return 0;
}
