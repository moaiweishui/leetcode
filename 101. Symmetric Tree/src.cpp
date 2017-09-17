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
    struct TreeNodeWithLevel {
        int level;
        TreeNode *node;
        TreeNodeWithLevel(TreeNode* node) : node(node), level(NULL) {}
    };
    
    bool checkSymmetric(vector<TreeNodeWithLevel*> vec)
    {
        int len = vec.size();
        if (len == 0 || len == 1)
            return true;

        for (int i = 0; i < len / 2; i++)
        {
            if (vec[i]->node == NULL && vec[len - i - 1]->node == NULL)
            {
                ;;
            }
            else if (vec[i]->node == NULL && vec[len - i - 1]->node != NULL)
            {
                return false;
            }
            else if (vec[i]->node != NULL && vec[len - i - 1]->node == NULL)
            {
                return false;
            }
            else
            {
                if (vec[i]->node->val != vec[len - i - 1]->node->val)
                    return false;
            }
        }

        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        TreeNodeWithLevel* rootnode = new TreeNodeWithLevel(root);
        rootnode->level = 1;
    
        queue<TreeNodeWithLevel*> q;
        q.push(rootnode);

        TreeNodeWithLevel* curr_node = NULL;
        TreeNodeWithLevel* temp_node = NULL;

        vector<TreeNodeWithLevel*> levelVec;

        int last_level = 0;

        while (!q.empty())
        {
            curr_node = q.front();
            if (curr_node->node == NULL)
            {
                //cout << "NULL" << '-' << curr_node->level << endl;
                ;;
            }
            else
            {
                //cout << curr_node->node->val <<'-'<<curr_node->level<< endl;

                temp_node = new TreeNodeWithLevel(curr_node->node->left);
                temp_node->level = curr_node->level + 1;
                q.push(temp_node);

                temp_node = new TreeNodeWithLevel(curr_node->node->right);
                temp_node->level = curr_node->level + 1;
                q.push(temp_node);
            }
            q.pop();
            if (curr_node->level != last_level)
            {
                if (checkSymmetric(levelVec))
                {
                    levelVec.clear();
                    last_level = curr_node->level;
                    levelVec.push_back(curr_node);
                }
                else
                {
                    return false;
                }
            }   
            else
            {
                levelVec.push_back(curr_node);
            }
        }

        return true;
    }
};
