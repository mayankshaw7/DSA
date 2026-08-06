#include <bits\stdc++.h>
using namespace std;
void heapify(int parent, vector<int> &arr, int n)
{
    int l = 2 * parent + 1;
    int r = 2 * parent + 2;
    int maxi = parent;
    if (l < n && arr[l] > arr[maxi])//made mistake here from next time do take care of these things very wisely
    {
        maxi = l;
    }
    if (r < n && arr[r] > arr[maxi])
    {
        maxi = r;
    }
    if (maxi != parent)
    {
        swap(arr[maxi], arr[parent]);
        heapify(maxi, arr, n); // updated parent shift to the upper level
    }
}
void heapsort(vector<int> &arr)
{   
    //step-1 making call for all non leaf node in imagination
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(i, arr, n); // we are passing n for the use of 2nd step
    }
    //step 2 --> taking element to their right position
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}
int main()
{
    vector<int> arr = {1, 4, 2, 5, 3};
    heapsort(arr);
    for(auto it:arr) cout<<it<<" ";
    return 0;
}