class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, int num)
    {
        int total_row = board.size();
        int total_col = board[0].size();
        
        for(int i = 0; i < total_col; i++)
        {
            if(i != col && board[row][i] == char(num + 48))
               return false;
        }
        
        for(int i = 0; i < total_row; i++)
        {
            if(i != row && board[i][col] == char(num + 48))
                return false;
        }
        
        int row_group = row / 3;
        int col_group = col / 3;
               
        for(int i = row_group * 3; i < row_group * 3 + 3; i++)
        {
            for(int j = col_group * 3; j < col_group * 3 + 3; j++)
            {
                if(i != row && j != col && board[i][j] == char(num + 48))
                    return false;
            }
        }
               
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() == 0)
            return true;
        else if(board[0].size() == 0)
            return true;
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != '.' && !isValid(board, i, j, int(board[i][j] - 48)))
                    return false;
            }
        }
        return true;
    }
};
