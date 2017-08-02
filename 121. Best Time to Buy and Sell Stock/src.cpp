class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy;
        bool have_stock = false;
        
        if(prices.size() < 2)
            return 0;
        else if(prices.size() == 2)
        {
            if((prices[1]-prices[0]) > 0)
                return prices[1]-prices[0];
            else
                return 0;
        }
        
        
        
        for(int i = 0; i < prices.size() - 1; i++)
        {
            if(!have_stock)
            {
                int max = prices[i];
                for(int j = i + 1; j < prices.size(); j++)
                {
                    if(prices[j] > max)
                        max = prices[j];
                }
                if(max > prices[i])
                {
                    buy = prices[i];
                    res = max - prices[i];
                    have_stock = true;
                }
            }
            else
            {
                if(prices[i] < buy)
                {
                    int max = prices[i];
                    for(int j = i + 1; j < prices.size(); j++)
                    {
                        if(prices[j] > max)
                            max = prices[j];
                    }
                    if(max - prices[i] > res)
                    {
                        buy = prices[i];
                        res = max - prices[i];
                        have_stock = true;
                    }
                }
            }
        }
        
        if(have_stock)
            return res;
        else
            return 0;
        
    }
};
