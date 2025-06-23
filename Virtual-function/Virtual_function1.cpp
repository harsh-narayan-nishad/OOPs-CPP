#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void speak() {  // virtual means this function can be overridden
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class: Dog
class Dog : public Animal {
public:
    void speak() override {  // override tells compiler we are overriding speak()
        cout << "Dog barks" << endl;
    }
};

// Derived class: Cat
class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();  // base class pointer to Dog
    Animal* a2 = new Cat();  // base class pointer to Cat

    a1->speak(); // Output: Dog barks
    a2->speak(); // Output: Cat meows

    delete a1;
    delete a2;

    return 0;
}
