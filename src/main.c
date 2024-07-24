// Project headers
#include "camera.h"
#include "matrix.h"
#include "object.h"
#include "shader.h"
#include "shape.h"
#include "vector.h"
#include "window.h"

// Standard library headers
#include <assert.h>
#include <float.h>
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

    Object *object = constructObject(constructCube(), shader);
    scaleObject(object, constructVector(2.0f, 1.0f, 1.5f));
    translateObject(object, constructVector(5.0f, 2.0f, 5.0f));
    rotateObject(object, constructVector(1.0f, 1.0f, 1.0f));

    setMatrixUniform(
        shader, "projection",
        constructPerspectiveMatrix((float)WINDOW_HEIGHT / (float)WINDOW_WIDTH, 120.0f, FLT_TRUE_MIN, 10.0f));

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
        updateCamera(camera);

        clearWindow(0.0f, 0.0f, 0.0f);
        drawObject(object);
        refreshWindow(window);

        dt = ((float)SDL_GetTicks() / 1000.0f) - t;
        t = ((float)SDL_GetTicks() / 1000.0f);
    }

    return 0;
}
