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
    class TreeNodeWithLevel{
    int level;
    TreeNode node;
    TreeNodeWithLevel(int x, TreeNode n){
        level = x;
        node = n;
    }
}
    
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null) return res;
        
        Queue<TreeNodeWithLevel> q = new LinkedList<>();
        TreeNodeWithLevel node = new TreeNodeWithLevel(0, root);
        q.offer(node);

        List<Integer> temp = new ArrayList<>();
        res.add(temp);

        while(!q.isEmpty()){
            node = q.poll();

            if(node.level == res.size()){
                temp = new ArrayList<>();
                res.add(temp);
            }
            if(node.level % 2 == 0){
                res.get(node.level).add(node.node.val);
            }else{
                res.get(node.level).add(0, node.node.val);
            }

            if(node.node.left != null){
                q.offer(new TreeNodeWithLevel(node.level + 1, node.node.left));
            }
            if(node.node.right != null){
                q.offer(new TreeNodeWithLevel(node.level + 1, node.node.right));
            }
        }

        return res;
    }
}
