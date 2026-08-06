#include<bits/stdc++.h>
using namespace std;

class parent{
    public:
    void show(){
        cout<<"showing from parent";
    }
};
class child: public parent{
    public:
    void show(){// Here the function is overriden by the child class 
        cout<<"showing from child";
    }
};


int main(){
    child c1;
    c1.show();
    return 0;
}