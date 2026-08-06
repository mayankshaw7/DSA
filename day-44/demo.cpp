#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        if (a == b) {
            // No operations needed
            cout << 0 << "\n";
        } else if (a > b) {
            // Check if a XOR b == a - b
            long long x = a ^ b;
            if (x == a - b && x >= 0 && x <= a) {
                // One operation
                cout << 1 << "\n" << x << "\n";
            } else {
                // Impossible
                cout << -1 << "\n";
            }
        } else {
            // a < b
            // Perform two operations:
            // 1) x = a  -> a becomes 0
            // 2) x = b  -> a becomes b
            cout << 2 << "\n" << a << " " << b << "\n";
        }
    }
    
    return 0;
}
