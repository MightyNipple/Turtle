#pragma once


#include <Turtle/BSTree.h>
#include <Turtle/Constants.h>


class InputParam
{
public:
    InputParam();
    void increase(int value);
    int get();
private:
    int value_;
};


class InputHandler
{
public:
    int registerKey(int keycode, InputParam* attrib, int value);
    int handleKey(int keycode, bool isPressed);
private:
    struct KeyHandler
    {
        InputParam* param;
        int value;
    };
    BSTree<int, KeyHandler> KeyTable;
};
