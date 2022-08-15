#pragma once

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Unicell
{
    class Shader {
    public:
        Shader(const char* vertex,const char* fragment);
        ~Shader();

        int getUniformLocation(const char* name);

        void setMatrix4(const char* name,glm::mat4 value);
        void setInt(const char* name,int value);
        
        void setVector4(const char* name,glm::vec4 value);

        void enable();
        void disable();
    private:
        GLuint ID;
    };
}