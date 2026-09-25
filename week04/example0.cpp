#include <iostream>

class Base {
protected:
    double base = 0;
};

class Left : virtual public Base {
protected:
    double left = 1;
};

class Right : virtual public Base {
protected:
    double right = 2;
};

class Derived : public Left, public Right {
private:
    double derived = 4;

public:
    void print() const {
        std::cout << "derived=" << derived << std::endl;
        std::cout << "left=" << left << std::endl;
        std::cout << "right=" << right << std::endl;
        std::cout << "Left::Base=" << (this->Left::base) << std::endl;
        std::cout << "Right::Base=" << (this->Right::base) << std::endl;
    }
};

int main() {
    std::cout << sizeof(Base) << std::endl;
    std::cout << sizeof(Left) << std::endl;
    std::cout << sizeof(Right) << std::endl;
    std::cout << sizeof(Derived) << std::endl;

    Derived d = {};
    d.print();
    return 0;
}