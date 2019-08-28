#pragma once


#include <Turtle/Window.h>


class Renderer
{
private:
    struct Pimpl;
    Pimpl* pimpl;
public:
    Renderer();
    Renderer(const Window& wnd);
    ~Renderer();
    int render(int);
};
