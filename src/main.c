// Project headers
#include "game.h"

// Standard library headers
#include <assert.h>
#include <float.h>
#include <stdbool.h>

// Third party headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <glad/glad.h>

int main()
{
    Game *game = constructGame();
    runGame(game);
    destroyGame(game);

    return 0;
}
