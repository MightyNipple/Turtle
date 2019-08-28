#include <Turtle/Constants.h>
#include <Turtle/Renderer.h>
#include "Surface.h"

#include <glm/common.hpp>
#include <glm/vec4.hpp>

#include <iostream>
struct Vertex3D
{
    glm::vec4 pos;
};


struct RenderEdge
{
    float x;
    float xStep;
    void step()
    {
        x += xStep;
    };
    void step(float multiplier)
    {
        x += xStep * multiplier;
    };
    RenderEdge(Vertex3D* topVert, Vertex3D* botVert) 
    {
        x = topVert->pos.x;
        // ????
        xStep = (botVert->pos.x - topVert->pos.x) / (topVert->pos.y - botVert->pos.y);
    }
};

struct Renderer::Pimpl
{
    Surface surface_;
    int fillTriangle(int yTop, int yBot, RenderEdge& reLeft, RenderEdge& reRight);
    int drawTriangle(Vertex3D* vertTop, Vertex3D* vertMid, Vertex3D* vertBot);
};


Renderer::Renderer()
{

}


Renderer::Renderer(const Window& wnd)
{
    pimpl = new Pimpl();
    pimpl->surface_ = (Surface)wnd;
}


Renderer::~Renderer()
{
    delete pimpl;
}


int Renderer::Pimpl::fillTriangle(int yTop, int yBot, RenderEdge& reLeft, RenderEdge& reRight)
{
    while (yTop >= yBot)
    {
        int x = (int)reLeft.x + 1;
        int xMax = (int)reRight.x;
        while (x <= xMax)
        {
            
            surface_.setPixel(x, yTop, 255, 0, 0);
            ++x;
        }
        reLeft.step();
        reRight.step();
        --yTop;
    }
    return FRC_OK;
}


int Renderer::Pimpl::drawTriangle(Vertex3D* vertTop, Vertex3D* vertMid, Vertex3D* vertBot)
{
    if (vertTop->pos.y < vertMid->pos.y)
    {
        Vertex3D* tmp = vertTop;
        vertTop = vertMid;
        vertMid = tmp;
    }
    if (vertMid->pos.y < vertBot->pos.y)
    {
        Vertex3D* tmp = vertMid;
        vertMid = vertBot;
        vertBot = tmp;
    }
    if (vertTop->pos.y < vertMid->pos.y)
    {
        Vertex3D* tmp = vertTop;
        vertTop = vertMid;
        vertMid = tmp;
    }
    RenderEdge topToMid(vertTop, vertMid);
    RenderEdge topToBot(vertTop, vertBot);
    RenderEdge midToBot(vertMid, vertBot);
    float delta = vertTop->pos.y - glm::floor(vertTop->pos.y);
    topToMid.step(delta);
    topToBot.step(delta);
    if (topToBot.xStep < topToMid.xStep)
    {
        fillTriangle((int)(vertTop->pos.y), (int)(vertMid->pos.y) + 1, topToBot, topToMid);
        midToBot.step(vertMid->pos.y - glm::floor(vertMid->pos.y));
        fillTriangle((int)vertMid->pos.y, (int)(vertBot->pos.y) + 1, topToBot, midToBot);
    } 
    else 
    {
        fillTriangle((int)(vertTop->pos.y), (int)(vertMid->pos.y) + 1, topToMid, topToBot);
        midToBot.step(vertMid->pos.y - glm::floor(vertMid->pos.y));
        fillTriangle((int)vertMid->pos.y, (int)(vertBot->pos.y) + 1, midToBot, topToBot);
    }
    return FRC_OK;
}


int Renderer::render(int delta)
{
    Vertex3D v1, v2, v3;
    v1.pos.x = 22.0 + delta;
    v1.pos.y = 2.0;
    v2.pos.x = 122.0 + delta;
    v2.pos.y = 100.0;
    v3.pos.x = 70.0 + delta;
    v3.pos.y = 272.0;
    for (int i = 0; i < 200; ++i)
    {
        for (int j = 0; j < 300; ++j)
        {
            pimpl->surface_.setPixel(i, j, 255, 255, 255);
        }
    }
    pimpl->drawTriangle(&v1, &v2, &v3);
    return FRC_OK;
}
