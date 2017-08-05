class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        for(int i = 0; i < matrix.size(); i++)
        {
            v.insert(v.end(), matrix[i].begin(), matrix[i].end());
        }
        sort(v.begin(), v.end());
        
        int res;
        
        return v[k-1];
    }
};
