class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 3)
        {
            if(nums[1] == nums[0])
                return nums[2];
            else
                return nums[0];
        }
        else
        {
            int mid = nums.size() / 2;
            if(mid%2 == 0)
            {
                if(nums[mid] == nums[mid - 1])
                {
                    vector<int> tmp(nums.begin(), nums.begin() + mid + 1);
                    return singleNonDuplicate(tmp);
                }              
                else if(nums[mid] == nums[mid + 1])
                {
                    vector<int> tmp(nums.begin() + mid, nums.end());
                    return singleNonDuplicate(tmp);
                }               
                else
                    return nums[mid];
            }
            else 
            {
                if(nums[mid] == nums[mid + 1])
                {
                    vector<int> tmp(nums.begin(), nums.begin() + mid);
                    return singleNonDuplicate(tmp);
                }              
                else if(nums[mid] == nums[mid - 1])
                {
                    vector<int> tmp(nums.begin() + mid + 1, nums.end());
                    return singleNonDuplicate(tmp);
                }               
                else
                    return nums[mid];
            }

        }
        
    }
};
