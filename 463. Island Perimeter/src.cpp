class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        int res = 0;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(i == 0 && j == 0)
                    {
                        res += 4;
                    }
                    else if(i == 0)
                    {
                        if(grid[i][j-1] == 1)
                            res += 2;
                        else
                            res += 4;
                    }
                    else if(j == 0)
                    {
                        if(grid[i-1][j] == 1)
                            res += 2;
                        else
                            res += 4;
                    }
                    else
                    {
                        if(grid[i-1][j] == 1 && grid[i][j-1] == 1)
                            res += 0;
                        else if(grid[i-1][j] == 1)
                            res += 2;
                        else if(grid[i][j-1] == 1)
                            res += 2;
                        else
                            res += 4;
                    }
                        
                }
            }
        }
        return res;
    }
};
