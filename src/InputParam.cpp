#include <Turtle/Input.h>



InputParam::InputParam()
{
    value_ = 0;
}


void InputParam::increase(int value)
{
    value_ += value;
}


int InputParam::get()
{
    return value_ > 0 ? 1 : (value_ < 0 ? -1 : 0);
}
