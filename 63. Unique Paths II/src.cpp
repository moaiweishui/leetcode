class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        if(r == 0)
            return 0;
        int c = obstacleGrid[0].size();
        if(c == 0)
            return 0;
        
        vector<vector<int>> mem(r, vector<int>(c, 0));
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(i == 0 && j == 0)
                    mem[i][j] = 1 - obstacleGrid[i][j];
                else
                {
                    if(obstacleGrid[i][j] == 1)
                        mem[i][j] = 0;
                    else if(i == 0)
                        mem[i][j] = mem[i][j - 1];
                    else if(j == 0)
                        mem[i][j] = mem[i - 1][j];
                    else
                        mem[i][j] = mem[i][j - 1] + mem[i - 1][j];
                }  
            }
        }
        
        return mem[r-1][c-1];
        
    }
};
