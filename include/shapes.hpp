#pragma once

#include <GL/gl.h>
#include "vec2.hpp"
#include "vec3.hpp"
#include "transformations.hpp"
#include <math.h>

// draw heart the ineffeciency way
void drawHeart(vec2f position, float size, vec3f color, float rotation) {
    glBegin(GL_POINTS);
        glColor3f(color.x, color.y, color.z);
        float x, y, r = size;
        for(float t = 0; t <= 250; t += 0.05f) {
            x = -r*(16 * sin(t) * sin(t) * sin(t));
            y = -r*(13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t));
            x /= 16.5f;
            y /= -16.5f;
            vec2f v(x, y); v += position;
            setRotationAround(&v, rotation, position);
            glVertex2f(v.x, v.y);
        }
    glEnd();
}

void drawRegularPolygon(vec2f center, float radius,
                        int side, vec3f* colors, float rotation,
                        bool fill) {
    glBegin(fill ? GL_POLYGON : GL_LINES);
        for(int t = 0; t < side; t++) {
            float a = t * 2 * M_PI / side + rotation;

            glColor3f((colors + t)->x, (colors + t)->y, (colors + t)->z);
            glVertex2f(cos(a) * radius + center.x,
                       sin(a) * radius + center.y);
            
            if(!fill) {
                int T = t + 1;
                if(T == side) T = 0;
                a = T * 2 * M_PI / side + rotation;

                glColor3f((colors + t)->x, (colors + t)->y, (colors + t)->z);
                glVertex2f(cos(a) * radius + center.x,
                           sin(a) * radius + center.y);
            }
        }
    glEnd();
}

float CIRCLE_SIDE_LENGTH = 0.05f;
void drawCircle(vec2f center, float radius, vec3f color, float rotation, bool fill) {
    // calculate the number of side needed, each side length equal to CIRCLE_SIDE_LENGTH
    int side = 2 * M_PI / acos(1 - CIRCLE_SIDE_LENGTH * CIRCLE_SIDE_LENGTH / (2 * radius * radius));
    vec3f colors[side];
    for(int i = 0; i < side; i++) colors[i] = color;
    drawRegularPolygon(center, radius, side, colors, rotation, fill);
}

// draw a graph from a given function
void drawGraph(vec2f origin, float (*function)(float), float zoom = 1.0f, vec3f color = vec3f(0, 1, 0)) {
    const float step = 0.00005f;
    
    glBegin(GL_LINES);
        glColor3f(color.x, color.y, color.z);

        for(float x = -1/zoom; x <= 1/zoom; x += step/zoom) {
            float y = function(x - origin.x / zoom) + origin.y / zoom;
            vec2f p1(x * zoom, y * zoom);

            float x2 = x + step/zoom;
            float y2 = function(x2 - origin.x / zoom) + origin.y / zoom;
            vec2f p2(x2 * zoom, y2 * zoom);
            if(length(p1 - p2)/zoom < 0.5f) {
                glVertex2f(p1.x, p1.y);
                glVertex2f(p2.x, p2.y);
            }
        }
    glEnd();
}