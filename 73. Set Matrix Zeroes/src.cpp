class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        if(r == 0)
            return;
        int c = matrix[0].size();
        if(c == 0)
            return;
        
        set<int> row_index;
        set<int> col_index;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row_index.insert(i);
                    col_index.insert(j);
                }
            }
        }
        
        for(auto it = row_index.begin(); it != row_index.end(); it++)
        {
            for(int i = 0; i < c; i++)
                matrix[*it][i] = 0;
        }
        for(auto it = col_index.begin(); it != col_index.end(); it++)
        {
            for(int i = 0; i < r; i++)
                matrix[i][*it] = 0;
        }
        return;
    }
};
