class Solution {
public:
    int robWithLen(vector<int>& nums, int len, vector<int>& mem)
    {
        if(len == 0)
            return 0;
        else if(len == 1)
            return nums[0];
        else
        {
            if(mem[len - 1] == -1)
                mem[len - 1] = robWithLen(nums, len - 1, mem);
            if(mem[len - 2] == -1)
                mem[len - 2] = robWithLen(nums, len - 2, mem);
            //cout<<mem[len - 1]<<endl;
            //cout<<nums[len - 1] + mem[len - 2]<<endl;
            return max(mem[len - 1], nums[len - 1] + mem[len - 2]);
        }
    }
    
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        vector<int> mem(len + 1, -1);
        mem[0] = 0;
        mem[1] = nums[0];
        return robWithLen(nums, nums.size(), mem);
    }
};
