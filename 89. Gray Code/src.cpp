class Solution {
public:
    void newGrayCode(int n, int num, vector<int>& res)
    {
        if(res.size() == pow(2, n))
            return;
        
        for(int i = 0; i < n; i++)
        {
            int new_num = num ^ (1 << i);
            auto it = find(res.begin(), res.end(), new_num);
            if(it == res.end())
            {
                res.push_back(new_num);
                newGrayCode(n, new_num, res);
            }
        }
        return;
    }
    
    vector<int> grayCode(int n) {
        
    vector<int> res;
    res.push_back(0);
    newGrayCode(n, 0, res);
    
    return res;
    }
};
