class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        vector<string> res;
        for(int i = 0; i < nums.size(); i++)
        {
            vector<int>::iterator it;
            it = find(v.begin(), v.end(), nums[i]);
            int rank = nums.size() - (it - v.begin());
            if(rank == 1)
                res.push_back("Gold Medal");
            else if(rank == 2)
                res.push_back("Silver Medal");
            else if(rank == 3)
                res.push_back("Bronze Medal");
            else
            {
                stringstream ss;
                string s;
                ss << rank;
                ss >> s;
                res.push_back(s);
            }
                
        }
        return res;
    }
};
