#define RIGHT 1
#define DOWN 2 
#define LEFT 3
#define UP 4
class Solution {

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(n == 0)
            return res;
	    vector<int> tmpv(n, 0);
	    for (int i = 0; i < n; i++)	
		    res.push_back(tmpv);

	    pair<int, int> current_pos(0, 0);
	    pair<int, int> end_pos;

	    if (n % 2 == 0)
	    {
		    end_pos.first = n / 2;
		    end_pos.second = n / 2 - 1;
	    }
	    else
	    {
		    end_pos.first = n / 2;
		    end_pos.second = n / 2;
	    }
        
        int ori = RIGHT;
	    int cnt = 1;
	    int r;
	    int c;
        
        while (current_pos != end_pos)
	    {
		    switch (ori){
			    case RIGHT:
				    res[current_pos.first][current_pos.second] = cnt;
				    cnt++;
				    r = current_pos.first;
				    c = current_pos.second + 1;
				    if (r >= 0 && r < n && c >= 0 && c < n && res[r][c] == 0)
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
				    res[current_pos.first][current_pos.second] = cnt;
				    cnt++;
				    r = current_pos.first + 1;
				    c = current_pos.second;
				    if (r >= 0 && r < n && c >= 0 && c < n && res[r][c] == 0)
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
				    res[current_pos.first][current_pos.second] = cnt;
				    cnt++;
				    r = current_pos.first;
				    c = current_pos.second - 1;
				    if (r >= 0 && r < n && c >= 0 && c < n && res[r][c] == 0)
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
				    res[current_pos.first][current_pos.second] = cnt;
				    cnt++;
				    r = current_pos.first - 1;
				    c = current_pos.second;
				    if (r >= 0 && r < n && c >= 0 && c < n && res[r][c] == 0)
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
	    res[current_pos.first][current_pos.second] = cnt;
        
        return res;
              
    }
};
