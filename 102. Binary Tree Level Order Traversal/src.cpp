//////// 88.89% /////////
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        vector<TreeNode*> vec;
        vec.push_back(root);
        int curr = 0;
        int end = vec.size();
        while (curr < vec.size()){
            end = vec.size();
            vector<int> temp_vec;
            while (curr != end){
                //开始这一层节点的遍历
                temp_vec.push_back(vec[curr]->val);
                if (vec[curr]->left != NULL) vec.push_back(vec[curr]->left);
                if (vec[curr]->right != NULL) vec.push_back(vec[curr]->right);
                curr++;
            }
            res.push_back(temp_vec);
        }

        return res;
    }
};

/////////////////////////// 11.87% ///////////////////////////////
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
    if (root == NULL) return res;
    
    queue<TreeNode*> qa, qb;
    qa.push(root);

    TreeNode* node;
    while (!qa.empty()){
        vector<int> temp_vec;
        while (!qa.empty()){
            node = qa.front();
            temp_vec.push_back(node->val);
            if (node->left != NULL) qb.push(node->left);
            if (node->right != NULL) qb.push(node->right);
            qa.pop();
        }
        qa.swap(qb);
        res.push_back(temp_vec);
    }

    return res;
    }
};
