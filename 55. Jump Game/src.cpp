class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;
        vector<int> mem(nums.size(), 0);
        vector<bool> can_reach(nums.size(), false);
        mem[0] = nums[0];
        can_reach[0] = true;
        for (int i = 1; i < nums.size(); i++){
            if (mem[i - 1] > 0){
                can_reach[i] = true;
                mem[i] = max(mem[i - 1] - 1, nums[i]);
            }
            else{
                return false;
            }
        }
        return can_reach[nums.size() - 1];
    }
};
