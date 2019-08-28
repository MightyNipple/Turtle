#pragma once


#include <Turtle/Input.h>


class EventHandler
{
public:
    int pollNextEvent();
    // TODO: assignment have to be made at initialisation
    int assignInputHandler(InputHandler* ih)
    {
        inputHandler_ = ih;
    };
private:
    InputHandler* inputHandler_;
};
