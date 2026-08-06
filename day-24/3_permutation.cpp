#include<bits/stdc++.h>
using namespace std;

void permutation(string str,string ans){
    int n=str.size();
    if(n==0){
        cout<<ans<<endl;
        return ;
    }
    for(int i=0;i<str.size();i++){
    char ch=str[i];
    string nextStr=str.substr(0,i)+str.substr(i+1,n-i-1); 
        permutation(nextStr,ans+ch);//ith char to choice to add in permutation
    }
}
int main(){
    string str="abc",ans="";
    permutation(str,ans);
    return 0;
}