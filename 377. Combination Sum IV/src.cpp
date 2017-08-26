class Solution {
public:
    int combinationSum4WithMem(vector<int>& nums, int target, vector<int>& mem)
    {
        if(target < 0)
            return 0;
        else if(target == 0)
            return 1;
        
        int len = nums.size();
        
        int res = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(target - nums[i] >= 0)
            {
                if(mem[target - nums[i]] == -1)
                    mem[target - nums[i]] = combinationSum4WithMem(nums, target - nums[i], mem);
                res += mem[target - nums[i]];
            }
        }
        return res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();      
        vector<int> mem(target + 1, -1);
        
        return combinationSum4WithMem(nums, target, mem);
    }
};
