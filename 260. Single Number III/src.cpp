class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        if(size == 2)
            return nums;
        vector<int>::iterator it = nums.begin();
        sort(nums.begin(), nums.end());
        vector<int> res;
        while(nums.size() > 1)
        {
            if(*it == *(it+1))
            {
                it = nums.erase(it);
                nums.erase(it);
                it = nums.begin();
            }
            else
            {
                res.push_back(*it);
                nums.erase(it);
                it = nums.begin();
            }
        }
        if(nums.size() == 1)
            res.push_back(nums[0]);
        
	    return res;
    }
};
