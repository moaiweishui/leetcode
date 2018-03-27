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
    public static TreeNode buildSubTree(int[] inorder, int[] postorder,
                        int mid_l, int mid_r, int post_l, int post_r){
        if(post_l > post_r) return null;
        TreeNode node = new TreeNode(postorder[post_r]);
        int pos = -1;
        for(int i = mid_l; i <= mid_r; i++){
            if(inorder[i] == node.val){
                pos = i; break;
            }
        }
        
        node.left = buildSubTree(inorder, postorder, mid_l, pos - 1, post_l, pos - 1 - mid_l + post_l);
        node.right = buildSubTree(inorder, postorder, pos + 1, mid_r, pos - mid_r + post_r, post_r - 1);
        return node;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(inorder.length == 0) return null;
        return buildSubTree(inorder, postorder, 0, inorder.length - 1, 0, postorder.length - 1);
    }
}
