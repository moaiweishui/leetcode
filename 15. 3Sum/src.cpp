class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int end, int target)
    {
        int left = start;
        int right = end;

        set<vector<int>> res_set;
        vector<int> tmp;

        while (left != right)
        {
            if (nums[left] + nums[right] == target)
            {
                tmp.clear();
                tmp.push_back(nums[left]);
                tmp.push_back(nums[right]);
                res_set.insert(tmp);
                if (left == right - 1)
                    break;
                left++;
                right--;
            }
            else if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else if (nums[left] + nums[right] < target)
            {
                left++;
            }
        }
        vector<vector<int>> res(res_set.begin(), res_set.end());
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res;
        
        if(size < 3)
            return res;
        
        sort(nums.begin(), nums.end());
	    set<vector<int>> res_set;
        
        for(int i = 0; i < size - 2; i++)
        {
            vector<vector<int>> tmpv = twoSum(nums, i+1, size-1, 0 - nums[i]);
            for(int j = 0; j < tmpv.size(); j++)
            {
                tmpv[j].insert(tmpv[j].begin(), nums[i]);
                res_set.insert(tmpv[j]);
            }
        }
        
        
        res.assign(res_set.begin(), res_set.end());
        
        return res;
        
    }
};
