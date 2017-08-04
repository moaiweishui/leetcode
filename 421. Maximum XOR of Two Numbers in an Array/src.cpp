class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0]^nums[0];
        
        int res = 0x80000000;
        for(int i = 0; i < nums.size() - 1; i++)
            for(int j = i; j < nums.size(); j++)
            {
                if((nums[i]^nums[j]) > res)
                    res = nums[i]^nums[j];
            }
        return res;
    }
};
