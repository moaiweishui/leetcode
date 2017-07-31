class Solution {
public:
    static bool cmp(pair<int, int>& x, pair<int, int>& y)
    {
        return x.second > y.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.count(nums[i]) == 0)
                mp[nums[i]] == 1;
            else
                mp[nums[i]] += 1;
        }
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);
        
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(v[i].first);
        }
        return res;
    }
};
