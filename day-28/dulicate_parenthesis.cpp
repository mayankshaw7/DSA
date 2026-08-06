#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
    bool duplicate_parenthesis(string str){
        stack<int>s;
        for(auto it:str){
            if(it!=')'){
                s.push(it);
            }else{
                if(s.top()=='(') return true;//means it is duplicate
                //if(s.empty()) <-- we are not using this as it is given that a vlid string is given
                // while(!s.empty() && s.top()!='('){ not need to add this condition stack will not be empty as
                //it is a valid string
                while( s.top()!='('){
                    s.pop();
                }
                s.pop();
            }
           
        } return false;
    }
int main(){
    string str="((a+b) + x)";
    string str1="((a+b))";
    cout<<str<<"is"<<duplicate_parenthesis(str)<<endl;
    cout<<str1<<"is"<<duplicate_parenthesis(str1);
    return 0;
}