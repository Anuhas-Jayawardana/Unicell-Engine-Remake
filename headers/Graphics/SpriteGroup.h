#pragma once

#include <GL/glew.h>
#include <Graphics/Sprite.h>
#include <iostream>
#include <vector>

namespace Unicell {
    class SpriteGroup {
        public:
            SpriteGroup();
            ~SpriteGroup();

            std::vector<Sprite> sprites;

            void Add(Sprite& sprite);
            void Remove(Sprite& item);
            void Move(float x,float y);
    };
}