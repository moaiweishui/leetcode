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
	    Tree(TreeNode* node) :node(node), level(NULL){}
    };
    
    vector<double> averageOfLevels(TreeNode* root) {
        queue<Tree*> tree_q;
        vector<Tree*> tree_v;
        Tree* root_node = new Tree(root);
	    root_node->level = 1;
	    tree_q.push(root_node);
        int deep = 1;
        
        while(!tree_q.empty())
        {
            tree_v.push_back(tree_q.front());
            if (tree_q.front()->node->left)
            {
                Tree* tmp = new Tree(tree_q.front()->node->left);
                tmp->level = tree_q.front()->level + 1;
                if(tmp->level > deep)
                    deep = tmp->level;
                tree_q.push(tmp);
            }
            if (tree_q.front()->node->right)
            {
                Tree* tmp = new Tree(tree_q.front()->node->right);
                tmp->level = tree_q.front()->level + 1;
                if(tmp->level > deep)
                    deep = tmp->level;
                tree_q.push(tmp);
            }
            tree_q.pop();
        }
        
        vector<double> res;
        vector<Tree*>::iterator it;
        vector<double> a(deep, 0);
	    vector<int> b(deep, 0);
        
        for (it = tree_v.begin(); it < tree_v.end(); it++)
        {
            a[(*it)->level - 1] += (*it)->node->val;
            b[(*it)->level - 1] += 1;
        }
        for (int i = 0; i < deep; i++)
	    {
		    res.push_back(a[i] / b[i]);
	    }
        return res;
    }
};
