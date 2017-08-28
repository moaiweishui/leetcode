class Solution {
public:
    int shoppingOffersWithSP(vector<int>& price, vector<vector<int>>& special, int len, vector<int> needs)
    {
        if(len == 0)
        {
            int res = 0;
            for(int i = 0; i < needs.size(); i++)
            {
                res += needs[i]*price[i];
            }
            return res;
        }
        
        bool allowLastSP = true;
        for(int i = 0; i < needs.size(); i++)
        {
            if(needs[i] < special[len - 1][i])
            {
                allowLastSP = false;
                break;
            }
        }
        
        if(allowLastSP)
        {
            int withoutLastSP = shoppingOffersWithSP(price, special, len - 1, needs);
            for(int i = 0; i < needs.size(); i++)
            {
                needs[i] -= special[len - 1][i];
            }
            int withLastSP = special[len - 1][price.size()] + shoppingOffersWithSP(price, special, len, needs);
            
            return min(withLastSP, withoutLastSP);
        }
        else
        {
            return shoppingOffersWithSP(price, special, len - 1, needs);
        }
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shoppingOffersWithSP(price, special, special.size(), needs);
    }
};
