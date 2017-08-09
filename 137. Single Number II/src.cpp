class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        sort(nums.begin(), nums.end());
        
        int res;
        
        for (int i = 0; i < nums.size();)
	    {
		    if (i == nums.size() - 1)
		    {
			    res = nums[i];
			    break;
		    }

		    if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
		    {
			    i += 3;
		    }
		    else if (nums[i] == nums[i + 1])
		    {
			    res = nums[i + 2];
			    break;
		    }
		    else if (nums[i] == nums[i + 2])
		    {
			    res = nums[i + 1];
			    break;
		    }
		    else if (nums[i + 1] == nums[i + 2])
		    {
			    res = nums[i];
			    break;
		    }
	    }
        
        return res;
           
    }
};
