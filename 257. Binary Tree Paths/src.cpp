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
    string int2string(int val)
    {
        stringstream stream;
        string res;
        stream << val;
        stream >> res;
        return res;
    }
    
    void findPath(TreeNode* node, string& path, vector<string>& paths)
    {
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        if(left == NULL && right == NULL)
        {
            int len = path.length();
            path += "->" + int2string(node->val);
            paths.push_back(path.substr(2, path.length() - 2));
            path = path.substr(0, len);
            return;
        }
        else
        {
            int len = path.length();
            path += "->" + int2string(node->val);
            if(left)
                findPath(left, path, paths);
            if(right)
                findPath(right, path, paths);
            path = path.substr(0, len);
        }
        
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root == NULL)
            return paths;
        
        string path;
        findPath(root, path, paths);
        return paths;
    }
};
