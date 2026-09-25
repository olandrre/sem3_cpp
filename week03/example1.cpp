#include <iostream>

using namespace std;

class Base {
protected:
    int base_field = 0;

public:
    Base() {
        cout << "Base()" << endl;
    }
    void print_base() {
        cout << "My base field=" << base_field << endl;
    }

    ~Base() {
        cout << "~Base()" << endl;
    }
};

class Derived : public Base {
private:
    int dervied_field = 1;

public:
    Derived() {
        cout << "My derived field" << dervied_field << endl;
    }

    void print_derived() {
        cout << "My derived field=" << dervied_field << endl;
        cout << "My base field=" << base_field << endl;
    }

    ~Derived() {
    cout << "~Derived()" << endl;
    }
};

int main() {
    Base base_instance;
    Derived derived_instance;
    base_instance.print_base();
    derived_instance.print_base();
    derived_instance.print_derived();
    return 0;
}