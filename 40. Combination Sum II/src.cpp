class Solution {
public:
    void combinationSumWithCandidate(vector<int>& candidates, int target, vector<int>& mem, set<vector<int>>& res_set, int& sum)
    {
        if(sum == target)
        {
            sort(mem.begin(), mem.end());
            res_set.insert(mem);
            return;
        }
        
        for(auto it = candidates.begin(); it != candidates.end(); it++)
        {
            if(sum + *it <= target)
            {
                int value = *it;
                sum += value;
                mem.push_back(value);
                int pos = it - candidates.begin();
                candidates.erase(it);
                combinationSumWithCandidate(candidates, target, mem, res_set, sum);
                sum = sum - value;
                auto temp_it = find(mem.begin(), mem.end(), value);
                mem.erase(temp_it);
                it = candidates.insert(candidates.begin() + pos, value);
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        set<vector<int>> res_set;
        vector<int> mem;
        int sum = 0;
        combinationSumWithCandidate(candidates, target, mem, res_set, sum);
        res.assign(res_set.begin(), res_set.end());
        return res;
    }
};
