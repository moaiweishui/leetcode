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
    vector<TreeNode*> searchPath(TreeNode* root, TreeNode* target)
    {
        vector<TreeNode*> path;
        TreeNode* p = root;
        
        //path.push_back(p);
        
        while(p != NULL)
        {
            path.push_back(p);
            if(p == target)
                break;
            else if(target->val > p->val)
                p = p->right;
            else if(target->val < p->val)
                p = p->left;
        }
        return path;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp = searchPath(root, p);
        vector<TreeNode*> pathq = searchPath(root, q);
        
        int lenp = pathp.size();
        int lenq = pathq.size();
        
        TreeNode* last_same = root;
        
        int len = min(lenp, lenq);
        
        int cnt = 0;
        while(cnt < len)
        {
            if(pathp[cnt] == pathq[cnt])
                last_same = pathp[cnt];
            else
                break;
            cnt++;
        }
        
        return last_same;
    }
};
