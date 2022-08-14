#include "Graphics/Sprite.h"

namespace Unicell {
    Sprite::Sprite(float x,float y,float width,float height)
    {
        float positions[] = {
            x,y + height,0.0f,              
            x + width,y + height,0.0f,      
            x + width,y,0.0f,               
            x + width,y,0.0f,               
            x,y,0.0f,                       
            x,y + height,0.0f,
        };

        count = sizeof(positions);

        const char* vertex = 
        "#version 330 core\n"
        "layout(location=0)in vec3 pos;\n"
        "layout(location=1)in vec2 aCoords;\n"
        "out vec2 coords;\n"
        "uniform mat4 u_projection;\n"
        "uniform mat4 u_model = mat4(1.0);\n"
        "uniform mat4 u_view = mat4(1.0);\n"
        "void main() {coords = aCoords; gl_Position = u_projection * u_model * u_view * vec4(pos,1.0);}";

        const char* fragment = 
        "#version 330 core\n"
        "out vec4 color;\n"
        "in vec2 coords;\n"
        "uniform sampler2D tex;\n"
        "void main() {color = texture(tex,coords);\n}";

        shader = std::make_shared<Shader>(vertex,fragment);
        vao = std::make_shared<VertexArray>();
        vbo = std::make_shared<VertexBuffer>(count,positions);
        vao->Bind();
        
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5 * sizeof(float),(void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5 * sizeof(float),(void*)(3 * sizeof(float)));

    }

    glm::mat4 Sprite::getModelView()
    {
        return model_view;
    }

    glm::vec2 Sprite::getPosition()
    {
        return position;
    }

    glm::vec2 Sprite::getSize()
    {
        return size;
    }

    int Sprite::getVertexCount()
    {
        return count;
    }

    void Sprite::setTexture(const char* path){
        texture = std::make_shared<Texture>(path);
    }

    void Sprite::Move(float x,float y)
    {
        model_view = glm::translate(model_view,glm::vec3(x,y,0.0f));
    }

    void Sprite::Rotate(float amount,glm::vec3 dir)
    {
        model_view = glm::rotate(model_view,glm::radians(amount),dir);
    }

    void Sprite::Scale(float x,float y)
    {
        model_view = glm::scale(model_view,glm::vec3(x,y,0.0f));
    }

    void Sprite::Bind()
    {
        vbo->Bind();
        vao->Bind();
    }

    void Sprite::Unbind()
    {
        vbo->Unbind();
        vao->Unbind();
    }

}