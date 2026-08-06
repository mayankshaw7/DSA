#include<bits/stdc++.h>
using namespace std;
class Animal{
    public:
    string color;
    void eat(){
        cout<<"eats\n";
    }
    void Sleep(){
        cout<<"Sleeps\n";
    }
    void Breathe(){
        cout<<"Breathe\n";
    }
};

class mammal: public Animal{
    public:
    string bloodType;
    mammal(){
        bloodType="warm";
    }
    void swims(){
        cout<<"Swins\n";
    }
};
class Dog:public mammal{
    string tailang;
    void bark(){
        cout<<"Bark ......bark\n";
    }
};
int main(){
    Dog d1;
    d1.eat();//this is called multi inheritence briefly given in copy
    // f1.eat();
    return 0;
}  