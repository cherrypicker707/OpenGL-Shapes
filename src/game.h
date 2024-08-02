#ifndef GAME_H
#define GAME_H

// Project headers
#include "camera.h"
#include "object.h"
#include "window.h"

// Constants
#define WINDOW_TITLE "Thing"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define VERTEX_SHADER_PATH "../res/vertexShader.glsl"
#define FRAGMENT_SHADER_PATH "../res/fragmentShader.glsl"
#define ASPECT ((float)WINDOW_HEIGHT / (float)WINDOW_WIDTH)

typedef struct
{
    Window *window;
    Shader *shader;
    Camera *camera;
    Shape *cube;
    Object *object;
    Object *another;
    Matrix *projection;
} Game;

Game *constructGame();
void runGame(Game *game);
void destroyGame(Game *game);

#endif
