/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;

        Stack<TreeNode> st = new Stack<>();
        TreeNode pre = null;
        TreeNode curr = root;

        while(curr != null || !st.isEmpty()){
            while(curr != null){
                //沿左下遍历到底
                st.push(curr);
                curr = curr.left;
            }

            curr = st.pop();
            if(pre != null && curr.val <= pre.val) return false;
            pre = curr;
            //跳到右节点
            curr = curr.right;
        }

        return true;
    }
}

class Solution {
    public static boolean isValidNode(TreeNode node, long min, long max){
        if(node == null) return true;
        if(node.val <= min || node.val >= max) return false;
        return isValidNode(node.left, min, node.val) & isValidNode(node.right, node.val, max);
    }
    
    public boolean isValidBST(TreeNode root) {
        if(root == null){
            return true;
        }

        return isValidNode(root.left, Long.MIN_VALUE, root.val) & isValidNode(root.right, root.val, Long.MAX_VALUE);
    }
}
