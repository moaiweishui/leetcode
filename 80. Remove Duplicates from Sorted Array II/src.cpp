class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        
        int size = nums.size()-1;
        int p = 1;
        int cnt = 1;
        int last = nums[0];
        
        while (size)
        {
            if (nums[p] == last)
            {
                cnt++;
                if (cnt == 3)
                {
                    int tmp = nums[p];
                    nums.erase(nums.begin() + p);
                    nums.push_back(tmp);
                    cnt = 2;
                }
                else
                {
                    p++;
                }
            }
            else
            {
                last = nums[p];
                cnt = 1;
                p++;   
            }
            size--;
        }
        return p;
    }
};
