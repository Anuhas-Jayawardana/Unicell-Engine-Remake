#include "Unicell.h"

using namespace Unicell;

int main()
{
    Window window(800,600,"Window");

    Sprite player(0.0f,0.0f,100.0f,100.0f);
    Sprite enemy(200.0f,200.0f,100.0f,100.0f);

    player.setTexture("res/player.png");
    enemy.setTexture("res/player.png");

    bool colliding = false;

   while(!window.closed()){
        window.Clear();

        colliding = player.CheckCollision(enemy);

        player.setPosition(window.getMousePosition().x,window.getMousePosition().y);

        window.Draw(player);
        
        if(!colliding)
            window.Draw(enemy);

        window.Update();
    }
    window.Quit();

    return 0;
}