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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left_depth = 0;
        int right_depth = 0;

        TreeNode* tmp = root;
        while (tmp)
        {
            tmp = tmp->left;
            left_depth++;
        }
        while (tmp)
        {
            tmp = tmp->right;
            right_depth++;
        }
        if (left_depth == right_depth)
            return pow(2, left_depth) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
