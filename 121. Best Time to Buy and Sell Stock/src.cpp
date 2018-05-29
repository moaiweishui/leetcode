class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        vector<int> min_v(prices.size(), 0);
        int max_p = 0;
        min_v[0] = prices[0];
        for (int i = 1; i < min_v.size(); i++){
            if (prices[i] < min_v[i - 1]){
                min_v[i] = prices[i];
            }
            else{
                min_v[i] = min_v[i - 1];
                if (prices[i] - min_v[i] > max_p){
                    max_p = prices[i] - min_v[i];
                }
            }
        }
        return max_p;
    }
};
