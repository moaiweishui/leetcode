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
    struct Tree{
        TreeNode* node;
        int level;
        Tree(TreeNode* node) : node(node), level(NULL) {}
    };
    
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        Tree* root_node = new Tree(root);
        root_node->level = 1;
        int depth = 1;
        queue<Tree*> q;
        q.push(root_node);
        while(!q.empty())
        {
            if(q.front()->node->left)
            {
                Tree* tmp = new Tree(q.front()->node->left);
                tmp->level = q.front()->level + 1;
                if(depth < tmp->level)
                    depth = tmp->level;
                q.push(tmp);
            }
            if(q.front()->node->right)
            {
                Tree* tmp = new Tree(q.front()->node->right);
                tmp->level = q.front()->level + 1;
                if(depth < tmp->level)
                    depth = tmp->level;
                q.push(tmp);
            }
            q.pop();
        }
        return depth;
    }
};
