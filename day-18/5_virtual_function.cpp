#include<bits/stdc++.h>
using namespace std;
 
class parent{
    public:
    virtual void show(){
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
    parent *ptr;//even if we are making parent class objects it is calling the child class function
    ptr=&c1;//run time ond binding
    ptr->show(); // virtual function

    return 0;
}
