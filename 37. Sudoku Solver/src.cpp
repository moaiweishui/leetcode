/*********************** Solution 1 **************************/
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
    
    
    void solveSudokuWithPos(vector<vector<char>>& board, int row, int col, bool& find_flag)
    {
        if(row == board.size() - 1 && col == board[0].size())
        {
            find_flag = true;
            return;
        }
        
        if(board[row][col] != '.')
        {
            int next_row = row;
            int next_col = col + 1;
            if(next_col == board[0].size() && next_row != board.size() - 1)
            {
                next_row = row + 1;
                next_col = 0;
            }
            solveSudokuWithPos(board, next_row, next_col, find_flag);
        }
        else
        {
            for(int i = 1; i <= 9;i++)
            {
                if(isValid(board, row, col, i))
                {
                    board[row][col] = char(i + 48);
                    int next_row = row;
                    int next_col = col + 1;
                    if(next_col == board[0].size() && next_row != board.size() - 1)
                    {
                        next_row = row + 1;
                        next_col = 0;
                    }
                    solveSudokuWithPos(board, next_row, next_col, find_flag);
                    if(!find_flag)
                        board[row][col] = '.';
                }
            }
        }
        
            
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        else if(board[0].size() == 0)
            return;
        
        bool find_falg = false;
        solveSudokuWithPos(board, 0, 0, find_falg);
        return;
    }
};

/*********************** Solution 2 **************************/
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
    
    
    void solveSudokuWithPos(vector<vector<char>>& board, int row, int col, bool& find_flag, vector<vector<vector<int>>>& nums)
    {
        if(row == board.size() - 1 && col == board[0].size())
        {
            find_flag = true;
            return;
        }
        
        if(board[row][col] != '.')
        {
            int next_row = row;
            int next_col = col + 1;
            if(next_col == board[0].size() && next_row != board.size() - 1)
            {
                next_row = row + 1;
                next_col = 0;
            }
            solveSudokuWithPos(board, next_row, next_col, find_flag, nums);
        }
        else
        {
            for(auto it = nums[row][col].begin(); it != nums[row][col].end(); it++)
            {
                if(isValid(board, row, col, *it))
                {
                    board[row][col] = char(*it + 48);
                    int next_row = row;
                    int next_col = col + 1;
                    if(next_col == board[0].size() && next_row != board.size() - 1)
                    {
                        next_row = row + 1;
                        next_col = 0;
                    }
                    solveSudokuWithPos(board, next_row, next_col, find_flag, nums);
                    if(!find_flag)
                        board[row][col] = '.';
                }
            }
        }
        
            
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        else if(board[0].size() == 0)
            return;
        
        vector<int> v;
        vector<vector<int>> vv(board[0].size(), v);
        vector<vector<vector<int>>> nums(board.size(), vv);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (isValid(board, i, j, k))
                            nums[i][j].push_back(k);
                    }
                }
            }
        }
        
        bool find_falg = false;
        solveSudokuWithPos(board, 0, 0, find_falg, nums);
        return;
    }
};

