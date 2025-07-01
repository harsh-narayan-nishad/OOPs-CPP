#include <iostream>
using namespace std;

class GfG {
public:
    static int val;
};

// Initialize static member
int GfG::val = 22;
int main() {
    
    // Access without creating object
    cout << GfG::val << endl;
}