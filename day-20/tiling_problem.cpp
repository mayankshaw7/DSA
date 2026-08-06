#include<bits/stdc++.h>
using namespace std;

int tiling_problem(int n){
    //considering two base cases
    if(n==0 || n==1) return 1;

    return tiling_problem(n-1)+tiling_problem(n-2);
}
int main(){
    cout<<tiling_problem(3);
    return 0;
}