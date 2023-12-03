#pragma once
#include <math.h>

template <typename T>
class vec2 {
public:
    T x;
    T y;

    vec2() {
        x = 0;
        y = 0;
    }
    vec2(T X, T Y) {
        x = X;
        y = Y;
    }

    template <typename U>
    explicit vec2(const vec2<U>& vector);

    vec2<T> operator=(vec2<int> v) {
        x = T(v.x);
        y = T(v.y);
    }
};

// arithmetic fucntions
template <typename T>
vec2<T> operator+(const vec2<T> a, const vec2<T> b) {
    return {a.x + b.x, a.y + b.y};
}
template <typename T>
vec2<T> operator*(T v, const vec2<T> a) {
    return {a.x * v, a.y * v};
}
template <typename T>
vec2<T> operator*(const vec2<T> a, T v) {
    return {a.x * v, a.y * v};
}
template <typename T>
vec2<T> operator-(vec2<T> a) {
    return a * T(-1);
}
template <typename T>
vec2<T> operator-(const vec2<T> a, const vec2<T> b) {
    return a + (-b);
}
template <typename T>
vec2<T> operator/(const vec2<T> a, T v) {
    return (T(1) / v) * a;
}
template <typename T>
vec2<T>& operator+=(vec2<T>& a, const vec2<T> b) {
    a.x += b.x;
    a.y += b.y;
    return a;
};
template <typename T>
vec2<T>& operator-=(vec2<T>& a, const vec2<T> b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
};
template <typename T>
vec2<T>& operator*=(vec2<T>& a, const T v) {
    a.x *= v;
    a.y *= v;
    return a;
};
template <typename T>
vec2<T>& operator/=(vec2<T>& a, const T v) {
    a.x /= v;
    a.y /= v;
    return a;
};

// vector functions
template <typename T>
T dot(vec2<T> a, vec2<T> b) {
    return a.x * b.x + a.y * b.y;
}
template <typename T>
float length(vec2<T> a) {
    return sqrt(dot(a, a));
}
template <typename T>
vec2<T> normalize(vec2<T> a) {
    return a / length(a);
}
template <typename T>
vec2<T> lerp(vec2<T> start, vec2<T> end, float t) {
    return start * (1.0f - t) + end * t;
}

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;

vec2f vec2i2f(vec2i v) {
    return vec2f(v.x, v.y);
}