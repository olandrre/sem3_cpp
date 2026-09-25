#include <iostream>

using namespace std;

class A {
public:
    int x1 = 0, x2 = 0;

public:
    A(int x1, int x2) : x1(x1), x2(x2) {
    }

    //get_x1(), get_x2();
    friend ostream& operator<<(ostream& os, const A& obj);
    friend A operator+(const A& lhv, const A& rhv);
};

ostream& operator<<(ostream& os, const A& obj) {
    os << "class A(x1=" << obj.x1 << ", x2=" << obj.x2 << ")";
    return os;
}

A operator+(const A& lhv, const A& rhv) {
    return A(lhv.x1 + rhv.x1, lhv.x2 + rhv.x2);
}

int main() {
    A my_first = {1, 2};
    cout << my_first << endl;
    cout << (my_first + my_first) << endl;
    return 0;
}