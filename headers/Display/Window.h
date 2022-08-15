#pragma once

#include <iostream>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Graphics/SpriteGroup.h"
#include "Graphics/Rectangle.h"
#include "Graphics/Sprite.h"
#include "Display/Camera.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Unicell 
{
    class Window {
        public:
            Window(int width,int height,const char* title);

            bool isKeyDown(int keycode);
            bool isMouseButtonDown(int button);

            std::shared_ptr<Camera> camera;

            glm::vec2 getMousePosition();
            glm::vec2 getSize();

            void Draw(Rectangle& rect);
            void Draw(Sprite& sprite);
            void Draw(SpriteGroup& group);

            void setProjection(glm::mat4 value);

            bool closed();
            void Clear();
            void Update();
            void Quit();

            glm::vec3 world_up = glm::vec3(0.0f,0.0f,1.0f);
            glm::vec3 world_down = glm::vec3(0.0f,0.0f,-1.0f);
            glm::vec3 world_right = glm::vec3(1.0f,0.0f,0.0f);
            glm::vec3 world_left = glm::vec3(-1.0f,0.0f,0.0f);

        private:
            int window_width,window_height;
            GLFWwindow* window;
            glm::mat4 projection;

    };
}