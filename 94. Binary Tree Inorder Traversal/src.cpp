/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*********************** Solution 1 ***********************/
class Solution {
public:
    void inOrder(TreeNode* node, vector<int>& nums)
    {
        if(node)
        {
            inOrder(node->left, nums);
            nums.push_back(node->val);
            inOrder(node->right, nums);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        inOrder(root, nums);
        return nums;
    }
};

/*********************** Solution 2 ***********************/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodev;
        if(root == NULL)
            return nodev;
        
        stack<TreeNode*> st;
        
        TreeNode* p = root;
        
        while(!st.empty() || p )
        {
            while(p)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            nodev.push_back(p->val);
            p = p->right;            
        }
        
        
        
        return nodev;
    }
};
