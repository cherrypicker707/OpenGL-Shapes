#include "game.h"
#include <SDL2/SDL.h>

Game *constructGame()
{
    Game *game = (Game *)malloc(sizeof(Game));

    game->window = constructWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    game->shader = constructShader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
    game->camera = constructCamera(game->shader);
    game->cube = constructCube();
    game->object = constructObject(game->cube, game->shader);
    game->another = constructObject(game->cube, game->shader);
    game->projection = constructPerspectiveMatrix(ASPECT, 120.0f, FLT_TRUE_MIN, 10.0f);

    useShader(game->shader);

    setMatrixUniform(game->shader, "projection", game->projection);

    translateCamera(game->camera, constructVector(1.0f, 1.0f, -2.0f));

    scaleObject(game->object, constructVector(2.0f, 1.0f, 1.5f));
    translateObject(game->object, constructVector(5.0f, 2.0f, 5.0f));
    rotateObject(game->object, constructVector(1.0f, 1.0f, 1.0f));
    colorObject(game->object, constructVector(0.75f, 0.0f, 0.75f));

    scaleObject(game->another, constructVector(0.5f, 1.0f, 2.0f));
    translateObject(game->another, constructVector(-5.0f, 0.0f, 0.0f));
    rotateObject(game->another, constructVector(-1.0f, 0.0f, 0.5f));
    colorObject(game->another, constructVector(0.5f, 1.0f, 0.0f));

    return game;
}

void runGame(Game *game)
{
    float t = (float)SDL_GetTicks() / 1000.0f;
    float dt = 0.0f;
    while (isWindowOpen(game->window))
    {
        handleEvents(game->window);

        if (isPressed(game->window, KEY_A))
            translateCamera(game->camera, constructVector(dt * -1.0f, 0.0f, 0.0f));
        if (isPressed(game->window, KEY_D))
            translateCamera(game->camera, constructVector(dt * 1.0f, 0.0f, 0.0f));
        if (isPressed(game->window, KEY_LCTRL))
            translateCamera(game->camera, constructVector(0.0f, dt * -1.0f, 0.0f));
        if (isPressed(game->window, KEY_SPACE))
            translateCamera(game->camera, constructVector(0.0f, dt * 1.0f, 0.0f));
        if (isPressed(game->window, KEY_S))
            translateCamera(game->camera, constructVector(0.0f, 0.0f, dt * -1.0f));
        if (isPressed(game->window, KEY_W))
            translateCamera(game->camera, constructVector(0.0f, 0.0f, dt * 1.0f));
        if (isPressed(game->window, KEY_Q))
            rotateCamera(game->camera, constructVector(0.0f, dt * -1.0f, 0.0f));
        if (isPressed(game->window, KEY_E))
            rotateCamera(game->camera, constructVector(0.0f, dt * 1.0f, 0.0f));
        updateCamera(game->camera);

        clearWindow(0.0f, 0.0f, 0.0f);
        drawObject(game->object);
        drawObject(game->another);
        refreshWindow(game->window);

        dt = ((float)SDL_GetTicks() / 1000.0f) - t;
        t = ((float)SDL_GetTicks() / 1000.0f);
    }
}

void destroyGame(Game *game)
{
    destroyShader(game->shader);
    destroyShape(game->cube);
    destroyCamera(game->camera);
    destroyObject(game->object);
    destroyObject(game->another);
    destroyMatrix(game->projection);
}
