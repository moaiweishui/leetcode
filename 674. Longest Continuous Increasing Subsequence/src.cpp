class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return 1;
        int max = INT_MIN;
        vector<int> mem(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i - 1]){
                mem[i] = mem[i - 1] + 1;
            }
            else{
                mem[i] = 1;
            }
            if (mem[i] > max){
                max = mem[i];
            }
        }
        return max;
    }
};
