#include <bits/stdc++.h>
using namespace std;

bool is_sorted(int a[], int n, int i)
{
    if (i == n - 1)
    {
        return true;
    }
    if (a[i] > a[i + 1])
        return false;
    return is_sorted(a, n, i+1);
}
int main()
{
    int a[5] = {1, 92, 83, 73, 76};
    if (is_sorted(a, 5, 0))
    {
        cout << "Array is already sorted";
    }
    else
    {
        cout << "Array is not sorted";
    }

    return 0;
}