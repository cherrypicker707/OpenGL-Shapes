#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <assert.h>
#include <glad/glad.h>
#include <stdbool.h>

int main()
{
    assert(SDL_Init(SDL_INIT_EVERYTHING) == 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_Window *window = SDL_CreateWindow("Thing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_GLContext *context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);

    gladLoadGLLoader(SDL_GL_GetProcAddress);

    bool running = true;
    while (running)
    {
        SDL_Event *event;
        while (SDL_PollEvent(event))
        {
            if (event->type == SDL_QUIT)
                running = false;
        }

        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);
    }

    return 0;
}
