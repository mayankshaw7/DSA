#include<bits/stdc++.h>
using namespace std;

void Interleave(queue<int> &q) {
       queue<int>temp;
       int n=q.size();
       for(int i=0;i<n/2;i++){
           temp.push(q.front());
           q.pop();
      }
      while(!temp.empty()){
          q.push(temp.front());
          temp.pop();
          q.push(q.front());
          q.pop();
      }
}
int main(){
    queue<int>org;
    for(int i=1;i<=10;i++){
        org.push(i);
    }
    Interleave(org);
    for(int i=0;i<10;i++){
        cout<<org.front()<<" ";
        org.pop();
    }
    return 0;
}
//question link
//https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1