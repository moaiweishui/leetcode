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
    void findPath(TreeNode* node, int& path, int& sum)
    {
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        if(left == NULL && right == NULL)
        {
            path = path * 10 + node->val;
            sum += path;
            path = path / 10;
            return;
        }
        else
        {
            path = path * 10 + node->val;
        
            if(left)
            {
                findPath(left, path, sum);
            }
            if(right)
            {
                findPath(right, path, sum);
            }
            path = path / 10;
            return;
        }
    }
        
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int path = 0;
        int sum = 0;
        
        findPath(root, path, sum);
        
        return sum;
    }
};
