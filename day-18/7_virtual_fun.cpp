#include<bits/stdc++.h>
using namespace std;

class Shape{
    public:
         virtual void draw()=0; //abstract  fnx, pure virtual fnc
         //since it is unimplement function so whenever we make the class
         //shape it will not able to run this funvton 
};
class Circle:public Shape{
        public:
    void draw(){
        cout<<"Drawing Circle\n";
    }
};
class Square:public Shape{
        public:
    void draw(){
        cout<<"Drawing Square\n";
    }
};
int main(){
    Circle c1;
    Square s1;
    s1.draw();
    c1.draw();
    // Shape s1;//we cannot create the shaped class as it is having the abstraxt ckass
    return 0;
}
// output
// Drawing Square
// Drawing Circle