#include <SDL2/SDL.h>
#include <Turtle/Constants.h>


int sleep(int n)
{
    SDL_Delay(n);
    return FRC_OK;
}
