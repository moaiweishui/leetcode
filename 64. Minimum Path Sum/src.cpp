class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        if(n == 0)
            return 0;
        
        vector<vector<int>> mem(m, vector<int>(n, 0));
        
        mem[0][0] = grid[0][0];
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                    mem[i][j] = grid[0][0];
                else if(i == 0)
                {
                    mem[i][j] = mem[i][j - 1] + grid[i][j];
                }
                else if(j == 0)
                {
                    mem[i][j] = mem[i - 1][j] + grid[i][j];
                }
                else
                {
                    mem[i][j] = min(mem[i - 1][j], mem[i][j - 1]) + grid[i][j];
                }
            }
        }
        
        return mem[m - 1][n - 1];
    }
};
