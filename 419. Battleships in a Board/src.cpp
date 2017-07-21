class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int r = board.size();
	    int c = board[0].size();
        
        vector<vector<int>> _board;
        
        for (int i = 0; i < r; i++)
	    {
		    vector<int> _vec(c, 0);
		    _board.push_back(_vec);
	    }
        
        for (int i = 0; i < r; i++)
	    {
		    for (int j = 0; j < c; j++)
		    {
			    if (board[i][j] == 'X')
				    _board[i][j] = -1;
			    else
				    _board[i][j] = 0;
		    }
	    }
        
        int color = 1;
        int res = 0;
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(_board[i][j] == -1)
                    if(i == 0 && j == 0)
                    {
                        _board[i][j] = color;
					    color++;
                    }
                    else if(i == 0)
                    {
                		if (_board[i][j - 1] != 0)
					    {
						    _board[i][j] = _board[i][j - 1];
					    }
					    else
					    {
						    _board[i][j] = color;
						    color++;
					    }
                    }
                    else if(j == 0)
                    {
                        if (_board[i - 1][j] != 0)
					    {
						    _board[i][j] = _board[i - 1][j];
					    }
					    else
					    {
						    _board[i][j] = color;
						    color++;
					    }
                    }
                    else
                    {
                        if (_board[i][j - 1] != 0)
					    {
						    _board[i][j] = _board[i][j - 1];
					    }
					    else if (_board[i - 1][j] != 0)
					    {
						    _board[i][j] = _board[i - 1][j];
					    }
					    else
					    {
						    _board[i][j] = color;
						    color++;
					    }
                    }
        return color-1;
    }
};
