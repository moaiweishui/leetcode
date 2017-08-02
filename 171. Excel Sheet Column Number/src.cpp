class Solution {
public:
    int titleToNumber(string s) {
        vector<int> v;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            v.push_back(int(s[len - 1 - i]) - 64);
        }
        
        int res = 0;
        
        for(int i = 0; i < v.size(); i++)
        {
            res += v[i]*pow(26, i);
        }
        return res;
    }
};
