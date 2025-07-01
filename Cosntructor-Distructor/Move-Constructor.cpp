// Syntax

// className (className&& obj) {
//      // body of the constructor
// }

#include <iostream>
#include <vector>
using namespace std; 

class MyClass {
private:
    int b;

public:
    // Constructor
    MyClass(int &&a) : b(std::move(a)) {
        cout << "Move constructor called!" << endl;
    }

    void display() {
            cout << b <<endl;
    }
};

int main() {
    int a = 4;
    MyClass obj1(std::move(a));  // Move constructor is called

    obj1.display();
    return 0;
}