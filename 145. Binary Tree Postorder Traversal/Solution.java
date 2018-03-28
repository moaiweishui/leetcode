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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        TreeNode node = root;
        TreeNode last = null;
        Stack<TreeNode> st = new Stack<>();
//        st.push(node);
        while(node != null || !st.isEmpty()){
            while(node != null){
                st.push(node);
                node = node.left;
            }

            //判断当前节点的右节点是否被访问过
            node = st.peek();
            if(node.right != null && node.right != last){
                node = node.right;
            }else{
                res.add(node.val);
                last = node;
                node = null;
                st.pop();
            }

        }

        return res;
    }
}
