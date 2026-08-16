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
 //with only onw liner change i did this question
 //thanks to striver and codewithstoryMAyank
 //it is a dawn wasy question
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        // TreeNode* temp=root;
        if (!root)
            return {};
        // Iterative appraoch
        vector<int> result;
        while (curr != NULL) {
            if (curr->left == NULL) {
                result.push_back(curr->val);
                curr = curr->right;
            } else // it means lft ka child NULL nahi hai
            {
                // getting the right Most value;
                TreeNode* leftChild = curr->left;
                while (leftChild->right != NULL) {
                    leftChild = leftChild->right;
                }
                leftChild->right = curr->right;
                result.push_back(curr->val);
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return result;
    }
};