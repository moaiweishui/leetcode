class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int cnt = 0;
        int origin_size = nums.size();
        for(int i = 0; i < origin_size; i++)
        {
            if(nums[i] == 0)
            {
                nums.push_back(0);
                cnt++;
            }
               
        }
        vector<int>::iterator it = nums.begin();
        while(cnt)
        {
            if(*it == 0)
            {
                it = nums.erase(it);
                cnt--;
            }
            else
            {
               it++; 
            }
                
        }
        
    }
};
