#pragma once
#include <iostream>
#include "ivec.hpp"

class Vec3 : public IVec {
private:
    double e[3];

public: 
    Vec3(double x, double y, double z);
    Vec3();

    double operator[](int i) const override;
    double& operator[](int i) override;

    Vec3& operator+=(const Vec3& v) override;
    Vec3& operator*=(double t) override;
    Vec3& operator/=(double t) override;

    double length() const override;
    double length_squared() const override;
};

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
    out << v[0] << ' ' << v[1] << ' ' << v[2];
    return out;
}