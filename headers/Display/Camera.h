#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Unicell {
    class Camera {
    public:
        Camera();

        void Move(float x,float y);

        glm::mat4 getViewMatrix();
    private:
        glm::mat4 view_matrix;
    };
}