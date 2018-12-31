#pragma once


class Window
{
    void* handle_;
public:
    Window();
    ~Window();
    int init(int x, int y, int w, int h, const char* title);
    int show();
};
