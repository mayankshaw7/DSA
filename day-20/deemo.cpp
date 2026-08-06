#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3][2],ans[3]={0,0,0};
    int mini=INT_MAX;
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cin>>a[i][j];
            if(mini>a[i][j]){
                ans[i]=a[i][j];
                mini=a[i][j];
            }
        }
    }
    for(int i=0;i<3;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}