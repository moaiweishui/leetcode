class Solution {
public:
    int maxSinglePathSum(TreeNode* node, int& max_val){
        if (node == NULL) return 0;
        int left = max(0, maxSinglePathSum(node->left, max_val));
        int right = max(0, maxSinglePathSum(node->right, max_val));
        int val = left + right + node->val;
        if (val > max_val) max_val = val;
        return max(left, right) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        int max_val = INT_MIN;
        maxSinglePathSum(root, max_val);
        return max_val;
    }
};
