#include<bits\stdc++.h>
using namespace std;

 int main(){
    // priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(4);
    pq.push(41);
    pq.push(23);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }cout<<endl;
    priority_queue<string,vector<string>,greater<string>> p; 
        p.push("hello world");
    p.push("buy");
    p.push("Alpha");
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    return 0;
 }