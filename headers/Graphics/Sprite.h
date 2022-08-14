#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Display/VertexArray.h"
#include "Display/VertexBuffer.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"

#include <iostream>
#include <memory>

namespace Unicell
{
    class Sprite {
    public:
        Sprite(float x,float y,float width,float height);

        void Bind();
        void Unbind();

        bool CheckCollision(Sprite& two);

        std::shared_ptr<Shader> shader;
        std::shared_ptr<Texture> texture;
        bool hasTexture = false; // just to avoid the program from crashing when it tries to bind an empty texture :)

        void Move(float x,float y);
        void Rotate(float amount,glm::vec3 dir);
        void Scale(float x,float y);

        void setPosition(float x,float y);
        void setTexture(const char* path);

        int getVertexCount();

        glm::mat4 getModelView();
        glm::vec2 getPosition();
        glm::vec2 getSize();
    private:
        int count;
        glm::mat4 model_view = glm::mat4(1.0f);
        std::shared_ptr<VertexArray> vao;
        std::shared_ptr<VertexBuffer> vbo;

        glm::vec2 position;
        glm::vec2 size;
    };
}