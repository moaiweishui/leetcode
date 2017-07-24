class Solution {
public:
    bool is_palindromic(string s)
    {
	    bool res = true;

	    int length = s.size();

	    if (length == 1)
		    return res;

	    for (int i = 0; i < (length / 2 + length % 2); i++)
	    {
		    if (s[i] != s[length - i - 1])
		    {
			    res = false;
			    break;
		    }
	    }
	    return res;
    }
    
    string longestPalindrome(string s) {
        string res;
        
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 0; j <= s.size() - i; j++)
            {
                string _s;
                _s = s.substr(j, i);
                if (is_palindromic(_s))
                {
                    res = _s;
                    break;
                }
                    
            }
        }
        
        
        return res;
    }
};
