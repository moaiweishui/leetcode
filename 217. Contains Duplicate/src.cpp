class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        multiset<int> numset(nums.begin(), nums.end());
        bool res = false;
        for(int i = 0; i < nums.size(); i++)
        {
            if(numset.count(nums[i]) > 1)
            {
                res = true;
                break;
            }
        }
        return res;
    }
};
