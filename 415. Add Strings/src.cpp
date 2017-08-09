class Solution {
public:
    string addStrings(string num1, string num2) {
        string x;
	    string y;
	    if (num1.length() >= num2.length())
	    {
		    x.assign(num1);
		    string tmps(num1.length() - num2.length(), '0');
		    y = tmps + num2;
	    }
	    else
	    {
		    x.assign(num2);
		    string tmps(num2.length() - num1.length(), '0');
		    y = tmps + num1;
	    }
        
        int c = 0;
        string res(x.length(), 0);
	    for (int i = x.length() - 1; i >= 0; i--)
	    {
		    int sum = (x[i] - 48) + (y[i] - 48) + c;
		    if (sum >= 10)
		    {
			    res[i] = sum % 10 + 48;
			    c = 1;
		    }
		    else
		    {
			    res[i] = sum + 48;
			    c = 0;
		    }
	    }
        
        if (c == 1)
		    res = "1" + res;
        
        return res;
        
    }
};
