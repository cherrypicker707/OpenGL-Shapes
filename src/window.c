// Project headers
#include "window.h"

// Standard library headers
#include <SDL2/SDL_keyboard.h>
#include <assert.h>
#include <stdlib.h>

// Third party headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <glad/glad.h>

Window *constructWindow(const char *title, unsigned int width, unsigned int height)
{
    assert(SDL_Init(SDL_INIT_EVERYTHING) == 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    SDL_Window *pointer = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                                           SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    assert(pointer != NULL);

    SDL_GLContext context = SDL_GL_CreateContext(pointer);
    assert(context != NULL);
    SDL_GL_MakeCurrent(pointer, context);

    gladLoadGLLoader(SDL_GL_GetProcAddress);
    glViewport(0, 0, width, height);

    Window *window = (Window *)malloc(sizeof(Window));
    window->pointer = pointer;
    window->context = context;
    window->open = true;

    return window;
}

bool isWindowOpen(Window *window)
{
    return window->open;
}

void handleEvents(Window *window)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT)
            destroyWindow(window);

    window->keyboard = SDL_GetKeyboardState(NULL);
}

void clearWindow(float red, float green, float blue)
{
    glClearColor(red, green, blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void refreshWindow(Window *window)
{
    SDL_GL_SwapWindow(window->pointer);
}

void destroyWindow(Window *window)
{
    window->open = false;

    SDL_GL_DeleteContext(window->context);
    SDL_DestroyWindow(window->pointer);
    SDL_Quit();
}
