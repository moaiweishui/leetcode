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
    public static void inorder(TreeNode node, List<Integer> res){
        if(node == null){
            return;
        }
        inorder(node.left, res);
        res.add(node.val);
        inorder(node.right, res);
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        inorder(root, res);
        return res;
    }
}

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> st = new Stack<>();
        TreeNode p = root;
        while (p != null || !st.empty()){
            if(p != null){
                st.push(p);
                p = p.left;
            }else{
                p = st.pop();
                res.add(p.val);
                p = p.right;
            }
        }
        return res;
    }
}
