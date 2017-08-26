class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int depth = triangle.size();
        
        if(depth == 1)
            return triangle[0][0];
        
        vector<int> rowv(depth, 0);
        vector<vector<int>> mem;
        
        for(int i = 0; i < depth; i++)
            mem.push_back(rowv);
        
        mem[0][0] = triangle[0][0];
        
        for(int i = 1; i < depth; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0)
                {
                    mem[i][j] = triangle[i][j] + mem[i - 1][0];
                }
                else if(j == i)
                {
                    mem[i][j] = triangle[i][j] + mem[i - 1][j - 1];
                }
                else
                {
                    mem[i][j] = triangle[i][j] + min(mem[i - 1][j - 1], mem[i - 1][j]);
                }
            }
        }
        
        int min = 0x7FFFFFFF;
        
        for(int i = 0; i < depth; i++)
        {
            if(mem[depth - 1][i] < min)
                min = mem[depth - 1][i];
        }
        return min;
    }
};
