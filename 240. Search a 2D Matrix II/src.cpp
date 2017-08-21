/**************** Solution 1 ******************/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        int x = c; 
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < x; j++)
            {
                if(matrix[i][j] == target)
                    return true;
                else if(matrix[i][j] > target)
                {
                    if(j == 0)
                        return false;
                    x = j;
                    int k;
                    for(k = i; k < r; k++)
                    {
                        if(matrix[k][j - 1] == target)
                            return true;
                        else if(matrix[k][j - 1] > target)
                        {
                            i = k - 1; 
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        return false;
            
    }
};
