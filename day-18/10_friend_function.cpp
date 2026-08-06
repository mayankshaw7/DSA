#include<bits/stdc++.h>
using namespace std;
class A{
    string secret="Smoooth";
    friend void reveal_secret(A &obj);
    friend class B;
};
class B{
    public:
    void show_secret(A &obj){
        cout<<obj.secret<<endl;
    }
};
void reveal_secret(A &obj){
    cout<<obj.secret<<endl;
}
int main(){
    A a1;
    B b1;
    b1.show_secret(a1);
    reveal_secret(a1);//here function as well as the class can access the private 
    // section of class A by becoming the friend of class A
    return 0;
}