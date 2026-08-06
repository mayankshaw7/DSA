#include<iostream>
using namespace std;
 
int partition(int arr[],int si,int ei){
    int i=si-1,pivot=arr[ei];
    for(int j=si;j<ei;j++){
        if(arr[j]<=pivot){
            i++; //incrementing i 
            swap(arr[i],arr[j]);//swap the element of the arr[i] and arr[j]
        }
    }i++;
    swap(arr[i],arr[ei]);//mistake happende here is i was swapping the pivot instead of the end of the array
    //swap(arr[i],arr[ei]) //this is basically a wrong method of swapping the pivot element
    return i;//here i is basically the pivotidx for the above code
}
void Quick_sort(int arr[],int si,int ei){

    if(si>=ei) return ;
        int pivotidx=partition(arr,si,ei);
        //quick sort
        Quick_sort(arr,si,pivotidx-1);
        Quick_sort(arr,pivotidx+1,ei);
    
}
int main(){
    int arr[6]={6,3,5,2,7,4};
    int n=sizeof(arr)/sizeof(int) ;
    Quick_sort(arr,0,n-1);
    cout<<"Showing result ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}