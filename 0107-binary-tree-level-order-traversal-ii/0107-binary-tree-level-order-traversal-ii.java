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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        //solving in Java Language 
        List<List<Integer>>res=new ArrayList<>();
        helper(root,res);
        Collections.reverse(res);
        return res;
    }
    private void helper(TreeNode root,List<List<Integer>>res){
        if(root==null) return;
        Queue<TreeNode>q=new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            int size=q.size();
                ArrayList<Integer>level=new ArrayList<>();
            for(int i=0;i<size;i++){
                TreeNode parent_node=q.peek();
                q.poll();
                level.add(parent_node.val);
                if(parent_node.left!=null){
                    q.offer(parent_node.left);
                }
                if(parent_node.right!=null){
                    q.offer(parent_node.right);
                }

            }
            res.add(level);
        }

    }
}