#pragma once

#include <GL/glew.h>

namespace Unicell
{
    class Texture {
    public:
        Texture(const char* path);
        ~Texture();

        void Bind();
        void Unbind();
    private:
        int width,height,bpp;
        GLuint ID;
    };
}