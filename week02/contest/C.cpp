#include <iostream>

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const std::string& msg) : msg(msg) { }
private:
    const std::string& msg;
};

struct Foo2 : Foo {
    Foo2(const std::string& msg) : Foo(msg) { }
};

Foo2 get_foo(std::string msg) {
    return Foo2(msg);
}

int main() {
    
    return 0;
}