class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        
        if(len == 0)
            return 0;
        int cnt = 0;
        for(int i = 1; i <= len; i++)
        {
            int _sum = 0;
            for(int j = 0; j < len - i + 1; j++)
            {
                if(j == 0)
                    for(int s = 0; s < i; s++)
                        _sum += nums[j + s];
                else
                {
                    _sum = _sum - nums[j - 1] + nums[j + i - 1];
                }
                if(_sum == k)
                    cnt++;
            }
            
        }
        
        return cnt;
    }
};
