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
    void exchangeNode(TreeNode* node1, TreeNode* node2)
    {
	    TreeNode* tmp = new TreeNode(node1->val);
	    tmp->left = node1->left;
	    tmp->right = node1->right;

	    node1->val = node2->val;
	    node1->left = node2->left;
	    node1->right = node2->right;

	    node2->val = tmp->val;
	    node2->left = tmp->left;
	    node2->right = tmp->right;
    }
    
    
    TreeNode* invertTree(TreeNode* root) {      
        
        if(!root)
            return root;
        
        if (root->left && root->right)
	    {
		    exchangeNode(root->left, root->right);
		    invertTree(root->left);
		    invertTree(root->right);
	    }
	    else if (root->left)
	    {
		    root->right = new TreeNode(root->left->val);
		    root->right->left = root->left->left;
		    root->right->right = root->left->right;
		    root->left = NULL; 
		    invertTree(root->right);
	    }
	    else if (root->right)
	    {
		    root->left = new TreeNode(root->right->val);
		    root->left->left = root->right->left;
		    root->left->right = root->right->right;
		    root->right = NULL;
		    invertTree(root->left);
	    }
	    return root;
    }
};
