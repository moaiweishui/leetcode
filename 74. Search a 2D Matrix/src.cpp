class Solution {
public:
    bool searchMatrixWithPos(vector<vector<int>>& matrix, int target, int start_r, int end_r)
    {
        if (end_r < 0 || start_r >= matrix.size() || end_r < start_r)
            return false;
        
        if(start_r == end_r)
        {
            set<int> s(matrix[start_r].begin(), matrix[end_r].end());
            if(s.count(target) != 0)
                return true;
            else
                return false;
        }
        else
        {
            int mid = (start_r + end_r) / 2;
            if(matrix[mid][0] > target)
                return searchMatrixWithPos(matrix, target, start_r, mid - 1);
            else if(matrix[mid][matrix[0].size()-1] < target)
                return searchMatrixWithPos(matrix, target, mid + 1, end_r);
            else
                return searchMatrixWithPos(matrix, target, mid, mid);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        if(matrix[0].size() == 0)
            return false;

        return searchMatrixWithPos(matrix, target, 0, matrix.size() - 1);
    }
};
