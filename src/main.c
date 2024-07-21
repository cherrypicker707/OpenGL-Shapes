// Project headers
#include "camera.h"
#include "matrix.h"
#include "shader.h"
#include "shape.h"
#include "vector.h"
#include "window.h"

// Standard library headers
#include <SDL2/SDL_timer.h>
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

    Camera *camera = constructCamera(shader);

    translateCamera(camera, constructVector(1.0f, 1.0f, -2.0f));

    Shape *cube = constructCube();

    setMatrixUniform(shader, "scaling", constructScalingMatrix(constructVector(0.5f, 0.5f, 0.5f)));
    setMatrixUniform(shader, "rotation", constructRotationMatrix(constructVector(0.5f, 0.0f, 0.0f)));
    setMatrixUniform(shader, "translation", constructTranslationMatrix(constructVector(0.0f, 0.0f, 5.0f)));
    setMatrixUniform(shader, "projection",
                     constructPerspectiveMatrix((float)WINDOW_HEIGHT / (float)WINDOW_WIDTH, 120.0f, 0.01f, 10.0f));

    float t = (float)SDL_GetTicks() / 1000.0f;
    float dt = 0.0f;
    while (isWindowOpen(window))
    {
        handleEvents(window);

        if (window->keyboard[SDL_SCANCODE_W])
            translateCamera(camera, constructVector(0.0f, 0.0f, dt * 1.0f));
        if (window->keyboard[SDL_SCANCODE_S])
            translateCamera(camera, constructVector(0.0f, 0.0f, dt * -1.0f));
        if (window->keyboard[SDL_SCANCODE_A])
            translateCamera(camera, constructVector(dt * -1.0f, 0.0f, 0.0f));
        if (window->keyboard[SDL_SCANCODE_D])
            translateCamera(camera, constructVector(dt * 1.0f, 0.0f, 0.0f));
        if (window->keyboard[SDL_SCANCODE_Q])
            rotateCamera(camera, constructVector(0.0f, dt * -1.0f, 0.0f));
        if (window->keyboard[SDL_SCANCODE_E])
            rotateCamera(camera, constructVector(0.0f, dt * 1.0f, 0.0f));

        clearWindow(0.0f, 0.0f, 0.0f);
        drawShape(cube);
        refreshWindow(window);

        dt = ((float)SDL_GetTicks() / 1000.0f) - t;
        t = ((float)SDL_GetTicks() / 1000.0f);
    }

    return 0;
}
