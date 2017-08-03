/**************** Solution 1 ***************/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.length();
        int t_size = t.length();
        if(s_size!=t_size)
            return false;
        multiset<char> s_ms;
        multiset<char> t_ms;
        for(int i = 0; i < s_size; i++)
            s_ms.insert(s[i]);
        for(int i = 0; i < t_size; i++)
            t_ms.insert(t[i]);
        
        return s_ms == t_ms;
    }
};

/**************** Solution 2 ***************/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.length();
        int t_size = t.length();
        if(s_size!=t_size)
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s.compare(t) == 0)
            return true;
        else
            return false;
    }
};
