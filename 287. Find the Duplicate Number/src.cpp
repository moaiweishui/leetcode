class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res;
        
	    for (int i = 0; i < nums.size()-1; i++)
	    {
		    vector<int>::iterator it;
		    it = find(nums.begin() + i + 1, nums.end(), nums[i]);
		    if (it != nums.end())
		    {
			    return nums[i];
		    }
	    }
        
    }
};
