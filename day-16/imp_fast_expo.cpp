#include<bits\stdc++.h>
using namespace std;
void fast_expo(int x,int n){
    int ans=1;
    while(n>0){
        int last_digit=n&1;
        if(last_digit){
            ans=ans*x;
        }
        x=x*x;
       n= n>>1;
      
    } cout<<ans<<endl;
}
int main(){

    fast_expo(3,5);
    return 0;
}