/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //did this question with my own with the help of the concept of subtree of another
class Solution {
public:
    bool sameTree(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL || p->val!=q->val){
            return false;
        }
        return sameTree(p->left,q->left)&& sameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      if(root==NULL && subRoot==NULL){
            return true;
        }
        //edge cases
        if(!root) return false;
        if(!subRoot) return true;

        if(sameTree(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};