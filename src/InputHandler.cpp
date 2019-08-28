#include <new>
#include <Turtle/Input.h>
#include <iostream>


/* 
    TODO: Make possible to assign multiple params to one key
*/
int InputHandler::registerKey(int keycode, InputParam* attrib, int value)
{
    KeyHandler* newKH = new (&(KeyTable[keycode])) KeyHandler;
    newKH->param = attrib;
    newKH->value = value;
    return FRC_OK;
}


int InputHandler::handleKey(int keycode, bool isPressed)
{
    KeyHandler* kh = KeyTable.getPtr(keycode);
    if (kh)
    {
        std::cout << keycode << " inc by " << kh->value * (isPressed ? 1 : -1) << std::endl;
        kh->param->increase(kh->value * (isPressed ? 1 : -1));
    }
    return FRC_OK;
}
