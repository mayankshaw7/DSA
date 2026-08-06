#include<bits/stdc++.h>
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
            (*this).color=colorvalue;
        }
        string name;
        string color;
    void start(){
        cout<<"The car has started"<<endl;
    }
    void stop(){
        cout<<"The car has stopped"<<endl;
    }

};
 int main(){
    car c0;//non parameterised constructor will run
    car c1("mayank","blue"); //parameterised constructor will run
    cout<<c1.name<<endl;
    cout<<c1.color<<endl;
    c1.start();
    c1.stop();
    return 0;
 }