class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int m = matrix.size();
        if(m == 0)
            return res;
        int n = matrix[0].size();

        

        
        int len = m + n - 1;
        
        for (int i = 0; i < len; i++)
	    {
		    if (i % 2 == 0)
		    {
			    if (i <= (m - 1))
			    {
				    int r = i;
				    int c = 0;
				    while (r >= 0 && c < n)
				    {
					    res.push_back(matrix[r][c]);
					    r--;
					    c++;
				    }
			    }
			    else
			    {
				    int r = m - 1;
				    int c = i + 1 - m;
				    while (r >= 0 && c < n)
				    {
					    res.push_back(matrix[r][c]);
					    r--;
					    c++;
				    }
			    }
		    }
		    else
		    {
			    if (i <= (n - 1))
			    {
				    int r = 0;
				    int c = i;
				    while (r<m && c>=0)
				    {
					    res.push_back(matrix[r][c]);
					    r++;
					    c--;
				    }
			    }
			    else
			    {
				    int r = i + 1 - n;
				    int c = n - 1;
				    while (r<m && c>=0)
				    {
					    res.push_back(matrix[r][c]);
					    r++;
					    c--;
				    }
			    }
		    }
	    }
        
        return res;
    }
};
