#include <SDL2/SDL.h>
#include <Turtle/Constants.h>
#include <Turtle/Window.h>


Window::Window()
{
}


Window::~Window()
{
    SDL_DestroyWindow((SDL_Window*)handle_);
    SDL_Quit();
}





int Window::init(int x, int y, int w, int h, const char* title)
{
    SDL_Init(SDL_INIT_VIDEO);
    handle_ = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
    SDL_Surface* screenSurface = SDL_GetWindowSurface((SDL_Window*)handle_);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    return 0;
}


int Window::show()
{
    return 0;
}


void* Window::getPixelData() const
{
    return SDL_GetWindowSurface((SDL_Window*)handle_)->pixels;
}


int Window::getWidth() const
{
    int result;
    SDL_GetWindowSize((SDL_Window*)handle_, &result, 0);
    return result;
}


int Window::getHeight() const
{
    int result;
    SDL_GetWindowSize((SDL_Window*)handle_, 0, &result);
    return result;
}


int Window::redraw()
{
    SDL_UpdateWindowSurface((SDL_Window*)handle_);
    return FRC_OK;
}
