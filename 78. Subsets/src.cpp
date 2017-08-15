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
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
	    vector<int> tmp;
	    res.push_back(tmp);
        
        if(size == 0)
            return res;
        
        vector<vector<int>> combination;

	    for (int i = 1; i < size; i++)
	    {
		    cmn(size, i, combination);
	    }

	    set<vector<int>> s;

	    for (int i = 0; i < combination.size(); i++)
	    {
		    tmp.clear();
		    for (int j = 0; j < size; j++)
		    {
			    if (combination[i][j])
				    tmp.push_back(nums[j]);
		    }
		    s.insert(tmp);
	    }   
	    res.insert(res.end(), s.begin(), s.end());
        
        res.push_back(nums);
        
        return res;
        
    }
};
