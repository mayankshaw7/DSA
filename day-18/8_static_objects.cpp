#include<bits/stdc++.h>
using namespace std;

class Example{
    public:
    Example(){
        cout<<"Constructor"<<endl;
    }
    ~Example(){
        cout<<"Destructor";
    }
};
int main(){
    static Example e1;//this object wiill be last remain unteill the program ends
    cout<<"Code ending \n";
    return 0;
}
