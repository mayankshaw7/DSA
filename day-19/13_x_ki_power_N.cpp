#include <bits/stdc++.h>
using namespace std;

int power(int x, int n) {
    // Base case: if n is 0, return 1
    if (n == 0) return 1;
    // Base case: if n is 1, return x
    if (n == 1) return x;

    // Recursive call
    return x * power(x, n - 1); // Multiply x by the result of power(x, n-1)
}
//o(n)
int main() {
    cout << power(2, 5); // Output should be 32
    return 0;
}
