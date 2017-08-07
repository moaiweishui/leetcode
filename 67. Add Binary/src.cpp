class Solution {
public:
    string addBinary(string a, string b) {
        int len1;
	    int len2;
	    string x;
	    string y;
        
        if(a.length() > b.length())
        {
            len1 = a.length();
            len2 = b.length();
            x = a;
            y = b;
        }
        else
        {
            len1 = b.length();
            len2 = a.length();
            x = b;
            y = a;
        }
        
        reverse(x.begin(), x.end());
	    reverse(y.begin(), y.end());
        
        for (int i = 0; i < len1 - len2; i++)
	    {
		    y.append("0");
	    }
        
        vector<int> v;
        int c = 0;
        for(int i = 0; i < len1; i++)
        {
            int sum;
            if(x[i] == '0' && y[i] == '0')
            {
                sum = c;
                c = 0;
            }
            else if(x[i] == '1' && y[i] == '1')
            {
                sum = c;
                c = 1;
            }
            else
            {
                sum = 1 ^ c;
                c = 1 & c;
            }   
            v.push_back(sum);
        }
        
        if (c)
		    v.push_back(1);
        
        string res = "";
        for (int i = v.size() - 1; i >= 0; i--)
	    {
		    stringstream ss;
		    string tmp;
		    ss << v[i];
		    ss >> tmp;
		    res.append(tmp);
	    }
        
        return res;
        
    }
};
