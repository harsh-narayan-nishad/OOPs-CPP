// #include <bits/stdc++.h>
// using namespace std;

// class MyClass {
// public:
//     MyClass() {
//         cout << "Constructor called!" << endl;
//     }

//     // Destructor
//     ~MyClass() {
//         cout << "Destructor called!";
//     }
// };

// int main() {
//     MyClass obj;
//     // Destructor will be called 
//     // automatically when obj goes out of scope
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

class MyClass {
private:
    static int count; // Static counter for all objects
    int id;           // Unique ID for each object

public:
    MyClass() {
        id = ++count;
        cout << "Constructor called for object " << id << "!" << endl;
    }

    ~MyClass() {
        cout << "Destructor called for object " << id << "!" << endl;
    }
};

// Define and initialize the static member
int MyClass::count = 0;

int main() {
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;

    return 0;
}
