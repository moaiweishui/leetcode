class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n  = M.size();
        if(n == 1)
            return 1;
        vector<int> tag;
        for(int i = 0; i < n; i++)
            tag.push_back(i);
        
        int res = n;
        
        for(int i = 0; i < n - 1; i++)
            for(int j = 1; j < n; j++)
            {
                if(j > i && M[i][j] == 1)
                {
                    if(tag[i] != tag[j])
                    {
                        int tmp = tag[j];
                        for(int k = 0; k < n; k++)
                            if(tag[k] == tmp)
                                tag[k] = tag[i];
                        res--;
                    }
                }
            }
        return res;
    }
};
