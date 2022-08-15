#include "Graphics/Shader.h"

namespace Unicell
{
    Shader::Shader(const char* vertex,const char* fragment)
    {
        ID = glCreateProgram();
        int vs = glCreateShader(GL_VERTEX_SHADER);
        int fs = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(vs,1,&vertex,nullptr);
        glCompileShader(vs);
        glShaderSource(fs,1,&fragment,nullptr);
        glCompileShader(fs);
        glAttachShader(ID,vs);
        glAttachShader(ID,fs);
        glLinkProgram(ID);
        glValidateProgram(ID);
        glDeleteShader(vs);
        glDeleteShader(fs);
    }

    int Shader::getUniformLocation(const char* name)
    {
        return glGetUniformLocation(ID,name);
    }

    void Shader::setVector4(const char* name,glm::vec4 value)
    {
        glUniform4f(getUniformLocation(name),value.x,value.y,value.z,value.w);
    }

    void Shader::setInt(const char* name,int value)
    {
        glUniform1i(getUniformLocation(name),value);
    }

    void Shader::setMatrix4(const char* name,glm::mat4 value)
    {
        glUniformMatrix4fv(getUniformLocation(name),1,GL_FALSE,glm::value_ptr(value));
    }

    Shader::~Shader()
    {
        disable();
        glDeleteProgram(ID);
    }

    void Shader::enable()
    {
        glUseProgram(ID);
    }

    void Shader::disable()
    {
        glUseProgram(0);
    }
}