class Solution {
public:
    void swap(vector<int>& v, int pos1, int pos2)
    {
	    int tmp = v[pos1];
	    v[pos1] = v[pos2];
	    v[pos2] = tmp;
    }
    
    vector<vector<int>> ann(int n)
    {
	    vector<vector<int>> res;
	    vector<int> start_v, end_v;

	    for (int i = 1; i <= n; i++)
	    {
		    start_v.push_back(i);
		    end_v.push_back(n + 1 - i);
	    }
		
	    res.push_back(start_v);

	    while (start_v != end_v)
	    {
		    for (int i = n - 2; i >= 0; i--)
		    {   
			    if (start_v[i] < start_v[i + 1])
			    {
				    int min_of_max = start_v[i + 1];
				    int index = i + 1;
				    for (int j = i + 1; j < start_v.size(); j++)
				    {
					    if (start_v[j] > start_v[i] && start_v[j] < min_of_max)
					    {
						    min_of_max = start_v[j];
						    index = j;
					    }
				    }
				    swap(start_v, i, index);
				    reverse(start_v.begin() + i + 1, start_v.end());
				    res.push_back(start_v);
				    break;
			    }
		    }
	    }
	    return res;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<vector<int>> permutation = ann(nums.size());
        
        for(int i = 0; i < permutation.size(); i++)
        {
            vector<int> tmpv;
            
            for(int j = 0; j < nums.size(); j++)
            {
                tmpv.push_back(nums[permutation[i][j]-1]);
            }
            res.push_back(tmpv);
        }
        
        return res;
        
        
    }
};
