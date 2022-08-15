#include "Graphics/SpriteGroup.h"

namespace Unicell {
    SpriteGroup::SpriteGroup()
    {

    }

    SpriteGroup::~SpriteGroup()
    {
        sprites.pop_back();
    }

    void SpriteGroup::Move(float x,float y)
    {
        for(int i = 0;i < sprites.size(); i++)
        {
            sprites.at(i).Move(x,y);
        }
    }

    void SpriteGroup::Remove(Sprite& sprite)
    {
        // TODO : find a way to remove it ...
    }

    void SpriteGroup::Add(Sprite& sprite)
    {
        sprites.push_back(sprite);
    }
}