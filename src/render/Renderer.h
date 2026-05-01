// Renderer.h — declares the Renderer class interface.
// main.cpp only needs to know WHAT the renderer can do, not HOW it does it.
// The actual OpenGL implementation lives in Renderer.cpp.

#pragma once
#include <GL/glew.h>

class Renderer {
public:
    bool init();      // sets up shaders, VAO, VBO
    void draw();      // called every frame
    void cleanup();   // deletes GPU resources
};