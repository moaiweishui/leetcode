class Solution {
public:
    //给定长度为n的数组，其第一个缺失的正整数不会超过n + 1
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            //将i位置上的数移动到其应在的位置（例如x应该移动到index = x - 1的位置，除非该位置超过原数组大小）
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++){
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
