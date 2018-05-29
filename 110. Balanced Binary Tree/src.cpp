/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* node){
        if (node == NULL) return 0;

        int left_h = getHeight(node->left);
        if (left_h == -1) return -1;
        int right_h = getHeight(node->right);
        if (right_h == -1) return -1;

        if (abs(left_h - right_h) > 1) return -1;
        else return max(left_h + 1, right_h + 1);
    }
    
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};
