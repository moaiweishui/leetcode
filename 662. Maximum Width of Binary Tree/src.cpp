class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        vector<TreeNode*> nodev;
        vector<int> indexes;
        nodev.push_back(root);
        indexes.push_back(0);
    
        int curr = 0;
        int end = 1;
        int max_width = 0;
        while (curr < nodev.size()){
            end = nodev.size();       
            int min_index = -1;
            int max_index = -1;
            while (curr < end){
                if (min_index == -1 || indexes[curr] < min_index) min_index = indexes[curr];
                if (max_index == -1 || indexes[curr] > max_index) max_index = indexes[curr];

                if (nodev[curr]->left != NULL){
                    nodev.push_back(nodev[curr]->left);
                    indexes.push_back(indexes[curr] * 2 + 1);
                }
                if (nodev[curr]->right != NULL){
                    nodev.push_back(nodev[curr]->right);
                    indexes.push_back(indexes[curr] * 2 + 2);
                }
                curr++;
            }
            if (min_index == -1 || max_index == -1){
                break;
            }
            else{
                int width = max_index - min_index + 1;
                if (width > max_width) max_width = width;
            }
        }
        return max_width;
    }
};
