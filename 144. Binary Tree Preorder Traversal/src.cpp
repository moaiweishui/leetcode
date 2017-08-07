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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> treeStack;
        TreeNode* p = root;
        vector<int> res;
        while(p || !treeStack.empty())
        {
            if(p)
            {
                treeStack.push(p);
                res.push_back(p->val);
                p = p->left;
            }
            else
            {
                p = treeStack.top();
                treeStack.pop();
                p = p->right;
            }        
        }
        return res;
        
    }
};
