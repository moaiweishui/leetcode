/*********************** Solution 1 ***************************/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        
        vector<int>::iterator it;
        vector<int>::iterator temp_it;
        
        int cnt = 0;
        bool flag = false;

        for (it = nums.begin(); it != nums.end();)
        {
            flag = false;
            temp_it = find(it + 1, nums.end(), *it + k);
            if (temp_it != nums.end())
            {
                cnt++;
                flag = true;
            }

            if (k != 0)
            {
                temp_it = find(it + 1, nums.end(), *it - k);
                if (temp_it != nums.end())
                {
                    cnt++;
                    flag = true;
                }
            }
            
            if (flag)
            {
                int target = *it;
                it = nums.erase(it);
                temp_it = find(it, nums.end(), target);
                while (temp_it != nums.end())
                {
                    temp_it = nums.erase(temp_it);
                    temp_it = find(temp_it, nums.end(), target);
                }
            }
            else
            {
                it++;
            }

        }
        
        return cnt;
    }
};

/*********************** Solution 2 ***************************/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        if(nums.size()<=1)
            return 0;
        vector<int>::iterator it;
        
        int cnt = 0;
        bool flag = false;

        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 1;)
        {
            it = find(nums.begin() + i + 1, nums.end(), nums[i] + k);
            if (it != nums.end())
            {
                cnt++;
                flag = true;
                int current = nums[i];
                while (current == nums[i])
                    i++;
            }
            else
            {
                i++;
            }

        }
        
        return cnt;
    }
};
