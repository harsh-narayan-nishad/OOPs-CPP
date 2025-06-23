#include <bits/stdc++.h>
using namespace std;

class abc{
    public:
    int x, y;

    void print() const
    {
        cout<<this->x<<" "<<this->y<<endl;
    }
};
int main() {
    abc obj1 = {1,2};
    abc obj2 = {4,5};
    obj1.print();
    obj2.print();
     
    return 0;
}