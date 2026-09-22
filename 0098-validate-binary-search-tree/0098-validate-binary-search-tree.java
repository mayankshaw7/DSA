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
 //simple simulation any one can do this easily 
class Solution {
    public boolean isValidBST(TreeNode root) {
        return solve(root.left,null,root) && solve(root.right,root,null);
    }
    private static boolean solve(TreeNode root, TreeNode mini,TreeNode maxi){
        if(root==null){
            //a single node is always a valid one 
            return true;
        }

        if(mini!=null && root.val<=mini.val){
            return false;
        }
        if(maxi!=null && root.val>=maxi.val){
            return false;
        }
        return solve(root.left,mini,root) && solve(root.right,root,maxi);
    }
}