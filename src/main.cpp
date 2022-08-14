#include "Unicell.h"
#include "Display/VertexArray.h"
#include "Display/VertexBuffer.h"

using namespace Unicell;

int main()
{
    Window window(800,600,"Window");
    Sprite sprite(0.0f,0.0f,100.0f,100.0f);

    sprite.setTexture("res/otherpfp.png");

   while(!window.closed()){
        window.Clear();
        window.Draw(sprite);
        window.Update();
    }
    window.Quit();

    return 0;
}