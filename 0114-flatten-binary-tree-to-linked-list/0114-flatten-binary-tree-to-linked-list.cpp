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
// optimized approach ..i did this with my own
// Morries Traversal Is damn easy man

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                curr = curr->right;
            } else {
                TreeNode* leftchild = curr->left;
                while (leftchild->right != NULL) {
                    leftchild = leftchild->right;
                }
                if (leftchild->right == NULL) {
                    leftchild->right = curr->right;
                    curr->right = curr->left;
                    curr->left = NULL;
                }
            }
        }
    }
};

// Recursive Solution
// Just solve one problem and everything will be done by recursion have faith in
// it has a stack space of o(n)
/*
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        TreeNode* templeft = root->left;
        TreeNode* tempright = root->right;
        flatten(root->left);
        flatten(root->right);

        root->left = NULL;
        root->right = templeft;
        TreeNode* curr = root;
        while (curr->right != NULL) {
            curr = curr->right;
        }
        if (curr->right == NULL)
            curr->right = tempright;
    }
};
*/