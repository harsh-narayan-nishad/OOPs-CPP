#include <iostream>
using namespace std;

class GfG {
public:
    static void printHello(); 
};

// Definintion of static member function
void GfG::printHello() {
    cout << "Hello World";
}
int main() {
    
    // Access without creating object
    GfG::printHello();
    
    return 0;
}