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
    void DFS(vector<vector<int>>& paths, vector<int>& path, vector<TreeNode*>& mem,
        TreeNode* node, int& curr_sum, int target){

        if (node->left == NULL && node->right == NULL){
            if (curr_sum == target){
                paths.push_back(path);
            }
            return;
        }

        if (node->left != NULL){
            path.push_back(node->left->val);
            mem.push_back(node->left);
            curr_sum += node->left->val;
            DFS(paths, path, mem, node->left, curr_sum, target);
            curr_sum -= node->left->val;
            mem.pop_back();
            path.pop_back();
        }

        if (node->right != NULL){
            path.push_back(node->right->val);
            mem.push_back(node->right);
            curr_sum += node->right->val;
            DFS(paths, path, mem, node->right, curr_sum, target);
            curr_sum -= node->right->val;
            mem.pop_back();
            path.pop_back();
        }

    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        
        if(root == NULL) return paths;
        
        vector<TreeNode*> mem;;
        vector<int> path;

        int curr_sum = 0;

        mem.push_back(root);
        path.push_back(root->val);
        curr_sum += root->val;
        DFS(paths, path, mem, root, curr_sum, sum);

        return paths;
    }
};
