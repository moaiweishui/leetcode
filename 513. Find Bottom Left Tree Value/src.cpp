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
        Tree(TreeNode* node):node(node), level(NULL){}
    };
    
    int findBottomLeftValue(TreeNode* root) {
        queue<Tree*> q;
        vector<Tree*> v;
        Tree* tree = new Tree(root);
        tree->level = 1;
        int deep = 1;
        q.push(tree);
        while(!q.empty())
        {
            v.push_back(q.front());
            if(q.front()->node->left)
            {
                Tree* tmp = new Tree(q.front()->node->left);
                tmp->level = q.front()->level + 1;
                if(tmp->level>deep)
                    deep = tmp->level;
                q.push(tmp);
            }
            if(q.front()->node->right)
            {
                Tree* tmp = new Tree(q.front()->node->right);
                tmp->level = q.front()->level + 1;
                if(tmp->level>deep)
                    deep = tmp->level;
                q.push(tmp);
            }
            q.pop();
        }
        for(int i = 0;i<v.size();i++)
        {
            if(v[i]->level == deep)
                return v[i]->node->val;
        }
        return 0;
    }
};
