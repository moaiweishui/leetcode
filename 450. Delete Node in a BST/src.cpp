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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* p = root;
        TreeNode* prep = NULL;
        TreeNode* head = root;
        
        while (p)
        {
            if (key == p->val)
            {
                //cout << key << endl;
                if (prep == NULL)
                {
                    if (p->right && p->left)
                    {
                        head = p->right;
                        TreeNode* q = p->right;
                        while (q->left)
                            q = q->left;
                        q->left = p->left;
                    }
                    else if (p->right)
                    {
                        head = p->right;
                    }
                    else if (p->left)
                    {
                        head = p->left;
                    }
                    else
                    {
                        head = NULL;
                    }
                    free(root);
                }
                else
                {
                    if (p->right && p->left)
                    {
                        TreeNode* q = p->right;
                        TreeNode* temp = p->right;
                        while (q->left)
                            q = q->left;
                        q->left = p->left;
                        if (p == prep->left)
                            prep->left = temp;
                        else
                            prep->right = temp;
                    }
                    else if (p->right)
                    {
                        if (p == prep->left)
                            prep->left = p->right;
                        else
                            prep->right = p->right;
                    }
                    else if (p->left)
                    {
                        if (p == prep->left)
                            prep->left = p->left;
                        else
                            prep->right = p->left;
                    }
                    else
                    {
                        if (p == prep->left)
                            prep->left = NULL;
                        else
                            prep->right = NULL;
                    }
                    free(p);
                }
                break;
            }
            else if (key < p->val)
            {
                prep = p;
                p = p->left;
            }
            else
            {
                prep = p;
                p = p->right;
            }
        }
        return head;
    }
};
