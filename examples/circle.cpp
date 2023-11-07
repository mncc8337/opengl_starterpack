// draw circles and regular polygons with random color

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <random>

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_real_distribution<float> dist(0.0, 1.0);

struct vec2f {
    float x;
    float y;
};

float rnd() {
    return dist(rng);
}

void draw_regular_polygon(vec2f center, float radius, float side) {
    glBegin(GL_POLYGON);
        for(float a = 0; a <= 2 * M_PI; a += 2 * M_PI / side) {
            glColor3f(rnd(), rnd(), rnd()); glVertex2f(cos(a) * radius + center.x,
                                                       sin(a) * radius + center.y);
        }
    glEnd();
}

const float circle_side_len = 0.07;
void draw_circle(vec2f center, float radius) {
    // calculate the number of side needed, each side length equal to circle_side_len
    float side = 2 * M_PI / acos(1 - circle_side_len * circle_side_len / (2 * radius * radius));
    draw_regular_polygon(center, radius, side);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    draw_circle({0, 0}, 0.2);
    draw_regular_polygon({-0.5, -0.5}, 0.1, 5);
    draw_regular_polygon({-0.5, 0.5}, 0.1, 4);
    draw_regular_polygon({0.5, 0.5}, 0.1, 3);
    draw_regular_polygon({0.5, -0.5}, 0.1, 6);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 800);
    glutCreateWindow("Circle");

    glutDisplayFunc(display);

    glutMainLoop();
}