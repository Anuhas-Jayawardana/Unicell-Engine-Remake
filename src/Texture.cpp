#include "Graphics/Texture.h"
#include <stb/stb_image.h>
#include <iostream>

namespace Unicell
{
    Texture::Texture(const char* path)
    {
        stbi_set_flip_vertically_on_load(1);
        
        glGenTextures(1,&ID);
        glBindTexture(GL_TEXTURE_2D,ID);

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

        unsigned char* bytes = stbi_load(path,&width,&height,&bpp,0);

        if(bpp == 3)
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,bytes);
        if(bpp == 4)
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,bytes);

        Unbind();

        stbi_image_free(bytes);

    }

    Texture::~Texture()
    {
        glDeleteTextures(1,&ID);
    }

    void Texture::Bind()
    {
        glBindTexture(GL_TEXTURE_2D,ID);
    }

    void Texture::Unbind()
    {
        glBindTexture(GL_TEXTURE_2D,0);
    }
}