#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Display/VertexArray.h"
#include "Display/VertexBuffer.h"
#include "Graphics/Shader.h"

#include <iostream>
#include <memory>

namespace Unicell
{
    class Rectangle {
    public:
        Rectangle(float x,float y,float width,float height);

        void Bind();
        void Unbind();
        std::shared_ptr<Shader> shader;

        void Move(glm::vec3 dir);

        void Move(float x,float y);
        void Rotate(float amount,glm::vec3 dir);
        void Scale(float x,float y);

        bool CheckCollision(Rectangle& two);

        void setPosition(float x,float y);
        void setFillColor(glm::vec3 color);

        int getVertexCount();

        glm::mat4 getModelView();
        glm::vec2 getPosition();
        glm::vec2 getSize();
        glm::vec4 getFillColor();
    private:
        int count;
        glm::mat4 model_view = glm::mat4(1.0f);
        std::shared_ptr<VertexArray> vao;
        std::shared_ptr<VertexBuffer> vbo;

        glm::vec2 position;
        glm::vec2 size;
        glm::vec4 fill = glm::vec4(1.0f,1.0f,1.0f,1.0f);
    };
}