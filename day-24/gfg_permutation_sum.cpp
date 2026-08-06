#include<bits/stdc++.h>
using namespace std;
void permutation(int arr[],int n,string ans){
    if(n==0){
        cout<<ans<<" ";
        return ;
    }
    for(int i=0;i<n;i++)
    {
        char ch=arr[i];
        
        permutation(arr,n-1,ans+=ch);
        permutation(arr,n-1,ans);
    }
}
int main(){
    int arr[3]={1,2,3};
    int n=sizeof(arr)/sizeof(int);
    permutation(arr,n-1,"");
    return 0;
}