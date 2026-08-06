#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
    bool isValid(string s) {
        stack<char> st;
        for (auto it : s) {
            if (it == '(' || it == '{' || it == '[') {
                st.push(it);
            } else {
                 if (st.empty())
                     return false;
                char ch = it;
                if(ch == ')' && st.top() == '(' || ch == '}' && st.top() == '{' ||
                 ch == ']' && st.top() == '[') {
                    st.pop();
                }else {
                    return false;
                }
            }
        }
            // if (st.empty())
            //     return true;
            // return false;
            return st.empty();
        }
int main(){
    string str="()[]{}";
    string str1="(])";
    cout<<str<<"is"<<isValid(str)<<endl;
    cout<<str1<<"is"<<isValid(str1);
    return 0;
}