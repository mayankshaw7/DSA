#include<bits/stdc++.h>
using namespace std;


void RemoveDuplicate(string str,string ans,int i,int map[]){
    if(i==str.size()){
        cout<<"ans :"<< ans;
        return ;
    }int ch=str[i];
    int map_idx=int(ch-'a');
    if(map[map_idx]==true) {//found duplicates
        RemoveDuplicate(str,ans,i+1,map);
    }else{
        map[map_idx]=true;
        RemoveDuplicate(str,ans+str[i],i+1,map);
    }
}
int main(){
    int map[26]={false};
    string ans="";
    string str="apnnacollege";
    RemoveDuplicate(str,ans,0,map);
    return 0;
}