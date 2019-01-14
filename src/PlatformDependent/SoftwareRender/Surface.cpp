#include "Surface.h"


Surface::Surface()
{
    colorsPerPixel_ = 3;
    colorDepth_ = 1;
    charsPerPixel_ = 3;
}



Surface::Surface(const Window& wnd)
{
    width_ = wnd.getWidth();
    height_ = wnd.getHeight();
    data_ = (char*)wnd.getPixelData();
    colorsPerPixel_ = 4;
    colorDepth_ = 1;
    charsPerPixel_ = 4;
}


Surface::~Surface()
{

}

