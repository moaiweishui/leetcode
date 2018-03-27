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
    public static TreeNode buildSubTree(List<Integer> preorder, List<Integer> inorder,
                        int pre_l, int pre_r,
                        int in_l, int in_r){
        if(pre_l > pre_r) return null;
        TreeNode node = new TreeNode(preorder.get(pre_l));

        int pos = inorder.indexOf(node.val);

        node.left = buildSubTree(preorder, inorder, pre_l + 1, pos - in_l + pre_l, in_l, pos - 1);
        node.right = buildSubTree(preorder, inorder, pos - in_l + pre_l + 1, pre_r, pos + 1, in_r);
        return node;
    }
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length == 0)
            return null;

        List<Integer> preorderList = new ArrayList<>();
        List<Integer> inorderList = new ArrayList<>();
        for (int x : preorder) preorderList.add(x);
        for (int x : inorder) inorderList.add(x);

        return buildSubTree(preorderList, inorderList, 0, preorder.length - 1, 0, inorder.length - 1);
    }
}
