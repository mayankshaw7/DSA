#include<bits/stdc++.h>
using namespace std;

class print{
    public:
    void show(int x){
        cout<<"Int : "<<x<<endl;
    }
    void show(string x){
        cout<<"string : "<<x<<endl;;
    }
};
int main(){
    print p1;
    p1.show("Mauanl");
    p1.show(16700500);
    return 0;
}