#include<bits/stdc++.h>
using namespace std;
 int get_ith_bit(int mask,int i){
        int num=1<<i;
        if((num & mask)> 0 ){//double parenthessis is necessary
            return 1;
        }else return 0;
    }
 int set_ith_bit(int mask,int i){
        int num=1<<i;
            return num | mask;
    }
int main(){
   int mask,i;
   cout<<"Enter the mask : ";cin>>mask;cout<<endl;
   cout<<"Enter the position nto check  : ";cin>>i;cout<<endl;
    cout<<"Result for get ith bit: "<<get_ith_bit(mask,i)<<endl;
    cout<<"Enter the postion to set ith bit to 1";cin>>i;cout<<endl;
    cout<<"Result : for set ith bit : "<<set_ith_bit(mask,i)<<endl;
    
    return 0;
}