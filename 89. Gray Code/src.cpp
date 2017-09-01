/******************** Solution 1 ********************/
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


/******************** Solution 2 ********************/
class Solution {
public:
    vector<int> grayCode(int n) {
    vector<int> res;
    if(n == 0)
    {
        res.push_back(0);
        return res;
    }
    else if(n == 1)
    {
        res.push_back(0);
        res.push_back(1);
        return res;
    }
        
    vector<int> v = grayCode(n - 1);
    res.insert(res.end(), v.begin(), v.end());    
    reverse(v.begin(), v.end());
    res.insert(res.end(), v.begin(), v.end());    
    for(int i = pow(2, n - 1); i < pow(2, n); i++)
        res[i] += pow(2, n - 1);
    return res;
    }
};
