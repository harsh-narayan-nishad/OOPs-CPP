#include <iostream>
using namespace std;

class GfG {
public:
    int a;
    
    // Parameterized constructor with
    // default value
    GfG(int val = 22) {a = val;}
};

int main() {
    
    // Creating object with argument
    GfG gfg1(109);
    
    // Creating object without argument
    GfG gfg2;
    
    cout << gfg1.a << endl;
    cout << gfg2.a;
    return 0;
}