/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 //in this way this qustion is solved using the INorder + counter Approach 
class Solution {
public:
    int ans=-1;
    void solve(TreeNode* root, int& cnt, int& k) {
        if (!root)
            return;
        solve(root->left, cnt, k);
        ++cnt;
        if (cnt == k){
            ans= root->val;
            return;
        }
        solve(root->right, cnt, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        solve(root, cnt, k);
        return ans;
    }
};