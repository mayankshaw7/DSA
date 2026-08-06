#include<bits/stdc++.h>
using namespace std;

void counter(){
    // int count=0;
    static int count=0;//now this stastement willr un  for only one timeand we not destory untill the program end
    count++;
    cout<<count<<endl;
}
class Example{
    public:
        static int x; // here you may can use it as --> static const int x
};
int Example::x = 0; 
int main(){
    counter();
    counter();
    counter();
    counter();

    Example e1;
    Example e2;
    Example e3;

    cout<< e1.x++ <<endl;
    cout<< e2.x++ <<endl;
    cout<< e3.x++ <<endl;

}