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
// brute force is simple
// sorted array and find the most appear and return them
// always do a dry before submitting
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root)
            return {};
        vector<int> vec;
        solve(vec, root);
        vector<int> ans;
        ans.push_back(vec[0]);
        int curr_cnt = 1;
        int maxi_cnt = 1;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] == vec[i - 1]) {
                curr_cnt++;
            } else {
                curr_cnt = 1;
            }
            if (curr_cnt > maxi_cnt) {
                maxi_cnt = curr_cnt;
                ans.clear();
                ans.push_back(vec[i]);
            } else if (curr_cnt == maxi_cnt) {
                ans.push_back(vec[i]);
            }
        }
        return ans;
    }
    void solve(vector<int>& vec, TreeNode* root) {
        if (!root)
            return;
        solve(vec, root->left);
        vec.push_back(root->val);
        solve(vec, root->right);
    }
};