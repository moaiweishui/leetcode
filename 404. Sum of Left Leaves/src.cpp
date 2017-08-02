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
    void displayLeaves(TreeNode* node, int& sum, int flag)//left:1  right:2
    {
        if(node)
        {
            if(node->left == NULL && node->right == NULL)
                if(flag == 1)
                {
                    sum += node->val;
                }
            displayLeaves(node->left, sum, 1);
		    displayLeaves(node->right, sum, 2);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        displayLeaves(root, sum, 0);
        return sum;
    }
};
