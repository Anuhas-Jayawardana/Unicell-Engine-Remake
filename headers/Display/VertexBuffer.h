#pragma once

#include <GL/glew.h>

namespace Unicell {
    class VertexBuffer {
    public:
        VertexBuffer(int size,const void* data);
        ~VertexBuffer();

        void Bind();
        void Unbind();
    private:
        GLuint ID;
    };
}