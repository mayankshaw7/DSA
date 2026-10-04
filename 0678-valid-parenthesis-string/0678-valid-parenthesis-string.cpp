// visit in future -->https://youtu.be/Pno2hATcwHA -->understand recursive tree
// then it will become piece of cake for you
// This question is having multiple appraochees
// solving with memoization approach
class Solution {
public:
    int t[101][101]; // why 101 observe from the constraints
    bool solve(int idx, int open, string s, int n) {
        if (idx == n) {
            return open == 0;
        }
        bool isValid=false;
        // memoization steps
        if (t[idx][open] != -1) {
            return t[idx][open];
        }
        if (s[idx] == '(') {
            isValid |= solve(idx + 1, open + 1, s, n);
        } else if (s[idx] == ')') {
            if (open > 0) {
                isValid |= solve(idx + 1, open - 1, s, n);
            }
        } else if (s[idx] == '*') {
            // having three possibilities
            isValid |= solve(idx + 1, open + 1, s, n);
            isValid |= solve(idx + 1, open, s, n); //*  --> vacant empty
            if (open > 0) {
                isValid |= solve(idx + 1, open - 1, s, n);
            }
        }
        return t[idx][open] = isValid;
    }
    bool checkValidString(string s) {
        int n = s.size();
        int open = 0;
        memset(t, -1, sizeof(t));
        return solve(0, open, s, n);
    }
};
//time and space is N^2
//bottom up appraoch or DP appraoch
//discussing below