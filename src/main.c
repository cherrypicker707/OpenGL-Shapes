#include "shader.h"
#include "shape.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <assert.h>
#include <glad/glad.h>
#include <stdbool.h>

int main()
{
    assert(SDL_Init(SDL_INIT_EVERYTHING) == 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_Window *window = SDL_CreateWindow("Thing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    assert(window != NULL);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    assert(context != NULL);
    SDL_GL_MakeCurrent(window, context);
    gladLoadGLLoader(SDL_GL_GetProcAddress);

    Shader *shader = constructShader("../res/vertexShader.glsl", "../res/fragmentShader.glsl");
    useShader(shader);

    Shape *cube = constructCube();

    glClearColor(0.07f, 0.07f, 0.11f, 1.0f);
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                running = 0;
        glClear(GL_COLOR_BUFFER_BIT);

        useShader(shader);
        glBindVertexArray(cube->vertexArrayObject);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        SDL_GL_SwapWindow(window);
    }

    return 0;
}
