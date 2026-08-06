#include <iostream>
#include <stack>
#include <string>
using namespace std;
void push_at_bottom(stack<int>&st,int n){
    if(st.empty()){
        st.push(n);
        return ;
    }
    int top=st.top();
    st.pop();
    push_at_bottom(st,n);
    st.push(top);
 }
 void reverse(stack<int>&st){
    if(st.empty()){
        return ;
    }
    int top=st.top();
    st.pop();
    reverse(st);
    push_at_bottom(st,top);
 }
 void printt(stack<int>st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
 }
 //if we want to show the change in the int main then we need to pass the reference using the pass by reference
int main(){
    stack<int> st;
    st.push(23);
    st.push(3);
    st.push(9);
    st.push(9);

    cout << "Original stack: ";
    printt(st); // prints copy, doesn't remove

    reverse(st);

    cout << "Reversed stack: ";
    printt(st); // prints copy of reversed
    return 0;
}
