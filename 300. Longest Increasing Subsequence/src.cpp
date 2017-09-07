class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)
            return len;
        
        vector<int> mem(len, 1);
        int maxlen = 1;
        for(int i = 1; i < len; i++)
        {
            int tempmax = 1;
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[j] < nums[i] && mem[j] > tempmax - 1)
                {
                    tempmax = mem[j] + 1;
                    if(tempmax == maxlen + 1)
                        break;
                }
            }
            mem[i] = tempmax;       
            
            //cout<<mem[i]<<endl;
            if(mem[i] > maxlen)
                maxlen = mem[i];
        }
        return maxlen;
    }
};
