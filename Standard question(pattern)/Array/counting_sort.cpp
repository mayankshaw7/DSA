#include<bits\stdc++.h>
using namespace std;

void count_sort(int *arr,int n){
    int freq[100000]={0}; //range initialisation of the frequency array is necessary other it won't run at all
    int minVal=INT_MAX,maxVal=INT_MIN;
    for(int i=0;i<n;i++){
        minVal=min(minVal,arr[i]);
        maxVal=max(maxVal,arr[i]);
    }
    //1st Step- o(n)
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    //2nd step=o(range)
    for(int i=minVal,j=0;i<maxVal;i++){
        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }
}
int main(){
    int arr[8]={1,4,1,3,2,4,3,7};
    int n=sizeof(arr)/sizeof(int);
    cout<<"Before the count sort"<<endl;
    for(auto it:arr){
        cout<<it<<",";
    }
    count_sort(arr,n);
cout<<endl<<"After the count sort"<<endl;
    for(auto it:arr){
        cout<<it<<",";
    }
    return 0;
}