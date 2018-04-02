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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        vector<TreeNode*> vec;
        vec.push_back(root);
        int curr = 0;
        int end;
        while(curr < vec.size()){
            end = vec.size();
            vector<int> temp_vec;
            while(curr < end){
                temp_vec.push_back(vec[curr]->val);
                if(vec[curr]->left != NULL) vec.push_back(vec[curr]->left);
                if(vec[curr]->right != NULL) vec.push_back(vec[curr]->right);
                curr++;
            }
            res.insert(res.begin(), temp_vec);
        }
        return res;
    }
};
