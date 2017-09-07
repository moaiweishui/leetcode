class Solution {
public:
    void findSubsequencesWithStart(vector<int>& nums, int start, vector<int>& subsequence, set<vector<int>>& mem)
    {
        int len = nums.size();
        if(start == len)
        {
            return;
        }
        
        for(int i = start; i < len; i++)
        {
            if(subsequence.size() == 0 || nums[i] >= subsequence[subsequence.size() - 1])
            {
                subsequence.push_back(nums[i]);
                if(subsequence.size() >= 2)
                    mem.insert(subsequence);
                findSubsequencesWithStart(nums, i + 1, subsequence, mem);
                subsequence.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len <= 1)
            return res;
        set<vector<int>> mem;
        vector<int> subsequence;
        
        findSubsequencesWithStart(nums, 0, subsequence, mem);
        
        res.assign(mem.begin(), mem.end());
        
        return res;
    }
};
