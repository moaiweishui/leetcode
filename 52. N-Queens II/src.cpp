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
    
    void totalNQueensWithPos(int n, int row, vector<int>& distribution, int& res)
    {
        if(row == n)
        {
            res ++;
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(isValid(row, i, distribution))
            {
                distribution[row] = i;
                totalNQueensWithPos(n, row+1, distribution, res);
                distribution[row] = -1;
            }
        }
        
        return;
    }
    
    int totalNQueens(int n) {
        int res = 0;
        
        vector<int> distribution(n, -1);
        
        totalNQueensWithPos(n, 0, distribution, res);
        
        return res;
    }
};
