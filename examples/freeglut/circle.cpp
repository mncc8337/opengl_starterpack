// draw circles and regular polygons with random color

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <random>
#include <map>

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_real_distribution<float> dist(0.0, 1.0);

std::map<unsigned char, bool> key_hold;

struct vec2f {
    float x;
    float y;
};

vec2f operator+(vec2f a, vec2f b) {
    return {a.x + b.x, a.y + b.y};
}
vec2f operator*(float x, vec2f a) {
    return {a.x * x, a.y * x};
}
vec2f operator*(vec2f a, float x) {
    return {a.x * x, a.y * x};
}
vec2f operator-(vec2f a, vec2f b) {
    return a + (-1 * b);
}
vec2f operator/(vec2f a, float x) {
    return (1 / x) * a;
}

float dot(vec2f a, vec2f b) {
    return a.x * b.x + a.y * b.y;
}
float length(vec2f a) {
    return sqrt(dot(a, a));
}
vec2f normalize(vec2f a) {
    return a / length(a);
}
vec2f lerp(vec2f start, vec2f end, float t) {
    return start * (1 - t) + end * t;
}

float rnd() {
    return dist(rng);
}

void draw_regular_polygon(vec2f center, float radius, float side) {
    glBegin(GL_POLYGON);
        for(int t = 0; t < side; t++) {
            float a = t * 2 * M_PI / side;
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

vec2f circle_pos = {0.0, 0.0};
vec2f target_pos = {0, 0};
float circle_speed = 0.003;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    vec2f dir = {0, 0};
    dir.x = -int(key_hold['a']) + int(key_hold['d']);
    dir.y = -int(key_hold['s']) + int(key_hold['w']);

    if(dir.x != dir.y or dir.x != 0.0)
        dir = normalize(dir);
    target_pos = target_pos + dir * circle_speed;
    circle_pos = lerp(circle_pos, target_pos, 0.007);

    draw_circle(circle_pos, 0.2);
    // draw_regular_polygon({-0.5, -0.5}, 0.1, 5);
    // draw_regular_polygon({-0.5, 0.5}, 0.1, 4);
    // draw_regular_polygon({0.5, 0.5}, 0.1, 3);
    // draw_regular_polygon({0.5, -0.5}, 0.1, 6);

    glFlush();
    glutSwapBuffers();
}

void timer(int s) {
    glutPostRedisplay();
    glutTimerFunc(1, timer, 0);
}

void keyboard_down(unsigned char key, int x, int y) {
    key_hold[key] = true;
}

void keyboard_up(unsigned char key, int x, int y) {
    key_hold[key] = false;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 800);
    glutCreateWindow("Circle");

    glutDisplayFunc(display);
    glutTimerFunc(1, timer, 0);

    glutKeyboardFunc(keyboard_down);
    glutKeyboardUpFunc(keyboard_up);
    glutIgnoreKeyRepeat(GL_TRUE);

    glutMainLoop();
}