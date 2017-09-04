class Solution {
public:
    void subsetsWithDup(vector<int>& nums, set<vector<int>>& mem, vector<int>& subset, int depth)
    {
        if(depth > nums.size())
            return;
        
        for(int i = depth; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            if(mem.count(subset) == 0)
            {
                mem.insert(subset);
                subsetsWithDup(nums, mem, subset, i + 1);
            }
            auto it = find(subset.begin(), subset.end(), nums[i]);
            if(it != subset.end())
                subset.erase(it);
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        vector<int> subset;
        vector<vector<int>> res;
        res.push_back(subset);
        if(len == 0)
            return res;
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> mem;
        mem.insert(subset);
        int depth = 0;
        subsetsWithDup(nums, mem, subset, depth);
        
        res.assign(mem.begin(), mem.end());
        
        return res;
    }
};
