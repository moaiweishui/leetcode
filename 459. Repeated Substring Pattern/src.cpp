class Solution {
public:
    bool repeatedSubstringPatternWithLen(string s, int len)
    {
        string subs(s.begin(), s.begin() + len);
        string news = "";
        for (int i = 0; i < s.length() / len; i++)
        {
            news += subs;
            if (news.compare(0, news.length(), s, 0, news.length()) != 0)
                return false;
        }
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        
        if(len == 0 || len == 1)
            return false;       
        
        if(repeatedSubstringPatternWithLen(s, 1))
            return true;
        
        for(int i = 2; i <= sqrt(len); i++)
        {
            if (len % i == 0)
            {
                if(repeatedSubstringPatternWithLen(s, i) || repeatedSubstringPatternWithLen(s, len/i))
                    return true;               
            }
        }
        return false;
    }
};
