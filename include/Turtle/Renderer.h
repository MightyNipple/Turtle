#pragma once


#include <Turtle/Window.h>


class Renderer
{
private:
    struct Private;
    Private* pimpl;
public:
    Renderer();
    Renderer(const Window& wnd);
    ~Renderer();
    int render();
};
