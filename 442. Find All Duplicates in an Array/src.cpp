/********************** Solution 1 ********************************/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = nums.begin();
        while( it!= nums.end())
        {
            if ((it + 1) == nums.end())
		    {
			    it = nums.erase(it);
	    	}
            else if(*it == *(it+1))
            {
                it = nums.erase(it);
                it++;
            }
            else
            {
                it = nums.erase(it);
            }
        }
            
        return nums;
        

    }
};

/************************ Solution 2 *****************************/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
            v[nums[i]-1]++;
        }
        for(int i = 0;i<v.size();i++)
        {
            if(v[i] == 2)
                res.push_back(i+1);
        }
        return res;

    }
};
