/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
    if (root == NULL) return res;

    vector<TreeNode*> nodev;
    nodev.push_back(root);
    int curr = 0;
    int next_level_start = 1;

    while (curr < nodev.size()){
        vector<int> tempv;
        next_level_start = nodev.size();
        while (curr < next_level_start){
            if (res.size() % 2 == 0){
                tempv.push_back(nodev[curr]->val);
            }
            else{
                tempv.insert(tempv.begin(), nodev[curr]->val);
            }
            if (nodev[curr]->left != NULL) nodev.push_back(nodev[curr]->left);
            if (nodev[curr]->right != NULL) nodev.push_back(nodev[curr]->right);
            curr++;
        }
        res.push_back(tempv);
    }


    return res;
    }
};
