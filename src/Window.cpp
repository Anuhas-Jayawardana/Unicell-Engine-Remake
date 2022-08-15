#include "Display/Window.h"

namespace Unicell {

    void resize_callback(GLFWwindow* window,int w,int h)
    {
        Window* win = (Window*)glfwGetWindowUserPointer(window);
        win->setProjection(glm::ortho(0.0f,(float)w,(float)h,0.0f,-1.0f,1.0f));
    }

    Window::Window(int width,int height,const char* title)
    {
        glfwInit();
        
        projection = glm::ortho(0.0f,(float)width,(float)height,0.0f,-1.0f,1.0f);
        camera = std::make_shared<Camera>();

        window = glfwCreateWindow(width,height,title,0,0);

        glfwMakeContextCurrent(window);
        glfwSetWindowSizeCallback(window,resize_callback);
        glfwSetWindowUserPointer(window,this);
        glfwSwapInterval(1);
        glewInit();
    }

    bool Window::isKeyDown(int keycode)
    {
        return glfwGetKey(window,keycode) != GLFW_RELEASE;
    }

    bool Window::isMouseButtonDown(int button)
    {
        return glfwGetMouseButton(window,button) != GLFW_RELEASE;
    }

    glm::vec2 Window::getMousePosition()
    {
        double x,y;
        glfwGetCursorPos(window,&x,&y);
        return glm::vec2(x,y);
    }

    glm::vec2 Window::getSize()
    {
        return glm::vec2(window_width,window_height);
    }

    bool Window::closed()
    {
        return glfwWindowShouldClose(window);
    }

    void Window::setProjection(glm::mat4 value)
    {
        projection = value;
    }

    void Window::Clear(){
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::Draw(SpriteGroup& group)
    {
        for (int i = 0; i < group.sprites.size(); i++)
        {
            Draw(group.sprites.at(i));
        }
        
    }

    void Window::Draw(Sprite& sprite)
    {
        sprite.Bind();
        sprite.shader->enable();
        if(sprite.hasTexture)
            sprite.texture->Bind();
        sprite.shader->setMatrix4("u_projection",projection);
        sprite.shader->setMatrix4("u_model",sprite.getModelView());
        sprite.shader->setMatrix4("u_view",camera->getViewMatrix());
        glDrawArrays(GL_TRIANGLES,0,sprite.getVertexCount());
        if(sprite.hasTexture)
            sprite.texture->Unbind();
        sprite.Unbind();
    }
        

    void Window::Draw(Rectangle& rect)
    {
        rect.Bind();
        rect.shader->enable();
        rect.shader->setMatrix4("u_projection",projection);
        rect.shader->setMatrix4("u_model",rect.getModelView());
        rect.shader->setMatrix4("u_view",camera->getViewMatrix());
        rect.shader->setVector4("fill",rect.getFillColor());
        glDrawArrays(GL_TRIANGLES,0,rect.getVertexCount());
        rect.Unbind();
    }
    
    void Window::Update(){
        glfwPollEvents();
        glViewport(0,0,window_width,window_height);
        glfwSwapBuffers(window);
    }
    
    void Window::Quit(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}