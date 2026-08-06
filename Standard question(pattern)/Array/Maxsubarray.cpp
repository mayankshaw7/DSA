#include<iostream>
using namespace std;

// void printsubarray(int *arr,int n){
// for(int start=0;start<n;start++){
//     for(int end=start;end<n;end++){
//        int currsum=0;
//         for(int i=start;i<=end;i++){
//             currsum+=arr[i];
//         }cout<<currsum<<",";
//     }cout<<endl;
// }
// }
void printsubarray(int *arr,int n){
    int maxi=0;
for(int start=0;start<n;start++){
    for(int end=start;end<n;end++){
       int currsum=0;
        for(int i=start;i<=end;i++){
            currsum+=arr[i];
        }if(currsum>maxi){
            maxi=currsum;
        }//Instead you can also use the max function max(maxsum,currsum);
    }
}
cout<<"Maximum subarray sum is "<<maxi;
}
int main(){
    int arr[6]={2,-3,6,-5,4,2};
    cout<<"hello world"<<endl;
    int n=sizeof(arr)/sizeof(int) ;
    printsubarray(arr,n);
    return 0;
}