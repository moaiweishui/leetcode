/******************* Solution 1 ********************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        multiset<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
            
            if(s.count(nums[i]) > n/2)
                return nums[i];
                
        }
    }
};


/******************* Solution 2 ********************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res;
        int cnt = 1;
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int last_val = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == last_val)
            {
                cnt ++;
                if(cnt > n/2)
                {
                    res = nums[i];
                    break;
                }
            }               
            else
            {
                cnt = 1;
                last_val = nums[i];
            }   
        }
        return res;   
    }
};
