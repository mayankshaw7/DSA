#include <bits/stdc++.h>
using namespace std;

class car {
public:
    string name;
    string color;
    int *mileage;

    // Default constructor
    car() : mileage(nullptr) {
        cout << "Constructor without parameterised" << endl;
    }

    // Parameterized constructor
    car(string name, string color) : name(name), color(color) {
        cout << "Constructor executed successfully" << endl;
        mileage = new int; // Allocate memory for mileage
        *mileage = 12; // Set default mileage
    }

    // Copy constructor
    car( car &original) {
        cout << "DEEP Copy constructor is running " << endl;
        name = original.name;
        color = original.color;
        mileage = new int; // Allocate new memory for mileage
        *mileage = *original.mileage; // Copy the value
    }

    // Destructor
    ~car() {
        delete mileage; // Free allocated memory
    }
};

int main() {
    car c0;                     // Non-parameterized constructor will run
    car c1("maruti", "purple"); // Parameterized constructor will run
    car c2(c1);                 // Copy constructor will run

    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << *c2.mileage << endl;

    // Uncommenting the following lines will show that c1 and c2 have independent mileage
    // *c2.mileage = 10;
    // cout << *c1.mileage << endl;
    // cout << *c2.mileage << endl;

    return 0;
}
