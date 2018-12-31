#include <SDL2/SDL.h>
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
    handle_ = SDL_CreateWindow(title, x, y, w, h, 0);
    return 0;
}


int Window::show()
{
    return 0;
}
