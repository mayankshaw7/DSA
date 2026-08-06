//very very important quesiton from the prospective of interview and software engineering 
#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int si, int ei, int target)
{
    if (si > ei)
    {
        return -1; // no suxh elenebt exist
    }
    // for line-1
    int mid = si + (ei - si) / 2;
    if(arr[mid]==target) return mid;
    if (arr[si] <= arr[mid])
    { // for l1
        if (arr[si] <= target && target <= arr[mid])
        {
            // left
            return search(arr, si, mid - 1, target);
        }
        else
        { // right
            return search(arr, mid + 1, ei, target);
        }
    }
    else
    { // for line 2 in graph
        if (arr[mid] <= target && target <= arr[ei])
        {
            // right
            return search(arr, mid + 1, ei, target);
        } // left
        return search(arr, si, mid - 1, target);
    }
}
int main()
{
    int a[7] = {4, 5, 6, 7, 0, 1, 2};
    cout << "index : " << search(a, 0, 6, 0);

    return 0;
}