#include <iostream>

using namespace std;

class ExplicitInt {
    int key;

public:
    explicit ExplicitInt(int key) : key(key) {
    };

    int value() const {
        return key;
    }
};

int main() {
    ExplicitInt a = ExplicitInt(5);
    cout << a.value() << endl;
    return 0;
}