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
 //solving using the Iterative post order technique
 //just doing little opposite of what we have done earlier 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;

        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->right==NULL){
                result.push_back(curr->val);
                curr=curr->left;
            }else{

                TreeNode* predecessor=curr->right;
                while(predecessor->left!=NULL && predecessor->left!=curr){
                    predecessor=predecessor->left;
                }

                if(predecessor->left==NULL){
                    result.push_back(curr->val);
                    predecessor->left=curr;//create a thread to root
                    curr=curr->right;
                }else{
                    //break the thread
                    predecessor->left=NULL;
                    curr=curr->left;

                }
            }
        }
        reverse(begin(result),end(result));
        return result;
    }
};