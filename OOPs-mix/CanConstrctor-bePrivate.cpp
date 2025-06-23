#include <bits/stdc++.h>
using namespace std;
class Box{
    int width;

    Box(int _w): width(_w){};
    public:
    // Box(int _w): width(_w){};
    int getWidth() const{
        return width;
    }

    void setWidth(int _val){
        width = _val;
    }

    friend class BoxFactory;  // Muje bs BoxFactory hi initialize kar sakta hai.
};


class BoxFactory{
    int count;
    public:
    Box getABox(int _w){
        ++count;
        return Box(_w);
    }
};

int main() {
    // Box b(5);
    BoxFactory bfact;
    Box b = bfact.getABox(5);
    cout<<b.getWidth();

    return 0;
}



