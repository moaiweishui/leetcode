class Solution {
public:
    int firstUniqChar(string s) {
        vector<char> v;
        if(s.length() == 1)
            return 0;
        
        for(int i = 0; i<s.length(); i++)
        {
            v.push_back(s[i]);
        }
        
        int res = -1;
        
        for(int i = 0; i<s.length(); i++)
        {
            vector<char>::iterator it;
            it = find(v.begin() + i + 1, v.end(), s[i]);
            if(it == v.end())
            {
                if(i == 0)
                    return 0;
                it = find(v.begin(), v.begin() + i, s[i]);
			    if (it == v.begin() + i)
			    {
				    res = i;
				    break;
			    }
            }
        }
        
        return res;
    }
};
