//Suppose you have infinite coins of given array where array is not sorted 
//find the question in the lleetcode by search 
//actually it is not the optimized way of finding the minimum nnumber of coins in the senarios
//In leetcode this test case fails and it will lead to wrong answer

#include<bits/stdc++.h>
using namespace std;
int Denomination_of_coins(vector<int>&coins,int target){
    int ans=0;
    int n=coins.size();
    if(n==0) return -1;
    for(int i=n-1;i>=0;i--){
        if(coins[i]<=target){
            ans+=target/coins[i];
            target=target%coins[i];
        }
       
    } return ans==0 ? -1 : ans;
}
int main(){
    vector<int>coins={1,2,3,20,10,50,100,500,2000}; 
    int target=590;
    //here we are taking input in forms of sorted array
    int ans=Denomination_of_coins(coins,target);
    cout<<"Total minimum number of coins is : "<<ans;
    return 0;
}