#include <bits/stdc++.h>
using namespace std;

int N_fibonacci(int n)
{
    // if (n == 0)
    //     return 0;
    // if (n == 1)
    //     return 1;
    if(n==1 || n==0) return n;
    return N_fibonacci(n - 1) + N_fibonacci(n - 2);
}
int main()
{
    cout << N_fibonacci(5);
    return 0;
}