#include "Display/Camera.h"

namespace Unicell {
    Camera::Camera()
    {
        view_matrix = glm::mat4(1.0f);
    }

    void Camera::Move(float x,float y)
    {
        view_matrix = glm::translate(view_matrix,glm::vec3(-x,y,0.0f));
    }

    glm::mat4 Camera::getViewMatrix()
    {
        return view_matrix;
    }
}