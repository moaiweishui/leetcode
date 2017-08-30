class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return nums[0];
        
        int current_max = nums[0];
        int total_max = current_max;
        
        for(int i = 1; i < len; i++)
        {
            current_max = max(current_max + nums[i], nums[i]);
            if(current_max > total_max)
                total_max = current_max;
        }
        
        return total_max;
    }
};
