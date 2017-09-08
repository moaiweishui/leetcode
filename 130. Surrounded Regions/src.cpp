class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        if(r == 0)
            return;
        int c = board[0].size();
        if(c == 0)
            return;
        
        vector<vector<int>> tag(r, vector<int>(c, 0));
        
        int cnt = 1;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(board[i][j] == 'O')
                {
                    if(i == 0 && j == 0)
                    {
                        tag[i][j] = cnt;
                        cnt++;
                    }
                    else if(i == 0)
                    {
                        if(board[i][j - 1] == 'O')
                        {
                            tag[i][j] = tag[i][j - 1];
                        }
                        else
                        {
                            tag[i][j] = cnt;
                            cnt++;
                        }
                    }
                    else if(j == 0)
                    {
                        if(board[i - 1][j] == 'O')
                        {
                            tag[i][j] = tag[i - 1][j];
                        }
                        else
                        {
                            tag[i][j] = cnt;
                            cnt++;
                        }
                    }
                    else
                    {
                        if(board[i][j - 1] == 'O' && board[i - 1][j] == 'O')
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
                        else if(board[i][j - 1] == 'O')
                        {
                            tag[i][j] = tag[i][j - 1];
                        }
                        else if(board[i - 1][j] == 'O')
                        {
                            tag[i][j] = tag[i - 1][j];
                        }
                        else
                        {
                            tag[i][j] = cnt;
                            cnt++;
                        }
                    }
                }
            }
        }
        set<int> tagSet;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(tag[i][j] != 0 && (i == 0 || j == 0 || i == r - 1 || j == c - 1))
                    tagSet.insert(tag[i][j]);
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(tag[i][j] != 0 && tagSet.count(tag[i][j]) == 0)
                {
                    board[i][j] = 'X';
                }
        
        
        return;
    }
};
