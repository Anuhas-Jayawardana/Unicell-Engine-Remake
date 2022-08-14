#include "Display/VertexBuffer.h"

namespace Unicell {
    VertexBuffer::VertexBuffer(int size,const void* data)
    {
        glGenBuffers(1,&ID);
        Bind();
        glBufferData(GL_ARRAY_BUFFER,size,data,GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1,&ID);
    }

    void VertexBuffer::Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER,ID);
    }

    void VertexBuffer::Unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }
}