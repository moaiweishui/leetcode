class Solution {
public:
    void findPermuteUnique(vector<int>& candidate, vector<int>& permute, vector<vector<int>>& mem)
    {
        if(candidate.empty())
        {
            mem.push_back(permute);
            return;
        }
        
        set<int> candidateUnique(candidate.begin(), candidate.end());
        for(auto it = candidateUnique.begin(); it != candidateUnique.end(); it++)
        {
            int tmp = *it;
            permute.push_back(tmp);
            auto findit = find(candidate.begin(), candidate.end(), tmp);
            int pos = findit - candidate.begin();
            candidate.erase(findit);
            findPermuteUnique(candidate, permute, mem);
            candidate.insert(candidate.begin() + pos, tmp);
            permute.pop_back();
        }
        
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> candidate(nums.begin(), nums.end());
        vector<int> permute;
        vector<vector<int>> mem;
        
        findPermuteUnique(candidate, permute, mem);
        
        return mem;
    }
};
