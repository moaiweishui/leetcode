/********************* Solution 1 ***********************/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 0)
            return 0;
        else if(len == 1)
            return nums[0];
        
        vector<int> max_pd(len, 0);
        vector<int> min_pd(len, 0);
        
        max_pd[0] = nums[0];
        min_pd[0] = nums[0];
        
        int res = max_pd[0];
        
        for(int i = 1; i < len; i++)
        {
            if(nums[i] >= 0)
            {
                max_pd[i] = max(nums[i] * max_pd[i - 1], nums[i]);
                min_pd[i] = min(nums[i] * min_pd[i - 1], nums[i]);
            }
            else
            {
                max_pd[i] = max(nums[i] * min_pd[i - 1], nums[i]);
                min_pd[i] = min(nums[i] * max_pd[i - 1], nums[i]);
            }
            if(max_pd[i] > res)
                res = max_pd[i];
        }
        
        return res;       
    }
};
