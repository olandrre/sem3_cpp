#include <iostream>

using namespace std;

int gcd(int a, int b);

class Rational final {
public:
    Rational(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {
        normalize();
    }
    Rational(const Rational& other) : m_numerator(other.m_numerator), m_denominator(other.m_denominator) {}

    Rational& operator=(const Rational& other) {
        m_numerator = other.m_numerator;
        m_denominator = other.m_denominator;
        return *this; //
    }

    Rational& operator+=(const Rational &rha) {
        m_numerator = m_numerator * rha.m_denominator + rha.m_numerator * m_denominator;
        m_denominator = m_denominator * rha.m_denominator;
        normalize();
        return *this;
    }

    Rational& operator-=(const Rational &rha) {
        m_numerator = m_numerator * rha.m_denominator - rha.m_numerator * m_denominator;
        m_denominator = m_denominator * rha.m_denominator;
        normalize();
        return *this;
    }

    Rational& operator*=(const Rational &rha) {
        m_numerator *= rha.m_numerator;
        m_denominator *= rha.m_denominator;
        normalize();
        return *this;
    }

    Rational& operator/=(const Rational &rha) {
        m_numerator *= rha.m_denominator;
        m_denominator *= rha.m_numerator;
        normalize();
        return *this;
    }

    Rational operator+() const {
        return *this;
    }

    Rational operator-() const {
        return Rational(-m_numerator, m_denominator);
    }

    explicit operator double() const {
        return static_cast<double>(m_numerator) / m_denominator;
    }

    double toDouble() const {
        return static_cast<double>(m_numerator) / m_denominator;
    }
private:
    friend bool operator<(const Rational &, const Rational &);

    int m_numerator;
    int m_denominator;

    void normalize() {
        if (m_denominator < 0) {
            m_numerator = - m_numerator;
            m_denominator = - m_denominator;
        }
        int g = gcd(m_numerator, m_denominator);
        m_denominator /= g;
        m_numerator /= g;
    }
};

int gcd(int a, int b) {
    if (a < 0) a = - a;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

bool operator<(const Rational &lha, const Rational &rha) {
    return lha.m_numerator * rha.m_denominator < rha.m_numerator * lha.m_denominator;
}

bool operator>(const Rational &lha, const Rational &rha) {
    return rha < lha;
}

bool operator<=(const Rational &lha, const Rational &rha) {
    return !(rha < lha);
}

bool operator>=(const Rational &lha, const Rational &rha) {
    return !(lha < rha);
}

bool operator==(const Rational &lha, const Rational &rha) {
    return !(lha < rha) and !(rha < lha);
}

bool operator!=(const Rational &lha, const Rational &rha) {
    return !(lha == rha);
}

Rational operator+(Rational lha, const Rational &rha) {
    lha += rha;
    return lha;
}

Rational operator-(Rational lha, const Rational &rha) {
    lha -= rha;
    return lha;
}

Rational operator*(Rational lha, const Rational &rha) {
    lha *= rha;
    return lha;
}

Rational operator/(Rational lha, const Rational &rha) {
    lha /= rha;
    return lha;
}

int main() {
    return 0;
}