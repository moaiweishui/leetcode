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
    struct TreeNodeWithLevel{
	    TreeNode* node;
	    int level;
	    TreeNodeWithLevel(TreeNode* node) :node(node), level(NULL){}
    };
    
    int minDepth(TreeNode* root) {
        
        if(!root)
            return 0;
        
        TreeNodeWithLevel* n0 = new TreeNodeWithLevel(root);
	    n0->level = 1;

	    queue<TreeNodeWithLevel*> q;

	    q.push(n0);
        
        int last_level = 1;
        int min_depth = 0x7FFFFFFF;
        
        while (!q.empty())
	    {
		    if (q.front()->node->left == NULL && q.front()->node->right == NULL && q.front()->level < min_depth)
			    min_depth = q.front()->level;

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
		    q.pop();
	    }
	    return min_depth;
    }
};
