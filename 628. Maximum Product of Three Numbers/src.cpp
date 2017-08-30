class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();  
        if(len == 3)
            return nums[0] * nums[1] * nums[2];
        
        sort(nums.begin(), nums.end());
    
        if(nums[len - 1] <= 0 || nums[0] >= 0)
            return nums[len - 1] * nums[len - 2] * nums[len - 3];
        
        vector<int> pos;
        vector<int> neg;
        
        for(int i = 0; i < 3; i++)
        {
            if(nums[i] >= 0)
                break;
            neg.push_back(nums[i]);
        }
        
        for(int i = len-1; i>=len - 3; i--)
        {
            if(nums[i] < 0)
                break;
            pos.push_back(nums[i]);
        }

        pos.insert(pos.end(), neg.begin(), neg.end());
        len = pos.size();
        
        int max = 0x80000000;
        
        for(int i = 0; i < len - 2; i++)
            for(int j = i + 1; j < len - 1; j++)
                for(int k = j + 1; k < len; k++)
                    if(pos[i]*pos[j]*pos[k] > max)
                        max = pos[i]*pos[j]*pos[k];
        
        return max;
    }
};
