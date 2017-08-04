class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        vector<int> res;
        for(int i= 0; i<nums.size() - 1; i++)
        {
            
            vector<int>::iterator it;
            it = find(nums.begin() + i + 1, nums.end(), target - nums[i]);
            if(it != nums.end())
            {
                res.clear();
                res.push_back(i);
                res.push_back(it - nums.begin());
            }
        }
        return res;
    }
};
