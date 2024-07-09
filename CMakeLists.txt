cmake_minimum_required(VERSION 3.20)

project(OpenGL-Thing)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_executable(thing glad/src/glad.c src/main.c src/file.c src/shader.c src/shape.c src/window.c src/vector.c src/matrix.c)
target_include_directories(thing PUBLIC glad/include)
target_link_libraries(thing m SDL2)
