#pragma once
#include <math.h>

template <typename T>
class vec3 {
public:
    T x;
    T y;
    T z;

    vec3() {
        x = 0;
        y = 0;
        z = 0;
    }
    vec3(T X, T Y, T Z) {
        x = X;
        y = Y;
        z = Z;
    }

    template <typename U>
    explicit vec3(const vec3<U>& vector);

    vec3<T> operator=(vec3<int> v) {
        x = T(v.x);
        y = T(v.y);
        z = T(v.z);
    }
};

// arithmetic fucntions
template <typename T>
vec3<T> operator+(const vec3<T> a, const vec3<T> b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}
template <typename T>
vec3<T> operator*(T v, const vec3<T> a) {
    return {a.x * v, a.y * v, a.z * v};
}
template <typename T>
vec3<T> operator*(const vec3<T> a, T v) {
    return {a.x * v, a.y * v, a.z * v};
}
template <typename T>
vec3<T> operator-(vec3<T> a) {
    return a * T(-1);
}
template <typename T>
vec3<T> operator-(const vec3<T> a, const vec3<T> b) {
    return a + (-b);
}
template <typename T>
vec3<T> operator/(const vec3<T> a, T v) {
    return (T(1) / v) * a;
}
template <typename T>
vec3<T>& operator+=(vec3<T>& a, const vec3<T> b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
};
template <typename T>
vec3<T>& operator-=(vec3<T>& a, const vec3<T> b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
};
template <typename T>
vec3<T>& operator*=(vec3<T>& a, const T v) {
    a.x *= v;
    a.y *= v;
    a.z *= v;
    return a;
};
template <typename T>
vec3<T>& operator/=(vec3<T>& a, const T v) {
    a.x /= v;
    a.y /= v;
    a.z /= v;
    return a;
};

// vector functions
template <typename T>
T dot(vec3<T> a, vec3<T> b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
template <typename T>
float length(vec3<T> a) {
    return sqrt(dot(a, a));
}
template <typename T>
vec3<T> normalize(vec3<T> a) {
    return a / length(a);
}
template <typename T>
vec3<T> lerp(vec3<T> start, vec3<T> end, float t) {
    return start * (1.0f - t) + end * t;
}

typedef vec3<int> vec3i;
typedef vec3<float> vec3f;

vec3f vec3i2f(vec3i v) {
    return vec3f(v.x, v.y, v.z);
}