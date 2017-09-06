class Solution {
public:
    bool isValid(string s)
    {
        int len = s.length();
        if(len == 1)
            return true;
        int l = 0, r = len - 1;
        while(l < r)
        {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void partitionWithMem(string& s, vector<vector<string>>& res, vector<string>& mem, int pos)
    {
        if(pos == s.length() + 1)
        {
            res.push_back(mem);
            return;
        }
        
        string temps;
        for(int i = pos; i <= s.length(); i++)
        {
            temps.assign(s.begin() + pos - 1, s.begin() + i);
            if(isValid(temps))
            {
                mem.push_back(temps);
                partitionWithMem(s, res, mem, i + 1);
                mem.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<string>> res;
        vector<string> mem;
        if(len == 0)
            return res;
        
        partitionWithMem(s, res, mem, 1);
        
        return res;
    }
};
