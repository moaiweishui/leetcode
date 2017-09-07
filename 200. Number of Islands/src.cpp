class Solution {
public:
    int countTag(vector<vector<int>>& tag)
    {
        int r = tag.size();
        int c = tag[0].size();
        set<int> s;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(tag[i][j])
                    s.insert(tag[i][j]);
        return s.size();
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if(r == 0)
            return 0;
        
        int c = grid[0].size();
        
        if(c == 0)
            return 0;
        
        vector<vector<int>> tag(r, vector<int>(c, 0));
        
        int max = INT_MIN;
        int cnt = 0;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(i == 0 && j == 0)
                {
                    if(grid[i][j] == '1')
                    {
                        tag[i][j] = 1;
                        cnt++;
                    }
                }
                else if(i == 0)
                {
                    if(grid[i][j] == '1' && grid[i][j - 1] != '1')
                    {
                        cnt++;
                        tag[i][j] = cnt;
                    }
                    else if(grid[i][j] == '1' && grid[i][j - 1] == '1')
                    {
                        tag[i][j] = tag[i][j - 1];
                    }
                }
                else if(j == 0)
                {
                    if(grid[i][j] == '1' && grid[i - 1][j] != '1')
                    {
                        cnt++;
                        tag[i][j] = cnt;
                    }
                    else if(grid[i][j] == '1' && grid[i - 1][j] == '1')
                    {
                        tag[i][j] = tag[i - 1][j];
                    }
                }
                else
                {
                    if(grid[i][j] == '1' && grid[i][j - 1] != '1' && grid[i - 1][j] != '1')
                    {
                        cnt++;
                        tag[i][j] = cnt;
                    }
                    else if(grid[i][j] == '1' && grid[i][j - 1] != '1')
                    {
                        tag[i][j] = tag[i - 1][j];
                    }
                    else if(grid[i][j] == '1' && grid[i - 1][j] != '1')
                    {
                        tag[i][j] = tag[i][j - 1];
                    }
                    else if(grid[i][j] == '1')
                    {
                        if(tag[i - 1][j] != tag[i][j - 1])
                        {
                            int tmp = tag[i - 1][j];
                            tag[i][j] = tmp;
                            for(int k = 0; k < r; k++)
                                for(int s = 0; s < c; s++)
                                    if(tag[k][s] == tag[i][j - 1])
                                        tag[k][s] = tmp;
                        }
                        else
                        {
                            tag[i][j] = tag[i][j - 1];
                        }
                    }
                }
            }
        }
        
        return countTag(tag);
    }
};
