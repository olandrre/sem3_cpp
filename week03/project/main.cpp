#include <iostream>
#include "vec3.hpp"

int main() {
    Vec3 a(10.0, 12.0, 9.0);
    Vec3 b(7.0, 5.0, 8.0);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    a += b;
    std::cout << "a += b: " << a << std::endl;

    a *= 4;
    std::cout << "a *= 4: " << a << std::endl;

    a /= 2;
    std::cout << "a /= 2: " << a << std::endl;

    std::cout << "length of a: " << a.length() << std::endl;
    std::cout << "length squared of a: " << a.length_squared() << std::endl;

    IVec* ptr = &a;
    std::cout << "ivec: " << ptr->length() << std::endl;
    
    return 0;
}