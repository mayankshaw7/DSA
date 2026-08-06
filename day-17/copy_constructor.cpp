#include <bits/stdc++.h>
using namespace std;
class car{
        public:
        car(){
            cout<<"Constructor without parameterised"<<endl;
        }
        // it can be passed without argument also //its name hould be same as the name of the class
        car(string namevalue,string colorvalue){
            cout<<"constructor executed successfully"<<endl;
            this ->name=namevalue;
            (*this).color=colorvalue; //both ways are same 
        }
        string name;
        string color;
        

        car(car &original){
            cout<<"Copy constructor is running "<<endl;
            name=original.name;
            color=original.color;
        }
    };
 int main(){
    car c0;//non parameterised constructor will run
    car c1("maruti","purple"); //parameterised constructor will run
    car c2(c1);//automaticaaly by default copy constructor will run here
    //but if want we can easily create the manual copy constructor

    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    return 0;
 }
 //output
//  Constructor without parameterised
// constructor executed successfully
// Copy constructor is running
// maruti
// purple