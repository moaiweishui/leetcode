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
        for(int i = 0; i < num_size - 1; i ++)
            for(int j = 0; j < num_size - 1 - i; j ++)
                if(nums[j] > nums[j + 1])
                    exchange(nums[j], nums[j + 1]);
        
        int res = 0;
        for (int i = 0; i < num_size; i = i + 2)
        {
            res += nums[i];
        }
        
        return res;
    }
};
