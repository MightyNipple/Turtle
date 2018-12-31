#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <Turtle/Window.h>


Window::Window()
{
}


Window::~Window()
{
}


int Window::init(int x, int y, int w, int h, const char* title)
{
    handle_ = new Fl_Window(x, y, w, h, title);
    ((Fl_Window*)handle_)->end();
    ((Fl_Window*)handle_)->show();
    return Fl::run();
}


int Window::show()
{
    return 0;
}
