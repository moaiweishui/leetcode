class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag = false;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                int index = i + 1;
                int min_max = nums[i + 1];
                
                for(int j = i + 1; j < nums.size(); j++)
                {
                    if(nums[j] > nums[i] && nums[j] <= min_max)
                    {
                        min_max = nums[j];
                        index = j;
                    }
                }
                
                int tmp = nums[i];
                nums[i] = nums[index];
                nums[index] = tmp;
                
                reverse(nums.begin() + i + 1, nums.end());
                flag = true;
                break;
            }
        }
        
        if(!flag)
            reverse(nums.begin(), nums.end());
    }
};
