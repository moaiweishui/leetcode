class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        if(root->left == NULL) return minDepth(root->right) + 1;
        if(root->right == NULL) return minDepth(root->left) + 1;
        
        int left_h = minDepth(root->left);
        int right_h = minDepth(root->right);
        return min(left_h + 1, right_h + 1);   
    }
};
