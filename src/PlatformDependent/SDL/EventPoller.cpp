#include <SDL2/SDL.h>
#include <Turtle/Constants.h>
#include <Turtle/EventHandler.h>


int EventHandler::pollNextEvent()
{
    SDL_Event e;
    if (!SDL_PollEvent(&e))
    {
        return FRC_NOEVENT;
    }
    switch (e.type)
    {
    case SDL_KEYDOWN:
        break;
    case SDL_KEYUP:
        break;
    case SDL_MOUSEBUTTONDOWN:
        break;
    case SDL_MOUSEBUTTONUP:
        break;
    case SDL_MOUSEMOTION:
        break;
    case SDL_QUIT:
        return FRC_QUIT;
    }
    return FRC_OK;
}
