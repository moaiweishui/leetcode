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
    void inOrder(TreeNode* node, vector<int>& nums)
    {
        if(node)
        {
            inOrder(node->left, nums);
            nums.push_back(node->val);
            inOrder(node->right, nums);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        inOrder(root, nums);
        return nums;
    }
};
