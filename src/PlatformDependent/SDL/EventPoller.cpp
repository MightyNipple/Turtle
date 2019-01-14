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
    case SDL_QUIT:
        return FRC_QUIT;
    }
    return FRC_OK;
}
