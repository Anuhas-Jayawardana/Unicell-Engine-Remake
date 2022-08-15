#include "Unicell.h"

/*
Unicell Engine - Apache 2.0 License (github open-source project)
    - textures
    - rectangles
    - sprite groups
    - window handling
    - shaders
    - audio support
    - image loading
*/

int main()
{
    Unicell::Window window(800,600,"Window");
    Unicell::Sprite spr(350.f,250.f,100.0f,100.0f);
    spr.setTexture("res/player.png");

    while(!window.closed())
    {
        // have a look around the engine, this can go much more than you think :)
        window.Clear();
        window.Draw(spr);
        window.Update();
    }

    window.Quit();
}