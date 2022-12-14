#include "Display/VertexArray.h"

namespace Unicell {
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1,&ID);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1,&ID);
    }

    void VertexArray::Bind()
    {
        glBindVertexArray(ID);
    }

    void VertexArray::Unbind()
    {
        glBindVertexArray(0);
    }
}