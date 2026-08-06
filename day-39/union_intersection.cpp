#include<bits\stdc++.h>
using namespace std;
void union_set(vector<int> &a,vector<int>&b){
    unordered_set<int>st;
    for(int el:a){
        st.insert(el);
    }
    for(int el:b){
        st.insert(el);
    }
    cout<<"Union of two vectors are "<<endl;
    for(int el:st){
        cout<<el<<" ";
    }
}
void Intersection(vector<int>&a,vector<int>&b){
     unordered_set<int>st;
    for(int el:a){
        st.insert(el);
    }
    cout<<"Intersection of Two vectors are "<<" ";
    for(int el:b){
        if(st.find(el)!=st.end()){
            cout<<el<<" ";
        }
    }
}
int main(){
    vector<int>a={1,2,3,4,5,5};
    vector<int>b={19,425,32,5,25};
    union_set(a,b);
    Intersection(a,b);

    return 0;
}