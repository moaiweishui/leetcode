class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        while(nums.size() != 1)
        {
            int tmp = *it;
		    nums.erase(it);
		    if (find(nums.begin(), nums.end(), tmp) == nums.end())
		    {
			    return tmp;
		    }
		    else
		    {
			    nums.erase(find(nums.begin(), nums.end(), tmp));
	    	}
            it = nums.begin();
        }
        return nums[0];    
    }
};
