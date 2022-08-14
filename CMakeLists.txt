cmake_minimum_required(VERSION 3.10)

project(Unicell)

set(
    SOURCE 
    src/main.cpp
    src/Window.cpp
    src/Shader.cpp
    src/VertexArray.cpp
    src/VertexBuffer.cpp
    src/Rectangle.cpp
    src/Texture.cpp
    src/Sprite.cpp
    src/stb_image.cpp
    src/miniaudio.cpp
    src/AudioManager.cpp
)

link_directories(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/headers)
target_link_libraries(${PROJECT_NAME} opengl32 glfw3 glew32 gdi32)