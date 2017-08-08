class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res(2, 0);
        
        bool flag = true;
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != i + 1)
			    flag = false;
            if(nums[i] == nums[i + 1])
            {
                res[0] = nums[i];
                break;
            }
        }
        
        if (flag)
	    {
		    for (int i = nums.size() - 1; i >= 0; i--)
		    {
			    if (nums[i] != i + 1)
			    {
				    res[1] = i + 1;
				    break;
			    }
		    }
	    }
	    else
	    {
		    for (int i = 0; i < nums.size(); i++)
		    {
			    if (nums[i] != i + 1)
			    {
				    res[1] = i + 1;
				    break;
			    }
		    }
	    }
        
        
        return res;
        
    }
};
