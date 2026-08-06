#include<bits/stdc++.h>
using namespace std;

int sum_of_N_natural_number(int n){
    if(n==0) 
        return 0;
    return sum_of_N_natural_number(n-1)+n;
}
int main(){
    cout<<sum_of_N_natural_number(5);
    return 0;
}