class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max = 0x80000000;
        for(int i = 0; i <= nums.size() - k; i++)
        {
            int _sum = 0;
            for(int j = i; j < i + k; j++)
                _sum += nums[j];
            if(_sum > max)
                max = _sum;
        }
        
        return double(max) / k;
    }
};
