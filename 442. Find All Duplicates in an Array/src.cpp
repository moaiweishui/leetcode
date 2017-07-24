class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = nums.begin();
        while( it!= nums.end())
        {
            if ((it + 1) == nums.end())
		    {
			    it = nums.erase(it);
	    	}
            else if(*it == *(it+1))
            {
                it = nums.erase(it);
                it++;
            }
            else
            {
                it = nums.erase(it);
            }
        }
            
        return nums;
        

    }
};
