// some rotating shapes

#include <GLFW/glfw3.h>
#include <shapes.hpp>
#include <iostream>

int main(void) {
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 800, "test", NULL, NULL);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        drawHeart(vec2f(0.3, 0.3), 0.07f, vec3f(1, 0, 0), -glfwGetTime());
        vec3f colors[] = {vec3f(1, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 1)};
        drawRegularPolygon(vec2f(0, 0), 0.3f, 3, colors, glfwGetTime(), 0);
        drawRegularPolygon(vec2f(0.3, -.03), 0.3f, 3, colors, glfwGetTime() * 6.0f, 1);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}