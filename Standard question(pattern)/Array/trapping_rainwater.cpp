#include<bits\stdc++.h>
using namespace std;

void trap(int *height,int n){
    int leftmax[20000];
    leftmax[0]=INT_MIN;
    cout<<leftmax[0]<<",";
    for(int i=1;i<n;i++){
        leftmax[i]=max(leftmax[i-1],height[i-1]);
        cout<<leftmax[i]<<",";
    }
    cout<<endl;
    int rightmax[20000];
    rightmax[n-1]=INT_MIN;
    cout<<rightmax[n-1]<<",";
    for(int i=n-2;i>=0;i--){
        rightmax[i]=max(rightmax[i+1],height[i+1]);
        cout<<rightmax[i]<<",";
    }
    cout<<endl;
    int water_trapped=0;
    for(int i=0;i<n;i++){
        int currtrapped=min(leftmax[i],rightmax[i])- height[i];
        if(currtrapped>0){
            water_trapped+=currtrapped;
        }
    }
    cout<<endl<<water_trapped<<endl;

}
int main(){
    int height[7]={4,2,0,6,3,2,5};
    int n=sizeof(height)/sizeof(int);
    trap(height,n);

}
//;leetcode 2016 is also off this type must practice preprocessing things 