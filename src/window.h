#ifndef WINDOW_H
#define WINDOW_H

// Project headers
#include "keys.h"

// Standard library headers
#include <stdbool.h>

// Third party headers
#include <SDL2/SDL_video.h>

typedef struct
{
    SDL_Window *pointer;
    SDL_GLContext context;
    const unsigned char *keyboard;
    bool open;
} Window;

Window *constructWindow(const char *title, unsigned int width, unsigned int height);
void destroyWindow(Window *window);
bool isWindowOpen(Window *window);
void handleEvents(Window *window);
bool isPressed(Window *window, unsigned short key);
void clearWindow(float red, float green, float blue);
void refreshWindow(Window *window);

#endif
