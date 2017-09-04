class Solution {
public:
    bool isValid(int pos, int num)
    {
        return (pos + 1)%num == 0 || num % (pos + 1) == 0;
    }
    
    void countArrangementWithDepth(int N, int& res, int depth, vector<int>& candidates)
    {
        if(depth == N)
        {
            res++;
            return;
        }
        
        for(auto it = candidates.begin(); it != candidates.end(); it++)
        {
            if(isValid(depth, *it))
            {
                int temp = *it;
                int temp_pos = it - candidates.begin();
                candidates.erase(it);
                countArrangementWithDepth(N, res, depth + 1, candidates);
                it = candidates.insert(candidates.begin() + temp_pos, temp);
            }
        }
    }
    
    int countArrangement(int N) {
        vector<int> candidates;
        for(int i = 1; i <= N; i++)
            candidates.push_back(i);
        int res = 0;
        int depth = 0;
        countArrangementWithDepth(N, res, depth, candidates);
        return res;
    }
};
