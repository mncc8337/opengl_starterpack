// draw some graphs
// move using mouse / WASD
// zoom using mouse wheel / QE

#include <GLFW/glfw3.h>
#include "shapes.hpp"
#include <map>
#include <iostream>

vec2f origin;
vec2f mouse_position;
float speed = 0.01f;
float zoom = 0.07;

vec2f mouse_position_on_click;
bool mouse_holding = false;

std::map<int, bool> keyhold;
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(action == GLFW_PRESS)
        keyhold[key] = true;
    else if(action == GLFW_RELEASE)
        keyhold[key] = false;
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    ypos *= -1;
    
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    mouse_position.x = xpos / (float)width;
    mouse_position.y = ypos / (float)height;
    mouse_position *= 2.0f;
}
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if(button == GLFW_MOUSE_BUTTON_LEFT) {
        if(action == GLFW_PRESS) {
            mouse_position_on_click = mouse_position;
            mouse_holding = true;
        }
        if(action == GLFW_RELEASE) {
            vec2f mouse_dir = mouse_position - mouse_position_on_click;
            origin += mouse_dir;
            mouse_holding = false;
        }
    }
}
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    zoom += 0.02f * yoffset;
}

void processInput() {
    vec2f dir;
    dir.x = -(int)keyhold[GLFW_KEY_D] + (int)keyhold[GLFW_KEY_A];
    dir.y = -(int)keyhold[GLFW_KEY_W] + (int)keyhold[GLFW_KEY_S];
    // normalize so that moving diagonal does not incease speed
    if(dir.x != dir.y or dir.x != 0.0f)
        dir = normalize(dir);
    
    origin += dir * speed;

    zoom += 0.01f * ((int)keyhold[GLFW_KEY_E] - (int)keyhold[GLFW_KEY_Q]);
}

float sinFunc(float x) {
    return sin(x);
}
float movingSinFunc(float x) {
    return sin(x + glfwGetTime());
}
float tanFunc(float x) {
    return tan(x);
}
float logFunc(float x) {
    return log(x);
}
float quadraticFunc(float x) {
    return x * x;
}
float floorFunc(float x) {
    return int(x);
}
float linearFunc(float x) {
    return (x + 3) / 2;
}

int main(void) {
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 800, "graphs", NULL, NULL);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetScrollCallback(window, scrollCallback);

    vec2f v(1, 1);

    while (!glfwWindowShouldClose(window)) {
        processInput();

        glClear(GL_COLOR_BUFFER_BIT);

        vec2f mouse_dir = mouse_position - mouse_position_on_click;
        if(mouse_holding)
            origin += mouse_dir;

        // the axes
        glBegin(GL_LINES);
            glColor3f(1, 0, 0);

            glVertex2f(origin.x,  1.0f);
            glVertex2f(origin.x, -1.0f);
            
            glVertex2f( 1.0f, origin.y);
            glVertex2f(-1.0f, origin.y);
        glEnd();

        // the graphs
        drawGraph(origin, sinFunc, zoom);
        drawGraph(origin, movingSinFunc, zoom, vec3f(0.5, 0.5, 0.5));
        drawGraph(origin, tanFunc, zoom, vec3f(0.5, 0.5, 1));
        drawGraph(origin, logFunc, zoom, vec3f(1, 1, 0));
        drawGraph(origin, quadraticFunc, zoom, vec3f(0, 1, 1));
        drawGraph(origin, floorFunc, zoom, vec3f(0.5, 1, 0.5));
        drawGraph(origin, linearFunc, zoom, vec3f(0.5, 1, 0.5));
    
        if(mouse_holding)
            origin -= mouse_dir;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}