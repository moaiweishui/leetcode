/******************** Solution 1 ********************/
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == -1 || len == 0 || len == 1)
            return 0;
            
        vector<int> profit(len + 1, 0);
        
        profit[2] = (prices[1] - prices[0] > 0) ? prices[1] - prices[0] : 0;
        
        if(len == 2)
            return profit[2];
        int _max;
        for(int i = 3; i <= len; i++)
        {
            _max = 0x80000000;
            int temp;
            for(int j = 0; j < i - 1; j++)
            {
                temp = profit[j - 1] + prices[i - 1] - prices[j];
                if(temp > _max)
                    _max = temp;
            }
            profit[i] = max(profit[i - 1], _max);
        }
        
        return profit[len];
    }
};


/******************** Solution 2 ********************/
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == -1 || len == 0 || len == 1)
            return 0;
        
        if(len == 2)
            return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        
        vector<int> buy(len, 0);
        vector<int> sell(len, 0);
        
        buy[0] = -prices[0];
        buy[1] = max(buy[0], -prices[1]);
        sell[1] = prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        
        for(int i = 2; i < len; i++)
        {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        
        return sell[len - 1];
    }
};
