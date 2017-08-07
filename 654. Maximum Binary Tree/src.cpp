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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())
		    return NULL;
        
        int max = 0x80000000;
	    int pos = -1;

	    for (int i = 0; i < nums.size(); i++)
	    {
		    if (nums[i] > max)
		    {
			    max = nums[i];
			    pos = i;
		    }
	    }
        
        TreeNode* tmp_root = new TreeNode(max);
        
        vector<int> left_nums;
	    vector<int> right_nums;
	    left_nums.assign(nums.begin(), nums.begin() + pos);
	    right_nums.assign(nums.begin() + pos + 1, nums.end());

	    tmp_root->left = constructMaximumBinaryTree(left_nums);
	    tmp_root->right = constructMaximumBinaryTree(right_nums);

	    return tmp_root;
        
    }
};
