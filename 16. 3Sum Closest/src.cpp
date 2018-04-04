class Solution {
public:
    int twoSumCloest(vector<int>& nums, int start, int target){
        int p = start;
        int q = nums.size() - 1;
        if (q - p == 1) return nums[p] + nums[q];

        int res = nums[p] + nums[q];
        int min = INT_MAX;
        while (p < q){
            int tempSum = nums[p] + nums[q];
            if (tempSum < target) p++;
            else if (tempSum > target) q--;
            else return tempSum;
            if (abs(tempSum - target) < min){
                min = abs(tempSum - target);
                res = tempSum;
            }
        }
        return res;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res;
        int min = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++){
            int tempSum = nums[i] + twoSumCloest(nums, i + 1, target - nums[i]);
            if (abs(tempSum - target) < min){
                min = abs(tempSum - target);
                res = tempSum;
            }
        }

        return res;
    }
};
