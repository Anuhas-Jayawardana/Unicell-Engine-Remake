#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Graphics/Rectangle.h"
#include "Graphics/Sprite.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Unicell 
{
    class Window {
        public:
            Window(int width,int height,const char* title);

            bool isKeyDown(int keycode);
            bool isMouseButtonDown(int button);

            glm::vec2 getMousePosition();
            glm::vec2 getSize();

            void Draw(Rectangle& rect);
            void Draw(Sprite& sprite);

            void setProjection(glm::mat4 value);

            bool closed();
            void Clear();
            void Update();
            void Quit();

        private:
            int window_width,window_height;
            GLFWwindow* window;
            glm::mat4 projection;
    };
}