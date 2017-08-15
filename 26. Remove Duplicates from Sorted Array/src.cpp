class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return 1;

        vector<int>::iterator it1 = nums.begin();
        while (it1 != nums.end())
        {
            vector<int>::iterator it2;
            for (it2 = it1 + 1; it2 != nums.end();)
            {
                if (*it2 == *it1)
                {
                    it2 = nums.erase(it2);
                }
                else
                {
                    break;
                }
            }
            it1++;
        }
        
        return nums.size();
        
    }
};
