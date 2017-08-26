/******************* Solution 1 ********************/
class Solution {
public:
    int findTargetSumWaysWithLen(vector<int>& nums, int len, int S, vector<int>& sumv)
    {
        if(len == 0)
            return 0;
        else if(len == 1)
        {
            if(S == 0)
                return nums[0]==S ? 2 : 0;
            else
                return abs(nums[0])==abs(S) ? 1 : 0;
        }
        else if(S > sumv[len - 1] || S < -sumv[len - 1])
        {
            return 0;
        }
        else
        {
            return findTargetSumWaysWithLen(nums, len - 1, S + nums[len - 1], sumv) + findTargetSumWaysWithLen(nums, len - 1, S - nums[len - 1], sumv);
        }
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {    
        vector<int> sumv(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
                sumv[i] = abs(nums[i]);
            else
                sumv[i] = abs(nums[i]) + sumv[i - 1];
        }
        
        return findTargetSumWaysWithLen(nums, nums.size(), S, sumv);      
    }
};

/******************* Solution 2 ********************/
class Solution {
public:
    int findTargetSumWaysWithLen(vector<int>& nums, int len, int S, vector<int>& sumv, vector<vector<int>>& res)
    {
        if(len == 0)
            return 0;
        else if(len == 1)
        {
            if(S == 0)
                return nums[0]==S ? 2 : 0;
            else
                return abs(nums[0])==abs(S) ? 1 : 0;
        }
        else if(S > sumv[len - 1] || S < -sumv[len - 1])
        {
            return 0;
        }
        else if(res[len - 1][S + 1000] == -1)
        {
            res[len - 1][S + 1000] = findTargetSumWaysWithLen(nums, len - 1, S + nums[len - 1], sumv, res) + findTargetSumWaysWithLen(nums, len - 1, S - nums[len - 1], sumv, res);
            return res[len - 1][S + 1000];
        }
        else
            return res[len - 1][S + 1000];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {    
        vector<int> tempv(2001, -1);
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++)
            res.push_back(tempv);
        
        vector<int> sumv(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
                sumv[i] = abs(nums[i]);
            else
                sumv[i] = abs(nums[i]) + sumv[i - 1];
        }
        
        return findTargetSumWaysWithLen(nums, nums.size(), S, sumv, res);
    }
};
