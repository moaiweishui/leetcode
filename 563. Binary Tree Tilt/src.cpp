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
    int sumTree(TreeNode* node)
    {
	    if (node)
	    {
		    int res = node->val;
		    res += sumTree(node->left);
		    res += sumTree(node->right);
		    return res;
	    }
	    else
		    return 0;
    }
    
    int nodeTilt(TreeNode* node){
        if(node)
        { 
            return abs(sumTree(node->left) - sumTree(node->right));
        }
        else
        {
            return 0;
        }    
    }
    
    void preOrderTraverse(TreeNode* node, int& sum)
    {
        if(node)
        {
            sum += nodeTilt(node);
            preOrderTraverse(node->left, sum);
            preOrderTraverse(node->right, sum);
        }
        else
            return;
    }
    
    int findTilt(TreeNode* root) {
        int sum = 0;
        preOrderTraverse(root, sum);
        return sum;
    }
};
