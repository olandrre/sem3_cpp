#include "vec3.hpp"
#include <cmath>

Vec3::Vec3(double x, double y, double z) : e{x, y, z}, veeee{z} {}

Vec3::Vec3() : Vec3(0, 0, 0) {}

double Vec3::operator[](int i) const {
    return e[i];
}

double& Vec3::operator[](int i) {
    return e[i];
}

Vec3& Vec3::operator+=(const Vec3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

Vec3& Vec3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vec3& Vec3::operator/=(double t) {
    return *this *= 1.0 / t;
}

double Vec3::length() const {
    return std::sqrt(length_squared());
}

double Vec3::length_squared() const {
    return e[0] * e[0] + e[1] * e[1] +e[2] * e[2];
}