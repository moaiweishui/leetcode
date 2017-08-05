class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<char> sv(s.begin(), s.end());
        vector<char> tv(t.begin(), t.end());
        
        bool res = true;
        
        for(int i = 0; i < sv.size(); i++)
        {
            vector<char>::iterator it;
            it = find(tv.begin(), tv.end(), sv[i]);
            if(it != tv.end())
            {
                tv.erase(tv.begin(), it + 1);
            }
            else
            {
                return false;
            }
        }
        
        return res;
        
    }
};
