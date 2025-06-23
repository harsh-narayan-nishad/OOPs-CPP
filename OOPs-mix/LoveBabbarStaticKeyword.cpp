#include <iostream>
using namespace std;

class abc {
public:
    static int x, y;  // Static variables shared among all instances

    void print() const {
        // this->x and this->y are allowed but unnecessary for static members
        cout << x << " " << y << endl;
    }
};

// Static variables must be defined outside the class
int abc::x = 0;
int abc::y = 0;

int main() {
    abc obj1;
    obj1.x = 1;
    obj1.y = 2;

    obj1.print();  // prints: 1 2

    abc obj2;
    obj1.print();  // prints: 1 2
    obj2.print();  // prints: 1 2 (same values, shared static)

    return 0;
}
