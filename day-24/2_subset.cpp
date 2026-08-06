#include<vector>
#include<iostream>
#include<string>
using namespace std;

void different_subset(string str,string subset){

    if(str.size()==0){
        cout<<"'"<<subset <<"'"<<endl;
        return ;
    }
    char ch=str[0];//mistake done over here is string ch;;
    //for yes
    different_subset(str.substr(1,str.size()-1),subset+ch);
    //for no
    different_subset(str.substr(1,str.size()-1),subset);
}
int main(){
        string str="abc";
        different_subset(str,"");
    return 0;
}