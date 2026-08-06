#include<bits/stdc++.h>
using namespace std;
int clear_ith_bit(int mask,int i){
    int num=~(1<<i);
    return mask & num;
}
int main(){
     int mask,i;
   cout<<"Enter the mask : ";cin>>mask;cout<<endl;
   cout<<"Enter the position to clear the bit  : ";cin>>i;cout<<endl;
    cout<<"Result for clear ith bit: "<<clear_ith_bit(mask,i)<<endl;

    return 0;
}