class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX; //minimum value in nums
        int max = INT_MAX; //minimum value in nums which big than min
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= min)
                min = nums[i];
            else if(nums[i] <= max)
                max = nums[i];
            else
                return true;
        }
        return false;
    }
};
