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
    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode*, int> height_map;

    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* pre = NULL;

    while (curr != NULL || !st.empty()){
        while (curr != NULL){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        if (curr->right != NULL && curr->right != pre){
            curr = curr->right;
        }
        else{
            int l_height, r_height;
            if (curr->left == NULL) l_height = 0;
            else l_height = height_map[curr->left];

            if (curr->right == NULL) r_height = 0;
            else r_height = height_map[curr->right];

            if (abs(l_height - r_height) > 1) return false;

            height_map[curr] = max(l_height, r_height) + 1;

            pre = curr;
            curr = NULL;
            st.pop();
        }

    }

    return true;
    }
};
