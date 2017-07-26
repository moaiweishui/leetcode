class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) { 
        if(nums.size() == 0)
            return 0;
        
        int res = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                cnt ++;
            else
            {
                res = (cnt>res)?cnt:res;
                cnt = 0;
            }
        }
        res = (cnt>res)?cnt:res;
        return res;
    }
};
