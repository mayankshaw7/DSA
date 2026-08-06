#include<bits\stdc++.h>
using namespace std;

int main(){
    //it is an PQ of student which store s the Student objects 
    priority_queue<pair<string,int>>pq;
    pq.push(make_pair("Chetan",56));
    pq.push(make_pair("Priya",90));
    pq.push(make_pair("Vivek",66));
    //popping and orinting the values
    while(!pq.empty()){
        cout<<"Top="<<pq.top().first <<" , "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}