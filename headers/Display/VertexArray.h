#pragma once

#include <GL/glew.h>

namespace Unicell {
    class VertexArray {
    public:
        VertexArray();
        ~VertexArray();

        void Bind();
        void Unbind();
    private:
        GLuint ID;
    };
}