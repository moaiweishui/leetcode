class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>>::iterator it;
        int max_r = m, max_c = n;
        for(it = ops.begin(); it != ops.end(); it++)
        {
            if((*it)[0] < max_r)
                max_r = (*it)[0];
            if((*it)[1] < max_c)
                max_c = (*it)[1];
        }
        return max_r*max_c;
    }
};
