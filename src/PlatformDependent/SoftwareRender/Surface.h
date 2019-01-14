#pragma once


#include <Turtle/Window.h>
#include <Debug.h>


class Surface
{
private:
    int width_;
    int height_;
    char* data_;
    short int charsPerPixel_;     // should be always equal to colorDepth_ * colorsPerPixel_
    short int colorDepth_;        // how many bytes there are in single R/G/B/A/... channel
    short int colorsPerPixel_;    // how many channels there are in one pixel
public:
    Surface();
    Surface(const Window& wnd);
    ~Surface();

    /*
     For now this function is TOO MUCH slow and does not care about surface format.
     There should be no additional variables and copying have to be performed in one opertation.
    */
    inline void setPixel(int x, int y, int r, int g, int b)
    {
        ASSERT(0 <= x && x < width_);
        ASSERT(0 <= y && y < height_);
        int index = (width_ * y + x) * charsPerPixel_;
        data_[index] = r;
        data_[index + 1] = g;
        data_[index + 2] = b;
    };
};
