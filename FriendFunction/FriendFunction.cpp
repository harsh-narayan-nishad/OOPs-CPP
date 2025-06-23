#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box() : length(0) {}

    // Declare friend function
    friend void setLength(Box &b, int len);
    
    void display() {
        cout << "Length: " << length << endl;
    }
};

// Definition of friend function
void setLength(Box &b, int len) {
    // Accessing private member of Box
    b.length = len;
}

int main() {
    Box myBox;
    myBox.display();        // Length: 0

    setLength(myBox, 10);   // Friend function sets private member
    myBox.display();        // Length: 10

    return 0;
}
