/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeLinkNodeWithLevel{
        TreeLinkNode* node;
        int level;
        TreeLinkNodeWithLevel(TreeLinkNode* node) : node(node), level(NULL) {}
    };
    
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        TreeLinkNodeWithLevel* root_node = new TreeLinkNodeWithLevel(root);
        root_node->level = 1;

        queue<TreeLinkNodeWithLevel*> q;
        q.push(root_node);

        TreeLinkNodeWithLevel* last_node = NULL;
        
        while (!q.empty())
        {
            cout << q.front()->node->val << endl;

            if (last_node != NULL)
            {
                if (last_node->level == q.front()->level)
                    last_node->node->next = q.front()->node;
            }

            if (q.front()->node->left)
            {
                TreeLinkNodeWithLevel* tmp = new TreeLinkNodeWithLevel(q.front()->node->left);
                tmp->level = q.front()->level + 1;
                q.push(tmp);
            }
            if (q.front()->node->right)
            {
                TreeLinkNodeWithLevel* tmp = new TreeLinkNodeWithLevel(q.front()->node->right);
                tmp->level = q.front()->level + 1;
                q.push(tmp);
            }
            last_node = q.front();
            q.pop();
        }
    }
};
