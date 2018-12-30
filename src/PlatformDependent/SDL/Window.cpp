#include <SDL/SDL.h>
#include <Turtle/Window.h>


Window::Window()
{
}


Window::~Window()
{
}


int Window::Init(int x, int y, int w, int h, const char* title)
{
    SDL_Init(SDL_INIT_VIDEO);
    handle_ = SDL_CreateWindow(title, x, y, w, h, 0);
    SDL_Delay(3000);
    SDL_DestroyWindow((SDL_Window*)handle_);
    SDL_Quit();
    return 0;
}


int Window::Show()
{
    return 0;
}
