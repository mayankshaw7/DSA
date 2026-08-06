#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n % 2 == 0)
        {
            return myPow(x, n / 2) * myPow(x, n / 2);
        }
        else
        {
            return x * myPow(x, n / 2) * myPow(x, n / 2);
        }
    }
};
int main()
{
    Solution s1;
    cout << s1.myPow(2, 5);
    return 0;
}