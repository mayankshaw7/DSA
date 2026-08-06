// #include<iostream>

// #include <climits>
#include<bits\stdc++.h>
using namespace std;

void maxProfit(int *prices,int n){
    int bestBuy[100000];
    int max_profit=0;
    bestBuy[0]=INT_MAX;
    for(int i=1;i<n;i++){
        bestBuy[i]=min(bestBuy[i-1],prices[i-1]);
    }
    for(int i=0;i<n;i++){
        int currprofit=prices[i]-bestBuy[i];
        max_profit=max(currprofit,max_profit);
    }
    cout<<"Maximum Profit earned are "<<max_profit;
}
int main(){
    int arr[6]={7,1,5,3,6,4};
    int n=sizeof(arr)/sizeof(int);
    maxProfit(arr,n);
    return 0;
}