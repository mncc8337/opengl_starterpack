// a movable rotating triangle with smooth movement
// move it with WASD

#include <GLFW/glfw3.h>
#include <shapes.hpp>
#include <map>

std::map<int, bool> keyhold;
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(action == GLFW_PRESS)
        keyhold[key] = true;
    else if(action == GLFW_RELEASE)
        keyhold[key] = false;
}

vec2f pos;
vec2f target;
float speed = 0.01f;
void processInput() {
    vec2f dir;
    dir.x = (int)keyhold[GLFW_KEY_D] - (int)keyhold[GLFW_KEY_A];
    dir.y = (int)keyhold[GLFW_KEY_W] - (int)keyhold[GLFW_KEY_S];
    if(dir.x != dir.y or dir.x != 0.0f)
        dir = normalize(dir);
    
    target += dir * speed;
    pos = lerp(pos, target, 0.1);
}

int main(void) {
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 800, "triangle", NULL, NULL);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);

    vec2f v(1, 1);

    while (!glfwWindowShouldClose(window)) {
        processInput();

        glClear(GL_COLOR_BUFFER_BIT);

        // drawHeart(vec2f(0.3, 0.3), 1.0f, vec3f(1, 0, 0), glfwGetTime());
        vec3f colors[] = {vec3f(1, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 1)};
        drawRegularPolygon(pos, 0.3f, 3, colors, glfwGetTime(), 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}