#include <bits/stdc++.h>
using namespace std;

class Student{
    public: 
    int age;
    int rollNo;
    bool present;

    void bunk(){
        cout<<"Bunking"<<endl;
    }
    void dancing(){
        cout<<"Dancing"<<endl;
    }

    void music(){
        cout<<"Music lover"<<endl;
    }
    
};

int main() {
    Student s1;
    
    cout<<sizeof(Student);

    return 0;
}

    