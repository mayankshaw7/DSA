#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number for checking odd or even"<<endl;
    cin>>n;
    //logic behind the odd _ even is & operator if & of number 
    // with 1 (00...0001) is not equal to 0 then number is odd and if it== 0 number is zero
    if((1&n) == 0) cout<<n<< " is even number"<<endl;
    else cout<<n<< " is odd number"<<endl;
    return 0;
}