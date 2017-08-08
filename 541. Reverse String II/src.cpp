class Solution {
public:
    string reverseStr(string s, int k) {
        
        int group = s.length() / k;
        if (group % 2 == 1)
	    {
		    int len = group / 2 + 1;
		    for (int i = 0; i < len; i++)
		    {
			    reverse(s.begin() + 2 * k * i, s.begin() + 2 * k * i + k);
		    }
	    }
	    else
	    {
		    int len = group / 2;
		    for (int i = 0; i < len; i++)
		    {
			    reverse(s.begin() + 2 * k * i, s.begin() + 2 * k * i + k);
		    }
		    reverse(s.begin() + 2 * k * len, s.end());
	    }
        return s;
    }
};
