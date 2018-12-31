#include <Turtle/Constants.h>
#include <Turtle/EventHandler.h>
#include <Turtle/Utility.h>
#include <Turtle/Window.h>


int main(int argc, char* argv[])
{
    Window w;
    w.init(0, 0, 200, 200, "Turtle");
    EventHandler eh;
    while (eh.pollNextEvent() != FRC_QUIT)
    {
        sleep(10);
    }
    return 0;
}
