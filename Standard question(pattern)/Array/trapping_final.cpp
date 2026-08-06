#include<bits\stdc++.h>
using namespace std;

void trap(int *height,int n){
    int leftmax[20000],rightmax[20000];
    leftmax[0]=height[0];
     rightmax[n-1]=height[n-1];

    for(int i=1;i<n;i++){
        leftmax[i]=max(leftmax[i-1],height[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        rightmax[i]=max(rightmax[i+1],height[i+1]);
    }
    int water_trapped=0;
    for(int i=0;i<n;i++){
        int currtrapped=min(leftmax[i],rightmax[i])- height[i];
        if(currtrapped>0){
            water_trapped+=currtrapped;
        }
    }
    cout<<endl<<"Total water trapped is  "<<water_trapped<<endl;

}
int main(){
    int height[7]={4,2,0,6,3,2,5};
    int n=sizeof(height)/sizeof(int);
    trap(height,n);
}