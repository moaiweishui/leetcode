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
    TreeNode firstNode = null;
    TreeNode secondNode = null;
    TreeNode preNode = null;
    
    //BST的中序序列是有序的
    public void inOrder(TreeNode node){
        if(node == null) return;
        inOrder(node.left);

        if(preNode != null){
            if(firstNode == null && node.val <= preNode.val){
                firstNode = preNode;
            }
            if(firstNode != null && node.val <= preNode.val){
                secondNode = node;
            }
        }

        preNode = node;

        inOrder(node.right);
    }
    
    public void recoverTree(TreeNode root) {
        if(root == null) return;

        inOrder(root);

        int temp = firstNode.val;
        firstNode.val = secondNode.val;
        secondNode.val = temp;
    }
}
