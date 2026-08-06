#include<bits/stdc++.h>
using namespace std;

void print_decreasing(int n){
    if(n==0){
        return ;
    }
    cout<<n<<" , ";
    print_decreasing(n-1);
}
void print_increasing(int n){
    if(n==0){
        return ;
    }
    print_increasing(n-1);
    cout<<n<<" , ";
}
int main(){
    print_decreasing(5);
    print_increasing(5);
    return 0;
}