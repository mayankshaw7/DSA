/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if(root==null){
        TreeNode newNode=new TreeNode(val);
        return newNode;
        }
        solve(root,val);
        return root;
    }
    private void solve(TreeNode root,int val){
        if(root==null) {
           return;
        }
        if(root.val>val){
            if(root.left == null){
                 TreeNode newNode=new TreeNode(val);
                 root.left=newNode;
                 return;
            }else{
                 solve(root.left,val);
                 return;
            }
        }else if(root.val<val){
             if(root.right == null){
                 TreeNode newNode=new TreeNode(val);
                 root.right=newNode;
                 return;
            }else{
                 solve(root.right,val);
                 return;
            }
        }
    }
}