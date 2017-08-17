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
    struct TreeNodeWithLevel {
        TreeNode *node;
        int level;
        TreeNodeWithLevel(TreeNode *node) : node(node), level(NULL) {}
    };
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        TreeNodeWithLevel* root_node = new TreeNodeWithLevel(root);
        root_node->level = 1;
        
        queue<TreeNodeWithLevel*> q;
        q.push(root_node);
        
        
        TreeNodeWithLevel* last_node = NULL;
        
        while(!q.empty())
        {
            if(last_node != NULL && last_node->level != q.front()->level)
                res.push_back(last_node->node->val);
            
            if (q.front()->node->left)
            {
                TreeNodeWithLevel* tmp = new TreeNodeWithLevel(q.front()->node->left);
                tmp->level = q.front()->level + 1;
                q.push(tmp);
            }
            if (q.front()->node->right)
            {
                TreeNodeWithLevel* tmp = new TreeNodeWithLevel(q.front()->node->right);
                tmp->level = q.front()->level + 1;
                q.push(tmp);
            }
            
            last_node = q.front();
            q.pop();
            if(q.empty())
                res.push_back(last_node->node->val);
        }
        
        return res;
    }
};
