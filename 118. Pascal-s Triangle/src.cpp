class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        
        for(int i = 1; i <= numRows; i++)
        {
            vector<int> tmpv;
            if(i == 1)
            {
                tmpv.push_back(1);
                res.push_back(tmpv);
            }
            else if(i == 2)
            {
                tmpv.push_back(1);
                tmpv.push_back(1);
                res.push_back(tmpv);
            }
            else
            {
                tmpv.push_back(1);
                for(int j = 1; j < i; j++)
                {
                    if(j <= (i-1)/2)
                        tmpv.push_back(res[i-2][j-1] + res[i-2][j]);
                    else
                        tmpv.push_back(tmpv[i - 1 - j]);
                }
                res.push_back(tmpv);
            }
            
        }
        return res;
    }
};
