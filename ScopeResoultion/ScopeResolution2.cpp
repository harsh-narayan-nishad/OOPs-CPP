#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    void setDetails(string n, int a); // Function declaration
    void display();
};

// Function Definition using Scope Resolution Operator
void Student::setDetails(string n, int a) {
    name = n;
    age = a;
}

void Student::display() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}


int main() {
    Student s1;

    s1.setDetails("Krishna", 20);
    s1.display();

    return 0;
}
