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
    TreeNode* sortedSubArrayToBST(vector<int>& nums, int start, int end){
        if (start > end) return NULL;
        int mid_index = (end + start) / 2;
        TreeNode* node = new TreeNode(nums[mid_index]);
        node->left = sortedSubArrayToBST(nums, start, mid_index - 1);
        node->right = sortedSubArrayToBST(nums, mid_index + 1, end);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       if (nums.size() == 0) return NULL;
        else if (nums.size() == 1) return new TreeNode(nums[0]);

        return sortedSubArrayToBST(nums, 0, nums.size() - 1);
    }
};
