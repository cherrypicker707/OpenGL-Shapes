#ifndef WINDOW_H
#define WINDOW_H

// Standard library headers
#include <stdbool.h>

// Third party headers
#include <SDL2/SDL_video.h>

typedef struct {
  SDL_Window *pointer;
  SDL_GLContext context;
  bool open;
} Window;

Window *constructWindow(const char *title, unsigned int width,
                        unsigned int height);
bool isWindowOpen(Window *window);
void handleEvents(Window *window);
void clearWindow(float red, float green, float blue);
void refreshWindow(Window *window);
void destroyWindow(Window *window);

#endif
