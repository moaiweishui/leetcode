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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 0;
        
        vector<TreeNode*> nodev;
        nodev.push_back(root);
        int curr = 0;
        int next_level_start = 1;
        while(curr < nodev.size()){
            next_level_start = nodev.size();
            while(curr < next_level_start){
                if(nodev[curr]->left != NULL) nodev.push_back(nodev[curr]->left);
                if(nodev[curr]->right != NULL) nodev.push_back(nodev[curr]->right);
                curr++;
            }
            depth++;
        }
        return depth;
    }
};
