/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//used Similar Logic of LCA of BT 
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        //left does nt have the asked Node 
        if(left==NULL) return right;
        //right does have the asked Node 
        if(right==NULL) return left;
        //it means that root got the both values right and left 
        //and it the onyl lower common ancester of both the root 
        return root;
    }
};
*/
//Solving using the Optimized Approach 
//By checking The greater and less than the root methodology
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
        int curr=root->val;
        if(curr<p->val && curr<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr>p->val && curr>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        //else it means it is lieing the middle of on left p and on right they have q;
        //also 1 se 1 bhi possible hai isme means agar sirf p and q diya ho toh 
        return root;
    }
};