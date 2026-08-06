#include<bits/stdc++.h>
using namespace std;

int first_occurence(vector<int> a, int i, int target){
    if(i==a.size()-1){
    return -1;
    }
    if(target==a[i]){
        return i;
    }
    return first_occurence(a,i+1,target);
}
int main(){
    vector<int>arr={1,2,3,3,3,5};
    cout<<"Index of the first occurence is "<<first_occurence(arr,0,30);
    return 0;
}