#include <iostream>
using namespace std;

class abc {
public:
    int x, y;
    static int count;  // Static member variable

    abc(int a, int b) {
        x = a;
        y = b;
        count++; // Count how many objects are created
    }

    void print() const {
        cout << "x = " << this->x << ", y = " << this->y << endl;
    }

    static void showCount() {
        // Can't access non-static members like x, y here
        cout << "Total objects created: " << count << endl;
    }
};

// Static member must be defined outside the class
int abc::count = 0;

int main() {
    abc obj1(1, 2);
    abc obj2(4, 5);

    obj1.print();
    obj2.print();

    // Call static function using class name (preferred)
    abc::showCount();

    return 0;
}
