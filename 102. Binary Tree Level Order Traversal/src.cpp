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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        
        TreeNodeWithLevel* n0 = new TreeNodeWithLevel(root);
	    n0->level = 1;

	    queue<TreeNodeWithLevel*> q;

	    q.push(n0);
        
        int last_level = 1;
	    vector<int> tmp;
        
        while (!q.empty())
	    {
		    cout << q.front()->node->val <<'-'<< q.front()->level<<endl;

		    if (q.front()->level == last_level)
		    {
			    tmp.push_back(q.front()->node->val);
		    }
		    else
		    {
			    res.push_back(tmp);
			    tmp.clear();
			    tmp.push_back(q.front()->node->val);
			    last_level = q.front()->level;
		    }

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
	    res.push_back(tmp);
        return res;
    }
};
