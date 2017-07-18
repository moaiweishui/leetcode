class Solution {
public:
    void exchange(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
        
        return;
    }
    
public:
    int arrayPairSum(vector<int>& nums) {
        int num_size = nums.size();
        int res = 0;
        for(int i = 0; i < num_size - 1; i ++)
        {
            for(int j = 0; j < num_size - 1 - i; j ++)
                if(nums[j] > nums[j + 1])
                    exchange(nums[j], nums[j + 1]);
            if(i % 2 != 0)
                res += nums[num_size - i - 1]; 
        }
        res += nums[0]; 
        
        
        return res;
    }
};
