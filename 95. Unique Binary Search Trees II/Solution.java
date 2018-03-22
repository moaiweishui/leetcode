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
    public static List<TreeNode> generateTreesWithRange(int start, int end){
        List<TreeNode> rootList = new ArrayList<>();
        if(start > end){
            rootList.add(null);
            return rootList;
        }else if(start == end){
            rootList.add(new TreeNode(start));
            return rootList;
        }else{
            for(int i = start; i <= end; i++){
                //确定root为 i
                List<TreeNode> leftNodeList = generateTreesWithRange(start, i - 1);
                List<TreeNode> rightNodeList = generateTreesWithRange(i + 1, end);

                for(TreeNode leftChild : leftNodeList){
                    for(TreeNode rightChild : rightNodeList){
                        //确定了当前点左右两边的子节点
                        TreeNode root = new TreeNode(i);
                        root.left = leftChild;
                        root.right = rightChild;
                        rootList.add(root);
                    }
                }

            }
            return rootList;
        }

    }
    
    public List<TreeNode> generateTrees(int n) {
        if(n == 0){
            //不加单独的判断时，会出现问题，当n=0时，应该返回[]，但是实际返回[[]]
            List<TreeNode> res = new ArrayList<>();
            return res;
        }
        return generateTreesWithRange(1, n);
    }
}
