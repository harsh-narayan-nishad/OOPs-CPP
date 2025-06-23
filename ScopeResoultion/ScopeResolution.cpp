#include <bits/stdc++.h>
using namespace std;

int a = 10;
int main() {
    int a =5;
    {
        int a = 3;
        cout<<a<<" "<<::a<<endl; // accessing gloabal value
    } 

    cout<<a<<" "<<::a<<endl;
    return 0;
}