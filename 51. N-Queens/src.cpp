class Solution {
public:
    bool isValid(int row, int col, vector<int>& distribution)
    {
        if(row == 0)
            return true;
        
        for(int i = 0; i < row; i++)
        {
            if(distribution[i] == col)
                return false;
            if(abs(i - row) == abs(distribution[i] - col))
                return false;      
        }
        
        return true;
    }
    
    void solveNQueensWithPos(int n, int row, vector<int>& distribution, vector<vector<string>>& res)
    {
        if(row == n)
        {
            vector<string> temp(n, string(n, '.'));
            for (int i = 0; i < n; i++)
                temp[i][distribution[i]] = 'Q';
            res.push_back(temp);
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(isValid(row, i, distribution))
            {
                distribution[row] = i;
                solveNQueensWithPos(n, row + 1, distribution, res);
                distribution[row] = -1;
            }
        }
    }
        
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        
        vector<int> distribution(n, -1);
        
        solveNQueensWithPos(n, 0, distribution, res);
        
        return res;
    }
};
