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


//Example for the public access modifier
// class Fish: public Animal{
//     public:
//     int fin=10;
//     void fins(){
//         cout<<fin;
//     }
//     void swims(){
//         cout<<"Swins\n";
//     }
// };

//example for the protected access modifier
class Fish: protected Animal{
    public:
    int fin=10;
    void fins(){
        eat();//methods of parrent class can be accessed inside the fucntion only
        cout<<fin;
    }
    void swims(){
        cout<<"Swins\n";
    }
};
//example for the private access modifer
//shave the same output as the protected one
// class Fish: private Animal{
//     public:
//     int fin=10;
//     void fins(){
//         eat();
//         cout<<fin;
//     }
//     void swims(){
//         cout<<"Swins\n";
//     }
// };
int main(){
    Fish f1;
    f1.fins();
    // f1.eat();
    return 0;
}