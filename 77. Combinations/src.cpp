class Solution {
public:
    vector<vector<int>> cmn(int m, int n)
    {
        vector<int> start_v(m, 0);
        vector<int> end_v(m, 0);
        
        vector<vector<int>> combination;
        
        for(int i = 0; i < n; i++)
        {
            start_v[i] = 1;
            end_v[m - i - 1] = 1;
        }
        combination.push_back(start_v);
        while(start_v != end_v)
        {
            for(int i = 0; i < m - 1; i++)
            {
                if(start_v[i] == 1 && start_v[i + 1] == 0)
                {
                    start_v[i] = 0;
                    start_v[i + 1] = 1;
                    
                    int cnt = 0;
                    
                    for(int k = 0; k < i; k++)
                    {
                        cnt += start_v[k];
                        start_v[k] = 0;
                    }
                    
                    for(int k = 0; k < cnt; k++)
                    {
                        start_v[k] = 1;
                    }
                    break;
                }
            }
            combination.push_back(start_v);          
        }
        
        return combination;
        
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        
        vector<vector<int>> combination = cmn(n, k);
        
        for(int i = 0; i < combination.size(); i++)
        {
            vector<int> tmpv;
            for(int j = 1; j <= n; j++)
            {
                if(combination[i][j-1])
                    tmpv.push_back(j);
            }
            res.push_back(tmpv);
            
        }
        
        
        return res;
        
    }
};
