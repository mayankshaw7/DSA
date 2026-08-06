#include <bits/stdc++.h>
using namespace std;
class car
{
public:
    string name;
    string color;
    int *mileage;
    car()
    {
        cout << "Constructor without parameterised" << endl;
    }
    // it can be passed without argument also //its name hould be same as the name of the class
    car(string name, string color)
    {
        cout << "constructor executed successfully" << endl;
        this->name = name;
        (*this).color = color;
        mileage = new int;
        *mileage = 12; // for all car mileage will be 12 for now
    }
    car(car &original)
    {
        cout << "DEEP Copy constructor is running " << endl;
        name = original.name;
        color = original.color;
        //since we want different mileage of the car c2 herer we need to 
        // again do the allocation of new memory for storing new valie of mileage 
        mileage=new int;
        *mileage = *original.mileage; // this previous mileage of c1 will
        // get copied into the newly copied element that is c2
        // no memeort allocation will happen only the address of same will be carry forward

    }
     // Destructor
    ~car() {
        delete mileage; // Free allocated memory
    }
};
int main()
{
    car c0;                     // non parameterised constructor will run
    car c1("maruti", "purple"); // parameterised constructor will run
    car c2(c1);                 // automaticaaly by default copy constructor will run here
    // but if want we can easily create the manual copy constructor

    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << *c2.mileage << endl;

    *c2.mileage = 10;
    cout << *c1.mileage << endl;
    cout << *c2.mileage << endl;
    return 0;
}
//output- we can now understand that why both are now haing the different values of mileage
// 12
// 12
// 10