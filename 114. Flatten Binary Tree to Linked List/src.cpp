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
    void merge(TreeNode* node){
    if (node->left == NULL) return;
    if (node->right == NULL){
        node->right = node->left;
        node->left = NULL;
        return;
    }

    TreeNode* p = node->left;
    while (p->right != NULL){
        p = p->right;
    }

    p->right = node->right;
    node->right = node->left;
    node->left = NULL;

    return;
}
    
    void flatten(TreeNode* root) {
        if (root == NULL) return;

    flatten(root->left);
    flatten(root->right);

    merge(root);
    root->left = NULL;
    }
};
