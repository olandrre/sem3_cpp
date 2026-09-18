#include <iostream>
#include <cmath>
#include <iomanip>
#include "my_math.hpp"

int main() {
    double x = 10;

    std::cout << std::scientific;

    std::cout << "x = " << x << std::endl;
    std::cout << "func, val, my_val, delta" << std::endl;
    std::cout << "sin, " << my_sin(x).val << ", " << sin(x) << ", " << my_sin(x).val - sin(x) << std::endl;
    std::cout << "cos, " << my_cos(x).val << ", " << cos(x) << ", " << my_cos(x).val - cos(x) << std::endl;
    std::cout << "tan, " << my_tan(x).val << ", " << tan(x) << ", " << my_tan(x).val - tan(x) << std::endl;
    std::cout << "cot, " << my_cot(x).val << ", " << 1/tan(x) << ", " << my_cot(x).val - 1/tan(x) << std::endl;
    return 0;
}