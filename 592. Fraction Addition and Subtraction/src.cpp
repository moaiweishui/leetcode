class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> up;
	    vector<int> low;
	    int len = 0;
	    if (expression[0] != '-')
	    {
		    expression = "+" + expression;
	    }
	
        vector<string> num_v;
	    
	    bool neg_flag = false;
	    if (expression[0] == '-')
		    neg_flag = true;
        
        string tmp = "";
        
        for (int i = 0; i < expression.length(); i++)
	    {	
		    if (i == expression.length()-1)
		    {
			    tmp += expression[i];
			    if (neg_flag)
				    num_v.push_back("-" + tmp);
			    else
				    num_v.push_back(tmp);
			    break;
		    }

		    if (expression[i] == '+')
		    {			
			    len++;
			    if (tmp.size() != 0)
			    {
				    if(neg_flag)
					    num_v.push_back("-" + tmp);
				    else
					    num_v.push_back(tmp);
				    tmp = "";
			    }
			    neg_flag = false;
		    }		
		    else if (expression[i] == '-')
		    {	
			    len++;
			    if (tmp.size() != 0)
			    {
				    if (neg_flag)
					    num_v.push_back("-" + tmp);
				    else
					    num_v.push_back(tmp);
				    tmp = "";
			    }
			    neg_flag = true;
		    }
		    else
		    {
			    tmp += expression[i];
		    }
	    }
        
        for (int i = 0; i < num_v.size(); i++)
	    {
		    tmp = "";
		    for (int j = 0; j < num_v[i].length(); j++)
		    {   
			    if (num_v[i][j] == '/')
			    {
				    stringstream _ss;
				    int t;
				    _ss << tmp;
				    _ss >> t;
				    up.push_back(t);
				    tmp = "";
			    }
			    else
			    {
				    tmp += num_v[i][j];
			    }
			    if (j == num_v[i].length() - 1)
			    {
				    stringstream _ss;
				    int t;
				    _ss << tmp;
				    _ss >> t;
				    low.push_back(t);
				    tmp = "";
			    }
		    }
	    }
        
        int product = 1;
        
	    for (int i = 0; i < len; i++)
		    product *= low[i];
        
        int numerator = 0;

	    for (int i = 0; i < len; i++)
	    {
		    int tmp = product/low[i];
		    numerator += tmp * up[i];
	    }
        
        bool neg = false;
        if (numerator < 0)
	    {
		    neg = true;
		    numerator = -numerator;
	    }
        
        string res;
        
        if (numerator == product)
	    {
		    if (neg)
			    return "-1/1";
		    else
			    return "1/1";
		}
        else if (numerator == 0)
	    {
		    return "0/1";
	    }
        else
	    {
		    int n = numerator < product ? numerator : product;
		    while (n >= 1)
		    {
			    if (numerator % n == 0 && product % n == 0)
				    break;
			    n--;
		    }
		    numerator = numerator / n;
		    product = product / n;
	    }
        
        stringstream ss1;
	    string s;
	    ss1 << numerator;
	    ss1 >> s;
	    res = s;
	
	    stringstream ss2;
	    ss2 << product;
	    ss2 >> s;
	    res = res + "/" + s;
	    if (neg)
		    res = "-" + res;
        
        return res;
    }
};
