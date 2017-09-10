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
    void findPath(TreeNode* node, int& mem, int& target, bool& flag)
    {
        if(flag)
            return;
        
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        
        if(left == NULL & right == NULL)
        {
            mem += node->val;
            if(mem == target)
                flag = true;
            mem = mem - node->val;
            return;
        }
        else
        {
            mem += node->val;
            if(left)
                findPath(left, mem, target, flag);
            if(right)
                findPath(right, mem, target, flag);
            mem = mem - node->val;
        }
        
        
            
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        
        bool flag = false;
        
        int mem = 0;
        
        findPath(root, mem, sum, flag);
        
        return flag;
    }
};
