#include <cmath>
#include "my_math.hpp"

const double pi = M_PI;
const double pi_2 = 2 * M_PI;

AnswerHandler my_sin(double x) {
    AnswerHandler sin;
    sin.x = x;
    x = fmod(x, pi_2);
    if (x > pi) x -= pi_2;
    if (x < -pi) x += pi_2;

    double term = x;
    double sum = x;

    for (int idx = 1; idx < 13; ++idx) {
        int den = 2 * idx * (2 * idx + 1);
        term = - term * x * x / den;
        sum += term;
    }

    sin.val = sum;

    return sin;
}
    
AnswerHandler my_cos(double x) {
    AnswerHandler cos;
    cos.x = x;
    x = fmod(x, pi_2);
    if (x > pi) x -= pi_2;
    if (x < -pi) x += pi_2;

    double term = 1.0;
    double sum = 1.0;

    for (int idx = 1; idx < 13; ++idx) {
        int den = 2 * idx * (2 * idx - 1);
        term = - term * x * x / den;
        sum += term;
    }

    cos.val = sum;

    return cos;
}

AnswerHandler my_tan(double x) {
    AnswerHandler tan;
    tan.x = x;
    if (my_cos(x).val == 0) {
        tan.val = NAN;
        return tan;
    }
    tan.val = my_sin(x).val/my_cos(x).val;
    return tan;
}

AnswerHandler my_cot(double x) {
    AnswerHandler cot;
    cot.x = x;
    if (my_sin(x).val == 0) {
        cot.val = NAN;
        return cot;
    }
    cot.val = my_cos(x).val/my_sin(x).val;
    return cot;
}

