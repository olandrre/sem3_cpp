#pragma once
#include <iostream>

class Vec3;

class IVec {
public:
    virtual ~IVec() = default;

    virtual double operator[](int i) const = 0;
    virtual double& operator[](int i) = 0;

    virtual Vec3& operator+=(const Vec3& v) = 0;
    virtual Vec3& operator*=(double t) = 0;
    virtual Vec3& operator/=(double t) = 0;

    double virtual length() const = 0;
    double virtual length_squared() const = 0;
};