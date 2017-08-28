/**********************************************************/
// 
//  分别考察每个点的左边/右边/左上三个点，以1为步长进行扩展
//
/**********************************************************/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        if(n == 0)
            return 0;
        
        vector<vector<int>> mem;
        vector<int> rowv(n, 0);
        for(int i = 0; i < m; i++)
            mem.push_back(rowv);
        
        int max = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0)
                {
                    mem[i][j] = matrix[i][j] - 48;
                }
                else if(matrix[i][j] == '1')
                {
                    mem[i][j] = 1 + min(mem[i][j - 1], min(mem[i - 1][j], mem[i - 1][j - 1]));
                }
                if(mem[i][j] > max)
                    max = mem[i][j];
            }
        }
            
        return max*max;
    }
};
