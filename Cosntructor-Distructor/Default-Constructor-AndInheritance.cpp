#include <iostream>
using namespace std;

class Base {
public:
    // Compiler "declares" constructor
};

class A {
public:
    // User defined constructor
    A() { cout << "A Constructor" << endl; }

    // Uninitialized
    int size;
};

class B : public A {
    // Compiler defines default constructor of B,
    // and inserts stub to call A constructor
    // Compiler won't initialize any data of A
};

class C : public A {
public:
    C()
    {
        // User defined default constructor of C
        // Compiler inserts stub to call A's constructor
        cout << "C Constructor" << endl;

        // Compiler won't initialize any data of A
    }
};

class D {
    A a;
public:
    D()
    {
        // User defined default constructor of D
        // a - constructor to be called, compiler inserts
        // stub to call A constructor
        cout << "D Constructor" << endl;

        // Compiler won't initialize any data of 'a'
    }
};

// Driver Code
int main()
{
    Base base; // Only Base constructor (default provided by the compiler) is called
    B b; // Calls A's constructor due to inheritance (compiler-generated constructor for B)
    C c; // Calls A's constructor first, then C's constructor
    D d; // Calls A's constructor for member 'a', then D's constructor

    return 0;
}