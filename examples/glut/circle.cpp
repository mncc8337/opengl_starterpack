// draw a movable circle with smooth movement
// move it with WASD

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <shapes.hpp>

#include <math.h>
#include <map>

std::map<unsigned char, bool> key_hold;

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

    drawCircle(circle_pos, 0.2, vec3f(1, 0, 0), 0, 0);

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