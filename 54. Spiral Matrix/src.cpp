#define RIGHT 1
#define DOWN 2 
#define LEFT 3
#define UP 4

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0)
            return res;
        int n = matrix[0].size();        
        if(n == 0)
            return res;
        
        vector<vector<int>> ref;

	    vector<int> tmpv(n, 0);
	    for (int i = 0; i < m; i++)	
		    ref.push_back(tmpv);
        
        pair<int, int> current_pos(0, 0);
	    pair<int, int> end_pos;
        
        int cnt = 0;
	    int ori = RIGHT;
	    int r, c;      
        
        while (cnt < m*n)
	    {
		    switch (ori)
		    {
		    case RIGHT:
			    res.push_back(matrix[current_pos.first][current_pos.second]);
			    ref[current_pos.first][current_pos.second] = 1;
			    cnt++;
			    r = current_pos.first;
			    c = current_pos.second + 1;
			    if (r >= 0 && r < m && c >= 0 && c < n && ref[r][c] == 0)
			    {
				    current_pos.first = r;
				    current_pos.second = c;
			    }
			    else
			    {
				    current_pos.first = r + 1;
				    current_pos.second = c - 1;
				    ori = DOWN;
			    }
			    break;

		    case DOWN:
			    res.push_back(matrix[current_pos.first][current_pos.second]);
			    ref[current_pos.first][current_pos.second] = 1;
			    cnt++;
			    r = current_pos.first + 1;
			    c = current_pos.second;
			    if (r >= 0 && r < m && c >= 0 && c < n && ref[r][c] == 0)
			    {
				    current_pos.first = r;
				    current_pos.second = c;
			    }
			    else
			    {
				    current_pos.first = r - 1;
				    current_pos.second = c - 1;
				    ori = LEFT;
			    }
			    break;

		    case LEFT:
			    res.push_back(matrix[current_pos.first][current_pos.second]);
			    ref[current_pos.first][current_pos.second] = 1;
			    cnt++;
			    r = current_pos.first;
			    c = current_pos.second - 1;
			    if (r >= 0 && r < m && c >= 0 && c < n && ref[r][c] == 0)
			    {
				    current_pos.first = r;
				    current_pos.second = c;
			    }
			    else
			    {
				    current_pos.first = r - 1;
				    current_pos.second = c + 1;
				    ori = UP;
			    }
			    break;

		    case UP:
			    res.push_back(matrix[current_pos.first][current_pos.second]);
			    ref[current_pos.first][current_pos.second] = 1;
			    cnt++;
			    r = current_pos.first - 1;
			    c = current_pos.second;
			    if (r >= 0 && r < m && c >= 0 && c < n && ref[r][c] == 0)
			    {
				    current_pos.first = r;
				    current_pos.second = c;
			    }
			    else
			    {
				    current_pos.first = r + 1;
				    current_pos.second = c + 1;
				    ori = RIGHT;
			    }
			    break;

		    default:
			    break;
		    }
	    }
        
        return res;
        
    }
};
