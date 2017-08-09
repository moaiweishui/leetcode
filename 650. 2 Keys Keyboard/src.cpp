class Solution {
public:
    vector<int> factor(int n)
    {
	    vector<int> res;
	    int x = n;
	    while (1)
	    {
		    bool flag = false;
		    int i;
		    for (i = 2; i < x; i++)
		    {
			    if (x % i == 0)
			    {
				    res.push_back(i);
				    x = x / i;
				    flag = true;
				    break;
			    }
		    }
		    if (!flag)
		    {   
			    res.push_back(i);
			    break;
		    }
	    }
	    return res;
    }
    
    int minSteps(int n) {
        if(n == 1)
            return 0;
        else if(n == 2)
            return 2;
        else if(n == 3)
            return 3;
        
        vector<int> factorization = factor(n);
        
        if(factorization.size() == 1)
            return n;
        else
        {
            int res = minSteps(factorization[0]);
            for(int i = 1; i < factorization.size(); i++)
            {
                res += factorization[i];
            }
            return res;
        }
    }
};
