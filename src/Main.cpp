#include <Turtle/Constants.h>
#include <Turtle/EventHandler.h>
#include <Turtle/Renderer.h>
#include <Turtle/Utility.h>
#include <Turtle/Window.h>
#include <Debug.h>


int main(int argc, char* argv[])
{
    ASSERT(false);
    Window w;
    w.init(50, 50, 500, 300, "Turtle");
    Renderer rnd(w);
    EventHandler eh;
    while (eh.pollNextEvent() != FRC_QUIT)
    {
        rnd.render();
        w.redraw();
        sleep(10);
    }
    return 0;
}
