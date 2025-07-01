#include <iostream>
using namespace std;

class Animal {
public:
    string species;
    int age;
    int name;
    
    // Member functions
    void eat() {
        // eat something
        cout<<"Eat function is called"<<endl;
    }
    void sleep() {
        // sleep for few hrs
        cout<<"sleep function is called"<<endl;

    }
    void makeSound () {
        // make sound;
        cout<<"makeSound function is called"<<endl;

    }
};

int main() {
    Animal VoidShadowDarkFangReaper;
    VoidShadowDarkFangReaper.makeSound();
    return 0;
}