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
    void inOrderTraverse(TreeNode* node, vector<int>& v)
    {
        if(node)
        {
            inOrderTraverse(node->left, v);
            v.push_back(node->val);
            inOrderTraverse(node->right, v);
        }
        else
            return;
    }
    
    int getMinimumDifference(TreeNode* root) {
        int res = 0x7FFFFFFF;
        
        vector<int> v;
        inOrderTraverse(root, v);
        
        for(int i = 0; i < v.size() - 1; i ++)
        {
            if((v[i + 1] - v[i])<res)
                res = v[i + 1] - v[i];
        }
        return res;
    }
};
