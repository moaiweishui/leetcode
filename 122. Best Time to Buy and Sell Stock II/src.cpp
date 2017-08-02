class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 1)
            return 0;
        else if(len == 2)
        {
            if((prices[1]-prices[0]) > 0)
                return prices[1]-prices[0];
            else
                return 0;
        }
        
        int buy;
        int profit = 0;
	    bool have_stock = false;
        
        for (int i = 0; i < prices.size(); i++)
	    {
		    if (i != prices.size() - 1)
		    {
			    if (prices[i + 1] > prices[i] && !have_stock)
			    {
				    buy = prices[i];
				    have_stock = true;
			    }
			    else if (prices[i + 1] < prices[i] && have_stock)
			    {
				    profit += prices[i] - buy;
				    have_stock = false;
			    }
		    }
		    else
		    {
			    if (have_stock)
			    {
				    profit += prices[i] - buy;
				    have_stock = false;
			    }
		    }
	    }
        
        return profit;
    }
};
