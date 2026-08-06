#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void next_greater(vector<int> &nums, vector<int> &ans)
{
    int idx = nums.size() - 1;
    ans[idx] = -1;
    stack<int> s;
    s.push(nums[idx]); 
    for (int i = idx - 1; i >= 0; i--)
    {
        int curr = nums[i];
        while (!s.empty() && curr >= s.top())
        {
            s.pop();
        }

        if (s.empty())
            ans[i] = -1;
        else
        {
            ans[i] = s.top();
        }
        s.push(curr);
    }
}
int main()
{
    vector<int> nums = {6, 8, 0, 1, 3};
    vector<int> ans(nums.size(),0);
    next_greater(nums, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;

// void next_greater(vector<int> &v, vector<int> &ans) // Pass 'ans' by reference
// {
//     int n = v.size(); // Use 'n' for size
    
//     // The next greater element for the last element is always -1
//     ans[n - 1] = -1; 
    
//     stack<int> s;
//     s.push(v[n - 1]); // Push the last element onto the stack

//     for (int i = n - 2; i >= 0; i--) // Iterate from the second to last element
//     {
//         int curr = v[i];
//         while (!s.empty() && curr >= s.top())
//         {
//             s.pop();
//         }

//         if (s.empty())
//             ans[i] = -1; // Assign to ans[i]
//         else
//         {
//             ans[i] = s.top(); // Assign to ans[i]
//         }
//         s.push(curr);
//     }
// }

// int main()
// {
//     vector<int> nums = {6, 8, 0, 1, 3};
//     vector<int> ans(nums.size()); // Initialize ans with the correct size
    
//     next_greater(nums, ans);
    
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << endl; // Add a newline for better output formatting
//     return 0;
// }