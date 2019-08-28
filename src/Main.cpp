#include <Turtle/Constants.h>
#include <Turtle/EventHandler.h>
#include <Turtle/Input.h>
#include <Turtle/Renderer.h>
#include <Turtle/Utility.h>
#include <Turtle/Window.h>


#include <Turtle/BSTree.h>
#include <iostream>
#include <Debug.h>



int main(int argc, char* argv[])
{
    ASSERT(false);
    Window w;
    w.init(50, 50, 500, 300, "Turtle");
    Renderer rnd(w);
    EventHandler eh;
    InputHandler ih;
    InputParam ipDelta;
    eh.assignInputHandler(&ih);
    ih.registerKey(KC_D, &ipDelta, 1);
    ih.registerKey(KC_A, &ipDelta, -1);
    while (eh.pollNextEvent() != FRC_QUIT)
    {
        rnd.render(ipDelta.get() * 20);
        w.redraw();
        sleep(10);
    }
    return 0;
}
