#include "Graphics/Rectangle.h"

namespace Unicell
{

    Rectangle::Rectangle(float x,float y,float width,float height)
    {
        position.x = x;
        position.y = y;
        
        size.x = width;
        size.y = height;
        
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
        "uniform mat4 u_projection;\n"
        "uniform mat4 u_model = mat4(1.0);\n"
        "uniform mat4 u_view = mat4(1.0);\n"
        "void main() {gl_Position = u_projection * u_model * u_view * vec4(pos,1.0);}";

        const char* fragment = 
        "#version 330 core\n"
        "out vec4 color;\n"
        "uniform vec4 fill = vec4(1.0,1.0,1.0,1.0);\n"
        "void main() {color = fill;}";

        shader = std::make_shared<Shader>(vertex,fragment);
        vao = std::make_shared<VertexArray>();
        vbo = std::make_shared<VertexBuffer>(count,positions);
        vao->Bind();
        
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(float),(void*)0);

    }

    glm::mat4 Rectangle::getModelView()
    {
        return model_view;
    }

    glm::vec4 Rectangle::getFillColor()
    {
        return fill;
    }

    glm::vec2 Rectangle::getPosition()
    {
        return position;
    }

    glm::vec2 Rectangle::getSize()
    {
        return size;
    }

    int Rectangle::getVertexCount()
    {
        return count;
    }

    void Rectangle::setFillColor(glm::vec3 color)
    {
        fill.x = color.x;
        fill.y = color.y;
        fill.z = color.z;
    }

    void Rectangle::setPosition(float x,float y)
    {
        Move(x - position.x,y - position.y);
    }

    void Rectangle::Move(float x,float y)
    {
        position.x += x;
        position.y += y;
        model_view = glm::translate(model_view,glm::vec3(x,y,0.0f));
    }

    void Rectangle::Move(glm::vec3 dir)
    {
        position.x += dir.x;
        position.y += dir.y;
        model_view = glm::translate(model_view,dir);
    }

    void Rectangle::Rotate(float amount,glm::vec3 dir)
    {
        model_view = glm::rotate(model_view,glm::radians(amount),dir);
        Move(amount,-(amount));
    }

    void Rectangle::Scale(float x,float y)
    {
        model_view = glm::scale(model_view,glm::vec3(x,y,0.0f));
    }

    void Rectangle::Bind()
    {
        vbo->Bind();
        vao->Bind();
    }

    void Rectangle::Unbind()
    {
        vbo->Unbind();
        vao->Unbind();
    }

    

    bool Rectangle::CheckCollision(Rectangle&two)
    {
        bool collisionX = getPosition().x + getSize().x >= two.getPosition().x &&
            two.getPosition().x + two.getSize().x >= getPosition().x;
        bool collisionY = getPosition().y + getSize().y >= two.getPosition().y &&
            two.getPosition().y + two.getSize().y >= getPosition().y;
        return collisionX && collisionY;
    }

}