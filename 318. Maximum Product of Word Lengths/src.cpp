class Solution {
public:
    bool isShareChar(string a, string b)
    {
	    string x, y;
	    if (a.length() >= b.length())
	    {
		    x = a;
		    y = b;
	    }
	    else
	    {
		    x = b;
		    y = a;
	    }

	    for (int i = 0; i < y.length(); i++)
	    {
		    int pos = x.find(y[i]);
		    if (pos > -1)
			    return true;
	    }
	    return false;
    }
    
    
    int maxProduct(vector<string>& words) {
        if(words.size() == 0)
            return 0;
        int max_length = 0;
        for (int i = 0; i < words.size() - 1; i++)
	    {
		    for (int j = 0; j < words.size(); j++)
		    {
			    if (!isShareChar(words[i], words[j]))
			    {
				    int tmp = words[i].length() * words[j].length();
				    if (tmp > max_length)
					    max_length = tmp;
			    }
		    }
	    }
        return max_length;
    }
};
