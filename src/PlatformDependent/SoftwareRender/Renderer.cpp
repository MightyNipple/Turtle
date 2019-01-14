#include <Turtle/Constants.h>
#include <Turtle/Renderer.h>
#include "Surface.h"


struct Renderer::Private
{
    Surface surface_;
};


Renderer::Renderer()
{

}


Renderer::Renderer(const Window& wnd)
{
    pimpl = new Private();
    pimpl->surface_ = (Surface)wnd;
}


Renderer::~Renderer()
{
    delete pimpl;
}



int Renderer::render()
{
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            pimpl->surface_.setPixel(i, j, 255, 0, 0);
        }
    }
    return FRC_OK;
}
