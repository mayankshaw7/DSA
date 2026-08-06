#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stock_span(vector<int>&stock,vector<int>&span){
    stack<int>s;
    s.push(0);
    span[0]=1;
    for(int i=1;i<span.size();i++){
        while(!s.empty() && stock[i]>=stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i]=i+1;
        }else{
            int prev_high=s.top();
             span[i]=i-prev_high;
        }
        s.push(i);
    }
}
int main(){
    vector<int> stock={100,80,60,70,60,85,100};
    // vector<int> span={0,0,0,0,0,0,0};
    vector<int> span(stock.size());
    stock_span(stock,span);
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
    return 0;
}
// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;

// void calculateStockSpan(const vector<int>& stock, vector<int>& span) {
//     stack<int> s;  // Stack to store indices
//     s.push(0);     // First element index
//     span[0] = 1;   // Span for the first day is always 1

//     for (int i = 1; i < stock.size(); i++) {
//         // Pop indices with smaller or equal stock values
//         while (!s.empty() && stock[i] >= stock[s.top()]) {
//             s.pop();
//         }

//         // If no greater element to the left
//         span[i] = s.empty() ? (i + 1) : (i - s.top());

//         s.push(i);  // Push current index
//     }
// }

// int main() {
//     vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
//     vector<int> span(stock.size());  // Create span vector of same size

//     calculateStockSpan(stock, span);

//     cout << "Stock Span: ";
//     for (int val : span) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }
