class Solution {
public:
    
    void cmn(int m, int n, vector<vector<int>>& num)
    {
	    vector<int> start_v(m, 0);
	    vector<int> end_v(m, 0);

	    for (int i = 0; i < n; i++)
	    {
		    start_v[i] = 1;
		    end_v[m - i - 1] = 1;
	    }
	    num.push_back(start_v);
	    while (start_v != end_v)
	    {
		    for (int i = 0; i < m - 1; i++)
		    {
			    if (start_v[i] == 1 && start_v[i + 1] == 0)
			    {
				    start_v[i] = 0;
				    start_v[i + 1] = 1;
				    int cnt = 0;
				    for (int j = 0; j < i; j++)
				    {
					    cnt += start_v[j];
					    start_v[j] = 0;
				    }
				    for (int j = 0; j < cnt; j++)
				    {
					    start_v[j] = 1;
				    }
				    break;
			    }
		    }
		    num.push_back(start_v);
	    }
    }
    
    int sum(vector<int>& num)
    {
	    int res = 0;
	    for (int i = 0; i < num.size(); i++)
	    {
		    res += (i + 1) * num[i];
	    }
	    return res;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        
        if(n > (19-k)*k/2)
            return res;
        
        vector<vector<int>> tmp;
        
        cmn(9, k, tmp);
        
        for (int i = 0; i < tmp.size(); i++)
	    {
		    int x;
		    x = sum(tmp[i]);
		    if (x == n)
		    {
			    vector<int> _v;
			    for (int j = 0; j < tmp[i].size(); j++)
			    {
				    if (tmp[i][j])
					    _v.push_back(j + 1);
			    }
			    res.push_back(_v);
		    }
	    }
        
        return res;
    }
};
