class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        sort(coins.begin(), coins.end());
        if(coins[0] > amount)
            return -1;
        
        vector<int> mem(amount + 1, -1);
        mem[0] = 0;
        
        for(int i = coins[0]; i <= amount; i++)
        {
            int min = 0x7FFFFFFF;
            for(int j = 0; j < coins.size(); j++)
            {
                if(i >= coins[j] && mem[i - coins[j]] != -1)
                {
                    int temp = 1 + mem[i - coins[j]];
                    if(temp < min)
                    {
                        min = temp;
                    }
                }
            }
            if(min != 0x7FFFFFFF)
                mem[i] = min;
            
        }
        return mem[amount];
    }
};
