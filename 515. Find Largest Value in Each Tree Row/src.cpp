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
    struct Tree{
        TreeNode* node;
        int level;
        Tree(TreeNode* node):node(node), level(NULL){}
    }; 
    
public:
    vector<int> largestValues(TreeNode* root) {
        
        if(!root)
        {
            vector<int> x;
            return x;
        }
        
        queue<Tree*> q;
        vector<Tree*> v;
        Tree* root_node = new Tree(root);
        root_node->level = 1;
        q.push(root_node);
        int deep = 1;
        while(!q.empty())
        {
            v.push_back(q.front());
            if(q.front()->node->left)
            {
                Tree* tmp_node = new Tree(q.front()->node->left);
                tmp_node->level = q.front()->level + 1;
                if(tmp_node->level > deep)
                    deep = tmp_node->level;
                q.push(tmp_node);
            }
            if(q.front()->node->right)
            {
                Tree* tmp_node = new Tree(q.front()->node->right);
                tmp_node->level = q.front()->level + 1;
                if(tmp_node->level > deep)
                    deep = tmp_node->level;
                q.push(tmp_node);
            }
            q.pop();
        }
        
        vector<int> res(deep, 0x80000000);
        
        for(vector<Tree*>::iterator it = v.begin(); it < v.end(); it++)
        {
            if((*it)->node->val > res[(*it)->level - 1])
            {
                res[(*it)->level - 1] = (*it)->node->val;
            }
        }
        
        return res;
        
    }
};
