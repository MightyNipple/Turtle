#include <SDL2/SDL.h>
#include <Turtle/Constants.h>
#include <Turtle/EventHandler.h>


int EventHandler::pollNextEvent()
{
    SDL_Event event;
    if (!SDL_PollEvent(&event))
    {
        return FRC_NOEVENT;
    }
    switch (event.type)
    {
    case SDL_KEYDOWN:
        inputHandler_->handleKey(event.key.keysym.scancode, true);
        break;
    case SDL_KEYUP:
        inputHandler_->handleKey(event.key.keysym.scancode, false);
        break;
    case SDL_MOUSEBUTTONDOWN:
        inputHandler_->handleKey(event.key.keysym.scancode, true);
        break;
    case SDL_MOUSEBUTTONUP:
        inputHandler_->handleKey(event.key.keysym.scancode, false);
        break;
    case SDL_MOUSEMOTION:
        break;
    case SDL_QUIT:
        return FRC_QUIT;
    }
    return FRC_OK;
}
