#include <iostream>

using namespace std;


struct NodeS {
public: //by default
    int key = 0;
};

class NodeC {
private: //by default
    int key = 0;
    const int value = 1;

public:
    // // Bad practice
    // NodeC(int key, int value) { // Constructor of the class;
    //     this->key = key;
    //     this->value = value;
    // };  

    NodeC(int key, int value) : key(key), value(value) { // Initialization list
    };  

    explicit NodeC(int key) : NodeC(key, 1) { 
    };  

    NodeC() = default;

    void change_key(int new_key) {
        key = new_key;
    }

    void change_key_alt(int key) {
        this->key = key;
    }

    int get_key() const {
        // ++key; // Forbidden by 'const' modifier of method
        return key;
    }

    NodeC operator+(NodeC& other) const {
        return NodeC(other.key + key, other.value + value);
    }

    // pre++
    NodeC& operator++() {
        ++(this->key);
        return *this;
    }

    // post++
    NodeC operator++(int) {
        NodeC copy = NodeC(*this);
        ++(this->key);
        return copy;
    }
};

int main() {
    NodeS s = {};
    NodeC c = {123, -2};
    NodeC c0 = {};
    NodeC c1 = NodeC{12}; 
    s.key = 0;
    // c.key = 0; // It is a private member of class

    c.change_key(-1);
    c.change_key_alt(2);

    cout << s.key << endl;
    cout << c.get_key() << endl;
    cout << (c1 + c0).get_key() << endl;
    // Same as previous
    cout << (c1.operator+(c0)).get_key() << endl;
    // cout << (c1 + 54).get_key() << endl; // Without '& in operator' or 'explicit'
    // // Bad practice
    // cout << (c1 + NodeC{54}).get_key() << endl;
    cout << (++c1).get_key() << endl;

    return 0;
}