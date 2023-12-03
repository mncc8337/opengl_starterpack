#include "vec2.hpp"

// rotate vector v by theta radian around origin
void setRotationAround(vec2f* v, float theta, vec2f origin) {
    vec2f dir = *v - origin;
    vec2f normal_dir = normalize(dir);
    float current_angle = acos(normal_dir.x) * (normal_dir.y < 0 ? -1 : 1);
    float len = length(dir);
    *v = vec2f(cos(current_angle + theta), sin(current_angle + theta)) * len + origin;
}