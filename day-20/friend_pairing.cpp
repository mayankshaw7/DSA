#include<bits/stdc++.h>
using namespace std;

int friend_pairing(int n){
    //base condition
    if(n==2 || n==1) return n;
    //single + paired case
    return friend_pairing (n-1) + (n-1) * friend_pairing(n-2);
}
int main(){
    cout<<friend_pairing(4);
    return 0;
}